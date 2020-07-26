#include <bits/stdc++.h>
using namespace std;


void recursive_count(int n){
	if(n==0) return;
	else{
		recursive_count(n-1);
		cout << n << " ";
	}
}


int main(void){

	int n;

	cin >> n;

	recursive_count(n);

	return 0;
}
