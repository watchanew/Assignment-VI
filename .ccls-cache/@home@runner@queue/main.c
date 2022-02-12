#include <stdio.h>
#include <string.h>
#include "Queue.h"

//1 Ramen 60
//2 Sandwich 25 
//3 Boat Noodles 15

int main(int argc, const char * argv[]) {
  int i,x,j=1;
  Queue Q;
  Q.head=NULL;
  Q.tail=NULL;
  Q.size=0;
  
  int ornum,change,payamount;

  for(i=1;i<argc;i++){
      if(strcmp(argv[i],"x")==0){
        if(Q.size == 0) puts("No Queue");
        else{
          ornum = Q.head->order_number;
          printf("Customer no: %d\n", j);
          j++;
          switch(ornum){
            case 1:
              puts("Ramen");
              break;
            case 2:
              puts("Sandwich");
              break;
            case 3:
              puts("Boat noodles");
              break;
            default:
              puts("NO FOOD");
              break;
          }
          x=dequeue(&Q);
          if(ornum>=1 && ornum<=3){
            printf("You have to pay: %d\n",x);
            while(x!=0){
              printf("Cash: ");
              scanf("%d", &payamount);
              if(payamount==x){
                printf("Thank You\n\n");
                break;
              }
              else if(payamount>x){
                change=payamount-x;
                printf("Thank You\n");
                printf("Change is: %d\n\n", change);
                break;
              }
            }
          }
        }
      }
      else {
        enqueue(&Q, atoi(argv[i]),atoi(argv[i+1]));
        printf("My order is %d\n", atoi(argv[i]));
        i++;
      }    
  }
  printf("=====================================================\n");
  if(Q.size != 0){
    printf("There are %d customers left in the queue\n", Q.size);
  }
  else{
    puts("誠にありがとうございます");
  }
}
  
