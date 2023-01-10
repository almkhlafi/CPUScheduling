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
/*_________________________SJF______________________________*/
struct Node
{
	int bt0=0;
	int bt=0;
	int at=0;
	int pid;
	struct Node *next;
};
void btswap(struct Node *a, struct Node *b)
{
	int temp = a->bt;
	a->bt = b->bt;
	b->bt = temp;

	temp = a->at;
	a->at = b->at;
	b->at = temp;

	temp = a->pid;
	a->pid = b->pid;
	b->pid = temp;
}

void atswap(struct Node *a, struct Node *b)
{
	int temp = a->at;
	a->at = b->at;
	b->at = temp;
}
void btSort(struct Node *start)
{
	int swapped, i;
	struct Node *ptr1;
	struct Node *lptr = NULL;

	if (start == NULL)
		return;

	do
	{
		swapped = 0;
		ptr1 = start;

		while (ptr1->next != lptr)
		{
			if (ptr1->bt > ptr1->next->bt)
			{
				btswap(ptr1, ptr1->next);
			//	atswap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;

	}
	while (swapped);

}
/* void atSort(struct Node *start)
{
	int swapped, i;
	struct Node *ptr1;
	struct Node *lptr = NULL;

	if (start == NULL)
		return;

	do
	{
		swapped = 0;
		ptr1 = start;

		while (ptr1->next != lptr)
		{
			if (ptr1->at > ptr1->next->at)
			{
				atswap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
	while (swapped);

}
*/
void push(struct Node** start_ref, int btt,int att,int p)
{

int c=0;
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	new_node->bt = btt;
	new_node->at = att;
	new_node->pid = p;
	 new_node->next = (*start_ref);
	(*start_ref) = new_node;
}

void printListl(struct Node *node, int count)
{
int count1=1,sum=0,sum2=0,wt=0;
	while (node != NULL)
	{
		//cout<<"P"<<node->pid<<":  "<<node->bt<<":"<<node->at<<endl;
		//if(count1==count)break;
		sum =sum+node->bt;
		sum2+=sum;
		//wt=sum-node->bt;
		cout<<"P"<<node->pid<<"  "<<sum<<":"<<node->at<<endl;
		node = node->next;count1++;
	}
	cout<<"\n________________________________________\n";
}

void printList(struct Node *node, int count)
{

int count1=1,sum=0,sum2=0;
	while (node != NULL)
	{


		//cout<<"P"<<node->pid<<":  "<<node->bt<<":"<<node->at<<endl;
		if(count1==count)break;
		sum =sum+node->bt;
		sum2+=sum;
		cout<<"P"<<node->pid<<"  "<<sum<<":"<<node->at<<endl;
		node = node->next;count1++;
	}
double avr=sum2/count;
printf("Average Waiting Time: %0.1f   ms",avr,"\n");
	cout<<"\n________________________________________\n";
}

int main(){

    int bt,at,p;
	char col;
    int wt=0,tat=0,ct=0,count=0,sum=0;
	struct LinearQueue lq,lq1;
struct Node *start = NULL;
   initializeQueue(&lq);
   initializeQueue(&lq1);
   ifstream fin("input.txt");
// 	if(fin == NULL)
// 	 {
//       cout<<"The File Not Exist !!";
//       exit(1);
//    }


	while(true){
	cout<<"choose scheduling method\n"<<endl;
	cout<<"1) Scheduling Method (None) \n2) Preemptive Mode (Off)\n3) Show Result\n4) End Program\nOption >";
	int choice=0;
    bool checked = false;

	cin>>choice;
	if(choice!=0 || choice>=1)
	switch (choice)
	{

	case 1 :


	while(!checked){
      int NonPre=0;
	cout<<"choose scheduling method\n1) First Come, First Served Scheduling\n2) Shortest Job First – Non-Preemptive\n3)Priority Scheduling – Non-Preemptive\n4) End Program\nOption >";
	cin>>NonPre;
	if(NonPre!=0 || NonPre>=1)
	switch (NonPre)
	{
    case 1 :cout<<"Scheduling Method: First Come First Served"<<endl;


	/*if(fin == NULL)
	 {
      cout<<"The File Not Exist !!";
      exit(1);
   }*/
//push(&start, 0,0);
    while(fin >> bt>> col >>at >> col>> p){
	count++;
	push(&start, bt,at,count);
 }
//	btSort(start);
	cout<<"\nShortest Job First (Non-preemptive) \n"<<endl;
	btSort(start);
	printListl(start,count);
	printList(start,count);
	break;
    case 2 :cout<<"Scheduling Method: Shortest Job First – Non-Preemptive"<<endl;

    break;
	case 3 :cout<<"Scheduling Method: Priority Scheduling – Non-Preemptive"<<endl;break;
	case 4 :exit(0);break;
	default:
	cout<<": None of scheduling method chosen \n Please Choose Correct Option From thr Menu"<<endl;
	}else{cout<<"Invalude input";
	 checked=false;
	 break;
	 }
	cout<<"Done !! \n Do you want to check again onther non-preemptive mathod !! Y or N"<<endl;
	char yn;
	cin>>yn;
	if(yn=='Y' || yn== 'y') checked=false;
	else if(yn=='N' || yn=='n')checked=true;
	}

    case 2 :


	while(!checked){
    int Pre;
	cout<<"choose scheduling method\n1) Shortest Job First –Preemptive\n2) Priority Scheduling –Preemptive\n3)Round Robin Scheduling – time_quantum=2\n4) End Program\nOption >";
	cin>>Pre;
	if(Pre!=0 || Pre>=1)
	switch (Pre)
	{
    case 1 :cout<<"Scheduling Method: Shortest Job First –Preemptive"<<endl;break;
    case 2 :cout<<"Scheduling Method: Priority Scheduling –Preemptive"<<endl;break;
	case 3 :cout<<"Round Robin Scheduling – time_quantum=2"<<endl;break;
	case 4 :exit(0);
	default:
	cout<<": None of scheduling method chosen \n Please Choose Correct Option From thr Menu"<<endl;
	}else{cout<<"Invalude input"; checked=false; break;}
	cout<<"Done !! \n Do you want to check again onther Preemptive mathod !! Y or N"<<endl;
	char yn;
	cin>>yn;
	if(yn=='Y' || yn== 'y') checked=false;
	else if(yn=='N' || yn=='n')checked=true;
	}

	case 3 :cout<<"Show Result"<<endl;break;
	case 4 :exit(0);
	default: cout<<"Invalid Input Please Check the Menu";
}else{cout<<"Invalude input";exit(0);}
}


 fcfs(&lq,&lq1,count);
    return 0;
   }
