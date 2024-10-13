#include <iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include <random>
#include <stdexcept>
#include"Admin.h"
#define ll long long
#define endl "\n"

using namespace std;

/**
 * Client Options :
 *    1,2,3,4, 5.1[bug] ,5.2[Can't change the id],5.3[bug],5.4 , 6 , 7 [bug] , 8
 *    in options 5.0  : make ACCESS database .
 */

/**
 * Admin Options :
 *    1,2,3,4, 5.1[bug] ,5.2[Can't change the id],5.3[bug],5.4,6, 7[bug] ,8,9[bug]
 *    in options 5.0  : make ACCESS database .
 */


/**
 * Error in test
 * Password not matching [-]Please try again   [string formatting]
 * CREATE CLIENT ACCOUNT   [run time error]      --->    ok
 * save_file
 * @return
 */

Client* create_account();
void sign_in(bool);
void edit_file(Client,const string& , bool = false);
void log_in(Client* , bool);
bool get_data(string , string& );
bool edit_account_data(Client*);
bool valid_id(string);
ll random_number(const string&);
Admin* sign_in_admin();
Admin* sign_up_admin(Admin* );
vector<string> accline(string);

int main()
{
MainMenu:
    cout << "-------------------- BANK SYSTEM -------------------- \n|";
    cout << "\tWelcome to my bank system project            |\n|"
            "\t--- Main menu ----                           |";
    char choose;

    cout << "\n|\t[-]Choose by enter the number                |"
            "\n|\t[1]- Create Client Account                   |"
            "\n|\t[2]- Sign in to your account                 |"
            "\n|\t[3]- create Admin account                    |"
            "\n|\t[4]- Enter AS Admin                          |"
            "\n|\t[5]- Exit                                    |"
            "\n>";

    cin >> choose;
    if(choose == '1'){
      auto* cur_client =  create_account() ;
      sign_in(false) ;
    }
    
    else if(choose == '2'){
        sign_in(false) ;
    }
    
    else if(choose == '3'){

        cout << "TO CREATE ADMIN ACCOUNT YOU MUST LET OLD ADMIN TO LET YOU SIGNUP\nPRESS A TO AGREE OR N FOR RETURN MAIN MENU\n";
        char ch;
        cin >> ch;
        if (ch == 'A') {
            Admin* admin = sign_in_admin();
            if (admin != nullptr)
            {
                admin = sign_up_admin(admin);
             //   asadmin(admin);
            }
        }
    }

    else if(choose == '4'){
        sign_in(true) ;
    }

    else{
        cout << "Exit The System" << endl ;
        return 0;
    }

    goto MainMenu ;
}

bool get_data( string type , string& var){

    // inset function
    auto valid_back = [](const string& data)-> int  {
        if(data == "00"){
            return 1 ;
        }
        else if(data == "01"){
            exit(0) ;
        }

        return 0;
    };

    if(type == "name"){
        do {
            cout << "\t[-]Please enter your name\n>";
            cin.ignore();
            getline(cin, var);

            if(valid_back(var) == 1){
                return false;
            }

        } while (var.empty());
    }

    else if(type == "phone"){
        cout << "\t[-]Please enter your phone number with this format {01xxxxxxxxx}\n>";
//        cin.ignore() ;
        int try_again = 5 ;
        do {
            cin >> var ;

            if(valid_back(var) == 1){
                return false ;
            }
            if(var.size() != 11){
                try_again--;
                if(try_again == 0){
                    cout <<"something error , pleas try again" << endl;
                    exit(0) ;
                }
                cout << "\nwrong phone number. [-]Please try again you have " << try_again << " Times\nNumber : ";
            }

        } while (var.size() != 11);
    }

     // Age
    /// dynamic from his personal_id in create_account()

    else if(type == "password"){
        Password:
        cout << "\t[-]Please enter your password --- must be contain from four char or more --- \n> ";
        do{
            cin >> var ;

            if(valid_back(var) == 1){
                return false ;
            }

            if(var.size() < 4){
                cout<< "\t--- must be contain from four char or more ---\n> " ;
            }
        }while(var.size() < 4) ;

        // confirm password
        cout << "confirm your pass \n> ";
        string con_pass ;
        int try_again = 3 ;
        do{
            cin >> con_pass ;
            if(valid_back(var) == 1){
                return false ;
            }
            if(con_pass.size() < 4 || con_pass != var ){
                try_again-- ;
                if(try_again == 0){
                    cout <<"something error , [-]Please tray again" << endl;
                    goto Password ;
                }
                cout<< "Password not matching [-]Please try again\n>" ;
            }
        }while(con_pass != var) ;
    }

    else if(type == "id"){
        cout << "\t[-]Please enter your personal number \n>";
        int try_again = 5 ;
        do {
            cin >> var ;

            if(valid_back(var) == 1 ){
                return false ;
            }
            if(var.size() != 14 || !valid_id(var)){
                try_again--;
                if(try_again == 0){
                    cout <<"something error , pleas try again" << endl;
                    exit(0) ;
                }
                cout << "\nwrong Personal Id. [-]Please try again you have " << try_again << " Times\n>";
            }

        } while (var.size() != 14 || !valid_id(var));

    }

    return true;
}

