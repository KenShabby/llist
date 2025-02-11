#include <iostream>

struct Node {
	int data;
	Node *next;

	Node(int val) : data(val), next(nullptr){}
};

// Singly Linked list
class MyLinkedList {

	private: 
		Node* head;

	public:
		MyLinkedList() : head(nullptr){}
									 
		void addAtHead(int val){

			Node* newNode = new Node(val);
			if(!head){
				head = newNode; // only node in list
				return;
			}

			// Other cases
			newNode->next = head;
			head = newNode;
		}

		void addAtTail(int val){
			Node* newNode = new Node(val);

			// first check for empty list, then traverse to tail
			if (!head) {head = newNode;}
			else {
				Node* cur = head;	
				while (cur->next) {
					cur = cur->next;
				}
				cur->next = newNode;
			}
		}

		int get(int index){

			Node* cur = head;
			int iterCount = 0;

			while(cur->next){
				if(iterCount == index){
					return cur->data;
				}
				iterCount++;
				cur = cur->next;
			}

			return -1; // index was invalid
		}	

		void addAtIndex(int index, int val){

			Node* cur = head;

			// Case for inserting at head
			if(index == 0){
				addAtHead(val);
				return;
			}

			// Traverse to the node that will be before the new node.
			for(int i = 1; i < index - 1 && cur != nullptr; i++){
				cur = cur->next;
			}

			// Check to see if we've arrived at the end of the list
			if(cur == nullptr)
				return;

			// Otherwise add the new node and update the pointers
			Node* newNode = new Node(val);

			newNode->next = cur->next;
			cur->next = newNode;

		}

		void deleteAtIndex(int index){

			// Empty list case
			if(head == nullptr){ 
				return;
			}
			
			Node* cur = head;

			// Deleting head case
			if(index == 0){
				head = cur->next;
				delete cur;
				return;
			}

			// Otherwise deleting a different node	
			for(int i = 1; i < index && cur != nullptr; i++){
				cur = cur->next;
			}

			// Goes out of range
			if(cur == nullptr || cur->next == nullptr) return;

			// Do the relinking
			Node* nextNode = cur->next->next;
			delete cur->next;
			cur->next = nextNode;

		}

		void printList(){
			
			Node* cur = head;
			while(cur != nullptr){
				std::cout << "Node: " << cur->data << std::endl;
				cur = cur->next;
			}
			std::cout << "*end*" << std::endl;
		}

};

int main(){

	// Your MyLinkedList object will be instantiated and called as such:
	MyLinkedList* obj = new MyLinkedList();

	obj->addAtHead(38);
	obj->addAtTail(66);
	obj->addAtTail(61);
	obj->addAtTail(76);
	obj->addAtTail(26);
	obj->addAtTail(37);
	obj->addAtTail(8);
	obj->deleteAtIndex(5);
	obj->addAtHead(4);
	obj->addAtHead(45);
	obj->get(4);
	obj->addAtTail(85);
	obj->addAtHead(37);
	obj->get(5);
	obj->addAtTail(93);
	obj->addAtIndex(10,23);
	obj->addAtTail(21);
	obj->addAtHead(52);
	obj->addAtHead(15);
	obj->addAtHead(47);
	obj->get(12);
	obj->addAtIndex(6,24);
	obj->addAtHead(64);
	obj->get(4);
	obj->addAtHead(31);
	obj->deleteAtIndex(6);
	obj->addAtHead(40);
	obj->addAtTail(17);
	obj->addAtTail(15);
	obj->addAtIndex(19,2);
	obj->addAtTail(11);
	obj->addAtHead(86);
	obj->get(17);
	obj->addAtTail(55);
	obj->deleteAtIndex(15);
	obj->addAtIndex(14,95);
	obj->deleteAtIndex(22);
	obj->addAtHead(66);
	obj->addAtTail(95);
	obj->addAtHead(8);
	obj->addAtHead(47);
	obj->addAtTail(23);
	obj->addAtTail(39);
	obj->get(30);
	obj->get(27);
	obj->addAtHead(0);
	obj->addAtTail(99);
	obj->addAtTail(45);
	obj->addAtTail(4);
	obj->addAtIndex(9,11);
	obj->get();
	obj->addAtHead();
	obj->addAtIndex();
	obj->addAtHead();
	obj->addAtTail();
	obj->addAtTail();
	obj->addAtIndex();
	obj->deleteAtIndex();
	obj->addAtIndex();
	obj->addAtHead();
	obj->addAtHead();
	obj->deleteAtIndex();
	obj->addAtTail();
	obj->deleteAtIndex();
	obj->addAtIndex();
	obj->addAtTail();
	obj->addAtHead();
	obj->get();
	obj->addAtIndex();
	obj->addAtTail();
	obj->addAtHead();
	obj->addAtHead();
	obj->addAtHead();
	obj->addAtHead();
	obj->addAtHead();
	obj->addAtHead();
	obj->deleteAtIndex();
	obj->get();
	obj->get();
	obj->addAtHead();
	obj->get();
	obj->addAtTail();
	obj->addAtTail();
	obj->addAtIndex();
	obj->addAtIndex();
	obj->addAtHead();
	obj->addAtTail();
	obj->addAtTail();
	obj->get();
	obj->addAtIndex();
	obj->addAtHead();
	obj->deleteAtIndex();
	obj->addAtTail();
	obj->get();
	obj->addAtHead();
	obj->get();
	obj->addAtHead();
	obj->deleteAtIndex();
	obj->get();
	obj->addAtTail();
	obj->addAtTail();
	[6],[81],[18,32],[20],[13],[42],[37,91],[36],[10,37],[96],[57],[20],[89],[18],[41,5],[23],[75],[7],[25,51],[48],[46],[29],[85],[82],[6],[38],[14],[1],[12],[42],[42],[83],[13],[14,20],[17,34],[36],[58],[2],[38],[33,59],[37],[15],[64],[56],[0],[40],[92],[63],[35],[62],[32]]

	return 0;
}
