#include<bits/stdc++.h>
using namespace std;

class Account{
    public:
        virtual void deposit(double amount) = 0;
        virtual void withdrawl(double amount) = 0;
};

class SavingsAccount: public Account{
    private:
      double balance;
      public:
        SavingsAccount(){
            balance=0;
        }  

        void deposit(double amount){
            balance+=amount;
            cout<<"Deposited: "<<amount << "in savings account.New Balance"<<balance<<endl;
        }

        void withdrawl(double amount){
            if(balance >= amount){
                balance-=amount;
                cout<<"Withdrawn:"<<amount <<"From savings Account.New balance"<<balance<<endl;
            }
            else{
                cout<<"Insufficient funds in savings account";
            }
        }
};

class CurrentAccount:public Account {
    private:
      double balance;
      public:
        CurrentAccount(){
            balance=0;
        }  

        void deposit(double amount){
            balance+=amount;
            cout<<"Deposited: "<<amount << "in Current account.New Balance"<<balance<<endl;
        }

        void withdrawl(double amount){
            if(balance >= amount){
                balance-=amount;
                cout<<"Withdrawn:"<<amount <<"From Current Account.New balance"<<balance<<endl;
            }
            else{
                cout<<"Insufficient funds in Current account";
            }
        }
};

class FixedAccount : public Account{
        private:
      double balance;
      public:
        FixedAccount(){
            balance=0;
        }  

        void deposit(double amount){
            balance+=amount;
            cout<<"Deposited: "<<amount << "in Current account.New Balance"<<balance<<endl;
        }

        void withdrawl(double amount){
            throw logic_error ("WithDdrwal not allowd in fixed term account");
        }
};

class BankClient{
    private:
        vector<Account*>accounts;
    public:
        BankClient( vector<Account*>accounts){
            this->accounts = accounts;
        }

    void processTransactions(){

        for(Account*acc :accounts){
            acc->deposit(1000);//alla accounts allow deposits
        //assuming all accounts support withdrawl (LSP violation)
            if(typeid(*acc)==typeid(FixedAccount)){
                cout<<"Skipping withdrawl for fixed term account"<<endl;
            }
            else{
                try{
                    acc->withdrawl(500);
                }catch(const logic_error& e){
                    cout<<"Exception:"<<e.what()<<endl;
                }
            }
    
    }

        
    }
};
int main(){
vector<Account*>accounts;
     accounts.push_back(new SavingsAccount());
     accounts.push_back(new CurrentAccount());
     accounts.push_back(new FixedAccount());

     BankClient* client = new BankClient(accounts);
     client->processTransactions();
     
}