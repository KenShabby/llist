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

		~MyLinkedList() {
			Node* current = head;
			while (current != nullptr) {
				Node* next = current->next;
				delete current;
				current = next;
			}
		}				 


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
			if (!head) 
				head = newNode;
			else {
				Node* cur = head;	
				while (cur->next) {
					cur = cur->next;
				}
				cur->next = newNode;
			}
		}


		int get(int index) {

			Node* cur = head;
			int iterCount = 0;
			while (cur != nullptr) { // Check that we have some nodes
				if (iterCount == index) {
					return cur->data;
				}
				iterCount++;
				cur = cur->next;
			}

			// If the index was out of bounds
			return -1;
		}


		void addAtIndex(int index, int val){

			Node* cur = head;

			// Case for inserting at head
			if(index == 0){
				addAtHead(val);
				return;
			}

			// Traverse to the node that will be before the new node.
			for(int i = 1; i < index && cur != nullptr; i++){
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


		void deleteAtIndex(int index) {
			if (head == nullptr) return;

			if (index == 0) {
				Node* temp = head;
				head = head->next;
				delete temp;
				return;
			}

			Node *prev = nullptr, *cur = head;
			int i = 0;
			while (cur != nullptr && i < index) {
				prev = cur;
				cur = cur->next;
				i++;
			}

			if (cur == nullptr) return; // Index out of bounds

			prev->next = cur->next;
			delete cur;
		}

};
