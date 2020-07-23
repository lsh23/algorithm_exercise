#include <bits/stdc++.h>
using namespace std;

int main(void){
	int h,w,i,j;
	cin >> h >> w;

	vector<vector<int>> teritory(h+1, vector<int>(w+1,0));
	vector<vector<int>> teritory_sum(h+1, vector<int>(w+1,0));
	for(i=1;i<=h;i++){
		for(j=1;j<=w;j++){
			cin >> teritory[i][j];
			teritory_sum[i][j] += teritory[i][j] + teritory_sum[i][j-1];
		}
	}
 

	int h_info, w_info;
	cin >> h_info >> w_info;
	int max = 0;

	for(i=0;i<=h-h_info;i++){
		for(j=0;j<=w-w_info;j++){
			int sum = 0;
			for(int k=0; k<h_info;k++){
				sum += teritory_sum[i+k][j+w_info] - teritory_sum[i+k][j];
			}
			max = max > sum ? max : sum;
		}
	}

	cout << max;

	return 0;
}
