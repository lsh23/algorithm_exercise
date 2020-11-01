#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

int main(void){

    //
    // 더 이상 먹을 수 있는 물고기가 존재하지 않으면 엄마에게 도움 요청
    // 먹을 수 있는 물고기가 1마리라면 그것을 먹는다.
    // 1마리보다 많으면, 가장 가까운 물고기를 먹는다.
    // 거리 - 지나야하는 칸의개수의 최솟값, 가능한 물고기가 많으면 가장 위 가장 왼쪽 물고기 

    // 1칸당 1초, 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1증가.
    // 아기 상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지.

    int n;

    cin >> n;

    vector<vector<int>> space(n,vector<int>(n,0));

    pair<int,int> start_position;
    int size = 2;
    int ate = 0;

    int answer = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int space_info;
            cin >> space_info;
            space[i][j] = space_info;
            if(space_info == 9){
                start_position = make_pair(i,j);
            }
        }
    }

    while(true){
        int before_ate = ate;
        vector<vector<int>> dists(n,vector<int>(n,0));
        vector<vector<int>> visited(n,vector<int>(n,0));
        visited[start_position.first][start_position.second] = 1;
        queue<pair<int,int>> q;
        q.push(start_position);
        int min = INT32_MAX;
        int x_min = INT32_MAX ;
        int y_min = INT32_MAX;
        while(!q.empty()){
            // 전파하면서 레벨단위(dist)로 이동한 것에 대해서 먹을수있는지 판단하고, 이동 
            pair<int,int> front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;
            int dist = dists[x][y];
            if(space[x][y] != 0 && space[x][y] < size){
                // 최초 먹는거 가능한 dist 를 구했다고 가정
                if(dist <= min){
                    min = dist;
                                    // 비교해서 x,y 확정 해야됨
                    if(x < x_min){
                        x_min = x;
                        y_min = y;
                    }else if( x == x_min){
                        if( y < y_min){
                            x_min = x;
                            y_min = y; 
                        }
                    }
                }
            }
            for(int i=0;i<4;i++){
                int next_x = x + dx[i];
                int next_y = y + dy[i];
                if(0<=next_x && next_x<n && 0<=next_y && next_y<n){
                    if(visited[next_x][next_y]==0 && space[next_x][next_y] <= size){
                        visited[next_x][next_y] = 1;
                        dists[next_x][next_y] = dist + 1;
                        q.push(make_pair(next_x,next_y));
                        // cout << next_x << "," << next_y << "\n";
                    }
                }
            }
        }
        if(min == INT32_MAX) break;
        // 먹는 좌표 x,y 확정 후
        space[x_min][y_min] = 0;
        answer += min;
        ate++;
        if(ate == size){
            ate = 0;
            size++;
        }
        // cout << x_min << " " << y_min << " ----------- dist : " << min << " size : " << size << " ate : " << ate <<"\n";
        space[start_position.first][start_position.second] = 0;
        start_position.first = x_min;
        start_position.second = y_min;
    }

    cout << answer;

    return 0;
}