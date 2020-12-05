#include<iostream>
#include<vector>

using namespace std;

int main(void){

    int n;
    cin >> n;

    vector<vector<int>> costs(n,vector<int>(3,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> costs[i][j];
        }
    }

    for(int i=1;i<n;i++){  
        costs[i][0] += (min(costs[i-1][1],costs[i-1][2]));
        costs[i][1] += (min(costs[i-1][0],costs[i-1][2]));
        costs[i][2] += (min(costs[i-1][0],costs[i-1][1]));
    }

    cout << min(min(costs[n-1][0],costs[n-1][1]),costs[n-1][2]);

    return 0;
}