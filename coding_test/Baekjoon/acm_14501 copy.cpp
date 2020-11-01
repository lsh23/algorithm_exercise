#include<bits/stdc++.h>
using namespace std;

int answer;

void DFS(int day,int n, vector<int> &visited,vector<pair<int,int>> &v){
    if(day>=n+1){
        return;
    }else{
        for(int i=day;i<=n;i++){
            int next_day = v[i].first;
            if(next_day <= n+1){
                visited[next_day]=1;
                DFS(next_day,n,visited,v);
                visited[next_day]=0;
            }
        }
    }
}

int main(void){

    int n;
    cin >> n;

    vector<pair<int,int>> v(n+1);
    vector<int> visited(n+1,0);

    for(int i=1;i<=n;i++){
        int t,p;
        cin >> t >> p;
        v[i] = make_pair(t,p);
    }

    for(int i=1;i<=n;i++){

    }

    cout << answer;
    return 0;
}