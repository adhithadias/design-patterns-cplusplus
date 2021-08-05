#include <iostream>
using namespace std;

class Printer {
    static int id;
public:
    int get_id() const { return this->id; }
    void set_id(int value = 0) { id = value; }
};

int Printer::id = 0;

int main() {
    Printer p;
    int id = p.get_id();
    cout << id << endl;

    Printer p2;
    p2.set_id(100);
    int id2 = p2.get_id();
    cout << id2 << endl;
    cout << id << endl;
    cout << p.get_id() << endl;


    return 0;   
}