#include<bits/stdc++.h>
using namespace std;

int dx[8] = {1,0,1,0,1,-1,-1,1};
int dy[8] = {0,1,0,-1,1,-1,1,-1};

int main(void) {

	int n;
	
	cin >> n;

	vector<vector<int> > map(n,vector<int> (n,0));
	vector<vector<int> > visited(n,vector<int> (n,0));
	queue<pair<int,int> > q;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> map[i][j];
		}
	}
	
	int ans = 0;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(visited[i][j] == 0 && map[i][j] == 1){
				visited[i][j] = 1;
				ans++;
				q.push(make_pair(i,j));
				while(!q.empty()){
					pair<int,int> front = q.front();
					int x = front.first;
					int y = front.second;
					q.pop();
					for(int i=0;i<8;i++){
						int next_x = x + dx[i];
						int next_y = y + dy[i];
						if(0 <= next_x && next_x < n && 0 <= next_y && next_y < n){
							if(map[next_x][next_y] == 1){
								if(visited[next_x][next_y]==0){
									visited[next_x][next_y] = 1;
									q.push(make_pair(next_x,next_y));
								}
							} 
						}
					}
				}
			}
		}
	}
	
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout <<  visited[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	cout << ans;

	



	return 0;
}