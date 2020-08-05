#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n,k;

	cin >> n >> k;

	// n 명을 queue에 넣는다.

	// pop 하면서 cnt 증가시키고 cnt가 k와 같아지면 push 하지 않는다. 같지 않으면 다시 큐에 push
	// queue에 원소 하나 남은 것이 정답.

	queue<int> q;

	for(int i=1;i<=n;i++){
		q.push(i);
	}

	int cnt = 0;
	while(q.size()!=1){
		int prince = q.front();
		q.pop();
		cnt++;
		if(cnt!=k){
			q.push(prince);
		}else{
			cnt = 0;
		}
	}
	
	cout << q.front();

	
	return 0;
}
