#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void){

    int n,k;
    cin >> n >> k;
    vector<int> bag(k+1,0);

    for(int i=0;i<n;i++){
        int w,v;
        cin >> w >> v;
        for(int j=k; j>=w;j--){
            bag[j]=max(bag[j],bag[j-w]+v);
        }
    }

    cout << bag[k];

    return 0;
}