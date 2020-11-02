#include <string>
#include <vector>
#include <algorithm>

//https://programmers.co.kr/learn/courses/30/lessons/43105

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    vector<vector<int>> DP(n,vector<int>(n,0));
    
    // DP(0,0) = 7
    // DP(1,0) = DP(0,0) + triangle(1,0)
    // DP(1,1) = DP(0,0) + triangle(1,1)
    // DP(2,0) = DP(1,0) + triangle(2,0)
    // DP(2,1) = MAX (DP(1,0) + triangle(2,1) , DP(1,1) + triangle(2,1))
    // DP(2,2) = DP(1,1) + triangle(2,2)
    
    DP[0][0] = triangle[0][0];
    for(int i=0;i<n-1;i++){
        for(int j=0;j<=i;j++){
            DP[i+1][j] = (DP[i][j] + triangle[i+1][j]) > (DP[i+1][j]) ? DP[i][j] + triangle[i+1][j] : DP[i+1][j];
            DP[i+1][j+1] = (DP[i][j] + triangle[i+1][j+1]) > (DP[i+1][j+1]) ? DP[i][j] + triangle[i+1][j+1] : DP[i+1][j+1];
        }
    }
    for(int i=0;i<n;i++){
        answer = answer > DP[n-1][i] ? answer : DP[n-1][i];
    }
    
    return answer;
}