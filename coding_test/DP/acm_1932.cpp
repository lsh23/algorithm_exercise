#include<bits/stdc++.h>
using namespace std;

int main(void){

    int n;

    cin >> n;

    vector<vector<int>> triangle(n,vector<int>(n,0));
    vector<vector<int>> DP(n,vector<int>(n,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            cin >> triangle[i-1][j];
        }
    }

    DP[0][0] = triangle[0][0];
    for(int i=1;i<n;i++){
        DP[i][0] = DP[i-1][0]+triangle[i][0];
        DP[i][i] = DP[i-1][i-1]+triangle[i][i];
        for(int j=1;j<i;j++){
            if(DP[i-1][j]+triangle[i][j] > DP[i-1][j-1]+triangle[i][j]){
                DP[i][j] = DP[i-1][j]+triangle[i][j];
            }else{
                DP[i][j] = DP[i-1][j-1]+triangle[i][j];
            }
        }
    }

    int answer = 0;
    for(int i=0;i<n;i++){
        answer = answer > DP[n-1][i] ? answer : DP[n-1][i];
    }

    cout << answer;


    return 0;
}