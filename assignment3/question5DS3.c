#include <iostream>
#include <string>
#include <cctype>
using namespace std;
#define MAX 100
int stack[MAX]; int top=-1;
void push(int x){ stack[++top]=x; }
int pop(){ return stack[top--]; }
int main(){
    string exp; cin>>exp;
    for(char c:exp){
        if(isdigit(c)) push(c-'0');
        else{
            int v2=pop(), v1=pop();
            if(c=='+') push(v1+v2);
            else if(c=='-') push(v1-v2);
            else if(c=='*') push(v1*v2);
            else if(c=='/') push(v1/v2);
        }
    }
    cout<<pop();
}
