// C++ Project to display the marksheet Generator of an student from his obtained marks
#include <iostream>
#include <iomanip>
#include <unistd.h>
using namespace std;
ostream &Percentage_Symbol(ostream &output) // Custom Manipulator
{
    return output << "%";
}
class Student_Data
{
    float *marks;
    float Percentage;
    float total_Obtained_marks;
    char pass_fail;
    int status;
    int sub;
    int *FM;
    float *PM;
    int Total;
    string sub_name[30];

public:
    Student_Data() // Constructor Called
    {
        int sub;
        int Total;
        float total_Obtained_marks;
        int status = 0;
    }
    ~Student_Data() // Destructor
    {
        int sub;
        int Total = 0;
        float total_Obtained_marks;
        int status = 0;
    }
    void loader(void);
    void ask(void) // first Step
    {
        system("cls");
        system("Color 0A");
        cout << "********************** Welcome to marksheet generator program in C++ ********************" << endl;
        cout << "Enter the number of subject" << endl;
        cin >> sub;
        cout << "Recieved Successfully!" << endl;
    }
    void Data_Input(void) // Data entry here
    {
        system("Color 0A");
        system("cls");
        sub_name[sub];
        Total = 0;
        system("cls");
        cout << "Start Entering the Subject Name & Marks" << endl;
        for (int i = 0; i < sub; i++)
        {
            system("cls");
            cout << "Enter the " << i + 1 << " Subject Name" << endl;
            cin >> sub_name[i];
            cout << "Full Marks:" << endl;
            cin >> FM[i];
            Total += FM[i];
            cout << "Pass Marks" << endl;
            cin >> PM[i];
            cout << "Enter the " << i + 1 << " Obtained Marks" << endl;
            cin >> marks[i];
            if (PM[i] > marks[i])
            {
                status = 1;
            }
            else
            {
                status = 0;
            }
            total_Obtained_marks += marks[i];
        }
    }
    void percentage_calc_status(void) // Percentage Calaculator
    {
        Percentage = ((total_Obtained_marks) / Total) * 100;
        if (status == 0)
        {
            pass_fail = 'P';
        }
        else
        {
            pass_fail = 'F';
        }
    }
    void generator(void) // Loader Screen for Generator
    {
        for (int i = 80; i < 100; i += 10)
        {
            system("cls");
            system("Color 0A");
            cout << "Generating Marksheet... " << i << Percentage_Symbol << endl;
            sleep(2);
        }
    }
    void output_display(void) // Display System
    {
        system("Color 0A");
        generator();
        system("cls");
        cout << "***********************-YOUR MARKSHEET-*********************" << endl;
        cout << setw(20) << "Subject Name"
             << "    " << setw(4)
             << "FM" << setw(6)
             << "    " << setw(4)
             << "PM" << setw(6)
             << "    " << setw(6)
             << "Obtained Marks" << setw(20) << endl;
        cout << "---------------------------------------------------------------" << endl;
        for (int i = 0; i < sub; i++)
        {
            cout << setw(20) << sub_name[i]
                 << "    " << setw(4)
                 << FM[i] << setw(6)
                 << "    " << setw(4)
                 << PM[i] << setw(6)
                 << "    " << setw(6)
                 << marks[i] << setw(20) << endl;
        }
        cout << "---------------------------------------------------------------" << endl;
        cout << setw(25) << "Total Marks:" << Total << endl;
        cout << setw(25) << "Obtained Marks:" << total_Obtained_marks << endl;
        if (pass_fail == 'P')
        {
            cout << setw(25) << "Percentage:" << Percentage << Percentage_Symbol << endl;
            cout << setw(25) << "Status:" << pass_fail;
        }
        else
        {
            cout << setw(20) << "Status:" << pass_fail;
        }
    }
    void allocator(int a) // Memory Initiator and Remover
    {
        if (a == 1)
        {
            marks = new float[sub];
            FM = new int[sub];
            PM = new float[sub];
        }
        else
        {
            delete[] marks;
            delete[] FM;
            delete[] PM;
        }
    }
};
void Student_Data ::loader(void)
{
    system("Color 0A");
    for (int i = 0; i < 3; i++)
    {
        system("cls");
        cout << "Opening Console";
        for (int j = 0; j < 3; j++)
        {
            cout << ".";
            sleep(1);
        }
    }
}
int main() // Main Module
{
    char runner = 'x';
    do
    {
        system("cls");
        system("Color 0A");
        Student_Data s1;
        if (runner == 'x')
        {
            s1.loader();
        }
        s1.ask();
        s1.allocator(1);
        s1.Data_Input();
        s1.percentage_calc_status();
        s1.output_display();
        s1.allocator(2);
        cout << "\nDo you want another Marksheet?(y/n)\n"
             << endl;
        cin >> runner;
    } while (runner == 'y' || runner == 'Y');
    return 0;
}