#include<bits/stdc++.h>
using namespace std;

int _min = INT32_MAX;

int dilivery_dist(pair<int,int> home, vector<pair<int,int> > &pizza ,vector<int> &selected_pizza){
	int min_dist = INT_MAX;
	for(int k=0;k<selected_pizza.size();k++){
		int dist = abs(pizza[selected_pizza[k]].first - home.first) + abs(pizza[selected_pizza[k]].second - home.second);
		min_dist = min_dist < dist ? min_dist : dist;
	}
	return min_dist;
}


void DFS(vector<pair<int,int> > &homes, vector<pair<int,int> > &pizza, 	vector<int> &selected_pizza, int cnt,int m,int s){
	
	// m개의 피자집 선택
	if(cnt == m){
		int sum = 0;
		//각 집의 피자 배달거리구해서 sum
		for(int i=0;i<homes.size();i++){
			sum += dilivery_dist(homes[i],pizza,selected_pizza);
		}

		// for(int i : selected_pizza){
		// 	cout << i << " ";
		// }
		// cout << "\n" ;

		_min = sum < _min ? sum : _min;
	}else{
		for(int i=s;i<pizza.size();i++){
			selected_pizza[cnt] = i;
			DFS(homes,pizza,selected_pizza,cnt+1,m,i+1);
		}
	}
	
}

int main(void) {

	int n,m;

	cin >> n >> m;

	vector<pair<int,int> > homes;
	vector<pair<int,int> > pizza;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int map_info;
			cin >> map_info;
			if(map_info == 1){
				homes.push_back(make_pair(i,j));
			}
			if(map_info == 2){
				pizza.push_back(make_pair(i,j));
			}		
		}
	}

	vector<int> selected_pizza(m,0);
	
	DFS(homes,pizza,selected_pizza,0,m,0);

	cout << _min;

	return 0;
}