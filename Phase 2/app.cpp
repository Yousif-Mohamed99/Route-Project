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

  int getId() const
  {
    return id;
  }
  string getName() const
  {
    return name;
  }
  string getPassword() const
  {
    return password;
  }
  void display() const
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
  double getBalance() const
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
  void checkBalance() const 
  {
    cout << "Your balance is: " << balance <<endl;
  }
  void display() const
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
  vector<Client> clients;
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

  double getSalary() const
  {
    return salary;
  }

  void display() const
  {
    Person::display();
    cout << "\n Your Salary is: " << salary;
  }

  void addClient(Client& client) 
  {
    clients.push_back(client);
  }

  Client* searchClient(int id) 
  {
    for (Client& client : clients) 
    {
      if (client.getId() == id) 
      {
      return &client;
      }
    }
    cout << "Client with ID " << id << " not found!" << endl;
    return 0;
  }

  void listClients() const 
  {
    if (clients.empty()) 
    {
      cout << "No clients found." << endl;
      return;
    }
    for (const Client& client : clients) 
    {
      client.display();
      cout << endl;
    }
  }

  void editClient(int id, string name, string password, double balance) 
  {
    Client* client = searchClient(id);
    if (client != nullptr) 
    {
      client->setName(name);
      client->setPassword(password);
      client->setBalance(balance);
      cout << "Client details updated successfully!" << endl;
    }
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
  vector<Client> clients;
  vector<Employee> employees;
public:
  Admin(string name, int id, string password, double salary) : Person(name, id, password)
  {
    this->salary = salary;
  }

  int getSalary() const 
  {
    return salary;
  }

  void addClient(Client& client) 
  {
    clients.push_back(client);
  }

  Client* searchClient(int id) 
  {
    for (Client& client : clients) 
    {
    if (client.getId() == id)
      {
        return &client;
      }
    }
    cout << "Client with ID " << id << " not found!" << endl;
    return nullptr;
    }

    void listClients() const 
    {
      if (clients.empty()) 
      {
        cout << "No clients found." << endl;
        return;
      }
      for (const Client& client : clients) 
      {
        client.display();
        cout << endl;
      }
    }

    void editClient(int id, string name, string password, double balance) 
    {
        Client* client = searchClient(id);
        if (client != nullptr) 
        {
            client->setName(name);
            client->setPassword(password);
            client->setBalance(balance);
            cout << "Client details updated successfully!" << endl;
        }
    }

    void addEmployee(Employee& employee) 
    {
        employees.push_back(employee);
    }

    Employee* searchEmployee(int id) 
    {
        for (Employee& employee : employees) 
        {
          if (employee.getId() == id) 
          {
            return &employee;
          }
        }
        cout << "Employee with ID " << id << " not found!" << endl;
        return nullptr;
    }

    void editEmployee(int id, string name, string password, double salary) 
    {
        Employee* employee = searchEmployee(id);
        if (employee != nullptr) {
            employee->setName(name);
            employee->setPassword(password);
            employee->setSalary(salary);
            cout << "Employee details updated successfully!" << endl;
        }
    }

    void listEmployees() const 
    {
        if (employees.empty()) 
        {
          cout << "No employees found." << endl;
          return;
        }
        for (const Employee& employee : employees) 
        {
          employee.display();
          cout << endl;
        }
    }

    void saveToFile() {
        ofstream adminFile("Admin.txt", ios::app);
        if (adminFile.is_open()) {
            adminFile << getId() << " " << getName() << " " << getPassword() << " " << salary << endl;
            adminFile.close();
        } else {
            cout << "Unable to open Admin.txt file.\n";
        }
    }

  void saveToFile() 
  {
    ofstream adminFile("Admin.txt", ios::app);
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


class FilesHelper 
{
public:

  static vector<Client> loadClientsFromFile() 
  {
    ifstream clientFile("Clients.txt");
    vector<Client> clients;
    if (clientFile.is_open()) 
    {
      int id;
      string name;
      string password;
      double balance;
      while (clientFile >> id >> name >> password >> balance) 
      {
        Client client(name, id, password, balance);
        clients.push_back(client);
      }
      clientFile.close();
    } 
    else 
    {
      cout << "Unable to open Clients.txt file.\n";
    }

    return clients;
    }

  static vector<Employee> loadEmployeesFromFile() 
  {
    ifstream employeeFile("Employee.txt");
    vector<Employee> employees;
    if (employeeFile.is_open()) 
    {
      int id;
      string name;
      string password;
      double salary;
      while (employeeFile >> id >> name >> password >> salary) 
      {
        Employee employee(name, id, password, salary);
        employees.push_back(employee);
      }
      employeeFile.close();
    } 
    else 
    {
        cout << "Unable to open Employee.txt file.\n";
    }

    return employees;
  }

  static vector<Admin> loadAdminsFromFile() 
  {
    ifstream adminFile("Admin.txt");
    vector<Admin> admins;
    if (adminFile.is_open()) 
    {
      int id;
      string name;
      string password;
      double salary;
      while (adminFile >> id >> name >> password >> salary) 
      {
        Admin admin(name, id, password, salary);
        admins.push_back(admin);
      }
      adminFile.close();
    } 
    else 
    {
      cout << "Unable to open Admin.txt file.\n";
    }

    return admins;
  }
};

class FileManager : public DataSourceInterface 
{
public:
  void addClient(const Client& client) override 
  {
    ofstream clientFile("Clients.txt", ios::app);
    if (clientFile.is_open()) 
    {
        clientFile << client.getId() << " " << client.getName() << " " << client.getPassword() << " " << client.getBalance() << endl;
        clientFile.close();
    } 
    else 
    {
      cout << "Error opening Clients.txt\n";
    }
  }

  void addEmployee(const Employee& employee) override 
  {
    ofstream employeeFile("Employee.txt", ios::app);
    if (employeeFile.is_open()) 
    {
      employeeFile << employee.getId() << " " << employee.getName() << " " << employee.getPassword() << " " << employee.getSalary() << endl;
      employeeFile.close();
    } 
    else 
    {
      cout << "Error opening Employee.txt\n";
    }
  }

  void addAdmin(const Admin& admin) override 
  {
    ofstream adminFile("Admin.txt", ios::app);
    if (adminFile.is_open()) 
    {
      adminFile << admin.getId() << " " << admin.getName() << " " << admin.getPassword() << " " << admin.getSalary() << endl;
      adminFile.close();
    } 
    else 
    {
      cout << "Error opening Admin.txt\n";
    }
  }

    vector<Client> getAllClients() override {
        ifstream clientFile("Clients.txt");
        vector<Client> clients;
        
        if (clientFile.is_open()) {
            int id;
            string name;
            string password;
            double balance;
            
            while (clientFile >> id >> name >> password >> balance) {
                Client client(name, id, password, balance);
                clients.push_back(client);
            }
            clientFile.close();
        } else {
            cout << "Error opening Clients.txt\n";
        }

        return clients;
    }

  vector<Employee> getAllEmployees() override
  {
    ifstream employeeFile("Employee.txt");
    vector<Employee> employees;
    if (employeeFile.is_open()) 
    {
      int id;
      string name;
      string password;
      double salary;
      while (employeeFile >> id >> name >> password >> salary) 
      {
        Employee employee(name, id, password, salary);
        employees.push_back(employee);
      }
      employeeFile.close();
    } 
    else 
    {
      cout << "Error opening Employee.txt\n";
    }
    return employees;
  }

    vector<Admin> getAllAdmins() override {
        ifstream adminFile("Admin.txt");
        vector<Admin> admins;
        
        if (adminFile.is_open()) {
            int id;
            string name;
            string password;
            double salary;
            
            while (adminFile >> id >> name >> password >> salary) {
                Admin admin(name, id, password, salary);
                admins.push_back(admin);
            }
            adminFile.close();
        } else {
            cout << "Error opening Admin.txt\n";
        }

        return admins;
    }

    void removeAllClients() override {
        ofstream clientFile("Clients.txt", ios::trunc); // Truncate to clear
        if (clientFile.is_open()) {
            cout << "All clients removed from Clients.txt.\n";
            clientFile.close();
        } else {
            cout << "Error opening Clients.txt\n";
        }
    }

    void removeAllEmployees() override {
        ofstream employeeFile("Employee.txt", ios::trunc);
        if (employeeFile.is_open()) {
            cout << "All employees removed from Employee.txt.\n";
            employeeFile.close();
        } else {
            cout << "Error opening Employee.txt\n";
        }
    }

    void removeAllAdmins() override {
        ofstream adminFile("Admin.txt", ios::trunc);
        if (adminFile.is_open()) {
            cout << "All admins removed from Admin.txt.\n";
            adminFile.close();
        } else {
            cout << "Error opening Admin.txt for truncation.\n";
        }
    }
};

int main()
{
  // FileManager fileManager;

  //   Client newClient("JohnDoe", 1, "password123", 5000.0);
  //   fileManager.addClient(newClient);

  //   Employee newEmployee("JaneDoe", 2, "password456", 6000.0);
  //   fileManager.addEmployee(newEmployee);

  //   Admin newAdmin("AdminOne", 3, "password789", 10000.0);
  //   fileManager.addAdmin(newAdmin);

  //   vector<Client> clients = fileManager.getAllClients();
  //   for (Client client : clients) 
  //   {
  //     client.display();
  //   }

  //   vector<Employee> employees = fileManager.getAllEmployees();
  //   for (Employee employee : employees) 
  //   {
  //     employee.display();
  //   }

  //   vector<Admin> admins = fileManager.getAllAdmins();
  //   for (Admin admin : admins) 
  //   {
  //     admin.display();
  //   }

  return 0;
}
