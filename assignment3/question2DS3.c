#include <iostream>
#include <string>
using namespace std;
#define MAX 100
char stack[MAX]; int top=-1;
void push(char c){ stack[++top]=c; }
char pop(){ return stack[top--]; }
int main(){
    string str; cin>>str;
    for(char c:str) push(c);
    while(top!=-1) cout<<pop();
}
