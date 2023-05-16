/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *forw;
    struct node *back;
    
}*start=NULL,*newnode,*ptr,*loc,*temp;
void display(struct node *);
void addBeg(int);
void addEnd(int);
void addAtLoc(int,int);
void addAfterLoc(int,int);
void deleteAtLoc(int);
int search(int);
int main()
{
    int ch,item,l;
    do{
   
        printf("\n Doubly LINKED LIST (TWO WAY LINKED LIST)");
        printf("\n 1. Insert item at beginning");
        printf("\n 2. Insert item at end of list");
        printf("\n 3. Insert item at location");
        printf("\n 4. Insert item after location.");
        printf("\n 5. Delete item at particular location");
        printf("\n 6. Display List");
        printf("\n 7. Search for an item");
        printf("\n 8. Exit");
        printf("\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                printf("\n Enter item to insert: ");
                scanf("%d",&item);
                addBeg(item);
                break;
            case 2:
                printf("\n Enter item to insert: ");
                scanf("%d",&item);
                addEnd(item);
                break;
            case 3:
                printf("\n Enter item to insert: ");
                scanf("%d",&item);
                printf("\n Enter location at which you want to insert: ");
                scanf("%d",&l);
                addAtLoc(item,l);
                break;
            case 4:
                printf("\n Enter item to insert: ");
                scanf("%d",&item);
                printf("\n Enter location after which you want to insert: ");
                scanf("%d",&l);
                addAfterLoc(item,l);
                break;
            case 5:
                printf("\n Enter location to delete: ");
                scanf("%d",&l);
                deleteAtLoc(l);
                break;
            case 6:
                display(start);
                break;
            case 7:
                printf("\n Enter item to search: ");
                scanf("%d",&item);
                l=search(item);
                if(l==-1)
                {
                    printf("\n %d not found.",item);
                
                }
                else
                {
                    printf("\n %d found at %d ",item,l);
                }
                break;
                
        }
    }while(ch!=8);

    return 0;
}

void addBeg(int item)
{
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->info=item;
    newnode->forw=start;
    newnode->back=NULL;
    start=newnode;
    display(start);
}

void addEnd(int item)
{
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->info=item;
    if(start==NULL)
    {
        newnode->forw=start;
        newnode->back=NULL;
        start=newnode;
    }
    else
    {
        ptr=start;
        while(ptr->forw!=NULL)
        {
            ptr=ptr->forw;
        }
        ptr->forw=newnode;
        newnode->back=ptr;
        newnode->forw=NULL;
    }
    display(start);
}
void addAtLoc(int item,int l)
{
    int c=0;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->info=item;
    if(l==1)
    {
        newnode->forw=start;
        newnode->back=NULL;
        start=newnode;
        
    }
    else
    {
      ptr=start;
      while(ptr!=NULL)
      {
          c++;
          if(c==l-1)
          {
      
             newnode->forw=ptr->forw;
             ptr->forw=newnode;
             ptr->forw->back=newnode;
             newnode->back=ptr;
             break;
          }
          ptr=ptr->forw;
      }
    }
    
    display(start);
    
}
void addAfterLoc(int item,int l)
{
    int c=0;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->info=item;
    
      ptr=start;
      while(ptr!=NULL)
      {
          c++;
          if(c==l)
          {
             
             newnode->forw=ptr->forw;
             ptr->forw=newnode;
             ptr->forw->back=newnode;
             newnode->back=ptr;
             break;
          }
          ptr=ptr->forw;
      }
    
  
    display(start);
    
}
void display(struct node *ptr)
{
    printf("NULL<-");
    while(ptr!=NULL)
    {
        printf("<-%d->",ptr->info);
        ptr=ptr->forw;
    }
    printf("NULL");
}
void deleteAtLoc(int l)
{
    int c=0;
    if(l==1)
    {
        temp=start;
        start=start->forw;
        start->back=NULL;
    }
    else
    {
        ptr=start;
        while(ptr!=NULL)
        {
            c++;
            if(c==l-1)
            {
                temp=ptr->forw;
               ptr->forw=ptr->forw->forw;
               ptr->forw->back=ptr;
               
            }
            ptr=ptr->forw;
        }
    }
    free(temp);
    display(start);
}
int search(int item)
{
    int l=-1,c=0;
    ptr=start;
    while(ptr!=NULL)
    {
        c++;
        if(item==ptr->info)
        {
            l=c;
           break;
        }
        ptr=ptr->forw;
    }
   return l;
}