#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(void){

    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int n,k;
        cin >> n >> k;
        vector<int> build_times(n+1,0);
        vector<int> finish_times(n+1,0);
        vector<vector<int>> graph(n+1,vector<int>(n+1,0));
        vector<int> topology(n+1,0);
        for(int j=1;j<=n;j++){
            cin >> build_times[j];
            finish_times[j] = build_times[j];
        }
        for(int j=0;j<k;j++){
            int prev,cur;
            cin >> prev >> cur;
            graph[prev][cur]=1;
            topology[cur]++;
        }
        int goal;
        cin >> goal;
        
        queue<int> q;
        for(int j=1;j<=n;j++){
            if(topology[j]==0)q.push(j);
        }

        while(!q.empty()){
            int completed = q.front();
            q.pop();
            for(int j=1;j<=n;j++){
                if(graph[completed][j]==1){
                    topology[j]--;
                    finish_times[j] = max(finish_times[j],build_times[j]+finish_times[completed]);
                    if(topology[j]==0)q.push(j);
                }
            }
        }
        cout << finish_times[goal] << "\n";
    }
    return 0;
}