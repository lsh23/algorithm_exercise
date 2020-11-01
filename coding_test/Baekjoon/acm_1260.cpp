#include <bits/stdc++.h>

using namespace std;

void DFS(vector<vector<int>> &graph,vector<int> &visited,int n,int v){
    for(int i=1;i<=n;i++){
        if(graph[v][i] == 1 && visited[i] == 0){
            visited[i] = 1;
            cout << i << " ";
            DFS(graph,visited,n,i);
        }
    }
}

int main(void){

    int n,m,v;

    cin >> n >> m >> v;

    vector<vector<int>> graph(n+1,vector<int>(n+1,0));
    
    for(int k=0;k<m;k++){
        int i,j;
        cin >> i >> j;
        graph[i][j] = 1;
        graph[j][i] = 1;
    }

    vector<int> visited(n+1,0);
    visited[v] = 1;
    cout << v << " ";
    DFS(graph,visited,n,v);

    cout << "\n";

    queue<int> q;
    q.push(v);
    visited = vector<int>(n+1,0);
    visited[v] = 1;
    while(!q.empty()){
        int front = q.front();
        cout << front << " ";
        q.pop();
        for(int i=1;i<=n;i++){
            if(graph[front][i] == 1 && visited[i]==0){
                visited[i] = 1;
                q.push(i);
            }
        }
    }

   
    return 0;
}