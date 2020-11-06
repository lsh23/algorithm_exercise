#include <string>
#include <vector>

using namespace std;

string binary(int n){
    
    if(n==1) return "1";
    
    return binary(n/2) + to_string(n%2);
    
}

int get_one_cnt(int n){
    
    string binary_n = binary(n);
    int cnt = 0;
    for(auto i : binary_n){
        if(i=='1') cnt++;
    }
    return cnt;
    
}


int solution(int n) {
    int answer = 0;

    int n_one_cnt = get_one_cnt(n);
    
    bool find_next_number = false;
    
    int next_n = n+1;
    while(find_next_number == false){
        if(n_one_cnt == get_one_cnt(next_n)){
            answer = next_n;
            break;
        }
        next_n++;
    }
    
    return answer;
}