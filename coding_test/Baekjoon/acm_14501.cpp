#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){

    int n;
    cin >> n;

    vector<pair<int,int>> v(n+1);
    for(int i=1;i<=n;i++){
        int t,p;
        cin >> t >> p;
        v[i] = make_pair(t,p);
    }

    int answer = 0;
    vector<int> cost(n+2,0);

    for(int i=1;i<=n;i++){
        int t_i = v[i].first;
        int p_i = v[i].second;
        for(int j=i+t_i;j<=n+1;j++){
            cost[j] = max(cost[j],cost[i]+p_i);
        }
    }

    answer = *max_element(cost.begin(),cost.end());

    cout << answer;

    return 0;
}