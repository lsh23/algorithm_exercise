#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n,r;

	cin >> n >> r;

	vector<long> i_factorial (n+1,0);
	i_factorial[1] = 1;
	for(int i = 2; i<=n ;i++){
		i_factorial[i] = i * i_factorial[i-1];
	}

	cout << i_factorial[n]/(i_factorial[n-r]*i_factorial[r]);


	return 0;
}
