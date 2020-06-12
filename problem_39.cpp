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

	vector<int> ans;
	int ptr_1 = 0;
	int ptr_2 = 0;
	while(ans.size() != n+m){
		if(v1[ptr_1]<=v2[ptr_2]){
			ans.push_back(v1[ptr_1++]);
			if(ptr_1==n){
				for(i=ptr_2;i<m;i++){
					ans.push_back(v2[i]);
				}
			}
		}else{
			ans.push_back(v2[ptr_2++]);
			if(ptr_2==m){
				for(i=ptr_1;i<n;i++){
					ans.push_back(v1[i]);
				}
			}
		}
	}

	for(auto k : ans){
		cout << k << " ";
	}

	return 0;
}
