#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){

    int n;
    cin >> n;
    vector<int> DP(n+1,0);

    for(int i=0;i<=n;i++){
        DP[i] = i;
        for(int j=1;j*j<=i;j++){
            DP[i] = min(DP[i],DP[i-j*j]+1);
        }
    }

    cout << DP[n];

    return 0;
}