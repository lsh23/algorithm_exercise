#include <string>
#include <queue>
#include <vector>
#include <iostream>

//https://programmers.co.kr/learn/courses/30/lessons/42861

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<vector<pair<int,int>>> graph (n);
    for(auto cost : costs){
        int from = cost[0];
        int to = cost[1];
        int weight = cost[2];
        graph[from].push_back(make_pair(to,weight));
        graph[to].push_back(make_pair(from,weight));
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p_q;
    vector<int> visited(n,0);
    p_q.push(make_pair(0,1));
    while(!p_q.empty()){
        int cost = p_q.top().first;
        int v = p_q.top().second;
        p_q.pop();
        if(visited[v]==1) continue;
        answer += cost;
        visited[v] = 1;
        for(int i=0;i<graph[v].size();i++){
            int to = graph[v][i].first;
            int weight = graph[v][i].second;
            if(visited[to]==0){
                p_q.push(make_pair(weight,to));
            }
        }
    }       
    return answer;
}