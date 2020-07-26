#include <bits/stdc++.h>
using namespace std;


void recursive_binary(int n){
	if(n==0) return;
	else{
		recursive_binary(n/2);
		cout << n%2;
	}
}


int main(void){

	int n;

	cin >> n;

	recursive_binary(n);

	return 0;
}
