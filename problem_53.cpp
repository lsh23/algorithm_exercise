#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n,k,i;
	cin >> n >> k;

	vector<int> st;

	while(n>0){
		int remainder = n % k;
		st.push_back(remainder);
		n /= k;
	}

	int digit_n = st.size();

	for(i=0;i<digit_n;i++){
		if(k==16){
			int remainder = st.back();
			if(remainder>9){
				char hexa = 'A' + (remainder-10);
				cout << hexa;
			} 
			else cout << remainder;
			st.pop_back();
		}else{
			cout << st.back();
			st.pop_back();
		}
	}

	return 0;
}
