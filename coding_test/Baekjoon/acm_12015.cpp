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

    vector<int> LIS;
    LIS.push_back(arr[0]);
    int end_idx_lis = 0;
    for(int i=1;i<n;i++){
        if(LIS[end_idx_lis]<arr[i]){
            LIS.push_back(arr[i]);
            end_idx_lis++;
        }
        else{
            auto low = lower_bound(LIS.begin(),LIS.end(),arr[i]);
            int low_idx = low - LIS.begin();
            LIS[low_idx] = arr[i];
        }
    }

    cout << LIS.size();

    return 0;
}