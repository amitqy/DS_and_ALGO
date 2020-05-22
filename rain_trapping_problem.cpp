#include <bits/stdc++.h>
using namespace std;

/*
broad idea : Find the max on left and right side array of each element. Find there min. Sub it from current.

*/


void find(int a[], int n)
{
    int l[n];
    int r[n];

    l[0] = a[0];
    r[n-1] = a[n-1];
    int max = l[0];
    for(int i = 1; i < n; i++){
        if(max > a[i]){
            l[i] = max;
        }
        else{
            max = a[i];
            l[i] = max;
        }
    }
    max = r[n-1];
    for(int i = n-1; i >= 0; i--){
        if(max > a[i]){
            r[i] = max;
        }
        else{
            max = a[i];
            r[i] = max;
        }
    }
   int ans = 0;
   for (int i = 0; i < n; i++)
   {
       ans += min(l[i],r[i]) - a[i];
   }
   
   cout << ans;
    
}

int main(int argc, char const *argv[])
{
    int t, n;
    cin >> t;
    while (t != 0)
    {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        find(a, n);
        t--;
    }
    return 0;
}
