#include<bits/stdc++.h>
using namespace std;

int answer = INT32_MIN;

void DFS(vector<pair<int,int> > schedules,vector<int> visited, int t, int day ,int n){
	if(day > n){
		int p_sum = 0;
		for(int i=1;i<=n;i++){
			if(visited[i]==1){
				p_sum += schedules[i].second;
			}
		}
		answer = answer > p_sum ? answer : p_sum;
	}
	else{
		if(t==0){
			for(int i=day;i<=n;i++){
				t = schedules[day].first;
				if(visited[i]==0){
					if(day+t <= n+1){
						visited[i]=1;
						DFS(schedules,visited,t-1,day+1,n);
						visited[i]=0;
					}
					else{
						DFS(schedules,visited,t-1,day+1,n);
					}
				}
			}
		}else{
			DFS(schedules,visited,t-1,day+1,n);
		}
	}
}

int main(void) {

	int n,i;

	cin >> n;

	vector<pair<int,int> > schedules(n+1);
	vector<int> visited (n+1,0);
	for(i=1;i<=n;i++){
		int t,p;
		cin >> t >> p;
		schedules[i] = make_pair(t,p);
	}

	// DFS로 모든 경우 해서 최소값.
	// 단 일 진행시 조건들이 있음
	// 걸리는 시간 때문에 무작 정 넣는게 아님.
	for(int i=1;i<=n;i++){
		int t = schedules[i].first;
		if(t <= n+1){
				visited[i]=1;
				DFS(schedules,visited,t,i,n);
				visited[i]=0;
		}
	}
	
	cout << answer;
	

	return 0;
}