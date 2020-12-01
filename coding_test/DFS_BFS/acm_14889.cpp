#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int answer = INT32_MAX;

void DFS(int n,int k,int cnt ,vector<vector<int>> &s,vector<int> &visited,vector<int> &selected){
    if(cnt == n/2){
        vector<int> start_team(n,0);
        for(auto s : selected){
            start_team[s]=1;
        }
        int start_team_score = 0;
        int link_team_score = 0;
        for(int i=0;i<n;i++){
            bool is_start_team = start_team[i];
            for(int j=i+1;j<n;j++){
                if(start_team[j]==1&&is_start_team==true){
                    start_team_score += (s[i][j] + s[j][i]);
                }
                if(start_team[j]==0&&is_start_team==false){
                    link_team_score += (s[i][j] + s[j][i]);
                }
            }
        }
        answer = min(answer,abs(start_team_score-link_team_score));
    }else{
        for(int i=k;i<n;i++){
            if(visited[i]==0){
                selected[cnt] = i;
                visited[i] = 1;
                DFS(n,i,cnt+1,s,visited,selected);
                visited[i] = 0;
            }
        }
    }
}


int main(void){
    int n;
    cin >> n;
    vector<vector<int>> s(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> s[i][j];
        }
    }

    vector<int> visited(n,0);
    vector<int> selected(n/2,0);
    DFS(n,0,0,s,visited,selected);

    cout << answer;
    return 0;
}