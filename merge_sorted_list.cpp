#include <iostream>
using namespace std;


//Definition for singly-nexted list.
struct ListNode {
	int val;
        ListNode *next;
        
};

class Solution {
private:
	
	ListNode *head=NULL;

public:
    Solution(){}


    ~Solution(){}


    ListNode* append(ListNode* &head1,int data);
    void print(ListNode *&head1);
    int length(ListNode *&head1);
    void deleteNode(ListNode* &head1, int location);
    void insert(ListNode* &head1, int location,int data);
	
			
};
ListNode* Solution::append(ListNode* &head1,int data){
		ListNode *temp;
		temp=new ListNode;
		temp->val=data;
		temp->next=NULL;
		if (head==NULL){
			head=temp;
			//cout << head->val;
		}
		else{
			ListNode *p=head;
			while(p->next!=NULL){
			p=p->next;}
			p->next=temp;
		    }
		head1=head;
		return head1;
}
void Solution::insert(ListNode* &head1, int location,int data){
	ListNode *temp;
	temp=new ListNode;
	temp->val=data;
	temp->next=NULL;
	int len = length(head1);
	
	if (location>len){
		cout << "invalid input" << endl;}
	else{
		int i=1;
		ListNode *p=head1;
		

		while(i<location-1){
			p=p->next;
			i=i+1;}
		temp->next=p->next;
		p->next=temp;
	}
}
	
void Solution::print(ListNode *&head1){
	ListNode* temp=head1;
	while(temp!=NULL){
		cout<<temp->val<<" ";
		temp=temp->next;
		
	}
	cout << endl;

	
}
int Solution::length(ListNode *&head1){
	ListNode *temp=head1;
	int count=0;
	while(temp!=NULL){
		count+=1;
		temp=temp->next;
	}
	return count;
}
void Solution::deleteNode(ListNode* &head1,int location){
	int len = length(head1);
	ListNode *temp=head1;
	if (location>len){
		cout << "invalid input" << endl;}
	else if(location==1){
		head1=temp->next;
		delete temp;}
	else{
		int i=1;
	ListNode *p=head1;
	ListNode *q;
		while(i<location-1){
			p=p->next;
			i=i+1;}
		q=p->next;
		p->next=q->next;
		delete q;
	}
}

		
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
	
        ListNode* sorting;
    	ListNode* new_head=NULL;
	if(l1==NULL) return l2;
	if(l2==NULL) return l1;
	if (l1&&l2){
		if(l1->val<=l2->val){
			sorting =l1;
			l1=sorting->next;
		}
		else {
			sorting=l2;
			l2=sorting->next;
		}
	}
	new_head=sorting;
	while(l1&&l2){
		if (l1->val<=l2->val){
			sorting->next=l1;
			sorting=l1;
			l1=sorting->next;
		}
		else{
			sorting->next=l2;
			sorting=l2;
			l2=sorting->next;
		}
	}
	if(l1==NULL) sorting->next=l2;
	if(l2==NULL) sorting->next=l1;
	return new_head;

	
}

void print1(ListNode* &head1){
	ListNode* temp=head1;
	while(temp!=NULL){
		cout<<temp->val<<" ";
		temp=temp->next;
		
	}
	cout << endl;

	
}

int main(){
	ListNode *a = NULL;
	ListNode *b = NULL;
	ListNode *res=NULL;
	Solution s;
	s.append(a,1);
	s.append(a,2);
	s.append(a,4);
	s.append(a,9);
	s.print(a);
	cout << "length is " << s.length(a) << endl;
	Solution s1;
	s1.append(b,1);
	s1.append(b,3);
	s1.append(b,4);
	//s1.deleteNode(b,3);
	//s1.insert(b,2,8);
	//s1.print(b);
	print1(a);
	print1(b);
	
	res= mergeTwoLists(a,b);
	//Listnode *sort=;
	print1(res);
	return 0;
}
		




