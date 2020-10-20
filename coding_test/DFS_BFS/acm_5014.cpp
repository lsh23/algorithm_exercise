#include<bits/stdc++.h>
using namespace std;

int main(void){

    int f,s,g,u,d;
    cin >> f >> s >> g >> u >> d;

    // 총 f 층
    // 스타트링크는 g층
    // 현재 위치 s층
    // 위로 u층 만큼 이동
    // 아래로 d층 만큼 이동
    vector<int> visited(f+1,0);
    visited[s] = 1;
    int answer = -1;
    queue<pair<int,int>> q;
    q.push(make_pair(s,0));
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cur == g){
            answer = cnt;
            break;
        }
        int next_up = cur + u;
        if(next_up <= f){
            if(visited[next_up]==0){
                visited[next_up]=1;
                q.push(make_pair(next_up,cnt+1));
            }
        }
        int next_down = cur - d;
        if(next_down >= 1){
            if(visited[next_down]==0){
                visited[next_down]=1;
                q.push(make_pair(next_down,cnt+1));
            }
        }
    }

    if(answer==-1) cout << "use the stairs\n";
    else cout << answer << "\n";

    return 0;
}