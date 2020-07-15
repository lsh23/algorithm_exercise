#include <bits/stdc++.h>
using namespace std;

int how_many_can_record_n_dvd(vector<int> v, int size){
	int sum = 0;
	int count = 0;
	for(int i=0; i<v.size();i++){
		sum += v[i];
		if(sum>size){
			sum = v[i];
			count++;
		}
	}
	return count+1;
}

int main(void){

	int n,m,i,j;
	cin >> n >> m;
	int sum = 0;
	vector<int> v(n,0);
	for(i=0;i<n;i++){
		cin >> v[i];
		sum += v[i];
	}
	int l = 0;
	int r = sum;
	int answer = sum;
	while (l<=r){
		int mid = (l+r)/2;
		if(m>=how_many_can_record_n_dvd(v,mid)){
			answer = mid;
			r = mid-1;
		}else{
			l = mid+1;
		}
	}
	cout << answer;

	return 0;
}
