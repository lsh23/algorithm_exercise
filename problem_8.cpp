#include <bits/stdc++.h>
using namespace std;

int main(void){
    string input;
    getline(cin,input);
    int i;
    int answer = 0;
    for(i=0;i<input.length();i++){
        if(input[i]=='(') answer++;
        else{
            answer--;
            if(answer < 0) break;
        }
    }
    if(answer==0) cout << "YES";
    else cout << "NO";
    return 0;
}