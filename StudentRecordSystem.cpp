#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class student
{
public:
    char fname[20];
    char lname[20];
    int roll,sem;
    float cgpa;
    char courseid[20];

    void student1()
    {
        fflush(stdin);
        cout<<"Add the Student Details: "<<endl;
        cout << "Enter Student Roll No: " << endl;
        cin >> roll;
        fflush(stdin);
        cout << "Enter Student First Name : " << endl;
        cin.getline(fname, 20);
        fflush(stdin);
        cout << "Enter Student Last Name : " << endl;
        cin.getline(lname, 20);
        fflush(stdin);
        cout << "Enter Student Semester: " << endl;
        cin >> sem;
        cout << "Enter Student CGPA: " << endl;
        cin >> cgpa;
        for(int i=1;i<=3;i++)
        {
            cout<<"Enter the Id of Course: "<<i<<" ";
            cin>>courseid[i];

        }
    }
    void display()
    {
        cout << "Roll No: " << roll << endl;
        cout << "First Name: " << fname << endl;
        cout << "Last Name: " << lname << endl;
        cout << "Semester: " << sem << endl;
        cout << "CGPA: " << cgpa << endl;
         for(int i=1;i<=3;i++)
        {
            cout<<"Id of Course: "<<i<<" "<<courseid[i]<<endl;
        }

    }
    void add_data();
    void updatedata(int);
    void searchnum(int);
    void display_all_num();
    void deletestu(int);
    void total();
};
void student::add_data()
{
    ofstream ab;
    ab.open("Student.txt", ios ::app | ios::binary);
    ab.write((char *)this, sizeof(*this));
    ab.close();
}
void student::updatedata(int id)
{
    fstream file;
    file.open("Student.txt", ios ::in | ios ::out | ios::binary | ios::ate);
    file.seekg(0);
    file.read((char *)this, sizeof(*this));
    while (!file.eof())
    {
        if (roll == id)
        {
            display();
            int b;
            do
            {
            cout<<"1. Update First Name\n2. Update Last Name\n3. Update CGPA\n4. Exist\n";
            cout<<"Enter choice : ";
            cin>>b;
            switch(b)
            {
            case 1:
            {
            char f[20];
            cout << "\nEnter new First Name: " << endl;
            cin.getline(f, 20);
            rename(fname,f);
            file.seekp(file.tellp() - sizeof(*this));
            file.write((char *)this, sizeof(*this));
            break;
            }
            case 2:
            {
            char l[20];
            cout << "\nEnter new Last Name: " << endl;
            cin.getline(lname, 20);
            rename(lname,l);
            file.seekp(file.tellp() - sizeof(*this));
            file.write((char *)this, sizeof(*this));
            break;
            }
            case 3:
            {
             int newl;
            cout << "\nEnter new CGPA: " << endl;
            cin >> newl;
             cgpa = newl;
            file.seekp(file.tellp() - sizeof(*this));
            file.write((char *)this, sizeof(*this));
            break;
            }
            }
            }while(b !=4);
        }
        file.read((char *)this, sizeof(*this));
    }
}
void student::searchnum(int id)
{
    ifstream fin;
    int counter;
    fin.open("Student.txt", ios::in | ios::binary);
    if (fin.eof() == 1)
    {
        cout << "file ended\n";
    }
    else
    {
        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            if (roll == id)
            {
                display();
                counter++;
            }
            fin.read((char *)this, sizeof(*this));
        }
        if (counter == 0)
        {
            cout << "\nRecord was not found";
        }
    }
    fin.close();
}
void student::display_all_num()
{
    ifstream fin;
    fin.open("Student.txt", ios::in | ios::binary);
    if (fin.eof() == 1)
    {
        cout << "file ended\n";
    }
    else
    {
        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            display();
            fin.read((char *)this, sizeof(*this));
        }
        fin.close();
    }
}

void student::deletestu(int id)
{int pos, flag = 0;

    ifstream ifs;
    ifs.open("Student.txt", ios::in | ios::binary);

    ofstream ofs;
    ofs.open("temp.txt", ios::out | ios::binary);

    while (!ifs.eof()) {

        ifs.read((char*)this, sizeof(*this));

        if (ifs) {

            if (roll == id) {
                flag = 1;
                cout << "The deleted record is \n";

                display();
            }
            else {

                ofs.write((char*)this, sizeof(*this));
            }
        }
    }

    ofs.close();
    ifs.close();

    remove("Student.txt");

    rename("temp.txt", "Student.txt");

    if (flag == 1)
        cout << "\nRecord successfully deleted \n";
    else
        cout << "\nRecord not found \n";
}
void student::total()
{
    ifstream fin;
    char ch;
    int c=0;
    fin.open("Student.txt", ios::in | ios::binary);
    if (fin.eof() == 1)
    {
        cout << "file ended\n";
    }
    else
    {
        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            ch = fin.get();
            if(ch=='\n')
            {
                c++;
            }

        }
        fin.close();
        cout<<"Total number of Students are: "<<(c/9 + 1)<<endl;
    }
}



int main()
{
     cout<<".............................................................................STUDENT RECORD SYSTEM.........................................................................\n";
    student s;
     int a;
     do
     {

    cout<<"\n**********************************************\n";
    cout << "1. Add Student Details" << endl;
    cout << "2. Update the Student Details by Roll Number " << endl;
    cout << "3. Search Student Details by Roll Number " << endl;
    cout << "4. Display Student Details " << endl;
    cout << "5. Delete the Students Details by Roll Number " << endl;
    cout << "6. Search Total Number of Students " << endl;
    cout << "7. Exit " << endl;

    cout<<"**********************************************\n";
    cout << "\nEnter your choice " << endl;


    cin >> a;
    switch (a)
    {
    case 1:
    {
        s.student1();
        s.add_data();

        break;
    }
    case 2:
    {

        cout << "\nEnter roll number of student whose data you want to update:"<<endl;
        int id;
        cin >> id;
        s.updatedata(id);

        break;
    }
    case 3:
    {
        int id;
        cout << "\nEnter roll number of student whose data you want to search: " << endl;
        cin >> id;
        s.searchnum(id);

        break;
    }
    case 4:
    {
        s.display_all_num();

        break;
    }
    case 5:
    {
        int id;
        cout << "\nEnter roll number of student whose data you want to delete: " << endl;
        cin >> id;
        s.deletestu(id);
            break;
    }
    case 6:
    {
            s.total();
            break;
    }
     }
     }while(a != 7);
}

