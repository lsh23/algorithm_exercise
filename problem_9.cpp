#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,i,j;
    cin >> n;
    int arr[n+1] = {0};
    for(i=1;i<=n;i++){
        j=1;
        for(;i*j<=n;j++)
            arr[i*j]++;
    }
    for(i=1;i<=n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}