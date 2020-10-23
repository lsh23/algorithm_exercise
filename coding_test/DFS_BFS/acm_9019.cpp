#include<bits/stdc++.h>
using namespace std;

int D(int n){
    return (n*2)%10000;
}

int S(int n){
   if(n==0) return 9999;
   return n-1; 
}


int L(int n){
    return (n*10)%10000 + n/1000;
}


int R(int n){
    return (n%10)*1000+ n/10;
}

int main(void){

    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int a,b;
        cin >> a >> b;
        queue<pair<int,string>> q;
        string command = "";
        q.push(make_pair(a,command));
        vector<int> visited(10001,0);
        visited[a] = 1;
        while(true){
            a = q.front().first;
            string com = q.front().second;
            q.pop();
            if(a==b){
                command = com;
                break;
            }
            int D_a = D(a);
            if(visited[D_a]==0){
                visited[D_a]=1;
                q.push(make_pair(D_a,com+"D"));
            }
            int S_a = S(a);
            if(visited[S_a]==0){
                visited[S_a]=1;
                q.push(make_pair(S_a,com+"S"));
            }
            int L_a = L(a);
            if(visited[L_a]==0){
                visited[L_a]=1;
                q.push(make_pair(L_a,com+"L"));
            }
            int R_a = R(a);
            if(visited[R_a]==0){
                visited[R_a]=1;
                q.push(make_pair(R_a,com+"R"));
            }
        }
        cout << command << "\n";
    }
    
    return 0;
}