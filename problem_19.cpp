#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,i;
    cin >> n;
    vector<int> v;
    for(i=0;i<n;i++){
        int k;
        cin >> k;
        while(!v.empty() && v.back() <= k){
            v.pop_back();
        }
        if(i!=n-1) v.push_back(k);
    }
    cout << v.size();
    return 0;
}