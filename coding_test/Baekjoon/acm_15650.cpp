#include<bits/stdc++.h>
using namespace std;


void DFS(vector<int> &visited,vector<int> &answer,int k,int m,int n,int cnt){
    if(cnt == m){
        for(int i : answer){
            cout << i+1 << " ";
        }
        cout << "\n";
    }else{
        for(int i=k;i<n;i++){
            if(visited[i]==0){
                visited[i] = 1;
                answer[cnt] = i;
                DFS(visited,answer,i,m,n,cnt+1);
                visited[i] = 0;
            }
        }
    }
}

int main(void){

    int n,m;

    cin >> n >> m;
    vector<int> visited(n,0);
    vector<int> answer(m,0);
    DFS(visited,answer,0,m,n,0);

    return 0;
}