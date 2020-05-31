#include <bits/stdc++.h>
using namespace std;

int main(void){

	string input;
	getline(cin, input);
	int a,b;
	int i;

	int c_index = 0;
	int h_index = 0;
	
	for(i=0;i<input.length();i++){
		if(input[i]=='C') c_index = i;
		if(input[i]=='H') h_index = i;
	}

	if(h_index - c_index == 1) a = 1;
	else a = stoi(input.substr(c_index+1,h_index));
	if(h_index == input.length()-1) b = 1;
	else b = stoi(input.substr(h_index+1,input.length()));

	int ans = a*12 + b*1;
	cout << ans;

	return 0;
}
