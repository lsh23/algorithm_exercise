#include<bits/stdc++.h>

using namespace std;

int main(void){


    int n;
    cin >> n;

    vector<vector<int>> v(101,vector<int>(101,0));
    for(int i=0;i<n;i++){
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        int cur_g = 0;
        //드래곤 커브 좌표찍기
        v[y][x]=1;
        if(d==0){
            x = x+1;
            d = 1;
        }
        else if(d==1){
            y = y-1;
            d = 2;
        }
        else if(d==2){
            x = x-1;
            d = 3;
        }
        else{
            y = y+1;
            d = 0;
        }
        v[y][x]=1;
        while(g!=0){
            //1세대로 갈때 1개
            //2세대로 갈때 2개
            //3세대로 갈때 4개
            //4세대로 갈때 8개
            //n세대로 갈때 2^(n-1)개
            cur_g++;
            int n = (int) pow(2,cur_g-1);
            for(int i=1;i<=n;i++){
                if(d==0){
                    x = x+1;
                    d = 1;
                }
                else if(d==1){
                    y = y-1;
                    d = 2;
                }
                else if(d==2){
                    x = x-1;
                    d = 3;
                }
                else{
                    y = y+1;
                    d = 0;
                }
                v[y][x]=1;
                cout << "\n";
                for(int i=0;i<7;i++){
                    for(int j=0;j<7;j++){
                        cout << v[i][j] << " ";
                    }
                    cout << "\n";
                }
            }
            g--;
        }

    }




    //1x1 정사각형 개수 세기


    int answer = 0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(v[i][j]==1&&v[i+1][j]==1&&v[i][j+1]==1&&v[i+1][j+1]==1){
                answer++;
            }
        }
    }

    cout << answer;


    return 0;
}