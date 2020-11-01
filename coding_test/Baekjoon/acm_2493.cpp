#include<bits/stdc++.h>
using namespace std;

int main(void){

    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> st;
    vector<int> answer(n+1,0);
    long long cnt_zero = 0;

    for(int i=1;i<=n;i++){
        int input;
        cin >> input;
        int cnt = 0;
        while(!st.empty()){
            if(st.back()<input){
                st.pop_back();
                cnt++;
            }else break;
        }
        if(st.empty()) {
            answer[i] = 0;
            cnt_zero++;
        }
        else answer[i] = (i-1 - cnt);
        st.push_back(input);
    }

    if(cnt_zero == n) cout << 0;
    else{
        for(int i=1;i<=n;i++){
            cout << answer[i] << " ";
        }
    }

    return 0;
}