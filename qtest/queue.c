// queue implementation
#include "queue.h"

static int front, rear;
static char * queue[MAX_SIZE];

void initQueue() 
{
   front = -1;
   rear = -1;
}
void clearQueue()
{
   front = -1;
   rear = -1;
}

void printQueue()
{
   int i;
   if ((front == -1) && (rear == -1)) {
     printf("queue is empty\n");
      return;
   }
   for (i=0;i<MAX_SIZE;i++) {
      printf("%s ", queue[i]);
   }
   printf("\n");
}

int isFull() {
   printf("queue is full\n");
   return ((rear - MAX_SIZE) == front);
   // queue is full if rear has wrapped
   // around to location of the head
}

int isEmpty() {
   if ((front == -1) && (rear == -1)) {
      return TRUE;
   }
   else {
      return FALSE;
   }
}

int enqueue(char * message) 
{
   printf("in enqueue, printlist:\n");
   printQueue();
   if ((rear+1) % MAX_SIZE == front) {
      printf("queue is full\n");
      return FALSE; // queue is full
   }
   else if (isEmpty()) {
      front = 0;
      rear = 0;
   }
   else {
      rear = (rear + 1) % MAX_SIZE;
   }
   queue[rear] = message;
   return TRUE;
}

int dequeue(char ** pmsg) {
   if(isEmpty()) {
      printf("queue is empty\n");
      return FALSE; 
      // can't dequeue, queue already empty
   }
   else if (front == rear) {
      (*pmsg) = queue[front];
      front = -1;
      rear = -1;
      return TRUE;
   }
   else {
      (*pmsg) = queue[front];
      front = (front + 1) % MAX_SIZE;
      return TRUE;
   }

}