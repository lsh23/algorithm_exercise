#include <bits/stdc++.h>
using namespace std;

int reverse(int x){
    int reverse_int = 0;
    while(x>0){
        reverse_int *= 10;
        reverse_int += x%10;
        x /= 10;
    }
    return reverse_int;
}

bool isPrime(int x){
    int i;
    if(x==1) return false;
    if(x==2) return true;
    for(i=2;i<x;i++){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}

int main(void){
    int n,i;
    cin >> n;
    for(i=0;i<n;i++){
        int k;
        cin >> k;
        int reverse_int = reverse(k);
        if(isPrime(reverse_int)){
            cout << reverse_int << " ";
        }
    }
    return 0;
}