bool valid_id(string id){
    int year , month , day ;

    year =stoi(id.substr(1,2)) ;
    month =stoi(id.substr(3,2)) ;
    day =stoi(id.substr(5,2)) ;

    if(id[0] == '3'){
     if(year > 24){
         return false ;
     }
    }

    if(!(year > 0 && day > 0 && day <= 31 && month > 0 && month < 13)) {
        return false ;
    }
    return true ;
}

Client* create_account() {
    string name, phone, password, personal_id;
    int age;
    double balance;
    ll card ;
    cout << "\tCREATE CLIENT ACCOUNT\n\nenter 00 to back to main menu\n01 to exit\n\n";

    /// GET NAME
    if(!get_data("name", name)){
        return nullptr;
    }

    /// GET PHONE
    if(!get_data("phone", phone)){
        return nullptr;
    }

    /// GET PASSWORD
    if( !get_data("password", password)){
        return nullptr;
    }

    /// GET PERSONAL ID
    if(!get_data("id", personal_id)){
        return nullptr;
    }

    /// GET AGE DYNAMIC
    int year =(personal_id[0] == '1' || personal_id[0] == '2' ? 1900 : 2000 ) + stoi(personal_id.substr(1,2));
    age = 2024 - year ;

    if(age < 18 || age >= 90){
        cout << "Can't create account for " << age << " year" << endl;
        return nullptr ;
    }

    ///GET BALANCE
 balance:
    cout <<"\t> Enter Your Balance\n> " ;
    cin >> balance ;

        if(balance < 0){
           goto balance;
        }

    /// GET card number :
  Create_Random_Card:
    card = random_number("client") ;

    /// check for the number
    string str_card = to_string(card) ;

    /// open file to read the data
    ifstream f_out("data_client.txt") ;
    string temp ;

    while(getline(f_out,temp) && temp.size() > 16){
       temp.resize(16) ;
       if(temp == str_card){
           goto Create_Random_Card ;
       }
    }
    // close file .
    f_out.close() ;

    auto* new_client = new Client(name , personal_id , password , card , phone , age , balance) ;
    ofstream fin;
    fin.open("data_client.txt" , ios::app);
    //card , pass , name  , age , phone ,  balance, id
    fin << new_client->getCard() << ','
        << new_client->getPass() << ','
        << new_client->getName() << ','
        << new_client->getAge() << ','
        << new_client->getPhon() << ','
        << new_client->getBalance() << ','
        << new_client->getID() << ','
        << endl;
    fin.close() ;

    cout <<"Your Card id is : " << str_card << "\nPLEASE SAVE IT " << endl ;
    return new_client ;
}

