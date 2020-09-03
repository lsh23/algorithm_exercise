#include<bits/stdc++.h>
using namespace std;

int main(void){

    string position;
    cin >> position;
    int cnt = 0;
    int y = position[0]-'a' + 1;
    int x = position[1]-'0';

    int first[] = {2,-2};
    int second[] = {1,-1};
    int dy,dx;
    // cout << y << " " << x;
    // 수평 두칸 이동 후 수직 한칸
    // 수평 y
    // 수평 +2 , 수직 +1 , 수직-1
    // 수평 -2 , 수직 +1 , 수직-1 
    for(int i=0;i<2;i++){
        dy = first[i];
        for(int j=0;j<2;j++){
            dx = second[j];
            int next_x = x + dx;
            int next_y = y + dy;
            if(8>=next_x&&next_x>=1 && 8>=next_y&&next_y>=1){
                cnt++;
            }
        }
    }

    for(int i=0;i<2;i++){
        dx = first[i];
        for(int j=0;j<2;j++){
            dy = second[j];
            int next_x = x + dx;
            int next_y = y + dy;
            if(8>=next_x&&next_x>=1 && 8>=next_y&&next_y>=1){
                cnt++;
            }
        }
    }

    // 수직 두칸 이동 후 수평 한칸
    // 수직 x
    // 수직 +2 , 수평 +1 , 수평-1
    // 수직 -2 , 수평 +1 , 수평-1 

    cout << cnt;

    return 0;
}