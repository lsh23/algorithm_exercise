#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
	int a_m = a.first;
	int b_m = b.first;

	int a_d = a.second;
	int b_d = b.second;

	if(a_d >= b_d){
		return true;
	}else{
		return false;
	}
}


int main(void){

	int n;

	cin >> n;

	// 날짜를 마지막날 부터해서
	// 해당 날에 가능한 보수를 priority queue에 넣고
	// 최대값 취하고 날을 줄여간다.

	vector<pair<int,int> > v;
	priority_queue<int> p_q;

	int end_day = 0;

	for(int i=0; i<n; i++){
		int m,d;
		cin >> m >> d;
		end_day = end_day > d ? end_day : d;
		v.push_back(make_pair(m,d));
	}

	sort(v.begin(),v.end(),cmp);

	int day = end_day;
	int money = 0;
	int i=0;
	while(day!=0){
		while(true){
			if(v[i].second < day){
				break;
			}
			p_q.push(v[i].first);
			i++;
		}
		if(!p_q.empty()){
			money += p_q.top();
			p_q.pop();
		}
		day--;
	}

	cout << money;

	return 0;
}