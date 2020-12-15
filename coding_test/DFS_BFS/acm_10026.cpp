#include<bits/stdc++.h>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int main(void){

    int n;
    cin >> n;

    vector<vector<int>> grids(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char grid;
            int grid_i;
            cin >> grid;
            if(grid=='R') grid_i = 0;
            if(grid=='G') grid_i = 1;
            if(grid=='B') grid_i = 2;
            grids[i][j] = grid_i;
        }
    }

    vector<vector<int>> visited(n,vector<int>(n,0));

    // 적록 색약이 아닌 사람
    int non_color_blined = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==0){
                int color = grids[i][j];
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                visited[i][j]=1;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int next_x = x + dx[k];
                        int next_y = y + dy[k];
                        if(0<=next_x && next_x<n && 0<=next_y && next_y<n ){
                            if(grids[next_x][next_y]== color && visited[next_x][next_y]==0){
                                q.push(make_pair(next_x,next_y));
                                visited[next_x][next_y] = 1;
                            }
                        }
                    }
                }
            non_color_blined++;
            }
        }
    }

    visited = vector<vector<int>>(n,vector<int>(n,0));

    // 적록 색약인 사람
    int color_blined = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==0){
                int color = grids[i][j];
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                visited[i][j]=1;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int next_x = x + dx[k];
                        int next_y = y + dy[k];
                        if(0<=next_x && next_x<n && 0<=next_y && next_y<n ){
                            if(color == 0 || color == 1){
                                if( (grids[next_x][next_y]==0 || grids[next_x][next_y]==1) && visited[next_x][next_y]==0){
                                    q.push(make_pair(next_x,next_y));
                                    visited[next_x][next_y] = 1;
                                }
                            }
                            else{
                                if(grids[next_x][next_y]== color && visited[next_x][next_y]==0){
                                    q.push(make_pair(next_x,next_y));
                                    visited[next_x][next_y] = 1;
                                }
                            }
                        }
                    }
                }
            color_blined++;   
            }
        }
    }

    cout << non_color_blined << " " << color_blined;

    return 0;
}