#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Customer
{
protected:
    int customer_id;
    string names;
    int customer_phone_no;

    int feed_back;
    string prefereces;
    string password;
    int search;
    int balance;

    bool customerExists;
    int file_customer_id;
    string file_name;
    int file_phone_no;

    int file_feedback;
    string file_preferences;
    string pas;
    int balnce;

public:
    void input()
    {
    	
        
        
        cout << "Enter the name of the Customer :";
        cin >> names;
        cout << "Enter the id of the Customer :";
        cin >> customer_id;
        cout << "Enter the phone_no of the Customer :";
        cin >> customer_phone_no;
        cout << "Enter the Preferences of the Customer :";
        cin >> prefereces;
        cout << "Give password to the Customer :";
        cin >> password;
        cout << "Enter the band balance of the Customer :";
        cin >> balance;

        ofstream prefer("prefer.txt", ios::app);

        prefer << customer_id <<" "<< prefereces<<endl;

        prefer.close();
    }

    void check_file()
    {
        fstream customer("Customer.txt", ios::in);
        if (customer.fail())
        {
            fstream customer("Customer.txt", ios::out);
            customer.close();
        }
    }

    void Check_write_customer()
    {
        color();
        fstream customer("Customer.txt", ios::in);

        if (customer.is_open())
        {
            while (customer >> file_customer_id >> file_name >> file_phone_no >> file_preferences >> pas >> balnce)
            {
                if (file_customer_id == customer_id)
                {
                    customerExists = true;
                }
            }
            customer.close();
        }

        if (!customerExists)
        {
            fstream customer("Customer.txt", ios::out | ios::app);
            if (customer.is_open())
            {
                customer << customer_id << setw(20) << names << setw(20) << customer_phone_no << setw(20) << prefereces << setw(20) << password << setw(20) << balance << endl;
                customer.close();
            }
            else
            {
                cout << "Error: Could not open the file for writing." << endl;
            }
        }
        else
        {
            cout << "Customer with id " << customer_id << " already exists." << endl;
        }
    }

    void information()
    {
        color();
        cout << "Name :" << file_name << endl;
        cout << "id :" << file_customer_id << endl;
        cout << "Phone :" << file_phone_no << endl;
        cout << "preference:" << file_preferences << endl;
        cout << "Balance recharge :" << balnce << endl;
    }

    void customer_update()
    {
        color();
        int option;
        int id_;
        cout << "Enter the id of the customer you want to update its data: ";
        cin >> id_;
        bool found = false;
        ifstream customer("Customer.txt");
        ofstream tempFile("temp.txt");

        if (!customer.is_open() || !tempFile.is_open())
        {
            cout << "Error: Could not open the file." << endl;
            return;
        }
        while (customer >> file_customer_id >> file_name >> file_phone_no >> file_preferences >> pas >> balnce)
        {
            if (file_customer_id == id_)
            {
                found = true;
                cout << "Updating details for customer ID: " << id_ << endl;
                system("pause");
                system("cls");
                do
                {
                    cout << "Enter the number of the detail you want to update:\n";
                    cout << "1. Update name " << endl;
                    cout << "2. Update phone number " << endl;
                    cout << "3. Update preferences" << endl;
                    cout << "4. Update password" << endl;
                    cout << "5. Update balance " << endl;
                    cout << "6. FOR EXITING " << endl;
                    cin >> option;

                    switch (option)
                    {
                    case 1:
                        cout << "Enter new name: ";
                        cin >> names;
                        file_name = names;
                        break;
                    case 2:
                        cout << "Enter new phone number: ";
                        cin >> customer_phone_no;
                        file_phone_no = customer_phone_no;
                        break;
                    case 3:
                        cout << "Enter new preferences: ";
                        cin >> prefereces;
                        file_preferences = prefereces;
                        break;
                    case 4:
                        cout << "Enter new password: ";
                        cin >> password;
                        pas = password;
                        break;
                    case 5:
                        cout << "Enter new balance: ";
                        cin >> balance;
                        balnce = balance;
                        break;
                    case 6:
                        cout << "You are exiting : ";
                        break;
                    default:
                        cout << "Invalid option selected." << endl;
                    }
                } while (option != 6);
                tempFile << file_customer_id << setw(20) << file_name << setw(20) << file_phone_no << setw(20) << file_preferences << setw(20) << pas << setw(20) << balnce << endl;
            }
            else
            {
                tempFile << file_customer_id << setw(20) << file_name << setw(20) << file_phone_no << setw(20) << file_preferences << setw(20) << pas << setw(20) << balnce << endl;
            }
        }

        customer.close();
        tempFile.close();

        if (found)
        {
            remove("Customer.txt");
            rename("temp.txt", "Customer.txt");
            cout << "Customer details updated successfully." << endl;
        }
        else
        {
            cout << "Customer ID not found." << endl;
            remove("temp.txt");
        }
    }

    void RechargeBand()
    {
        cout << "Welcome sir." << endl
             << endl;

        int Cid, Cid_, Cbalance, contact;
        string name, pas, preference;
        int count = 0;

    bandAg:
        cout << "Enter customer id: ";
        cin >> Cid;

        ifstream recharge("Customer.txt");
        ofstream temp("temp.txt");

        while (recharge >> Cid_ >> name >> contact >> preference >> pas >> Cbalance)
        {
            if (Cid == Cid_)
            {
                count = 1;
                int balen;
                while (true)
                {
                    cout << "Enter the amount you want to add to your band: ";
                    cin >> balen;

                    if (balen > 100)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Low amount. Please enter more than 100 rupees." << endl
                             << endl;
                    }
                }
                int total_bal = balen + Cbalance;
                temp << Cid_ << " " << name << " " << contact << " " << preference << " " << pas << " " << total_bal << endl;
            }
            else
            {
                temp << Cid_ << " " << name << " " << contact << " " << preference << " " << pas << " " << Cbalance << endl;
            }
        }

        recharge.close();
        temp.close();

        if (count == 0)
        {
            cout << "Band ID is incorrect. Please enter the correct band ID." << endl
                 << endl;
            goto bandAg;
        }

        remove("Customer.txt");
        rename("temp.txt", "Customer.txt");
        cout << "Your balance is updates successfully. Now you can take rides." << endl
             << endl;
    }

    void customer_delete()
    {
        int id_;
        cout << "Enter the id of the customer you want to delete its data: ";
        cin >> id_;

        ifstream customer("Customer.txt");
        ofstream tempFile("temp.txt");

        if (!customer.is_open() || !tempFile.is_open())
        {
            cout << "Error: Could not open the file." << endl;
            return;
        }

        bool found = false;
        while (customer >> file_customer_id >> file_name >> file_phone_no >> file_preferences >> pas >> balnce)
        {
            if (file_customer_id == id_)
            {
                found = true;
            }
            else
            {
                tempFile << file_customer_id << setw(20) << file_name << setw(20) << file_phone_no << setw(20) << file_preferences << setw(20) << pas << setw(20) << balnce << endl;
            }
        }

        customer.close();
        tempFile.close();

        if (found)
        {
            remove("Customer.txt");
            rename("temp.txt", "Customer.txt");
            cout << "Customer details deleted successfully." << endl;
        }
        else
        {
            cout << "Customer ID not found." << endl;
            remove("temp.txt");
        }
    }

    void see_all_customers()
    {
        color();
        fstream customer("Customer.txt", ios::in);
        while (customer >> file_customer_id >> file_name >> file_phone_no >> file_preferences >> pas >> balnce)
        {
            cout << "id is : " << file_customer_id << endl;
            cout << "name is : " << file_name << endl;
            cout << "Phone_no is : " << file_phone_no << endl;
            cout << "preferences : " << file_preferences << endl;
            cout << "password : " << pas << endl;
            cout << "balance : " << balnce << endl;
            cout << endl
                 << endl;
        }
    }

    void color()
    {
        system("color f2");
    }

    void check_ratings()
    {
        fstream feedback("feed_back.txt", ios::in);
        cout << "id" << "     " << "Ratings" << endl;
        if (feedback.is_open())
        {
            while (feedback >> file_customer_id >> file_feedback)
            {
                cout << file_customer_id << "    " << file_feedback << endl;
            }
        }
        else
        {
            cout << "file failed to open ";
        }
    }

    void show_preferences()
    {
        color();
        fstream customer("prefer.txt", ios::in);
        cout << endl
             << setw(10) << left << "id" << setw(15) << left << "preferences" << endl
             << endl;
        if (customer.is_open())
        {
            while (customer >> file_customer_id >> file_preferences)
            {
                cout << setw(10) << left << file_customer_id << setw(15) << left << file_preferences << endl
                     << endl;
            }
            customer.close();
        }
        else
        {
            cout << endl
                 << " file failed to open " << endl;
        }
    }

    void show_specific_customer()
    {
        int customer_id;
        cout << "Enter the ID of the customer you want to view: ";
        cin >> customer_id;

        fstream customer("Customer.txt", ios::in);
        if (customer.is_open())
        {
            bool found = false;
            while (customer >> file_customer_id >> file_name >> file_phone_no >> file_preferences >> pas >> balnce)
            {
                if (file_customer_id == customer_id)
                {
                    found = true;
                    cout << "Customer ID: " << file_customer_id << endl;
                    cout << "Name: " << file_name << endl;
                    cout << "Phone Number: " << file_phone_no << endl;
                    cout << "Preferences: " << file_preferences << endl;
                    cout << "Balance: " << balnce << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "Customer with ID " << customer_id << " not found." << endl;
            }
            customer.close();
        }
        else
        {
            cout << "File failed to open." << endl;
        }
    }

    void show_all_customer()
    {
        fstream customer("Customer.txt", ios::in);
        if (customer.is_open())
        {
            while (customer >> file_customer_id >> file_name >> file_phone_no >> file_preferences >> pas >> balnce)
            {
                cout << "Customer ID: " << file_customer_id << endl;
                cout << "Name: " << file_name << endl;
                cout << "Phone Number: " << file_phone_no << endl;
                cout << "Preferences: " << file_preferences << endl;
                cout << "Balance: " << balnce << endl;
                cout << endl
                     << endl;
            }
            customer.close();
        }
        else
        {
            cout << "File failed to open." << endl;
        }
    }
};
