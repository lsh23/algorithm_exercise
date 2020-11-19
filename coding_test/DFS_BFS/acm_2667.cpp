#include<bits/stdc++.h>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(void){

    int n;

    cin >> n;

    vector<vector<int>> map_info(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d",&map_info[i][j]);
        }
    }

    vector<vector<int>> visited(n,vector<int>(n,0));
    vector<int> answer;
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==0 && map_info[i][j]!=0){
                cnt++;
                int size = 1;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                visited[i][j]=1;
                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int next_y = y+dy[k];
                        int next_x = x+dx[k];
                        if(next_x<0 || next_x >=n || next_y <0 || next_y >=n) continue;
                        if(map_info[next_y][next_x]==0) continue;
                        if(visited[next_y][next_x] == 0){
                            visited[next_y][next_x]=1;
                            size++;
                            q.push(make_pair(next_y,next_x));
                        }
                    }
                }
                answer.push_back(size);
            }
        }
    }

    cout << cnt << "\n";

    sort(answer.begin(),answer.end());

    for(auto size : answer){
        cout << size << "\n";
    }


    return 0;
}