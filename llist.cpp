#include <iostream>

struct Node {
	int data;
	Node *next;

	// Constructor
	Node(int val) : data(val), next(nullptr){}
};

// Singly Linked list
class MyLinkedList {

	private: 
		Node* head;

	public:
		MyLinkedList() : head(nullptr){}

		~MyLinkedList() {} // Not sure if this is how it works!
									 
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
			if (!head) {
				head = newNode;
			} else {
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

			while(cur != nullptr){
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

	["MyLinkedList
	addAtHead
	addAtTail
	addAtTail
	addAtTail
	addAtTail
	addAtTail
	addAtTail
	deleteAtIndex
	addAtHead
	addAtHead
	get
	addAtTail
	addAtHead
	get
	addAtTail
	addAtIndex
	addAtTail
	addAtHead
	addAtHead
	addAtHead
	get
	addAtIndex
	addAtHead
	get
	addAtHead
	deleteAtIndex
	addAtHead
	addAtTail
	addAtTail
	addAtIndex
	addAtTail
	addAtHead
	get
	addAtTail
	deleteAtIndex
	addAtIndex
	deleteAtIndex
	addAtHead
	addAtTail
	addAtHead
	addAtHead
	addAtTail
	addAtTail
	get
	get
	addAtHead
	addAtTail
	addAtTail
	addAtTail
	addAtIndex
	get
	addAtHead
	addAtIndex
	addAtHead
	addAtTail
	addAtTail
	addAtIndex
	deleteAtIndex
	addAtIndex
	addAtHead
	addAtHead
	deleteAtIndex
	addAtTail
	deleteAtIndex
	addAtIndex
	addAtTail
	addAtHead
	get
	addAtIndex
	addAtTail
	addAtHead
	addAtHead
	addAtHead
	addAtHead
	addAtHead
	addAtHead
	deleteAtIndex
	get
	get
	addAtHead
	get
	addAtTail
	addAtTail
	addAtIndex
	addAtIndex
	addAtHead
	addAtTail
	addAtTail
	get
	addAtIndex
	addAtHead
	deleteAtIndex
	addAtTail
	get
	addAtHead
	get
	addAtHead
	deleteAtIndex
	get
	addAtTail
	addAtTail
	[[],[38],[66],[61],[76],[26],[37],[8],[5],[4],[45],[4],[85],[37],[5],[93],[10,23],[21],[52],[15],[47],[12],[6,24],[64],[4],[31],[6],[40],[17],[15],[19,2],[11],[86],[17],[55],[15],[14,95],[22],[66],[95],[8],[47],[23],[39],[30],[27],[0],[99],[45],[4],[9,11],[6],[81],[18,32],[20],[13],[42],[37,91],[36],[10,37],[96],[57],[20],[89],[18],[41,5],[23],[75],[7],[25,51],[48],[46],[29],[85],[82],[6],[38],[14],[1],[12],[42],[42],[83],[13],[14,20],[17,34],[36],[58],[2],[38],[33,59],[37],[15],[64],[56],[0],[40],[92],[63],[35],[62],[32]]


	return 0;
}
