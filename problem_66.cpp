#include <bits/stdc++.h>
using namespace std;

int answer = 0;



void DFS(int from, int end,vector<vector<int>>& v, vector<int>& visited){

	if(from == end){
		answer++;
		return;
	}
	else{
		for(int i=1;i<=end;i++){
			if(visited[i]!=1 && v[from][i]==1){
				visited[i]=1;
				DFS(i,end,v,visited);
				visited[i]=0;
			}
		}

	}
} 

int main(void){


	int n,m;

	cin >> n >> m;

	vector<vector<int>> v(n+1, vector<int>(n+1,0));
	vector<int> visited(n+1,0);


	for(int k=0; k<m; k++){
		int i,j;
		cin >> i >> j;
		v[i][j]=1;
	}

	visited[1] = 1;
	DFS(1,n,v,visited);

	cout << answer;

	return 0;
}
