#include <bits/stdc++.h>
using namespace std;

int main(void){
    string a,b;
    getline(cin,a);
    getline(cin,b);

    int a_cnt[52] = {0};
    int b_cnt[52] = {0};

    int i;

    for(i=0;i<a.length();i++){
        if(a[i]>='a' && a[i]<='z')
            a_cnt[a[i]-71]++;
        else
            a_cnt[a[i]-'A']++;
    }

    for(i=0;i<b.length();i++){
        if(b[i]>='a' && b[i]<='z')
            b_cnt[b[i]-71]++;
        else
            b_cnt[b[i]-'A']++;
    }

    string ans = "YES";
    for(i=0;i<52;i++){
        if(a_cnt[i]!=b_cnt[i]){
            ans = "NO";
            break;
        }
    }

    cout << ans;

    return 0;
}