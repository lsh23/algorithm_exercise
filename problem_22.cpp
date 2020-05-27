#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,k,i;
    cin >> n >> k;
    int arr[n+1] ={0};
    for(i=1;i<=n;i++){
        int input;
        cin >> input;
        arr[i] = arr[i-1]+input;
    }
    int max = -2147000000;
    for(i=1;i<=n-(k-1);i++){
        int sum_of_part;
        if(k==1) sum_of_part = arr[i];
        else sum_of_part = arr[i+(k-1)]-arr[i-1];
        if(max<sum_of_part){
            max = sum_of_part;
        }
    }
    cout << max;
    return 0;
}
// #include<stdio.h>
// #include<vector>
// using namespace std;			
// int main(){
// 	int n, k, i, sum=0, res;
// 	scanf("%d %d", &n, &k);
// 	vector<int> a(n);
// 	for(i=0; i<n; i++){
// 		scanf("%d", &a[i]);
// 	}
// 	for(i=0; i<k; i++){
// 		sum=sum+a[i];
// 	}
// 	res=sum;
// 	for(i=k; i<n; i++){
// 		sum=sum+(a[i]-a[i-k]);
// 		if(sum>res) res=sum;
// 	}
// 	printf("%d\n", res);
// 	return 0;
// }