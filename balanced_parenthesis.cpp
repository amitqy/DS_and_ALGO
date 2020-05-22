#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void find(string str){
    if(str.size() == 0){
         cout << "balanced" << endl;
         return;
    }
    if(str[0] == ')' || str[0] == '}' || str[0] == ']'){
        cout << "not balanced" << endl;
        return;
    }
    stack<char> s;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            s.push(str[i]);
        }
        else
        {
           if(!s.empty()){
           if(s.top() == '(' && str[i] == ')'){
           s.pop();
           continue;
           }
           else if(s.top() == '{' && str[i] == '}'){
           s.pop();
           continue;
           }
           else if(s.top() == '[' && str[i] == ']'){
           s.pop();
           continue;
           }
           else{
                cout << "not balanced" << endl;
                return;
           }
           
        }  
        }
    }
    if(s.empty()){
        cout << "balanced" << endl;
    }
    else{
        cout << "not balanced" << endl;
    }
    return;
}


int main() {
	int t;
	string str;
	cin >> t;
	while(t!=0){
	   cin >> str;
	   find(str);
	   t--;
	}
	return 0;
}