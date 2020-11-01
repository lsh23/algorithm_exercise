#include<bits/stdc++.h>
using namespace std;

struct p_s_max{
	bool operator()(pair<int,int> a,pair<int,int> b){
		return a.second < b.second;
	}
};

int main(void){

    int n;
    cin >> n;

    vector<pair<int,int>> v(n+1);
    for(int i=1;i<=n;i++){
        int t,p;
        cin >> t >> p;
        v[i] = make_pair(t,p);
    }

    int answer = 0;
    for(int i=1;i<=n;i++){
        int day = i;
        int sum = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,p_s_max> p_q(v.begin()+i,v.end());
        while(true){
            if(day>n) break;
            int next_day = day + v[day].first;
            if(next_day>n+1) break;
            sum += v[day].second;
            day=next_day;
        }
        answer = answer > sum ? answer : sum;
    }

    cout << answer;
    return 0;
}