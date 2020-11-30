#include<bits/stdc++.h>

using namespace std;


int main(void){

    int n;
    queue<int> q;
    vector<int> visited(n,0);
    vector<vector<int>> graph(n,vector<int>(n,0));
    int root = 0;
    
    cin >> n;

    for(int i=0;i<n;i++){
        int p_i;
        cin >> p_i;
        if(p_i == -1) root = i;
        else{ 
            graph[i][p_i] = 1;
            graph[p_i][i] = 1;
        }
    }

    int deleted;
    cin >> deleted;
    visited[deleted] = 1;

    int cnt = 0;
    if(deleted != root){
        q.push(root);
        visited[root] = 1;

        while(!q.empty()){
            int front = q.front();
            q.pop();
            bool is_leaf = true;
            for(int i=0;i<n;i++){
                if(visited[i]==0 &&graph[front][i]==1){
                    visited[i]=1;
                    q.push(i);
                    is_leaf = false;
                }
            }
            if(is_leaf) cnt++;
        }
    }


    cout << cnt;


    return 0;
}