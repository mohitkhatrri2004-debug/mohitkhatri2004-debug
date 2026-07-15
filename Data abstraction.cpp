#include<bits/stdc++.h>
using namespace std;
class BankAccount{
    private:
        double balance;
    public:
        BankAccount(double initialBalance){
            balance = initialBalance;
        }
        void Deposit(double amount){
            balance += amount;
        }
        void withdrawal(double amount){
            if(amount < balance){
                balance -= amount;
            }else{
                cout << "Insufficient balance " << endl;
            }
        }
        int getBalance(){
            return balance;
        }
};
int main(){
    BankAccount b(2000);
    b.Deposit(500);
    b.withdrawal(1000);
    cout << "Current balance : " << b.getBalance() << endl;
    return 0;
}