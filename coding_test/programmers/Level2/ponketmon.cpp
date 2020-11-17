#include <vector>
#include <set>
using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/1845

#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size();
    set<int> s(nums.begin(),nums.end());
    int s_n = s.size();
    
    if(s_n<=n/2) answer = s_n;
    else{
        answer = n/2;
    }
    return answer;
}