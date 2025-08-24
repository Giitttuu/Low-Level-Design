#include <iostream>
using namespace std;

// Abstraction (Interface)
class Database {
public:
    virtual void save(string data) = 0; // Pure virtual function
    virtual ~Database() {} // Always add virtual destructor for interfaces
};

// MySQL implementation (Low-level module)
class MySQLDatabase : public Database {
public:
    void save(string data) override {
        cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << endl;
    }
};

// MongoDB implementation (Low-level module)
class MongoDBDatabase : public Database {
public:
    void save(string data) override {
        cout << "Executing MongoDB Function: db.users.insert({name: '" << data << "'})" << endl;
    }
};

// High-level module (Now loosely coupled)
class UserService {
private:
    Database* db;  // Dependency Injection

public:
    UserService(Database* database) {  
        db = database;
    }
    
    void storeUser(string user) {
        db->save(user);
    }
};

int main() {
    // Create objects dynamically
    Database* mysql = new MySQLDatabase();
    Database* mongodb = new MongoDBDatabase();

    UserService service1(mysql);   // Inject MySQL
    service1.storeUser("Aditya");

    UserService service2(mongodb); // Inject MongoDB
    service2.storeUser("Rohit");

    // Clean up memory
    delete mysql;
    delete mongodb;
}
