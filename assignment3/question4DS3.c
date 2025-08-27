#include <iostream>
#include <string>
#include <cctype>
using namespace std;
#define MAX 100
char stack[MAX]; int top=-1;
void push(char c){ stack[++top]=c; }
char pop(){ return stack[top--]; }
int precedence(char c){ if(c=='^') return 3; if(c=='*'||c=='/') return 2; if(c=='+'||c=='-') return 1; return -1; }
int main(){
    string exp,res; cin>>exp;
    for(char c:exp){
        if(isalnum(c)) res+=c;
        else if(c=='(') push(c);
        else if(c==')'){ while(top!=-1 && stack[top]!='(') res+=pop(); pop(); }
        else { while(top!=-1 && precedence(stack[top])>=precedence(c)) res+=pop(); push(c); }
    }
    while(top!=-1) res+=pop();
    cout<<res;
}
