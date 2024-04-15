#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

// FILE HANDLING
ofstream fout, fout1;
ifstream fin, fin1;
char name[50];
int age, pass;

// VOTE COUNT
int vote1 = 0, vote2 = 0, vote3 = 0, vote4 = 0, vote5 = 0;

class welcome
{
public:
    void portal()
    {
        cout << "WELCOME TO THE E-VOTING PORTAL\n";
    }
};

class uregister
{
public:
    void regi(char *name, int age, int pass)
    {
        fout.open("a.txt", ios::app);
        fout << "\n" << name << "\t" << age << "\t" << pass;
        cout << "Registered Successfully";
        fout.close();
    }
};

class valid
{
public:
    bool agechk(int age)
    {
        return (age >= 18);
    }

    bool namechk(char *name, char *lname)
    {
        return (strcmp(name, lname) != 0);
    }

    bool passchk(int pass, int pswd)
    {
        return (pass != pswd);
    }
};

class result
{
public:
    void view(int vi)
    {
        cout << "\n\nVOTING RESULT VIEW PAGE" << endl;
        cout << "VIEW VOTES OF" << endl;
        switch (vi)
        {
        case 1:
            cout << "\n\ncandidate 1: Number of votes: " << vote1;
            break;
        case 2:
            cout << "\n\ncandidate 2: Number of votes: " << vote2;
            break;
        case 3:
            cout << "\n\ncandidate 3: Number of votes: " << vote3;
            break;
        case 4:
            cout << "\n\ncandidate 4: Number of votes: " << vote4;
            break;
        case 5:
            cout << "\n\ncandidate 5: Number of votes: " << vote5;
            break;
        default:
            cout << "\n\nNo such option" << endl;
            break;
        }
    }

    void winner()
    {
        if (vote1 < vote2)
        {
            cout << "\n\nWINNER OF THE ELECTION IS candidate 2";
            if (vote2 < vote3)
            {
                cout << "\n\nWINNER OF THE ELECTION IS candidate 3";
                if (vote3 < vote4)
                {
                    cout << "\n\nWINNER OF THE ELECTION IS candidate 4";
                    if (vote4 < vote5)
                    {
                        cout << "\n\nWINNER OF THE ELECTION IS candidate 5";
                    }
                }
            }
        }
        else
        {
            cout << "\n\nWINNER OF THE ELECTION IS candidate 1";
        }
    }

    void tvotes()
    {
        int totalv;
        totalv = vote1 + vote2 + vote3 + vote4 + vote5;
        cout << "\n\nTotal number of votes casted were: " << totalv << endl;
    }
};

class rep
{
public:
    void voting(int vt)
    {
        cout << "\n\nWELCOME TO THE VOTING PAGE" << endl;
        cout << "REPRESENTATIVE NAMES" << endl;
        switch (vt)
        {
        case 1:
            cout << "\n\nAre you sure you want to vote candidate 1?";
            break;
        case 2:
            cout << "\n\nAre you sure you want to vote candidate 2?";
            break;
        case 3:
            cout << "\n\nAre you sure you want to vote candidate 3?";
            break;
        case 4:
            cout << "\n\nAre you sure you want to vote candidate 4?";
            break;
        case 5:
            cout << "\n\nAre you sure you want to vote candidate 5?";
            break;
        default:
            cout << "No such option" << endl;
            break;
        }

        cout << "\n1. YES";
        cout << "\n2. NO" << endl;

        int ch;
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nVoted Successfully" << endl;
            switch (vt)
            {
            case 1:
                vote1++;
                break;
            case 2:
                vote2++;
                break;
            case 3:
                vote3++;
                break;
            case 4:
                vote4++;
                break;
            case 5:
                vote5++;
                break;
            }
            break;
        case 2:
            cout << "\nNo vote casted" << endl;
            break;
        default:
            cout << "\nInvalid option" << endl;
            break;
        }
    }
};

int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        cout << "Usage: " << argv[0] << " <name> <age> <password> <login_name>" << endl;
        return 1;
    }

    welcome w;
    w.portal();

    uregister ur;
    ur.regi(argv[1], atoi(argv[2]), atoi(argv[3]));

    valid v;
    if (!v.agechk(atoi(argv[2])))
    {
        cout << "\nNot Eligible due to age" << endl;
        return 1;
    }

    if (!v.namechk(argv[1], argv[4]))
    {
        cout << "\nNot Eligible due to name" << endl;
        return 1;
    }

    if (!v.passchk(atoi(argv[3]), atoi(argv[5])))
    {
        cout << "\nNot Eligible due to password" << endl;
        return 1;
    }

    result r;
    rep rp;

    cout << "\n\nWELCOME TO THE VOTING PAGE" << endl;
    cout << "REPRESENTATIVE NAMES" << endl;
    cout << "\n1. candidate 1";
    cout << "\n2. candidate 2";
    cout << "\n3. candidate 3";
    cout << "\n4. candidate 4";
    cout << "\n5. candidate 5" << endl;

    int vt;
    cout << "\n\nEnter the number of the representative you want to vote for: ";
    cin >> vt;

    rp.voting(vt);

    r.view(vt);
    r.winner();
    r.tvotes();

    return 0;
}
