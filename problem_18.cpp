#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,m,i;
    int max = 0;
    int alram = 0;
    cin >> n >> m;
    for(i=0;i<n;i++){
        int k;
        cin >> k;
        if(k>m)alram++;
        else alram=0;
        if(max<alram) max = alram;
    }
    if(max==0) cout << -1;
    else{
        cout << max;
    }

    
    return 0;
}