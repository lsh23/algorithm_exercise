#include <bits/stdc++.h>
using namespace std;

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

int main(void){

    int r,c;
    cin >> r >> c;
    vector<vector<int>> map_info(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            char c_input;
            int i_input;
            cin >> c_input;
            if(c_input=='.') i_input=0;
            if(c_input=='#') i_input=1;
            if(c_input=='o') i_input=2;
            if(c_input=='v') i_input=3;
            map_info[i][j] = i_input;
        }
    }

    vector<vector<int>> visited(r,vector<int>(c,0));
    int total_o_cnt = 0;
    int total_v_cnt = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            // 한 영역 안에서
            // 늑대랑 양의 개수를 센다
            if(map_info[i][j]!=1 && visited[i][j]==0){
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                visited[i][j]=1;
                int o_cnt = 0;
                int v_cnt = 0;
                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    if(map_info[y][x]==2) o_cnt++;
                    if(map_info[y][x]==3) v_cnt++;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int next_y = y+dy[k];
                        int next_x = x+dx[k];
                        if(next_y < 0 || next_y >=r || next_x < 0 || next_x >= c) continue;
                        if(visited[next_y][next_x]==1)continue;
                        if(map_info[next_y][next_x]==1)continue;
                        visited[next_y][next_x]=1;
                        q.push(make_pair(next_y,next_x));
                    }
                }
                // 양이 늑대 보다 많으면 양의 개수만 체크
                // 아니면 늑대 개수만 체크
                if(o_cnt > v_cnt) total_o_cnt += o_cnt;
                else total_v_cnt += v_cnt;

            }
        }
    }


    cout << total_o_cnt << " " << total_v_cnt;


    return 0;
}