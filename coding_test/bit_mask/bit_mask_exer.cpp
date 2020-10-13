#include<bits/stdc++.h>
using namespace std;

void show(int* a){
    for(int i=32;i>0;i--){
        cout << (*a & (1 << (i-1)) ? 1 : 0);
    }
    cout << "\n";
}

void init(int* a){
    *a = 0;
}

void full(int* a){
    *a = -1;
}

void drop(int* a , int i){
    *a &= ~(1 << i);
}

void _set(int* a , int i){
    *a |= (1 << i );
}

bool isSet(int *a, int i){
    return *a & (1 << i);
}

void toggle(int *a, int i){
    *a ^= (1 << i);
}

int getLast(int *a){
    return (*a & -*a);
}

void dropLast(int *a){
    *a &=(*a - 1);
}
int main(void){
    int a = 15;
    show(&a);
    init(&a);
    show(&a);
    full(&a);
    show(&a);
    a = 15;
    drop(&a,2);
    show(&a);
    _set(&a,2);
    show(&a);
    if(isSet(&a,2)) cout << "true\n";
    cout << getLast(&a) << "\n";
    dropLast(&a);
    dropLast(&a);
    dropLast(&a);
    show(&a);
    if(isSet(&a,2)) cout << "true\n";
    cout << getLast(&a) << "\n";
    return 0;
}