#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main(void) {

	int m,n;

	cin >> m >> n;

	vector<vector<int> > tomatos (n,vector<int> (m,0));
	queue<pair<int,int> > q;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int is_ripen;
			cin >> is_ripen;
			if(is_ripen == 1) q.push(make_pair(i,j));
			tomatos[i][j] = is_ripen;
		}
	}

	// BFS 한다. day 기록
	while(!q.empty()){
		pair<int,int> front = q.front();
		q.pop();
		int front_i = front.first;
		int front_j = front.second;
		int day = tomatos[front_i][front_j];
		for(int i=0;i<4;i++){
			int next_i = front_i + dx[i];
			int next_j = front_j + dy[i];
			if(0<=next_i && next_i<n && 0<=next_j && next_j <m){
				if(tomatos[next_i][next_j] == 0){
					tomatos[next_i][next_j] = day + 1;
					q.push(make_pair(next_i,next_j));
				}
			}
		}
	}

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout << tomatos[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(tomatos[i][j]==0){
				cout << -1;
				return 0;
			}
			ans = ans > tomatos[i][j] ? ans : tomatos[i][j];
		}
	}

	if(ans == 1){
		cout << 0;
	}else{
		cout << ans-1;
	}
	// 하고 나서 전체 배열 검사해서 0 있으면 -1
	// 없으면 최대값 -1 
	// 최대값이 1이면 0

	return 0;
}