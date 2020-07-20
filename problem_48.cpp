#include <bits/stdc++.h>
using namespace std;

int main(void){

	int i,j;
	vector<vector<int>> board(9, vector<int>(9,0));
	for(i=0;i<9;i++){
		int sum = 0;
		for(j=0;j<9;j++){
			cin >> board[i][j];
			sum += board[i][j];
		}
		int average = round(sum/9.0);
		int diff = abs(average-board[i][0]);
		int nearst_with_avg = board[i][0];
		for(j=1;j<9;j++){
			int cur_diff = abs(average-board[i][j]);
			if(cur_diff<diff){
				diff = cur_diff;
				nearst_with_avg = board[i][j];
			}
			if(cur_diff==diff){
				diff = cur_diff;
				nearst_with_avg = nearst_with_avg>board[i][j]? nearst_with_avg:board[i][j];
			}
		}
		cout << average << " " << nearst_with_avg << "\n";
	}

	return 0;
}
