#include <string>
#include <vector>
#include <iostream>
using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42898

int solution(int m, int n, vector<vector<int>> puddles) {
   
    int answer = 0;
    
    vector<vector<int>> DP(n+1,vector<int>(m+1,0));

    for(auto puddle : puddles){
        DP[puddle[1]][puddle[0]] = -1;
    }
    
    DP[1][1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1 && j==1) continue;
            if(DP[i][j]== -1){
                DP[i][j] = 0;
                continue;
            }
            if(i==1) DP[i][j] = DP[i][j-1];
            else if(j==1) DP[i][j] = DP[i-1][j];
            else{
                DP[i][j] = (DP[i-1][j] + DP[i][j-1]) % 1000000007; 
            }
        }
    }
    
    answer = DP[n][m];
    
    return answer;
}