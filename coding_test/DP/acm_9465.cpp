#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){

    int T;
    cin >> T;

    while(T!=0){

        int n;
        cin >> n;

        vector<vector<int>> scores(2,vector<int>(n,0));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin >> scores[i][j];
            }
        }

        scores[0][1] += scores[1][0];
        scores[1][1] += scores[0][0];
        for(int j=2;j<n;j++){
            for(int i=0;i<2;i++){
                if(i==0) scores[i][j] += max(scores[1][j-1],scores[1][j-2]);
                if(i==1) scores[i][j] += max(scores[0][j-1],scores[0][j-2]);
            }
        }

        cout << max(scores[0][n-1],scores[1][n-1]) << "\n";

        T--;
    }

    return 0;
}