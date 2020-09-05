#include <bits/stdc++.h>
using namespace std;

bool desc_v(int a ,int b){
	return a > b;
}

bool ascend(int a, int b){
	return a < b;
}

bool first_desc_second_ascend(pair<int,int> a , pair<int,int> b){
	if(a.first == b.first){
		return a.second < b.second;
	}
	return a.first > b.first;
}

bool second_ascend(pair<int,int> a , pair<int,int> b){
	return a.second < b.second;
}

bool second_desc(pair<int,int> a , pair<int,int> b){
	return a.second > b.second;
}

struct p_s_max{
	bool operator()(pair<int,int> a,pair<int,int> b){
		return a.second < b.second;
	}
};


struct p_s_min{
	bool operator()(pair<int,int> a,pair<int,int> b){
		return a.second > b.second;
	}
};

struct Point{
	int x;
	int y;
	int dist;
	Point(int a, int b,int c){
		x=a;
		y=b;
		dist=c;
	}
	bool operator<(Point const &b)const{
		return dist > b.dist;
	}
};
// bool operator<(Point a, Point b){
// 		return a.dist < b.dist;
// }
struct point_max{
	bool operator()(Point a, Point b){
		return a.dist < b.dist;
	}
};
struct point_min{
	bool operator()(Point a, Point b){
		return a.dist > b.dist;
	}
};
int main(void){

// 	1. 1차원 벡터 정렬 오름차순
	vector<int> v = {5,4,3,2,1};
	sort(v.begin(),v.end());
	for (int i : v){
		cout << i << " ";
	}
	cout << "\n";
	vector<int> v0 = {5,4,3,2,1};
	sort(v0.begin(),v0.end(),less<int>());
	for (int i : v0){
		cout << i << " ";
	}
	cout << "\n";
	vector<int> v1 = {5,4,3,2,1};
	sort(v1.begin(),v1.end(),ascend);
	for (int i : v1){
		cout << i << " ";
	}
	cout << "\n";
// 	2. 1차원 벡터 정렬 내림차순
	vector<int> v2 = {1,2,3,4,5};
	sort(v2.begin(),v2.end(),greater<int>());
	for (int i : v2){
		cout << i << " ";
	}
	cout << "\n";
	vector<int> v3 = {1,2,3,4,5};
	sort(v3.begin(),v3.end(),desc_v);
	for (int i : v3){
		cout << i << " ";
	}
	cout << "\n";
// 	3. vector<pair<int,int>> v first 오름차순 -> second 오름차순
	vector<pair<int,int>> v4 = {make_pair(5,2),make_pair(6,7),make_pair(3,1),make_pair(4,10),make_pair(4,9)};
	sort(v4.begin(),v4.end());
	for (pair<int,int> i : v4){
		cout << "(" << i.first << " , " << i.second << ") "; 
	}
	cout << "\n";
// 	4. vector<pair<int,int>> v first 내림차순 -> second 내림차순
	vector<pair<int,int>> v5 = {make_pair(5,2),make_pair(6,7),make_pair(3,1),make_pair(4,10),make_pair(4,9)};
	sort(v5.begin(),v5.end(),greater<pair<int,int>>());
	for (pair<int,int> i : v5){
		cout << "(" << i.first << " , " << i.second << ") "; 
	}
	cout << "\n";
// 	vector<pair<int,int>> v first 내림 ->, second 오름차순
	vector<pair<int,int>> v6 = {make_pair(5,2),make_pair(6,7),make_pair(3,1),make_pair(4,10),make_pair(4,9)};
	sort(v6.begin(),v6.end(),first_desc_second_ascend);
	for (pair<int,int> i : v6){
		cout << "(" << i.first << " , " << i.second << ") "; 
	}
	cout << "\n";
// 	5. vector<pair<int,int>> v second 오름차순
	vector<pair<int,int>> v7 = {make_pair(5,2),make_pair(6,1),make_pair(3,7),make_pair(4,10),make_pair(4,9)};
	sort(v7.begin(),v7.end(),second_ascend);
	for (pair<int,int> i : v7){
		cout << "(" << i.first << " , " << i.second << ") "; 
	}
	cout << "\n";

// 	6. vector<pair<int,int>> v second 내림차순
	vector<pair<int,int>> v8 = {make_pair(5,2),make_pair(6,1),make_pair(3,7),make_pair(4,10),make_pair(4,9)};
	sort(v8.begin(),v8.end(),second_desc);
	for (pair<int,int> i : v8){
		cout << "(" << i.first << " , " << i.second << ") "; 
	}
	cout << "\n";
// 	7. prioirity_queue<int> max;
	priority_queue<int> max_heap;
	for(int i=0;i<10;i++){
		max_heap.push(i);
	}
	cout << " max_heap - top : " << max_heap.top() << "\n";
// 	8. prioirity_queue<int> min;
	priority_queue<int,vector<int>,greater<int>> min_heap;
	for(int i=0;i<10;i++){
		min_heap.push(i);
	}
	cout << " min_heap - top : " << min_heap.top() << "\n";
// 	9. prioirity_queue<pair<int,int>> frist max
	priority_queue<pair<int,int>> max_p_heap;
	for(int i=0;i<10;i++){
		max_p_heap.push(make_pair(i,9-i));
	}
	cout << " max_p_ heap - top : " << "(" << max_p_heap.top().first << " , " << max_p_heap.top().second << ")\n";
//    10. prioirity_queue<pair<int,int>> frist min
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_p_heap;
	for(int i=0;i<10;i++){
		min_p_heap.push(make_pair(i,9-i));
	}
	cout << " min_p_ heap - top : " << "(" << min_p_heap.top().first << " , " << min_p_heap.top().second << ")\n";
//    11. prioirity_queue<pair<int,int>> second max
	priority_queue<pair<int,int>,vector<pair<int,int>>,p_s_max> max_p_s_heap;
	for(int i=0;i<10;i++){
		max_p_s_heap.push(make_pair(i,9-i));
	}
	cout << " max_p_s_ heap - top : " << "(" << max_p_s_heap.top().first << " , " << max_p_s_heap.top().second << ")\n";
//    12. prioirity_queue<pair<int,int>> second min
	priority_queue<pair<int,int>,vector<pair<int,int>>,p_s_min> min_p_s_heap;
	for(int i=0;i<10;i++){
		min_p_s_heap.push(make_pair(i,9-i));
	}
	cout << " min_p_s_ heap - top : " << "(" << min_p_s_heap.top().first << " , " << min_p_s_heap.top().second << ")\n";

//    13. vector<object> object.fields 오름차순
	priority_queue<Point,vector<Point>,point_max> p_q_point_max;
	for(int i=0;i<10;i++){
		p_q_point_max.push(Point(1,1,i));
	}
	cout << " p_q_point_max - top : " << p_q_point_max.top().dist <<"\n";

//    14. vector<object> object.fields 내림차순
	priority_queue<Point,vector<Point>,point_min> p_q_point_min;
	for(int i=0;i<10;i++){
		p_q_point_min.push(Point(1,1,i));
	}
	cout << " p_q_point_min - top : " << p_q_point_min.top().dist <<"\n";

	priority_queue<Point> p_q_point_min_;
	for(int i=0;i<10;i++){
		p_q_point_min_.push(Point(1,1,i));
	}
	cout << " p_q_point_min_ - top : " << p_q_point_min_.top().dist <<"\n";

	return 0;
}

