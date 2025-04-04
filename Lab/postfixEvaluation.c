#include<stdio.h>
#include<ctype.h>

int stack[20];
int top = -1;

void push(int x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

int main(){
    char exp[20];
    char *e;
    int n1,n2,num;
    printf("Enter an expression: ");
    scanf("%s, \n",exp);
    e = exp;
    while (*e != '\0')
    {
        if(isdigit(*e)){
            num = *e - 48;
            push(num);
        }
        else{
            n1 = pop();
            n2 = pop();
            switch (*e)
            {
            case '+':
            {
                num = n2 + n1;
                break;
            }
            case '-':
            {
                num = n2 - n1;
                break;
            }
            case '*':
            {
                num = n2 * n1;
                break;
            }    
            case '/':
            {
                num = n2 / n1;
                break;            
            }
            }
            push(num);
        }
        e++;
    }
    printf("\n The sresult of expression %s = %d \n\n", exp,pop());
    return 0;
}
