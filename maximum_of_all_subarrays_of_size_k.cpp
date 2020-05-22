#include<bits/stdc++.h>
using namespace std;
void find(int a[],int n,int k){
    deque<int> dq;
    int i = 0;
    for(; i < k; i++ ){
        while (!dq.empty() and a[dq.back()] < a[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);    
    }
    for (; i < n; i++)
    {
       cout << a[dq.front()] << " ";
       while(!dq.empty() && dq.front() <= i-k){ // does deque cover the current window? 
           dq.pop_front();
       }
       while (!dq.empty() and a[dq.back()] < a[i]) // if element to be inserted in deque has greater value than back element of deque, remove that element. 
        {
            dq.pop_back();
        }
        dq.push_back(i);   
    }
    cout << a[dq.front()] ;
    
}


int main(int argc, char const *argv[])
{
    int t,n,k;
    cin >> t;
    while(t!=0){
     cin >> n >> k;
     int a[n];
     for(int i =0; i < n; i++){
         cin >> a[i];
     }
     t--;
     find(a,n,k);
     cout << endl;
    }
    return 0;
}
