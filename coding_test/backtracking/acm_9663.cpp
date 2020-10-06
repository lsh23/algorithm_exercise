#include<bits/stdc++.h>
using namespace std;

int answer;
void DFS(int k,int cnt,int n,vector<int> &selected,vector<pair<int,int>> &v){
    if(cnt == n){
        answer++;
    }else{
        for(int i=cnt*n;i<cnt*n+n;i++){
            selected[cnt]=i;
            int j=0;
            for(;j<cnt;j++){
                int x = v[selected[j]].first;
                int y = v[selected[j]].second;
                int x_2 = v[selected[cnt]].first;
                int y_2 = v[selected[cnt]].second;
                    // 같은행
                    if(y==y_2) break;
                    // 같은열
                    if(x==x_2) break;
                    // 대각
                    if(abs(x-x_2) == abs(y-y_2)) break;
            }
            if(j==cnt)DFS(i,cnt+1,n,selected,v);
        }    
    }
}

int main(void){

    int n;
    cin >> n;

    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            v.push_back(make_pair(i,j));
        }
    }

    vector<int> selected(n,0);
    // n*n 개중에 n개 선택
    DFS(0,0,n,selected,v);

    cout << answer;
    return 0;
}