#include <iostream>
using namespace std;

class Person{

protected:
    int id;
    string name;
    string password;
    double balance;

public:

    Person (string name, string password, int id, double balance) : id(id)
    {
        ///set name on constructor
        if(name.size() >= 8 && name.size() <= 20)
        {
            this->name = name;
        }
        else{
            cout << "Error name \n";
            cout << "Use setName to setter\n";
        }
        ///set password on constructor
        if(password.size() >= 8 && password.size() <= 20)
        {
            this->password = password;
        }else{
            cout << "Error password \n";
            cout << "Use setPassword to setter\n";
        }
        ///set balance on constructor
        if(balance >1500)
        {
            this->balance = balance;
        }
    }

    void setName (string name)
    {
        if(name.size() >= 8 && name.size() <= 20)
        {
            this->name = name;
            return;
        }
        cout << "Error Please enter name less 2 and more 8 \n";
        cin >> name;
    }
    void setPassword(string password)
    {
        if(password.size() >= 8 && password.size() <= 20)
        {
            this->password = password;
        }
        else{
            cout << "Error Please enter name less 2 and more 8 \n";
            cin >> password;
        }
    }
    virtual setBalance(double balance)
    {
        this->balance = balance;
    }

    string getName()
    {
        return name;
    }
    string getPassword()
    {
        return password;
    }
    int getID()
    {
        return id;
    }
    double getBalance()
    {
        return balance;
    }
};

class Client : public Person{

public:
    Client (string name, string password, int id, double balance) : Person(name,password,id,balance)
    {
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "done \n";
        cout << "your balance is: " <<balance <<endl;
    }
    void withdraw (double amount)
    {
        if (amount > balance){
            cout << "Error \n";
            return;
        }
        balance -=amount;
        cout << "done \n";
        cout << "your balance is: " <<balance <<endl;
    }
    void transferTo (int amount, Client &recipient){
        if (amount < balance){

            balance -= amount;
            recipient.balance += amount;
            cout << "done \n";
        }
        else{
            cout << "Error \n";
        }
    }
    void checkBalance(){
        cout << balance<<endl;
    }
    void display()
    {
        cout << name<<endl;
        cout << id <<endl;
        cout << balance<<endl;
    }
};


int main()
{

    Client c("ahmed","231",2,333333);

    c.display();
    return 0;
}
