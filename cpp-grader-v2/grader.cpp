// Dev: Autoratch
#include <bits/stdc++.h>
using namespace std;

// this is version 2 for generating testcase to check with the correct solution

string code,correct,testin,testout,yourout,testgen;
int number;
fstream sol,your;

void print(string s)
{
    char c[s.length()+1];
    for(int i = 0;i < s.length();i++) c[i] = s[i];
    c[s.length()] = '\0';
    system(c);
}

int main()
{
    cout << "Your code filename: ";
    cin >> code;
    cout << "Correct code filename: ";
    cin >> correct;
    cout << "Testcase generator filename: ";
    cin >> testgen;
    cout << "Testcase Input filename: ";
    cin >> testin;
    cout << "Filename you want to store correct output: ";
    cin >> testout;
    cout << "Filename you want to store your output: ";
    cin >> yourout;

    print("g++ "+code+" -o code"); // compile source code
    print("g++ "+correct+" -o correct"); // compile correct code
    print("g++ "+testgen+" -o testgen"); // compile testcase generator code

    cout << "Number of testcases: ";
    cin >> number;

    for(int i = 1;i <= number;i++)
    {
        print("./testgen > "+testin);
        print("./correct < "+testin+" > "+testout);
        print("./code < "+testin+" > "+yourout);
        sol.open(testout,ios::in); // open testcase output file
        your.open(yourout,ios::in); // open your output file
        bool wrong = false;
        while(true)
        {
            char a = sol.get(),b = your.get();
            while(a=='\n' or a==' ') a = sol.get();
            while(b=='\n' or b==' ') b = your.get();
            if(a!=b){ wrong = true; break; }
            if(sol.eof() or your.eof()) break;
        }
        sol.close(),your.close();
        if(wrong){ cout << "Incorrect testcase found after " << i << " run!\nInput is now stored in " << testin; return 0; }
    }

    cout << "Your code gives correct output for all "  << number << " testcases.";
}

