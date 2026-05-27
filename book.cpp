#include <iostream>
#include <fstream>
#include <ios>
#include <iomanip>
#include <chrono>
#include <thread>
using namespace std;
int option_book()
{
    cout << "BOOK MENU" << endl;
    cout << "consider following options & enter option no.:-" << endl;
    cout << "1.writing to books file" << endl;
    cout << "2.inserting to books file" << endl;
    cout << "3.deleting from books file" << endl;
    cout << "4.updating a books file" << endl;
    cout << "5. end " << endl;
    int input;
    cin >> input;
    cout << "\033[2J\033[1;1H";
    return input;
}
class book
{
    int serial_no;
    char book_name[20];
    char author[20];
    int edition;
    int price;

public:
    book(int serial_no, char book_name[20], char author[20], int edition, int price)
    {
        this->serial_no = serial_no;
        strcpy(this->book_name, book_name);
        strcpy(this->author, author);
        this->edition = edition;
        this->price = price;
    }

    book()
    {
        serial_no = 0;
        strcpy(book_name, " ");
        strcpy(author, " ");
        edition = 0;
        price = 0;
    }
    book(int n)
    {
        cout << "Serial No. :";
        cin >> serial_no;
        cout << "Book Name:";
        cin >> book_name;
        cout << "Author of book:";
        cin >> author;
        cout << "Edition of book:";
        cin >> edition;
        cout << "Price of book:";
        cin >> price;
    }
    void display()
    {
        cout << setw(3) << serial_no << setw(16) << book_name << setw(13) << author << setw(13) << edition << setw(13) << price << endl;
    }

    friend int search_book(int n);
    friend void copy_delete_book();
    friend void copy_update_book();
};
// write
void write_book()
{
    ofstream fout("book.dat");
    string permit;
    do
    {
        book b1(1);
        fout.write((char *)&b1, sizeof(b1));
        cout << "do you want to enter more data? :- ";
        cin >> permit;
    } while (permit == "yes");
    fout.close();
}

// ⁡⁢⁣⁣​‌‌‍search
int search_book(int n)
{
    ifstream fin("book.dat");
    book b1;
    int result = 0;
    while (fin.read((char *)&b1, sizeof(b1)))
    {
        if (b1.serial_no == n)
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
void copy_insert_book()
{
    int n;
    int result;
    do
    {
        cout << "enter the book serial no. you want to insert" << endl;
        cin >> n;
        result = search_book(n);
    } while (result == 1);

    ifstream fin("book.dat");
    ofstream fout1("copy_book.dat");
    if (result == 0)
    {
        book b1;
        while (fin.read((char *)&b1, sizeof(b1)))
        {
            fout1.write((char *)&b1, sizeof(b1));
        }
        cout << "enter full details of insertion" << endl;
        book b_insert(1);
        fout1.write((char *)&b_insert, sizeof(b_insert));
    }
    fin.close();
    fout1.close();
    remove("book.dat");
    rename("copy_book.dat", "book.dat");
}

// delete
void copy_delete_book()
{
    int n;
    cout << "enter the book serial no. you want to insert" << endl;
    cin >> n;
    int result = search_book(n);
    ifstream fin("book.dat");
    ofstream fout1("copy_book.dat");
    if (result == 1)
    {
        book b1;
        while (fin.read((char *)&b1, sizeof(b1)))
        {
            if (b1.serial_no != n)
                fout1.write((char *)&b1, sizeof(b1));
        }
    }
    fin.close();
    fout1.close();
    remove("book.dat");
    rename("copy_book.dat", "book.dat");
}

// update
void copy_update_book()
{
    int n;
    cout << "enter the book serial no. you want to update" << endl;
    cin >> n;
    int result = search_book(n);
    ifstream fin("book.dat");
    ofstream fout1("copy_book.dat");
    if (result == 1)
    {
        book b1;
        while (fin.read((char *)&b1, sizeof(b1)))
        {
            if (b1.serial_no == n)
            {
                book b1(1);
                fout1.write((char *)&b1, sizeof(b1));
            }
            else
                cout << "enter full details of updation" << endl;
            fout1.write((char *)&b1, sizeof(b1));
        }
    }
    fin.close();
    fout1.close();
    remove("book.dat");
    rename("copy_book.dat", "book.dat");
}

// checking
void check_book()
{
    ifstream fin1("book.dat");
    cout << "Books in library:" << endl;
    cout << setw(6) << "SR.No." << setw(13) << "BOOK" << setw(13) << "AUTHOR" << setw(13) << "EDITION" << setw(13) << "PRICE" << endl;
    cout << "-----------------------------------------------------------" << endl;
    book b1;
    while (fin1.read((char *)&b1, sizeof(b1)))
    {
        b1.display();
    }
    fin1.close();
    
}
void get_book_menu()
{
    while (1)
    {
        int input = option_book();
        if (input == 1)
            write_book();
        else if (input == 2)
            copy_insert_book();
        else if (input == 3)
            copy_delete_book();
        else if (input == 4)
            copy_update_book();
        else
            goto end;
    }
end:
{
    check_book();
    this_thread::sleep_for(chrono::seconds(2));
    cout << ".............\n.............\n.............\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout <<"The code ends here." << endl;
}
}

int main()
{
    get_book_menu();
}