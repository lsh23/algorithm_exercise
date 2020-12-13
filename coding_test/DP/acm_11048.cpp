#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){

    int n,m;

    cin >> n >> m;

    vector<vector<int>> miro(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> miro[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            miro[i][j] += max(max(miro[i-1][j],miro[i][j-1]),miro[i-1][j-1]);
        }
    }

    cout << miro[n][m];

    return 0;
}