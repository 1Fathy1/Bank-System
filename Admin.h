#pragma A
#include "Client.h"
class Admin :public Client {
private:

public:
    Admin();

    Admin(string name , string per , string pass , long long card , string phone , int age , double  bal);

    bool allowAccess(Client*) ;
};