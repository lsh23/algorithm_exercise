#include<vector>
#include<iostream>
#include<queue>
using namespace std;

int main(void){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> graph (n+1,vector<int>(n+1,0));
    vector<int> topology (n+1,0);
    queue<int> q;

    for(int i=0;i<m;i++){
        int from,to;
        cin >> from >> to;
        graph[from][to]=1;
        topology[to]++;
    }

    for(int i=1;i<=n;i++){
        if(topology[i]==0) q.push(i);
    }

    while(!q.empty()){
        int out = q.front();
        cout << out << " ";
        q.pop();
        for(int i=1;i<=n;i++){
            if(graph[out][i]==1){
                topology[i]--;
                if(topology[i]==0)q.push(i);
            }
        }
    }

    return 0;
}