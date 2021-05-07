#include <iostream>
#include <string>
using namespace std;


class Employee
{
protected: double salary, expierence_;

public:
	int id, number_of_projects_completed;
	string name, designation;
	bool employee_is_permanent;
	string junior = "junior"; // lower position

	string senior = "senior"; // higher position

	Employee(int id , string name , double salary, double expierence_, string designation , int number_of_projects_completed)
	{
		this->id = id;
		this->name = name;
        this->expierence_ = expierence_;
		this->salary = salary;
		this->employee_is_permanent = false;
		this->designation = designation;
		this->number_of_projects_completed = number_of_projects_completed;
		
	}
	~Employee()
	{
		cout << "Destructor is called." << endl;
	}
	 void  display()
	{
		cout << "============================================================================================\n";
		cout << "                                      OVERALL DATABASE                                      \n";
		cout << "============================================================================================\n";
		cout << "ID"
			<< "\t"
			<< "NAME"
			<< "\t"
			<< "PROJECT COMPLETED"
			<< "\t"
			<< "Designation"
			<< "\t"
			<< "SALARY"
			<< "\t"
			<< "EXPERIENCE"
			<< "\t"
			<< "Permanent?";
		cout << "\n============================================================================================\n";
		cout << this->id;
		cout << this->name;
		cout << this->number_of_projects_completed;
		cout << this->designation;
		cout << this->salary;
		cout << this->expierence_;
		cout << this-> employee_is_permanent;
		cout << endl;
		cout << endl;
	}
	friend class Manager;
	friend void switch_statements();

	bool operator<(const Employee &d)
	{
		if (junior == designation && senior == d.designation)
		{
			return true;
		}
		return false;
	}
	
};

class Manager : public Employee
{
public:
	   Manager(int id, string name, double salary, double expierence_, string designation, int number_of_projects_completed) : Employee(id, name , salary, expierence_, designation, number_of_projects_completed )
	   {
		   //we simply pass stuff to employee constructor.
	   }

	   

	   ~Manager()
	   {
		  cout << "Destructor is called." << endl;
	   }

	   void appraise_employee(Employee *e)
	   {
		   if (e->employee_is_permanent == true) {
			   try
			   {
				   if (e->number_of_projects_completed > 0)
				   {
					   e->salary = e->salary + (e->number_of_projects_completed * 1000);

					   cout << "Employee Appraised" << endl;
				   }

				   else
				   {
					   throw runtime_error("Employee couldn't be appraised");
				   }
			   }

			   catch (runtime_error& E)
			   {
				   cout << "Employee salary could not be assigned." << endl;
			   }
		   }
		   else
		   {

			   cout << "Employee is not permanent and can't be appraised." << endl;
		   }
	   }
	   friend class   HeadDepartment;


	   bool operator<(const Manager &d)
	   {
		   if (junior == designation && senior == d.designation)
		   {
			   return true;
		   }
		   return false;
	   }
};

void make_employee_permanent(Employee *e)
{
	try {
		if (e->employee_is_permanent == false) {

			e->employee_is_permanent = true;

			cout << "Employee is permanent now!" << endl;
		}
		else {

			throw runtime_error("Employee is already permanent");
		}
	}
		catch (runtime_error& E)
		{
			cout << "Employee is already permanent. How permanent you want him to be???" << endl;
		}
		
	}




class HeadDepartment 
{

public: int id;

	HeadDepartment(int id) 
	{
		this->id = id;
	}
	void manager_salary_appraise(Manager *m)
	{
		if (m->employee_is_permanent == true) {
			try
			{
				if (m->number_of_projects_completed > 0)
				{
					m->salary = m->salary + (m->number_of_projects_completed * 3000);

					cout << "Manager Appraised" << endl;
				}

				else
				{
					throw runtime_error("Employee couldn't be appraised");
				}
			}

			catch (runtime_error& E)
			{
				cout << "Manager salary could not be assigned." << endl;
			}
		}
		else
		{

			cout << "Manager is not permanent and can't be appraised." << endl;
		}
	}

};


void create_employee()
{

	
		int id, number_of_projects_completed;
		string name, designation;
		double salary, expierence;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;
		cout << "!!!           WELCOME TO COMPANY MANAGEMENT SYSTEM           !!! " << endl;
		cout << "!!!                     ~REGISTRATION MENU~                  !!! " << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;
		cout << "                             Enter the id                        " << endl;
		cin >> id;
		cout << "                             Enter the name                      " << endl;
		cin >> name;
		cout << "                             Enter the Salary                    " << endl;
		cin >> salary;
		cout << "                             Enter the Expierence                " << endl;
		cin >> expierence;
		cout << "                             Enter the Designation(j/s)          " << endl;
		cin >> designation;
		cout << "                             Enter the No. of projects done      " << endl;
		cin >> number_of_projects_completed;

		Employee *e = new Employee(id, name, salary, expierence, designation, number_of_projects_completed);

		
	
}

