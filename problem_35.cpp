#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n,i,j,k;
	cin >> n;
	vector<int> v(n,0);
	for(i=0;i<n;i++){
		cin >> v[i];
	}
	int negative_index = 0;
	for(i=0;i<n;i++){
		int tmp = v[i];
		for(j=i;j<n;j++){
			if(v[j]<0) {
				v[i] = v[j];
				for(k=i;k<j;k++){
					int tmp_2 = v[k+1];	
					v[k+1] = tmp;
					tmp = tmp_2;
				}
				break;
			}
		}
	}

	for(i=0;i<n;i++){
		cout << v[i] << " ";
	}
	return 0;
}
