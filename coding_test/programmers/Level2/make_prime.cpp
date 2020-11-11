#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12977

int answer;

bool is_prime(int n){
    int sqrt_n = (int) sqrt(n);
    for(int i=2;i<=sqrt_n;i++){
        if(n%i==0) return false;
    }
    return true;
}


void DFS(int n,int cnt,int k,vector<int> &nums, vector<int> &selected, vector<int> &visited){
    if(cnt == 3){
        int sum = 0;
        for(auto i : selected){
            sum += nums[i];
        }
        if(is_prime(sum)) answer ++;
    }else{
        for(int i=k;i<n;i++){
            if(visited[i]==0){
                selected[cnt]=i;
                visited[i]=1;
                DFS(n,cnt+1,i,nums,selected,visited);
                visited[i]=0;
            }
        }
    }
}


int solution(vector<int> nums) {
    int n = nums.size();
    vector<int> visited(n,0);
    vector<int> selected(3,0);
    
    DFS(n,0,0,nums,selected,visited);
    return answer;
}