/*
Pawel Chowdhury
Description: Member insertion by position
Date: 6/1/2023
*/
//loading Preprocessor instructions
#include <iostream>
#include <iomanip>
using namespace std;

//create class for linked list
class LinkedList {
	//we use protected keyword since these members do not need to be acessed outside of class functions
protected:
	//structs inside class defining what a node is
	struct ListNode {
		double data;
		ListNode* next;
		//constructor for node
		ListNode(double d, ListNode* nextOne = NULL) {
			data = d;
			next = nextOne; //when creation of node occurs it always enures that the next node is a null, hence why we do ListNode *
		}
	};
	ListNode* h;//list head pointer

	//h is always what our nodepointer is set to at begining of function to tranverse list
public:
	void add(double data) {  //since we have our structure protected we use this add method for users to add into list
		if (h == NULL) {       //checks if empty list
			h = new ListNode(data);
		}
		else { //if not proceeds to find end of list
			ListNode* nodePtr = h;
			while (nodePtr->next != NULL) { //goes to end of list
				nodePtr = nodePtr->next;
			}
			nodePtr->next = new ListNode(data); //makes next item the new node with data using contructor
		}

	}
	LinkedList() {//when our class is created it creates an empty linked list
		h = NULL;
	}
	~LinkedList() {//destructor frees up Dynamic memory 
		cout << "\nDestructor called"; //for debugging purposes
		ListNode* nodePtr = h; //we use a node ptr and set it to the head, if we have more then one element it will point to a node with data
		while (nodePtr != NULL) { //Loops and frees up memory until we hit the end of the list
			ListNode* freedNode = nodePtr;
			nodePtr = nodePtr->next;
			delete freedNode;
		}
	}
	void print() {							 //prints out contents of linked list
		ListNode* nodePtr = h;
		while (nodePtr != NULL) {
			cout << nodePtr->data << " ";
			nodePtr = nodePtr->next;
		}
	}
	void remove(int pos) {
		int i = 0;
		ListNode* nodePtr = h; //sets ptrs up
		ListNode* beforeDeleted=nodePtr;
			while (i < pos && nodePtr->next != NULL) {//loops in scenario where pos!= 0, making before deleted element before selected one to delete
				beforeDeleted = nodePtr;
				i++;
				nodePtr = nodePtr->next;
			}
			if (pos == 0 && nodePtr->next != NULL) {//if our first element is to be deleted and there is a next
				beforeDeleted = nodePtr->next;		//it will delete first element and set header to the next one
				h = beforeDeleted;
				delete nodePtr;
			}
			else if ( nodePtr->next != NULL) {		//if our next element after deletedis not null then we simply set our past elemnent next value to the 
				beforeDeleted->next = nodePtr->next; //next value of nodeptr and delete node ptr
				delete nodePtr;
			}
			else if (pos == 0 && nodePtr->next == NULL) {//if list has only one element then it sets head to null
				h = NULL;
			}
			else if(beforeDeleted->next==NULL && nodePtr->next ==NULL){ //if pos>0 and list has only one element
				cout << "Value passed for position is greater or equal to length of the list, so NOTHING is done";
			}
			else if (beforeDeleted != NULL && nodePtr->next == NULL && ((pos-i)==0)) {//if we are at the end of our list
				beforeDeleted->next = NULL;
				delete nodePtr;
			}
			else {//if removal number given greater then list
				cout << "Value passed for position is greater then length of the list, so NOTHING is done";
			}
		
	}
	void insert(double x, int pos) {
		int i = 0;
		ListNode* nodePtr = h;
		double temp1, temp2;

		if (pos == 0) { //checks if we want to put at beginning

			//we use swapping methods for this program
			temp1 = nodePtr->data;  //store old data
			nodePtr->data = x;			//replace old data with new
			//checks if there is a next node
			while (nodePtr->next != NULL) {
				nodePtr = nodePtr->next;  //moves to next node
				temp2 = nodePtr->data;    //takes old data of that node
				nodePtr->data = temp1;    //replaces old with new
				temp1 = temp2;						//holds to replace in next loop

			}
			nodePtr->next = new ListNode(temp1);  //when loop is done a new element is added at end with old element
		}
		else {
			while (nodePtr->next != NULL && i < pos) {
				i++;
				nodePtr = nodePtr->next;
			}
			if (nodePtr->next == NULL && i != pos) {
				nodePtr->next = new ListNode(x);  //when loop is done a new element is added at end with old element
			}
			else {
				//we use swapping methods for this program
				temp1 = nodePtr->data;  //store old data
				nodePtr->data = x;			//replace old data with new
				//checks if there is a next node
				while (nodePtr->next != NULL) {
					nodePtr = nodePtr->next;  //moves to next node
					temp2 = nodePtr->data;    //takes old data of that node
					nodePtr->data = temp1;    //replaces old with new
					temp1 = temp2;						//holds to replace in next loop

				}
				nodePtr->next = new ListNode(temp1);  //when loop is done a new element is added at end with old element
			}
		}
	}



};


int main() {
	LinkedList listOfNodes;
	int listLen, position;
	double userInput;

	do { //asks user to enter a length for list
		cout << "\nPlease enter your linked list length: ";
		cin >> listLen;
	} while (listLen <= 0);

	for (int i = 0; i < listLen; i++) { //using class functions takes user data and fills in list
		cout << "\nPlease enter any number for your data: ";
		cin >> userInput;
		listOfNodes.add(userInput);
	}
	cout << "Here is your linked list with its data: " << endl;
	listOfNodes.print(); //prints out users list to show before and after
	do {//asks user for where they want their new element to be
		cout << "\nFor your list where would you like to remove your entry(0 to remove at begining 1 for second and so on),do not enter a negative number: ";
		cin >> position;
	} while (position < 0);
	listOfNodes.remove(position);
	cout << "\nHere is your list with the removed data: " << endl;
	listOfNodes.print(); //prints out new linked list

	return 0;
}