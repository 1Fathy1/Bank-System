#pragma A
#include "Person.h"
class Client :public Person {
private:

public:
    Client()  ;

    Client(string name , string per , string pass , long long card , string phone , int age , double  bal);

    void withdraw(double amount);

    void deposit(double amount);


};