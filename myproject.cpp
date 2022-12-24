#include <iostream>
#include<stdio.h>
using namespace std;
void  readinputs();
int main(){
   
readinputs();
   return 0;
}
void  readinputs(){
 FILE *fptr;
   int a, b, c,count=0,sum=0;
  
   fptr = fopen("input.txt","r");
   if(fptr == NULL){
      cout<<"The File Not Exist !!";   
      exit(1);             
   }
   while(fscanf(fptr,"%d:%d:%d", &a, &b, &c) == 3)
       {
        printf("%d : %d : %d\n", a, b, c);
    	sum+=a;
	    count++;
        }  
		 
    double avr=sum/count;  
    cout<<"Total is :"<<sum<<"\t"<<"Avrage is :"<<avr;	 
   fclose(fptr);}
