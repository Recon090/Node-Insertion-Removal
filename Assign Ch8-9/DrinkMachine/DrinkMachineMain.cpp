/*
Pawel Chowdhury
Description: Drinking machine program
Date: 3/16/23


*/
//preprocessor instruction
#include <iostream>
#include <iomanip>
using namespace std;
//declaration of struct drink with variables to describe it
	struct drink{
		string drinkName;
		float price;
		int numAvailable;
	};

	//declaration of the class drinking machine
class DrinkingMachine {
	//input money function
	float inputMoney(int c) {//takes in user choice
		float inputtedMoney;
		cout<<"\nYou selected: " <<drinks[c-1].drinkName;
		do {
			cout << "\nPlease input $" << drinks[c-1].price << ": "; //verifies the user inputs at mininum the amount of money needed for the drink
			cin >> inputtedMoney;
		} while (inputtedMoney<drinks[c-1].price);
		return inputtedMoney;//returns the money the user inputted
	}
	void dailyReport() {//daily report function
		float totalAmountMade=0;
		for (int i = 0; i < 5; i++) {//for loop goes through the report of each drink and how many were sold
			cout << left << setw(20) << "\nDrink: " + drinks[i].drinkName << setw(10) << "\nNumber of drinks sold: " << 20 - drinks[i].numAvailable;
			totalAmountMade += ((20.0 - drinks[i].numAvailable) * drinks[i].price);
		}
		cout << "\nTotal money collected: $" << totalAmountMade;//ends off by stating how much money made that day
	}


public:
	drink drinks[5];//initalize the array with drinks

	void displayChoices(){//displays the vending machine screen
		cout <<left<<setw(10)<< "\nDrink Name"<< right<< setw(14) <<"Cost" << setw(23)<< "Number in Machine"

			<<endl  <<left<<setw(20) << "1 " + drinks[0].drinkName << setw(10) << drinks[0].price << setw(10) << drinks[0].numAvailable
			<< endl << left << setw(20) << "2 " + drinks[1].drinkName << setw(10) << drinks[1].price << setw(10) << drinks[1].numAvailable
			<< endl << left << setw(20) << "3 " + drinks[2].drinkName << setw(10) << drinks[2].price << setw(10) << drinks[2].numAvailable
			<< endl << left << setw(20) << "4 " + drinks[3].drinkName << setw(10) << drinks[3].price << setw(10) << drinks[3].numAvailable
			<< endl << left << setw(20) << "5 " + drinks[4].drinkName << setw(10) << drinks[4].price << setw(10) << drinks[4].numAvailable;
	}

	void buyDrink(int c) {//the function that processes the verifying, buying, and updating of the machine, parameter represents user choice
		char confirm;//variable used to confirm 
		float moneyTaken = inputMoney(c);//calls function to take users money
		cout << "\nEnter c to confirm purchase, enter anything else to cancel: ";//allows user to back out at the last second
		cin >> confirm;
		if (confirm == 'c' || confirm == 'C') {
			if (drinks[c-1].numAvailable == 0) {//checks if the drink is available and outputs if its not
				cout << "\nSOLD OUT, here is $" << moneyTaken << " back have a good day";
			}
			else {
				drinks[c - 1].numAvailable--;//deducts number of drinks available for what the user selected
				moneyTaken -= drinks[c - 1].price;//takes users money
				moneyTaken == 0 ? cout << "Here is 1 " <<drinks[c - 1].drinkName << " have a good day!" : 
					cout << "Here is 1 " << drinks[c - 1].drinkName << " and $" << moneyTaken << " back and have a good day!"; //ternary operator which will see if the user has any change
																															  //if the user has no change, message is outputted just saying drink, 
																															  //if user has change, message outputts along wtih change message
			}
		}
		else {
			cout << "\nPurchase canceled, here is $" << moneyTaken << " back have a good day"; //if user cancels message of cancellation and money given back is said
		}
	}
	~DrinkingMachine() {//destructor that is called when class is destroyed, calls daily report
		cout << fixed << showpoint << setprecision(2);//sets standard output to what we want
		dailyReport();
	}

};
//function declaration
void initialize(drink & drink1, drink& drink2, drink& drink3, drink& drink4, drink& drink5);
int buyingDrink();

int main() {
	cout << fixed << showpoint << setprecision(2);//sets standard output to what we want
	drink cola, rootBeer, orangeSoda, grapeSoda, bottleWater;//initializes the drinks we use to fill in our array for the class
	int choice;//used to get user choice
	DrinkingMachine d; //declaration of class
	//call to initialize function followed with filling of class array
	initialize(cola, rootBeer, orangeSoda, grapeSoda, bottleWater);
	d.drinks[0] = cola;
	d.drinks[1] = rootBeer;
	d.drinks[2] = orangeSoda;
	d.drinks[3] = grapeSoda;
	d.drinks[4] = bottleWater;

	//first display the choice to user and asks if they want to buy drink
		d.displayChoices();
		choice = buyingDrink();
		while (choice != 6) {//loops until user enters exit number 6
			d.buyDrink(choice);//goes to buydrink function with choice entered
			d.displayChoices();
			choice = buyingDrink();
	}

		
	return 0;


		//destructor called when this function ends



}
//initializes all the drinks
void initialize(drink& drink1, drink& drink2, drink& drink3, drink& drink4, drink& drink5) {
	drink1.drinkName = "Cola";
	drink1.price = 1.00;
	drink1.numAvailable = 20;

	drink2.drinkName = "Root Beer";
	drink2.price = 1.00;
	drink2.numAvailable = 20;

	drink3.drinkName = "Orange Soda";
	drink3.price = 1.00;
	drink3.numAvailable = 20;

	drink4.drinkName = "Grape Soda";
	drink4.price = 1.00;
	drink4.numAvailable = 20;

	drink5.drinkName = "Bottled Water";
	drink5.price = 1.50;
	drink5.numAvailable = 20;

}
//used to take in and return user choice, all while validating it
int buyingDrink() {
	int userChoice;
	do {
		cout << "\nPlease enter an Id going from 1-5 for what drink you want, otherwise enter 6 to exit: ";
		cin >> userChoice;
		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (userChoice < 1 || userChoice>6);
	return userChoice;
}