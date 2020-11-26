#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int only_number_buttion(int c,vector<int> &controller){
    int cnt = 0;
    if(c==0){
        if(controller[0]==1) cnt = 1;
        else cnt = -1;
    } 
    while(c){
        if(controller[c%10]==0){
            return -1;
        }else{
            cnt++;
            c /= 10;
        }
    }
    return cnt;
}

int main(void){

    int n,m;
    cin >> n >> m;
    vector<int> controller(10,1);
    for(int i=0;i<m;i++){
        int broken_number;
        cin >> broken_number;
        controller[broken_number] = 0;
    }

    int answer = abs(n-100);
    vector<int> channel(1000001,0);

    for(int i=0;i<=1000000;i++){
        int onb_cnt = only_number_buttion(i,controller);
        int plus_minus_btn_cnt = abs(n-i);
        if(onb_cnt!=-1) answer = min(onb_cnt+plus_minus_btn_cnt,answer);
    }

    cout << answer;

    return 0;
}