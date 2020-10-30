#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42578

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    map<string,int> clothe_cnt;
    
    for(auto clothe : clothes){
        if(clothe_cnt.find(clothe[1])==clothe_cnt.end()){
            clothe_cnt[clothe[1]]=1;
        }else{
            clothe_cnt[clothe[1]]++;
        }
    }
    
    vector<pair<string,int>> v_clothe_cnt (clothe_cnt.begin(),clothe_cnt.end());
    int n = v_clothe_cnt.size();

    for(int i=0;i<n;i++){
        int total = v_clothe_cnt[i].second;
        for(int j=i+1;j<n;j++){
            total*= v_clothe_cnt[j].second+1;
        }
        answer += total;
    }
    
    return answer;
}


// wrong answer
// int ans;

// void combination(vector<pair<string,int>> v_clothe_cnt,vector<int> &visited ,vector<int> &selected,int cnt,int i,int k,int n){
 
//     if(cnt == k){
//         int total = 1;
//         for(auto selected_index : selected){
//             total *= v_clothe_cnt[selected_index].second;
//         }
//         ans += total;
//     }else{
//         for(;i<n;i++){
//             if(visited[i]==0){
//                 visited[i]=1;
//                 selected[cnt] = i;
//                 combination(v_clothe_cnt,visited,selected,cnt+1,i,k,n);
//                 visited[i]=0;
//             }
//         }
//     }
// }


// int solution(vector<vector<string>> clothes) {
//     int answer = 0;

//     map<string,int> clothe_cnt;
    
//     for(auto clothe : clothes){
//         if(clothe_cnt.find(clothe[1])==clothe_cnt.end()){
//             clothe_cnt[clothe[1]]=1;
//         }else{
//             clothe_cnt[clothe[1]]++;
//         }
//     }
    
//     vector<pair<string,int>> v_clothe_cnt (clothe_cnt.begin(),clothe_cnt.end());
//     int n = v_clothe_cnt.size();

//     for(int i=1;i<=n;i++){
//         vector<int> selected(i,0);
//         vector<int> visited(n,0);
//         combination(v_clothe_cnt,visited,selected,0,0,i,n);
//     }
    
//     answer = ans;
    
//     return answer;
// }