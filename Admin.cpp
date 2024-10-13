#include "Admin.h"
#include <iostream>

    Admin::Admin(){
    }

    Admin:: Admin(string name , string per , string pass , long long card , string phone , int age , double  bal)
            :Client(name , per , pass , card , phone , age , bal){}

    bool Admin::allowAccess(Client* cl){
        cout << "You Allow to " << cl->getName() << " To change his data ? (y/n) " ;
        char choose ;
        cin >> choose ;

        return choose == 'y' ;
    }