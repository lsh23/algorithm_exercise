#include<bits/stdc++.h>
using namespace std;


vector<int> DP(46,0);

int dinamic_programming(vector<int> &DP,int i){
	if(i==1){
		return 1;
	}
	if(i==2){
		return 2;
	}
	if(DP[i]!=0){
		return DP[i];
	}else{
		return DP[i] = dinamic_programming(DP,i-1) + dinamic_programming(DP,i-2); 
	}
}


int main(void){

	int n;

	cin >> n;	


	DP[1] = 1;
	DP[2] = 2;

	dinamic_programming(DP,n);

	cout << DP[n];
	
	return 0;
}