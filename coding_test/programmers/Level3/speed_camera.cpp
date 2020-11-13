#include <string>
#include <algorithm>
#include <vector>

//https://programmers.co.kr/learn/courses/30/lessons/42884

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    int n = routes.size();
    sort(routes.begin(),routes.end());
    int front = routes[0][1];
    for(int i=0;i<n-1;i++){
        if(routes[i][1]<front) front = routes[i][1];
        if(routes[i+1][0]>front){
            answer++;
            front = routes[i+1][1];
        }
    }
    return answer;
}