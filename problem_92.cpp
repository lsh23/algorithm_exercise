#include<bits/stdc++.h>
using namespace std;

int DP(int n,vector<int> &dp){
	if(n==1) return 1;
	if(n==2) return 2;
	if(dp[n]!=0) return dp[n];
	else{
		return dp[n] = DP(n-1,dp) + DP(n-2,dp);
	}
}

int main(void){

	// 계단 오르기 top-down

	int n;

	cin >> n;

	vector<int> dp(46,0);
	dp[1] = 1;
	dp[2] = 2;
	
	DP(n,dp);

	cout << dp[n];
	return 0;
}