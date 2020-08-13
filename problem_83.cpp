#include<bits/stdc++.h>
using namespace std;

int send(vector<int> &v){
	return v[0]*1000 + v[1]*100 + v[2]*10 + v[3]*1;
}
int money(vector<int> &v){
	return v[4]*10000 + v[5]*1000 + v[2]*100 + v[1]*10 + v[6]*1;
}
int more(vector<int> &v){
	return v[4]*1000 + v[5]*100 + v[6]*10 + v[1]*1;
}

void DFS(vector<int> &v, vector<int> &visited,int cnt){
	if(cnt==8){
		if(send(v) + more(v) == money(v)){
			cout << "  " << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << "\n";
			cout << "+ "<< v[4] << " " << v[5] << " " << v[6] << " " << v[1] << "\n";
			cout << "---------\n";
			cout << v[4] << " " << v[5] << " " << v[2] << " " << v[1] << " " << v[6] << "\n";
			return;
		}
	}
	else{
		for(int i=0;i<=9;i++){
			if(visited[i]==0){
				visited[i]=1;
				v[cnt] = i;
				DFS(v,visited,cnt+1);
				visited[i]=0;
			}
		}
	}
}

int main(void){

	vector<int> v(7,0); //sendmory
	vector<int> visited(10,0);

	DFS(v,visited,0);

	return 0;
}