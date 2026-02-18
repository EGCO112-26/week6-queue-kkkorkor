#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

#include "queue.h"

int Price(int order_number,char name[]);

int main(int argc , char **argv) {
  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL;
// For struct Queue
  Queue  q;
   q.head=NULL;
   q.tail=NULL;
   q.size=0;

   int i,x;
   int cusNO=1;
   
   for(i=1;i<argc;i++){
     enqueue_struct(&q, atoi(argv[i]));
   }
   for(i=1; i<argc; i++){
    if(q.size > 0) dequeue_struct(&q, &cusNO);
   }
   
   
   printf("================================\n");
   printf("There are %d ppl left in the queue\n", q.size);

  return 0;
}

int Price(int order_number,char name[]){
  switch (order_number){
    case 1:  
        strcpy(name,"Ramen");
        return 200; break;

    case 2:  
        strcpy(name,"Somtum");
        return 20; break;
        
    case 3:  
        strcpy(name,"Fried Chicken");
        return 50; break;

    default:
        strcpy(name,"No Food\n");
        return 0; break;
  }
}