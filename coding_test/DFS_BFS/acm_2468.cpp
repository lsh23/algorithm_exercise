#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int main(void){

    int n;
    cin >> n;

    vector<vector<int>> area_info(n,vector<int>(n,0));
    int max_height = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> area_info[i][j];
            max_height = max(max_height,area_info[i][j]);
        }
    }


    int max_cnt = 0;
    for(int h=0;h<=max_height;h++){
        
        vector<vector<int>> flood_area(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(h>=area_info[i][j]) flood_area[i][j]=1;
            }
        }
        vector<vector<int>> visited(n,vector<int>(n,0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0 && flood_area[i][j]==0){
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
                                if(flood_area[next_x][next_y]==0 && visited[next_x][next_y]==0){
                                    q.push(make_pair(next_x,next_y));
                                    visited[next_x][next_y] = 1;
                                }
                            }
                        }
                    }
                    cnt++;
                }
            }
        }
        max_cnt = max(max_cnt,cnt);
    }

    cout << max_cnt;

    return 0;
}