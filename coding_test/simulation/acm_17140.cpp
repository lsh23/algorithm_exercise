#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.second==b.second){
        return a.first<b.first;
    }else{
        return a.second<b.second;
    }
}

bool cmp_2(pair<int,int>a,pair<int,int>b){
    return a.second < b.second;
}

int main(void){

    int r,c,k;
    cin >> r >> c>> k;

    vector<vector<int>> v(101,vector<int>(101,0));

    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin >> v[i][j];
        }
    }

    int col_size = 3;
    int row_size = 3;

    int cnt = 0;
    while(cnt<100 && v[r][c]!=k){
        if(row_size >= col_size){
            //r
            //행
            int max = 0;
            for(int j=1;j<=row_size;j++){
                map<int,int> m;
                for(int i=1;i<=col_size;i++){
                    if(v[j][i]==0) continue;
                    if(m.find(v[j][i])!=m.end()){
                        m[v[j][i]]++;
                    }else{
                        m[v[j][i]]=1;
                    }
                }
                for(int z=1;z<=col_size;z++) v[j][z]=0;
                vector<pair<int,int>> tmp (m.begin(),m.end());
                max = max > tmp.size()*2 ? max : tmp.size()*2;
                int k = 1;
                sort(tmp.begin(),tmp.end(),cmp);
                for(auto t:tmp){
                    v[j][k++]=t.first;
                    if(k==101) break;
                    v[j][k++]=t.second;
                    if(k==101) break;
                }
            }
            col_size = max;
            cnt++;
        }else{
            //c
            //열
            int max = 0;
            for(int j=1;j<=col_size;j++){
                map<int,int> m;
                for(int i=1;i<=row_size;i++){
                    if(v[i][j]==0) continue;
                    if(m.find(v[i][j])!=m.end()){
                        m[v[i][j]]++;
                    }else{
                        m[v[i][j]]=1;
                    }
                }
                for(int z=1;z<=row_size;z++) v[z][j]=0;
                vector<pair<int,int>> tmp (m.begin(),m.end());
                max = max > tmp.size()*2 ? max : tmp.size()*2;
                int k = 1;
                sort(tmp.begin(),tmp.end(),cmp);
                for(auto t:tmp){
                    v[k++][j]=t.first;
                    if(k==101) break;
                    v[k++][j]=t.second;
                    if(k==101) break;
                }
            }
            row_size = max;
            cnt++;
        }
    }

    if(cnt==100) cout << -1;
    else cout << cnt;


    return 0;
}