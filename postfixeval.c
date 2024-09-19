#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

int top=-1;
int i=-1;
#define Asize 30
#define Bsize 60
char A[Asize]; //stack
char B[Bsize]; //P.E array

bool isFullA(){
    return (top==Asize-1);
}
bool isEmptyA(){
    return (top==-1);
    
}
bool isFullB(){
    return (i==Bsize-1);
}
void push(char c){
    if (!isFullA()){
        A[++top]=c;
    }
}
//to pop operator from stack
char pop(){
    if (!isEmptyA()){
        return A[top--];
    }
}
//to add operator or operant into postfix expression
void add(char c){
     if (!isFullB()){
        i=i+1;
        B[i]=c;
    }
}

int prio(char c){//function to return priority and checek for operator
    switch (c){
        case '(':return 0;break;
        case '+':return 1;break;
        case '-':return 1;break;
        case '*':return 2;break;
        case '/':return 2;break;
        case '^':return 3;break;
        default :return -1;
    }
}
void main(){
    char x;
    char C[30];
    printf("Enter expression : ");
    scanf("%s",C);
    int l= strlen(C);
    for(int j=0;j<l;j++){
        if (C[j]==')'){
            while (A[top]!='('){
                x=pop();
                add(x);
            }
            x=pop();
        }
        else if (C[j]=='^' && A[top]=='^'){
            push(C[j]);
        }
        else if(prio(C[j])==-1){//operant case
            add(C[j]);
        }
        else{
            if (C[j]=='(' || isEmptyA()){
                push(C[j]);
            }
            else if (prio(C[j])>prio(A[top])){
                push(C[j]);
            }
            else{
                while(!isEmptyA() && prio(C[j])<=prio(A[top])){
                    x=pop();
                    add(x);
                }
                push(C[j]);
            }
            
        }
    }
        
        while(!isEmptyA()){
            x=pop();
            add(x);
        }
        for (int j=0;j<i+1;j++){
             printf("%c",B[j]);
    }
    printf("\n");
        
}
