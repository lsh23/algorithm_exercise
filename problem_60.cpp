#include <bits/stdc++.h>
using namespace std;

bool subset(int i, vector<int>& visited, vector<int>& input){

	if(i==visited.size()){
		int j = 0;
		int subset_sum_1 = 0;
		int subset_sum_2 = 0;
		for(j=0;j<visited.size();j++){
			if(visited[j]) subset_sum_1 += input[j];
			else subset_sum_2 += input[j];
		}
		return subset_sum_1 == subset_sum_2;
	}

	visited[i] = 1;
	bool subset_1 = subset(i+1,visited,input);

	
	visited[i] = 0;
	bool subset_2 = subset(i+1,visited,input);

	return subset_1 || subset_2;

}


int main(void){

	int n,i;
	
	cin >> n;

	vector<int> visited(n,0);
	
	vector<int> input(n,0);
	

	for(i=0;i<n;i++){
		cin >> input[i];
	}
	
	if(subset(0,visited,input)){
		cout << "YES";
	}else{
		cout << "NO";
	}
	
	return 0;
}
