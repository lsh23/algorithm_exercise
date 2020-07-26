#include <bits/stdc++.h>
using namespace std;


void pre_search(int i, int n){
	
	if(i>n) return;
	//자신 
	cout << i << " ";
	//좌자식 
	pre_search(2*i,n);
	//우좌식
	pre_search(2*i+1,n);

}

void mid_search(int i, int n){
	
	if(i>n) return;
	
	//좌자식 
	mid_search(2*i,n);
	
	//자신 
	cout << i << " ";

	//우좌식
	mid_search(2*i+1,n);

}

void post_search(int i, int n){
	
	if(i>n) return;
	
	//좌자식 
	post_search(2*i,n);
	
	//우좌식
	post_search(2*i+1,n);

	//자신 
	cout << i << " ";

}


int main(void){

	post_search(1,7);

	return 0;
}
