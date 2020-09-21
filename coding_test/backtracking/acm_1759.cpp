#include<bits/stdc++.h>
using namespace std;

    // 암호 길이 L
    // 최소 한 개의 모음
    // 최소 두개의 자음

void DFS(int L,int C,int cnt,int k,vector<int> &visited, vector<char> &password ,vector<char> v){
    if(L==cnt){
        int count_1 = 0;
        int count_2 = 0;
        for( char c : password){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') count_1++;
            else count_2++;
        }
        if(count_1 >=1 && count_2 >=2){
            string s(password.begin(),password.end());
            cout << s  << "\n"; 
        }
    }else{
        for(int i=k;i<C;i++){
            if(visited[i]==0){
                visited[i] = 1;
                password[cnt] = v[i];
                DFS(L,C,cnt+1,i,visited,password,v);
                visited[i] = 0;
            }
        }
    }
}

int main(void){

    int L,C;
    cin >> L >> C;

    vector<char> v(C,0);
    for(int i=0;i<C;i++){
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    vector<int> visited(C,0);
    vector<char> password(L,0);

    DFS(L,C,0,0,visited,password,v);

    return 0;
}