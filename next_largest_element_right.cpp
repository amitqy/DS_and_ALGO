#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{  // broad idea ::  store the right array of the element in stack. Here stack is helping reducing the complexity from O(n2) to O(n)
    vector<int> v;
    stack<int> s;
    int a[7] = {1, 3, 0, 0, 1, 2, 4};
    int n = 7;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            s.push(a[i]);
            v.push_back(-1);
        }
        else
        {
            if (s.top() <= a[i])
            {
                while (s.size() != 0 && s.top() <= a[i]) // loop runs until stack size is not zero or top element is lesser than a[i]
                {                                       // the moment any of these conditions become false,loop breaks.
                    s.pop();
                }
                if (s.size() != 0)
                {
                    v.push_back(s.top());
                    s.push(a[i]);
                }
                if (s.size() == 0)
                {
                    v.push_back(-1);
                    s.push(a[i]);
                }
            }
            else
            {
                v.push_back(s.top());
                s.push(a[i]);
            }
        }
    }
    reverse(v.begin(),v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    return 0;
}
