#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct stacks
{
    int value;
    struct stacks *next;
};

struct stacks *getNode(int);
struct stacks *enqueue(struct stacks *,int);
int dequeue(struct stacks **);

int main()
{
struct stacks *head;
head = NULL;


int i,j,k,l=0,p=0,q=0,v=0,element;
int *x,*y,*A,*visited;                  // x is for first vertex . y is for second vertex . A stores the (index+1) for each element
char a,b,c,d,sp[4];
FILE *fp,*fp1;
char *line = NULL;
size_t len = 0;
ssize_t read;
fp=fopen("output.txt","r");    //output is the output file generated from GTgraph. Output1 contains only the edge list
fp1=fopen("output1.txt","w");
for(i=0;i<7;i++)
  {
   read=getline(&line, &len, fp);
   //printf("Retrieved line of length %zu :\n", read);
   //printf("%s", line);
  }
free(line);

int max=0;

fscanf(fp, "%c %s %d %d\n", &a,sp,&max,&p);    // p is number of edges . max is number of vertices.

x=(int *)malloc(sizeof(int)*p);                 // here p=15 and num of vertices= 20
y=(int *)malloc(sizeof(int)*p);

while(fscanf(fp, "%c %d %d %d\n", &a,&i,&j,&k)!= -1)
 {
 fprintf(fp1, "%d %d\n",i,j);
   x[l]=i;
   y[l]=j;
   l++;

}

free(fp);
free(fp1);

max++;
printf("max and p= %d %d\n",max,p);

A=(int *)malloc(sizeof(int)*max);
visited=(int *)malloc(sizeof(int)*max);

for(i=0;i<max;i++)
{
A[i]=0;
visited[i]=0;
}

 for (i=0;i<p;i++)
  {
    if(A[x[i]]==0)
     { A[x[i]]=i+1;
    }
  }
for(i=0;i<p;i++)
{
printf("%d ",x[i]);
}
printf("\n");
for(i=0;i<p;i++)
{
printf("%d ",y[i]);
}
printf("\n");
for(i=0;i<max;i++)
{

  printf("%d ",A[i]);

}
printf("\n");


printf("Enter the root node\n");
scanf("%d",&v);

visited[v]=1;
head = enqueue(head,v);
//enqueue(v)

while(head != NULL)
    {
        element = dequeue(&head);
         v=element;
        printf("%d-->",v);
            i=A[v]-1;
			if(i>=0){
			 j=x[i];
			 while(j==x[i])
         {
         
            if(visited[y[i]]==0)
		{
		  visited[y[i]]=1;
                  head = enqueue(head,y[i]);
                  
                }
				i++;

          }
			}
			
		  
     }
}

int dequeue(struct stacks **head)
{
    int element;
    struct stacks *temp;
    temp = *(head);
    element = (*head)->value;
    *head = (*head)->next;
    free(temp);
    return element;
}


struct stacks *enqueue(struct stacks *head,int value)
{
    struct stacks *temp,*node;
    node = getNode(value);
    temp = head;
    if (head == NULL)
    {
        head = node;
        return head;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
        return head;
    }

}

struct stacks *getNode(int value)
{
    struct stacks *newnode;
    newnode = (struct stacks *)malloc(sizeof(struct stacks));
    newnode->value = value;
    newnode->next = NULL;
    return newnode;
}
