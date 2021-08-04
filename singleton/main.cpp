#include <iostream>
#include <fstream>
#include <map>
using namespace std;

#include <boost/lexical_cast.hpp>
using namespace boost;

// only makes sense to have one instance of the database

class SingletonDatabase {
    SingletonDatabase() {
        cout << "Initializing the database\n";
        ifstream ifs("./database/capitals.txt");

        string s, s2;
        while (getline(ifs, s)) {
            getline(ifs, s2);
            int pop = lexical_cast<int>(s2);
            capitals[s] = pop;
        }
    }
    map<string, int> capitals;

public:
    // should not allow the user to use copy constructor
    // or copy assignment
    // you want to delete both of those operations to 
    // not allow the user to use copy constructor or copy assignment
    // in modern c++ we can use the delete keyword to delete those
    SingletonDatabase(SingletonDatabase const&) = delete;
    void operator=(SingletonDatabase const&) = delete;

    static SingletonDatabase& get() {
        static SingletonDatabase db;
        return db;
    }

    int get_population(const string& name) {
        return capitals[name];
    }
};

int main(int argc, char *argv[]) {
    string city = "Tokyo";
    cout << city << " has population " << SingletonDatabase::get().get_population(city) << endl;


    return 0;
}