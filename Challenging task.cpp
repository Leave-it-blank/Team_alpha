#include <fstream>
#include <iostream>
using namespace std;

class Employee
{

public:
    int ID;

    string Name, Designation;

    double Salary, Exp;

    bool Employee_is_permanent;

    int Number_of_projects_completed;

    Employee(int ID, string Name, string Designation, double Salary, double Exp, int Number_of_projects_completed)
    {

        this->ID = ID;

        this->Name = Name;

        this->Designation = Designation;

        this->Salary = Salary;

        this->Number_of_projects_completed = Number_of_projects_completed;

        this->Employee_is_permanent = false;
    }

    ~Employee()
    {
        cout << "Destructor is called here." << endl;
    }

    void DisplayEmployee()
    {

        cout << "ID is: " << ID << endl;

        cout << "Name is: " << ID << endl;

        cout << "Designation is: " << Name << endl;

        cout << "Salary is: " << Salary << endl;

        cout << "Project completed is: " << Number_of_projects_completed << endl;
    }
    void createfileEmp()
    {
        ifstream obj("Myfile.txt");
        if (obj.is_open())
        {
            obj << Salary;
            obj << Name;
            obj << Number_of_projects_completed;
            obj << ID;
            obj << Exp;
        }
        obj.close();
    }
};

class Manager : public virtual Employee // polymorphism //encapsulation
{
public:
    int bonus;
    Manager(int ID, string Name, string Designation, double Salary, double Exp, int Number_of_projects_completed) : Employee(ID, Name, Designation, Salary, Exp, Number_of_projects_completed)
    {
        this->Employee_is_permanent = true;
    }
    void AppraiseEmployee(Employee *E)
    {
        if (E->Employee_is_permanent = true)
            try
            {
                if (E->number_of_projects_completed > 0)
                {
                    E->salary = E->salary + (E->number_of_projects_completed * 5000);

                    cout << "Manager Appraised" << endl;
                }

                else
                {

                    throw runtime_error("Employee couldn't be appraised");
                }
            }

            catch (runtime_error &E)
            {

                cout << "Employ salary could not be assigned." << endl;
            }
    }
    else
    {

        cout << "Employee is not permanent and can't be appraised." << endl;
    }

} ~Manager()
{
    cout << "Destructor is called" << endl;
}
void createfile()
{
    ifstream obj("Myfile.txt");
    if (obj.is_open())
    {
        obj << Salary;
        obj << Name;
        obj << Number_of_projects_completed;
        obj << ID;
        obj << Exp;
    }
    obj.close();
}

void make_employe_permanent(Employee *E)
{
    E->Employee_is_permanent = true;
}

friend class LibDepartment;
}
;

class Department
{ // abstract class
public:
    int id;
    void virtual managersalaryappraise() = 0; //pure virtual function, abstract function, cannot have implementations

    void virtual display() = 0;
};

class LibDepartment : public virtual Department
{

public:
    LibDepartment(int id) : Department()
    {
        this->id = id;
    }

    void virtual managersalaryappraise(Manager *M)
    {
        try
        {
            if (M->number_of_projects_completed > 0)
            {
                M->salary = M->salary + (M->number_of_projects_completed * 5000);

                cout << "Manager Appraised" << endl;
            }

            else
            {

                throw runtime_error("Employee couldn't be appraised");
            }
        }

        catch (runtime_error &M)
        {

            cout << "Employ salary could not be assigned." << endl;
        }
    }

    void virtual display()
    {
    }
};
int main()
{
    Employee obj;
    Manager obj1;
    Department obj2;
    int ID;
    string Name;
    string Designation;
    double Salary;
    double Exp;
    int Number_of_projects_completed;

    LibDepartment *L = LibDepartment(1);

    for (int i = 10; i > 1; i++)
    {
        int number;

    
      
        cout << "Enter the value from the following" << endl;
        cout << "1: Create Employee " << endl;
        cout << "2: Create Manager " << endl;
        cout << "3: Display Employee " << endl;
        cout << "4: Display manager " << endl;
        cout << "5: Appraise Manager Salary " << endl;
        cout << "6: Appraise Empoyee Salary " << endl;
        cout << "7:Make employee permanent" << endl;
        cout << "8:Upload data to file for employee" << endl;
        cout << "9:Upload data to file for Manager" << endl;
        cout << "10:Exit" << endl;
        cin >> number;
        switch (number)
        {
        case 1:
            cout << "Enter the details of the Employee" << endl;
            cout << "ID" << endl;
            cin >> ID;
            cout << "Name" << endl;
            cin >> Name;
            cout << "Designation" << endl;
            cin >> Designation;
            cout << "Salary" << endl;
            cin >> Salary;
            cout << "Exp" << endl;
            cin >> Exp;
            cout << "Number_of_projects_completed" << endl;
            cin >> Number_of_projects_completed;
            Employee *E = new Employee(ID, Name, Designation, Salary, Exp, Number_of_projects_complete);
            break;

        case 2:
            // code block
            cout << "Enter the details of the Employee" << endl;
            cout << "ID" << endl;
            cin >> ID;
            cout << "Name" << endl;
            cin >> Name;
            cout << "Designation" << endl;
            cin >> Designation;
            cout << "Salary" << endl;
            cin >> Salary;
            cout << "Exp" << endl;
            cin >> Exp;
            cout << "Number_of_projects_completed" << endl;
            cin >> Number_of_projects_completed;
            cin >> Number_of_projects_completed;
            Manager *M = new Manager(ID, Name, Designation, Salary, Exp, Number_of_projects_complete);
            break;
        case 3:
            E->DisplayEmployee();
            break;
        case 4:
            // code block
            M->DisplayEmployee();
            break;
        case 5:
            L->managersalaryappraise(M) break;
        case 6:
            M->AppraiseEmployee(E);
            break;

        case 7:
            M->make_employe_permanent(E);
            break;
     
        case 8:
            E->createfileEmp();
            break;
        case 9:
            M->createfile();
            break;
        case 10:

            exit(EXIT_SUCCESS);
            break;
            //exit the program logic
        default:
            cout << "You didn't enter a valid input." << endl;
            break;
        }
    }
}
