//Scott Snyder
/*
stack is LIFO
operations:
-push
-pop
-top
-isEmpty()
-size()

*/
#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

bool isEmpty(Node* head){
	if(head != NULL){
		return false;
	}
	return true;
}


void print(Node* n){
	std::cout<<'\t';
	while(n != NULL){
		std::cout<<n->data<< ' ';
		n = n->next;
	}
	std::cout<<'\n';
}

void push(Node*& n, int value){
	Node *oldHead = n;
	Node *temp = new Node();
	temp->data = value;
	temp->next = oldHead;
	n = temp;
}

Node* pop(Node *&n){
	Node* temp = new Node();
	temp->data = n->data;
	temp->next = NULL;
	n = n->next;
	return temp;
}
int top(Node* head){
	return head->data;
}


int main(int argc, char const *argv[])
{
	std::cout<<"Stack implementation using liked list, head = 0\n";
	Node *head = new Node();
	head->data = 0;	
	
	std::cout<<"Testing push\n";
	push(head, 1);
	push(head, 2);
	print(head);

	std::cout<<"Testing pop\n";
	Node *popped = pop(head);
	std::cout<<"Popped:";
	print(popped);
	std::cout<<"head:";
	print(head);
	
	std::cout<<"Testing top \n";
	int t = top(head);
	std::cout<<'top:\t' << t<<'\n';

	std::cout<<"Testing isEmpty(): \n";
	std::cout<<"Non empty stack: ";
	std::cout<< isEmpty(head)<<'\n';
	std::cout<<"empty stack: ";
	Node *eStack= NULL;
	std::cout<< isEmpty(eStack) << std::endl;
	std::cout<<"Testing size()\n";
	return 0;
}