#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,i;
    cin >> n;
    int answer = 0;
    for(i=1;i<=n;i++){
        if(i<10) answer +=1;
        else if(i<100) answer +=2;
        else if(i<1000) answer +=3;
        else if(i<10000) answer +=4;
        else if(i<100000) answer +=5;
    }
    cout << answer;
    return 0;
}