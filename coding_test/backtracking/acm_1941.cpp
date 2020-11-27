#include<bits/stdc++.h>
using namespace std;

int answer;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};


void DFS(int cnt,int k,vector<vector<int>> seat_info, vector<int> &visited, vector<int> &selected){
    if(cnt==7){
        vector<pair<int,int>> v;
        for(int i : selected){
            v.push_back(make_pair(i/5,i%5));
        }
        int s = 0;
        for(int i=0;i<7;i++){
            if(seat_info[v[i].first][v[i].second]==1) s++;
        }
        if(s>=4){
            queue<pair<int,int>> q;
            vector<vector<int>> visited_2(5,vector<int>(5,0));
            visited_2[v[0].first][v[0].second]=1;
            q.push({v[0].first,v[0].second});
            int cnt = 0;
            while(!q.empty()){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                cnt++;
                for(int i=0;i<4;i++){
                    int next_y = y + dy[i];
                    int next_x = x + dx[i];
                    if(next_y<0 || next_y >=5 || next_x < 0 || next_x >=5) continue;
                    if(visited_2[next_y][next_x]==1) continue;
                    bool flag = false;
                    for(int j=0;j<7;j++){
                        if(v[j].first == next_y && v[j].second == next_x){
                            flag = true;
                            break;
                        }
                    }
                    if(flag){
                        q.push({next_y,next_x});
                        visited_2[next_y][next_x]=1;
                    }
                }
            }
            if(cnt==7) answer++;
        }
    }else{
        for(int i=k;i<25;i++){
            if(visited[i]==0){
                visited[i] = 1;
                selected[cnt] = i;
                DFS(cnt+1,i,seat_info,visited,selected);
                visited[i] = 0;
            }
        }
    }
}

int main(void){

    vector<vector<int>> seat_info(5,vector<int>(5,0));

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            char info;
            cin >> info;
            if(info=='Y') seat_info[i][j] = 0;
            else seat_info[i][j] = 1;
        }
    }

    vector<int> visited(25,0);
    vector<int> selected(7,0);
    DFS(0,0,seat_info,visited,selected);
    
    cout << answer;
    return 0;
}