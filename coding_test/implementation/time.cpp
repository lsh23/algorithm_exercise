#include<bits/stdc++.h>
using namespace std;

int main(void){

    int n;

    cin >> n;

    //0부터 n 시 59분 59 초 까지 값을 같게 하고 거기서 3이 하나라도 포함되는 수를 구하면 됨

    int second=0;
    int minite=0;
    int hour= 0;
    int cnt = 0;
    while(true){

        if(second==60){
            second = 0; 
            minite++;
        }
        if(minite==60){
            minite = 0; 
            hour++;
            if(hour == n+1) break;
        }

        string h = to_string(hour);
        string m = to_string(minite);
        string s = to_string(second);
        string time = h+m+s;
        // cout << time << "\n";
        for( char c : time){
            if(c == '3'){
                cnt++;
                break;
            }
        }

        second++;

    }

    cout << cnt; 

    // n+1 시간 * 3600 * 6 
    return 0;
}