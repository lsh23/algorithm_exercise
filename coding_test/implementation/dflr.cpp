#include<bits/stdc++.h>
using namespace std;

int main(void){

    int n ;
    cin >> n;

    vector<string> commands;
    
    for(int i=0;i<n;i++){
        string command;
        cin >> command;
        commands.push_back(command);
    }

    int x = 1;
    int y = 1;

    for(string command : commands){
        int dx = 0;
        int dy = 0;
        if(command == "U"){ 
            dx = -1;
            if(x==1) dx = 0;
        }
        if(command == "D"){
            dx = 1;
            if(x==n) dx = 0;
        }
        if(command == "L"){
            dy = -1;
            if(y==1) dy = 0;
        }
        if(command == "R"){
            dy = 1;
            if(y==n) dy =0;
        }
        x += dx;
        y += dy;
    }

    cout << x << " " << y; 

    return 0;
}