#include<iostream>
struct ListNode{
	int val;
	ListNode*next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution{
	public:
		ListNode*deleteDuplicates(ListNode*head){
			//create a dummy node to simplify handling of the head
			ListNode*dummy=new ListNode(0);
			dummy->next=head;
			ListNode*prev=dummy;//pointer to the last unique node
			ListNode*current=head;//pointer to the traverse the list
			while(current){
				//check for duplicates
				if(current->next&&current->val==current->next->val){
					//skip all nodes with the same value
					while(current->next&&current->val==current->next->val){
						current=current->next;
					}
					//link the last unique node to the next distinct node
					prev->next=current->next; 
				}
				else{
					//move prev to the current node if its unique
					prev=current;
				}
				//move current forward
				current=current->next;
			}
			return dummy->next;//return the modified list
		}
};
//helper function to print the linked list
void printList(ListNode*head){
	while(head){
		std::cout<<head->val<<"->";
		head=head->next;
	}
	std::cout<<"null"<<std::endl;
}
int main(){
	//example usage
	ListNode*head=new ListNode(1);
	head->next=new ListNode(2);
	head->next->next=new ListNode(3);
	head->next->next->next=new ListNode(3);
	head->next->next->next->next=new ListNode(4);
	head->next->next->next->next->next=new ListNode(4);
	head->next->next->next->next->next->next=new ListNode(5);
	Solution solution;
	ListNode*modifiedList=solution.deleteDuplicates(head);
	printList(modifiedList);
	return 0;
}