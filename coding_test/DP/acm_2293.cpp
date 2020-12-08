#include<iostream>
#include<vector>

using namespace std;

int main(void){

    int n,k;
    cin >> n >> k;

    vector<int> coins(n,0);
    for(int i=0;i<n;i++){
        cin >> coins[i];
    }

    vector<int> DP(k+1,0);
    
    DP[0] = 1;

    for(int i=0;i<n;i++){
        for(int j=coins[i];j<=k;j++){
            DP[j] = DP[j] + DP[j-coins[i]];
        }
    }

    cout << DP[k];

    return 0;
}