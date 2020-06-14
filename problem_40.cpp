#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n,m,i;
	cin >> n;
	vector<int> v1(n,0);
	for(i=0;i<n;i++){
		cin >> v1[i];
	}
	cin >> m;
	vector<int> v2(m,0);
	for(i=0;i<m;i++){
		cin >> v2[i];
	}

	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());

	vector<int> ans;
	int ptr_1 = 0;
	int ptr_2 = 0;
	while(ptr_1 < n && ptr_2 < m){
		if(v1[ptr_1]>v2[ptr_2]){
			ptr_2++;
		}
		else if(v1[ptr_1]<v2[ptr_2]){
			ptr_1++;
		}else{
			ans.push_back(v1[ptr_1]);
			ptr_1++;
			ptr_2++;
		}
	}

	for (auto x : ans){
		cout << x << " ";
	}

	return 0;
}
