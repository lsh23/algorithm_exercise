#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main(void){

	int n;
	cin >> n;

	vector<vector<int>> score(n+1,vector<int>(n+1,INT32_MAX));

	for(int i=1;i<=n;i++){
		score[i][i] = 0;
	}

	while(true){
		int i,j;
		cin >> i >> j;
		if(i==-1 && j==-1)break;
		score[i][j] = 1;
		score[j][i] = 1;
	}

	vector<int> max_scores(n+1,0);

	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(score[i][k]!=INT32_MAX && score[k][j]!=INT32_MAX){
					score[i][j] = min(score[i][k]+score[k][j],score[i][j]);
				}
			}
		}
	}


	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			max_scores[i] = max(max_scores[i],score[i][j]);
		}
	}

	int min_score = *min_element(max_scores.begin()+1,max_scores.end());
	vector<int> chair_mans;
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(max_scores[i]==min_score){
			cnt++;
			chair_mans.push_back(i);
		}
	}

	cout << min_score << " " << cnt << "\n";
	for(auto chair_man : chair_mans){
		cout << chair_man << " ";
	}

	return 0;
}