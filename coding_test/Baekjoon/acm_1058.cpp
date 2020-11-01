#include<bits/stdc++.h>
using namespace std;


void DFS(int i,vector<int> &visited, vector<vector<int>> friend_info,int n,set<int> &s){

    for(int k=0;k<n;k++){
        if(friend_info[i][k] && visited[k]==0){
            visited[k] = 1;
            s.insert(k);
            DFS(k,visited,friend_info,n,s);
            visited[k] = 0;
        }
    }

}

int main(void){

    int n;
    cin >> n;

    vector<vector<int>> friend_info(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char info;
            cin >> info;
            if(info=='N') friend_info[i][j] = 0;
            else friend_info[i][j] = 1;
        }
    }

    // 2-친구
    // 그냥 서로 친구인 경우
    // 중간 친구가 있는 경우 

    // 각 개인에 대해서 DFS해서 길이 구하면 됨
    int answer = 0;

    for(int i=0;i<n;i++){
        vector<int> visited(n,0);
        visited[i]=1;
        set<int> s;
        DFS(i,visited,friend_info,n,s);
        
        answer = answer > s.size() ? answer : s.size();
    }

    cout << answer;

    return 0;
}