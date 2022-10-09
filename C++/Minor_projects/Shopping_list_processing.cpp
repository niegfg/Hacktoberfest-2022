// C++ Program to process the shopping list
#include <iostream>
#include <unistd.h>
#include <iomanip>
using namespace std;
// I have made here the custom manipulator to use Currency denotion
ostream &currency(ostream &output)
{
    return output << "\tRs.";
}
ostream &loader(ostream &output)
{
    return output << "%";
} // For % in loading  screen
const int m = 50;
class ITEM
{
    int itemcode[m];
    float itemprice[m];
    int count;
    float total;

public:
    void counter(void) { count = 0; }
    void loading(void);
    void getitem(void);
    void displaySum(void);
    void remove(void);
    void displayItems(void);
    void holder(void);
    ITEM(){
        total;
    }
};
void ITEM::loading(void) // Adding the loading screen in CPP
{
    int load;
    for (load = 40; load != 100; load += 20)
    {
        system("cls");
        cout << "Loading..." << load << loader << endl;
        sleep(2);
    }
}

void ITEM ::getitem(void) // Reading an item
{
    system("cls");
    cout << "Enter item code:" << endl;
    cin >> itemcode[count];
    cout << "Enter item cost" << endl;
    cin >> itemprice[count];
    count++;
}
void ITEM::displaySum(void) // Displaying sum
{
    system("cls");
     total = 0;
    for (int i = 0; i < count; i++)
    {
        total += itemprice[i];
    }
    cout << "Total Price:" << currency << total << endl;
    holder();
}
void ITEM ::remove(void) // removing items
{
    system("cls");
    int a;
    cout << "Enter item code to remove item" << endl;
    cin >> a;
    for (int i = 0; i < count; i++)
    {
        if (itemcode[i] == a)
        {
            itemprice[i] = 0;
        }
    }
}
void ITEM ::displayItems(void) // displaying item
{
    system("cls");
    cout << "\n"
         << setw(10) << "Item-Code"
         << "     " << setw(10) << "Item-Price";
    for (int i = 0; i < count; i++)
    {
        cout << "\n"
             << setw(10) << itemcode[i] << " " << setw(10) << itemprice[i];
    }
    cout << "\n****************************\n";
    cout <<"Total Price:"<<currency<<total<<endl;
    holder();
}
void ITEM::holder()
{
    char x;
    cout << "Enter any Key to Continue....\n";
    cin >> x;
}
// Completion of editing in classes
int main()
{
    ITEM order;
    order.counter();
    order.loading();
    int x = 0;
    char e;
    A:
    do
    {

        if (x == 0)
        {
            system("cls");
        }
        else
        {
            system("cls");
            cout << "Task Done Successfully!\n";
        }
        cout << "____________________________Welcome to Prajjwal Live C++ shopping Centre_____________________________" << endl;
        cout << "You can do the following things\n";
        cout << "Please choose the appropriate numbers";
        cout << "\n1:Add an item"
             << "\n2.Display Total"
             << "\n3.Remove an item"
             << "\n4.Display all items"
             << "\n5.Check out\n";
        cout << "***********************************************************\n"
             << endl;
        cout << "what is your option\n";
        cin >> x;
        switch (x)
        {
        case 1:
            order.getitem();
            break;
        case 2:
            order.displaySum();
            break;
        case 3:
            order.remove();
            break;
        case 4:
            order.displayItems();
            break;
        case 5:
            cout << "Do want to proceed to check out!(y/n)" << endl;
            cin >> e;
            if (e == 'y' || e == 'Y')
            {
                exit(32);
            }
            else
            {
                goto A;
            }
        default:
            cout << "Error in input : Please! try again" << endl;
            order.holder();
        }
    } while (x != 5);
    return 0;
}