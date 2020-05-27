#include <bits/stdc++.h>
using namespace std;

// bool compare_2(pair<int,int> a , pair<int,int> b){
// 	return a.second < b.second;
// }
// int main(void){
// 	int n,i;
// 	cin >> n;
// 	vector<pair<int,int>> scores;
// 	unordered_map<int,int> scores_map;
// 	for(i=0;i<n;i++){
// 		int score;
// 		cin >> score;
// 		scores.push_back(make_pair(i,score));
// 		scores_map[i]=score;
// 	}
// 	sort(scores.begin(),scores.end(),compare_2);
// 	unordered_map<int,int> order;
// 	for(i=0;i<n;i++){
// 		if(order.find(scores[i].second)==order.end()){
// 			order[scores[i].second] = n-i;
// 		}
// 		else{
// 			order[scores[i].second]--;
// 		}
// 	}
// 	for(i=0;i<n;i++){
// 		cout << order[scores_map[i]] << " ";
// 	}
//     return 0;
// }

int main(void){
	int n,i,j;
	cin >> n;
	int arr[n] = {0};
	int rank[n];
	
	for(i=0;i<n;i++){
		cin >> arr[i];
		rank[i] = 1;
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(arr[i]<arr[j]) rank[i]++;
		}
	}

	for(i=0;i<n;i++){
		cout << rank[i] << " ";
	}
	
	return 0;
}