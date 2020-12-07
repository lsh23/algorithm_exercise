#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){

    int n;
    cin >> n;
    vector<int> sum(n+1,0);
    for(int i=1;i<=n;i++){
        int input_i;
        cin >> input_i;
        sum[i] = max(input_i,sum[i-1]+input_i);
    }

    cout << *max_element(sum.begin()+1,sum.end());

    return 0;
}