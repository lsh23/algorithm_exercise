#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

//https://programmers.co.kr/learn/courses/30/lessons/42627

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = jobs.size();
    int sum = 0;
    int time = 0;
    sort(jobs.begin(),jobs.end());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p_q;

    int push_cnt=0;
    int pop_cnt=0;
    while(pop_cnt<n){
        int request_time = jobs[push_cnt][0];
        int spending_time = jobs[push_cnt][1];
            
        // 현재시간에 실행할수있는 요청을 모음  
        if( push_cnt<n && time>=request_time){
            p_q.push(make_pair(spending_time,request_time));
            push_cnt++;
            continue;
        }
            
        // 모여있는 요청 수행, 짧은 수행시간 우선순위로   
        if(!p_q.empty()){
            int s_t = p_q.top().first;
            int r_t = p_q.top().second;
            p_q.pop();
            sum += (time-r_t) + s_t;
            time += s_t;
            pop_cnt++;
        }else{
        // 요청은 남아있는데 현재 시간에 처리할 수 있는 요청을 의미하는 큐가 비어있다면 시간증가
            time++;
        }
    }

    answer = sum / n;
    return answer;
}