/*:
 * File: main.cpp
 * Developer: Kolin Jacobs
 * Email: jacobsk138447@student.vvc.edu
 * Descrition : This program will read in the descriptions and then print out
 * statement listing all deposits, withdrawals, and the daily balance for each day
 **/

#include <iostream>
#include <string>
#include <vector>


/////////////////////***   Transaction Class   ***/////////////////////////
class Transaction
{
  public:
    Transaction(int, double, std::string);
    double get_amount();
    void print();
    
  private:
    int day;
    double amount;
    std::string description;
};

//addd Transaction data when the object is created
Transaction::Transaction(int d, double a, std::string desc){
  day = d;
  amount = a;
  description = desc;
}

//gets the Transaction amount
double Transaction::get_amount(){
  return amount;
}

//prints out Transaction data
void Transaction::print()
{
    std::cout << "day: " << day << std::endl;
    std::cout << "amount: " << amount << std::endl;
    std::cout << "description: " << description << std::endl;
}




////////////////////***  Account Class  ***/////////////////////


class Account
{
  public:
    Account();
    double get_balance();
    void print();
    void accrue_interest();
    double get_interest_earned();
    void add_transaction();
    
  private:
    std::vector<Transaction> transactions;
    double balance;
    double interest_earned;
};


Account::Account(){
  Transaction intial(1, 1143.24, "intial");
  transactions.push_back(intial);
  balance = get_balance();
  interest_earned = 0;
}

//returns interest
double Account::get_interest_earned(){
  return interest_earned;
}

//gets the current Account balance including interest
double Account::get_balance(){
  double balance = 0;
  for(int i=0;i< transactions.size();i++){
    balance += transactions[i].get_amount();
  }
  return balance + get_interest_earned();
}

//accrues intrest based on current balance
//intrest accrues daily
void Account::accrue_interest(){
  double interest = (get_balance())*(0.5/30);
  interest_earned += interest;
}

//adds a transaction
void Account::add_transaction(){
  
    bool more = true;
    while(more)
   {
      double d = transactions.size() + 1;
      double a;
      std::string desc;
      
      
      std::cout << "please enter an amount";
      std::cin >> a;
      std::cout << "please enter a description";
      std::cin >> desc;
      accrue_interest();
      Transaction t(d, a, desc);
      transactions.push_back(t);
      
      std::cout << "Enter another (Y/N)" << std::endl;
      char response = a;
      std::cin >> response;
      
      if(response != 'y' && response != 'Y'){
        more = false;  
      }
   }
}
//prints out transaction and total
void Account::print(){
  for(int i=0;i< transactions.size();i++){
    std::cout << "_______________" << std::endl;
    transactions[i].print();
  }
  std::cout << std::endl;
  std::cout << "your total balance is: " << get_balance() << std::endl;
  std::cout << "total interest earned: " << get_interest_earned() << std::endl;
}

////////////////////**** Main ***//////////////////////////////////////////

int main() {
    Account account;
    std::cout << "Hello, welcome to your bank account" << std::endl;
    std::cout << "your current balance is: " << account.get_balance() << std::endl;
    std::cout << "Please add a Transaction" << std::endl;
    
    account.add_transaction();
    account.print();
}

