#include<iostream>
#include<vector>

using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(void){


    int r,c,t;
    cin >> r >> c >> t;
    vector<vector<int>> v (r+1,vector<int>(c+1,0));
    vector<pair<int,int>> cleaner;
    // 공기 청정기가 설치되어 있는곳은 -1
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            int dust;
            cin >> dust;
            v[i][j] = dust;
            if(dust == -1){
                cleaner.push_back(make_pair(i,j));
            }
        }
    }

    // t초후 남아 있는 먼지의 총량
    // 미세 먼지 확신 규칙
    // 인접 4방향
    // 공기청정기 있으면 그쪽은 x , 칸없으면 x
    // 확산되는 양은 A(r,c)/5 이고 소수점 버림
    // (r,c)에 남은 미세먼지양은 A(r,c) - A(r,c)/5 * 확산 방향 개수 

    // 1초마다

    while(t!=0){
        // 확산
        vector<vector<int>> next_v (r+1,vector<int>(c+1,0));
        next_v[cleaner[0].first][1] = -1;
        next_v[cleaner[1].first][1] = -1;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(v[i][j]==0 || v[i][j] == -1) continue;
                int x = i;
                int y = j;
                int cnt = 0;
                for(int k=0;k<4;k++){
                    int next_x = x+dx[k];
                    int next_y = y+dy[k];
                    if(1<=next_x && next_x<=r && 1<=next_y && next_y<=c){
                        if(v[next_x][next_y]==-1)continue;
                        next_v[next_x][next_y] += v[x][y]/5;
                        cnt++;
                    }
                }
                next_v[x][y] += v[x][y] - (cnt*(v[x][y]/5));
            }
        }

        // cout << "\n";
        // for(int i=1;i<=r;i++){
        //     for(int j=1;j<=c;j++){
        //         cout << next_v[i][j] << " ";
        //     }
        //     cout << "\n";
        // }


        // 공기청정기 순환
        vector<vector<int>> next_v_2 (next_v.begin(),next_v.end());
        int cleaner_up_row = cleaner[0].first;
        int cleaner_down_row = cleaner[1].first;

        next_v_2[cleaner_down_row][2] = 0;
        next_v_2[cleaner_up_row][2] = 0;

        for(int j=3;j<=c;j++){
            next_v_2[cleaner_up_row][j] = next_v[cleaner_up_row][j-1];
            next_v_2[cleaner_down_row][j] = next_v[cleaner_down_row][j-1];
        }

        // cout << "\n";
        // for(int i=1;i<=r;i++){
        //     for(int j=1;j<=c;j++){
        //         cout << next_v_2[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        for(int j=c;j>=2;j--){
            next_v_2[1][j-1] = next_v[1][j];
            next_v_2[r][j-1] = next_v[r][j];
        }

        // cout << "\n";
        // for(int i=1;i<=r;i++){
        //     for(int j=1;j<=c;j++){
        //         cout << next_v_2[i][j] << " ";
        //     }
        //     cout << "\n";
        // }


        for(int i=cleaner_up_row;i>1;i--){
            next_v_2[i-1][c] = next_v[i][c];
        }


        // cout << "\n";
        // for(int i=1;i<=r;i++){
        //     for(int j=1;j<=c;j++){
        //         cout << next_v_2[i][j] << " ";
        //     }
        //     cout << "\n";
        // }


        for(int i=cleaner_down_row;i<r;i++){
            next_v_2[i+1][c] = next_v[i][c];
        }

        // cout << "\n";
        // for(int i=1;i<=r;i++){
        //     for(int j=1;j<=c;j++){
        //         cout << next_v_2[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        for(int i=1;i<cleaner_up_row;i++){
            next_v_2[i+1][1] = next_v[i][1];
        }


        // cout << "\n";
        // for(int i=1;i<=r;i++){
        //     for(int j=1;j<=c;j++){
        //         cout << next_v_2[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        for(int i=r;i>cleaner_down_row;i--){
            next_v_2[i-1][1] = next_v[i][1];
        }

        // cout << "\n";
        // for(int i=1;i<=r;i++){
        //     for(int j=1;j<=c;j++){
        //         cout << next_v_2[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        next_v_2[cleaner_down_row][1] = -1;
        next_v_2[cleaner_up_row][1] = -1;

        t--;
        v = next_v_2;
        // cout << "\n";
        // for(int i=1;i<=r;i++){
        //     for(int j=1;j<=c;j++){
        //         cout << v[i][j] <<" ";
        //     }
        //     cout << "\n";
        // }
    }

    // cout << "\n";

    int answer = 0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(v[i][j]!=-1) answer += v[i][j];
            // cout << v[i][j] << " ";
        }
        // cout << "\n";
    }

    cout << answer;

    return 0;
}