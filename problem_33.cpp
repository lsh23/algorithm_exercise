#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n,i,j;
	cin >> n;
	vector<int> v(n,0);
	for(i=0;i<n;i++){
		cin >> v[i];
	}
	for(i=0;i<n;i++){
		int max_index = i;
		for(j=i+1;j<n;j++){
			if(v[max_index]<v[j]){
				max_index = j;
			}
		}
		int tmp = v[i];
		v[i] = v[max_index];
		v[max_index] = tmp; 
	}

	int rank = 0;
	int prev_score = -1;
	for(i=0;i<n;i++){
		if(prev_score==v[i]) continue;
		else{
			rank++;
			prev_score = v[i];
		}
		if(rank==3) break;
	}

	cout << v[i];
	return 0;
}
