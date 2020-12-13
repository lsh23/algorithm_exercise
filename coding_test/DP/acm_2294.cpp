#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int main(void){

    int n,k;
    cin >> n >> k;

    vector<int> bags(k+1,INT32_MAX);
    bags[0] = 0;
    for(int i=0;i<n;i++){
        int coin;
        cin >> coin;

        for(int j=coin;j<=k;j++){
            if(bags[j-coin]==INT32_MAX) continue;
            bags[j] = min(bags[j],(bags[j-coin] + 1)); 
        }
    }

    if(bags[k]==INT32_MAX) cout << -1;
    else cout << bags[k];

    return 0;
}