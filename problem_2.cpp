#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,i;
    cin >> a >> b;
    string answer = to_string(a);
    int ans = a;
    for(i=a+1;i<=b;i++){
        answer += " + "+to_string(i);
        ans +=i;
    }
    cout << answer + " = "+to_string(ans);
    return 0;
}