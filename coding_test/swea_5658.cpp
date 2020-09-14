#include<bits/stdc++.h>
using namespace std;

int main(void){

    // 적힌 숫자로 만들 수 있는 모든 수 중, K번째로 큰 수를 10진수로 만든 수
    int n,k;
    string input;
    cin >> n >> k;
    // getline(cin,input);
    cin >> input;
    
    deque<char> d_q;
    set<int> s;

    for(char i : input){
        d_q.push_back(i);
    }
    
    int rotate_n = n/4;
    for(int i=0;i<rotate_n;i++){

        // n/4 개씩 짤라서 저장
        string s_hex = "";
        for(int j=0;j<n;j++){
            s_hex += d_q[j];
            if(s_hex.size()==rotate_n){
                s.insert(stoi(s_hex,nullptr,16));
                s_hex ="";
            }
        }
        d_q.push_front(d_q.back());
        d_q.pop_back();

    }

    vector<int> list (s.begin(),s.end());

    sort(list.begin(),list.end(),greater<int>());

    cout << list[k-1];

    return 0;
}