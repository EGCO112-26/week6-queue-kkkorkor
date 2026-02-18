

/*typedef struct {
	 NodePtr headPtr,tailPtr;
	int size;
}Queue;
*/

int Price(int order_number, char name[]);

typedef struct Queue{
   order *head,*tail;
    int size;
}Queue;

void enqueue_struct(Queue* q, int orderno){
  order *new_queue=(order*) malloc(sizeof(order));
if(new_queue){
  new_queue->order_number = orderno;
  new_queue->next = NULL;

  if(q->size == 0) q->head = new_queue;
  else q->tail->next = new_queue;
  q->tail=new_queue;
  q->size++;
  printf("My order is %d\n", orderno);
  //Finish enqueue
 }
}


int dequeue_struct(Queue *q, int *cusNo){
   order *t=q->head;
   if(t){
    int value = t->order_number;
    char menu[20];
    int price = Price(t->order_number,menu);
    int cash=0;

    printf("Customer no: %d\n", (*cusNo)++);
    printf("%s\n", menu);
    printf("You have to pay %d\n", price);
    printf("Cash: ");
    scanf("%d", &cash);
    
    while(cash<price){
      printf("Cash: ");
      scanf("%d",&cash);
   }

    printf("Thank you\n");
    if(cash>price)
        printf("Change is: %d\n", cash-price);


    q->head = t->next;
    free(t);
    q->size--;

    if(q->size == 0) q->tail = NULL;
       //Finish dequeue
   return value;
   }
   printf("The queue is empty \n");
   return 0;
}
