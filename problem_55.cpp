#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n,i;

	cin >> n;
	
	vector<int> train_order(n,0);
	vector<int> st;
	for(i=0;i<n;i++){
		cin >> train_order[i];
	}

	// top이 지금 나가야 하는 숫자가 아니면 P 맞으면 O

	int top = 1;
	bool is_impossible = false;
	string answer = "P";
	i = 1;
	st.push_back(train_order[0]);

	while(top <= n){

		if(st.back() != top){
			answer += "P";
			if(st.back()<train_order[i]){
				is_impossible = true;
				break;
			}
			st.push_back(train_order[i]);
			i++;
		}else{
			answer += "O";
			st.pop_back();
			top++;
		}
	}

	if(is_impossible){
		cout <<"impossible";
	}else{
		cout << answer;
	}


	return 0;
}
