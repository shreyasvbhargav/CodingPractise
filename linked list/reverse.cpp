/*given a list of size n, and factor key k,
reverse the list such a way that every k elements in the list are reversed
Eg: 
ip = 1->2->3->4->5->6
k = 3
op = 3->2->1->6->5->4
*/

#include<iostream>
#include<stack>
using namespace std;

typedef struct LL{
    int v;
    struct LL *next;
}LL;

LL* newNode(int val){
    LL *node = (LL *)malloc(sizeof(LL));
    node->v = val;
    node->next = NULL;
    return node;
}

LL* createList(){
    int i = 1;
    LL *head = newNode(i++);
    LL *cur = head;

    for(; i<11; i++)
    {
        cur->next = newNode(i);
        cur = cur->next;
    }
    return head;
}

void printList(LL *head){
    LL *cur = head;
    while(cur){
        cout<<cur->v<<", ";
        cur = cur->next;
    }
    cout<<endl;
}


// 3->2->1->4->5->6
// 6->5->4->3

LL* reverseList(LL **head, int k){
    int i=0;
    LL* prev = NULL, *cur = *head, *next;

    if(head)
        next = (*head)->next;
    
    while(i<k && cur){
        cur->next = prev;
        prev = cur;
        cur = next;
        if(next)
            next = next->next;
        i++;
    }
    *head = cur;
    
    return prev;
}

LL* reverseLink(LL *head, int k){
    LL *prev = NULL, *cur = head, *nextNode = head->next;
    LL *tmp_head = head, *tmp_tail = NULL, *ret_head = NULL;
    int i=0;

    tmp_tail = cur;
    while(cur){
        tmp_head = reverseList(&cur, k);
        if(ret_head==NULL)
            ret_head = tmp_head;
        else
            tmp_tail->next = tmp_head; 

        while(tmp_tail->next)
            tmp_tail = tmp_tail->next;
    }   
    tmp_tail->next = NULL;
    printList(ret_head);

    return ret_head;
}

LL *reverse_swapElements(LL *head, int k){
    int i=0;
    LL *cur=head, *start = cur;
    stack<int> st;
    while(cur){
        while((i < k) && (cur)){
            st.push(cur->v);
            cur = cur->next;
            i++;
        }

        i=0;
        while(!st.empty()){
            start->v = st.top();
            start = start->next;
            st.pop();
        }
    }
    return head;
}

int main(){
    int k =3;
    
    LL *head = createList();

    printList(head);

    head = reverseLink(head, k);
    //head = reverse_swapElements(head, k);
    //printList(head);
}