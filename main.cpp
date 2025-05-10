#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits> // for numeric_limits

using namespace std;

void registeration()
{
    string Name;
    string DOB;
    string Password;

    // Clear the input buffer before taking new input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Your Name: ";
    getline(cin, Name);
    cout << "Enter your Date of Birth: ";
    getline(cin, DOB);
    cout << "Enter Your Password: ";
    getline(cin, Password);

    // Check if the file already exists and if the user is already registered
    ifstream f1("reg.txt");
    if (f1.is_open())
    {
        string line;
        while (getline(f1, line))
        {
            stringstream ss(line);
            string fname, fDOB, fpassword;
            getline(ss, fname, ',');
            getline(ss, fDOB, ',');
            getline(ss, fpassword, ',');

            if (fname == Name && fpassword == Password)
            {
                cout << "You are already registered in the system. You just need to login." << endl;
                f1.close();
                return;
            }
        }
        f1.close();
    }

    // Register the user by appending to the file
    ofstream f("reg.txt", ios::app);
    if (!f.is_open())
    {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    f << Name << "," << DOB << "," << Password << endl;
    f.close();

    cout << "Registration successful!" << endl;
}

void login()
{
    int r = 0;  // Reset the login status before each attempt

    string Name;
    string Password;

    // Clear the input buffer before taking new input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Your Name: ";
    getline(cin, Name);
    cout << "Enter Your Password: ";
    getline(cin, Password);

    ifstream f1("reg.txt");
    if (!f1.is_open())
    {
        cout << "Error opening file for reading or file does not exist!" << endl;
        return;
    }

    string line;
    while (getline(f1, line))
    {
        stringstream ss(line);
        string fname, fDOB, fpassword;
        getline(ss, fname, ',');
        getline(ss, fDOB, ',');
        getline(ss, fpassword, ',');

        if (fname == Name && fpassword == Password)
        {
            r = 1;
            break;
        }
    }
    f1.close();

    if (r == 1)
    {
        cout << "Login successful!!!" << endl;
    }
    else
    {
        cout << "Login failed! Incorrect Name or Password." << endl;
    }
}

int main()
{
    int s, g;
    do
    {
        cout << "Welcome to CodeAlpha" << endl;
        cout << "-----------------------" << endl;
        cout << "Select Services:" << endl;
        cout << "1. Register/Sign Up" << endl;
        cout << "2. Login/Sign In" << endl;
        cin >> s;

        if (s == 1)
        {
            registeration();
        }
        else if (s == 2)
        {
            login();
        }
        else
        {
            cout << "Invalid Input! Try Again." << endl;
        }

        cout << "Press 1 to Continue or 0 to Exit: ";
        cin >> g;

    } while (g != 0);

    return 0;
}
