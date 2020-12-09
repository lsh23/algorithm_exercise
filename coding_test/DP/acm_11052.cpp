#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){

    int n;
    cin >> n;

    vector<int> costs(n+1,0);

    for(int i=1;i<=n;i++){
        int p_i;
        cin >> p_i;
        for(int j=i;j<=n;j++){
            costs[j] = max(costs[j],costs[j-i]+p_i);
        }
    }

    cout << costs[n];

    return 0;
}