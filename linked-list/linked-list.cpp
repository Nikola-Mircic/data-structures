#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

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
		first = nullptr;
		last = nullptr;
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
		if (first == nullptr) {
			first = createNode(element);
			last = first;
		}
		else {
			if (last == first) {
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

	void removeAll() {
		this->eraseAll(&first);
	}

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

	void swap(const int index1, const int index2) {
		int idx = 0, found = 0;
		Node** toSwap = (Node**) calloc(2,sizeof(Node*));
		Node* temp = first;
		while (found < 2 && idx < size) {
			if (idx == index1 || idx == index2) {
				toSwap[found++] = temp;
			}
			temp = temp->Node::link;
			++idx;
		}
		if (found == 2) {
			TYPE t = toSwap[0]->Node::value;
			toSwap[0]->Node::value = toSwap[1]->Node::value;
			toSwap[1]->Node::value = t;
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

	void custom_print(void printFunction(TYPE& x)) {
		for (Node* i = first; i != last->Node::link; i = i->Node::link) {
			printFunction(i->Node::value);
		}
		std::cout << std::endl;
	}

	int getSize() {
		return size;
	}

	void operator = (const LinkedList<TYPE>& list) {
		if (this->size > 0) {
			init();
		}
		if (list.first != nullptr) {
			for (Node* i = list.first; i != list.last->Node::link; i = i->Node::link) {
				this->insert(i->Node::value);
			}
		}
	}

	template<class T> 
	LinkedList<T> operator + (const LinkedList<T>& a) {
		LinkedList<T>* temp = new LinkedList<T>();
		if (this->first != nullptr) {
			for (Node* i = this->first; i != this->last->Node::link; i = i->Node::link) {
				temp->insert(i->Node::value);
			}
		}
		if (a.first != nullptr) {
			for (Node* i = a.first; i != a.last->Node::link; i = i->Node::link) {
				temp->insert(i->Node::value);
			}
		}

		return *temp;
	}
};