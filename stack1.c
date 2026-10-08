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
        printf(" Enter the choice(1/2/3/4) : ");
        scanf("%d",&choice);
        
        
        switch(choice)
     {
    case 1: printf("selected the push operation ");
            push();
            break;
    case 2: printf("selected the pop operation ");
            pop();
            break;
    case 3: printf("selected peek operation ");
            peek();
            break;
    case 4: printf("selected display operation ");
            display();
            break;
   default: printf("invalid choice");
            break;                                  
      } 
          }while(choice<MAX);
}

//    check for the overflow,read the element ,increament top,assign value to array.  



void push()
  {
    if(top==MAX-1)
     printf("stack is overflow ");
     break;
   
    printf("enter the values \n");
    scanf("%d",&value);

    a[++top]=value;
 }


//  check for the outflow, filling every places with the null value,decreamenting the top value,printing the message.

 void pop()
 {
    if(top==-1)
    printf("the stack is overflow ");
    break;

    a[top]=NULL;
    top-=1;

    printf("The elements of the stack is deleted . ");

 }
