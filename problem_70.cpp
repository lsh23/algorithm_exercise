#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n,m;

	cin >> n >> m;

	vector<vector<int>> adjacent(n+1,vector<int> (n+1,0));
	vector<int> visited (n+1,0);
	for(int k=0;k<m;k++){
		int i,j;
		cin >> i >> j;
		adjacent[i][j] = 1;
	}

	int count = 1;
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while(!q.empty()){
		int front = q.front();
		q.pop();
		for(int i=1; i<=n; i++){
			if(adjacent[front][i] && visited[i]==0){
				visited[i]=visited[front]+1;
				q.push(i);
			}
		}
	}

	for(int i=2; i<=n;i++){
		cout << i << " : " << visited[i]-1 << "\n";
	}

	return 0;
}
