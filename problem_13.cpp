#include <bits/stdc++.h>
using namespace std;

int main(void){
    int i;
    string input;
    getline(cin,input);
    int cnt[input.length()+1] ={0};
    for(i=0;i<input.length();i++){
        cnt[input[i]-'0']++;
    }
    int max = 0;
    int max_index = 0;
    for(i=1;i<=input.length();i++){
        if(max<=cnt[i]){
            max = cnt[i];
            max_index = i;
        }
    }
    cout << max_index;
    return 0;
}