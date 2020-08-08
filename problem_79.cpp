#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int e;
	int val;
	Edge(int a, int b){
		e = a;
		val = b;
	}
	bool operator< (const Edge &e)const{
		return val > e.val;
	}
};


int main(void){

	int v,e;

	cin >> v >> e;

	vector<vector<int> > loads(v+1,vector<int>(v+1,0));
	priority_queue<Edge> p_q;
	vector<int> visited(v+1,0);

	for(int i=0;i<e;i++){
		int a,b,c;
		cin >> a >> b >> c;
		loads[a][b]=c;
		loads[b][a]=c;
	}

	int cost = 0;
	p_q.push(Edge(1,0));
	
	while(!p_q.empty()){
		Edge edge = p_q.top();
		p_q.pop();
		int vertex = edge.e;
		int val = edge.val;
		if(visited[vertex]==0){
			visited[vertex]=1;
			cost += val;
			for(int i=1;i<=v;i++){
				if(loads[vertex][i]>0){
					p_q.push(Edge(i,loads[vertex][i]));
				}
			}
		}
	}

	cout << cost;

	return 0;
}
