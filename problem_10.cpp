#include <bits/stdc++.h>
using namespace std;


int digit_sum(int x){
    int sum = 0;
    while(x>0){
        sum += x%10;
        x /= 10; 
    }
    return sum;
}

int main(void){
    int n,i;
    int ans=0;
    int max=0;
    int sum=0;
    cin >> n;
    for(i=0;i<n;i++){
        int input;
        cin >> input;
        sum = digit_sum(input);
        if(max< sum){
            max = sum; 
            ans = input;
        }
        if(max==sum){
            if(ans<input) ans = input;
        }
    }
    cout << ans;
    return 0;
}