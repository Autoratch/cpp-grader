// Dev: Autoratch
#include <bits/stdc++.h>
using namespace std;

void print(string s)
{
    char c[s.length()+1];
    for(int i = 0;i < s.length();i++) c[i] = s[i];
    c[s.length()] = '\0';
    system(c);
}

int main()
{
    cout << "Welcome to CPP-Grader Testcase Generator\n";
    cout << "Testcase will be in form of x.in and x.sol\n";
    cout << "Testcase random generator code will be testgen.cpp\n";
    string solname;
    int st,en;
    cout << "Solname: ";
    cin >> solname;
    cout << "Id of test: \n   From: ";
    cin >> st;
    cout << "   To: ";
    cin >> en;
    print("g++ "+solname+" -o code");
    for(int i = st;i <= en;i++)
    {
        string s = "";
        int tmp = i;
        while(tmp) s = (char)(tmp%10+'0')+s,tmp/=10;
        print("g++ testgen.cpp -o testgen && ./testgen > "+s+".in");
        print("./code < "+s+".in > "+s+".sol");
    }
}

