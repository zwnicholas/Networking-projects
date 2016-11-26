#include <stdio.h>
#include "queue.h"
#include <stdlib.h>
#include <string.h>

int main() {
   initQueue();
   printf("queue initialized\n");
   char ** pmsg = malloc(sizeof(char *));
   (*pmsg) = malloc(sizeof(char) * 10);
   int cmd = 0;
   char buf [10];
   //char toEnqueue[10];
   
   printf("enter a command: 1 to enqueue, 2 to dequeue, 3 to view\n");
   while(1) {
      printQueue();
      scanf("%d", &cmd);
      if (cmd == 1) {
         printf("enter a string to enqueue\n");
         scanf("%s", buf);
         if (enqueue(buf)) {
            printf("%s enqueued successfully\n", buf);
         }
      }
      else if (cmd == 2) {
         if (dequeue(pmsg)) {
            printf("successfully dequeued %s\n", (*pmsg));
         }
         else printf("dequeue failed\n");
      }
   }
}
