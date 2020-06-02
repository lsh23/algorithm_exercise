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
		for(j=i+1;j<n;j++){
			int tmp2 = arr[j];
			if(tmp>=tmp2){
				arr[i] = tmp2;
				arr[j] = tmp;
				tmp = tmp2;
			}
		}
	}
	for(i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	return 0;
}
