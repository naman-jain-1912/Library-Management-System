#include <iostream>
#include <fstream>
#include <ctime>
#include "tzfile.h"
#include "students.h"
#include "book.h"
#include <ios>
#include <iomanip>
#include <chrono>
#include <thread>
using namespace std;
int option_issue()
{
    cout << "ISSUE MENU" << endl;
    cout << "consider following options & enter option no.:-" << endl;
    cout << "1.writing to issue file" << endl;
    cout << "2.inserting to issue file" << endl;
    cout << "3.deleting from issue file" << endl;
    cout << "4.updating a issue file" << endl;
    cout << "5. end " << endl;
    int input;
    cin >> input;
    cout << "\033[2J\033[1;1H";
    return input;
}

class issue
{
    int issue_id;
    int book_id;
    int student_id;
    struct tm issue_date;
    struct tm return_date;
    time_t id;

public:
    issue(int issue_id, int book_id, int student_id, struct tm issue_date, struct tm return_date)
    {
        this->issue_id = issue_id;
        this->book_id = book_id;
        this->student_id = student_id;
        this->issue_date = issue_date;
        this->return_date = return_date;
    }

    issue()
    {
        issue_id = 0;
        book_id = 0;
        student_id = 0;
        issue_date;
        return_date;
    }
    issue(int n)
    {
        int result1;
        int result2;
        do
        {
            cout << "enter valid  student id" << endl;
            cin >> student_id;
            result1 = search_stu(student_id);
        } while (result1 == 0);
        do
        {
            cout << "enter valid book serial no." << endl;
            cin >> book_id;
            result2 = search_book(book_id);
        } while (result2 == 0);
        cout << "Sr. No. : ";
        cin >> issue_id;
        cout << "BOOK ID : ";
        cin >> book_id;
        cout << "STUDENT ID : ";
        cin >> student_id;
        cout << "RETURN DAY: ";
        cin >> return_date.tm_mday;
        cout << "RETURN MONTH: ";
        int month;
        cin >> month;
        return_date.tm_mon = month - 1;
        cout << "RETURN YEAR: ";
        int year;
        cin >> year;
        return_date.tm_year = year - 1900;
        time(&id);
        issue_date = *localtime(&id);
    }

    void display()
    {
        cout << setw(3) << issue_id << ". " << setw(9) << book_id << setw(12) << student_id;
        char output[50];
        strftime(output, 50, "%e %b,%Y", &issue_date);
        cout << setw(19) << output;
        strftime(output, 50, "%I:%M:%S %p", &issue_date);
        cout << setw(15) << output;
        strftime(output, 50, "%e %b,%Y", &return_date);
        cout << setw(15) << output << endl;
    }
    friend int search_iss(int n);
    friend void copy_delete_iss();
    friend void copy_update_iss();
};
// write
void write_iss()
{
    ofstream fout("issue.dat");
    string permit;
    do
    {
        issue i1(1);
        fout.write((char *)&i1, sizeof(i1));
        cout << "do you want to enter more data? :- ";
        cin >> permit;
    } while (permit == "yes");
    fout.close();
}

// ⁡⁢⁣⁣​‌‌‍search
int search_iss(int n)
{
    ifstream fin("issue.dat");
    issue i1;
    int result = 0;
    while (fin.read((char *)&i1, sizeof(i1)))
    {
        if (i1.issue_id == n)
        {
            result = 1;
            cout << "FOUND IN EXISTING DATA" << endl;
            break;
        }
    }
    if (result == 0)
        cout << "NOT FOUND IN EXISTING DATA" << endl;
    return result;
}

// insert
void copy_insert_iss()
{
    int n;
    cout << "enter the issue id you want to insert" << endl;
    cin >> n;
    int result = search_iss(n);
    ifstream fin("issue.dat");
    ofstream fout1("copy_issue.dat");
    if (result == 0)
    {
        issue i1;
        while (fin.read((char *)&i1, sizeof(i1)))
        {
            fout1.write((char *)&i1, sizeof(i1));
        }
        cout << "enter full details of insertion" << endl;
        issue i_insert(1);
        fout1.write((char *)&i_insert, sizeof(i_insert));
    }
    fin.close();
    fout1.close();
    remove("issue.dat");
    rename("copy_issue.dat", "issue.dat");
}

// delete
void copy_delete_iss()
{
    int n;
    cout << "enter the issue id id you want to insert" << endl;
    cin >> n;
    int result = search_iss(n);
    ifstream fin("issue.dat");
    ofstream fout1("copy_issue.dat");
    if (result == 1)
    {
        issue i1;
        while (fin.read((char *)&i1, sizeof(i1)))
        {
            if (i1.issue_id != n)
                fout1.write((char *)&i1, sizeof(i1));
        }
    }
    fin.close();
    fout1.close();
    remove("issue.dat");
    rename("copy_issue.dat", "issue.dat");
}

// update
void copy_update_iss()
{
    int n;
    cout << "enter the issue id you want to update" << endl;
    cin >> n;
    int result = search_iss(n);
    ifstream fin("issue.dat");
    ofstream fout1("copy_issue.dat");
    if (result == 1)
    {
        issue i1;
        while (fin.read((char *)&i1, sizeof(i1)))
        {
            if (i1.issue_id == n)
            {
                issue i1(1);
                fout1.write((char *)&i1, sizeof(i1));
            }
            else
                cout << "enter full details of updation" << endl;
            fout1.write((char *)&i1, sizeof(i1));
        }
    }
    fin.close();
    fout1.close();
    remove("issue.dat");
    rename("copy_issue.dat", "issue.dat");
}

// checking
void check_iss()
{
    ifstream fin1("issue.dat");
    cout << "ISSUE RECORD" << endl;
    cout << "SR.NO." << setw(11) << "BOOK ID" << setw(14) << "STUDENT ID" << setw(14) << "ISSUE DATE" << setw(14) << "ISSUE TIME" << setw(16) << "RETURN DATE" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    issue i;
    while (fin1.read((char *)&i, sizeof(i)))
    {
        i.display();
    }
    fin1.close();
}

void get_issue_menu()
{
    while (1)
    {
        int input = option_issue();
        if (input == 1)
            write_iss();
        else if (input == 2)
            copy_insert_iss();
        else if (input == 3)
            copy_delete_iss();
        else if (input == 4)
            copy_update_iss();
        else
            goto end;
    }
end:
{
    check_iss();
    this_thread::sleep_for(chrono::seconds(2));
    cout << ".............\n.............\n.............\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout << "The code ends here." << endl;
}
}