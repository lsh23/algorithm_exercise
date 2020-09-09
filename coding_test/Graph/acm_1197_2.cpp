#include<bits/stdc++.h>

using namespace std;

int my_find(vector<int> &v,int a){
    if(v[a]!=a){
        return v[a]=my_find(v,v[a]);
    }else{
        return a;
    }
}

void my_union(vector<int> &v,int a,int b){

    a = my_find(v,a);
    b = my_find(v,b);
    if(a!=b){
        v[b] = a;
    }

}


struct Edge{
    int from;
    int to;
    int weight;
    Edge(int a,int b,int c){
        from = a;
        to = b;
        weight = c;
    }
    bool operator<(const Edge &edge)const{
        return weight < edge.weight;
    }
};

int main(void){

    int v,e;

    cin >> v >> e;
    vector<Edge> edges;
    for(int i=0;i<e;i++){
        int from,to,weight;
        cin >> from >> to >> weight;
        edges.push_back(Edge(from,to,weight));
    }

    sort(edges.begin(),edges.end());

    vector<int> u(v+1,0);
    for(int i=1;i<=v;i++){
        u[i] = i;
    }

    int answer = 0;

    for (Edge edge : edges){
        int from = edge.from;
        int to = edge.to;
        int weight = edge.weight;
        if(my_find(u,from)!=my_find(u,to)){
            // cout << "from : " << from << " to : " << to << " weight : " << weight << "\n";
            answer += weight;
            my_union(u,from,to);
        }

    }

    cout << answer;

    return 0;
}