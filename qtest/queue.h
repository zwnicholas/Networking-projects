#include <stdio.h>

#define MAX_NUM_ELEMENTS 4
#define MAX_LENGTH 10

// Function prototypes
 void initQueue();
 void clearQueue();
 void printQueue();
 int enqueue(char * message);
 int dequeue(char ** pmsg);
 int isEmpty();
 int isFull();

#ifndef FALSE
#define FALSE (0)
#endif
#ifndef TRUE
#define TRUE (!FALSE)
#endif
