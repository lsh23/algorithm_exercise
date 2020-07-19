#include <bits/stdc++.h>
using namespace std;


bool is_top(int i,int j, vector<vector<int>> &map,int n){
	int up = (i-1)>=0? i-1:-1;
	int down = (i+1)<n? i+1:-1;
	int left = (j-1)>=0? j-1:-1;
	int right = (j+1)<n? j+1:-1;
	bool is_top = true;
	if(up!=-1){
		if(map[up][j]>=map[i][j]) is_top = false;
	}
	if(down!=-1){
		if(map[down][j]>=map[i][j]) is_top = false;
	}
	if(left!=-1){
		if(map[i][left]>=map[i][j]) is_top = false;
	}
	if(right!=-1){
		if(map[i][right]>=map[i][j]) is_top = false;
	}
	return is_top;	
}

int main(void){

	int n,i,j;
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n,0));
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin >> map[i][j];
		}
	}
	int answer = 0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(is_top(i,j,map,n)){
				answer++;
			}
		}
	}
	cout << answer;
	return 0;
}
