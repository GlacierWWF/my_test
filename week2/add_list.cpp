#include <iostream>
#include<cstdlib>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}  //初始化当前节点的值为x，指针的下一个节点为空
};

int main()
{return 0;}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    int len1=0,len2=0;  //保存链表的长度
    int i,n;
    ListNode *head1, *head2,*temp_long,*temp_short;
    if((l1==NULL)&&(l2==NULL))
    {
        return NULL;
    }
    else
    {
        head1=l1;
        head2=l2;
        while(head1!=NULL)
        {
            len1++;
            head1=head1->next;
        }
        while(head2!=NULL)
        {
            len2++;
            head2=head2->next;
        }
        n=len1>len2 ? len1:len2;
        temp_long=len1>len2 ? l1:l2;
        temp_short=len1>len2 ? l2:l1;
        int* value=NULL;
        value=new int[n];
        int sign=0;  //是否有进位
        for(i=0;i<n;i++){
        if((i<n-len1)||(i<n-len2))
        {
            value[i]=temp_long->val;
            temp_long=temp_long->next;
        }
        else{
            value[i]=temp_long->val + temp_short->val + sign;
            sign=0;  //标记为归零
            if(value[i]>9)
            {
                value[i]=value[i] % 10;
                sign=1;  //说明有进位
            }
            temp_long=temp_long->next;
            temp_short=temp_short->next;
        }
 }
        ListNode *head,*normal,*end;
        head=(ListNode *)malloc(sizeof(ListNode));
        head->val=value[0];
        end=head;
        for(int i=1;i<n;i++)
        {
            normal=(ListNode*)malloc(sizeof(ListNode));
            normal->val=value[i];
            end->next=normal;
            end=normal;
        }
        if(sign==1){
        normal=(ListNode*)malloc(sizeof(ListNode));
        normal->val=1;
        end->next=normal;
        end=normal;}
        end->next=NULL;
        delete [] value;
        return head;
        }
}
