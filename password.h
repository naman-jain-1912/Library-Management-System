#include <iostream>
#include <fstream>
#include <termios.h>
#include <unistd.h>
using namespace std;
class authenticate
{
    char username[9];
    char password[9];

public:
    authenticate(char username[9], char password[9])
    {
        strcpy(this->username, username);
        strcpy(this->password, password);
    }
    authenticate()
    {
        strcpy(username, " ");
        strcpy(password, " ");
    }
    authenticate(int n)
    {
        cout << "ENTER USERNAME (8 CHARACTERS ONLY): ";
        cin >> username;
        cout << "ENTER PASSWORD (8 CHARACTERS ONLY): ";
        cin >> password;
    }
    void display()
    {
        cout << "USERNAME-" << username << endl;
        cout << "PASSWORD-" << password << endl;
    }
    friend int check_pass(char input_user[9], char input_pass[9]);
    friend void reset_pass();
};
void write_pass()
{
    ofstream passfile("password.dat");
    authenticate a1(1);
    passfile.write((char *)&a1, sizeof(a1));

    passfile.close();
}
void print()
{
    ifstream fin("password.dat");
    authenticate a;
    fin.read((char *)&a, sizeof(a));
    a.display();
    fin.close();
}
void reset_pass()
{
    cout << "ENTER THE NEW DETAILS" << endl;
    write_pass();
    cout << "\n........\nPASSWORD CHANGED SUCCESFULLY";
}
int check_pass(char input_user[9], char input_pass[9])
{
    ifstream fin("password.dat");
    authenticate a;
    fin.read((char *)&a, sizeof(a));
    if (strcmp(input_user, a.username) == 0 & strcmp(input_pass, a.password) == 0)
        return 1;
    else
        return 0;
    fin.close();
}
int input_password(char ARR[]){
    int argc; char ** argv;
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= 'a'; // remove ~ECHO
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Hides

    string s, current;
    char c;
    cout << setw(80) << "ENTER PASSWORD" << endl;
        cout << setw(69) << " ";
    do {
      cout << current;
      s += c;
      current = "*";
    }while((c = getchar()) != '\n' && c != EOF);


  
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // return to display
  strcpy(ARR,s.c_str());
    return EXIT_SUCCESS;
}
