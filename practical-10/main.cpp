#include <iostream>
#include <stdexcept>
struct BankingError : std::runtime_error { using runtime_error::runtime_error; };
struct InvalidAmount : BankingError { using BankingError::BankingError; };
struct InsufficientFunds : BankingError { using BankingError::BankingError; };
class BankAccount {
    int balance = 1000;
public:
    void withdraw(int amount) {
        if (amount <= 0) throw InvalidAmount("Amount must be positive");
        if (amount > balance) throw InsufficientFunds("Not enough funds");
        balance -= amount;
    }
    int available() const { return balance; }
};
int main() {
    BankAccount account;
    for (int amount : {300,0,900}) {
        std::cout << "Withdraw " << amount << ": ";
        try { account.withdraw(amount); std::cout << "Approved"; }
        catch (const InvalidAmount& e) { std::cout << e.what(); }
        catch (const InsufficientFunds& e) { std::cout << e.what(); }
        std::cout << "; balance = " << account.available() << '\n';
    }
}
