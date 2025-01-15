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
}#include<stdio.h>
#include<stdlib.h>
int top=-1,n;

void push(int a[],int e)
{
	if(top==n-1)
	{
		printf("Stack is full\n");
	}
	else
	{
		top++;
		a[top]=e;
printf("***************************\n");
		printf("\n Elements %d is pushed\n",e);
printf("***************************\n");
	}
}
void pop(int a[])
{
	if(top==-1)
	{
printf("***************************\n");
		printf("Stack is under flow\n");
printf("***************************\n");
	}
	else
	{
printf("***************************\n");
	printf("Element %d is poped\n",a[top--]);
printf("***************************\n");
	}
}
void peep(int a[])
{
	if(top==-1)
	{
printf("***************************\n");
	printf("stack is under flow\n");
printf("***************************\n");
	}
	else
	{
printf("***************************\n");
	printf("The top most element is %d\n",a[top]);
printf("***************************\n");
	}
}
void display(int a[])
{
	if(top-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Elements of stack are:\n");
printf("***************************\n");
	}
		for(int i=top;i>-1;i--)
		{
			printf("%d\n",a[i]);
		}
}
void main()
{
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	int a[n],e;
		int ch;
		while(1)
		{
		printf("\n\n1->Insert element\t2->delete element\n3->peep\t\t4->display\n5->exit\n");
		printf("\n enter choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the element to be pushed:\n");
			      scanf("%d",&e);
			      push(a,e);
			      break;
			case 2:pop(a);
			      break;
			case 3:peep(a);
			      break;
			case 4:display(a);
			      break;
			case 5: exit(0); 
			default:printf("enter the correct choice");
		}
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
