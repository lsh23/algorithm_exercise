#include <bits/stdc++.h>
using namespace std;

int main(void){

	int s,e;

	cin >> s >> e;

	queue<int> q;
	int position = s;
	int answer = 0;
	//앞으로 1, 뒤로 1, 앞으로 5

	int visited[10001] = {0};
	int dist[10001] = {0};
	visited[s] = 1;
	q.push(s);

	while(!q.empty()){
		int position = q.front();
		q.pop();
		if(position==e){
			answer = dist[position];
			break;
		}
		if (visited[position+1]==0){
			visited[position+1]=1;
			dist[position+1] = dist[position] + 1;
			q.push(position+1);
		}
		if (visited[position-1]==0){
			visited[position-1]=1;
			dist[position-1] = dist[position] + 1;
			q.push(position-1);
		}
		if (visited[position+5]==0){
			visited[position+5]=1;
			dist[position+5] = dist[position] + 1;
			q.push(position+5);
		}
	}



	cout << answer;

	return 0;
}
