#include <bits/stdc++.h>
using namespace std;

int main(void){
    int i;
    string input;
    string s_number = "";
    getline(cin,input);
    for(i=0;i<input.length();i++){
        if(isdigit(input[i])){
            s_number += input[i];
        }
    }
    int number = stoi(s_number);
    int answer = 0;
    for(i=1;i<=number;i++){
        if(number%i==0) answer++;
    }
    
    cout << number << endl << answer;
    return 0;
}