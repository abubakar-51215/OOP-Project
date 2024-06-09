#include <iostream>
#include <iomanip>
#include <fstream>
#include <iomanip>
using namespace std;

class Employee
{
    int id;
    string name;
    string address;
    int phone_no;
    int age;
    string user_name;
    string password;
    string designation;
    double salary;

public:
    void EmpMenu() // Emp fun
    {
        int choice;

        system("cls");

        cout << "************************************************" << endl;
        cout << "*                                              *" << endl;
        cout << "*         Welcome to the Employee Portal!      *" << endl;
        cout << "*                                              *" << endl;
        cout << "************************************************" << endl;
        cout << "*                                              *" << endl;
        cout << "*  1. Check your record                        *" << endl;
        cout << "*  2. Calculate your salary                    *" << endl;
        cout << "*  3. Change password                          *" << endl;
        cout << "*  4. Exit                                     *" << endl;
        cout << "*                                              *" << endl;
        cout << "************************************************" << endl;
        cout << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
        {
            cout << "You chose to check your record." << endl
                 << endl;

            system("pause");
            system("cls");
            CheckRecord();
            break;
        }
        case 2:
        {
            cout << "You chose to calculate your salary." << endl
                 << endl;

            system("pause");
            system("cls");
            Salary_calculate();
            break;
        }
        case 3:
        {
            cout << "You chose to change your password." << endl;

            system("pause");
            system("cls");
            ChangePass();
            break;
        }

        case 4:
        {
            cout << "Good Bye!" << endl;

            exit(0);
        }
        default:
            cout << "Invalid choice. Please choose again." << endl;
            break;
        }
    }

    void EmpLogin() // emp function
    {
        cout << "Welcome to the Employee Login!" << endl
             << endl;
        int login_check;
        string pass, unn, _user_name, _password;
        int id_;
    again:
        cout << "Enter user name: ";
        cin >> unn;

        cout << "Enter password: ";
        cin >> pass;

        ifstream login2; // now retrive data

        login2.open("login1.txt");

        while (!login2.eof())
        {

            login2 >> id_ >> _user_name >> _password;

            if (unn == _user_name && pass == _password)
            {

                login_check = 1;
            }
        }
        login2.close();

        if (login_check == 1)
        {
            EmpMenu();
        }

        else
        {
            cout << "Wrong password. Enter correct password. " << endl
                 << endl;

            goto again;
        }
    }

    void setDetails(int id_, string n, string a, int pn, int ag, string un, string p, string d, double s) // this will store value in datamember of class and in files
    {
        id = id_;
        name = n;
        address = a;
        phone_no = pn;
        age = ag;
        user_name = un;
        password = p;
        designation = d;
        salary = s;

        ofstream login; // this file store only un and pass

        login.open("login1.txt", ios::app);

        login << id << " " << user_name << " " << password << endl;

        login.close();

        ofstream record; // this file store all record of emp

        record.open("record1.txt", ios::app);

        record << id << " " << name << " " << phone_no << " " << age << " " << address << " " << designation << " " << salary << endl;

        record.close();

        ofstream Uniqueid;

        Uniqueid.open("Empid.txt", ios::app);

        Uniqueid << id << endl;

        Uniqueid.close();
    }

    void CheckRecord() // emp fun
    {

        int id; // user value
        int count = 0;
        int id2; // to show in record
        string name;
        string address;
        int contact;
        int age;
        string designation;
        double salary;
    againID:
        cout << "Enter your id to see your record: ";
        cin >> id;

        ifstream checkFile; // to view record by id retrive id from file 1st than give all data

        checkFile.open("record1.txt");

        checkFile >> id2 >> name >> contact >> age >> address >> designation >> salary;

        while (checkFile.eof() == 0)
        {

            if (id == id2)
            {

                cout << "Your Record" << endl
                     << endl;

                cout << "ID: " << id2 << endl;
                cout << "Name: " << name << endl;
                cout << "Address: " << address << endl;
                cout << "Contact: " << contact << endl;
                cout << "Age: " << age << endl;
                cout << "Designation: " << designation << endl;
                cout << "Salary Per hour $ " << salary << endl;

                count = 1;
            }
            checkFile >> id2 >> name >> contact >> age >> address >> designation >> salary;
        }

        checkFile.close();

        if (count == 0)
        {
            cout << "Id not found. Enter again " << endl
                 << endl;

            goto againID;
        }

        system("pause");
        system("cls");
        int choice;

        cout << "1. Go back to Employee Menu " << endl;
        cout << "2. Press any key to exit " << endl
             << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            EmpMenu();
        }

        else
        {
            cout << endl
                 << "Good Bye!";
            exit(0);
        }
    }

    void Salary_calculate() // emp fun
    {
        int choice;
        int full_day_hours = 8; // full day have 8 hours of worf
        int half_day_hours = 4; // half day have 4 hours of work
        int full_days, half_days, total_days;
        double total_salary, salary_per_hour;
    againSalary:
        cout << "Enter your salary per hour: ";
        cin >> salary_per_hour;

        if (salary_per_hour > 15)
        {
            cout << "Invalid input. Enter less than $15" << endl
                 << endl;

            goto againSalary;
        }
    againDays:
        cout << endl
             << "Enter the number of full days you worked in this month: ";
        cin >> full_days;

        cout << "Enter number of half days you worked in this month: ";
        cin >> half_days;

        total_days = half_days + full_days;

        if (total_days > 26)
        {
            cout << "Invalid. You are entering more than working days in month. Enter again: " << endl
                 << endl;

            goto againDays;
        }

        total_salary = full_days * (full_day_hours * salary_per_hour) + half_days * (half_day_hours * salary_per_hour);

        cout << endl
             << "Your expected monthly salary is $" << total_salary << endl
             << endl;

        system("pause");
        system("cls");

        cout << "1. Go back to Employee Menu " << endl;
        cout << "2. Press any key to exit " << endl
             << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            EmpMenu();
        }

        else
        {
            cout << endl
                 << "Good Bye!";
            exit(0);
        }
    }

    void Calculate_Daily_sale()
    {
        int R_id, price, no_ticket;
        string R_name;
        int total_sales = 0;

        ifstream sale2("sales.txt");

        while (sale2 >> R_id >> R_name >> price >> no_ticket)
        {
            total_sales = total_sales + (price * no_ticket);
        }

        sale2.close();

        cout << "Todays total sale is: " << total_sales << endl
             << endl;

        char choice;

        cout << "Do you want to save today sale ? (Y/N)" << endl
             << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            string date = __DATE__;

            ofstream daily("daily_sales_record", ios::app);

            daily << total_sales << "    " << date << endl;

            daily.close();

            ofstream clear("sales.txt", ios::trunc);

            clear.close();
        }

        system("pause");
        system("cls");

        AdminSalesMenu();
    
    }

    void ChangePass() // emp fun
    {
    againUn:
        string un, old_pas, new_pas, chk_un, chk_pas;
        bool found = false;
        int id;
        int choice;

        cout << "Enter username: ";
        cin >> un;

        cout << "Enter old password: ";
        cin >> old_pas;

        ifstream file6; // for change password

        file6.open("login1.txt");

        ofstream tempFile("temp.txt"); // Temporary file to store updated password

        file6 >> id >> chk_un >> chk_pas;

        while (file6.eof() == 0)

        {

            if (un == chk_un && old_pas == chk_pas)
            {
                found = true;
                cout << endl
                     << "You can change your password now " << endl
                     << endl;

                cout << "Enter new password: ";
                cin >> new_pas;

                tempFile << id << " " << chk_un << " " << new_pas << endl;
            }
            else
            {
                tempFile << id << " " << chk_un << " " << chk_pas << endl;
            }

            file6 >> id >> chk_un >> chk_pas;
        }

        file6.close();
        tempFile.close();

        if (!found)
        {
            cout << "Username or password incorrect. Enter again." << endl
                 << endl;

            goto againUn;
        }

        remove("login1.txt"); // To remove file

        rename("temp.txt", "login1.txt"); // To rename file

        cout << endl
             << "Your password updated successfully" << endl
             << endl;

        system("pause");
        system("cls");

        cout << "1. Go back to Employee Menu " << endl;
        cout << "2. Press any key to exit " << endl
             << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            EmpMenu();
        }

        else
        {
            cout << endl
                 << "Good Bye!";
            exit(0);
        }
    }

    void AddEmp() // Admin fun
    {

        cout << "Hired new employee now add its data " << endl
             << endl;

        string name, user_name, address, password, designation;
        int phone_no, age, id, chk_id;
        double salary;
    XID:
        cout << "Enter unique id of Employee: ";
        cin >> id;

        ifstream checkID;

        checkID.open("Empid.txt");

        while (checkID.eof() == 0)
        {
            checkID >> chk_id;

            if (id == chk_id)
            {
                cout << "User of the same id already exsist. Please enter some other id " << endl
                     << endl;
                goto XID;
            }
        }

        checkID.close();

        cout << "Enter name of Employee: ";
        cin >> name;

        cout << "Enter designation of employee: ";
        cin >> designation;

        cout << "Enter phone no of employee: ";
        cin >> phone_no;

        cout << "Enter address of employee: ";
        cin >> address;

        cout << "Enter age of employee: ";
        cin >> age;

        cout << "Enter salary of employee: ";
        cin >> salary;

        cout << "Enter user name of employee: ";
        cin >> user_name;
    x:
        cout << "Enter strong password(atleaset 8 digits) of employee: ";
        cin >> password;

        if (password.size() < 8)
        {
            cout << "Your password is not strong not acceptable. Enter again " << endl
                 << endl;

            goto x;
        }

        setDetails(id, name, address, phone_no, age, user_name, password, designation, salary); // set the values to file record1

    detailAgain:
        system("pause");
        system("cls");
        int choice;

        cout << endl
             << endl
             << "1. Add another employee. " << endl;
        cout << "2. Admin menu." << endl;
        cout << "3, Exit" << endl
             << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {

            AddEmp();
            break;
        }

        case 2:
        {

            AdminEmpMenu();
            break;
        }

        case 3:
        {
            exit(0);
            break;
        }
        default:
        {
            cout << "Input invalid. Enter choice again" << endl
                 << endl;

            goto detailAgain;
        }
        }
    }

    void EmpRecord() // Admin fun . It is for view all emp records
    {

        int count = 1;
        int id;
        string name;
        string address;
        int contact;
        int age;
        string designation;
        double salary;

        ifstream Efile;

        Efile.open("record1.txt");

        Efile >> id >> name >> contact >> age >> address >> designation >> salary;

        while (Efile.eof() == 0)
        {
            cout << endl
                 << endl
                 << "Record of Employee " << count << endl
                 << endl;

            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;
            cout << "Contact: " << contact << endl;
            cout << "Age: " << age << endl;
            cout << "Designation: " << designation << endl;
            cout << "Salary: " << salary << endl;

            count++;

            Efile >> id >> name >> contact >> age >> address >> designation >> salary;
        }

        Efile.close();
    again10:
        int choice;
        system("pause");
        system("cls");
        cout << endl
             << endl
             << "1. View Agian. " << endl;
        cout << "2. Admin menu." << endl;
        cout << "3, Exit" << endl
             << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {

            EmpRecord();
            break;
        }

        case 2:
        {

            AdminEmpMenu();
            break;
        }

        case 3:
        {
            exit(0);
            break;
        }
        default:
        {
            cout << "Input invalid. Enter choice again" << endl
                 << endl;

            goto again10;
        }
        }
    }

    void Emplog() // Admin fun. It is to view all emp login
    {
        int count = 1;
        string pass;
        string user;
        int id;
        int choice;

        ifstream log;

        log.open("login1.txt");

        log >> id >> user >> pass;

        while (log.eof() == 0)
        {
            cout << endl
                 << endl
                 << "Login of Employee " << count << endl
                 << endl;
            cout << "ID: " << id << endl;
            cout << "User Name: " << user << endl;
            cout << "Password: " << pass << endl;

            count++;
            log >> id >> user >> pass;
        }

        log.close();
        cout << endl
             << endl;

        system("pause");
        system("cls");

        cout << "Do you want to login employees account? " << endl
             << endl;
        cout << "1. Login" << endl;
        cout << "2. Admin Menu" << endl;
        cout << "3. Exit" << endl
             << endl;

    Admagain:

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            EmpLogin();
            break;
        }

        case 2:
        {
            AdminEmpMenu();
            break;
        }

        case 3:
        {
            exit(0);
            break;
        }
        default:
            cout << "Invalid choice. Please choose again." << endl
                 << endl;

            goto Admagain;
            break;
        }
    }

    void UpdateEmp() // Admin fun
    {
        ifstream upfile;
        ofstream tempFile;
        string name, address, designation;
        int phone_no, age, id, id_;
        double salary;

    XID2:
        int count = 0;

        cout << "Enter the id of employee you want to update its data: ";
        cin >> id_;

        upfile.open("record1.txt");

        tempFile.open("temp.txt");

        upfile >> id >> name >> phone_no >> age >> address >> designation >> salary;

        while (upfile.eof() == 0)
        {
            if (id_ == id)
            {
                count = 1;

                char choice;

                cout << "Do you want to update the name of this employee (Y/N): ";
                cin >> choice;

                if (choice == 'y' || choice == 'Y')
                {
                    cout << "Enter new name: ";
                    cin >> name;
                }

                cout << "Do you want to update the phone number of this employee (Y/N): ";
                cin >> choice;

                if (choice == 'y' || choice == 'Y')
                {
                    cout << "Enter new phone no: ";
                    cin >> phone_no;
                }

                cout << "Do you want to update the age of this employee (Y/N): ";
                cin >> choice;

                if (choice == 'y' || choice == 'Y')
                {
                    cout << "Enter new age: ";
                    cin >> age;
                }

                cout << "Do you want to update the address of this employee (Y/N): ";
                cin >> choice;

                if (choice == 'y' || choice == 'Y')
                {
                    cout << "Enter new address: ";
                    cin >> address;
                }

                cout << "Do you want to update the designation of this employee (Y/N): ";
                cin >> choice;

                if (choice == 'y' || choice == 'Y')
                {
                    cout << "Enter new designation: ";
                    cin >> designation;
                }

                cout << "Do you want to update the salary of this employee (Y/N): ";
                cin >> choice;

                if (choice == 'y' || choice == 'Y')
                {
                    cout << "Enter new salary: ";
                    cin >> salary;
                }

                tempFile << id << " " << name << " " << phone_no << " " << age << " " << address << " " << designation << " " << salary << endl;
            }
            else
            {
                tempFile << id << " " << name << " " << phone_no << " " << age << " " << address << " " << designation << " " << salary << endl;
            }

            upfile >> id >> name >> phone_no >> age >> address >> designation >> salary;
        }

        upfile.close();
        tempFile.close();

        remove("record1.txt");
        rename("temp.txt", "record1.txt");

        if (count == 0)
        {
            cout << endl
                 << endl
                 << "Input invalid. Id not found. Enter agian " << endl
                 << endl;

            goto XID2;
        }

        int choice;

        system("pause");
        system("cls");

        cout << "1. Go back to Admin Menu " << endl;
        cout << "2. Press any key to exit " << endl
             << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            AdminEmpMenu();
        }

        else
        {
            cout << endl
                 << "Good Bye!";
            exit(0);
        }
    }

    void DelEmp()
    {
        int id_;
        int id_emp; // to show in record
        string name;
        string address;
        int contact;
        int age;
        string designation;
        double salary;
        bool found = false;

    againEmpID:

        cout << "Enter the id of the employee you want to delete data: ";
        cin >> id_;

        ifstream emp("record1.txt");
        ofstream tempFile("temp.txt");

        if (!emp.is_open() || !tempFile.is_open())
        {
            cout << "Error: Could not open the file." << endl;
            return;
        }

        while (emp >> id_emp >> name >> contact >> age >> address >> designation >> salary)
        {
            if (id_emp == id_)
            {

                found = true;
            }
            else
            {
                tempFile << " " << id_emp << " " << name << " " << contact << " " << age << " " << address << " " << designation << " " << salary << endl;
            }
        }

        emp.close();
        tempFile.close();

        if (found)
        {
            remove("record1.txt");
            rename("temp.txt", "record1.txt");
        }
        else
        {
            cout << "Employee ID not found." << endl;
            remove("temp.txt");

            goto againEmpID;
        }

        DelLogin(id_);
    }

    void DelLogin(int i)
    {

        bool found2 = false;
        int id2;
        string user, pas;
    againEmpID1:
        ifstream login("login1.txt");
        ofstream tempFile1("temp1.txt");

        while (login >> id2 >> user >> pas)
        {
            if (id2 == i)
            {

                found2 = true;
            }
            else
            {
                tempFile1 << " " << id2 << " " << user << " " << pas << endl;
            }
        }

        login.close();
        tempFile1.close();

        if (found2)
        {
            remove("login1.txt");
            rename("temp1.txt", "login1.txt");
            cout << "Employee deleted successfully." << endl;
        }
        else
        {
            cout << "Employee ID not found." << endl;
            remove("temp1.txt");

            goto againEmpID1;
        }

        system("cls");
        system("pause");

        int choice;
        cout << "1. Delete another employee " << endl;
        cout << "2. Go back to Admin Menu " << endl;
        cout << "3. Press any key to exit " << endl
             << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            DelEmp();
        }

        else if (choice == 2)
        {
            AdminEmpMenu();
        }

        else
        {
            cout << endl
                 << "Good Bye!";
            exit(0);
        }
    }

    void AdminSalesMenu()
    {

        cout << "***********************************************" << endl;
        cout << "*                                             *" << endl;
        cout << "*               Welcome Sir                   *" << endl;
        cout << "*                                             *" << endl;
        cout << "***********************************************" << endl;
        cout << "*                                             *" << endl;
        cout << "*  1. All Sales Record                        *" << endl;
        cout << "*  2. Daily sales                             *" << endl;
        cout << "*  3. Monthly sales                           *" << endl;
        cout << "*  4. Exit                                    *" << endl;
        cout << "*                                             *" << endl;
        cout << "***********************************************" << endl
             << endl;
    monthly:
        int choice;

        cout << "Enter choice: ";
        cin >> choice;

        system("pause");
        system("cls");

        if (choice == 1)
        {
            showSales();
        }

        else if (choice == 2)
        {
            Calculate_Daily_sale();
        }

        else if (choice == 3)
        {
            Show_Monthly_sale();
        }

        else if (choice == 4)
        {
            cout << "Good Bye!" << endl;

            exit(0);
        }

        else
        {
            cout << "Input invalid. Enter choice again" << endl
                 << endl;

            goto monthly;
        }
    }

    void Show_Monthly_sale()
    {
        int sale;
        string m, d, y;
        cout << "Sale \t Date" << endl
             << endl;

        ifstream month("daily_sales_record");

        while (month >> sale >> m >> d >> y)
        {
            cout << sale << "\t" << m << " " << d << " " << y << endl;
        }

        month.close();

        system("pause");
        system("cls");

        AdminSalesMenu();
    }

    void showSales()
    {
        int C_id, R_id, price, balance, ticket;
        string name;

        ifstream sales("customer_billing.txt");

        cout << "Ride Id   Name \t  Price  Tickets_Sold" << endl
             << endl;

        while (sales >> C_id >> R_id >> name >> price >> balance >> ticket)
        {
            cout << R_id << setw(15) << name << setw(5) << price << setw(5) << ticket << endl;
        }

        sales.close();

        system("pause");
        system("cls");

        AdminSalesMenu();
    }

    void AdminEmpMenu()
    {
        int choice;
    Eagain:
        cout << "***********************************************" << endl;
        cout << "*                                             *" << endl;
        cout << "*               Welcome Sir                   *" << endl;
        cout << "*                                             *" << endl;
        cout << "***********************************************" << endl;
        cout << "*                                             *" << endl;
        cout << "*  1. Add employee                            *" << endl;
        cout << "*  2. View employee records                   *" << endl;
        cout << "*  3. View employee login                     *" << endl;
        cout << "*  4. Update employee record                  *" << endl;
        cout << "*  5. Delete employee record                  *" << endl;
        cout << "*  6. Exit                                    *" << endl;
        cout << "*                                             *" << endl;
        cout << "***********************************************" << endl
             << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "You chose to add an employee." << endl;

            system("pause");
            system("cls");

            AddEmp();

            break;
        }
        case 2:
        {
            cout << "You chose to view employee records." << endl;

            system("pause");
            system("cls");

            EmpRecord();

            break;
        }

        case 3:
        {
            cout << "You chose to view employee logins." << endl;

            system("pause");
            system("cls");

            Emplog();

            break;
        }

        case 4:
        {
            cout << "You chose to update employee record." << endl;

            system("pause");
            system("cls");

            UpdateEmp();

            break;
        }

        case 5:
        {
            cout << "You chose to delete employee record." << endl;

            system("pause");
            system("cls");

            DelEmp();

            break;
        }

        case 6:
        {
            system("pause");
            system("cls");

            cout << "Good Bye!" << endl;
            exit(0);
        }

        default:
        {
            cout << endl
                 << "Invalid choice. Please choose again." << endl
                 << endl;

            goto Eagain;
        }
        }
    }
};
