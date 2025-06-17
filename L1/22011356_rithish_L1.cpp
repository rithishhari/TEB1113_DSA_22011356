/*
id: 22011356
name: Rithish Hari
contact: +60182030508
email: rithish_22011356@utp.edu.
lab: 1 
*/


#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    string phone;
    string email;
};

int main()
{
    const int SIZE = 3; 
    Student students[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> students[i].id;
        cin.ignore();

        cout << "Name: ";
        getline(cin, students[i].name);

        cout << "Phone: ";
        getline(cin, students[i].phone);

        cout << "Email: ";
        getline(cin, students[i].email);
        cout << endl;
    }

    return 0;
}