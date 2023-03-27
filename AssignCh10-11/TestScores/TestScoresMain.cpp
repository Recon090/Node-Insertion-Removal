/*
Pawel Chowdhury
Assignment: Test Scores
3/25/2023
*/
#include <iostream>
using namespace std;
void fillArray(float* list, int size);
void sortAscending(float *list,int size);
void calculateAverage(float* list, int size, float* average);
void print(float* list, int size, float* average);
int main() {
	float* tListPtr = nullptr;
	float* averagePtr = new float;
	int studentCount;
	do {
	cout << "Please enter a valid number above 0 for the amount of students you have: ";
	cin >> studentCount;
	} while (studentCount < 1);
	
	tListPtr = new float[studentCount];
	fillArray(tListPtr, studentCount);
	sortAscending(tListPtr, studentCount);
	calculateAverage(tListPtr, studentCount, averagePtr);
	print(tListPtr, studentCount, averagePtr);
	



	delete[] tListPtr;
	delete averagePtr;
	return 0;
}
void fillArray(float * list, int size) {
	float grades;
	for (int i = 0; i < size; i++) {
		do {
			cout << "\nPlease enter a valid grade from 0 to 100: ";
			cin >> grades;
		} while (grades<0 || grades>100);
	
		*(list+i) = grades;
		cout << "Entered";
	}
}

void sortAscending(float* list, int size) {
	//create a variable to help swap numbers
	float temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-i-1; j++) {//the nested loop always shrinks as i increases since the last element after each run will be in place
			if (list[j] > list[j + 1]) {//when an element is bigger then the element after it
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
				cout<<endl<<list[j];
				cout<<endl<<list[j+1];

			}//the two are swapped and the element swapped goes on to be tested with the next, therefore guranteeing that the gretestelement is at the end
			}

		}
	}

void calculateAverage(float* list, int size, float* average){
	*(average) = 0;
	for(int i=0;i<size;i++){
		*(average)+=*(list+i);
	}
	*(average)/=size;
}
void print(float* list, int size, float* average){
	for(int i=0;i<size;i++){
		cout<<"\nGrade " << i+1 << ": " << *(list+i);
	}
	cout<<"\nClass average: " << *(average);
}