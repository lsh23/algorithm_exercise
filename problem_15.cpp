#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,i,j,k;
    cin >> n;
    int cnt[n+1];
    for(i=1;i<=n;i++){
        cnt[i] = 1;
    }
    int ans = 0;
    for(i=2;i<=n;i++){
        //소수판정
        bool isPrime = true;
        for(j=2;j<i;j++){
            if( cnt[i]>1 || i%j==0) {
                isPrime = false;
                break;
            }
            if(i>3 && cnt[i]==1){
                break;
            }
        }
        //자기의 배수 다 증가
        if(isPrime){
            ans++;
            for(k=1;i*k<=n;k++) cnt[i*k]++;
        }
    }
    cout << ans;
    return 0;
}