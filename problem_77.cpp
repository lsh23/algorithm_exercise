#include <bits/stdc++.h>
using namespace std;

int find(int x,vector<int>& students){
	if(students[x] == x){
		return x;
	}else{
		return find(students[x],students);
	}
}

void union_ (int x,int y,vector<int>& students){
	int x_root = find(x,students);
	int y_root = find(y,students);
	
	students[y_root] = x_root;
}

int main(void){

	int n,m;

	cin >> n >> m;

	vector<int> students(n+1,0);
	for(int i=1;i<=n;i++){
		students[i]=i;
	}

	for(int i=0;i<m;i++){
		int st_1,st_2;
		cin >> st_1 >> st_2;
		union_(st_1,st_2,students);
	}

	int st_1,st_2;
	cin >> st_1 >> st_2;
	if(find(st_1,students)==find(st_2,students)) cout << "YES";
	else cout << "NO";


	return 0;
}
