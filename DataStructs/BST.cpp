//Scott Snyder
#include <iostream>

struct Node(){
	int data;
	Node* left = NULL;
	Node* right = NULL;
};

void insertion(Node *&n, int val){
	if(!n){
		n = new Node();
		n->data = val;
		n->left = NULL;
		n->right = NULL;
	}
	if(n->data > val){
		
	}

}


int main(int argc, char const *argv[])
{
	Node* head = new Node();
	head->data = 1;
	
	Node* second = new Node();
	second->data = 2;



	return 0;
}