#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

int answer = INT32_MAX;

void DFS(vector<vector<int>> map_info,vector<pair<int,int>> &virus,vector<int> &visited,vector<int> &selecte_virus,int n_virus,int cnt,int m,int n,int k){
    if(cnt == m){

        queue<pair<int,int>> q;

        
        for(int i=0;i<m;i++){
            int selected_virus_y = virus[selecte_virus[i]].first;
            int selected_virus_x = virus[selecte_virus[i]].second;
            q.push(make_pair(selected_virus_y,selected_virus_x));
            map_info[selected_virus_y][selected_virus_x] = 0;
        }

        int total_second = INT32_MIN;
        while(!q.empty()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            int d = map_info[y][x];
            total_second = total_second > d ? total_second : d;
            for(int i=0;i<4;i++){
                int next_y = y+dy[i];
                int next_x = x+dx[i];
                if(next_y < 0 || next_y >=n || next_x < 0 || next_x >=n) continue;
                if(map_info[next_y][next_x]==-1) continue;
                if(map_info[next_y][next_x] >= map_info[y][x]+1){
                    map_info[next_y][next_x] = map_info[y][x]+1;
                    q.push(make_pair(next_y,next_x));
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(map_info[i][j]==INT32_MAX){
                    return;
                }
            }
        }

        answer = answer < total_second ? answer : total_second;

    }else{
        for(int i=k;i<n_virus;i++){
            if(visited[i]==0){
                visited[i]=1;
                selecte_virus[cnt]=i;
                DFS(map_info,virus,visited,selecte_virus,n_virus,cnt+1,m,n,i);
                visited[i]=0;
            }
        }
    }
}

int main(void){

    int n,m;
    cin >> n >> m;

    vector<vector<int>> map_info(n,vector<int>(n,INT32_MAX));
    vector<pair<int,int>> virus;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int info;
            cin >> info;
            if(info==1)map_info[i][j] = info;
            if(info==2){
                virus.push_back(make_pair(i,j));
            }
        }
    }
    int n_virus = virus.size();

    vector<int>selecte_virus(m,0);
    vector<int>visited(n_virus,0);
    DFS(map_info,virus,visited,selecte_virus,n_virus,0,m,n,0);

    if(answer == INT32_MAX) cout << -1;
    else cout << answer;

    return 0;
}