#include <iostream>
#include<stdio.h>
using namespace std;
#define QUEUE_SIZE 5
struct LinearQueue
{
    int front;
    int rear;
    int items[QUEUE_SIZE];
};
void initializeQueue(struct LinearQueue *l)
{
    l->front = 0; l->rear = -1;
}
int isQueueEmpty(struct LinearQueue *l)
{
    if (l->rear < l->front) return 1;
    else return 0;
}

int isQueuefull(struct LinearQueue *l)
{
    if (l->rear == QUEUE_SIZE - 1) return 1;
    else return 0;
}
void insert(struct LinearQueue *l, int x)
{
    if (isQueuefull(l))
    {
       cout<<"Overflow: Queue is full"<<endl;
       exit(1);
    }
    else
   	   l->items[++l->rear]=x;
}
int remove(struct LinearQueue *l)
{
    int x;
    if (isQueueEmpty(l))
	{   cout<<"Underflow: Queue is empty"<<endl; 
        exit(1);
    }
	else
	{
        x = l->items[l->front++];
        return x;
    }
}


void printLinearQueue(struct LinearQueue *b)
{
	int x,count;
	struct LinearQueue temp;
	initializeQueue(&temp);
	while(!isQueueEmpty(b))
	{
      
      count++;
      
		x=remove(b);
        cout <<x<<"\t";
	//	insert(&temp,x);
		

	}



/*	initializeQueue(b);
	while(!isQueueEmpty(&temp))
	{
		x=remove(&temp);
		insert(b,x);
	}*/
   
}



int main(){
 FILE *fptr;
 
   int bt,at,p, wt=0,tat=0,ct=0,count=0,sum=0,aini;
	  struct LinearQueue lq;
	initializeQueue(&lq);
   fptr = fopen("input.txt","r");
   if(fptr == NULL){
      cout<<"The File Not Exist !!";   
      exit(1);             
   }
   while(fscanf(fptr,"%d:%d:%d",&bt ,&at ,&p ) == 3)
       {
       
    //cout<<"Barst Time"<<": "<<bt<<"  Arrival Time : "<<at<<endl;
      	// count++;
      	//tat=bt+wt;
      //	wt=tat-bt;
     //   cout<<"Waiting Time : "<<wt<<endl;
      //	  tat=at-ct;
      //	  tat=at-ct;
      //	  tat=at-ct;
      	
      //	  tat=at-ct;

		//cout<<"P"<<count<<":"<<a+aini<<" ms"<<endl;	
	  
   
	insert(&lq,bt);
  
 }

 printLinearQueue(&lq);

  //  double avr=a+aini/count; 
//cout<<"Total is :"<<sum<<"\t"<<"Avrage is :"<<avr;	

   fclose(fptr);
   
    return 0;
   }
   

