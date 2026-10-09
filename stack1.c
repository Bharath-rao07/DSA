 #include<stdio.h>
 #define MAX 5
int a[MAX],i,top=-1,choice,value;
 void push();
 void pop();
 void peek();
 void display();
int  main()
{
      do{
       
        printf("\n\n--- STACK OPERATIONS ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");


        printf(" Enter the choice(1/2/3/4) : ");
        scanf("%d",&choice);
        
        
        switch(choice)
     {
    case 1:
            printf("selected the push operation ");
            push();
            break;
    case 2:
            printf("selected the pop operation ");
            pop();
            break;
    case 3: 
            printf("selected peek operation ");
            peek();
            break;
    case 4:
            printf("selected display operation ");
            display();
            break;
   default: 
            printf("invalid choice");
            break;                                  
      } 
          }while(choice!=MAX);
}

//    check for the overflow,read the element , increament top,assign value to array.  



void push()
  {
    if(top==MAX-1)
     printf("stack is overflow ");
     return;
   
    printf("enter the values \n");
    scanf("%d",&value);

    a[++top]=value;
 }


//  check for the outflow,  delete the top element and decrement top.Display the message.

 void pop()
 {
    if(top==-1)
    printf("the stack is overflow ");
    return;

    printf("The element %d is deleted.",a[top]);

    top-=1;

    printf("The elements of the stack is deleted . ");

 }


// checking whether the stack is empty or not.displaying the top element.

void peek()
{
    if(top==-1)
    {
        printf("Stack is underflow  ");
        return;
    }

    printf("The top element is %d",a[top]);
}



// checking whether the stack is empty or not then displaying the all the elements in thw stack.

void display()
{
    if(top==-1)
    {
        printf("Stack is underflow ");
        return;
    }

    printf("The elements of the stack are:\n");

    for(i=top;i>=0;i--)
    {
        printf("%d\n",a[i]);
    }
}
