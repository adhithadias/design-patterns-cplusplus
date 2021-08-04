#include <iostream>
#include <fstream>
#include <map>
using namespace std;

#include <boost/lexical_cast.hpp>
using namespace boost;

#include <gtest/gtest.h>

// only makes sense to have one instance of the database

class SingletonDatabase {
    SingletonDatabase() {
        cout << "Initializing the database\n";
        ifstream ifs("/home/min/a/kadhitha/workspace/design_patterns/singleton/database/capitals.txt");

        if(ifs.is_open()) {
            string s, s2;
            while (getline(ifs, s)) {
                getline(ifs, s2);
                int pop = lexical_cast<int>(s2);
                capitals[s] = pop;
            }
        }
        else {
            cout << "could not open file\n"; 
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
        // since this is static - only one object is created
        static SingletonDatabase db;
        return db;
    }

    int get_population(const string& name) {
        return capitals[name];
    }
};

struct SingletonRecordFinder {
    int total_population(vector<string> names) {
        int result{0};
        for (auto& name : names) {
            result += SingletonDatabase::get().get_population(name);
        }
        return result;
    }
};

TEST(HelloTest, BasicAssertions) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(6*7, 42);
}

TEST(RecordFinderTests, SingletonTotalPopulationTest) {
    SingletonRecordFinder rf;
    vector<string> names{"Seoul", "Mexico City"};
    int tp = rf.total_population(names);
    EXPECT_EQ(17500000+17400000, tp);
}

int main(int argc, char* argv[]) {
    // string city = "Tokyo";
    // cout << city << " has population " << SingletonDatabase::get().get_population(city) << endl;


    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    return 0;
}