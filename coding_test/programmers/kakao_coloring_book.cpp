#include <vector>
#include <queue>
using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/1829

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    // 그냥 bfs 문제
    vector<vector<int>> visited(m,vector<int>(n,0));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==0 && picture[i][j]!=0){
                number_of_area++;
                visited[i][j]=1;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                int size = 1;
                int color = picture[i][j];
                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int next_y = y + dy[k];
                        int next_x = x + dx[k];
                        if(next_y<0 || next_y >= m || next_x < 0 || next_x >= n) continue;
                        if(visited[next_y][next_x]!=0)continue;
                        if(picture[next_y][next_x]!=color)continue;
                        visited[next_y][next_x] = 1;
                        size++;
                        q.push(make_pair(next_y,next_x));
                    }
                }
                max_size_of_one_area = max_size_of_one_area > size ? max_size_of_one_area : size;
            }
        }
    }
    
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}