#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main(void){

    int n;
    cin >> n;

    vector<int> spending_times (n+1,0);
    vector<vector<int>> graph (n+1,vector<int>(n+1,0));
    vector<int> topology (n+1,0);
    vector<int> result (n+1,0);

    for(int i=1;i<=n;i++){
        int spending_time;
        cin >> spending_time;
        spending_times[i] = spending_time;
        while(true){
            int dependency;
            cin >> dependency;
            if(dependency == -1) break;
            graph[i][dependency]=1;
            topology[i]++;
        }
    }

    queue<int> q;

    for(int i=1;i<=n;i++){
        result[i] = spending_times[i];
        if(topology[i]==0) q.push(i);
    }

    while(!q.empty()){
        int out = q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(graph[i][out]==1){
                topology[i]--;
                result[i] = max(result[i],spending_times[i]+result[out]);
                if(topology[i]==0)q.push(i);
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout << result[i] << "\n";
    }

    return 0;
}