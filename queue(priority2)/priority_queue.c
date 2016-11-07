#include<stdio.h>
//#define size 5
int size;
void insert();
void delete();
void display();
struct p{
	int data;
	int prior;
};
typedef struct p pqueue;
int main(void){
	puts("Enter the size of priority queue ");
	scanf("%d",&size);
	pqueue queue[size];
	int rear=-1,front=0,num=1,count=0;
	while(num){
		puts("1.Insert into queue");
		puts("2.Delete from queue");
		puts("3.Display queue");
		puts("0.Exit");
		printf("Choose Option :");
		scanf("%d",&num);
		switch(num){
			case 1:
                   insert(queue,&rear,&front,&count);
                   break;
            case 2:
                   delete(queue,&front,&count);
                   break;
			case 3:
                   display(queue,rear,front,&count);
                   break;	          
		}
	}
}
//Insert Function
void insert(pqueue *q,int *r,int *f,int *c){
	int val,i,j,temp,temp1,priority;
	if(*c == size || *r >= size-1){
		puts("Queue is full");
		return;
	}
	puts("Enter the no u wanna insert");
	scanf("%d",&val);
	puts("Enter its priority");
	scanf("%d",&priority);
	(*r)++;
	(*c)++;
	q[*r].data=val;
	q[*r].prior=priority;
	
	puts("Inserted Succesfuly");
	for(i= *f;i<= *r;i++){
		for(j = i+1;j <= *r ; j++){
			if(q[i].prior	 >  q[j].prior	){
			temp=q[i].data;
			temp1=q[i].prior;
			q[i].data=q[j].data;
			q[i].prior=q[j].prior;
			q[j].data=temp;
			q[j].prior=temp1;	
			}
		}
	}
}

//delete function
void delete(pqueue *q,int *f,int *c){
	if(*c == 0 ){
		puts("Queue is empty");
		return;
	}
	printf("Element Deleted is : %d\n",q[*f].data);
	q[*f].data=0;
	q[*f].prior=0;
	(*f)++;
	(*c)--;
	puts("Deleted Succesfuly");
}


//display function
void display(pqueue	*q,int r,int f,int *c){
	int i,co=*c;
    if(*c == 0){
    	puts("Nothing to display");
    	return;
    }
	puts("List is :");
	for(i=f;co>0;i++){
		printf("\t%d -- %d",q[i].data,q[i].prior);
		co--;
	}
	printf("\n");
    puts("Displayed Succesfuly");
}