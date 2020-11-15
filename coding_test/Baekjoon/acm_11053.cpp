#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){

    int n;

    cin >> n;

    vector<int> arr(n,0);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<int> LIS(n,0);

    for(int i=0;i<n;i++){
        LIS[i]=1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && LIS[i]<LIS[j]+1) LIS[i] = LIS[j]+1;
        }
    }

    cout << *max_element(LIS.begin(),LIS.end());

    return 0;
}