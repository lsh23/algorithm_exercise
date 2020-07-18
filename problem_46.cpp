#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n,k,i;
	cin >> n;
	vector<int> v(n,0);
	for(i=0;i<n;i++){
		cin >> v[i];
	}
	cin >> k;
	
	int count = 0;
	i=0;
	while(count<k){
		if(v[i]>0){
			v[i]--;
			count++;
		}
		i++;
		i = i % n;
	}

	// count 0     1     	 	2        3          3         3        4       4      4      5
	// i	  0     1           2        0          1         2        0       1      2      0
	// v [1,2,3]  [0,2,3]    [0,1,3]   [0,1,2]  [0,1,2]   [0,0,2]  [0,0,1] [0,0,1] [0,0,1] [0,0,0]
	count = 0;
	while(v[i]==0 && count<n){
		i++;
		count++;
		i = i % n;
	}

	if(count==n){
		cout << -1;
	}else{
		cout << i+1;
	}

	return 0;
}
