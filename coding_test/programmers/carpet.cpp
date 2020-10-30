#include <string>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/42842

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    int carpet_width = 0;
    int carpet_height = 0;
    
   
    // Set init width 
    carpet_width = (int) sqrt(total);
    carpet_height = total / carpet_width;
    
    // width is greater than height
    if(carpet_width<carpet_height){
        int tmp = carpet_width;
        carpet_width = carpet_height;
        carpet_height = tmp;
    }
    
    while(true){
        if(total%carpet_width==0){
            carpet_height = total / carpet_width;
            if(2*carpet_width + 2*(carpet_height-2) == brown){
                answer.push_back(carpet_width);
                answer.push_back(carpet_height);
                break;
            }
        }
        carpet_width++;
    }

    return answer;
}