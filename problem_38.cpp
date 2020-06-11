#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n,i,j;
	cin >> n;
	vector<int> v(n,0);
	for(i=0;i<n;i++){
		cin >> v[i];
	}

	vector<int> ans(n,0);
	for(i=0;i<n;i++){
		int cnt = 0;
		int cnt_2 = 0;
		if(v[i]==0){
			for(j=0;j<n;j++){
				if(ans[j]==0){
					ans[j]=i+1;
					break;
				} 
			}
		}
		else{
			for(j=0;j<v[i]+i;j++){
				if(cnt_2 == v[i] && ans[j]== 0){
					ans[j] = i+1;
					break;
				} 
				if(ans[j] != 0 && ans[j] < i+1) cnt++;
				if(ans[j] == 0 )cnt_2++;

			}
			if(j==v[i]+i) ans[v[i]+cnt]=i+1;
		}
	}
	
	for(i=0;i<n;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
