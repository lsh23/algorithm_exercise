#include<iostream>
#include<vector>
using namespace std;

int main(void){

    int n;
    cin >> n;

    // f(1) = 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 

    // f(2) = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10

    // f(3) = 1 +  

    vector<vector<int>> DP(1001,vector<int>(10,0));
    for(int i=0;i<10;i++){
        DP[1][i]=1;
    }
    
    for(int i=2;i<=1000;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<=j;k++){
                DP[i][j]+=DP[i-1][k]%10007;
            }
        }
    }

    int answer = 0;
    for(int i=0;i<10;i++){
        answer += DP[n][i];
    }

    cout << answer%10007;

    return 0;
}