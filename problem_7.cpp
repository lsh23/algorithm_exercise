#include <bits/stdc++.h>
using namespace std;

int main(void){
    int i;
    string input;
    getline(cin,input);
    for(i=0;i<input.length();i++){
        if(input[i] !=' '){
            cout << (char) tolower(input[i]);
        }
    }
    return 0;
}