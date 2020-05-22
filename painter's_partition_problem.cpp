#include<bits/stdc++.h>
using namespace std;

bool find_valid(int a[],int mid, int m, int n){

int num_s = 1;
int sum = 0;
for(int i = 0; i < n; i++)
{
    sum = sum + a[i];
	if(sum > mid){
		num_s++;
		sum = a[i];
	}
	if(num_s > m){
	return false;
    }
}
return true;
}



void find(int a[], int k, int n){
    int start = *max_element(a,a+n);
    int end = 0;
    for(int i = 0; i < n; i++){
            end += a[i];
        }
    int ans = 0;
    while(start <= end){
     int mid = start + (end - start)/2;
       if(find_valid(a,mid,k,n)==true){
           ans = mid;
           end = mid - 1;
       }
       else{
           start = mid + 1;
       }

    }
    cout << ans <<" ";
}


int main(int argc, char const *argv[])
{
    int t,n,k;
    cin >> t;
    while(t!=0){
        cin >> k >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(k > n){
            cout << -1 << endl;
        }
        find(a,k,n);
        t--;
    }
    return 0;
}
