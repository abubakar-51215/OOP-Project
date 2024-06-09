#include <iostream>
#include <iomanip>
#include <fstream>
#include "Untitled1.h"
#include "Rides.h"

using namespace std;

class Customer_interface : public Customer, public Rides
{
protected:
    string pass;
    int ids;
    bool check_login;
    int balance_hold;
    int rides_id;
    int choice;
    int remaining_balance;
    int total_ticket_purchased;
    

public:
    int total_spent;

    void tickets()
    {
        cout << "Your tickets are " << endl
             << endl;
        fstream billing_history("customer_billing.txt", ios::in);
        cout << "Ride_Tickets " << setw(18) << "ride price " << setw(18) << "Total tickets " << endl
             << endl;
        while (billing_history >> file_customer_id >> rides_id >> name >> ride_price >> remaining_balance >> total_ticket_purchased)
        {
            if (ids == file_customer_id)
            {
                cout << left << setw(20) << name << left << setw(20) << ride_price<< left << setw(20) << total_ticket_purchased << endl;
            }
        }
        billing_history.close();
        system("Pause");
        system("cls");
    }

    void display_interface()
    {
        do
        {
            check_login = false;
            fstream Customer_file("customer.txt", ios::in);

            cout << "Hello Sir please enter your id and pass to login " << endl;
            cout << "Enter id: ";
            cin >> ids;
            cout << "Enter Password: ";
            cin >> pass;

            system("pause");
            system("cls");

            if (Customer_file.is_open())
            {
                while (Customer_file >> file_customer_id >> file_name >> file_phone_no >> file_preferences >> pas >> balnce)
                {
                    if (ids == file_customer_id && pass == pas)
                    {
                        balance_hold = balnce;
                        check_login = true;
                        break;
                    }
                }
                Customer_file.close();

                if (check_login)
                {
                    do
                    {
                        cout << "*******************************************************" << endl;
                        cout << "*                                                     *" << endl;
                        cout << "*                 Customer Menu                       *" << endl;
                        cout << "*                                                     *" << endl;
                        cout << "*******************************************************" << endl;
                        cout << "*                                                     *" << endl;
                        cout << "*  Type number from which you want to see information *" << endl;
                        cout << "*                                                     *" << endl;
                        cout << "*  1. View Information                                *" << endl;
                        cout << "*  2. View Tickets                                    *" << endl;
                        cout << "*  3. View Total Spent                                *" << endl;
                        cout << "*  4. Exit                                            *" << endl;
                        cout << "*                                                     *" << endl;
                        cout << "*******************************************************" << endl;
                        cout << endl;

                        cout << "Enter choice: ";
                        cin >> choice;
                        
                        system("pause");
                        system("cls");

                        if (choice == 1)
                        {
                            information();
                            cout << "Remaining Balance: " << balance_hold << endl;
                            system("Pause");
                            system("cls");
                        }
                        else if (choice == 2)
                        {
                            tickets();
                        }
                        else if (choice == 3)
                        {
                        	int ride_ides;
                            fstream billing_history("customer_billing.txt", ios::in);
                            while (billing_history >> file_customer_id >>ride_ides>> name >> ride_price >> balance_hold >> total_ticket_purchased)
                            {
                                if (ids == file_customer_id)
                                {
                                    total_spent = ride_price * total_ticket_purchased;
                                }
                            }
                            billing_history.close();
                            cout << "Total money you spent: " << total_spent << endl;
                            system("pause");
                            system("cls");
                        }

                        
                        else if (choice == 4)
                        {
                            cout << "Thanks for coming, sir. We hope you enjoyed your day here." << endl;
                            cout << "Please now return the band and receive your remaining balance from the counter: " << balance_hold << endl;
                            do
                            {
                                cout << endl
                                     << "Please enter feedback between 1-5: ";
                                cin >> file_feedback;
                                if (file_feedback >= 0 && file_feedback <= 5)
                                {
                                    fstream feedback("feed_back.txt", ios::out | ios::app);
                                    if (feedback.is_open())
                                    {
                                        feedback << file_customer_id << " " << file_feedback << endl;
                                    }
                                    feedback.close();
                                }
                                else
                                {
                                    cout << endl
                                         << endl
                                         << "The feedback must be between 1-5." << endl;
                                }
                            } while (file_feedback < 0 || file_feedback > 5);
                            exit(0);
                        }
                    } while (choice != 4);
                }
                else
                {
                    cout << "Login failed. Wrong ID or password." << endl;
                }
            }
            else
            {
                cout << "Unable to open file." << endl;
            }
        } while (!check_login);
    }
};

int main()
{
    Customer_interface obj7;
    obj7.display_interface();
    return 0;
}
