#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n,k,i;
	cin >> n >> k;

	vector<int> princess(n,0);
	for(i=0;i<n;i++){
		princess[i] = i+1;
	}
	
	int count = 0;
	i = 0;
	while(princess.size()!=1){
		count++;
		if(count==k){
			princess.erase(princess.begin()+i);
			count=0;
			continue;
		}
		i++;
		i = i % princess.size();
	}

	cout << princess[0];
	
	return 0;
}