Admin* sign_in_admin(){
    string name, phone, password, personal_id , strage , strbalance;
    int age;
    double balance;
    ll card ;
    auto* cur_admin = new Admin() ;

 LoginAdmin:
    cout << "\t\tSign in to your account"
            "\n\n\tEnter card id"
            "\ncard:";
    string data , str_card ;

    int try_again = 3 ;
    bool found = false ;
    ifstream fin("admin_data.txt");

    do{
        fin.seekg(0, std::ios::beg);
        try_again--;
        cin >> card ;
        while(getline(fin,data)){
             stringstream in(data);
             getline(in , str_card , ',') ;
             if(to_string(card) == str_card){

                 getline(in , password , ',') ;
                 getline(in , name , ',') ;
                 getline(in , strage , ',') ;
                 age = stoi(strage) ;
                 getline(in , phone , ',') ;
                 getline(in , strbalance , ',') ;
                 balance = stoi(strbalance) ;
                 getline(in , personal_id , ',') ;
                 /// admin format

                 cur_admin = new Admin(name ,personal_id , password , card , phone , age , balance);
                 found = true ;
                 break;
             }
        }
        if(!found){
            cout <<"Invalid Card Number tray again\n>"  ;
        }
        if(try_again == 0){
            cout <<"\t\tFind error pleas tray again" << endl;
            goto LoginAdmin ;
        }
    }while(!found);

    /// confirm password
    // close file
    fin.close() ;

    // check for password
    password = "" ;
    cout << "\t> Enter your password\n> ";
    int try_time = 3 ;
    do{
        cin >> password ;
        try_time--;
        if(password != cur_admin->getPass()) {
            cout <<"Wrong password , Please try again\n>" ;
        }
        if(try_time == 0){
            cout <<"Find a error please tray again" << endl;
            goto LoginAdmin;
        }
    }while(password != cur_admin->getPass()) ;

    return cur_admin ;
}

Admin* sign_up_admin(Admin* cur ){
    string name, phone, password, personal_id;
    int age;
    double balance;
    ll card ;
    cout << "\tCREATE ADMIN ACCOUNT\n\nenter 00 to back to main menu\n01 to exit\n\n";

    /// GET NAME
    if(!get_data("name", name)){
        return nullptr;
    }

    /// GET PHONE
    if(!get_data("phone", phone)){
        return nullptr;
    }

    /// GET PASSWORD
    if( !get_data("password", password)){
        return nullptr;
    }

    /// GET PERSONAL ID
    if(!get_data("id", personal_id)){
        return nullptr;
    }

    /// GET AGE DYNAMIC
    int year =(personal_id[0] == '1' || personal_id[0] == '2' ? 1900 : 2000 ) + stoi(personal_id.substr(1,2));
    age = 2024 - year ;

    if(age < 18 || age >= 90){
        cout << "Can't create account for " << age << " year" << endl;
        return nullptr ;
    }

    ///GET BALANCE
    balance:
    cout <<"\t> Enter Your Balance\nBalance : " ;
    cin >> balance ;

    if(balance < 0){
        goto balance;
    }

    /// GET card number :
Create_Random_Card_admin:
    card = random_number( "admin") ;
    card *= pow(10 , 6) ;

       /// check for the number
    try{
       /// open file to read the data
       ifstream f_out("admin_data.txt") ;

       if (!f_out.is_open()) {
           throw runtime_error("Failed to open file: admin_data.txt");
       }

       string temp ;
       string str_card = to_string(card) ;

       while(getline(f_out,temp) && temp.size() > 16){
           temp.resize(16) ;
           if(temp == str_card){
               goto Create_Random_Card_admin ;
           }
       }
       // close file .
       f_out.close() ;
       cout << "Your card number is : " << card << "\nPLEAS SAVE IT" << endl ;
   }
   catch (const std::exception& e) {
       std::cerr << "Exception: " << e.what() << '\n';
   }


    auto* new_admin = new Admin(name , personal_id , password , card , phone , age , balance) ;
    ofstream fin;
    fin.open("admin_data.txt" , ios::app);
    //card , pass , name  , age , phone ,  balance, id
    fin << new_admin->getCard() << ','
        << new_admin->getPass() << ','
        << new_admin->getName() << ','
        << new_admin->getAge() << ','
        << new_admin->getPhon() << ','
        << new_admin->getBalance() << ','
        << new_admin->getID() << ','
        << endl;
    fin.close() ;
    return new_admin ;
}

