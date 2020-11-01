#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/64065

struct SubTuple{
  int size;
  vector<int> v;
  SubTuple(int a,vector<int> sub_tuple){
      size = a;
      v = sub_tuple;
  }
  bool operator<(SubTuple const &s)const{
      return size < s.size;
  }
};

vector<int> solution(string s) {
    vector<int> answer;
    int n = s.length();
    vector<int> sub_tuple;
    vector<SubTuple> sub_tuples;
    string s_n = "";
    for(int i=1;i<n-1;i++){
        if(s[i]=='{'){
            continue;
        }else if(s[i]=='}'){
            sub_tuples.push_back(SubTuple(sub_tuple.size(),sub_tuple));
            sub_tuple.clear();
        }else{
            if(s[i]!=','){
                string s_n = "";
                for(;i<n-1;i++){
                    if(s[i]==','||s[i]=='}')break;
                    s_n += s[i];
                }
                sub_tuple.push_back(stoi(s_n));
                i--;
            }
        }
        //{ 나오면 }나올때 까지 숫자 수집
        //숫자 수집다했으면 SubTuple 만들어서 Vector에 삽입
    }
    
    // Vector 정렬 - SubTuple size 오름차순
    sort(sub_tuples.begin(),sub_tuples.end());
    
    // 해쉬써서 result 만들면 됨
    map<int,int> m;
    for(auto tuple:sub_tuples){
        // cout << "{";
        for(auto i : tuple.v){
            // cout << i << " ";
            if(m.find(i)==m.end()){
                m[i]=1;
                answer.push_back(i);
            }
        }
        // cout << "}";
    }

    return answer;
}