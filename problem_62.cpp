#include <bits/stdc++.h>
using namespace std;

vector<int> merge_sort(vector<int>& v){

	if(v.size()==1)
		return v;
	else{
		int v_size = v.size();
		vector<int> left;
		vector<int> right;
		
		for(int i=0;i<v_size;i++){
			if(i<v_size/2) left.push_back(v[i]);
			else right.push_back(v[i]);
		}

		vector<int> sorted_left = merge_sort(left);  
		vector<int> sorted_right = merge_sort(right);

		
		/*
		1.left, right 처음 원소부터 포인터 옮겨가면서 작은수 먼저 새로운 v에 넣기 
		2.한쪽 다 넣었으면 나머지 남은것 다 넣어버리기

		*/
		int left_ptr=0, right_ptr=0;

		vector<int> sorted_v;

		while(left_ptr<sorted_left.size() && right_ptr<sorted_right.size()){
			if(sorted_left[left_ptr]>sorted_right[right_ptr]){
				sorted_v.push_back(sorted_right[right_ptr++]);
			}else{
				sorted_v.push_back(sorted_left[left_ptr++]);
			}
		}
		while(left_ptr<sorted_left.size()) sorted_v.push_back(sorted_left[left_ptr++]);
		while(right_ptr<sorted_right.size()) sorted_v.push_back(sorted_right[right_ptr++]);
		return sorted_v; 
	}

}


int main(void){

	int n,i;

	cin >> n;

	vector<int> v(n,0);

	for(i=0;i<n;i++){
		cin >> v[i];
	}

	vector<int> sorted_vector = merge_sort(v);

	for (int i : sorted_vector){
		cout << i << " ";
	}


	return 0;
}
