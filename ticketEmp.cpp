#include <iostream>
#include <ctime>
#include "Rides.h"
#include "Untitled1.h"

using namespace std;

class Ticket : public Rides, public Customer
{

public:
    void Ticket_employee()
    {
        int ids, rides_id, balance_hold;
        int option;

        do
        {
            cout << "************************************************" << endl;
            cout << "*                                              *" << endl;
            cout << "*                 Employee Menu                *" << endl;
            cout << "*                                              *" << endl;
            cout << "************************************************" << endl;
            cout << "*                                              *" << endl;
            cout << "*  1. See rate list                            *" << endl;
            cout << "*  2. Enter new customer                       *" << endl;
            cout << "*  3. Search customer                          *" << endl;
            cout << "*  4. See Biling history                       *" << endl;
            cout << "*  5. Recharge Band                            *" << endl;
            cout << "*  6. Give Ticket                              *" << endl;
            cout << "*  7. Exit                                     *" << endl;
            cout << "*                                              *" << endl;
            cout << "************************************************" << endl;

            cout << endl;

            cout << "Enter your choice: ";
            cin >> option;

            system("pause");
            system("cls");

            if (option == 1)
            {
                show_specific_rides();
                system("Pause");
                system("cls");
            }

            else if (option == 2)
            {
                check_file();           // this will check does file exist or not if not then create file
                input();                // this will take input from employee about customer and save in file also check wehter the customer exist or not
                Check_write_customer(); // Not necessary but for double check whether the customer exist or not
                system("pause");
                system("cls");
            }

            else if (option == 3)
            {
                show_specific_customer(); // will use to find information about specific person
                system("pause");
                system("cls");
            }

            else if (option == 4)
            {
                see_tickets_purchase(); // this will show info of about specifc customer who purchased tickets
                system("pause");
                system("cls");
            }

            else if (option == 5)
            {
                RechargeBand();
                system("pause");
                system("cls");
            }

            else if (option == 6)
            {
                cout << endl
                     << "Enter the id of the customer: ";
                cin >> ids;

                ofstream temp("temp.txt");

                fstream customer("Customer.txt", ios::in);
                if (customer.is_open())
                {
                    cout << "Rides are : " << endl;
                    show_specific_rides();
                    bool customerFound = false;
                    while (customer >> file_customer_id >> file_name >> file_phone_no >> file_preferences >> pas >> balnce)
                    {
                        if (file_customer_id == ids)
                        {
                            customerFound = true;
                            int tickets_assign;

                            cout << endl
                                 << "Enter the id of the ride you want to give a ticket to the customer:";
                            cin >> rides_id;

                            cout << endl
                                 << "Enter the number of tickets you want to give to the customer:";
                            cin >> tickets_assign;

                            fstream rides("Rides.txt", ios::in);
                            bool rideFound = false;
                            if (rides.is_open())
                            {
                                while (rides >> id >> name >> capacity >> area >> energy_consume >> ride_price >> ride_time >> status)
                                {
                                    if (rides_id == id)
                                    {
                                        rideFound = true;

                                        balance_hold = balnce;

                                        if (balance_hold >= ride_price * tickets_assign)
                                        {
                                            balance_hold -= ride_price * tickets_assign;

                                            system("cls");

                                            cout << "========================================" << endl;
                                            cout << "               TICKET                   " << endl;
                                            cout << "========================================" << endl;
                                            cout << left << setw(20) << "Swing Name" << "\t: " << name << endl;
                                            cout << left << setw(20) << "Tickets.No" << "\t: " << tickets_assign << endl;
                                            cout << left << setw(20) << "Price per Ticket" << "\t: $" << fixed << setprecision(2) << ride_price << endl;
                                            cout << "----------------------------------------" << endl;
                                            cout << left << setw(20) << "Total Amount" << "\t: $" << ride_price * tickets_assign << endl;
                                            cout << left << setw(20) << "Remaining Balance" << "\t: $" << fixed << setprecision(2) << balance_hold << endl;
                                            cout << "              \t\t       Time: " << __TIME__ << endl;
                                            cout << "========================================" << endl
                                                 << endl;

                                            fstream billing_history("customer_billing.txt", ios::out | ios::app);
                                            billing_history << file_customer_id << setw(15) << id << setw(15) << name << setw(15) << ride_price << setw(20) << balance_hold << setw(15) << tickets_assign << endl;
                                            billing_history.close();

                                            ofstream sale("sales.txt", ios::app);
                                            sale << id << " " << name << " " << ride_price << " " << tickets_assign << endl;
                                            sale.close();
                                        
                                            temp << file_customer_id << " " << file_name << " " << file_phone_no << " " << file_preferences << " " << pas << " " << balance_hold << endl;
                                        }
                                        else
                                        {
                                            cout << endl
                                                 << "Customer balance is not enough for the ride. Go to the counter to recharge money." << endl;
                                        }
                                        system("Pause");
                                        system("cls");
                                        break;
                                    }
                                }
                                rides.close();
                                if (!rideFound)
                                {
                                    cout << endl
                                         << "Ride ID does not exist." << endl;
                                    system("Pause");
                                    system("cls");
                                }
                            }
                        }

                        else
                        {
                            temp << file_customer_id << " " << file_name << " " << file_phone_no << " " << file_preferences << " " << pas << " " << balnce << endl;
                        }
                    }
                    if (!customerFound)
                    {
                        remove("temp.txt");
                        cout << endl
                             << "Customer ID does not exist." << endl;
                        system("Pause");
                        system("cls");
                    }

                    customer.close();
                    temp.close();

                    remove("Customer.txt");
                    
                    rename("temp.txt", "Customer.txt");
                }
                else
                {
                    cout << endl
                         << "File failed to open." << endl;
                }
            }
            else if (option == 7)
            {
                 system("Pause");
                 system("cls");
                 
                cout << "Good Bye!";
                exit(0);
            }
        } while (option != 7);
    }
};

int main()
{
    Ticket obj;
    obj.Ticket_employee();
}
