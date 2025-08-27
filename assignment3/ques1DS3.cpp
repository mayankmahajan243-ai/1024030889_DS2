#include <iostream>
using namespace std;
#define MAX 100
int stack[MAX], top=-1;
void push(int x){ if(top<MAX-1) stack[++top]=x; }
int pop(){ if(top>=0) return stack[top--]; return -1; }
int isEmpty(){ return top==-1; }
int isFull(){ return top==MAX-1; }
int peek(){ if(top>=0) return stack[top]; return -1; }
void display(){ for(int i=top;i>=0;i--) cout<<stack[i]<<" "; cout<<endl; }
int main(){
    int ch,val;
    while(1){
        cout<<"1.Push 2.Pop 3.Peek 4.Display 5.Exit\n";
        cin>>ch;
        if(ch==1){cin>>val;push(val);}
        else if(ch==2){cout<<pop()<<endl;}
        else if(ch==3){cout<<peek()<<endl;}
        else if(ch==4){display();}
        else break;
    }
}
