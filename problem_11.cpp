#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,i;
    cin >> n;
    int answer = 0;
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