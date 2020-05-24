#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,i;
    cin >> n;
    int a[n]={0};
    int b[n]={0};
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    for(i=0;i<n;i++){
        cin >> b[i];
    }
    for(i=0;i<n;i++){
        if(a[i]==b[i]) cout << "D" << "\n";
        if(abs(a[i]-b[i])==1){
            if(a[i]>b[i]) cout << "A" << "\n";
            else cout << "B" << "\n";
        }
        if(abs(a[i]-b[i])==2){
            if(a[i]>b[i]) cout << "B" << "\n";
            else cout << "A" << "\n";
        }
    }
    return 0;
}