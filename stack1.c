 #include<stdio.h>
 #define MAX 5
 void push();
 void pop();
 void peek();
 void display();
int  main()
{
    int a[10],i,top=-1,choice;
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
