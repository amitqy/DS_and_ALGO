#include<bits/stdc++.h>
using namespace std;

void find(long long int a[], int n){
   
   stack<pair<long long int,int>> s;
   stack<pair<long long int,int>> s2;
   vector<int> l;
   vector<int> r;

for (int i = 0; i < n; i++)
{
    
    if(s.empty()){
        s.push({a[i],i});
        l.push_back(-1);
    }
    else{
        if(s.top().first >= a[i]){
           while(s.size() != 0 && s.top().first >= a[i]){
               s.pop();
           }
           if(s.size() == 0){
               s.push({a[i],i});
               l.push_back(-1);
           }
           else{
              l.push_back(s.top().second);
               s.push({a[i],i});
           }
        }
        else{
             l.push_back(s.top().second);
             s.push({a[i],i});
        }
    }
}
for (int i = n-1; i >= 0; i--)
{

    if(s2.empty()){
        s2.push({a[i],i});
        r.push_back(n);
    }
    else{
        if(s2.top().first >= a[i]){
           while(s2.size() != 0 && s2.top().first >= a[i]){
               s2.pop();
           }
           if(s2.size() == 0){
                s2.push({a[i],i});
                r.push_back(n);
           }
           else{
               r.push_back(s2.top().second);
               s2.push({a[i],i});;
           }
        }
        else{
            r.push_back(s2.top().second);
            s2.push({a[i],i});
        }
    }
}
reverse(r.begin(),r.end());

for(int i = 0; i < n; i++){
    cout << l[i] <<" ";
}
cout << endl;

long long int ans = 0;
long long int sum = 0;

for(int i = 0 ; i < n; i++){
    sum = (r[i] - l[i] - 1) * a[i];
    ans = max(ans,sum);
}

cout << ans << endl;

}


int main(int argc, char const *argv[])
{
    int t,n;
    cin >> t;
    while( t!= 0){
        cin >> n;
        long long int a[1000000];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        t--;
        find(a,n);
    }
    return 0;
}
