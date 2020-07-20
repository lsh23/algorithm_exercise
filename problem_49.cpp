#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n,i,j;
	cin >> n;

	vector<int> front_height (n,0);
	vector<int> right_side_height (n,0);
	vector<vector<int>> block(n, vector<int>(n,0));

	for(i=0;i<n;i++){
		cin >> front_height[i];
	}
	for(i=0;i<n;i++){
		cin >> right_side_height[i];
	}

	for(i=0;i<n;i++){
		int i_th_max_height = right_side_height[i];
		for(j=0;j<n;j++){
			if(i_th_max_height==0) break;
			if(front_height[j]>i_th_max_height){
				block[i][j]=i_th_max_height;
			}else{
				block[i][j]=front_height[j]==0? 0:front_height[j];
			}
		}	 
	}

	int answer = 0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			answer += block[i][j];
		}
	}

	cout << answer;

	return 0;
}
