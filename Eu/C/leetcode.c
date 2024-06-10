 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>


 //Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* result = malloc(sizeof(struct ListNode));
    if(!result){
        return NULL;
    }
    struct ListNode* answer = result;

    if(!list1 && !list2){
        answer = NULL;
        return answer;
    }
    else if(!list1){
        return list2;
    }
    else if(!list2){
        return list1;
    }

    if(list1->val < list2->val){
        answer->val = list1->val;
        list1 = list1->next;
    }
    else{
        answer->val = list2->val;
        list2 = list2->next;
    }

    while(list1 != NULL || list2 != NULL){
        if(list1 == NULL){
            answer->next = list2;
            break;
        }
        else if(list2 == NULL){
            answer->next = list1;
            break;
        }


        struct ListNode* tmp = malloc(sizeof(struct ListNode));
        if(tmp == NULL){
            return NULL;
        }
        tmp->next = NULL;

        if(list1->val > list2->val){
            tmp->val = list1->val;
            list1 = list1->next;
        }
        else{
            tmp->val = list2->val;
            list2 = list2->next;
        }

        answer->next = tmp;
    }
    
    return result;
}
