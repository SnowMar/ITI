#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount
{
private:
    string accountHolderName;
    int accountNumber;
    double balance;
    double interestRate;
public:
    BankAccount(string ahn, int an, double b, double ir);
    ~BankAccount();
    void deposit(double amount);
    void withdraw(double amount);
    void addInterest();
    void printAccountDetails();
};

BankAccount::BankAccount(string ahn, int an, double b, double ir)
    : accountHolderName(ahn), accountNumber(an), balance(b), interestRate(ir)
{
}

BankAccount::~BankAccount()
{
}
void BankAccount::deposit(double amount)
{
    balance += amount;
}

void BankAccount::withdraw(double amount)
{
    if (balance >= amount)
    {
        balance -= amount;
    }
    else
    {
        cout << "Insufficient balance" << endl;
    }
}
void BankAccount::addInterest(){
    balance = balance + balance * interestRate;
}
void BankAccount::printAccountDetails(){
    cout << "Account Holder Name: " << accountHolderName << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: " << balance << endl;
    cout << "Interest Rate: " << interestRate << endl;
}
int main(){
    BankAccount b("Mohamed", 2000, 0, 20);
    b.printAccountDetails();
    b.deposit(3000);
    b.printAccountDetails();
    BankAccount a(b);
    a.withdraw(300);
    a.printAccountDetails();
    return 0;
}
