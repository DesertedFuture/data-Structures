//Scott Snyder

/*
max heap:
	max element is always stored at the root

min heap:
	min element is stored at the root

*/
#include <iostream>
#include <vector>
#include <math.h>

int height(std::vector<int> arr){
	int size = arr.size();
	return log2(size);
}
void print(std::vector<int> arr){
	for(auto i : arr){
		std::cout<< i <<' ';
	}
	std::cout<<'\n';

}

int parent(int index){
	if(index == 0) {
		return 0;
	}
	if(index % 2 ==0){
		return (index/2)-1;
	}
	return floor(index /2);
}

int left(int index){
	return (2*index)+1;
}

int right(int index) {
	return 2*(index+1);
}

void maxHeapify(std::vector<int> &a, int index){
	//std::cout<<"Index: " << index << std::endl;
	//print(a);
	//we assume there is error with index but that left and right are max heaps already
	//this is just supposed to float down a value
	int l = left(index); //left node
	int r = right(index); //right node
	int largest;

	if(l < a.size() && a[l] > a[index] ){
		largest = l;
	} else {
		largest = index;
	}

	if(r < a.size()  && a[r] > a[largest]){
		largest = r;
	}
	if(largest != index){
		int temp = a[index];
		a[index] = a[largest];
		a[largest] = temp;
		maxHeapify(a, largest);
	}
}

void buildMaxHeap(std::vector<int> &a){
	for(int i = floor(a.size()/2)-1; i >= 0; --i){
		//std::cout<< "I: " << i << std::endl;
		maxHeapify(a, i);
	}
}

void heapSort(std::vector<int> &a){
	buildMaxHeap(a);
	for (int i = a.size()-1; i >= 0; i--) {
        std::swap(a[0], a[i]);
        maxHeapify(a, 0);
    }
}



int headpExtractMax(std::vector<int> &a){
	if(a.size() < 1){
		std::cout<<"Heap Underflow \n";
		return -1;
	}
	int max = a[0];
	a[0] = a[a.size() - 1];
	maxHeapify(a,0);
	return max;
}

void heapIncreaseKey(std::vector<int> &a, int index, int key){
	if(key < index){
		std::cout<< "Error: New key is smaller than current key\n";
		return;
	}

	a[index] = key;
	while( index > 0 && a[parent(index) < a[index]]){
		std::swap(a[index], a[parent(index)]);
		index = parent(index);
	}
}

int heapMaximum(std::vector<int> a){
	return a[0];
}
void maxHeapInsert(std::vector<int> &a, int key){
	a.push_back(key);
	heapIncreaseKey(a,a.size()-1, key);
}



int main(int argc, char const *argv[])
{
	std::vector<int> arr = {16,4,10,14,7,9,3,2,8,1};
	std::vector<int> x = {1,2,3,4,5,6,7,8,9,10,11,12};
	std::vector<int> y = {4,1,3,2,16,9,10,14,8,7};
	print(arr);
	maxHeapify(arr, 1);
	print(arr);

	std::cout<<std::endl;

	print(y);
	buildMaxHeap(y);
	print(y);

	std::cout<<std::endl;

	print(y);
	heapSort(y);
	print(y);

	print(y);
	std::cout<<headpExtractMax(y)<<std::endl;
	print(y);

	std::cout<<std::endl;

	print(y);
	heapIncreaseKey(y, 9, 16);
	print(y);

	std::cout<<std::endl;
	print(y);
	maxHeapInsert(y, 10000);
	print(y);


	
	return 0;
}