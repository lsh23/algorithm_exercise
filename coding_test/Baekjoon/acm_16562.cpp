#include<iostream>
#include<vector>
#include<set>

using namespace std;

int find(vector<int> &friends,int v){
    if(friends[v]==v) return v;
    else return friends[v] = find(friends,friends[v]);
}

void my_union(vector<int> &friends, int v,int w){
    int v_p = find(friends,v);
    int w_p = find(friends,w);
    if(v_p!=w_p) friends[v_p] = w_p;
}


int main(void){

    int n,m,k;
    int total = 0;
    cin >> n >> m >> k;

    vector<int> friends(n+1,0);
    vector<int> costs(n+1,0);
    vector<int> min_costs(n+1,INT32_MAX);
    for(int i=1;i<=n;i++){
        friends[i]=i;
        cin >> costs[i];
    }
    for(int i=0;i<m;i++){
        int v,w;
        cin >> v >> w;
        my_union(friends,v,w);
    }

    for(int i=1;i<=n;i++){
        friends[i] = find(friends,i);
    }

    set<int> friend_p;
    for(int i=1;i<=n;i++){
        friend_p.insert(friends[i]);
    }

    for(auto p : friend_p){
        int min = INT32_MAX;
        for(int i=1;i<=n;i++){
            if(friends[i]==p){
                min = min < costs[i] ? min : costs[i];
            }
        }
        total += min;
    }


    if(total>k) cout << "Oh no";
    else cout << total;

    return 0;
}