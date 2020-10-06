#pragma once
#include <iostream>

template<class TYPE>
class LinkedList {
private:
	struct Node {
		TYPE value;
		Node* link;
	};

	Node* first;
	Node* last;
	int size;

	Node* createNode(TYPE value) {
		Node* temp = new Node();
		temp->Node::value = value;
		temp->Node::link = nullptr;
		return temp;
	};

	void init() {
		first = new Node();
		last = new Node();
		first->Node::value = NULL;
		first->Node::link = nullptr;
		last->Node::value = NULL;
		last->Node::link = nullptr;
		size = 0;
	}
public:
	LinkedList() {
		init();
	};

	LinkedList(const TYPE* arr_start, const TYPE* arr_end) {
		init();

		int n = arr_end - arr_start;
		for (int i = 0; i < n; ++i) {
			insert(arr_start[i]);
		}
	};

	void insert(TYPE element) {
		if (first->Node::value == NULL) {
			first = createNode(element);
		}
		else {
			if (last->Node::value == NULL) {
				last = createNode(element);
				if (size == 1)
					first->Node::link = last;
			}
			else {
				last->Node::link = createNode(element);
				last = last->Node::link;
			}
		}
		++size;
	};

	void insert(int index,TYPE element) {
		Node* temp = createNode(element);
		if(index==0){
			temp->Node::link = first;
			if (size == 1) {
				last = first;
			}
			first = temp;
		}
		else {
			Node* iter = first;
			while (index != 1) {
				iter = iter->Node::link;
				--index;
			}
			temp->Node::link = iter->Node::link;
			iter->Node::link = temp;
		}
		++size;
	};

	TYPE& get(int index) {
		if (index == size - 1)
			return last->Node::value;
		else {
			Node* temp = first;
			while (index > 0) {
				temp = temp->Node::link;
				--index;
			}
			return temp->Node::value;
		}
	}

	TYPE& getFirst() {
		return first->Node::value;
	};

	TYPE& getLast() {
		return last->Node::value;
	};

	void print() {
		for (Node* i = first; i != last->Node::link; i = i->Node::link) {
			std::cout << i->Node::value << " ";
		}
		std::cout << std::endl;
	};

	int getSize() {
		return size;
	}
};