#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n,i,j;
	cin >> n;
	vector<int> arr(n,0);
	
	for(i=0;i<n;i++){
		cin >> arr[i];
	}

	for(i=0;i<n;i++){
		int tmp = arr[i];
		int min = tmp;
		int min_index = i; 
		for(j=i+1;j<n;j++){
			if(arr[j]<min) {
				min_index = j;
				min = arr[j];
			}

		}
		arr[i] = arr[min_index];
		arr[min_index] = tmp;
	}

	for(i=0;i<n;i++){
		cout << arr[i] << " ";
	}

	return 0;
}
