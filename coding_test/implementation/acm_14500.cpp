#include<bits/stdc++.h>
using namespace std;

int answer;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
vector<vector<int>> v;

void DFS(int cnt,vector<vector<int>> &visited,int sum,int x,int y,int n,int m){
    if(cnt == 4){
        answer = answer > sum ? answer : sum;
    }else{
        for(int i=0;i<4;i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if(0>next_x || next_x>=n || 0>next_y || next_y>=m) continue;
            if(visited[next_x][next_y]==0){
                visited[next_x][next_y]=1;
                DFS(cnt+1,visited,sum+v[next_x][next_y],next_x,next_y,n,m);
                visited[next_x][next_y]=0;
            }
        }
    }

}

int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    v = vector<vector<int>>(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }

    vector<vector<int>> visited(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = 1;
            DFS(1,visited,v[i][j],i,j,n,m);
            visited[i][j] = 0;

            int sum = 0;
            if(0<=i-1 && i+1<n && j+1<m){
                sum = v[i][j] + v[i-1][j] + v[i+1][j] + v[i][j+1];
                answer = answer > sum ? answer : sum;
            }
            if(i+1<n && 0<=j-1 && j+1<m){
                sum = v[i][j] + v[i][j-1] + v[i+1][j] + v[i][j+1];
                answer = answer > sum ? answer : sum;
            }
            if(0<=i-1 && 0<=j-1 && j+1<m){
                sum = v[i][j] + v[i][j-1] + v[i-1][j] + v[i][j+1];
                answer = answer > sum ? answer : sum;
            }
            if(0<=j-1 && 0<=i-1 && i+1<n){
                sum = v[i][j] + v[i][j-1] + v[i-1][j] + v[i+1][j];
                answer = answer > sum ? answer : sum;
            }
        }
    }

    // ㅏ
    // x,y // x-1, y //x+1,y // x ,y+1

    // ㅜ
    // x,y // x,y-1 // x+1,y // x, y+1

    // ㅗ
    // x,y // x,y-1 // x-1,y // x, y+1

    // ㅓ
    // x,y // x,y-1 // x-1,y // x+1, y 
    cout << answer;

    // cout << "\n" << c;
    return 0;
}