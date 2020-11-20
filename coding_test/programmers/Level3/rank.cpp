#include <string>
#include <vector>

//https://programmers.co.kr/learn/courses/30/lessons/49191

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> dist(n+1,vector<int>(n+1,0));
    for(int i=0;i<results.size();i++){
        dist[results[i][0]][results[i][1]]=1;
        dist[results[i][1]][results[i][0]]=-1;
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k] ==1 && dist[k][j]==1){
                    dist[i][j]=1;
                    dist[j][i]=-1;
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(int j=1;j<=n;j++){
            if(dist[i][j]!=0)cnt++;
        }
        if(cnt==n-1)answer++;
    }
     
    return answer;
}