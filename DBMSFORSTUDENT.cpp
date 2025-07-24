#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct StudentDetails {
    string Name, RegisterNumber, Department, Section, DOB;
    string Address, FathersName, MothersName, StudentPhoneNumber, ParentsPhoneNumber, CGPA;
};
 
void AddDetails() {
    StudentDetails s;
    cin.ignore();
    cout << "Enter Student Name: "; getline(cin, s.Name);
    cout << "Enter Register Number: "; getline(cin, s.RegisterNumber);
    cout << "Enter Department: "; getline(cin, s.Department);
    cout << "Enter Section: "; getline(cin, s.Section);
    cout << "Enter DOB: "; getline(cin, s.DOB);
    cout << "Enter Address: "; getline(cin, s.Address);
    cout << "Enter Father's Name: "; getline(cin, s.FathersName);
    cout << "Enter Mother's Name: "; getline(cin, s.MothersName);
    cout << "Enter Student Phone Number: "; getline(cin, s.StudentPhoneNumber);
    cout << "Enter Parents Phone Number: "; getline(cin, s.ParentsPhoneNumber);
    cout << "Enter CGPA: "; getline(cin, s.CGPA);

    ofstream out("StudentDetails.txt", ios::app);
    if (!out) {
        cout << "Error opening file for writing!\n";
        return;
    }
    out << "Name: " << s.Name << '\n';
    out << "Register Number: " << s.RegisterNumber << '\n';
    out << "Department: " << s.Department << '\n';
    out << "Section: " << s.Section << '\n';
    out << "DOB: " << s.DOB << '\n';
    out << "Address: " << s.Address << '\n'; 
    out << "Father's Name: " << s.FathersName << '\n';
    out << "Mother's Name: " << s.MothersName << '\n';
    out << "Student Phone Number: " << s.StudentPhoneNumber << '\n';
    out << "Parent's Phone Number: " << s.ParentsPhoneNumber << '\n';
    out << "CGPA: " << s.CGPA << '\n';
    out << "------------------------------\n";
    out.close();
}

void ShowDetails() {
    ifstream in("StudentDetails.txt");
    if (!in) {
        cout << "Error opening file for reading!\n";
        return;
    }
    string line;
    while (getline(in, line)) {
        cout << line << '\n';
    }
    in.close();
}

void EditDetails() {
    ifstream in("StudentDetails.txt");
    ofstream temp("Temp.txt");
    if (!in || !temp) {
        cout << "Error opening files!\n";
        return;
    }

    string regToEdit;
    cout << "Enter Register Number to edit: ";
    cin.ignore();
    getline(cin, regToEdit);

    cout << "Choose field to edit:\n";
    cout << "a. Name\nb. Phone Number\nc. Address\nd. Register Number\ne. CGPA\nChoice: ";
    char choice;
    cin >> choice;
    cin.ignore();

    string line;
    bool found = false;

 while (getline(in, line)) {
  
    if (line.find("Name: ") != string::npos) {
        string currentStudent = line;
        temp << line << '\n';

       
        string lines[10];
        for (int i = 0; i < 10; ++i) {
            getline(in, lines[i]);
            temp << lines[i] << '\n';
        }

       
        if (lines[0].find(regToEdit) != string::npos) {
            found = true;
            switch (choice) {
                case 'a':
                    cout << "Enter new name: ";
                    getline(cin, currentStudent);
                    currentStudent = "Name: " + currentStudent;
                    break;
                case 'b':
                    cout << "Enter new phone: ";
                    getline(cin, lines[7]); 
                    lines[7] = "Student Phone Number: " + lines[7];
                    break;
                case 'c':
                    cout << "Enter new address: ";
                    getline(cin, lines[4]); 
                    lines[4] = "Address: " + lines[4];
                    break;
                case 'd':
                    cout << "Enter new register number: ";
                    getline(cin, lines[0]); 
                    lines[0] = "Register Number: " + lines[0];
                    break;
                case 'e':
                    cout << "Enter new CGPA: ";
                    getline(cin, lines[9]);
                    lines[9] = "CGPA: " + lines[9];
                    break;
            }

           
            temp << currentStudent << '\n';
            for (int i = 0; i < 10; ++i)
                temp << lines[i] << '\n';

     
            continue;
        }

    } else {
        temp << line << '\n'; 
    }
}
}

int main() {
    while (true) {
        int choice;
        cout << "\n=== Student Database Menu ===\n";
        cout << "1. Add Student\n2. Show Students\n3. Edit Student\n4. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: AddDetails(); break;
            case 2: ShowDetails(); break;
            case 3: EditDetails(); break;
            case 4: return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}
