#include <bits/stdc++.h>
using namespace std;

int main(void){
    int i;
    char last_winner ='0';
    int a_score = 0;
    int b_score = 0;
    int a[10] = {0};
    int b[10] = {0};
    for(i=0;i<10;i++){
        cin >> a[i];
    }
    for(i=0;i<10;i++){
        cin >> b[i];
    }
    for(i=0;i<10;i++){
        if(a[i]>b[i]){
            a_score +=3;
            last_winner ='A';
        }else if(a[i]<b[i]){
            b_score +=3;
            last_winner = 'B';
        }else{
            a_score++;
            b_score++;
        }
    }

    cout << a_score << " " <<  b_score << "\n";

    if(a_score>b_score) cout <<"A";
    else if(b_score>a_score) cout << "B";
    else{
        if(last_winner != '0') cout << last_winner;
        else cout << "D";
    }
    return 0;
}