#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
		Node(int a) {
			data = a;
			next = NULL;
		}
};

class LinkedList {
	private:
		Node* head;
	public:
		LinkedList() {
			head = NULL;
		}
		~LinkedList() {
			Node* p;
			while(head != NULL) {
				p = head;
				head = head->next;
				cout << "free([" << p->data << "])->";
				delete p;
			}
			cout << "null" << endl;
		}
		void append_node(int new_data) {
			Node* newNode = new Node(new_data);
			if(head == NULL) {
				head = newNode;
				cout << "["<< head->data << "]->null" << endl;
				return;
			}
			Node* list = head;
			while(list->next != NULL) {
				list = list->next;
			}
			list->next = newNode;
			Node* current = head;
			while(current != NULL) {
				cout << "["<< current->data << "]->";
				current = current->next;
			}
			cout << "null" << endl;
		}
		void del_node(int n)  {
			Node* dummy_head = new Node(0);
			dummy_head->next = head;
			int count = 0;
			Node* p = dummy_head;
			while(count != n) {
				p = p->next;
				count++;
			}
			Node* delete_node = p->next;
			p->next = delete_node->next;
			delete delete_node;
			Node* current = head;
			while(current != NULL) {
				cout << "["<< current->data << "]->";
				current = current->next;
			}
			cout << "null" << endl;
		}
};

int main() {
	LinkedList mylink;
	mylink.append_node(0);
	mylink.append_node(1);
	mylink.append_node(2);
	mylink.append_node(3);
	mylink.del_node(1);
	return 0;
}
