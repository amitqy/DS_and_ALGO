#include <iostream>
#define  ll long long
using namespace std;

void find(ll a[],ll n,ll e)
{
    ll curr_sum = 0;
    for(int i = 0 ; i < n; i++){
        for(int j = i; j < n; j++){
            curr_sum += a[j];
            if(curr_sum == e){
               cout << i+1 << " " << j+1 << endl;
                return;
            }
            if(curr_sum > e){
                curr_sum = 0;
                break;
            }
        }
    }
    cout << -1 <<endl;
}


int main() {
	int t;
	ll e;
	cin >> t;
	ll n;
	while(t!=0){
	    cin >> n >> e;
	    ll a[1000000];
	    for(ll i = 0; i < n; i++){
	        cin >> a[i];
	    }
	    find(a,n,e);
	    t--;
	}
	
	return 0;
}