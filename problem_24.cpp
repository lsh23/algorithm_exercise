#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n,i;
	cin >> n;
	int arr[n] = {0};
	int prev;
	cin >> prev;
	string ans = "YES";
	for(i=1;i<n;i++){
		int k;
		cin >> k;
		if(arr[abs(k-prev)]>=1){
			ans = "NO";
			break;
		}
		arr[abs(k-prev)]++;
		prev = k;		
	}
	cout << ans;
    return 0;
}
