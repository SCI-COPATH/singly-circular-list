#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void insertionStart(struct node **tail,int value){
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    if(*tail==NULL){
        *tail=newNode;
        newNode->link=newNode;
    }
    else{
        newNode->link=(*tail)->link;
        (*tail)->link=newNode;
    }
}
void insertionEnd(struct node **tail,int value){
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    if(*tail==NULL){
        *tail=newNode;
        newNode->link=newNode;
    }
    else{
        newNode->link=(*tail)->link;
        (*tail)->link=newNode;
        (*tail)=newNode;
    }
}
void insertionMid(struct node **tail,int pos,int value){
    if(pos<=1){
        printf("Wrong input");
        return;
    }
    struct node *newNode,*temp=*tail;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    while(--pos){
        temp=temp->link;
    }
    newNode->link=temp->link;
    temp->link=newNode;
    
}
void deleteStart(struct node **tail){
    struct node *temp;
    if(*tail==(*tail)->link){
        free(*tail);
        *tail=NULL;
    }
    else{
        temp=(*tail)->link;
        (*tail)->link=temp->link;
        printf("Remove %d\n",temp->data);
        free(temp);
        temp=NULL;
    }
}
void deleteEnd(struct node **tail){
    struct node *temp,*remove;
    if(*tail==(*tail)->link){
        free(*tail);
        *tail=NULL;
    }
    else{
        temp=(*tail)->link;
        while(temp->link!=*tail){
            temp=temp->link;
        }
        remove=temp->link;
        temp->link=(*tail)->link;
        *tail=temp;
        printf("Remove %d\n",remove->data);
        free(remove);
        remove=NULL;
    }
}
void deleteMid(struct node **tail,int pos){
    struct node *temp,*ptr=*tail;
    if(pos<=1)
        printf("Wrong input");
    else{
        while(--pos)
            ptr=ptr->link;
        temp=ptr->link;
        ptr->link=temp->link;
        printf("Remove %d\n ",temp->data);
        free(temp);
        temp=NULL;
    }
}
void view(struct node *tail){
    struct node *ptr=tail;
    if(tail==NULL)
        printf("Empty list\n");
    else{
        printf("LIST IS \n");
        do{
            ptr=ptr->link;
            printf("%d\n",ptr->data);
        }while(ptr!=tail);
    }

}
void main(){
    struct node* tail=NULL;
    int dis ,value,pos;
    do{
        printf("1-INSERTION AT START\n2-INSERTION AT END\n3-INSERTION AT INTERMEDIATE POSITION\n4-DELETE FORM FRONT\n5-DELETE FORM END\n6-DELETE FORM INTERMEDIATE POSITION\n7-EXIT\nENTER :");
        scanf("%d",&dis);
        switch(dis){
            case 1:printf("Enter value :");
                    scanf("%d",&value);
                    insertionStart(&tail,value);
                    view(tail);
                    break;
            case 2:printf("Enter value :");
                    scanf("%d",&value);
                    insertionEnd(&tail,value);
                    view(tail);
                    break;
            case 3:printf("Enter value :");
                    scanf("%d",&value);
                    printf("Enter position :");
                    scanf("%d",&pos);
                    insertionMid(&tail,pos,value);
                    view(tail);
                    break;
            case 4:deleteStart(&tail);
                    view(tail);
                    break;
            case 5:deleteEnd(&tail);
                    view(tail);
                    break;
            case 6: printf("Enter position :");
                    scanf("%d",&pos); 
                    deleteMid(&tail,pos);
                    view(tail);
                    break;
            case 7:break;
            default :printf("Wrong input\n");
        }

    }while(dis!=7);

}