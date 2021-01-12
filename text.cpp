#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    char kata[100];

    Node *next;
    Node *prev;

}*head, *tail;

Node *createNode(const char *kata){
    Node *temp = (Node *) malloc(sizeof(Node));
    strcpy(temp -> kata, kata);
    temp -> next = NULL;
    temp -> prev = NULL;
}

void pushHead(const char *kata){
    Node *temp = createNode(kata);
    
    if(!head){
        head = tail = temp;
    }

    else{
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }

}

void pushTail(const char *kata){
    Node *temp = createNode(kata);

    if(!head){
        head = tail = temp;
    }
    else{
        temp -> prev = tail;
        tail -> next = temp;
        tail = temp;
    }
}

void popHead(){
    if(!head){
        return;
    }

    else{
        Node *temp = head -> next;
        head -> next = NULL;
        temp -> prev = NULL;
        head = NULL;
        free(head);
        head = temp;
    }
}

void popTail(){
    if(!head){
        return;
    }
    else{
        Node *temp = tail -> prev;
        temp -> next = NULL;
        tail -> prev = NULL;
        tail = NULL;
        free(tail);
        tail = temp;
    }
}

void popMid(const char *kata){
    if(!head){
        return;
    }

    else if(strcmp(kata, head -> kata) == 0){
        popHead();
    }
    else if(strcmp(kata, tail -> kata) == 0){
        popTail();
    }
    else{
        Node *curr = head;

        while(curr != NULL && strcmp(kata, curr -> kata) != 0){
            curr = curr -> next;
        }

        if(!curr){
            printf("Kata tidak ada\n");
            return;
        }

        curr -> prev -> next = curr -> next;
        curr -> next -> prev = curr -> prev;
        curr -> next = NULL;
        curr -> prev = NULL;
        curr = NULL;
        free(curr);

    }

}

void print(){
    Node *curr = head;
    while(curr){
        printf("%s ",curr -> kata);
        curr = curr -> next;
    }
    printf("\n");
}

int main(){
    int n;
    char kata[100];


    while(n != 4){
    printf("\n");
    printf("Mau masukkan kata pilih 1 \nkalau mau hapus pilih 2\npilih 3 untuk print\npilih 4 untuk stop\n");
    printf(">> ");
    scanf("%d",&n);

        if(n == 1){
            printf("Masukkan kata: ");
            scanf("%s",&kata);
            pushTail(kata);
        }

        else if(n == 2){
            printf("Masukkan kata yang mau dihapus : ");
            scanf("%s",&kata);
            popMid(kata);
        }

        else if(n == 3){
            print();
        }

    }

    
}