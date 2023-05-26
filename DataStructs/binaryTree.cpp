//Scott Snyder
#include <cstddef>

struct bstNode{
	int data;
	bstNode* left = NULL;
	bstNode* right = NULL;
};




int main(int argc, char const *argv[])
{
	bstNode* head = new bstNode();
	head->data = 1;


	return 0;
}