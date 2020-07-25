#include <bits/stdc++.h>
using namespace std;

int main(void){

	string input;
	getline(cin,input);

	int count = 0;
	for (char braket : input) {
		if(braket==')') {
			count--;
			if(count<0) break;
		}
		if(braket=='(') count++;

	}

	if(count==0){
		cout << "YES";
	}else{
		cout << "NO";
	}


	return 0;
}
