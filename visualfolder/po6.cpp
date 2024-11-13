#include <iostream>

class BankAccount {
public:
    BankAccount(int _balance, const int _accNumber, const std::string &_name, const std::string &_secondName)
                : balance(_balance), accNumber(_accNumber), name(_name), secondName(_secondName) {}
    virtual ~BankAccount() = default;
    virtual void print() const {
        std::cout << name << secondName << "("<< accNumber << ")\n"
        << "Your balance is: " << balance <<  std::endl;
    };
    virtual void depositBalance(int amount) {
        balance += amount;
        std::cout << "Deposited " << amount << ". New balance: " << balance << std::endl;
    };
    virtual void withdrawBalance(int amount) {
        if (amount <= balance) {
            balance -= amount;
            std::cout << "Withdrew " << amount << ". New balance: " << balance << std::endl;
        } else {
            std::cout << "Not enough balance to withdraw " << amount << " from account " << accNumber << std::endl;
        }
    };

protected:
    int balance;
    int accNumber;
    std::string name;
    std::string secondName;
};

class SavingsAccount : BankAccount {
public:
    SavingsAccount(int _balance, const int _accNumber, const std::string &_name, const std::string &_secondName, int _interestRate)
                : BankAccount(_balance, _accNumber, _name, _secondName), interestRate(_interestRate), savingsBalance(0) {}

    void print() const {
        std::cout << "SavingsAccount - " << name << " " << secondName << " (" << accNumber << ")\n"
                  << "Balance: " << balance << ", Interest Rate: " << interestRate << "%\n";
    };

    void depositSavings(int amount) {
        int savingsBalance;
        if(balance >= amount) {
            savingsBalance += amount; 
            balance -= amount; 
            std::cout << "Your money had been deposited with interest rate of "  << interestRate << "%" << std::endl;
        } else {
            std::cout<<"Not enought balance in your acc: " << accNumber << std::endl;
        }
    };

    };
    void withdraw(int amount) {
        if(savingsBalance >= amount) {
            savingsBalance -= amount; 
            std::cout << "Your balance: "<< savingsBalance << std::endl;
        } else {
            std::cout<<"Not enought balance in your acc: " << accNumber << std::endl;
        }
    };
protected:
    int interestRate;
    int savingsBalance;


};

class InvestmentAccount : BankAccount {
public:
    InvestmentAccount(int _balance, const int _accNumber, const std::string &_name, 
                      const std::string &_secondName, const std::string &_assetName)
                      : BankAccount(_balance, _accNumber, _name, _secondName), assetName(_assetName) {}

    void print() const {
        std::cout << "Investment account - " << name << " " << secondName << " (" << accNumber << ")\n"
        << "Balance: " << balance << "\n Your assets: " << assetName << std::endl;
    };

    void buyAsset() {
        std::cout << "Buying asset: " << assetName << std::endl;
    }

    void sellAsset() {
        std::cout << "Selling asset: " << assetName << std::endl;
    }
private:
    std::string assetName;
};


int main() {
    BankAccount b(10000, 1337, "JAN", "KOWALSKI");
    b.print();
    SavingsAccount c(10000, 1234, "JOHN", "SMITH", 5);
    c.print();
    c.depositSavings(500);
    c.withdraw(200);
    InvestmentAccount inv(20000, 5678, "WIKTOR", "NOWAK", "Bitcoin");
    inv.print();
    inv.buyAsset();
    inv.sellAsset();

    return 0;
}