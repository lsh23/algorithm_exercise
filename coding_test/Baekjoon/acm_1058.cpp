#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


int main(void){

    int n;
    cin >> n;
    vector<vector<int>> graph(n,vector<int>(n,0));
    int answer = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char input;
            cin >> input;
            if(input=='N') graph[i][j] = INT32_MAX;
            else graph[i][j] = 1;
            if(i==j) graph[i][j] = 0;
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][k] != INT32_MAX && graph[k][j] != INT32_MAX) graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(i==j)continue;
            if(graph[i][j]<=2)cnt++;
        }
        answer = answer > cnt ? answer : cnt;
    }

    cout << answer;
    return 0;
}