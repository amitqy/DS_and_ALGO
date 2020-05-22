#include<iostream>
#include<stack>
using namespace std;
void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty()){
		    pop();
		}
		while(!isFull(n)){
			cin>>a;
			push(a);
		}
		cout<<getMin()<<endl;
        pop();
        cout<<getMin()<<endl;
	}
}// } Driver Code Ends

stack<int> s2;
/*Complete the function(s) below*/
void push(int a)
{
    s.push(a);
    if(s2.size() == 0 || s2.top() >= a){
        s2.push(a);
        return;
    }
}

bool isFull(int n)
{
    return (s.size() == n);
}

bool isEmpty()
{
    return (s.size() == 0);
}

int pop()
{
    if(s.size() == 0){
        return -1;
    }
    int ans = s.top();
    s.pop();
    if(s2.top() == ans){
        s2.pop();
    }
    return ans;
}  

int getMin()
{
  if(s2.size() == 0){
      return -1;
  }
  return s2.top();
}