#include <string>
#include <vector>

// https://programmers.co.kr/learn/courses/30/lessons/12899

using namespace std;

string solution(int n) {
    string answer = "";
    while(n>0){
        if( n % 3 == 0){
            answer = to_string(4) + answer;
            n /= 3;
            n--;
        }else{
            answer = to_string(n%3) + answer;
            n /= 3;
        }
    }
    return answer;
}