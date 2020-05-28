#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n,i,j;
	cin >> n;
	int prime[1001] = {0};
	for(i=2;i<=1000;i++){
		bool isPrime = true;
		if(prime[i]>=1) continue;
		for(j=2;j<=sqrt(i);j++){
			if(i%j==0) {
				prime[i]++;
				isPrime=false;
				break;
			}
		}
		if(isPrime){
			int k;
			for(k=2;k*i<=n;k++){
				prime[k*i]++;
			}
		}
	}

	int cnt[n+1] = {0};
	int end_point = 2;

	for(j=2;j<=1000;j++){
		if(prime[j]==0){
			for(int k=j;k<=n;){
				cnt[j] += n/k;
				k *=j;
				end_point = j;
			}	
			if(j==n) {
				break;
			}
		}
	}
	
	cout << n <<"! = " << " ";
	for(i=2;i<=end_point;i++){
		if(prime[i]==0) cout << cnt[i] << " ";
	}

}
