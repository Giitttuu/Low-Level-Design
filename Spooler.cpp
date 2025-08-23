#include <iostream>
#include <queue>
using namespace std;

class Spooler {
private:
    queue<pair<int, string>> q;
    static Spooler inst;

    // Private Constructor
    Spooler() {}

public:
    // Singleton Accessor
    static Spooler& getInstance() {
        return inst;
    }

    void print(int id, string val) {
        q.push({id, val});
    }

    void output() {
        int size = q.size();
        while (size--) {
            int id = q.front().first;
            string s = q.front().second;
            q.pop();
            q.push({id, s});
            cout << id << " " << s << endl;
        }
    }
};

// Definition of static member
Spooler Spooler::inst;

int main() {
    Spooler& obj1 = Spooler::getInstance();
    Spooler& obj2 = Spooler::getInstance();
    Spooler& obj3 = Spooler::getInstance();

    obj1.print(1, "Lokesh");
    obj2.print(2, "Rohit");
    obj1.print(1, "Singh");
    obj3.print(3, "Ankit");

    obj1.output();

    return 0;
}
