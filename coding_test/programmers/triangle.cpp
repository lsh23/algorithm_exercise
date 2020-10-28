#include <string>
#include <iostream>
#include <vector>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/68645

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> triangle(n,vector<int>(n,0));
    //내려갔다가
    int number = 1;
    int final_number = n*(n+1)/2;

    int k=0;
    while(number<=final_number){
        for(int i=k*2;i<n-k;i++){
            triangle[i][k]=number++;
        }
        //옆으로갔다가
        for(int i=1;i+k<n-2*k;i++){
            triangle[n-(k+1)][i+k]=number++;
        }
        //올라갔다가
        for(int i=n-(2+k);i>2*k;i--){
            triangle[i][i-k]=number++;
        }
        k++;
    }

    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(triangle[i][j]!=0) answer.push_back(triangle[i][j]);
        }
    }
    
    
    return answer;
}