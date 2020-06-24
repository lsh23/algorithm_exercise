#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n,m,i;
	cin >> n >> m;

	vector<int> v(n,0);

	for(i=0;i<n;i++){
		cin >> v[i];
	}

	sort(v.begin(),v.end());

	int answer = 0;
	int left = 0;
	int right = n-1;

	while(left<=right){
		int mid = (left + right) / 2;
		if(v[mid]>m){
			right = mid-1;
		}
		else if(v[mid]<m){
			left = mid+1;
		}else{
			answer = mid+1;
			break;
		}
	}

	cout << answer;
	return 0;
}
