#include <string>
#include <vector>
#include <iostream>

//https://programmers.co.kr/learn/courses/30/lessons/68936

using namespace std;


int count_1;
int count_0;

void compress(vector<vector<int>> &arr, int y,int x, int n){

    int sum = 0;
    for(int i=y;i<y+n;i++){
        for(int j=x;j<x+n;j++){
            sum +=arr[i][j];
        }
    }
    if(sum==0){
        count_0++;
        return;
    }
    if(sum==n*n){
        count_1++;
        return;
    }
    compress(arr,y,x,n/2);
    compress(arr,y,n/2+x,n/2);
    compress(arr,y+n/2,x,n/2);
    compress(arr,y+n/2,x+n/2,n/2);
    
}
vector<int> solution(vector<vector<int>> arr) {
    
    vector<int> answer;
    compress(arr,0,0,arr.size());
    answer.push_back(count_0);
    answer.push_back(count_1);
    return answer;
    
}