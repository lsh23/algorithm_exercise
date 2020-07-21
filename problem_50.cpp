#include <bits/stdc++.h>
using namespace std;

int main(void){
	int h,w,i,j;
	cin >> h >> w;

	vector<vector<int>> teritory(h, vector<int>(w,0));
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			cin >> teritory[i][j];
		}
	}

	int h_info, w_info;
	cin >> h_info >> w_info;
	int max = 0;


	for(i=0;i<=h-h_info;i++){
		for(j=0;j<=w-w_info;j++){
			int sum = 0;
			for(int k=i;k<i+h_info;k++){
				for(int l=j;l<j+w_info;l++){
					sum += teritory[k][l];
				}
			}
			max = max > sum ? max : sum;
		}
	}

	cout << max;

	return 0;
}
