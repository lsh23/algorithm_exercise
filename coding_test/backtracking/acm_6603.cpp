#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int> &v,vector<int> &visited,vector<int> &selected,int cnt,int n,int k){
    if(cnt == 6){
        for(auto i : selected){
            cout << v[i] << " ";
        }
        cout << "\n";
    }else{
        for(int i=k;i<n;i++){
            if(visited[i]==0){
                visited[i]=1;
                selected[cnt]=i;
                DFS(v,visited,selected,cnt+1,n,i);
                visited[i]=0;
            }
        }
    }
}


int main(void){

    int k;

    while(true){
        cin >> k;
        if(k==0)break;
        vector<int> v(k,0);
        vector<int> visited(k,0);
        vector<int> selected(6,0);
        for(int i=0;i<k;i++){
            cin >> v[i];
        }
        DFS(v,visited,selected,0,k,0);
        cout <<"\n";
    }

    return 0;
}