#pragma A
#include<iostream>
#include <string>
using namespace std;
class Person {
private:
    string name  ;
    string personal_id ;
    string password ;
    string phone_number;
    int age ;
    double balance ;
    long long card_num ;
public:
    Person();
    Person(string name , string per , string pass , long long  card , string phone , int age , double  bal);

    string getID();
    void setID(string id);

    string getName();
    void setName(string name);

    int getAge();
    void setAge(int age);

    string getPass();
    void setPass(string password);

    long long  getCard();
    void setCard(long long  card_number);

    string getPhon();
    void setPhone(string phone_number);

    double getBalance();
    void setBalance(double balance);

};