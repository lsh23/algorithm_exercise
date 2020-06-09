#include <bits/stdc++.h>
using namespace std;

int main(void){

	int s,n,i,j;
	cin >> s >> n;

	deque<int> cache;

	int work;
	cin >> work;
	cache.push_front(work);


	for(i=1;i<n;i++){
		int work;
		cin >> work;

		//if cache miss
		bool cache_miss = true;
		int cache_hit_index = -1;
		int cache_hit_work = -1;
		for(j=0;j<cache.size();j++){
			if(cache[j]==work){
				cache_miss = false;
				cache_hit_index = j;
				cache_hit_work = cache[j];
				break;
			}
		}
		if(cache_miss){
			if(cache.size()<s){
				cache.push_front(work);
			}else{
				cache.pop_back();
				cache.push_front(work);
			}
		}
		else{
			vector<int> tmp;
			for(j=0;j<cache_hit_index;j++){
				tmp.push_back(cache.front());
				cache.pop_front();
			}
			cache.pop_front();
			for(j=tmp.size()-1;j>=0;j--){
				cache.push_front(tmp[j]);
			}
			cache.push_front(cache_hit_work);
		}
	}

	for(i=0;i<s;i++){
		cout << cache[i] << " ";
	}
	
	return 0;
}
