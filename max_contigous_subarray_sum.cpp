#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void find(int a[],int n){
int cumm[n];
cumm[0] = a[0];
    for(int i = 1; i < n; i++){
        cumm[i] = max(cumm[i-1]+a[i],a[i]);
    }
    cout << *max_element(cumm,cumm+n) << endl;
}

int main() {
	int t,n;
	cin >> t;
	while(t!=0){
	    cin >> n;
	    int a[1000000];
	    for(int i = 0; i < n; i++){
	        cin >> a[i];
	    }
	    find(a,n);
	    t--;
	}
	return 0;
}