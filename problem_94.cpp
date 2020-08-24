#include<bits/stdc++.h>
using namespace std;


int main(void){

	int n;
	cin >> n;

	vector<int> v (n,0);

	for(int i=0; i<n; i++){
		cin >> v[i];
	} 

	// 2일때
	// for 2 다음부터 돌면서 2보다 크면
	
	vector<int> m (n,0);
	int max = 0;

	for(int i=n-1;i>=0;i--){
		int tmp = v[i];
		m[i] = 1;
		int m_i = m[i];
		for(int j=i+1;j<n;j++){
			if(v[j]>tmp){
				m[i] = m[i] > m_i + m[j] ? m[i] : m_i + m[j];
			}
		}
		max = max > m[i] ? max : m[i];
	}

	cout << max;

	return 0;
}