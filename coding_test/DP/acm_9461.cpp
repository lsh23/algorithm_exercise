#include<iostream>
#include<vector>

using namespace std;

int main(void){

    int T;
    cin >> T;

    vector<long long> DP(101,0);
    DP[1] = 1; DP[2] = 1; DP[3] = 1; DP[4] = 2; DP[5] = 2;

    for(int i=6;i<=100;i++){
        DP[i] = DP[i-1] + DP[i-5];
    }

    while(T!=0){
        int n;
        cin >> n;
        cout << DP[n] << "\n";
        T--;
    }

    return 0;
}