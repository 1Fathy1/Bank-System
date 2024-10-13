#include "Client.h"
#include <string>
#include <iostream>

    Client::Client(){

    }
    Client::Client(string name , string per , string pass , long long card , string phone , int age , double  bal)
        :Person(name , per , pass , card , phone , age , bal){
    }


     void Client::withdraw(double amount){

        double old_balance = getBalance() ;

        if(amount > 0 && amount <= old_balance){
             double new_balance = old_balance - amount ;
            setBalance(new_balance) ;
        }

        else{
             cout << "===\tThere is not enough balance , please check your bank balance\t===" << endl;
        }
     }
    void Client::deposit(double amount)
    {
        if(amount > 0){
            double old_balance = getBalance() ;
            setBalance(old_balance + amount) ;
        }
        else{
             cout << "===\tPlease enter a valid number\t===" << endl;
        }
    }

