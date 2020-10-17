#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };

struct Person {

	int start_y;
	int start_x;
	int end_y;
	int end_x;
	bool complete;
	Person(){}
	Person(int a, int b, int c, int d) {
		start_y = a;
		start_x = b;
		end_y = c;
		end_x = d;
		complete = false;
	}

};


int main()
{
	int n, m, fuel;	
	cin >> n >> m >> fuel;
	vector<vector<int>> map_info(n+1, vector<int>(n+1, 0));
	vector<Person> persons(m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map_info[i][j];
		}
	}
	int t_start_y, t_start_x;
	cin >> t_start_y >> t_start_x;
	for (int i = 0; i < m; i++) {
		int start_y, start_x,end_y,end_x;
		cin >> start_y >> start_x >> end_y >> end_x;
		persons[i] = Person(start_y, start_x, end_y, end_x);
	}


	//승객은 스스로 움직이지 않으며, 출발지에서만 택시에 탈 수 있고, 목적지에서만 택시에서 내릴 수 있다.
	int cnt = 0;
	while (true) {
		queue<pair<int, int>> q;
		q.push(make_pair(t_start_y, t_start_x));
		vector<vector<int>> dist(n+1, vector<int>(n+1, INT32_MAX));
		dist[t_start_y][t_start_x] = 0;
		//현재 택시위치에서 가장 가까운 승객 고르기
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			int d = dist[y][x];
			q.pop();
			for (int i = 0; i < 4; i++) {
				int next_y = y + dy[i];
				int next_x = x + dx[i];
				if (next_x < 1 || next_x > n || next_y < 1 || next_y > n) continue;
				if (map_info[next_y][next_x] == 1)continue;
				if (dist[next_y][next_x] > d + 1) {
					dist[next_y][next_x] = d + 1;
					q.push(make_pair(next_y, next_x));
				}
			}
		}
		int dist_min = INT32_MAX;
		int dist_min_i = INT32_MAX;
		for (int i = 0; i < m; i++) {
			if (persons[i].complete) continue;
			int dist_i = dist[persons[i].start_y][persons[i].start_x];
			if (dist_i == INT32_MAX) continue;
			if (dist_min > dist_i) {
				dist_min = dist_i;
				dist_min_i = i;
			}
			if (dist_min == dist_i) {
				if (persons[dist_min_i].start_y == persons[i].start_y) {
					if (persons[dist_min_i].start_x > persons[i].start_x) {
						dist_min_i = i;
					}
				}
				else {
					if (persons[dist_min_i].start_y > persons[i].start_y) {
						dist_min_i = i;
					}
				}
			}
		}
		// 승객 태우러가기
		if (dist_min == INT32_MAX) break;
		fuel -= dist_min;
		if (fuel <= 0) break;
		
		int start_y, start_x, end_y, end_x;
		start_y = persons[dist_min_i].start_y;
		start_x = persons[dist_min_i].start_x;
		end_y = persons[dist_min_i].end_y;
		end_x = persons[dist_min_i].end_x;

		queue<pair<int, int>> q_2;
		q_2.push(make_pair(start_y,start_x));
		vector<vector<int>> dist_2(n+1, vector<int>(n+1, INT32_MAX));
		dist_2[start_y][start_x] = 0;
		while (!q_2.empty()) {
			int y = q_2.front().first;
			int x = q_2.front().second;
			int d = dist_2[y][x];
			q_2.pop();
			for (int i = 0; i < 4; i++) {
				int next_y = y + dy[i];
				int next_x = x + dx[i];
				if (next_x < 1 || next_x > n || next_y < 1 || next_y > n) continue;
				if (map_info[next_y][next_x] == 1)continue;
				if (dist_2[next_y][next_x] > d + 1) {
					dist_2[next_y][next_x] = d + 1;
					q_2.push(make_pair(next_y, next_x));
				}
			}
		}

		if (dist_2[end_y][end_x] == INT32_MAX) break;
		fuel -= dist_2[end_y][end_x];
		if (fuel < 0) break;
		//승객태우고 해당 목적기 까지가기
		else {
			fuel += dist_2[end_y][end_x] * 2;
			persons[dist_min_i].complete = true;
			t_start_y = end_y;
			t_start_x = end_x;
			cnt++;
		}
		//이동완료하면 이동하면서 쓴 연료 *2가 충전됨

		if (cnt == m) break;
		// 모든손님이동완료후 충전하고나서의 남은 연료의양
	}

	if (cnt == m) cout << fuel;
	else cout << -1;

	return 0;
}