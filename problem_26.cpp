#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n,i,j;
	cin >> n;
	int arr[n];
	int rank[n];
	for(i=0;i<n;i++){
		cin >> arr[i];
		rank[i] = i+1;
	}
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			if(arr[i]>arr[j]) rank[i]--;
		}
	}
	for(i=0;i<n;i++){
		cout << rank[i] << " ";
	}
    return 0;
}
