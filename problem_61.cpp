#include <bits/stdc++.h>
using namespace std;

int answer = 0;

void subset(int i,vector<int>& option,vector<int>& v,int m){
	
	if(i==v.size()){
		int j;
		int sum = 0;
		for(j=0;j<v.size();j++){
			if(option[j]==0) sum +=v[j];
			if(option[j]==1) sum -=v[j];
		}
		if(sum == m) answer++;
		return;
	}

	option[i] = 0;
	subset(i+1,option,v,m);

	option[i] = 1;
	subset(i+1,option,v,m);

	option[i] = 2;
	subset(i+1,option,v,m);
}


int main(void){

	int n,m,i;

	cin >> n >> m;

	vector<int> v(n,0);
	vector<int> option(n,0);

	for(i=0;i<n;i++){
		cin >> v[i];
	}

	subset(0,option,v,m);	 

	cout << answer;

	return 0;
}
