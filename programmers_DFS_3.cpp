#include<bits/stdc++.h>
using namespace std;


int main(void){

	int n;

	cin >> n;

	vector<int> v(n+1,0);
	vector<int> ans(n+1,0);

	for(int i=1;i<=n;i++){
		cin >> v[i];
	}

	int max = 0;
	for(int i=n;i>=1;i--){
		ans[v[i]] = 1;
		int tmp = ans[v[i]];
		for(int j=i+1;j<=n;j++){
			if(v[i]<v[j]){
				ans[v[i]] = ans[v[i]] > (ans[v[j]] + tmp) ?  ans[v[i]] : (ans[v[j]] + tmp);
			}
		}
		max = max > ans[v[i]] ? max : ans[v[i]];
	}

	cout << max;

	return 0;
}