#include <iostream>
// #include "students.h"
// #include "book.h"
#include "issue.h"
#include "password.h"
int authentication()
{
    char input_user[20], input_pass[20];
    int i;
    for (i = 0; i < 3; i++)
    {
        cout << "\033[2J\033[1;1H";
        cout << setw(80) << "WELCOME" << endl;
         this_thread::sleep_for(chrono::seconds(1));
        cout << "\033[2J\033[1;1H";
        cout << setw(80) << "ENTER USERNAME" << endl;
        cout << setw(69) << " ";
        cin >> input_user;
        cout << setw(80) << "ENTER PASSWORD" << endl;
        cout << setw(69) << " ";
        // input_password(input_pass);
        cin>> input_pass;
        int res_check_pass = check_pass(input_user, input_pass);
        if (res_check_pass == 1)
            break;
        else
        {
            cout << "\033[2J\033[1;1H";
            cout << setw(80) << "WRONG CREDENTIALS" << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
    if (i == 3)
    {
        cout << "\n\nYOU FAILED TO ENTER CORRRECT CREDENTIALS SO YOU CAN'T CONTINUE" << endl;
        return 0;
    }
    else
        return 1;
}
int option_p()
{

    cout << "consider following options & enter option no.:-" << endl;
    cout << "1. Get STUDENT Menu" << endl;
    cout << "2. Get BOOK Menu" << endl;
    cout << "3. Get ISSUE Menu" << endl;
    cout << "4. RESET PASSWORD" << endl;
    cout << "5. END & LOCK" << endl;
    int input;
    cin >> input;
    cout << "\033[2J\033[1;1H";
    return input;
}

void get_menu()
{
    while (1)
    {
        int input = option_p();
        if (input == 1)
            get_student_menu();
        else if (input == 2)
            get_book_menu();
        else if (input == 3)
            get_issue_menu();
        else if (input == 4)
            write_pass();
        else
            goto end;
    }
end:
{
    for (int i = 0; i < 2; i++)
    {
        this_thread::sleep_for(chrono::seconds(1));
        cout << setw(80) << ".............\n";
        cout << "\033[2J\033[1;1H";
    }
    this_thread::sleep_for(chrono::seconds(2));
    cout << setw(80) << "LOGGING OUT" << endl;
    cout << "\033[2J\033[1;1H";
    this_thread::sleep_for(chrono::seconds(2));
    cout << setw(80) << "HAVE A NICE DAY" << endl;
}
}

int main()
{
    int out_authen = authentication();
    cout << "\033[2J\033[1;1H";
    if (out_authen == 0)
        exit(0);

    for (int i = 0; i < 3; i++)
    {
        this_thread::sleep_for(chrono::seconds(1));
        cout << setw(80) << ".............\n";
    }
    cout << "\033[2J\033[1;1H";
    this_thread::sleep_for(chrono::seconds(1));
    cout << setw(80) << "Starting the execution..." << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\033[2J\033[1;1H";
    get_menu();
}
