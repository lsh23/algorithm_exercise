#include <bits/stdc++.h>
using namespace std;

int main(void){

	priority_queue< int,vector<int>,greater<int> > p_q;
	

	while(true){
		int input;
		cin >> input;
		if(input == -1){
			break;
		}
		else if(input == 0){
			cout << p_q.top() << "\n";
			p_q.pop();
		}else{
			p_q.push(input);
		}
	}

	return 0;
}