ll random_number(const string& type){
    random_device rd ;

    mt19937 gen(rd());

    ll rn_num ;
    if(type == "admin"){
        uniform_int_distribution<ll> distribution(1000000000LL, 9999999999LL);
        rn_num = distribution(gen) ;
    }
    else{
        uniform_int_distribution<ll> distribution(1000000000000000LL, 9999999999999999LL);
        rn_num = distribution(gen) ;
    }
    return rn_num ;
}

void log_in(Client* cur_user , bool is_admin){
    admin_menu:
    if(is_admin)
        cout << "\n\t ------ Welcome to your account [ "
             << cur_user->getName() << " ]"
             << "\n|\t1- Withdraw "
                "\n|\t2- Deposit"
                "\n|\t3- Balance inquiry"
                "\n|\t4- Account details"
                "\n|\t5- Edit account data"
                "\n|\t6- Delete account"
                "\n|\t7- Log out"
                "\n|\t8- Exit>"
                "\n|\t9- List all account\n>";

    client_menu:
    if(!is_admin)
        cout << "\n\t------ Welcome to your account [ " << cur_user->getName() << " ]"
             << "\n|\t1- Withdraw "
                "\n|\t2- Deposit"
                "\n|\t3- Balance inquiry"
                "\n|\t4- Account details"
                "\n|\t5- Edit account data"
                "\n|\t6- Delete account"
                "\n|\t7- Log out"
                "\n|\t8- Exit\n>";
    choose_option:
    char choose;
    string password , data ;
    int en_pass = 3 ;
    auto* access = new Admin() ;
    ifstream file("data_client.txt") ;

    cin >> choose ;
    switch (choose) {

        case '1' :
            cout << "\n\t> Enter the amount you want to withdraw\n>";
            double amount ;
            do{
                cin >> amount;
                if(amount < 0){
                    cout<< "[-] Please enter positive amount\n>" << endl;
                }
            }while(amount < 0) ;

            if(amount > cur_user->getBalance()){
                cout << "\n[-] Sorry your balance isn\'t enough\n";
            }else{
                cur_user->withdraw(amount) ;
            }
            edit_file(*cur_user , "client") ;
            amount = 0 ;
            break ;

        case '2' :
            cout << "\n\t> Enter the amount you want to deposit\n>";
            do{
                cin >> amount;
                if(amount < 0){
                    cout<< "[-]Please enter positive amount\n>" << endl;
                }
            }while(amount < 0) ;

            cur_user->deposit(amount) ;
            cout << "\n" << amount << " has been deposited\n";
            edit_file(*cur_user , "client");
            break ;

        case '3' :
            cout << "\nyour current balance is :" << cur_user->getBalance();
            break ;

        case '4' :
            cout <<"\n\tName          : " << cur_user->getName()
                 <<"\n\tCard          : " << cur_user->getCard()
                 <<"\n\tPersonal Id   : " << cur_user->getID()
                 <<"\n\tPhone Number  : " << cur_user->getPhon()
                 <<"\n\tAge           : " << cur_user->getAge()
                 <<"\n\tBalance       : " << cur_user->getBalance()
                 <<"\n\tPassword      : **** \n"  ;
            break ;

        case '5' :
            if(is_admin)
                goto Edit_account;
            cout << "YOU MUST GET ACCESS FROM ADMIN. DO YOU WANT CONTINUE?(y/n)\n>";
            char _choose ;
            cin >> _choose ;
            if(_choose == 'n'){
                break;
            }
            access = sign_in_admin();
            if(!access->allowAccess(cur_user)){
                cout <<"Sorry Admin deny your request" << endl;
                break ;
            }
            else{
                Edit_account:
                bool save_data =  edit_account_data(cur_user);
                if(save_data)
                    edit_file(*cur_user , "admin") ;
            }
            break ;

        case '6' :
            if(is_admin)
                goto delete_account ;
            cout << "YOU MUST GET ACCESS FROM ADMIN. DO YOU WANT CONTINUE?(y/n)\n>";
            cin >> _choose ;
            if(_choose == 'n'){
                break;
            }
            access = sign_in_admin();

            if(!access->allowAccess(cur_user)){
                cout <<"Sorry Admin deny your request" << endl;
                break ;
            }
            else{
                delete_account:
                edit_file(*cur_user ,"C"  , true) ;
                cout << "\nyour account deleted successfully\n";
                return;
            }

        case '7' :
            return ;

        case '8' :
            exit(0);
            break ;

        case '9':
            cout <<"\t> Enter Your Password\n>" ;

            do{
                en_pass-- ;
                cin >> password ;
                if(password != cur_user->getPass()){
                    cout <<"Invalid Password , [-]Please Try Again\n>" ;
                }
                if(en_pass == 0){
                    cout <<"Find Error , try again\n " ;
                    break ;
                }
            }while(password != cur_user->getPass());

            /// display all data
            cout << "-----------------------------------------------------------------------------------------------------------------------\n";
            cout << "||\tName                \tcard number     \tpersonal id   \tphone      \tbalance   \ttype\n\n";
            while (getline(file, data))
            {
//                cout << "||\t" ;
                vector<string> information = accline(data) ;
                for(auto i : information){
                    cout << i << '\t' ;
                }
                cout << "|| " ;
                ///"\n\t\t\t\t---------------------------------\n";
            }
            file.close();
            break ;

        default:
            cout << "unified choose";
            break;
    }
    if(is_admin){
        goto admin_menu;
    }
    else{
        goto client_menu;
    }
}

