#include <bits/stdc++.h>
using namespace std;

int answer = 2147000000;



void DFS(int from, int end,vector<vector<int>>& v, vector<int>& visited,int sum){

	if(from == end){
		answer = answer < sum ? answer : sum;
		return;
	}
	else{
		for(int i=1;i<=end;i++){
			if(visited[i]!=1 && v[from][i]!=0){
				visited[i]=1;
				DFS(i,end,v,visited,sum+v[from][i]);
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
		int i,j,weight;
		cin >> i >> j >> weight;
		v[i][j]=weight;
	}

	visited[1] = 1;
	DFS(1,n,v,visited,0);

	cout << answer;

	return 0;
}
