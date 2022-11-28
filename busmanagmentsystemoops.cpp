#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
static int p = 0;

class a
{
    char busn[5], driver[10], arrival[5], departure[5], from[10], to[10], seat[8][4][10];

public:
    void install();
    void allotment();
    void empty();
    void show();
    void tkt();
    void avail();
    void position(int i);

} bus[10];
void vline(char ch)
{
    for (int i = 80; i > 0; i--)
    {
        cout << ch;
    }
}

void a::install()
{
    vline('-');
    cout << endl;
    cout << "                       Bus information installation Window" << endl;
    vline('-');
    cout << endl;
    cout << "Enter the bus no: ";
    cin >> bus[p].busn;
    cout << "\nEnter the Driver's name: ";
    cin >> bus[p].driver;
    cout << "\n Arrival time: ";
    cin >> bus[p].arrival;
    cout << "\nDeparture time: ";
    cin >> bus[p].departure;
    cout << "\nFrom: ";
    cin >> bus[p].from;
    cout << "\nTo: ";
    cin >> bus[p].to;
    bus[p].empty();
    p++;
}

void a::allotment()
{
    vline('-');
    cout << endl;
    cout << "                       Ticket Reservation Window" << endl;
    vline('-');
    cout << endl;
    int seat;
    char number[5];
top:
    cout << "Enter the Bus no: ";
    cin >> number;
    int n;

    for (n = 0; n <= p; n++)
    {
        if (strcmp(bus[n].busn, number) == 0)
            break;
    }

    while (n <= p)
    {
        cout << "\n Seat Number: ";
        cin >> seat;
        if (seat > 32)
        {
            cout << "\nThere is only 32 seats in the bus.";
        }
        else
        {
            if (strcmp(bus[n].seat[seat / 4][(seat % 4) - 1], "Empty") == 0)
            {
                cout << "Enter the passenger's name: ";
                cin >> bus[n].seat[seat / 4][(seat % 4) - 1];
                cout << endl;
                break;
            }
            else
            {
                cout << "The seat no is already reserved.\n";
            }
        }
    }
    if (n > p)
    {
        cout << "Enter the correct bus number \n";
        goto top;
    }
}
void a::tkt()
{
    vline('-');
    cout << endl;
    cout << "                       Ticket Downloading Window" << endl;
    vline('-');
    cout << endl;
    int n, seat;
    cout << "Enter the bus no : ";
    cin >> n;
    cout << "You have to enter the seat no for the verification" << endl;
    cin >> seat;
    

    cout << "Your ticket is" << endl;
    cout << endl;
    cout << "__________________________________________________________________________" << endl;
    cout << "                                                                          " << endl;
    cout << "------------------------------Indian Bus Services-------------------------" << endl;
    cout << "Seat no   :" << seat << endl;
    cout << "        ";
    cout << "Status : "
         << "Confirmed" << endl;
    cout << endl;
    cout << "       We wish you a happy journey" << endl;
    cout << "------------------------------Indian Bus Services-------------------------" << endl;
    cout << "__________________________________________________________________________" << endl;
    cout << endl;
}

void a::empty()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            strcpy(bus[p].seat[i][j], "Empty");
        }
    }
}

void a::show()
{
    vline('-');
    cout << endl;
    cout << "                       Seat View" << endl;
    vline('-');
    cout << endl;
    int n;
    char number[5];
    cout << "Enter the bus no :";
    cin >> number;
    for (n = 0; n <= p; n++)
    {
        if (strcmp(bus[n].busn, number) == 0)
            break;
    }

    while (n <= p)
    {
        vline('*');
        cout << endl;
        cout << "Bus no : " << bus[n].busn << "\n Driver : " << bus[n].driver << "\nArrival time : " << bus[n].arrival << "\ndeparture : " << bus[n].departure << "\nFrom : " << bus[n].from << endl;
        cout << "To : " << bus[n].to << endl;
        vline('*');
        bus[0].position(n);
        int a = 1;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                a++;
                if (strcmp(bus[n].seat[i][j], "Empty") != 0)
                    cout << "\n The seat no" << (a - 1) << " is reserved for" << bus[n].seat[i][j] << ".";
            }
        }
        break;
    }
    if (n > p)
        cout << "Enter the correct bus no: ";
}

void a::position(int l)
{
    int s = 0;
    int p = 0;
    for (int i = 0; i < 8; i++)
    {
        cout << endl;
        for (int j = 0; j < 4; j++)
        {
            s++;
            if (strcmp(bus[l].seat[i][j], "Empty") == 0)
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << bus[l].seat[i][j];
                p++;
            }
            else
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << bus[l].seat[i][j];
            }
        }
    }
    cout << endl;
    cout << endl;
    cout << "There are " << p << "empty seats in the bus no:" << bus[l].busn;
}

void a::avail()
{
    vline('-');
    cout << endl;
    cout << "                       Available Buses" << endl;
    vline('-');
    cout << endl;
    for (int n = 0; n < p; n++)
    {

        cout << "Bus no: " << bus[n].busn << endl;
        cout << "Driver: " << bus[n].driver << endl;
        cout << "Arrival time: " << bus[n].arrival << endl;
        cout << "Departure time: " << bus[n].departure << endl;
        cout << "From: " << bus[n].from << endl;
        cout << "To: " << bus[n].to << endl;
    }
}

int main()
{
    system("cls");
    int w;
    cout << "====================================" << endl;
    cout << "---------INDIAN BUS SERIVECES-------" << endl;
    cout << "====================================" << endl;
    cout << "                        By 21BCA0091" << endl;
    cout << "                           21BCA0092" << endl;
    cout << "                           21BCA0132" << endl;
    while (1)
    {

        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "1.Install" << endl;
        cout << "2.Reservation" << endl;
        cout << "3.Show" << endl;
        cout << "4.Buses Available" << endl;
        cout << "5.Check status of Your Ticket" << endl;
        cout << "6.Exit" << endl;
        cout << endl;
        cout << endl;
        cout << "Enter your choice->" << endl;
        cin >> w;
        switch (w)
        {
        case 1:
            bus[p].install();
            break;

        case 2:
            bus[p].allotment();
            break;

        case 3:
            bus[0].show();
            break;

        case 4:
            bus[0].avail();
            break;

        case 5:
            bus[p].tkt();
            break;

        case 6:
            exit(1);
        }
    }
    return 0;
}
