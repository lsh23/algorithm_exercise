#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,i;
    cin >> n;
    int max = 0;
    int min = INT32_MAX;
    for(i=0;i<n;i++){
        int input;
        cin >> input;
        if(max<input) max=input;
        if(min>input) min=input;
    }
    cout << max-min;
    return 0;
}