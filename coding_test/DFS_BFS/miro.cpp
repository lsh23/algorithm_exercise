#include<bits/stdc++.h>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(void){

    int n,m;

    cin >> n >> m;

    vector<vector<int>> miro(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> miro[i][j];
        }
    }

    // 1 이 이동 가능
    vector<vector<int>> dist(n+1,vector<int>(m+1,INT32_MAX));
    vector<vector<int>> visited(n+1,vector<int>(m+1,0));
    queue<pair<int,int>> q;
    q.push(make_pair(1,1));
    dist[1][1] = 1;
    visited[1][1] = 1;
    while(!q.empty()){
        pair<int,int> front = q.front();
        q.pop();
        int x = front.first;
        int y = front.second;
        // cout << x << y << "\n";
        for(int k=0;k<4;k++){
            int next_x = x+dx[k];
            int next_y = y+dy[k];
            if(1<=next_x&&next_x<=n&&1<=next_y&&next_y<=m){
                if(visited[next_x][next_y]==0 && miro[next_x][next_y]==1){
                    visited[next_x][next_y] = 1;
                    dist[next_x][next_y] = dist[next_x][next_y] < dist[x][y] + 1 ? dist[next_x][next_y] : dist[x][y] + 1;
                    q.push(make_pair(next_x,next_y));
                }
            }
        }
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    cout << dist[n][m];

    return 0;
}