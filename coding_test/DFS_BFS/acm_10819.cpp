#include<bits/stdc++.h>
using namespace std;


int ans ;
void DFS(int cnt,int n,vector<int> &visited, vector<int> &v, vector<int> &selected){
    if( cnt == n){
        int sum = 0;
        for(int i=1;i<n;i++){
            sum +=abs(v[selected[i]]-v[selected[i-1]]);
        }
        ans = ans > sum ? ans : sum ;
    }
    else{
        for(int i=0;i<n;i++){
            if(visited[i]==1)continue;
            visited[i]=1;
            selected[cnt]=i;
            DFS(cnt+1,n,visited,v,selected);
            visited[i]=0;
        }
    }
}


int main(void){

    int n;
    cin >> n;

    vector<int> v(n,0);
    vector<int> visited(n,0);
    vector<int> selected(n,0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    DFS(0,n,visited,v,selected);

    cout << ans;

    return 0;
}