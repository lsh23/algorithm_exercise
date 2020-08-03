#include <bits/stdc++.h>
using namespace std;

int answer = 0;

void DFS(vector<vector<int>>& adjacent, int from, int end, vector<int>& visited){
	if(from==end){
		answer++;
		return;
	}
	else{
		int i;
		vector<int> v (visited.size(),0);
		for(i=0;i<visited.size();i++){
			v[i] = visited[i];
		}
		v[from]=1;
		for(i=1;i<=end;i++){
			if(i != from && v[i] == 0 && adjacent[from][i]){
				DFS(adjacent,i,end,v);
			}
		}
	}
}


int main(void){

	int n,m;

	cin >> n >> m;

	vector<vector<int>> adjacent(n, vector<int>(n+1,0));
	vector<int> visited (n+1,0);
	for(int k=0; k<m; k++){
		int i,j;
		cin >> i >> j;
		adjacent[i][j] = 1;
	}
	DFS(adjacent,1,n,visited);
	/*
	
	*/

	cout << answer;

	return 0;
}
