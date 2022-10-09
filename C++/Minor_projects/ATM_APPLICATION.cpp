// Function Containted check balance,deposit , withdraw , showmenu
#include <iostream>
using namespace std;
void showmenu()
{
    cout << "**********MENU**********" << endl;
    cout << "1.Check Balance" << endl;
    cout << "2.Deposit " << endl;
    cout << "3.Withdraw " << endl;
    cout << "4.Exit" << endl;
    cout << "**********MENU**********" << endl;
}

int main()
{
    int option;
    double balance = 0;
    do
    {
        showmenu();
        cout << " Please choose one of the option" << endl;
        cin >> option;
        system("cls");
        switch (option)
        {
        case 1:
            cout << "Balance is : "
                 << " $" << balance << endl;
            break;
        case 2:
            cout << "Deposit Amount:";
            double depositamount;
            cin >> depositamount;
            balance += depositamount;
            break;
        case 3:
            double withdraw;
            cout << "Withdraw amount ";
            cout << "Please Enter the Amount To WithDraw";
            cin >> withdraw;
            if (withdraw < balance)
            {
                cout << " Money Send Successfully " << endl;
                balance -= withdraw;
            }
            else
            {
                cout << " Not Enough Balance " << endl;
            }
            break;
        default:
            cout << " Please choose the vaild Option " << endl;
        }

    } while (option != 4);
    return 0;
}