#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n,i;
	int cnt = 0;
	cin >> n;
	for(i=1;i<=n;i++){
		int tmp = i;
		while(tmp>1){
			if(tmp%10==3){
				cnt ++;
			}
			tmp /= 10;
		}
	}
	cout << cnt;
	return 0;
}
