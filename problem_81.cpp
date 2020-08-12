#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n,m;
	cin >> n >> m;

	vector<vector<int> > graph(n+1,vector<int>(n+1,0));
	vector<int> dist(n+1,2147000000);
	
	queue<int> q;
	for(int k=0;k<m;k++){
		int i,j,weight;
		cin >> i >> j >> weight;
		graph[i][j] = weight;
	}

	int from,to;
	cin >> from >> to;

	dist[from] = 0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int weight = graph[i][j];
			if(dist[i]!=2147000000 && weight !=0 && dist[j] > dist[i] + weight){
				dist[j] = dist[i] + weight; 
			}
		}
	}


	bool nega_cycle = false;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int weight = graph[i][j];
			if(dist[i]!=2147000000 && weight !=0 && dist[j] > dist[i] + weight){
				nega_cycle = true;
				break;
			}
	
		if(nega_cycle) break;	}
	}

	if(nega_cycle){
		cout << "-1";
	}else{
		cout << dist[to];
	}


	return 0;
}
