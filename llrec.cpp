#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot)
{
    smaller = nullptr;
    larger = nullptr;
 
    if (head == NULL)
    {
        
        return;
    }
    else if (head->val <= pivot)
    {
        smaller = head;
        Node* tmep = head->next;
        head = nullptr;
        llpivot(tmep, smaller->next, larger, pivot);
        if(smaller->next != NULL)
        {
            if(smaller->next->val > pivot)
            {
                smaller->next = nullptr;
            }
        }
    }
    else
    {
        larger = head;
        Node* temp = head->next;
        head = nullptr;
        llpivot(temp, smaller, larger->next, pivot);
        if(larger->next != NULL)
        {
            if(larger->next->val < pivot)
            {
                larger->next = nullptr;
            }
        }
    }
    
       
}



