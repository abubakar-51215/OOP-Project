#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Rides
{
protected:
    string ride_name;
    int ride_id;
    int ride_capacity;
    string total_area;
    double energy_consume_per_ride;
    double per_ride_price;
    string per_ride_time;
    bool working_status;
    bool ride_exist;
    // for file
    string name;
    int id;
    int capacity;
    string area;
    double energy_consume;
    int ride_price;
    string ride_time;
    string status;

    int user_id;
    string ticket;
    int get_balance;

public:
    Rides()
    {
        ride_exist = false;
    }

    void ride_inputs()
    { // for employee to put data and also for administrator
        do
        {
            ride_exist = false;
            cout << "Enter id of ride:";
            cin >> ride_id;
            fstream rides("Rides.txt", ios::in);

            if (rides.is_open())
            {
                while (rides >> id >> name >> capacity >> area >> energy_consume >> ride_price >> ride_time >> status)
                {
                    if (id == ride_id)
                    {
                        ride_exist = true;
                        cout << "The ride with id " << id << " already exists. Please enter ID agian \n"
                             << endl;
                        break;
                    }
                }
                rides.close();
            }
            else
            {
                cout << "File failed to open.\n";
            }

            if (!ride_exist)
            {
                cout << "Enter name of ride:";
                cin >> ride_name;
                cout << "Enter Ride capacity:";
                cin >> ride_capacity;
                cout << "Enter total Area of ride:";
                cin >> total_area;
                cout << "Enter energy consumed per ride:";
                cin >> energy_consume_per_ride;
                cout << "Enter ticket price of ride:";
                cin >> per_ride_price;
                cout << "Enter per ride time:";
                cin >> per_ride_time;
                cout << "Enter the working status of ride (Working or NotWorking):";
                cin >> status;
            }
        } while (ride_exist);
    }

    void check_files()
    { // to check whether the file is open or not
        fstream rides("Rides.txt", ios::in);
        if (rides.fail())
        {
            fstream rides("Rides.txt", ios::out | ios::app);
        }
    }

    void check_data_write_data()
    { // this will check that we are not putting data with the same id if id is not same then it put data
        fstream rides("Rides.txt", ios::in);

        if (rides.is_open())
        {
            string read;
            while (rides >> id >> name >> capacity >> area >> energy_consume >> ride_price >> ride_time >> status)
            {
                if (id == ride_id)
                {
                    ride_exist = true;
                    break;
                }
            }
            rides.close();
        }
        else
        {
            cout << "File failed to open.\n";
        }

        if (!ride_exist)
        {
            fstream rides("Rides.txt", ios::out | ios::app);
            rides << setw(8) << ride_id << setw(20) << ride_name << setw(20) << ride_capacity << setw(20) << total_area << setw(25) << energy_consume_per_ride << setw(20)
                  << per_ride_price << setw(20) << per_ride_time << setw(20) << (working_status ? "Working" : "Not working") << endl;
            rides.close();
        }
        else
        {
            cout << "A ride with id " << ride_id << " already exists.\n";
        }
    }

    void show_specific_rides()
    {
        fstream rides("Rides.txt", ios::in);

        if (rides.is_open())
        {
            cout << setw(5) << "ID" << setw(15) << "Name" << setw(10) << "Price" << endl
                 << endl;
            while (rides >> id >> name >> capacity >> area >> energy_consume >> ride_price >> ride_time >> status)
            {
                cout << setw(5) << id << setw(15) << name << setw(10) << ride_price << endl;
            }
            rides.close();
        }
        else
        {
            cout << "File failed to open.\n";
        }
    }

    void search_specific_rides()
    {
        fstream rides("Rides.txt", ios::in);
        int searchid;
        cout << "Enter the id you want to search :";
        cin >> searchid;
        if (rides.is_open())
        {
            while (rides >> id >> name >> capacity >> area >> energy_consume >> ride_price >> ride_time >> status)
            {
                if (id == searchid)
                {
                    cout << "Name: " << name << endl
                         << "ID: " << id << endl
                         << "Capacity: " << capacity << endl
                         << "Area: " << area << endl
                         << "Energy Consumption: " << energy_consume << endl
                         << "Ride Price: " << ride_price << endl
                         << "Ride Time: " << ride_time << endl
                         << "Status: " << status << endl
                         << endl;

                    break;
                }
            }
            rides.close();
        }
        else
        {
            cout << "File failed to open.\n";
        }
    }

    void info_show_all_rides()
    { // this will show all rides we have in our play land and it will only see by administrator
        fstream rides("Rides.txt", ios::in);

        if (rides.is_open())
        {
            cout << left << setw(10) << "Ride_id" << setw(20) << "Ride_Name" << setw(15) << "Capacity" << setw(15) << "Area" << setw(20) << "Energy_consume" << setw(15) << "Ride_price" << setw(20) << "Ride_time" << setw(10) << "Status" << endl;

            while (rides >> id >> name >> capacity >> area >> energy_consume >> ride_price >> ride_time >> status)
            {
                cout << left << setw(10) << id << setw(20) << name << setw(15) << capacity << setw(15) << area << setw(20) << energy_consume << setw(15) << ride_price << setw(20) << ride_time << setw(10) << status << endl;
            }
            rides.close();
        }
        else
        {
            cout << "File failed to open.\n";
        }
    }

    void ride_update()
    {
        int option;
        int id_;
        cout << "Enter the id of the ride you want to update:";
        cin >> id_;

        ifstream rides("Rides.txt");
        ofstream tempFile("temp2.txt");

        if (!rides.is_open() || !tempFile.is_open())
        {
            cout << "Error: Could not open the file." << endl;
            return;
        }
        bool found = false;
        while (rides >> id >> name >> capacity >> area >> energy_consume >> ride_price >> ride_time >> status)
        {
            if (id == id_)
            {
                found = true;
                cout << "Updating details for ride ID: " << id_ << endl;
                system("pause");
                system("cls");
                do
                {
                    cout << "Enter the number of which ride detail you want to update" << endl;
                    cout << "1. Update id" << endl;
                    cout << "2. Update name" << endl;
                    cout << "3. Update capacity" << endl;
                    cout << "4. Update area" << endl;
                    cout << "5. Update energy consumption" << endl;
                    cout << "6. Update ride price" << endl;
                    cout << "7. Update ride time" << endl;
                    cout << "8. Update working status" << endl;
                    cout << "9. Update all result " << endl
                         << endl;

                    cout << "Enter your choice: ";

                    cin >> option;

                    switch (option)
                    {
                    case 1:
                        cout << "Enter new id:";
                        cin >> id;
                        break;
                    case 2:
                        cout << "Enter new name:";
                        cin >> ride_name;
                        name = ride_name;
                        break;
                    case 3:
                        cout << "Enter new capacity:";
                        cin >> ride_capacity;
                        capacity = ride_capacity;
                        break;
                    case 4:
                        cout << "Enter new area:";
                        cin >> total_area;
                        area = total_area;
                        break;
                    case 5:
                        cout << "Enter new energy consumption:";
                        cin >> energy_consume_per_ride;
                        energy_consume = energy_consume_per_ride;
                        break;
                    case 6:
                        cout << "Enter new ride price:";
                        cin >> per_ride_price;
                        ride_price = per_ride_price;
                        break;
                    case 7:
                        cout << "Enter new ride time:";
                        cin >> per_ride_time;
                        ride_time = per_ride_time;
                        break;
                    case 8:
                        cout << "Enter new working status (true/false):";
                        cin >> working_status;
                        status = working_status ? "Working" : "Not working";
                        break;
                    case 9:
                        cout << "You are exiting" << endl;
                        break;

                    default:
                        cout << "Invalid option selected." << endl;
                    }
                } while (option != 9);

                tempFile << setw(8) << id << setw(20) << name << setw(20) << capacity << setw(20) << area << setw(25) << energy_consume << setw(20)
                         << ride_price << setw(20) << ride_time << setw(20) << status << endl;
            }
            else
            {
                tempFile << setw(8) << id << setw(20) << name << setw(20) << capacity << setw(20) << area << setw(25) << energy_consume << setw(20)
                         << ride_price << setw(20) << ride_time << setw(20) << status << endl;
            }
        }

        rides.close();
        tempFile.close();

        if (found)
        {
            remove("Rides.txt");
            rename("temp2.txt", "Rides.txt");
            cout << "Ride details updated successfully." << endl;
        }
        else
        {
            cout << "Ride ID not found." << endl;
            remove("temp2.txt");
        }
    }

    void ride_delete()
    {
        int id_;
        cout << "Enter the id of the ride you want to delete:";
        cin >> id_;

        ifstream ride_file("Rides.txt");
        ofstream tempFile("temp.txt");

        if (!ride_file.is_open() || !tempFile.is_open())
        {
            cout << "Error: Could not open the file." << endl;
            return;
        }

        bool found = false;
        while (ride_file >> id >> name >> capacity >> area >> energy_consume >> ride_price >> ride_time >> status)
        {
            if (id == id_)
            {
                found = true;
            }
            else
            {
                tempFile << id << setw(20) << name << setw(20) << capacity << setw(20) << area << setw(25)
                         << energy_consume << setw(20) << ride_price << setw(20) << ride_time << setw(20) << status << endl;
            }
        }

        ride_file.close();
        tempFile.close();

        if (found)
        {
            remove("Rides.txt");
            rename("temp.txt", "Rides.txt");
            cout << "Ride details deleted successfully." << endl;
        }
        else
        {
            cout << "Ride ID not found." << endl;
            remove("temp.txt");
        }
    }

    void see_tickets_purchase()
    {
    tickAgian:

        int i_d;
        int count = 0;
        cout << "Enter the id of the customer you want to see about the tickets he purchased: ";
        cin >> i_d;

        system("clear");

        fstream billing_history("customer_billing.txt", ios::in);

        cout << "Ride_Tickets " << setw(18) << "Spent on " << endl
             << endl;

        while (billing_history >> user_id >> id >> name >> ride_price >> get_balance >> ticket)
        {
            if (user_id == i_d)
            {
                count = 1;
                cout << name << setw(15) << ride_price << endl;
            }
        }

        billing_history.close();

        if (count == 0)
        {
            cout << "Customer not found. Enter ID again" << endl
                 << endl;

            goto tickAgian;
        }

        system("Pause");
        system("cls");
    }

    void see_all_tickets_purchase()
    {
        fstream billing_history("customer_billing.txt", ios::in);
        if (billing_history.is_open())
        {
            cout << "Ride_Tickets " << setw(18) << "Spent on " << setw(18) << " ticket sells " << endl
                 << endl;
            while (billing_history >> user_id >> id >> name >> ride_price >> get_balance >> ticket)
            {
                cout << name << setw(15) << ride_price << setw(15) << ticket << endl;
            }
        }
        else
        {
            cout << "file failed to open ";
        }
        system("Pause");
        system("cls");
    }

    void see_sales_of_all_rides()
    {
        int user_id;
        int t_t;
        int total_sales = 0;
        fstream billing("customer_billing.txt", ios::in);

        if (billing.is_open())
        {
            cout << left << setw(10) << "Ride_id" << setw(20) << "Ride name" << setw(15) << "Ride_price" << setw(30) << "Ticket_sold" << setw(20) << "Ride_total_sales" << endl;
            while (billing >> user_id >> id >> name >> ride_price >> get_balance >> t_t)
            {
                cout << left << setw(10) << id << setw(20) << name << setw(15) << ride_price << setw(30) << t_t << setw(20) << ride_price * t_t << endl;
                total_sales += ride_price * t_t;
            }
            cout << "Total sales of all rides is : " << total_sales << endl;
            billing.close();

            
        }
        else
        {
            cout << "Billing file failed to open." << endl;
        }
    }

    void see_sales_of_specific_rides()
    {
        int user_id;
        int t_t;
        int total_sales = 0;
        int search_id;
        int total_ticket_Sell = 0;
        fstream billing("customer_billing.txt", ios::in);

        if (billing.is_open())
        {
            cout << "Enter the id of the ride you want to see sales:";
            cin >> search_id;

            while (billing >> user_id >> id >> name >> ride_price >> get_balance >> t_t)
            {
                if (search_id == id)
                {
                    total_ticket_Sell += t_t;
                    total_sales += ride_price * t_t;
                }
            }

            if (total_ticket_Sell > 0)
            {
                cout << left << setw(10) << "Ride_id" << setw(20) << "Ride name" << setw(15) << "Ride_price" << setw(30) << "Ticket_Sold" << setw(20) << "Ride_total_sales" << endl;
                cout << left << setw(10) << search_id << setw(20) << name << setw(15) << ride_price << setw(30) << total_ticket_Sell << setw(20) << total_sales << endl;
            }
            else
            {
                cout << "No sales found for ride with id: " << search_id << endl;
            }

            cout << "Total sales of all rides is: " << total_sales << endl;
            billing.close();
        }
        else
        {
            cout << "Billing file failed to open." << endl;
        }
    }
};
