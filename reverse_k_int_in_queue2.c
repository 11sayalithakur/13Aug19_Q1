// Program for reverse first k elements of queue
// Input : 1 2 3 4 5 6 7 8 9   k=4
// Output : 5 4 3 2 1 6 7 8 9
// Time Complexity : O(n) 

#include <stdio.h>
#include<stdlib.h>
#define MAX 50

void enqueue();
void dequeue();
void display();
int  reverse_queue();

int queue_array[MAX];
int rear = - 1;
int front = - 1;

int main()
{
	int choice;

	while (1)
    	{
		printf("1.Insert element to queue \n");
        	printf("2.Delete element from queue \n");
        	printf("3.Display all elements of queue \n");
		printf("4.Reverse queue to k'th position\n ");
        	printf("5.Quit \n");
        	printf("Enter your choice : ");
		printf("\n\n");

        	scanf("%d", &choice);

		switch (choice)
		{
            		case 1:
            			enqueue();
            			break;

            		case 2:
            			dequeue();
            			break;

            		case 3:
	            		display();
	       	     		break;
			case 4:
				reverse_queue();
				break;
		
            		case 5:
            			exit(1);

            		default:
            			printf("Wrong choice \n");

        	}
    	}
}
 
void enqueue()
{
	int add_item;

	if (rear == MAX - 1)
	{
   		 printf("Queue Overflow \n");
	}
    	else
    	{
		if (front == - 1)
		{
        		front = 0;
        		printf("Inset the element in queue : ");
        		scanf("%d", &add_item);
        		rear = rear + 1;
        		queue_array[rear] = add_item;
		}
    	}
}

void dequeue()
{
	if (front == - 1 || front > rear)
	{
        	printf("Queue Underflow \n");
        	return ;
    	}
    	else
    	{
        	printf("Element deleted from queue is : %d\n", queue_array[front]);
        	front = front + 1;
    	}

}

void display()
{
	int i;

    	if (front == - 1)
	{
        	printf("Queue is empty \n");
	}
    	else
    	{
        	printf("QUEUE IS : \n");

       		for(i = front; i <= rear; i++)
		{
            		printf("%d\t ", queue_array[i]);
		}
        	printf("\n\n");
    	}	
}

int reverse_queue()
{
	int i,k,t,j;
    	if (front == - 1)
        	printf("Queue is empty \n");
	else
	{
		printf("enter k th position of queue\n");
		scanf("%d",&k);

		for(i = front, j = k; i < j; i++, j--)
		{
			t = queue_array[i];
			queue_array[i] = queue_array[j];
			queue_array[j] = t;
		}	
		printf("REVERSE QUEUE IS : \n");
		for(i = front; i<=rear; i++)
		{
			printf("%d\t",queue_array[i]);
		}
		printf("\n\n");
	}
}
