#include<stdio.h>
int top = -1, n;

void push(int a[],int e){
    if(top = n-1){
        printf("Stack is full");
    }
    else{
        top++;
        a[top]=e;
        printf("Element %d is pushed \n",e);
    }
}

void pop(int a[]){
    if(top==-1){
        printf("Stack is underflow");
    }
    else{
        printf("Element %d is popped \n",a[top--]);
    }

}

void peak(int a[]){
    if(top==-1){
        printf("Stack is underflow");
    }
    else{
        printf("Top element of stack is %d \n",a[top]);
    }
}

void display(int a[]){
    if (top==-1){
        printf("Stack is under flow");
    }
    else{
        printf("Elements of the stack are: \n");
        for(int i=top;i>-1;i--){
            printf("%d \n", a[i]);
        }
    }
}

void main(){
    printf("Enter the size of the array: \n");
    scanf("%d \n",&n);
    int a[n], e;
        int ch;
        printf("\n\n 1. Insert a element \t 2. Delete an element \n 3. Peak \t 4. Display \n 5. Exit");
        printf("Enter a choice: ");
        scanf("%d \n", &ch);
    while(1){

        switch (ch)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d",&e);
            push(a,e);
            break;
        case 2:
            pop(a);
            break;
        case 3:
            peak(a);
            break;
        case 4:
            display(a);
            break;
        case 5:
            exit();            
        
        default:
            printf("Enter the correct choice");
            break;
        }
    }    
}