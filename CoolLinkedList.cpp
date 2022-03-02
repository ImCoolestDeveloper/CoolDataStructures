/*
A basic linked list in 3 days
*/

#include <iostream>
#include <string>
#include <initializer_list>

using namespace std;

template<class T> class LinkedList;

template<class T>
class Node {
	friend class LinkedList<T>;

	Node *next = nullptr;
	T val;

	void addNextNode() {
		next=new Node();
	}
	void addNextNode(T val_) {
		next=new Node();
		next->val=val_;
	}
	void setNextNodeWithVal(Node *next_, T val_) {
		next=next_;
		next_->val=val_;
	}
	void setNext(Node *n) {
		next=n;
	}
public:
	Node():next(nullptr){}
	Node(T val):val(val),next(nullptr){}
	void setVal(T val_) {
		val=val_;
	}
	bool isLast(){return (next==nullptr || next==NULL);}
	T getVal() {return val;}
	Node *getNext() {return next;}
};

template<class T>
ostream &operator<<(ostream &os, Node<T> &n) {
	return os<<n.getVal();
}

template<class T>
class LinkedList {
	size_t size_=0;
	Node<T> *streamNode=nullptr;
	Node<T> *firstNode = nullptr;
	Node<T> *lastNode = nullptr;

	void reset(){
		streamNode=nullptr;
		firstNode = nullptr;
		lastNode = nullptr;
	}
public:
		LinkedList(initializer_list<T> list){
		if (list.size()>0) {
			firstNode=new Node<T>();
			streamNode=firstNode;
			Node<T> *currNode=firstNode;
			const T *e=list.begin();
			while (e!=list.end()-1) {
				currNode->setVal(*e);
				size_++;
				currNode->addNextNode();
				currNode=currNode->getNext();
				e = list.begin()+size_;
			}
			size_++;
			currNode->setVal(*e);
			currNode->setNext(nullptr);
			lastNode=currNode;
		}
		else size_=0;
	}

	bool canStream() {return (streamNode!=nullptr);}
	void reStream(){
		streamNode=firstNode;
	}
	T stream() {
		if (canStream()){
			T v = streamNode->getVal();
			streamNode=streamNode->getNext();
			return v;
		}
		return lastNode->getVal();
	}

	void setAt(int idx, T val) {
		if (idx<size_&&idx>=0){
			Node<T> *n = firstNode;
			for (int i=0;i<idx;i++) n = n->next;
			n->setVal(val);
		}
	}
	T getValAt(int idx) {
		if (idx<size_&&idx>=0){
			Node<T> *n = firstNode;
			for (int i=0;i<idx;i++) n = n->next;
			return n->getVal();
		}
		return lastNode->getVal();
	}
	void add(T val) {
		if (size_==0){
			firstNode=new Node<T>(val);
			lastNode=firstNode;
			lastNode->next=nullptr;
			streamNode=firstNode;
		}
		else {
			Node<T> *n = new Node<T>(val);
			lastNode->next=n;
			n->next=nullptr;
			lastNode=n;
		}
		size_++;
	}
	Node<T> *getFirst(){return firstNode;}
	Node<T> *getLast(){return lastNode;}
	size_t getSize(){return size_;}
};

void printIntList(LinkedList<int> l) {
	cout << "[ ";
	l.reStream();
	while (l.canStream()){
		cout<<l.stream()<<" ";
	}
	cout << "]" << endl;
}

int main() {
	LinkedList<int> l = {40,46,26,83};
	l.add(20);
	cout<<"L size: "<<l.getSize()<<endl;
	cout << "The last item is " << *l.getLast() << endl;
	cout << "Value at index 2 is " << l.getValAt(2) << endl;
	printIntList(l);
	return 0;
}