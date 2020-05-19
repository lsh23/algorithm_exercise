#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,i;
    cin >> n;
    long long answer = 0;
    // for(i=1;i<=n;i++){
    //     if(i<10) answer +=1;
    //     else if(i<100) answer +=2;
    //     else if(i<1000) answer +=3;
    //     else if(i<10000) answer +=4;
    //     else if(i<100000) answer +=5;
    //     else if(i<1000000) answer +=6;
    //     else if(i<10000000) answer +=7;
    //     else if(i<100000000) answer +=8;
    //     else answer +=9;
    // }
        for(i=1;i<=n;i++){
        int tmp = i;
        while(tmp>0){
            tmp = tmp/10;
            answer++;
        }
    }
    cout << answer;
    return 0;
}