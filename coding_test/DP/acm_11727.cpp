#include<iostream>
#include<vector>

using namespace std;

int main(void){

    int n;
    cin >> n;

    vector<int> DP(n+1,0);

    DP[1] = 1;
    DP[2] = 3;

    for(int i=3;i<=n;i++){
        DP[i] = (DP[i-1] + 2 * DP[i-2])%10007;
    }

    cout << DP[n];

    return 0;
}