#include<bits/stdc++.h>
using namespace std;


vector<int> DP(46,0);

int main(void){

	int n;

	cin >> n;	


	DP[1] = 1;
	DP[2] = 2;
	for(int i=3;i<=45;i++){
		DP[i] = DP[i-1] + DP[i-2];
	}

	cout << DP[n];
	
	return 0;
}