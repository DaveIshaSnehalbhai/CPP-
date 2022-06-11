#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class tel_dir
{
public:
    char name[20];
    long long int phone_number;

    void itel_dir()
    {
        fflush(stdin);
        cout << " enter person name :: " << endl;
        cin.getline(name, 20);
        fflush(stdin);
        cout << "enter phone number (10 digit number):: " << endl;
        cin >> phone_number;
    }
    void display()
    {
        cout << "name :: " << name << endl;
        cout << "phone number :: " << phone_number << endl;
    }
    void add_data();
    void updatedata(long long int);
    void searchnum(char *);
    void display_all_num();
};
void tel_dir::add_data()
{
    ofstream ab;
    ab.open("tele.txt", ios ::app | ios::binary);
    ab.write((char *)this, sizeof(*this));
    ab.close();
}
void tel_dir::updatedata(long long int ph_num)
{
    fstream file;
    file.open("tele.txt", ios ::in | ios ::out | ios::binary | ios::ate);
    file.seekg(0);
    file.read((char *)this, sizeof(*this));
    while (!file.eof())
    {
        if (phone_number == ph_num)
        {
            display();
            long long int ph_no;
            cout << "\nenter new phone number :: " << endl;
            cin >> ph_no;
            phone_number = ph_no;
            file.seekp(file.tellp() - sizeof(*this));
            file.write((char *)this, sizeof(*this));
        }
        file.read((char *)this, sizeof(*this));
    }
}
void tel_dir::searchnum(char *t)
{
    ifstream fin;
    int counter;
    fin.open("tele.txt", ios::in | ios::binary);
    if (fin.eof() == 1)
    {
        cout << "file ended\n";
    }
    else
    {
        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            if (!strcmp(name, t))
            {
                display();
                counter++;
            }
            fin.read((char *)this, sizeof(*this));
        }
        if (counter == 0)
        {
            cout << "\nrecord was not found";
        }
    }
    fin.close();
}
void tel_dir::display_all_num()
{
    ifstream fin;
    fin.open("tele.txt", ios::in | ios::binary);
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
int main()
{
label:
    cout << "1. add new customer " << endl;
    cout << "2. update telephone number " << endl;
    cout << "3. search number " << endl;
    cout << "4. display " << endl;
    cout << "\n\n enter your choice " << endl;
    tel_dir tel;
    int a;
    cin >> a;
    switch (a)
    {
    case 1:
    {
        tel.itel_dir();
        tel.add_data();
        cout << "\n\ndo you want continue :: \n\n " << endl;
        char b;
        cin >> b;
        if (b == 'y' || b == 'Y')
        {
            goto label;
        }
        break;
    }
    case 2:
    {

        cout << "\n\nEnter person ph_no whose number to be changed (10 digit) ::";
        long long int ph_no;
        cin >> ph_no;
        tel.updatedata(ph_no);
        cout << "\n\ndo you want continue :: \n\n " << endl;
        char b;
        cin >> b;
        if (b == 'y' || b == 'Y')
        {
            goto label;
        }
        break;
    }
    case 3:
    {
        char search_name[20];
        cout << "enter person name whose number do you want to search :: " << endl;
        cin >> search_name;
        tel.searchnum(search_name);
        cout << "\n\ndo you want continue :: \n\n " << endl;
        char b;
        cin >> b;
        if (b == 'y' || b == 'Y')
        {
            goto label;
        }
        break;
    }
    case 4:
    {
        tel.display_all_num();
        cout << "\n\ndo you want continue :: \n\n " << endl;
        char b;
        cin >> b;
        if (b == 'y' || b == 'Y')
        {
            goto label;
        }
        break;
    }
    }
}
