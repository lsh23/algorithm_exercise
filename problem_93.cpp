#include<bits/stdc++.h>
using namespace std;


int main(void){

	int n;

	cin >> n;

	vector<int> dp(47,0);

	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=46;i++){
		dp[i] = dp[i-2] + dp[i-1];
	}

	cout << dp[n+1];

	return 0;
}