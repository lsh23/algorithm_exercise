#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,m,i;
    cin >> n >> m;
    int answer = 0;
    for(i=1;i<=n;i++){
        if(i%m==0){
            answer +=i;
        }
    }
    cout << answer;
    return 0;
}