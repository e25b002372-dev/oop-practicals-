#include <iostream>
#include <stdexcept>
#include <string>
class BankAccount {
    // Private: callers cannot bypass balance checks.
    std::string number;
    int balance; // whole rupees for this exercise
public:
    // Public operations provide controlled access.
    BankAccount(std::string id, int opening) : number(id), balance(opening) {
        if (id.empty() || opening < 0) throw std::invalid_argument("Invalid account");
    }
    bool withdraw(int amount) {
        if (amount <= 0 || amount > balance) return false;
        balance -= amount;
        return true;
    }
    void display() const { std::cout << number << ": Rs " << balance << '\n'; }
};
int main() {
    BankAccount a("A01", 500), b("A02", 250);
    for (auto* account : {&a, &b}) {
        account->display();
        std::cout << (account->withdraw(300) ? "Paid 300" : "Payment declined") << '\n';
        account->display();
    }
}
