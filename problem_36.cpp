#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n,i,j,k;
	cin >> n;
	vector<int> v(n,0);
	for(i=0;i<n;i++){
		cin >> v[i];
	}

	for(i=0;i<n-1;i++){
		for(j=i+1;j>0;j--){
			if(v[j]<v[j-1]){
				int tmp = v[j-1];
				v[j-1] = v[j];
				v[j] = tmp;
			}
			else break;
		}
	}

	for(i=0;i<n;i++){
		cout << v[i] << " ";
	}
	return 0;
}
