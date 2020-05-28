#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n,i,j;
	cin >> n;
	int arr[n+1] = {0};
	for(i=2;i<=n;i++){
		int tmp = i;
		for(j=2;j<=i;j++){		
			while(tmp>1){
				if(tmp%j==0){
					tmp /= j;
					arr[j]++;
				}
				else break;
			}
		}
	}
	cout << n << "! = ";
	for(i=2;i<j;i++){
		if(arr[i]!=0) cout << arr[i] << " ";
	}
	return 0;
}
