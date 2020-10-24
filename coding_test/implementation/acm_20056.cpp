#include<bits/stdc++.h>
using namespace std;

int dr[] = {-1,-1,0,1,1,1,0,-1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

struct Ball{
    int r,c,m,s,d;
    bool dead = false;
    Ball(int a,int b,int g,int f,int e){
        r=a;
        c=b;
        m=g;
        s=f;
        d=e;
    }
};


int main(void)
{

    int n,m,k;
    cin >> n >> m >> k;

    vector<vector<vector<int>>> v(n,vector<vector<int>>(n));
    vector<Ball> v_b;
    for(int i=1;i<=m;i++){
        int r,c,m,s,d;
        cin >> r >> c >> m >> s >> d;
        v_b.push_back(Ball(r,c,m,s,d));
    }

    for(int i=0;i<k;i++){
        // 모든 ball 이동
        vector<vector<vector<int>>> v(n+1,vector<vector<int>>(n+1));
        int v_b_size = v_b.size();
        for(int i=0;i<v_b_size;i++){
            if(v_b[i].dead)continue;
            int r = v_b[i].r;
            int c = v_b[i].c;
            int next_r = r + dr[v_b[i].d]*v_b[i].s;
            int next_c = c + dc[v_b[i].d]*v_b[i].s;
            if(next_r>n){
                next_r %= n;
            }
            if(next_r<=0){
                next_r %= n;
                next_r += n;
            }
            if(next_c>n){
                next_c %= n;
            }
            if(next_c<=0){
                next_c %= n;
                next_c += n;
            }
            v[next_r][next_c].push_back(i);
            v_b[i].r = next_r;
            v_b[i].c = next_c;
        }
                // 다음 위치 및 방향 확정 후 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(v[i][j].size()>1){
                    int even_cnt = 0;
                    int m_sum = 0;
                    int s_sum = 0;
                    for(int z=0;z<v[i][j].size();z++){
                        v_b[v[i][j][z]].dead = true;
                        if(v_b[v[i][j][z]].d%2==0) even_cnt++;;
                        m_sum += v_b[v[i][j][z]].m;
                        s_sum += v_b[v[i][j][z]].s;
                    }
                    if(m_sum<5) continue;
                    int new_m = m_sum/5;
                    int new_s = s_sum/v[i][j].size();
                    if(even_cnt==0 || even_cnt == v[i][j].size()){
                        v_b.push_back(Ball(i,j,new_m,new_s,0));
                        v_b.push_back(Ball(i,j,new_m,new_s,2));
                        v_b.push_back(Ball(i,j,new_m,new_s,4));
                        v_b.push_back(Ball(i,j,new_m,new_s,6));
                    }else{
                        v_b.push_back(Ball(i,j,new_m,new_s,1));
                        v_b.push_back(Ball(i,j,new_m,new_s,3));
                        v_b.push_back(Ball(i,j,new_m,new_s,5));
                        v_b.push_back(Ball(i,j,new_m,new_s,7));
                    }
                }
            }
        }
    }
    int answer = 0;
    for(int i=0;i<v_b.size();i++){
        if(v_b[i].dead)continue;
        answer += v_b[i].m;
    }

    cout << answer;
    return 0;
}