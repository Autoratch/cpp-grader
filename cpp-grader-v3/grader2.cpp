// Dev: Autoratch
#include <bits/stdc++.h>
using namespace std;

// this is version 3 for generating testcase to check with the correct solution
// with addition feature to configure your own files name

string code,correct,testin,testout,yourout,testgen;
int number;
fstream sol,your,conf;

void print(string s)
{
    char c[s.length()+1];
    for(int i = 0;i < s.length();i++) c[i] = s[i];
    c[s.length()] = '\0';
    system(c);
}

int main()
{
    conf.open("config.txt",ios::in);
    getline(conf,code);
    getline(conf,correct);
    getline(conf,testgen);
    getline(conf,testin);
    getline(conf,testout);
    getline(conf,yourout);

    cout << "Welcome to CPP-Grader V.3\nYou can config the file names of your code and your files in config.txt\n";

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
        else{ cout << "Test  " << i << ":  Correct\n"; }
    }

    cout << "Your code gives correct output for all "  << number << " testcases.";
}
