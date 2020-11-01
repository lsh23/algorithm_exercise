#include<bits/stdc++.h>
using namespace std;


// 0 1 2 3 
// 상하좌우

int ans = 0;
void DFS(vector<vector<int>> board, vector<int> &select, int cnt, int n){
    if(cnt == 5){
        // for(int i : select){
        //     cout << i << " ";
        // }
        // cout << "\n";
        for(int k : select){
            if(k==0){
                //
                // 0,1 행
                // 1,2 행
                // 2,3 행
                // 3,4 행
                // ...

                // n-1,n행
                // 같은 숫자 있는지 확인
                for(int j=0;j<n;j++){
                    deque<int> tmp;
                    queue<int> q;
                    for(int i=0;i<n;i++){
                        if(board[i][j]!=0) q.push(board[i][j]);
                    }

                    if(q.size()<2){
                        while(!q.empty()){
                            int front = q.front();
                            q.pop();
                            tmp.push_back(front);
                        }
                    }
                    else{
                        int first = q.front();
                        q.pop();
                        int front = q.front();
                        q.pop();
                        if(front == first){
                            tmp.push_back(front*2);
                            if(!q.empty()){
                                first = q.front();
                                q.pop();
                                if(q.empty()) tmp.push_back(first);
                            }
                        }else{
                            tmp.push_back(first);
                            first = front;
                        }
                        while(!q.empty()){
                            front = q.front();
                            q.pop();
                            if(front == first){
                                tmp.push_back(front*2);
                                if(!q.empty()) {
                                    first = q.front();
                                    q.pop();
                                    if(q.empty())tmp.push_back(first);
                                }
                            }else{
                                tmp.push_back(first);
                                first = front;
                            }
                        }
                    }
                    
                    while(tmp.size()!=n){
                        tmp.push_back(0);
                    }

                    for(int i=0;i<n;i++){
                        board[i][j] = tmp[i];
                    }
                }

            }
            if(k==1){
                for(int j=0;j<n;j++){
                    deque<int> tmp;
                    queue<int> q;
                    for(int i=n-1;i>=0;i--){
                        if(board[i][j]!=0) q.push(board[i][j]);
                    }

                    if(q.size()<2){
                        while(!q.empty()){
                            int front = q.front();
                            q.pop();
                            tmp.push_front(front);
                        }
                    }
                    else{
                        int first = q.front();
                        q.pop();
                        int front = q.front();
                        q.pop();
                        if(front == first){
                            tmp.push_front(front*2);
                            if(!q.empty()){
                                first = q.front();
                                q.pop();
                                if(q.empty()) tmp.push_front(first);
                            }
                        }else{
                            tmp.push_front(first);
                            first = front;
                        }
                        while(!q.empty()){
                            front = q.front();
                            q.pop();
                            if(front == first){
                                tmp.push_front(front*2);
                                if(!q.empty()) {
                                    first = q.front();
                                    q.pop();
                                    if(q.empty())tmp.push_front(first);
                                }
                            }else{
                                tmp.push_front(first);
                                first = front;
                            }
                        }
                    }
                    
                    while(tmp.size()!=n){
                        tmp.push_front(0);
                    }

                    for(int i=0;i<n;i++){
                        board[i][j] = tmp[i];
                    }
                }            
            }
            if(k==2){
                for(int i=0;i<n;i++){
                    deque<int> tmp;
                    queue<int> q;
                    for(int j=0;j<n;j++){
                        if(board[i][j]!=0) q.push(board[i][j]);
                    }
                    if(q.size()<2){
                        while(!q.empty()){
                            int front = q.front();
                            q.pop();
                            tmp.push_back(front);
                        }
                    }
                    else{
                        int first = q.front();
                        q.pop();
                        int front = q.front();
                        q.pop();
                        if(front == first){
                            tmp.push_back(front*2);
                            if(!q.empty()){
                                first = q.front();
                                q.pop();
                                if(q.empty()) tmp.push_back(first);
                            }
                        }else{
                            tmp.push_back(first);
                            first = front;
                        }
                        while(!q.empty()){
                            front = q.front();
                            q.pop();
                            if(front == first){
                                tmp.push_back(front*2);
                                if(!q.empty()) {
                                    first = q.front();
                                    q.pop();
                                    if(q.empty())tmp.push_back(first);
                                }
                            }else{
                                tmp.push_back(first);
                                first = front;
                            }
                        }
                    }
                    
                    while(tmp.size()!=n){
                        tmp.push_back(0);
                    }

                    for(int j=0;j<n;j++){
                        board[i][j] = tmp[j];
                    }
                }            
            }
            if(k==3){
                for(int i=0;i<n;i++){
                    deque<int> tmp;
                    queue<int> q;
                    for(int j=n-1;j>=0;j--){
                        if(board[i][j]!=0) q.push(board[i][j]);
                    }

                    if(q.size()<2){
                        while(!q.empty()){
                            int front = q.front();
                            q.pop();
                            tmp.push_front(front);
                        }
                    }
                    else{
                        int first = q.front();
                        q.pop();
                        int front = q.front();
                        q.pop();
                        if(front == first){
                            tmp.push_front(front*2);
                            if(!q.empty()){
                                first = q.front();
                                q.pop();
                                if(q.empty()) tmp.push_front(first);
                            }
                        }else{
                            tmp.push_front(first);
                            first = front;
                        }
                        while(!q.empty()){
                            front = q.front();
                            q.pop();
                            if(front == first){
                                tmp.push_front(front*2);
                                if(!q.empty()) {
                                    first = q.front();
                                    q.pop();
                                    if(q.empty())tmp.push_front(first);
                                }
                            }else{
                                tmp.push_front(first);
                                first = front;
                            }
                        }
                    }
                    
                    while(tmp.size()!=n){
                        tmp.push_front(0);
                    }

                    for(int j=0;j<n;j++){
                        board[i][j] = tmp[j];
                    }
                }                
            }
        }

        int board_max = 0;
        for(vector<int> row : board){
            for(int i : row){
                board_max = board_max > i ? board_max : i;
            }
        }
        
        ans = ans > board_max ? ans : board_max;

    }else{
        for(int i=0;i<4;i++){
            select[cnt] = i;
            DFS(board,select,cnt+1,n);
        }
    }
}

int main(void){

    int n;
    cin >> n;
    vector<vector<int>> board(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }  
    vector<int> select(5,0);
    DFS(board,select,0,n);

    cout << ans;

    return 0;
}