#include <bits/stdc++.h>
using namespace std;

int main(void){
    int i;
    string input;
    int number = 0;
    getline(cin,input);
    for(i=0;i<input.length();i++){
        if(isdigit(input[i])){
            number = number*10 + (input[i]-'0');
        }
    }
    int answer = 0;
    for(i=1;i<=number;i++){
        if(number%i==0) answer++;
    }
    
    cout << number << endl << answer;
    return 0;
}