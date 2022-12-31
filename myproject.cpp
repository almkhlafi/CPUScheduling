#include <iostream>
#include<stdio.h>
#include <fstream>
using namespace std;
#define QUEUE_SIZE 1000
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


void printLinearQueue(struct LinearQueue *b,int count)
{

	int x,count1=0,sum=0,sum1=0;
	struct LinearQueue temp;
	initializeQueue(&temp);
	while(!isQueueEmpty(b))
	{
	
		x=remove(b);
        sum=sum+x;
        cout <<"P"<<count1+1<<"  :"<<sum<<"\n";
	    count1++;      
	}
	
//	double avr=sum/count;
	cout<<"Sum is:"<<sum<<"Avr is :"<<endl;
}



int main(){
 
    int bt,at,p;
	char col;
    int wt=0,tat=0,ct=0,count=0,sum=0;
	struct LinearQueue lq;
	
	initializeQueue(&lq);
   ifstream fin("input.txt");
	if(fin == NULL){
      cout<<"The File Not Exist !!";   
      exit(1);             
   }
   insert(&lq,0);
    while(fin >> bt>> col >>at >> col>> p){
	count++;	
	insert(&lq,bt);
 }
 printLinearQueue(&lq,count);
 	


    return 0;
   }
