// Dev: Autoratch
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Welcome to CPP System Grader\n";
    cout << "Input: x.in, Output: x.sol\n";
    cout << "Solution code name: ";
    char code[100];
    scanf("%s",code);
    cout << "Number of testcase: ";
    int num;
    cin >> num;
    char in[100],out[100];
    system("g++ grader.cpp -o grader");
    for(int i = 1;i <= num;i++)
    {
        string s = "";
        int tm = i;
        while(tm) s = char(tm%10+'0')+s,tm/=10;
        for(int j = 0;j < s.length();j++) in[j] = out[j] = s[j];
        in[s.length()] = '.',in[s.length()+1] = 'i',in[s.length()+2] = 'n',in[s.length()+3] = '\0';
        out[s.length()] = '.',out[s.length()+1] = 's',out[s.length()+2] = 'o',out[s.length()+3] = 'l',out[s.length()+4] = '\0';
        FILE *f = fopen("config.txt","w");
        fprintf(f,"%s\n%s\n%s\nyour.out",code,in,out);
        fclose(f);
        system("./grader");
    }
}

