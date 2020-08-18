#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void) {

	int i,j;

	vector<vector<int> > miro(8,vector<int> (8,0));
	vector<vector<int> > visited(8,vector<int> (8,INT32_MAX));
	queue<pair<int,int> > q;

	for(i=1;i<=7;i++){
		for(j=1;j<=7;j++){
			cin >> miro[i][j];
		}
	}
 

	q.push(make_pair(1,1));
	visited[1][1] = 0;
	while(!q.empty()){
		pair<int,int> front = q.front();
		q.pop();
		int x = front.first;
		int y = front.second;
		for(i=0;i<4;i++){
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if(1<=next_x && next_x <=7 && 1<=next_y && next_y <=7){
				if(miro[next_x][next_y]==0 && visited[next_x][next_y] > visited[x][y] + 1){
					visited[next_x][next_y] = visited[x][y] + 1;
					q.push(make_pair(next_x,next_y));
				}
			}
		}
	}
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cout <<  visited[i][j] << " ";
		}
		cout << "\n";
	}

	if(visited[7][7] == INT32_MAX){
		cout << -1;
	}else cout << visited[7][7];

	return 0;
}