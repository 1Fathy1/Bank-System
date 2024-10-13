#include "Person.h"
#include <string>

    Person::Person() {
        this->name = "" ;
        this->personal_id = "" ;
        this->phone_number = "" ;
        this->password = "" ;
        this->age = 0;
        this->card_num = 0;
    }
    Person::Person(string name , string per , string pass , long long  card , string phone , int age , double  bal):
    name(name) , personal_id(per) , password(pass) , card_num(card) , phone_number(phone) , age(age) , balance(bal) {
    }
    string Person::getName(){
        return name ;
    }
    void Person::setName(string Name ){
        name = Name ;
    }

    string Person::getID(){
     return personal_id ;
    }
    void Person::setID(string id){
        personal_id = id ;
    }

    int Person::getAge(){
        return age ;
    }
    void  Person::setAge(int Age){
        age = Age ;
    }

    string Person::getPass(){
        return password ;
    }
    void  Person::setPass(string Password){
        password = Password ;
    }

    long long  Person::getCard(){
       return card_num ;
    }
    void  Person::setCard(long long  card_number){
      card_num = card_number ;
    }

    string  Person::getPhon(){
       return phone_number ;
    }

    void  Person::setPhone(string phone){
      phone_number = phone ;
    }

    double  Person::getBalance(){
       return balance ;
    }
    void  Person::setBalance(double blan){
    balance = blan ;
    }
