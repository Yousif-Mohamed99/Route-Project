#include <iostream>
using namespace std;

class Person
{
protected:
    int id;
    string name;
    string password;
    double balance;

public:

  Person (string name, string password, int id, double balance) : id(id)
  {
    if(name.size() >= 5 && name.size() <= 20)
    {
      this->name = name;
    }
    else
    {
      cout << "Error name \n";
    }
    if(password.size() >= 8 && password.size() <= 20)
    {
      this->password = password;
    }
    else
    {
      cout << "Error password \n";
    }
    if(balance > 1500 )
    {
      this->balance = balance;
    }
    else
    {
      cout << "Min Balance Is: 1500, Please Try Again!";
    }
  }

  void setName (string name)
  {
    if(name.size() >= 8 && name.size() <= 20)
    this->name = name;
    else cout << "Min size is 5 and max is 20\n";
  }
  void setPassword(string password)
  {
    if(password.size() >= 8 && password.size() <= 20) 
    this->password = password;
    else cout << "Min size is 8 and max is 20\n";
  }
  void setBalance(double balance)
  {
    if(balance > 1500)
    {
      this->balance = balance;
    }
    else
    {
      cout << "Min balance is 1500\n";
    }
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

class Client : public Person
{

public:
  Client (string name, string password, int id, double balance) : Person(name,password,id,balance)
  {
  }
  void deposit(double amount)
  {
    balance += amount;
    cout << "Successful Transcation\n";
    cout << "your balance is: " << balance << endl;
  }
  void withdraw (double amount)
  {
    if(amount < balance)
    {
      balance -=amount;
      cout << "Successful Transcation\n";
      cout << "your balance is: " << balance << endl;
      return;
    }
    else cout << "Your balance is insufficient\n";
  }
  void transferTo (int amount, Client &recipient)
  {
    if (amount < balance)
    {
      recipient.balance += amount;
      balance -= amount;
      cout << "Successful Transcation\n";
    }
    else
    {
      cout << "Insufficient Funds To Execute The Transaction\n";
    }
  }
  void checkBalance()
  {
    cout << "Your balance is: " << balance <<endl;
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
  return 0;
}