void sign_in(bool as_admin){

    string name, phone, password, personal_id , strage , strbalance , file_name = "data_client.txt" ;
    int age;
    double balance;
    ll card ;
    auto* cur_user = new Client() ;
    if(as_admin){
        file_name = "admin_data.txt" ;
        cur_user = new Admin() ;
    }

 SigIn:

    cout << "\t\t   ----------------------- \n"
         << "\t\t| Sign in to your account |\n"
         <<"\t\t   ----------------------- "
           "\n\n\t [-] Enter card id"
           "\n>";

     ifstream f_out(file_name ) ;
     bool fl = false ;
     string data ;

     do{
         cin >> card ;
         f_out.seekg(0, std::ios::beg);
         while(getline(f_out , data)){
             stringstream in(data);
             /// Data Format
             //card , pass , name  , age , phone ,  balance, id
             string str_card ;
             getline(in , str_card , ',') ;
             if(to_string(card) == str_card){
                 getline(in , password , ',') ;
                 getline(in , name , ',') ;
                 getline(in , strage , ',') ;
                 age = stoi(strage) ;
                 getline(in , phone , ',') ;
                 getline(in , strbalance , ',') ;
                 balance = stoi(strbalance) ;
                 getline(in , personal_id , ',') ;
 ////   client format (string name , string per , string pass , long long card , string phone , int age , double  bal)
                 if(as_admin){
                     cur_user = new Admin(name ,personal_id , password , card , phone , age , balance);
                 }
                 else
                    cur_user = new Client(name ,personal_id , password , card , phone , age , balance);
                 fl = true ;
             }
         }
         if(!fl)
            cout << "Card number not found in my data, please try again\n>";
     }while(!fl);

     // close file
     f_out.close() ;

     // check for password
    password = "" ;
    cout << "\t> Enter your password\n>";
    int try_time = 3 ;
     do{
          cin >> password ;
          try_time--;
          if(password != cur_user->getPass()) {
              cout <<"Wrong password , Please try again" << endl;
          }
          if(try_time == 0){
              cout <<"Find a error , Please tray again\n>" << endl;
              goto SigIn;
          }
     }while(password != cur_user->getPass()) ;

    log_in(cur_user , as_admin );
}

