#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,i;
    cin >> n;
    for(i=0;i<n;i++){
        int k;
        cin >> k;
        int student_answer;
        cin >> student_answer;
        if(student_answer == ((k*(k+1))/2)) cout << "YES";
        else cout << "NO";
    }
    return 0;
}