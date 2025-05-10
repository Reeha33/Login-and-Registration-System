# Login-and-Registration-System
Project Overview
This C++ console-based application provides a simple user authentication system that allows users to register (sign up) and login (sign in) securely. It stores the user’s name, date of birth, and password in a local text file (reg.txt). On successful login, it confirms the user's identity. This project serves as an excellent example of file handling, string manipulation, and basic data validation in C++.

Key Features
User Registration
Allows new users to sign up by entering their name, date of birth, and password.

Login Authentication
Users can sign in using the registered credentials.

Duplicate Check
Prevents users from registering with an already existing name and password.

Persistent Storage
User data is stored in a file (reg.txt) for later verification.

Simple Menu Interface
A user-friendly loop-based menu to access services.

How It Works
1. Registration
When a user selects the "Register" option, the system:

Collects the user's name, date of birth, and password.

Checks if this combination already exists in the file.

If not already registered, it appends the information to reg.txt.

2. Login
When a user chooses to login:

The system prompts for name and password.

It reads from the file and compares credentials.

If matched, the login is successful; otherwise, it fails.

3. File Format (reg.txt)
Each line of the file stores a user's record:

pgsql
Copy
Edit
Name,DOB,Password
Code Breakdown
Functions
registeration()
Handles user registration and ensures no duplicate user is registered.

login()
Verifies login credentials by reading from the reg.txt file.

main()
Displays the menu and manages the flow of the program.

Technologies Used
Programming Language: C++

Concepts Used:

File handling using <fstream>

Input/output using cin/cout

String parsing using stringstream

Conditionals, Loops, and Functions

Limitations
Passwords are stored in plain text, which is not secure.

There is no password recovery or encryption.

The file is accessed linearly, which may not scale well with many users.

Future Enhancements
Implement password encryption/hashing for security.

Add support for admin access or different user roles.

Provide email/username-based login.

Introduce multi-session handling and GUI support.

Implement user profile editing and deletion.
