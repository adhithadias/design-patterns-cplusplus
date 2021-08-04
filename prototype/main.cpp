#include <iostream>
#include <memory>

using namespace std;

struct Address {
    string street, city;
    int suite;

    Address(const string &street, const string &city, int suite)
        : street(street), city(city), suite(suite) {}

    Address(const Address& address) 
    : street{address.street}, city{address.city}, suite{address.suite}
    {}

    friend ostream &operator<<(ostream &os, const Address &address) {
        os << "streat: " << address.street << ", city: " << address.city 
            << ", suite: " << address.suite;
        return os;
    }
};

// if we make the Address a pointer, then main method cannot simply change the address values
// if did so, it would change the address values in the original object too.
// Hence the prototype design pattern fails in this scenario.

// we can resolve this by defining a copy constructor
struct Contact {
    string name;
    Address* address;

    Contact (const string &name, Address *address)
        : name(name), address(address) {}

    Contact (const Contact& other) 
        : name {other.name}
        , address { new Address{*(other.address)} }
    {}

    ~Contact() { delete address; }

    friend ostream &operator<<(ostream &os, const Contact &contact) {
        os << "name: " << contact.name << ", address: " << *contact.address;
        return os;
    }
};

struct EmployeeFactory {
    static unique_ptr<Contact> new_main_office_employee(const string& name, const int suite) {
        static Contact p{ "", new Address {"123 East Dr", "London", 0} };
        return new_employee(name, suite, p);
    }

private:
    static unique_ptr<Contact> new_employee(const string& name, const int suite,
    const Contact& prototype) {
        auto result = make_unique<Contact>(prototype);
        result->name = name;
        result->address->suite = suite;
        return result;
    }
};

int main() {
    Contact john{"John Doe", new Address{"123 East Dr", "London", 123}};
    // Contact jane{"Jane Smith", Address{"123 East Dr", "London", 103}};
    Contact jane {john}; // deep copy
    jane.name = "Jane Smith";
    jane.address->suite = 103;

    cout << john << endl << jane << endl << john << endl;

    auto adhitha = EmployeeFactory::new_main_office_employee("Adhitha", 100);
    cout << *adhitha << endl;

    return 0;
}