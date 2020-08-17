#include<bits/stdc++.h>
using namespace std;


void DFS(int s, int L,int n,int r,vector<int> &visited){
	if(L==r){
		for(int i : visited){
			cout << i << " ";
		}
		cout << "\n";
	}else{
		for(int i=s;i<n;i++){
			visited[L] = i;
			DFS(s+1,L+1,n,r,visited);
		}
	}
}



int main(void){

	int n,r;

	cin >> n >> r;

	vector<int> visited(r,0);

	DFS(0,0,n,r,visited);

	return 0;
}