void create_manager()
{
	int id, number_of_projects_completed;
	string name, designation;
	double salary, expierence;
	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;
	cout << "!!!           WELCOME TO COMPANY MANAGEMENT SYSTEM           !!! " << endl;
	cout << "!!!                     ~REGISTRATION MENU~                  !!! " << endl;
	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;
	cout << "                             Enter the id                        " << endl;
	cin >> id;
	cout << "                             Enter the name                      " << endl;
	cin >> name;
	cout << "                             Enter the Salary                    " << endl;
	cin >> salary;
	cout << "                             Enter the Expierence                " << endl;
	cin >> expierence;
	cout << "                             Enter the Designation(j/s)          " << endl;
	cin >> designation;
	cout << "                             Enter the No. of projects done      " << endl;
	cin >> number_of_projects_completed;
	
	Manager *m = new Manager(id, name, salary, expierence, designation, number_of_projects_completed);
}

void display_employee(Employee *e)
{
	e->display();

}

void delete_manager(Manager *m)
{

	delete m;
}
void delete_employee(Employee *e)
{

	delete e;
}

void display_Manager(Manager *m)
{
	m->display();  // NOLINT(modernize-use-auto)

}



int main()
{
	HeadDepartment *h = new HeadDepartment(1);
	Employee *e = new Employee(1, "name", 20.00, 1.00, "senior", 100);
	Manager *m = new Manager(1, "name", 20.00, 1.00, "senior", 100);
	Employee *e1 = new Employee(1, "name", 20.00, 1.00, "senior", 100); //default we gonna be comparing to
	Manager *m1 = new Manager(1, "name", 20.00, 1.00, "senior", 100); //default we gonna be comparing to
	int options;

	for (int i = 10; i > 1; i++) {
		

		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;
		cout << "!!!           WELCOME TO COMPANY MANAGEMENT SYSTEM           !!! " << endl;
		cout << "!!!                     ~REGISTRATION MENU~                  !!! " << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;

		cout << "1: Create Employee                                               " << endl;
		cout << "2: Create Manager                                                " << endl;
		cout << "3: Continue Program                                              " << endl;
		cout << "4: Exit Program                                                  " << endl;
		cin >> options;
		switch (options)
		{

		case 1:
			create_employee();
			
			break;

		case 2:
			create_manager();
		
			break;
		case 3:
			i = -1;

			break;
	
		case 4:
			exit(EXIT_SUCCESS);
			break;
			
		default:
			cout << "You didn't enter a valid input." << endl;
			break;
		}
	}

	for (int i = 10; i > 1; i++) {


		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;
		cout << "!!!           WELCOME TO COMPANY MANAGEMENT SYSTEM           !!! " << endl;
		cout << "!!!                     ~REGISTRATION MENU~                  !!! " << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;

		cout << "1: Display Employee                                              " << endl;
		cout << "2: Display Manager                                               " << endl;
		cout << "3: Delete Employee                                               " << endl;
		cout << "4: Delete Manage                                                 " << endl;
		cout << "5: Appraise Employee                                             " << endl;
		cout << "6: Appraise Manage                                               " << endl;
		cout << "7: Compare Employee to default employee                          " << endl;
		cout << "8: Compare Employee to default manager                           " << endl;
		cout << "9: Make Employee Permanent                                       " << endl;
		cout << "10: Exit Program                                                 " << endl;
		cin >> options;
		switch (options)
		{

		case 1:
			display_employee(e);

			break;

		case 2:
			display_Manager(m);

			break;
		case 3:
			delete_employee(e);

			break;
		case 4:
			delete_manager(m);

			break;
		case 5:

			m->appraise_employee(e);
			break; 

		case 6:
			h->manager_salary_appraise(m);
			break;
		case 7:
			if (e < e1)
			{
				cout << "Employee 1 is lower position than Employee 2 " << endl;
			}
			else
			{
				if (e1 < e)
				{
					cout << "Employee 2 is lower position than Employee 1 " << endl;
				}
				else
				{

					cout << "Both Employee have same position" << endl;
				}
			}
		
			break;
		case 8:
			if (m < m1)
			{
				cout << "Employee 1 is lower position than Employee 2 " << endl;
			}
			else
			{
				if (m1 < m)
				{
					cout << "Employee 2 is lower position than Employee 1 " << endl;
				}
				else
				{

					cout << "Both Employee have same position" << endl;
				}
			}

			break;

		case 9:

			make_employee_permanent(e);
			break;

		case 10:
			exit(EXIT_SUCCESS);
			break;

		default:
			cout << "You didn't enter a valid input." << endl;
			break;
		}
	}

	

	return 0;
}

