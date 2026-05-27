#include <iostream>
#include <fstream>
#include <ios>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;
int option_stu()
{
    cout << "STUDENT MENU" << endl;
    cout << "consider following options & enter option no.:-" << endl;
    cout << "1.writing to student file" << endl;
    cout << "2.inserting to student file" << endl;
    cout << "3.deleting from student file" << endl;
    cout << "4.updating a student file" << endl;
    cout << "5. end " << endl;
    int input;
    cin >> input;
    cout << "\033[2J\033[1;1H";
    return input;
}
class student
{
    int roll_no;
    char name[20];
    int dd, mm, yyyy;

public:
    student(int roll_no, char name[20], int dd, int mm, int yyyy)
    {
        this->roll_no = roll_no;
        strcpy(this->name, name);
        this->dd = dd;
        this->mm = mm;
        this->yyyy = yyyy;
    }

    student()
    {
        roll_no = 0;
        strcpy(name, " ");
        dd = 0;
        mm = 0;
        yyyy = 0;
    }
    student(int n)
    {
        cout << "Roll No. :";
        cin >> roll_no;
        cout << "Name:";
        cin >> name;
        cout << "Date";
        cin >> dd;
        cout << "Month";
        cin >> mm;
        cout << "Year";
        cin >> yyyy;
    }
    void display()
    {
        cout << setw(4) << roll_no;
        cout << setw(17) << name;
        cout << setw(12) << dd << "/" << setw(2) << mm << "/" << yyyy << endl;
    }

    friend int search_stu(int n);
    friend void copy_delete_stu();
    friend void copy_update_stu();
};
// write
void write_stu()
{
    ofstream fout("student.dat");
    string permit;
    do
    {
        student s1(1);
        fout.write((char *)&s1, sizeof(s1));
        cout << "do you want to enter more data? :- ";
        cin >> permit;
    } while (permit == "yes");
    fout.close();
}

// ⁡⁢⁣⁣​‌‌‍search
int search_stu(int n)
{
    ifstream fin("student.dat");
    student s1;
    int result = 0;
    while (fin.read((char *)&s1, sizeof(s1)))
    {
        if (s1.roll_no == n)
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
void copy_insert_stu()
{
    int n;
    cout << "enter the roll no. you want to insert" << endl;
    cin >> n;
    int result = search_stu(n);
    ifstream fin("student.dat");
    ofstream fout1("copy_student.dat");
    if (result == 0)
    {
        student s1;
        while (fin.read((char *)&s1, sizeof(s1)))
        {
            fout1.write((char *)&s1, sizeof(s1));
        }
        cout << "enter full details of insertion" << endl;
        student s_insert(1);
        fout1.write((char *)&s_insert, sizeof(s_insert));
    }
    fin.close();
    fout1.close();
    remove("student.dat");
    rename("copy_student.dat", "student.dat");
}

// delete
void copy_delete_stu()
{
    int n;
    cout << "enter the roll no. you want to insert" << endl;
    cin >> n;
    int result = search_stu(n);
    ifstream fin("student.dat");
    ofstream fout1("copy_student.dat");
    if (result == 1)
    {
        student s1;
        while (fin.read((char *)&s1, sizeof(s1)))
        {
            if (s1.roll_no != n)
                fout1.write((char *)&s1, sizeof(s1));
        }
    }
    fin.close();
    fout1.close();
    remove("student.dat");
    rename("copy_student.dat", "student.dat");
}

// update
void copy_update_stu()
{
    int n;
    cout << "enter the roll no. you want to update" << endl;
    cin >> n;
    int result = search_stu(n);
    ifstream fin("student.dat");
    ofstream fout1("copy_student.dat");
    if (result == 1)
    {
        student s1;
        while (fin.read((char *)&s1, sizeof(s1)))
        {
            if (s1.roll_no == n)
            {
                student s1(1);
                fout1.write((char *)&s1, sizeof(s1));
            }
            else
                cout << "enter full details of updation" << endl;
            fout1.write((char *)&s1, sizeof(s1));
        }
    }
    fin.close();
    fout1.close();
    remove("student.dat");
    rename("copy_student.dat", "student.dat");
}

// checking
void check_stu()
{
    ifstream fin1("student.dat");
    cout << "STUDENT DATA" << endl;
    cout << "ROLL No." << setw(12) << "NAME" << setw(17) << "DOB" << endl;
    cout << "------------------------------------------" << endl;
    student s;
    while (fin1.read((char *)&s, sizeof(s)))
    {
        s.display();
    }
    fin1.close();
}

void get_student_menu()
{
    while (1)
    {
        int input = option_stu();
        if (input == 1)
            write_stu();
        else if (input == 2)
            copy_insert_stu();
        else if (input == 3)
            copy_delete_stu();
        else if (input == 4)
            copy_update_stu();
        else
            goto end;
    }
end:
{
    check_stu();
    this_thread::sleep_for(chrono::seconds(2));
    cout << ".............\n.............\n.............\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout << "The code ends here." << endl;
}
}