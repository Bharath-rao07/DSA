#include<stdio.h>
#define max 5
void insert();
void deletion();
void peek();
void display();

int a[10],front=-1,rear=-1;

int main()
{
    int choice;

    do
    {
        printf("\n===QUEUE OPERATIONS===\n");
        printf("\n1.INSERT\n");
        printf("\n2.DELETE\n");
        printf("\n3.PEEK\n");
        printf("\n4.DISPLAY\n");
        printf("\n5.EXITING THE PROGRAM\n");

        printf("Enter your choice (1/2/3/4/5) : ");
        scanf("%d",&choice);
      
        switch(choice)
          {
            case 1:
                   printf("Selected the insert operation .\n");
                   insert();
                   break;
            case 2:
                   printf("Selected the deletion operation .\n");
                   deletion();
                   break;
            case 3:
                   printf("Selected the peek operation .\n");  
                   peek();
                   break;
            case 4:
                   printf("Selected the display operation .\n");
                   display();
                   break;
            case 5:
                   printf("Exiting the programm.\n");
                   break;
           default:
                   printf("INVALID CHOICE!!.\n");
                   break;                                
          }

    } while(choice!=5);
    
    return 0;
}


// check for the overflow,insert the new element.
void insert()
{
    int value;
    if(rear==max-1)
    {
        printf("the Queue is overflow !!! ");
        return;
    }

    printf("Enter the element to be inserted : ");
    scanf("%d",&value);

    if (front==-1)
      front=0;

   rear++;
   a[rear]=value;  
}


// check for the underflow, delete the element present at the front.
void deletion()
{
    if(front==-1)
    {
        printf("The Queue is underflow .\n");
        return ;
    }

    printf(" the Queue element %d  is deleted .",a[front]);

    front++;

    if (front>rear)
    {
        front=-1;
        rear=-1;
        printf("\n Now the Queue is in the underflow condition.\n");
    }
}


// Check the underflow condition,display the elements present at front of Queue.
void peek()
 {
    if(front==-1)
     {
        printf("The Queue is in the underflow condition.\n");
        return ;
     }

     printf(" the first  element is %d .\n",a[front]);
 }


// check for the underflow condition, display the all elements of the Queue.
void display()
 {
    int i;
    if (front==-1)
        
    {
        printf("The Queue is in underflow condition.\n");
         return;
    }

    for(i=front;i<=rear;i++)
      {
        printf("%d\t",a[i]);
      }
 }
