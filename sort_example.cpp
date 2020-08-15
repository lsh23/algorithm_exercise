#include <bits/stdc++.h>
using namespace std;


bool ascending(int a,int b){
	return a < b;
}


bool descending(int a,int b){
	return a > b;
}


bool ascending_first(pair<int,int> a , pair<int,int> b){
	return a.first < b.first ;
}


bool descending_first(pair<int,int> a , pair<int,int> b){
	return a.first > b.first ;
}


bool ascending_second(pair<int,int> a , pair<int,int> b){
	return a.second < b.second ;
}


bool descending_second(pair<int,int> a , pair<int,int> b){
	return a.second > b.second ;
}


struct cmp{
	bool operator()(pair<int,int> a , pair<int,int> b){
		return a.second > b.second;
	}
};

int main(void){

	vector<int> v;
	vector<pair<int,int> > v_p;

	priority_queue<int> p_q;
	priority_queue<pair<int,int>,vector<pair<int,int> >,cmp> p_q_p;

	for(int i=0;i<10;i++){
		v.push_back(rand());
		v_p.push_back(make_pair(rand(),rand()));

		p_q.push(rand());
		p_q_p.push(make_pair(rand(),rand()));
	}

	v_p.push_back(make_pair(5,4));
	v_p.push_back(make_pair(5,3));
	v_p.push_back(make_pair(4,4));
	v_p.push_back(make_pair(4,3));


	p_q_p.push(make_pair(4,4));
	p_q_p.push(make_pair(4,3));

	p_q_p.push(make_pair(5,4));
	p_q_p.push(make_pair(5,3));

	sort(v.begin(),v.end());
	sort(v_p.begin(),v_p.end(),ascending_second);

	for (int a : v){
		cout << a << " ";
	}
	cout << "\n";
	for (pair<int,int> p: v_p){
		cout << p.first << "," << p.second << " ";
	}
	cout << "\n";
	while(!p_q.empty()){
		cout << p_q.top() << " ";
		p_q.pop();
	}
	cout << "\n";
	while(!p_q_p.empty()){
		pair<int,int> top = p_q_p.top();
		cout << top.first << "," << top.second << " ";
		p_q_p.pop();
	}

	return 0;
}