#include <bits/stdc++.h>
using namespace std;

int main(void){
    string personal_number;
    getline(cin,personal_number);
    int age;
    string sex;

    char sex_number = personal_number[7];
    if(sex_number =='1' | sex_number =='3'){
        sex = "M"; 
    }
    else{
        sex = "W";
    }
    
    if(personal_number[0]=='0'){
        age = 2019 - (2000 + stoi(personal_number.substr(0,2)));
    }else{
        age = 2019 - (1900 + stoi(personal_number.substr(0,2)));
    }

    cout << age+1 << " " << sex;

    return 0;
}