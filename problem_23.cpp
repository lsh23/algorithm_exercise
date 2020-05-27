#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,i;
	cin >> n;
	int prev = 0;
	int max = 0;
	int cnt = 0;
	for(i=0;i<n;i++){
		int k;
		cin >> k;
		if(k>=prev){
			cnt++;
		}else{
			cnt = 1;
		}
		prev = k;
		if(cnt>max) max = cnt;
	}
	cout << max;
    return 0;
}
