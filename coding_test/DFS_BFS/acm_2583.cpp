#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void fill_square(vector<vector<int>> sq_info,int k,vector<vector<int>> &map_info){

    for(int i=0;i<k;i++){

        int left_bottom_x = sq_info[i][0];
        int left_bottom_y = sq_info[i][1];
        int right_top_x = sq_info[i][2];
        int right_top_y = sq_info[i][3];

        for(int j=left_bottom_y;j<right_top_y;j++){
            for(int k=left_bottom_x;k<right_top_x;k++){
                map_info[j][k]=1;
            }
        }

    }

}


int main(void){

    int m,n,k;
    cin >> m >> n >> k;
    vector<vector<int>> sq_info(k,vector<int>(4,0));
    vector<vector<int>> map_info(m,vector<int>(n,0));
    for(int i=0;i<k;i++){
        cin >> sq_info[i][0] >> sq_info[i][1] >> sq_info[i][2] >> sq_info[i][3];
    }

    fill_square(sq_info,k,map_info);

    vector<vector<int>> visited(m,vector<int>(n,0));
    vector<int> sq_size;
    int cnt = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==0 && map_info[i][j]==0){
                cnt++;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                visited[i][j]=1;
                int size = 1;
                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int next_x = x + dx[k];
                        int next_y = y + dy[k];
                        if(next_x<0 || next_x >=n || next_y < 0 || next_y >=m) continue;
                        if(visited[next_y][next_x]==1)continue;
                        if(map_info[next_y][next_x]==1)continue;
                        visited[next_y][next_x] = 1;
                        q.push(make_pair(next_y,next_x));
                        size++;
                    }
                }
                sq_size.push_back(size);
            }
        }
    }

    sort(sq_size.begin(),sq_size.end());

    cout << cnt << "\n";
    for(auto size : sq_size){
        cout << size << " ";
    }

    return 0;
}