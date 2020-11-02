#include<string>
#include<vector>
#include <iostream>


//https://programmers.co.kr/learn/courses/30/lessons/12909

using namespace std;

bool solution(string s)
{
    bool answer = true;

    // 여는 괄호나오면 스택에 넣고
    // 닫는 괄호나오면 스택에서 하나 뺀다
    // 뺄때 스택이 비어있으면 false
    // 다하고 스택에 여는 괄호 남아있으면 false
    
    vector<char> st;
    
    for(auto c : s){
        if(c=='('){
            st.push_back(c);
        }else{
            if(st.empty()) return false;
            else{
                st.pop_back();
            }
        }
    }

    if(!st.empty()) answer = false;
    return answer;
}