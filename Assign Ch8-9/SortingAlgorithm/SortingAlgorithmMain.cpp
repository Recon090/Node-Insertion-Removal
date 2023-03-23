/*
Pawel Chowdhury
Description: Program 2, Sorting orders
Date: 3/16/23

*/


//preprocessor instructions
#include <iostream>
using namespace std;

//function declaration
void bubbleSort(int list[]);
void selectionSort(int list[]);




int main() {
	//initializing 2 unfilled arrays
	int list1[8];
	int list2[8];

	//for loop that takes in user input and fills out arrays
	cout << "\nPlease enter numbers 8 times to fill out arrays";
	for (int i = 0; i < 8; i++) {
		cout << "\nPlease enter any number: ";
			cin >> list1[i];
			list2[i] = list1[i];
	}

	//prints out the first array unsorted
	cout << "\nUnsorted"<<endl;
	for (int n : list1) {
		cout << n << " ";
	}

	//call to bubble sort function which will return array sorted via reference parameter
	bubbleSort(list1);
	cout << "\nBubble sorted: " <<endl;
	//outputs array with bubble sort
	for (int n : list1) {
		cout << n << " ";
	}

	//outputs array 2 unsorted
	cout << "\nUnsorted" << endl;
	for (int n : list2) {
		cout << n << " ";
	}
	//sorts array and returns it via reference parameter with selection sort
	selectionSort(list2);
	//prints out sorted array
	cout << "\nSelection sorted: " << endl;
	for (int n : list2) {
		cout << n << " ";
	}
}

//code for what function does
void bubbleSort(int list[]) {
	//create a variable to help swap numbers
	int temp;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 7-i; j++) {//the nested loop always shrinks as i increases since the last element after each run will be in place
			if (list[j] > list[j + 1]) {//when an element is bigger then the element after it
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}//the two are swapped and the element swapped goes on to be tested with the next, therefore guranteeing that the gretestelement is at the end
			}

		}
	}
void selectionSort(int list[]) {
	int min,t;//variables to compare min
	int temp;//variable for swapping


	for (int i = 0; i < 8; i++) {
		min = list[i];//collects the min which woudl be the first variable at the start
		t = i;
		for (int j = i; j < 8; j++) {//starts at i since after the loop runs the first element will always be the smallest
			if (min > list[j]) {//if it runs into an element that is smaller then the min, min is that and the index is collected
				min = list[j];
				t = j;
			}

		}//after the run the two are swapped ensuring the index i is the smallest value
			temp = list[i];
			list[i] = min; 
			list[t] = temp;
	}
}

