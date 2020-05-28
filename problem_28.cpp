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
	int ans = arr[2]>arr[5]? arr[5]:arr[2];
	cout << ans;
}
