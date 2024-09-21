#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Person
{
protected:
  int id;
  string name;
  string password;
public:
  Person (string name, int id, string password)
  {
    this->name = name;
    this->id = id;
    this->password = password;
  }
  void setName(string name) 
  {
  bool flag = true;
  for (int i = 0; i < name.size(); i++) 
    {
      if (!isalpha(name[i]))
      {
        flag = false;
        break;
      }
    }
    if (flag && (name.size() >= 5 && name.size() <= 20)) 
    {
      this->name = name;
    }
    else 
    {
      cout << "Retry to enter the name; the name must be alphabetic chars and min size 5 and max size 20\n";
    }
  }

  void setPassword(string password) 
  {
    if (password.size() >= 8 && password. size()<= 20) 
    {
      this->password = password;
    }
    else 
    {
      cout << "Retry to enter a password, Password must be with min size 8 and max size 20\n";
    }
  }

  int getId()
  {
    return id;
  }
  string getName()
  {
    return name;
  }
  string getPassword()
  {
    return password;
  }
  void display()
  {
    cout << "Your name is: " << name<< endl;
    cout << "Your id is: " << id << endl;
    cout << "Your password is: " << password << endl;
  }
};

class Client : public Person
{
private:
  double balance;
public:
  Client (string name, int id, string password, double balance) : Person(name,id,password)
  {
    this->balance = balance;
  }
  void setBalance(double balance) 
  {
    if (balance >= 1500) 
    {
      this->balance = balance;
    }
    else 
    {
      cout << "Balance must be greater than or equal to 1500\n";
    }
  }
  double getBalance()
  {
    return balance;
  }

  void deposit(double amount)
  {
    if (amount < 0)
    {
      cout << "Amount to deposit cannot be negative";
      return;
    }
    balance += amount;
    cout << "Successful Transcation\n";
    cout << "your balance is: " << balance << endl;
  }
  void withdraw (double amount)
  {
    if (amount < 0)
    {
      cout << "Amount to withdraw cannot be negative";
      return;
    }
    if(amount < balance)
    {
      balance -=amount;
      cout << "Successful Transcation\n";
      cout << "your balance is: " << balance << endl;
      return;
    }
    else cout << "Your balance is insufficient\n";
  }
  void transferTo (double amount, Client &recipient)
  {
    if (amount < 0)
    {
      cout << "Amount to transfer cannot be negative";
      return;
    }
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
    Person::display();
    cout << "Your balance is: " << balance <<endl;
  }

  void saveToFile() 
{
  ofstream clientFile("Clients.txt", ios::app);
  if (clientFile.is_open()) 
  {
    clientFile << id << " " << name << " " << password << " " << balance << endl;
    clientFile.close();
  } 
  else
  {
    cout << "Unable to open Clients.txt file.\n";
  }
}
};

class Employee : public Person 
{
private:
  double salary;
public:
  Employee(string name, int id, string password, double salary) : Person(name, id, password)
  {
    setSalary(salary);
  }
  void setSalary(double salary) 
  {
    if (salary >= 5000) 
    {
      this->salary = salary;
    }
    else 
    {
      cout << "Salary must be greater than or equal to 5000\n";
    }
  }

  void display() 
  {
    Person::display();
    cout << "\n Your Salary is: " << salary;
  }

  void saveToFile() 
  {
    ofstream employeeFile("Employee.txt", ios::app);
    if (employeeFile.is_open()) 
    {
      employeeFile << id << " " << name << " " << password << " " << salary << endl;
      employeeFile.close();
    } 
    else 
    {
      cout << "Unable to open Employee.txt file.\n";
    }
}

};

class Admin : public Person
{
  double salary;
public:
  Admin(string name, int id, string password, double salary) : Person(name, id, password)
  {
    this->salary = salary;
  }
  void saveToFile() 
  {
    ofstream adminFile("Admin.txt", ios::app); // Open in append mode
    if (adminFile.is_open()) 
    {
      adminFile << id << " " << name << " " << password << " " << salary << endl;
      adminFile.close();
    } 
    else 
    {
      cout << "Unable to open Admin.txt file.\n";
    }
}
};

class DataSourceInterface 
{
public:
  virtual void addClient(const Client& client) = 0;
  virtual void addEmployee(const Employee& employee) = 0;
  virtual void addAdmin(const Admin& admin) = 0;
  virtual vector<Client> getAllClients() = 0;
  virtual vector<Employee> getAllEmployees() = 0;
  virtual vector<Admin> getAllAdmins() = 0;
  virtual void removeAllClients() = 0;
  virtual void removeAllEmployees() = 0;
  virtual void removeAllAdmins() = 0;
};


int main()
{
  return 0;
}