#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer;

bool can_queen(int y,int x, vector<pair<int,int>> &queens, int cnt){
    int j=0;
    for(;j<cnt;j++){
        int y_2 = queens[j].first;
        int x_2 = queens[j].second;
        if( y==y_2 || x==x_2 )break;
        if( abs(y-y_2) == abs(x-x_2) )break;
    }
    if(j==cnt) return true;
    else return false;
}

void DFS(int n,int cnt,vector<pair<int,int>> &queens){
    if(cnt == n){
        answer++;
    }else{
        for(int i=0;i<n;i++){
            int y = cnt;
            int x = i;
            int j = 0;
            if(can_queen(y,x,queens,cnt)){
                queens[cnt] = make_pair(y,x);
                DFS(n,cnt+1,queens);
            }
        }
    }
}


int solution(int n) {
    
    vector<pair<int,int>> queens (n);
    DFS(n,0,queens);
    
    return answer;
}