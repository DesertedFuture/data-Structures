// Scott Snyder
//Basic operations:	push	append	find	delete	reverse length
#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};
Node* createNode(int val){
	Node* temp = new Node();
	temp->data = val;
	temp->next = NULL;
	return temp;
}

void findNode(Node *n, int val){
	int count =1;
	while(n->data != val){
		if(n == NULL){
			cout<< "no find \n";
		}
		count++;
		n = n->next;
	}
	cout<<"Position of val " << val << " is: " << count <<endl;
}

void printList(Node* n){
	while (n != NULL){
		cout << n->data << " ";
		n = n->next;
	}
	cout<<"\n";
}

void push(Node *& n, int val){
	if(n == NULL){
		n = createNode(val);
		return;
	}
	Node* temp = n;
	n = createNode(val);
	n->next = temp;
	//if n is empty
}

void append(Node *& n, int val){
	if(n == NULL){
		n = createNode(val);
		return;
	}
	Node* newNode = createNode(val);
	Node* temp = n;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}

void reverse(Node *&n){
	//create new list then push each one i go to, to new list
	Node* revList= NULL;
	Node* tempList = n;

	while(tempList != NULL){
		push(revList, tempList->data);
		tempList = tempList->next;
	}
	
	n = revList;
}

int findLength(Node *n){
	int count = 0;
	while(n != NULL){
		count++;
		n = n-> next;
	}
	return count;
}

void deleteKey(Node *&n, int val){
	Node* newList = NULL;
	Node *temp = n;

	while(temp != NULL ) {
		if(temp->data != val){
			append(newList, temp->data);
		}
		temp = temp->next;
	}
	n = newList;
}

void deletePosition(Node *&n, int pos){
	if(pos == 1){
		Node* temp = n;
		n = temp->next;
		return
	}
	int count = pos;
	if(pos > findLength(n)){
		cout<<"list not long enough" << endl;
	}
	Node *temp = n;

	while(temp->next != NULL){
		count--;
		//im gonna need to think about this, i cant go back
		//i want to look at next but what about position 1?
		if(count == 0){
			
		}
		temp = temp->next;
		
	}
}

int main(int argc, char const *argv[])
{
	Node* head = new Node();
	head->data = 1;
	head->next = NULL;

	Node* second = createNode(2);
	head->next = second;

	push(head, 3);


	append(head, 4);
	printList(head);

	findNode(head,2);

	reverse(head);
	printList(head);

	cout<< "length of list is: "<< findLength(head) << '\n';

	deleteKey(head, 2);
	printList(head);

	return 0;
}
