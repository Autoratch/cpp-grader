// Dev: Autoratch
#include <bits/stdc++.h>
using namespace std;
     
/*  Normal    Demo
    code      code.cpp  :  your solution code  
    testin    demo.in   :  input of testcase
    testout   demo.out  :  output of testcase
    yourout   demo.sol  :  your output
    sol                 :  correct output
    your                :  your output
*/

string code,testin,testout,yourout;
fstream sol,your;
bool wrong;

void print(string s)
{
    char c[s.length()+1];
    for(int i = 0;i < s.length();i++) c[i] = s[i];
    c[s.length()] = '\0';
    system(c);
}

int main()
{
    cout << "Your solution code filename: ";
    cin >> code;
    cout << "Testcase Input filename: ";
    cin >> testin;
    cout << "Testcase Output filename: ";
    cin >> testout;
    cout << "Filename you want to store your output: ";
    cin >> yourout;

    print("g++ "+code); // compile source code using g++
    print("./a.out < "+testin+" > "+yourout); // run source code and store output in yourout

    sol.open(testout,ios::in); // open testcase output file
    your.open(yourout,ios::in); // open your output file
       
    while(true)
    {
        char a = sol.get(),b = your.get();
        while(a=='\n' or a==' ') a = sol.get();
        while(b=='\n' or b==' ') b = your.get();
        if(a!=b){ wrong = true; break; }
        if(sol.eof() or your.eof()) break;
    }

    sol.close(),your.close();

    if(!wrong) cout << "Correct!";
    else cout << "Incorrect!";
}

