#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,0,-1,-1,-1,0,1,1,1 };

int answer;


struct Fish {

	int x;
	int y;
	int num;
	int dir;
	bool dead;
	Fish() {}
	Fish(int a, int b, int n, int d) {
		x = a;
		y = b;
		num = n;
		dir = d;
		dead = false;
	}

	void move(vector<vector<int>> &v, vector<Fish> &v_f) {
		if (dead) return;
		for (int i = 0; i < 8; i++) {
			if (dir == 9) dir = 1;
			int next_x = x + dx[dir];
			int next_y = y + dy[dir];
			if (next_x<0 || next_x >=4 || next_y<0 || next_y >=4 || v[next_x][next_y] == -1) {
				dir++;
				continue;
			}
			if (v[next_x][next_y] == 0) {
				v[x][y] = 0;
			}
			else {
				Fish& fish = v_f[v[next_x][next_y]];
				fish.x = x;
				fish.y = y;
				v[x][y] = v_f[v[next_x][next_y]].num;
			}
			x = next_x;
			y = next_y;
			v[next_x][next_y] = num;
			break;
		}

	}

};

void DFS(vector<vector<int>> v, vector<Fish> v_f, int s_x, int s_y, int s_d, int sum,vector<int> &selected,int cnt) {

	//물고기 이동
	for (int i = 1; i <= 16; i++) {
		v_f[i].move(v, v_f);
	}

	//상어이동
	bool can_move = false;
	for (int i = 1; i <= 3; i++) {
		int next_s_x = s_x + i*dx[s_d];
		int next_s_y = s_y + i*dy[s_d];
		if (next_s_x < 0 || next_s_x >= 4 || next_s_y < 0 || next_s_y >= 4)continue;
		if (v[next_s_x][next_s_y] == 0)continue;
		//이동가능
		can_move = true;
		int next_s_d = v_f[v[next_s_x][next_s_y]].dir;
		int next_n = v_f[v[next_s_x][next_s_y]].num;
		v_f[v[next_s_x][next_s_y]].dead = true;
		v[next_s_x][next_s_y] = -1;
		v[s_x][s_y] = 0;
		selected[cnt] = next_n;
		DFS(v, v_f, next_s_x, next_s_y, next_s_d, sum + next_n, selected,cnt+1);
		v[s_x][s_y] = -1;
		v[next_s_x][next_s_y] = next_n;
		v_f[v[next_s_x][next_s_y]].dead = false;
	}
	//불가능
	if (can_move == false) {
		answer = answer > sum ? answer : sum;
		//for (auto i : selected) {
		//	cout << i << " ";
		//}
		//cout << "\n";
		return;
	}
}



int main()
{

	vector<vector<int>> v(4, vector<int>(4));
	vector<Fish> v_f(17);
	vector<int> selected(20,0);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int f_n, f_d;
			cin >> f_n >> f_d;
			v[i][j] = f_n;
			v_f[f_n] = Fish(i, j, f_n, f_d);
		}
	}
	
	int s_x = 0;
	int s_y = 0;
	int s_d = v_f[v[0][0]].dir;
	int sum = v_f[v[0][0]].num;
	v_f[v[0][0]].dead = true;
	v[0][0] = -1;
	selected[0] = sum;
	DFS(v, v_f, 0, 0,s_d,sum,selected,1);

	cout << answer;

	return 0;
}