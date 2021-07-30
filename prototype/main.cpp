#include <iostream>

using namespace std;

struct Address {
    string street, city;
    int suite;

    Address(const string &street, const string &city, int suite)
        : street(street), city(city), suite(suite) {}

    friend ostream &operator<<(ostream &os, const Address &address) {
        os << "streat: " << address.street << ", city: " << address.city 
            << ", suite: " << address.suite;
        return os;
    }
};

struct Contact {
    string name;
    Address address;

    Contact (const string &name, const Address &address)
        : name(name), address(address) {}

    friend ostream &operator<<(ostream &os, const Contact &contact) {
        os << "name: " << contact.name << ", address: " << contact.address;
        return os;
    }
};

int main() {
    Contact john{"John Doe", Address{"123 East Dr", "London", 123}};
    // Contact jane{"Jane Smith", Address{"123 East Dr", "London", 103}};
    Contact jane = john;
    jane.name = "Jane Smith";
    jane.address.suite = 103;

    cout << john << endl << jane << endl << john << endl;

    return 0;
}