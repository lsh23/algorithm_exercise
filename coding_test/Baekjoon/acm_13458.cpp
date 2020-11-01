#include<bits/stdc++.h>

using namespace std;

int main(void){

    int n,b,c;

    cin >> n;
    vector<int> student(n,0);

    for(int i=0;i<n;i++){
        cin >> student[i];
    }

    cin >> b >> c;

    // 각 시험장에 총감독관은 오직 1명,
    // 부감독관 여러명 가능
    // b - 총
    // c - 부감

    // 그냥 각 시험장 순회하면서 총감독관으로 커버되면 끝내고 아니면 더해버리는식
    long long cnt = 0;
    for(int i=0;i<n;i++){
        cnt++; // 총감독관
        if(student[i]<=b) continue;
        if((student[i]-b)%c==0){
            cnt += (student[i]-b)/c;
        }else{
            cnt += (student[i]-b)/c + 1;
        }
    }

    cout << cnt ;

    return 0;
}