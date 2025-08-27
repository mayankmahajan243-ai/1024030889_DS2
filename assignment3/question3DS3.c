#include <iostream>
#include <string>
using namespace std;
#define MAX 100
char stack[MAX]; int top=-1;
void push(char c){ stack[++top]=c; }
char pop(){ return stack[top--]; }
int main(){
    string exp; cin>>exp;
    for(char c:exp){
        if(c=='('||c=='{'||c=='[') push(c);
        else if(c==')'||c=='}'||c==']'){
            if(top==-1){ cout<<"Not Balanced"; return 0; }
            char x=pop();
            if((c==')'&&x!='(')||(c=='}'&&x!='{')||(c==']'&&x!='[')){ cout<<"Not Balanced"; return 0; }
        }
    }
    if(top==-1) cout<<"Balanced"; else cout<<"Not Balanced";
}
