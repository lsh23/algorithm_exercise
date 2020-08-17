#include<bits/stdc++.h>
using namespace std;


void DFS(int L,int n,int r,vector<int> &visited,vector<int> &_answer){
	if(L==r){
		for(int i : _answer){
			cout << i << " ";
		}
		cout << "\n";
	}else{
		for(int i=0;i<n;i++){
			if(visited[i]==0){
				visited[i]=1;
				_answer[L] = i;
				DFS(L+1,n,r,visited,_answer);
				visited[i]=0;
			}
		}
	}
}



int main(void){

	int n,r;

	cin >> n >> r;

	vector<int> visited(n,0);
	vector<int> answer(r,0);
	DFS(0,n,r,visited,answer);

	return 0;
}