#include <bits/stdc++.h>
using namespace std;

bool sort(pair<int,pair<int,int> > a ,pair<int,pair<int,int> > b){
	if(a.first<b.first) {
		return true;
	}else{
		return false;
	}
}

int find(int a,vector<int>& v){
	if(v[a]==a){
		return a;
	}else{
		return find(v[a],v);
	}
}

void _union(int a,int b,vector<int>& v){
	int a_root = find(a,v);
	int b_root = find(b,v);
	v[a_root] = b_root;
}

int main(void){

	int v,e;

	cin >> v >> e;

	vector<pair<int,pair<int,int> > > loads;
	vector<int> union_find(v+1,0);

	for(int i=1;i<=v;i++){
		union_find[i] = i;
	}

	for(int i=0;i<e;i++){
		int a,b,c;
		cin >> a >> b >> c;
		loads.push_back(make_pair(c,make_pair(a,b)));
	}

	sort(loads.begin(),loads.end());

	int cost = 0;
	int edge_count = 0;
	for(int i=0;i<e;i++){
		int a = loads[i].second.first;
		int b = loads[i].second.second;

		if(find(a,union_find)!=find(b,union_find)){
			cost += loads[i].first;
			edge_count++;
			_union(a,b,union_find);
		}
		
		if(edge_count == v-1) break;
	}

	cout << cost;

	return 0;
}