void edit_file(Client obj,const string& type, bool _delete){
     string file_name = (type == "admin") ? "admin_data.txt" : "data_client.txt" ;
     vector<string> datas ;
     string data ;

     ll card = obj.getCard() ;
     /// open file to read data

     ifstream fin(file_name) ;
     while(getline(fin , data)){

      /// to get only card number .
      string temp = data ;
      temp.resize(16);


       if(to_string(card) == temp){
      /// card , pass , name , age , phone , balance , id
           if(_delete){
               continue;
           }
           data = to_string(card) + ','
               + obj.getPass() + ','
               + obj.getName() + ','
               + to_string(obj.getAge())  + ','
               + obj.getPhon() + ','
               + to_string(obj.getBalance()) + ','
               + obj.getID() + ',' ;
       }
       datas.push_back(data) ;
     }
     fin.close() ;

     /// open the file and clear his data
     ofstream f_out(file_name ,ios::out | ios::trunc) ;
     for(auto i : datas){
         f_out << i << '\n' ;
     }
    f_out.close() ;
    return void(cout << "Successful Save Data \n" );

}

bool edit_account_data(Client* cur_client){
    Client clt ;
    int try_time = 3 ;
    vector<bool> option(4,false) ;
 Edit_Mnue :
    cout << "\n\t------ What do you want to edit ------"
            "\n|\t1- Name"
            "\n|\t2- Personal id"
            "\n|\t3- Phone number"
            "\n|\t4- Password"
            "\n|\t5- Return to account"
            "\n|\t6 - exit"
            "\n>";

    char opt ;
    cin >> opt ;
    string data ;
    switch (opt) {

        case '1' :
            get_data("name" , data) ;
            clt.setName(data) ;
            option[0] = true ;
            break ;

        case '2' :
            get_data("id" , data) ;
            clt.setID(data) ;
            option[1] = true ;
            break ;

        case '3' :
            get_data("phone" , data) ;
            clt.setPhone(data) ;
            option[2] = true ;
            break ;

        case '4' :
            get_data("password" , data) ;
            clt.setPass(data) ;
            option[3] = true ;
            break ;

        case '5' :
            return false;
        case '6' :
            exit(0) ;
            break ;

        default :
            cout<<"[-] Please Enter Valid Option" << endl;
            try_time-- ;
            if(try_time == 0){
                return false ;
            }
            goto Edit_Mnue ;
    }

    /// More Change
    cout << "[+]You Need Change Any thing again ? (y/n) \n>" ;
    char again = '?' ;
    do{
         cin >> again ;
        if(again != 'y' && again != 'n'){
             cout << "\t> Enter valid option\n>" ;
        }
    } while (again != 'y' && again != 'n');

    if(again == 'y'){
        goto  Edit_Mnue;
    }

    /// Save Change
    cout << "[+]You Need Save Your Change ? (y/n) \n>" ;
    again = '?' ;
    do{
        cin >> again ;
        if(again != 'y' && again != 'n'){
            cout << "\t>Enter valid option\n>" ;
        }
    } while (again != 'y' && again != 'n');


    if(again == 'y'){
        if(option[0]){
            cur_client->setName(clt.getName()) ;
        }
        if(option[1]){
            cur_client->setID(clt.getID()) ;
        }
        if(option[2]){
            cur_client->setPhone(clt.getPhon()) ;
        }
        if(option[3]){
            cur_client->setPass(clt.getPass()) ;
        }
    }
    return true ;
}

vector<string> accline(string data){
    // card , pass , name , age , phone , balance , id
    //  [0]    [1]   [2]    [3]    [4]     [5]      [6]
    vector<string> information(7) ;
    string card , pass , name , age , phone , balance , id ;
    stringstream informations(data) ;

    getline(informations , information[2]) ;
    getline(informations , information[0]) ;
    getline(informations , information[6]) ;
    getline(informations , information[4]) ;
    getline(informations , information[5]) ;
    getline(informations , information[5]) ;
    getline(informations , information[6]) ;

    return information ;
}