#include <iostream>
#include<stdio.h>
#include <fstream>
#include <stdlib.h>
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
void fcfs(struct LinearQueue *a,struct LinearQueue *b,int count )
{
	
	ofstream file; 
    file.open("FCFS.txt");
	int x,y,z=0,count1=0,sum=0,sum2=0,wt=0,count3=0,cntr=1;
	struct LinearQueue temp,temp2;
	initializeQueue(&temp);
	initializeQueue(&temp2);
	count-1;
	cout<<"Process Waiting Times:"<<endl;
	while(!isQueueEmpty(a))
	{
		if(count1==count)
		break;
		x=remove(a);
        sum=sum+x;
        insert(&temp,sum);
	    count1++;      
	}
		while(!isQueueEmpty(&temp)){
			if(count1==count-1)
			break;
			x=remove(&temp);
			insert(&temp2,x);		
		}
	while(!isQueueEmpty(b))
	{
		x=remove(b);
		y=remove(&temp2);
		wt=y-x;
		z+=wt;
        cout<<wt<<endl;
        file<<"P"<<cntr++<<":"<<wt<<"\n";
	    count3++;
	}
		double avr;
		avr=z/count3;
	printf("Average Waiting Time: %0.1f   ms",avr,"\n");
	file<<"Average Waiting Time: "<<avr<<"  ms"<<endl;
    file.close(); 
	
	
}
int main(){
 
    int bt,at,p;
	char col;
    int wt=0,tat=0,ct=0,count=0,sum=0;
	struct LinearQueue lq,lq1;
	
   initializeQueue(&lq);
   initializeQueue(&lq1);
   ifstream fin("input.txt");
// 	if(fin == NULL)
// 	 {
//       cout<<"The File Not Exist !!";   
//       exit(1);             
//    }


	while(true){

	printf(" 1) Scheduling Method (None) \n2) Preemptive Mode (Off)\n3) Show Result\n4) End Program\nOption >");	
	break;
   	insert(&lq,0);
    while(fin >> bt>> col >>at >> col>> p){
	count++;	
	insert(&lq,bt);
	insert(&lq1,at);
 }
 }
 fcfs(&lq,&lq1,count);
    return 0;
   }
