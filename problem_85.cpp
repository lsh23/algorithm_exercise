#include<bits/stdc++.h>
using namespace std;

int _max = INT32_MIN;
int _min = INT32_MAX;

void DFS(vector<int> numbers, vector<int> oper, vector<int> used, vector<int>used_oper, int n, int cnt){
	if(cnt==n-1){
		int result = numbers[0];
		for(int i=0;i<used_oper.size();i++){
			if(used_oper[i]==0){
				result += numbers[i+1];
			}
			if(used_oper[i]==1){
				result -= numbers[i+1];
			}
			if(used_oper[i]==2){
				result *= numbers[i+1];
			}
			if(used_oper[i]==3){
				result /= numbers[i+1];
			}
		}
		_max = result > _max ? result : _max;
		_min = result < _min ? result : _min;
	}else{
		for(int i=0;i<4;i++){
			if(used[i]<oper[i]){
				used[i]++;
				used_oper.push_back(i);
				DFS(numbers,oper,used,used_oper,n,cnt+1);
				used_oper.pop_back();
				used[i]--;
			}
		}
	}
}


int main(void) {

	int n;

	cin >> n;

	vector<int> numbers (n,0);
	vector<int> oper (4,0);
	// oper[0] : + , oper[1] : - , oper[2] : x , oper[3] : /
	vector<int> used (4,0);
	vector<int> used_oper;

	for(int i=0;i<n;i++){
		cin >> numbers[i];
	}

	for(int i=0;i<4;i++){
		cin >> oper[i];
	}

	DFS(numbers,oper,used,used_oper,n,0);

	cout << _max << "\n";
	cout << _min ;

	return 0;
}