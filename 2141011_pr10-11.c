#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};
struct Node* head = NULL;
int main()
{
  int num,choice,data1,position,after,size;
  system("cls");
  cyan();
  printf("\n\t-==-=-=Program 11-==-=-\n\n\tLinked List Creation , Insertion and Deletion \n\n ");
  error:
  printf("Enter the Number Of Data You Want to Insert : ");
  scanf("%d",&num);
  if(num<1 || num > 100)
  {
      printf("\n\tINVALID INPUT !! Input data between 1 and 100 ( Inclusive )\n");
      goto error;
  }
  reset();
 
for(int i=0;i<num;i++)
{
    int data;
    printf("Enter the Data %d : ",i+1);
    scanf("%d",&data);
    append(&head, data);
}
  printf("\n Created Linked list is: ");
  cyan();
  printList(head);
  reset();
    printf("\n");
    re:
    green();
    printf("\n\t-=-=-=Menu-=-=-=-=\n");
    printf("\n\t -=-=-=-Insertion-=-=-=-=- \n 1.) Insert A New Element in The Front Of the List \n 2.) Insert At a given Postion \n 3.) Insert At The End \n 4.) Print The Whole Lsit \n 5.) Insert At A Specific Location  \n 6.) Insert After A Specific Data \n\t -=-=-Deletion-=-=-= \n 7.) Delete Element At A Position  \n 8.) Delete First Element \n 9.) Delete The First Occurance Of the Element \n 10.) Exit \n Choice : ");
    scanf("%d",&choice);
    reset();
    switch(choice)
    {
        case 1 : 
            printf("\n\tInsert Element In the Front OF the List\n");
            printf("Enter the Element You Want To Insert :");
            scanf("%d",&data1);
            push(&head,data1);
            goto re;
        case 2 :
            printf("Enter the Position You Want to Insert After : ");
            scanf("%d",&position);
            printf("Enter the Element You Want to Insert : ");
            scanf("%d",&data1);
            insertPosition(position,data1,&head);
            goto re;
        case 3 :
            printf("\n\tInsert A Element At the Last\n ");
            printf("Enter the Element : ");
            scanf("%d",&data1);
            append(&head,data1);
            goto re;
        case 4 :
            printList(head);
            goto re;
        case 5 :
            printf("Enter the Position You Want to Insert At : ");
            scanf("%d",&position);
            printf("Enter the Element You Want to Insert : ");
            scanf("%d",&data1);
            insertPosition(position-1,data1,&head);
            goto re;
        case 6 :
                printf("\nEnter the Data To Insert After : ");
                scanf("%d",&after);
                printf("\nEnter the Data to Be Inserted : ");
                scanf("%d",&data1);
                insert_after(head,after,data1,&head);
                goto re;
        case 7 :
                size=calcSize(head);
                printf("Enter the Position To Be Deleted : ");
                scanf("%d",&data1);
                data1--;
                if(data1<size && data1>0)
                    delete(data1);
                else
                    printf("\n The Entered Position Is Invalid ! \n ");
                goto re;
        case 8 :
                beginningdelete();
                printf("\nThe First Element Has Been Deleted From the List \n");
                goto re;
        case 9 :
                printf("Enter the Element to be Deleted : ");
                scanf("%d",&data1);
                deleteNode(&head,data1);
                printf("The First Occurance Of %d has been deleted from the list",data1);
                goto re;
        case 10 :
                red();
                printf("\n\t-=-=-Program Ended-=-=\n");
                reset();
                break;
        default:
                red();
                printf("\nInvalid Choice\n");
                reset();
                goto re;
    }
  return 0;
}
//function defining Starts
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void insertPosition(int pos, int data, struct Node** head)
{
    int size = calcSize(*head);
    if(pos < 1 || size < pos) 
    { 
        red();
        printf("Can't insert, %d is not a valid position\n",pos); 
        reset();
    } 
    else 
    { 
        struct Node* temp = *head; 
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
        newNode->data = data;
        newNode->next = NULL;

        while(--pos)
        {
            temp=temp->next;
        }
        newNode->next= temp->next;
        temp->next = newNode;
    }
}
 

void append(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;  
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
 

void printList(struct Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}

int calcSize(struct Node* node){
    int size=0;
    while(node!=NULL){
        node = node->next;
        size++;
    }
    return size;
}

void insert_after(struct Node *list, int knownData, int data,struct Node** head)
{
  struct Node *temp = (struct node*)malloc(sizeof(struct Node));
  temp->data = data;
  int size = calcSize(*head);
  int count=0;
  while(list->data != knownData || count >= size )
    {
    int size = calcSize(*head);
    list = list->next;
    count++;
    if (count==size)
    {
        goto next;
    }
}
next:
    if(count>=size)
        {
            red();
            printf("\n The Searched Element Is Not Found In The List !! \n");
            reset();
        }
    else
        {
            temp->next = list->next;
            list->next = temp;
            yellow();
            printf("\nSuccessfully Inserted After %d \n",knownData); 
            reset();           
        }
}

void delete(int pos)
{
    struct Node *temp = head;   
    int i;                   
    if(pos==0)
    {
        printf("\nElement deleted is : %d\n",temp->data);
        head=head->next;       
        temp->next=NULL;
        free(temp);             
    }
    else
    {
        for(i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        struct Node *del =temp->next;      
        temp->next=temp->next->next;
        printf("\nElement deleted is : %d\n",del->data);      
        del->next=NULL;
        free(del);                          
    }
}

void beginningdelete()  
    {  
        struct Node *ptr;  
        if(head == NULL)  
        {  
            printf("\nList is empty");  
        }  
        else   
        {  
            ptr = head;  
            head = ptr->next;  
            free(ptr);   
        }  
    } 

void deleteNode(struct Node** head_ref, int key)
{

    struct Node *temp = *head_ref, *prev;
 

    if (temp != NULL && temp->data == key) 
    {
        *head_ref = temp->next; 
        free(temp); 
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
 

    if (temp == NULL)
        return;
 

    prev->next = temp->next;
 
    free(temp); 
}

//colour defining

void red () 
{
  printf("\033[1;31m");
}
void yellow() 
{
  printf("\033[1;33m");
}
void reset () 
{
  printf("\033[0m");
}
void green()
{
    printf("\033[0;32m");
}
void purple()
{
    printf("\033[0;35m");
}
void cyan()
{
    printf("\033[0;36m");
}

