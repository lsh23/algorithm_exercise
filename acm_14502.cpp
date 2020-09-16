#include <bits/stdc++.h>

using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int answer = 0;
void DFS(int cnt,int k, vector<pair<int,int>> &v, vector<int> &selected,int n, int m, vector<vector<int>> &research, vector<pair<int,int>> &virus){
    if(cnt == 3){
        vector<vector<int>> result (research.begin(),research.end());
        for(int i : selected){
            int selected_x = v[i].first;
            int selected_y = v[i].second;
            result[selected_x][selected_y] = 1;
            // cout << i << " ";
        }
        // cout << "\n";

        // 전파 시키고
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for (pair<int,int> vi : virus){
            q.push(vi);
        }

        while(!q.empty()){
            pair<int,int> front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;
            for(int i=0;i<4;i++){
                int next_x = x + dx[i];
                int next_y = y + dy[i];
                if(0<=next_x && next_x<n && 0<=next_y && next_y<m){
                    if(visited[next_x][next_y]==0 && result[next_x][next_y]==0){
                        visited[next_x][next_y] = 1;
                        result[next_x][next_y] = 2;
                        q.push(make_pair(next_x,next_y));
                    }
                }
            }
        }

        // 빈칸 수세고
        int cnt = 0;
        if(selected[0]==0 && selected[1]==4 && selected[2]==15){
            int a = 1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(result[i][j] == 0) cnt ++;
            }
        }
        // cout << cnt;
        answer = answer > cnt ? answer : cnt;

    }else{
        for(int i=k;i<v.size();i++){
            selected[cnt] = i;
            DFS(cnt+1,i+1,v,selected,n,m,research,virus);
        }
    }
}


int main(void){

    int n,m;

    cin >> n >> m;

    vector<vector<int>> research (n,vector<int>(m,0));
    vector<pair<int,int>> v;
    vector<pair<int,int>> virus;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int virus_info;
            cin >> virus_info;
            research[i][j] = virus_info;
            if(virus_info == 0) v.push_back(make_pair(i,j));
            if(virus_info == 2) virus.push_back(make_pair(i,j));
        }
    }

    // 0 빈칸, 1 벽, 2는 바이러스 , 바이러스는 상하좌우 인접한 빈칸으로 퍼져나감
    // 벽을 새로 3개 세우는데, 벽을 3개 새로 세우고 빈칸의 수가 가장 많을 때의 수 구하기.
    // 총 크기 최소 9 최대 64 3c3 ~ 62c3

    // 3개 고르고

    vector<int> selected(3,0);
    DFS(0,0,v,selected,n,m,research,virus);

    cout << answer;

    return 0;
}
