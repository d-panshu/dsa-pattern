#include <bits/stdc++.h>
using namespace std;


class node{
    public:
    int val;
    node* next;
    node(int data){
        val = data;
        next = NULL;
    }
};


node *detectcycle(node* head){
    if(!head || !head->next) return NULL;

    node* slow = head;
    node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast){
            node* entry = head;
            while(entry != slow){
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }
    return NULL;
}