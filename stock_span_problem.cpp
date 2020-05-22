#include<bits/stdc++.h>
using namespace std;

// broad idea : ( index of nearest greater element left - current index ) gives the stock span for that stock 

void find(int a[],int n){
stack<pair<int,int>> s;
vector<int> v;
for (int i = 0; i < n; i++)
{
    if(s.empty()){
       v.push_back(-1);
       s.push({a[i],i});
    }
    else{
        if(s.top().first > a[i]){
            v.push_back(s.top().second);
            s.push({a[i],i});
        }
        else{
         while (s.size() != 0 && s.top().first < a[i])
         {
             s.pop();
         }
         if(s.size() == 0){
             v.push_back(-1);
             s.push({a[i],i});
         }
         else
         {
             v.push_back(s.top().second);
             s.push({a[i],i});    
         }
         
        }

    }
}
 for (int i = 0; i < v.size(); i++)
 {
     cout << i - v[i] << " ";
 }
  cout << endl;
}

int main(int argc, char const *argv[])
{
    int t,n;
    cin >> t;
    while( t!=0 ){
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        find(a,n);
        t--;
        cout << endl;
    }
    
    return 0;
}
