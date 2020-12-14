#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){

    int n;
    cin >> n;

    vector<int> serial(n,0);
    for(int i=0;i<n;i++){
        cin >> serial[i];
    }

    vector<int> DP(n,1);

    for(int i=0;i<n;i++){
        for(int j=i;j>=0;j--){
            if(serial[i] < serial[j]) DP[i] = max(DP[i],DP[j]+1);
        }
    }

    cout << *max_element(DP.begin(),DP.end());

    return 0;
}