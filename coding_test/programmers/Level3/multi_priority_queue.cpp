#include <string>
#include <vector>
#include <queue>
#include <iostream>

//https://programmers.co.kr/learn/courses/30/lessons/42628

using namespace std;

vector<int> solution(vector<string> operations) {
    
    vector<int> answer;
    
    priority_queue<int> p_q;
    
    for(string operation : operations){
        int len = operation.length();
        string command = operation.substr(0,1);
        string number = operation.substr(2,len-2);
        int i_number = stoi(number);
        
        if(command == "I"){
            p_q.push(i_number);
        }
        if(command == "D"){
            if(i_number == 1){
                if(!p_q.empty()) p_q.pop();
            }
            if(i_number == -1){
                priority_queue<int> tmp;
                if(!p_q.empty()){
                    while(p_q.size()!=1){
                        tmp.push(p_q.top());
                        p_q.pop();
                    }
                }
                p_q = tmp;
            }
        }
    }
    
    if(p_q.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(p_q.top());
        while(p_q.size()!=1){
            p_q.pop();
        }
        answer.push_back(p_q.top());
    }
    
    return answer;
}