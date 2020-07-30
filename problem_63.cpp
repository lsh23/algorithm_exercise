#include <bits/stdc++.h>
using namespace std;


int main(void){

	int n,m;

	cin >> n >> m;

	vector<vector<int>> adjacent(n, vector<int>(n,0));

	for(int k=0; k<m; k++){
		int i,j,weight;
		cin >> i >> j >> weight;
		adjacent[i-1][j-1] = weight;
	}

	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout << adjacent[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
