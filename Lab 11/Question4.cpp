#include <iostream>
#include <exception>
#include <string>
using namespace std;

class DatabaseException : public exception {
protected:
    string message;

public:
    DatabaseException(string msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class ConnectionFailedException : public DatabaseException {
public:
    ConnectionFailedException(string msg) : DatabaseException(msg) {}
};

class QueryTimeoutException : public DatabaseException {
public:
    QueryTimeoutException(string msg) : DatabaseException(msg) {}
};

template <typename T>
class DatabaseConnector {
private:
    T db_name;

public:
    DatabaseConnector(T name) : db_name(name) {}

    void connect() {
        if (db_name == "invalid_db") {
            throw ConnectionFailedException("Connection failed: Invalid database name.");
        } else if (db_name == "slow_db") {
            throw QueryTimeoutException("Query timeout: Database response too slow.");
        } else {
            cout << "Connected to " << db_name << " successfully." << endl;
        }
    }
};

int main() {
    try {
        cout << "Attempting to connect to invalid_db..." << endl;
        DatabaseConnector<string> conn1("invalid_db");
        conn1.connect();
    }
    catch (DatabaseException& e) {
        cout << "Caught Exception: " << e.what() << endl;
    }

    try {
        cout << "Attempting to connect to slow_db..." << endl;
        DatabaseConnector<string> conn2("slow_db");
        conn2.connect();
    }
    catch (DatabaseException& e) {
        cout << "Caught Exception: " << e.what() << endl;
    }

    return 0;
}
