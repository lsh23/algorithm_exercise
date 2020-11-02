#include <string>
#include <iostream>
#include <vector>

using namespace std;

int next_i(int n,int i,vector<int> &visited, string init_str , string name,int &left_right_cnt){
    for(int j=0;j<n;j++){
        int next_right_i = (i+j)%n;
        int next_left_i = (i-j+n)%n;
        if(init_str[next_right_i]!= name[next_right_i] && visited[next_right_i]==0){
            visited[next_right_i] = 1;
            left_right_cnt += j;
            return next_right_i;
        }
        if(init_str[next_left_i]!= name[next_left_i] && visited[next_left_i]==0){
            visited[next_left_i] = 1;
            left_right_cnt += j;
            return next_left_i;
        }
    }
    return -1;
}


int solution(string name) {
    int answer = 0;
    int n = name.length();
    string init_str = "";
    for(int i=0;i<n;i++){
        init_str += "A";
    }
    // ABCDEFGHIJKLMNOPQRSTUVWXYZ
    // 01234567890123456789012345
    //              3210987654321
    
    int up_down_cnt = 0;
    int left_right_cnt = 0;
    vector<int> visited(n,0);
    int i = 0;
    
    while(i!=-1){
        i = next_i(n,i,visited,init_str,name,left_right_cnt);
        int diff = abs(init_str[i] - name[i]);
        if(diff>13) diff = 26-diff;
        up_down_cnt += diff;
    }
    
    answer = up_down_cnt + left_right_cnt;
    return answer;
}