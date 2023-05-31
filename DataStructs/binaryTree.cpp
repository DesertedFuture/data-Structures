//Scott Snyder
#include <cstddef>
#include <iostream>

struct treeNode{
	int data;
	treeNode* left = NULL;
	treeNode* right = NULL;
};

//destroy
//empty
//insert
//delete
//traversal
	//pre order
	//post order
	//in order
//search
void postOrder(treeNode *n){
	//left
	//right
	//center
	if(n->left != NULL){
		postOrder(n->left); 
	}
	if(n->right != NULL){
		postOrder(n->right);
	}
	std::cout<<n->data << ' ';
}
void inOrder(treeNode *n){
	//left
	//center
	//right
	if(n->left != NULL){
		inOrder(n->left);
	}
	std::cout<< n->data << ' ';
	if(n->right != NULL){
		inOrder(n->right);
	}

}
void preOrder(treeNode *n){
	//current node
	//left
	//right
	std::cout<< n->data << ' ';
	if(n->left != NULL) {
		preOrder(n->left);
	}
	if(n->right != NULL) {
		preOrder(n->right);
	}
}

treeNode* createTreeNode(int val) {
	treeNode* temp = new treeNode();
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void insert(treeNode *&n, int val){
	treeNode *temp = n;
	if(temp->left == NULL){
		temp->left = createTreeNode(val);
	} else if(temp->left != NULL && temp->right == NULL){
		temp->right = createTreeNode(val);
	} else {
		temp = temp->left;
		insert(temp, val);
	}

}
/*
how to find place for insertion



*/
int main(int argc, char const *argv[])
{
	treeNode* head = new treeNode();
	head->data = 1;
	insert(head, 2);
	insert(head,3);
	insert(head,4);
	insert(head,5);
	insert(head,6);
	insert(head,7);
	insert(head,8);
	insert(head,9);

	std::cout<<"Pre-order: center, left, right\n";
	preOrder(head);
	std::cout<<std::endl;

	
	std::cout<<"In-order: left, center, right\n";
	inOrder(head);
	std::cout<<std::endl;
	
	std::cout<<"Post-order: left, right, center\n";
	postOrder(head);
	std::cout<<std::endl;

	return 0;
}