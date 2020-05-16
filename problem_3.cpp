#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,i;
    cin >> n;
    int sum = 1;
    string answer = "1";
    for(i=2;i<n;i++){
        if(n%i==0){
            answer += " + " + to_string(i);
            sum += i;
        }
    }
    cout << answer << " = " << sum;
    return 0;
}