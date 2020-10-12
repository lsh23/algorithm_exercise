#include<bits/stdc++.h>
using namespace std;

int ans_max = INT32_MIN;
int ans_min = INT32_MAX;

int calculate(vector<int> &selected,vector<int> &numbers){
    int sum = numbers[0];
    for(int i=0;i<selected.size();i++){
        if(selected[i]==0){
            sum += numbers[i+1];
        }else if(selected[i]==1){
            sum -= numbers[i+1];
        }else if(selected[i]==2){
            sum *= numbers[i+1];
        }else{
            sum /= numbers[i+1];
        }
    }
    return sum;
}


void DFS(vector<int> &numbers,vector<int> &opers,vector<int> &visited,vector<int> &selected,int cnt,int n){
    if(cnt == n-1){
        int sum = calculate(selected,numbers);
        ans_max = ans_max > sum ? ans_max : sum;
        ans_min = ans_min < sum ? ans_min : sum;
    }else{
        for(int i=0;i<4;i++){
            if(visited[i]<opers[i]){
                visited[i]++;
                selected[cnt]=i;
                DFS(numbers,opers,visited,selected,cnt+1,n);
                visited[i]--;
            }
        }
    }
}

int main(void){

    int n;
    cin >> n;

    vector<int> numbers(n,0);

    for(int i=0;i<n;i++){
        cin >> numbers[i];
    }

    vector<int> opers(4,0);
    cin >> opers[0] >> opers[1] >> opers[2] >> opers[3];

    vector<int> visited(4,0);
    vector<int> selected(n-1,0);
    DFS(numbers,opers,visited,selected,0,n);

    cout << ans_max << "\n" << ans_min;

    return 0;
}