#include<bits/stdc++.h>
using namespace std;

int _cnt = 0;

void BFS(vector<int> &v, vector<int> &visited, int cnt, int r,vector<int> &visit){
	if(cnt == r){
		for(int i=0;i<visit.size();i++){
			cout << visit[i] << " ";
		}
		_cnt++;
		cout << "\n";
		return;
	}else{
		for(int i=0;i<v.size();i++){
			if(visited[v[i]]==0){
				visited[v[i]]=1;
				visit.push_back(v[i]);
				BFS(v,visited,cnt+1,r,visit);
				visited[v[i]]=0;
				visit.pop_back();
			}
		}
	}
}


int main(){
	int n,r;
	cin >> n >> r;
	vector<int> v(n,0);
	vector<int> visited(16,0);
	vector<int> visit;
	for(int i=0;i<n;i++){
		cin >> v[i];	
	}

	BFS(v,visited,0,r,visit);

	cout << _cnt;

	return 0;
}