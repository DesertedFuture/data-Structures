// Scott Snyder
/*
node:
	element
	pointer to node
*/

/*
operations:
insertion
search element in linked list
	iterative
	recursive
reverse linked list
deletion:
	given key
	deleting key at given postion
delete linked list
get nth node
nth node from end of linked list
*/

#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};
Node * createNode(int val){
	Node* temp = new Node();
	temp->data = val;
	temp->next = NULL;
	return temp;
}

//given a node, insert at front
void insertNodeTop(Node*& head, Node* newHead ){
	Node* temp;
	temp = head;
	head = newHead;
	head->next = temp;

}

void insertDataTop(Node *& head, int val){
	Node* newNode = createNode(val);
	Node* temp = new Node();
	temp = head;
	head = newNode;
	head->next = temp;
}
void findNode(Node* n, int val){
	int counter = 1;
	while(n->data != val){
		n = n->next;
		counter++;
	}
	cout<<"position: " << counter << endl;
}

void insertDataBottom(Node *& n, int val){
	Node* temp = createNode(val);
	while(n->next != NULL){
		n = n->next;
	}
	n->next = temp;
	return;
}


void printList(Node* n){
	while (n != NULL){
		cout << n->data << " ";
		n = n->next;
	}
	cout<<"\n";
}

int main(int argc, char const *argv[])
{
	Node* head;
	Node* second;
	Node* third;

	head = new Node();
	second = new Node();
	third = new Node();

	head->data = 1;
	head->next = second;

	second->data =2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	Node* fourth;
	fourth = new Node();
	fourth->data = 4;
	fourth->next = NULL;

	insertNodeTop(head, fourth);
	insertDataTop(head, 5);
	insertDataBottom(head, 6);

	printList(head);

	findNode(head,2);

	return 0;
}