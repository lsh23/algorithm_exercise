#include<bits/stdc++.h>

using namespace std;

int main(void){

    int v,e;

    cin >> v >> e;

    vector<vector<pair<int,int>>> graph(v+1);
    for(int i=0; i<e;i++){
        int x,y,weight;
        cin >> x >> y >> weight;
        graph[x].push_back(make_pair(y,weight));
        graph[y].push_back(make_pair(x,weight));
    }


    long long answer = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > p_q;
    vector<int> visited(v+1,0);
    p_q.push(make_pair(0,1));

    while(!p_q.empty()){
        pair<int,int> top = p_q.top();
        p_q.pop();
        int vertex = top.second;
        int d = top.first;
        if(visited[vertex]==0){
            visited[vertex]=1;
            answer+=d;
            for(int i=0;i<graph[vertex].size();i++){
                if(visited[graph[vertex][i].second==0]) p_q.push(make_pair(graph[vertex][i].second,graph[vertex][i].first));
            }
        }
    }
    
    cout << answer;

    return 0;
}