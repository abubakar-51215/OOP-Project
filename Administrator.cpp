#include <iostream>
#include <fstream>
#include <iomanip>
#include "Untitled1.h"
#include "Rides.h"
#include "Employee.h"
using namespace std;

class Admin : public Rides, public Customer, public Employee
{
    string user_name = "Admin";
    string password = "admin123";
    string user;
    string pass;

public:
    void color()
    {
        system("color f2");
    }
    void Admin_interface()
    {
        color();
        do
        {
            int choice;
            cout << "Enter user_name : ";
            cin >> user;
            cout << "Enter password : ";
            cin >> pass;
            if (user == user_name && pass == password)
            {
                system("pause");
                system("cls");
                do
                {
                adminIntr:
                    cout << endl;
                    cout << "***********************************************" << endl;
                    cout << "*                                             *" << endl;
                    cout << "*                 Main Menu                   *" << endl;
                    cout << "*                                             *" << endl;
                    cout << "***********************************************" << endl;
                    cout << "*                                             *" << endl;
                    cout << "*  1. Customer                                *" << endl;
                    cout << "*  2. Rides                                   *" << endl;
                    cout << "*  3. Employee                                *" << endl;
                    cout << "*  4. Sales                                   *" << endl;
                    cout << "*  5. Exit                                    *" << endl;
                    cout << "*                                             *" << endl;
                    cout << "***********************************************" << endl;
                    cout << endl;

                    cout << "Enter input : ";
                    cin >> choice;

                    cout << endl;
                    system("cls");

                    if (choice == 1)
                    {
                        int option;
                        do
                        {

                            cout << "*******************************************************" << endl;
                            cout << "*                                                     *" << endl;
                            cout << "*                  Admin Menu                         *" << endl;
                            cout << "*                                                     *" << endl;
                            cout << "*******************************************************" << endl;
                            cout << "*                                                     *" << endl;
                            cout << "*  1. Enter new customer                              *" << endl;
                            cout << "*  2. Update customer information                     *" << endl;
                            cout << "*  3. Delete customer                                 *" << endl;
                            cout << "*  4. Search customer                                 *" << endl;
                            cout << "*  5. See all customers                               *" << endl;
                            cout << "*  6. See customer billing history                    *" << endl;
                            cout << "*  7. See all customer billing history                *" << endl;
                            cout << "*  8. See customer feedback                           *" << endl;
                            cout << "*  9. See customer preferences                        *" << endl;
                            cout << "* 10. Exit                                            *" << endl;
                            cout << "*                                                     *" << endl;
                            cout << "*******************************************************" << endl;
                            cout << endl;

                            cout << "Please enter your choice : ";
                            cin >> option;
                            system("pause");
                            system("cls");
                            switch (option)
                            {
                            case 1:
                                check_file();           // this will check does file exist or not if not then create file
                                input();                // this will take input from employee about customer and save in file also check wehter the customer exist or not
                                Check_write_customer(); // Not necessary but for double check whether the customer exist or not
                                system("pause");
                                system("cls");
                                break;
                            case 2:
                                customer_update(); // this will ask which data of the customer you want to update
                                system("pause");
                                system("cls");
                                break;
                            case 3:
                                customer_delete();
                                system("pause"); // this will delete all customer data
                                system("cls");
                                break;
                            case 4:
                                show_specific_customer(); // will use to find information about specific person
                                system("pause");
                                system("cls");
                                break;
                            case 5:
                                show_all_customer(); // this will show info of all customers
                                system("pause");
                                system("cls");
                                break;
                            case 6:
                                see_tickets_purchase(); // this will show info of about specifc customer who purchased tickets
                                system("pause");
                                system("cls");
                                break;
                            case 7:
                                see_all_tickets_purchase(); // this will show info of all the tickets purchased by our customers
                                system("pause");
                                system("cls");
                                break;
                            case 8:
                                check_ratings(); // this will show the ratings of the customer which they gave about our joyland
                                system("pause");
                                system("cls");
                                break;
                            case 9:
                                show_preferences(); // this will show customer ride preferences
                                system("pause");
                                system("cls");
                                break;
                            case 10:
                                cout << endl
                                     << "returning back " << endl;
                                system("pause");
                                system("cls");
                                break;
                            default:
                                cout << "Invalid option selected." << endl;
                            }
                        } while (option != 10);
                    }

                    else if (choice == 2)
                    {

                        int option;
                        do
                        {
                            cout << "*******************************************************" << endl;
                            cout << "*                                                     *" << endl;
                            cout << "*                   Admin Menu                        *" << endl;
                            cout << "*                                                     *" << endl;
                            cout << "*******************************************************" << endl;
                            cout << "*                                                     *" << endl;
                            cout << "*  Select the option number you want to select        *" << endl;
                            cout << "*                                                     *" << endl;
                            cout << "*  1. Enter new ride                                  *" << endl;
                            cout << "*  2. Update ride information                         *" << endl;
                            cout << "*  3. Delete ride                                     *" << endl;
                            cout << "*  4. Search ride                                     *" << endl;
                            cout << "*  5. See all rides                                   *" << endl;
                            cout << "*  6. See sales of all rides                          *" << endl;
                            cout << "*  7. See sales of specific ride                      *" << endl;
                            cout << "*  8. Exit                                            *" << endl;
                            cout << "*                                                     *" << endl;
                            cout << "*******************************************************" << endl;
                            cout << endl;

                            cout << "Enter your choice : ";
                            cin >> option;
                            system("pause");
                            system("cls");
                            switch (option)
                            {
                            case 1:
                                check_files();           // this will check does file exist or not if not then create file
                                ride_inputs();           // this will add a new ride and check wether same id exist or not
                                check_data_write_data(); // double check
                                system("pause");
                                system("cls");
                                break;
                            case 2:
                                ride_update(); // this will update ride
                                system("pause");
                                system("cls");
                                break;
                            case 3:
                                ride_delete(); // this will delete ride
                                system("pause");
                                system("cls");
                                break;
                            case 4:
                                search_specific_rides(); // this will search specific ride
                                system("pause");
                                system("cls");
                                break;
                            case 5:
                                info_show_all_rides(); // will show all rides
                                system("pause");
                                system("cls");
                                break;

                            case 6:
                                see_sales_of_all_rides(); // will show all rides
                                system("pause");
                                system("cls");

                                break;

                            case 7:
                                see_sales_of_specific_rides(); // will show all rides
                                system("pause");
                                system("cls");
                                break;

                            case 8:
                                cout << endl
                                     << "Returning back " << endl;
                                system("pause");
                                system("cls");

                                goto adminIntr;
                                break;
                            default:
                                cout << "Invalid option selected." << endl;
                            }
                        } while (option != 8);
                    }

                    else if (choice == 3)
                    {
                        AdminEmpMenu();
                    }

                    else if (choice == 4)
                    {

                        AdminSalesMenu();
                    }

                    else if (choice == 5)
                    {
                        exit(0);
                    }
                    else
                    {
                        cout << endl
                             << "you enter wrong input type again " << endl;
                    }
                } while (choice != 5);
            }
            else
            {
                cout << endl
                     << "You enter wrong user_name or password type again " << endl
                     << endl;
            }
        } while (user != user_name && pass != password);
    }
};
int main()
{
    Admin obj;
    obj.Admin_interface();
}
