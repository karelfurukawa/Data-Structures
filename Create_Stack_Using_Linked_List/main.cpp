#include <iostream>

class Node {
public:
	int item;
	Node *next;
	Node();
	Node(int);
};

class List {
protected:
	int size;
	Node *head;
	Node *tail;
public:
	List();
	void insertFront(int);
	void deleteFront();
	void printList();
	Node *findTheNode(int);
	int findTheData(int);
	bool isEmpty();
};

class Stack : List {
public:
	void push(int);
	void pop();
	void display();
	void findNode(int);
	void findData(int);
	void stackIsEmpty();
};

Node::Node() : item(0), next(NULL) {}
Node::Node(int itm) : item(itm), next(NULL) {}
List::List() : size(0), head(NULL), tail(NULL) {}

//List
void List::insertFront(int itm) {
	Node *temp = new Node(itm);

	if (temp == NULL) std::cout << "Memory not allocated" << std::endl;
	else {
		temp->next = head;
		head = temp;

		size++;
	}
	return;
}

void List::deleteFront() {

	if (size == 0) std::cout << "\nNothing to delete. List is empty." << std::endl;
	else {
		Node *temp = head;
		head = temp->next;
		delete temp;
		size--;
	}
	return;
}

void List::printList() {
	Node *temp = head;

	std::cout << "\nThe list: ";

	while (temp != NULL) {
		std::cout << temp->item << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
} 

int List::findTheData(int itm) {
	Node *tempHead = head;

	while (tempHead != NULL) {
		if (tempHead->item == itm) {
			return tempHead->item;
		}
		tempHead = tempHead->next;
	}
	return NULL;
}

Node* List::findTheNode(int pos) {
	Node *tempHead = head;

	if (pos == 0 || pos > size) return NULL;
	
	if (pos == 1) return tempHead;
	
	for (; pos > 1; pos--) {
		tempHead = tempHead->next;
	}
	return tempHead;
}

bool List::isEmpty() {
	if (head == NULL) return true;
	return false;
} 


//Stack
void Stack::pop()
{
	deleteFront();
}

void Stack::push(int x)
{
	insertFront(x);
}

void Stack::display() {
	if (head != NULL) printList();
	else stackIsEmpty();
} 

void Stack::findData(int itm) {

	if (head != NULL) {
		int num = findTheData(itm);
		if (num == 0) std::cout << "\nData is not found!" << std::endl;
		else std::cout << "\nData is found! Data: " << num << std::endl;
	}
	else stackIsEmpty();
}

void Stack::findNode(int pos) {
	if (head != NULL)
	{
		Node *theNode = findTheNode(pos);
		if (theNode == NULL)  std::cout << "\nInvalid input. It must be within the list. " << std::endl;
		else std::cout << "\nNode data: " << theNode->item << "\n";
	}
	else stackIsEmpty();
}

void Stack::stackIsEmpty() {
	if (isEmpty()) std::cout << "\nThe list is empty." << std::endl;
	else std::cout << "\nThe list is not empty. " << std::endl;
} 

int main() {
	Stack stack;
	int choice, position, num = 0;

	std::cout << "1. Push \n2. Pop \n3. Display \n4. Find Data \n5. Find Node \n6. Check if stack is empty \n7. Quit\n";

	do {
		std::cout << "\nChoice: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			std::cout << "Number: ";
			std::cin >> choice;
			stack.push(choice);
			break;
		case 2:
			stack.pop();
			break;
		case 3:
			stack.display();
			break;
		case 4:
			std::cout << "Find data: ";
			std::cin >> num;
			stack.findData(num);
			break;
		case 5:
			std::cout << "Position: ";
			std::cin >> position;
			stack.findNode(position);
			break;
		case 6:
			stack.stackIsEmpty();
			break;
		case 7:
			return 0;
		default:
			std::cout << "Invalid choice. ";
			break;
		}
	} while (true);

}