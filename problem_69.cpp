#include <bits/stdc++.h>
using namespace std;

class My_queue{
private:
	
	int front = -1;
	int back = -1;
	vector<int> q;
	
public:
	
	bool is_empty();
	void push(int x);
	int pop();

	My_queue(){
		q = vector<int> (10);
	}
	
};

	bool My_queue::is_empty(){
		return q.size() == 0;
	}

	void My_queue::push(int x){
		q[++back]=x;
	}

	int My_queue::pop(){
		return q[front++];
	}


int main(void){


	int m = 6;

	My_queue q;
	q.push(1);

	vector<vector<int>> tree (8);
	for(int k=1; k<=m; k++){
		int i,j;
		cin >> i >> j;
		tree[i].push_back(j);
	}

	cout << 1 << " ";
	for(int i=1; i<=7 ;i++){
		for(int j=0;j<tree[i].size(); j++){
			if(tree[i][j]!=1)
				cout << tree[i][j] << " ";
		}
	}

	return 0;
}
