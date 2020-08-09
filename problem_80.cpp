#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n,m;
	cin >> n >> m;
	vector<vector<int> > graph(n+1,vector<int>(n+1,0));
	vector<int> dist(n+1,2147000000);
	dist[0] = 0;
	priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > p_q;
	for(int k=0;k<m;k++){
		int i,j,weight;
		cin >> i >> j >> weight;
		graph[i][j] = weight;
	}

	p_q.push( make_pair(0,make_pair(1,0)) );

	while(!p_q.empty()){
		pair<int,pair<int,int> > top = p_q.top();
		p_q.pop();
		int weight = top.first;
		int vertex = top.second.first;
		int prev = top.second.second;
		if (dist[vertex] > dist[prev] + weight){
			dist[vertex] = dist[prev] + weight;
			
			for(int i=1;i<=n;i++){
				if(graph[vertex][i]>0){
					p_q.push(make_pair(graph[vertex][i],make_pair(i,vertex)));
				}
			}
		}

	}

	for(int i=2;i<=n;i++){
		if(dist[i]!= 2147000000) cout << i << " : " << dist[i] << "\n";
		else cout << i << " : " << "impossible" << "\n";
	}

	// 시작 점 넣고 우선순위큐에 넣어서
	// 큐에 아무것도 없을 때 까지
	// weight 가장 작은 거 뽑고 
	// dist[vertex] 업데이트

	return 0;
}
