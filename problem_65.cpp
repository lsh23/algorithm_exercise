#include <bits/stdc++.h>
using namespace std;

int answer = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


void DFS(int x, int y,vector<vector<int>>& miro, vector<vector<int>>& visited){
	if(x==6 && y ==6){
		answer++;
		return;
	}else{
		for(int i=0; i<4; i++){
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if(next_x>=0 && next_y>=0 && next_x < 7 && next_y < 7){
				if(miro[next_x][next_y] == 0 && visited[next_x][next_y] == 0){
					visited[next_x][next_y] = 1;
					DFS(next_x,next_y,miro,visited);
					visited[next_x][next_y] = 0;
				}
			}
		}
	}

} 

int main(void){

	int i,j;
	vector<vector<int>> miro (7,vector<int>(7,0));
	vector<vector<int>> visited (7,vector<int>(7,0));
	
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			cin >> miro[i][j];
		}
	}
	visited[0][0] = 1;
	DFS(0,0,miro,visited);

	cout << answer;



	return 0;
}
