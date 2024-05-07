// F24.

/*
Aim : Company maintains employee information as employee ID, name, designation and salary.
Allow user to add, delete  information of employee.
Display information of particular employee.
If employee does not exist an appropriate message is displayed.
If it is, then the system displays the employee details.
Use index sequential file to maintain the data.
*/

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class Record
{
    int id;
    string name;
    int salary;
    string designation;

public:
    Record();
    int getIdno();
    void getData();
    void putData();
};

Record::Record()
{
    id = 0;
    name = "";
    designation = "";
    salary = 0;
}

int Record::getIdno()
{
    return id;
}

void Record::getData()
{
    cout << "\nEnter Details: ";
    cout << "\nId no: ";
    cin >> id;
    cout << "Name: ";
    cin >> name;
    cout << "Salary: ";
    cin >> salary;
    cout << "Designation: ";
    cin >> designation;
}

void Record::putData()
{
    cout << "\nId No.: " << id;
    cout << "\tName: " << name;
    cout << "\nSalary: " << salary;
    cout << "\tDesignation: " << designation;
}

class File
{
    fstream dataFile;
    map<int, long> index; // Key: ID, Value: File offset

public:
    File();
    void insert();
    void display();
    void search(int);
    int Delete(int);
    int edit(int);
};

File::File()
{
    dataFile.open("EmployeeDB", ios::in | ios::out | ios::binary | ios::app);
    if (!dataFile)
    {
        cerr << "Error: Unable to open data file.";
        exit(1);
    }

    // Build index
    dataFile.seekg(0, ios::end);
    streampos fileSize = dataFile.tellg();
    if (fileSize != 0)
    {
        dataFile.seekg(0, ios::beg);
        while (!dataFile.eof())
        {
            long pos = dataFile.tellg();
            Record r;
            dataFile.read((char *)&r, sizeof(r));
            if (dataFile.eof())
                break;
            index[r.getIdno()] = pos;
        }
    }
}

void File::insert()
{
    Record r;
    r.getData();
    dataFile.write((char *)&r, sizeof(r));
    index[r.getIdno()] = dataFile.tellp() - sizeof(r); // Update index
}

void File::display()
{
    dataFile.clear();
    dataFile.seekg(0, ios::beg);
    while (!dataFile.eof())
    {
        Record r;
        dataFile.read((char *)&r, sizeof(r));
        if (dataFile.eof())
            break;
        r.putData();
    }
}

void File::search(int id)
{
    if (index.find(id) != index.end())
    {
        dataFile.clear();
        dataFile.seekg(index[id], ios::beg);
        Record r;
        dataFile.read((char *)&r, sizeof(r));
        r.putData();
    }
    else
    {
        cout << "\nRecord not Found";
    }
}

int File::Delete(int id)
{
    if (index.find(id) != index.end())
    {
        dataFile.clear();
        dataFile.seekg(index[id], ios::beg);
        Record r;
        dataFile.read((char *)&r, sizeof(r));
        index.erase(id);
        return 1;
    }
    else
    {
        cout << "\nRecord not Found";
        return 0;
    }
}

int File::edit(int id)
{
    if (index.find(id) != index.end())
    {
        dataFile.clear();
        dataFile.seekg(index[id], ios::beg);
        Record r;
        dataFile.read((char *)&r, sizeof(r));
        r.getData();
        dataFile.seekp(index[id], ios::beg);
        dataFile.write((char *)&r, sizeof(r));
        return 1;
    }
    else
    {
        cout << "\nRecord not Found";
        return 0;
    }
}

int main()
{
    File f;
    int ch, n, i, flag = 0;
    do
    {
        cout << "\n\n\t-----M E N U-----";
        cout << "\n\n1. Build A Master Table";
        cout << "\n2. List A Table";
        cout << "\n3. Insert a New Entry";
        cout << "\n4. Delete Old Entry";
        cout << "\n5. Edit an Entry";
        cout << "\n6. Search for a Record";
        cout << "\n7. Quit";
        cout << "\nEnter your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            if (flag == 0)
            {
                cout << "\nEnter No of Records to insert : ";
                cin >> n;
                for (i = 0; i < n; i++)
                {
                    f.insert();
                }
                flag = 1;
            }
            else
            {
                cout << "\nSorry.. Table is Already build... \n If want to add record please select Insert a New Entry in option.....";
            }
            break;
        case 2:
            f.display();
            break;
        case 3:
            f.insert();
            break;
        case 4:
            cout << "\nEnter Id No of Employee Whose Record is to be Deleted: ";
            cin >> n;
            i = f.Delete(n);
            if (i == 1)
                cout << "\nRecord Deleted Successfully";
            break;
        case 5:
            cout << "\nEnter Id No of Employee Whose Record is to be Edit: ";
            cin >> n;
            i = f.edit(n);
            if (i == 1)
                cout << "\nRecord Modified Successfully";
            break;
        case 6:
            cout << "\nEnter Id No of Employee Whose Record is to be Searched: ";
            cin >> n;
            f.search(n);
            break;
        case 7:
            break;
        default:
            cout << "\nEnter Valid Choice.....";
        }
    } while (ch != 7);
    return (0);
}
