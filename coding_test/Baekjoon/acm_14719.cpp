#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){

    int h,w;
    int answer = 0;
    cin >> h >> w;

    vector<int> blocks(w,0);

    for(int i=0;i<w;i++){
        cin >> blocks[i];
    }

    for(int i=1;i<w-1;i++){
        
        int i_th = blocks[i];
        int left_max,right_max;
        
        left_max = *max_element(blocks.begin(),blocks.begin()+i+1);
        right_max = *max_element(blocks.begin()+i,blocks.end());

        answer += min(left_max,right_max) - i_th;

    }

    vector<int> v = {1,2,5,4,3};

    cout << *max_element(v.begin()+2,v.end());

    cout << answer;

    return 0;
}