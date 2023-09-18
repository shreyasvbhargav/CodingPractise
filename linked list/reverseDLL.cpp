#include<iostream>
using namespace std;

typedef struct DLL{
    int val;
    struct DLL *next, *prev;
}DLL;

DLL* push(DLL *head, int v){
    DLL *node = new DLL();
    node->val = v;
    node->next = head;
    node->prev = NULL;

    if(head)
        head->prev = node;
    
    head = node;
    return head;
}

void print(DLL *head){
    DLL *cur = head;
    while(cur){
        cout<<cur->val<<", ";
        if(cur->next)
            cur=cur->next;
        else
            break;
    }
    // cout<<"\nReverse:\n";
    // while(cur){
    //     cout<<cur->val<<", ";
    //     if(cur->prev)
    //         cur=cur->prev;
    //     else
    //         break;
    // }
}

DLL* reverseLink(DLL **head, int k){
    DLL *cur=*head, *prev=NULL, *next;
    int i=0;
    if((*head)->next)
        next = (*head)->next;
    else
        return *head;
    
    while(cur && i<k){
        cur->next = prev;
        cur->prev = next;
        prev = cur;
        cur = next;
        if(next)
            next = next->next;
        i++;
    }
    //head = &cur;
    // cur->prev = next;
    // cur->next = prev;
    return prev;
}

void reverse(DLL *head, int k){
    DLL *cur = head;
    DLL *ret=NULL, *tmph = NULL, *tmpt = head;

    print(head);

   // while(cur)
   {
        tmph = reverseLink(&cur, k);
        if(ret == NULL)
            ret = tmph;
        else
            tmpt->next = tmph;
        
        while(tmpt->next)
            tmpt = tmpt->next;
    }
    print(ret);
}

int main(){
    int k =2;
    DLL *head = NULL;

    // head = push(head, 9);
    // head = push(head, 8);
    // head = push(head, 7);
    // head = push(head, 6);
    // head = push(head, 5);
    // head = push(head, 4);
    // head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1);

    //print(head);

    reverse(head, k);
}