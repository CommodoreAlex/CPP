#include <iostream>
using namespace std;

class Account {
protected:
    string owner;
    double balance;

// Base class
public:
    Account(const string& name, double initialBalance) 
        : owner(name), balance(initialBalance) {}
    
    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual bool withdraw(double amount) {
        if (amount > balance) return false;
        balance -= amount;
        return true;
    }

    virtual void display() const {
        cout << "Owner: " << owner << ", Balance: $" << balance << endl;

    }

    virtual ~Account() {} // Virtual destructor for proper cleanup
};

// Derived class
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const string& name, double initialBalance, double rate)
        : Account(name, initialBalance), interestRate(rate) {}

    void applyInterest() {
        balance += balance * interestRate;
    }

    void display() const override {
        cout << "Savings - ";
        Account::display();
    }
};

// Another derived class
class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(const string&name, double initialBalance, double overdraft)
        : Account(name, initialBalance), overdraftLimit(overdraft) {}
    
    bool withdraw(double amount) override {
        if (amount > balance + overdraftLimit) return false;
        balance -= amount;
        return true;
    }

    void display() const override {
        cout << "Checking - "; 
        Account::display();
    }
};

// Polymorphic Use in Main
int main() {
    Account* accounts[] = {
        new SavingsAccount("Alice", 1000, 0.05),
        new CheckingAccount("Bob", 500, 200)
    };

    for (Account* acc : accounts) {
        acc->deposit(200);
        acc->withdraw(100);
        acc->display();
    }

    // Cleanup
    for (Account* acc: accounts) {
        delete acc;
    }

    return 0
}
