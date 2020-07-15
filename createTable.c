#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "func.h"
#define ARRSIZE(arr) (sizeof(arr)/sizeof(*(arr)))

void createTable (float exec[], int period[], int deadine[], int hp,size_t arr_size,int frameSize)
{
   int noOfFrames=hp/frameSize;
   int temp_size=0;
   int a[arr_size];
   int b[]={0,0,0};
   int arrival[]={0,0,0};
   for(int i=0;i<arr_size;i++){
   a[i]=hp/period[i];
   //printf("%d",a[i]);
   //printf("\n");
   }
   for(int i=0;i<arr_size;i++)
   temp_size+=a[i];
   //printf("%d",temp_size);
   //printf("\n");
   float temp[temp_size];
   
   float temp1[arr_size][3];
   float temp2[hp-1][4];
   float temp4[temp_size][4];
   
   
   
   for(int k=0;k<arr_size;k++)
   {
        for(int l=0;l<3;l++)
        {
            if(l==0)
            temp1[k][l]=period[k];
            else if(l==1)
            temp1[k][l]=exec[k];
            else if(l==2)
            temp1[k][l]=deadine[k];
        }
   }
   /*for(int k=0;k<arr_size;k++)
   {
        for(int l=0;l<3;l++)
        {
            printf ("%d", temp1[k][l]);printf ("\t");
        }
        printf ("\n");
   }*/
   int h=0;
   char s1[20]; 
   char s2[20];
  
   for(int k=0;k<hp;k++)
   {
       if(a[k%arr_size]>0)
       {
           
        for(int l=0;l<4;l++)
        {
            
            if(l==0)
            temp2[k][l]=0/*arrival[k%arr_size]*/+b[k%arr_size]*period[k%arr_size];
            else if(l==1)
            temp2[k][l]=exec[k%arr_size];
            else if(l==2)
            temp2[k][l]=temp2[k][0]+deadine[k%arr_size];
            else if(l==3)
             
            {
            // Convert both the integers to string 
            sprintf(s1, "%d",k%(int)arr_size+1); 
            sprintf(s2, "%d", 1+b[k%arr_size]); 
          
            // Concatenate both strings 
            strcat(s1, s2); 
          
            // Convert the concatenated string 
            // to integer 
            
            temp2[k][l]=atoi(s1);}
        }
       
       a[k%arr_size]-=1;
       b[k%arr_size]+=1;
        
       }
       
       else
       {
           
        for(int l=0;l<4;l++)
        {
            
            if(l==0)
            temp2[k][l]=0;
            else if(l==1)
            temp2[k][l]=0;
            else if(l==2)
            temp2[k][l]=0;
            else if(l==3)
             
            {
            // Convert both the integers to string 
            sprintf(s1, "%d",0); 
            sprintf(s2, "%d", 0); 
          
            // Concatenate both strings 
            strcat(s1, s2); 
          
            // Convert the concatenated string 
            // to integer 
            
            temp2[k][l]=atoi(s1);}
        }
       
       //a[k%arr_size]-=1;
       //b[k%arr_size]+=1;
        
       }
        
       
   }
   
    /*for(int k=0;k<hp;k++)
   {
        for(int l=0;l<4;l++)
        {
            printf ("%d", temp2[k][l]);printf ("\t");
        }
        printf ("\n");
   }*/
   
  int k=2;
  float temp3 ;
 for(int i=0;i<hp;i++)
        {
                for(int j=i+1;j<hp-1;j++)
                {
                        if(temp2[i][k] > temp2[j][k])
                        {
                            for(int x=0;x<4;x++) {
                                temp3=temp2[i][x];
                                temp2[i][x]=temp2[j][x];
                                temp2[j][x]=temp3;
                                }
                        }
                }
        }

 /*printf ("\n");
 printf ("\n");
 printf ("\n");
 for(int k=0;k<hp;k++)
   {
        for(int l=0;l<4;l++)
        {
            printf ("%f", temp2[k][l]);printf ("\t");
        }
        printf ("\n");
   }*/
   int p=0,q=0;
   for(int k=0;k<hp;k++)
   {
       if(temp2[k][3]!=0){
        for(int l=0;l<4;l++)
        {
           temp4[p][q]=temp2[k][l];q++;
        }
        //printf ("\n");
        p++;q=0;}
   }
   
  /*for(int k=0;k<temp_size;k++)
   {
        for(int l=0;l<4;l++)
        {
            printf ("%d", temp4[k][l]);printf ("\t");
        }
        printf ("\n");
   }*/
   
    // A structure to represent an adjacency list node 
struct AdjListNode 
{ 
    int dest;
    float st;
    float end;
    struct AdjListNode* next; 
}; 
  
// A structure to represent an adjacency list 
struct AdjList 
{ 
    struct AdjListNode *head;  
}; 
  
// A structure to represent a graph. A graph 
// is an array of adjacency lists. 
// Size of array will be V (number of vertices  
// in graph) 
struct Graph 
{ 
    int V; 
    struct AdjList* array; 
}; 
  
// A utility function to create a new adjacency list node 
struct AdjListNode* newAdjListNode(int dest,float st,float end) 
{ 
    struct AdjListNode* newNode = 
     (struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
    newNode->dest = dest;
    newNode->st = st;
    newNode->end = end;
    newNode->next = NULL; 
    return newNode; 
} 
  
// A utility function that creates a graph of V vertices 
struct Graph* createGraph(int V) 
{ 
    struct Graph* graph =  
        (struct Graph*) malloc(sizeof(struct Graph)); 
    graph->V = V; 
  
    // Create an array of adjacency lists.  Size of  
    // array will be V 
    graph->array =  
      (struct AdjList*) malloc(V * sizeof(struct AdjList)); 
  
    // Initialize each adjacency list as empty by  
    // making head as NULL 
    int i; 
    for (i = 0; i < V; ++i) 
        graph->array[i].head = NULL; 
  
    return graph; 
} 
  
// Adds an edge to an undirected graph 
void addEdge(struct Graph* graph, int src, int dest,float st,float end) 
{ 
    // Add an edge from src to dest.  A new node is  
    // added to the adjacency list of src.  The node 
    // is added at the begining 
    struct AdjListNode* newNode = newAdjListNode(dest,st,end); 
    newNode->next = graph->array[src].head; 
    graph->array[src].head = newNode; 
  
    // Since graph is undirected, add an edge from 
    // dest to src also 
    /*newNode = newAdjListNode(src); 
    newNode->next = graph->array[dest].head; 
    graph->array[dest].head = newNode; */
} 
  


// A utility function to print the adjacency list  

void printTasks(struct Graph* graph,float arr[],int frameSize) 
{ 
    int v; 
    int num;
    FILE *fptr;
    fptr = fopen("periodicSchedule.txt","w");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   
   
    for (v = 0; v < graph->V ; ++v) 
    { 
        struct AdjListNode* pCrawl = graph->array[v].head; 
        //printf("\n Adjacency list of vertex %d\n head ", v); 
        fprintf(fptr,"%d\t%0.2f\t",v,frameSize-arr[v]);
        
        while (pCrawl) 
        { 
            fprintf(fptr,"%d-%0.2f-%0.2f\t",pCrawl->dest,pCrawl->st,pCrawl->end);
            //printf("-> %d", pCrawl->dest); 
            pCrawl = pCrawl->next; 
        }
        if(v < (graph->V)-1)
        fprintf(fptr,"\n");
        //printf("\n"); 
    } 
    
    fclose(fptr);
}  

   
   
   int V = noOfFrames;  
   struct Graph* graph = createGraph(V);  
    
   float arr[noOfFrames];
   for(int k=0;k<noOfFrames;k++)
   {
       arr[k]=0;
   }
   for(int k=0;k<temp_size;k++)
   {
       for(int l=0;l<noOfFrames;l++)
       {
           if(temp4[k][0]<=l*frameSize&&arr[l]+temp4[k][1]<=frameSize )
           {
            addEdge(graph, l,temp4[k][3],l*frameSize+arr[l], l*frameSize+arr[l]+temp4[k][1]);
    	    arr[l]+=temp4[k][1];
    	    break;
           }
        
       }
      
    }

	//for(int k=0;k<noOfFrames;k++)
	 //printf("\n  %0.2f\n ", arr[k]); 
   
   printTasks(graph,arr,frameSize); 
}
