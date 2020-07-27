#include <bits/stdc++.h>
using namespace std;

void subset(int i, vector<int>& visited){


	int j;
	if(i==visited.size()){
		for(j=0;j<visited.size();j++){
			if(visited[j]==0) cout << j+1 << " ";
		}
		cout << "\n";
		return;
	}
	
	visited[i]=0;
	subset(i+1,visited);

	visited[i]=1;
	subset(i+1,visited);

}


int main(void){

	int n;
	
	cin >> n;

	vector<int> visited(n,0);

	
	subset(0,visited);
	
	return 0;
}
