#include <bits/stdc++.h>
using namespace std;

int main(void){

	string n;
	int i,j;
	int ans = 0;
	int mul = 1;
	getline(cin,n);
	string tmp = "";
	for(i=n.length()-1;i>0;i--){
		int digit_of_index = n[i]-'0';

		if(3<digit_of_index){
			ans += mul * (1 + stoi(n.substr(0,i)));
			mul *= 10;
			tmp = n[i] + tmp;
		}
		else if(3==digit_of_index){
			ans += mul * (stoi(n.substr(0,i)));
			ans += stoi(tmp)+1;
			tmp = n[i] + tmp;  
			mul *= 10;
		}
		else{
			ans += mul * (stoi(n.substr(0,i)));
			mul *= 10;
			tmp = n[i] + tmp;
		}

	}
	if (n[i]-'0' == 3){
		ans += stoi(tmp)+1;
	}
	if( n[i]-'0' > 3){
		ans += mul;
	}
	cout << ans;


	return 0;
}
