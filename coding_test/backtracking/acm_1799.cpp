#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int answer_1;
int answer_2;

int dy[] = {1,-1,1,-1};
int dx[] = {1,-1,-1,1};
vector<vector<int>> chess;

bool can_seleted(int y,int x,int n,vector<vector<int>> &selected){
    if(chess[y][x]==0)return false;
    for(int i=0;i<4;i++){
        int yy = dy[i];
        int xx = dx[i];
        for(int j=1;j<n;j++){
            int next_y = y+yy*j;
            int next_x = x+xx*j;
            if(next_y<0 || next_y>=n || next_x < 0 || next_x >=n)continue;
            if(selected[next_y][next_x]) return false;
        }
    }
    return true;
}

void DFS_1(int n,int y,int x,vector<vector<int>> &selected,int cnt){

    answer_1 = max(answer_1,cnt);

    if(y>=n){
        return;
    }    
    //배치
    else{

        int next_y;
        int next_x;
        if(x+2<n){
            next_y = y;
            next_x = x+2;
        }else{
            next_y = y+1;
            if(next_y%2==0){
                next_x = 0;
            }else{
                next_x = 1;
            }
        }

        //선택가능하면 선택
        if(can_seleted(y,x,n,selected)){
            selected[y][x]=1;
            DFS_1(n,next_y,next_x,selected,cnt+1);
            selected[y][x]=0;
        }
        //아니면 스킵 
        DFS_1(n,next_y,next_x,selected,cnt);

    }
}

void DFS_2(int n,int y,int x,vector<vector<int>> &selected,int cnt){

    answer_2 = max(answer_2,cnt);

    if(y>=n){
        return;
    }    
    //배치
    else{

        int next_y;
        int next_x;
        if(x+2<n){
            next_y = y;
            next_x = x+2;
        }else{
            next_y = y+1;
            if(next_y%2==0){
                next_x = 1;
            }else{
                next_x = 0;
            }
        }

        //선택가능하면 선택
        if(can_seleted(y,x,n,selected)){
            selected[y][x]=1;
            DFS_2(n,next_y,next_x,selected,cnt+1);
            selected[y][x]=0;
        }
        //아니면 스킵 
        DFS_2(n,next_y,next_x,selected,cnt);
    }
}

int main(void){

    int n;
    cin >> n;
    chess = vector<vector<int>>(n,vector<int>(n,0));
    vector<pair<int,int>> can_bishop;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int for_bishop;
            cin >> for_bishop;
            chess[i][j] = for_bishop;
            if(for_bishop){
                can_bishop.push_back({i,j});
            }
        }
    }

    vector<vector<int>> selected(n,vector<int>(n,0));
    DFS_1(n,0,0,selected,0);
    selected = vector<vector<int>>(n,vector<int>(n,0));
    DFS_2(n,0,1,selected,0);

    cout << answer_1+answer_2;

    return 0;
}