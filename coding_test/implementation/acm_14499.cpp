#include<bits/stdc++.h>
using namespace std;

int main(void){
    
    int n,m,x,y,k;
    cin >> n >> m >> x >> y >> k;

    vector<vector<int>> map_infos(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map_infos[i][j];
        }
    }

    vector<int> commands(k,0);
    for(int i=0;i<k;i++){
        cin >> commands[i];
    }

    int bottom = 0;
    int up = 0;
    int left = 0;
    int right = 0;
    int down = 0;
    int top = 0;

    for(int command : commands){
        int _bottom = bottom;
        int _up = up;
        int _left = left;
        int _right = right;
        int _down = down;
        int _top = top;

        if(command == 1){
            int next_x = x;
            int next_y = y+1;
            if(0<=next_y && next_y<m){
                bottom = _right;
                left = _bottom;
                right = _top;
                top = _left;
                if(map_infos[next_x][next_y]==0) map_infos[next_x][next_y] = bottom;
                else{
                    bottom = map_infos[next_x][next_y];
                    map_infos[next_x][next_y] = 0;
                }
                cout << top << "\n";
                x = next_x;
                y = next_y;
            }
        }
        if(command == 2){
            int next_x = x;
            int next_y = y-1;
            if(0<=next_y && next_y<m){
                bottom = _left;
                left = _top;
                right = _bottom;
                top = _right;
                if(map_infos[next_x][next_y]==0) map_infos[next_x][next_y] = bottom;
                else{
                    bottom = map_infos[next_x][next_y];
                    map_infos[next_x][next_y] = 0;
                }
                cout << top << "\n";
                x = next_x;
                y = next_y;
            }
        }
        if(command == 3){
            int next_x = x-1;
            int next_y = y;
            if(0<=next_x&& next_x<n){
                bottom = _up;
                up = _top;
                down = _bottom;
                top = _down;
                if(map_infos[next_x][next_y]==0) map_infos[next_x][next_y] = bottom;
                else{
                    bottom = map_infos[next_x][next_y];
                    map_infos[next_x][next_y] = 0;
                }
                cout << top << "\n";
                x = next_x;
                y = next_y;
            }
        }
        if(command == 4){
            int next_x = x+1;
            int next_y = y;
            if(0<=next_x&& next_x<n){
                bottom = _down;
                up = _bottom;
                down = _top;
                top = _up;
                if(map_infos[next_x][next_y]==0) map_infos[next_x][next_y] = bottom;
                else{
                    bottom = map_infos[next_x][next_y];
                    map_infos[next_x][next_y] = 0;
                }
                cout << top << "\n";
                x = next_x;
                y = next_y;
            }
        }


    }



    return 0;
}