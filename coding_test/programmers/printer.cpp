#include <string>
#include <vector>
#include <queue>
using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/42587


int solution(vector<int> priorities, int location) {
    int answer = 0;
    // 꺼내
    // 꺼내면서 현재 우선순위보다 크면 큐에 다시 넣어 
    // 없으면 인쇄
    queue<pair<int,int>> q;
    
    int i=0;
    for(auto priority : priorities){
        q.push(make_pair(priority,i++));
    }
    int order=1;
    while(!q.empty()){
        pair<int,int> front = q.front();
        int p = q.front().first;
        q.pop();
        bool print = true;
        queue<pair<int,int>> q_2 (q);
        while(!q_2.empty()){
            if(q_2.front().first>p){
                print=false;
                q.push(front);
                break;
            }
            q_2.pop();
        }
        if(print){
            if(front.second==location){
                answer = order;
                break;
            }
            order++;
        }
    }

    
    
    return answer;
}