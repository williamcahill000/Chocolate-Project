#include "Function.h"
using namespace std;

void FillOrder(int& largeInv, int& mediumInv, int& smallInv, int& counter) {
	//variable decleration / initilization
	float largePrice = 30.50, mediumPrice = 25.99, smallPrice = 10.50;
	int largeOrder = 0, mediumOrder = 0, smallOrder = 0, largeWeight = 5, mediumWeight = 3, smallWeight = 1, totalWeight = 0, subTotal = 0;
	bool quit = false;
	int temp1;

	while (quit != true) {
		//Gets amount of chocolate for order
		cout << "Enter total number of pounds of chocolate you would like: ";
		cin >> temp1;
		cout << endl << endl;

		//Measures large inputs and filters it down for medium and small chocolate weights
		if (temp1 / 5 >= 1) {
			largeOrder = floor(temp1 / 5);
			if ((largeInv * 5) - temp1 < 0) {
				largeOrder = largeInv;
			}
			if ((temp1 - (largeOrder * 5)) / 3 >= 1 || temp1 - (largeOrder * 5) <= 2) {
				mediumOrder = floor((temp1 - (largeOrder * 5)) / 3);
				if ((mediumInv * 3) - temp1 < 0) {
					mediumOrder = mediumInv;
					if (mediumInv - mediumOrder < 0) {
						cout << "Not enough chocolate in inventory, order more!" << endl;
							break;
					}
				}
				if (((temp1 - ((largeOrder * 5) + (mediumOrder * 3))) >= 1) || (temp1 - (mediumOrder * 3 + largeOrder * 5) == 0)) {
					smallOrder = (temp1 - (largeOrder * 5 + mediumOrder * 3));

					if (smallInv-smallOrder < 0) {
						cout << "Not enough chocolate in inventory, order more!" << endl;
						break;
					}
					cout << "Chocolate Order: " << counter << endl;
					cout << "Small bars: " << fixed << setw(5) << setprecision(2) << smallOrder << " = " << smallPrice * smallOrder << endl;
					cout << "Medium bars: " << fixed << setw(4) << setprecision(2) << mediumOrder << " = " << mediumPrice * mediumOrder << endl;
					cout << "Large bars: " << fixed << setw(5) << setprecision(2) << largeOrder << " = " << largePrice * largeOrder << endl;
					cout << endl;
					totalWeight = (smallOrder * smallWeight) + (mediumOrder * mediumWeight) + (largeOrder * largeWeight);
					subTotal = (smallOrder * smallPrice) + (mediumOrder * mediumPrice) + (largeOrder * largePrice);
					ShippingCost(subTotal, totalWeight);

					//Subtracting chocolate orders from inventory
					largeInv -= largeOrder;
					mediumInv -= mediumOrder;
					smallInv -= smallOrder;
					break;
				}
			}
		}
		//Measuring medium chocolate and small chocolate weight only for smaller inputs
		if (temp1 / 3 >= 1) {
			mediumOrder = floor(temp1 / 3);
			if (temp1 - (mediumOrder * 3) >= 1 || (temp1 - (mediumOrder * 3) == 0)) {
				smallOrder = temp1 - (mediumOrder * 3);
				cout << "Your order has been filled:" << endl;
				cout << "Small bars: " << fixed << setw(5) << setprecision(2) << smallOrder << " = " << smallPrice * smallOrder << endl;
				cout << "Medium bars: " << fixed << setw(4) << setprecision(2) << mediumOrder << " = " << mediumPrice * mediumOrder << endl;
				cout << "Large bars: " << fixed << setw(5) << setprecision(2) << largeOrder << " = " << largePrice * largeOrder << endl;
				cout << endl;
				totalWeight = (smallOrder * smallWeight) + (mediumOrder * mediumWeight) + (largeOrder * largeWeight);
				subTotal = (smallOrder * smallPrice) + (mediumOrder * mediumPrice) + (largeOrder * largePrice);
				ShippingCost(subTotal, totalWeight);

				//Subtracting chocolate orders from inventory
				mediumInv -= mediumOrder;
				smallInv -= smallOrder;
				break;
			}
		}
		//Measures small chocolate only for extra small inputs
		if (temp1 / 1 >= 1) {
			smallOrder = temp1 - (mediumOrder * 3);
			cout << "Your order has been filled:" << endl;
			cout << "Small bars: " << fixed << setw(5) << setprecision(2) << smallOrder << " = " << smallPrice * smallOrder << endl;
			cout << "Medium bars: " << fixed << setw(4) << setprecision(2) << mediumOrder << " = " << mediumPrice * mediumOrder << endl;
			cout << "Large bars: " << fixed << setw(5) << setprecision(2) << largeOrder << " = " << largePrice * largeOrder << endl;
			cout << endl;
			totalWeight = (smallOrder * smallWeight) + (mediumOrder * mediumWeight) + (largeOrder * largeWeight);
			subTotal = (smallOrder * smallPrice) + (mediumOrder * mediumPrice) + (largeOrder * largePrice);
			ShippingCost(subTotal, totalWeight);

			//Subtracting chocolate orders from inventory
			smallInv -= smallOrder;
			break;
		}
	}
}

void PrintInventory(int largeInv, int mediumInv, int smallInv) {
	cout << endl << endl;
	cout << "Chocolate Inventory:" << endl;
	cout << "Small bars: " << setw(5) << smallInv << endl;
	cout << "Medium bars: " << setw(4) << mediumInv << endl;
	cout << "Large bars: " << setw(5) << largeInv << endl;
}

void ShippingCost(int subTotal, int weight) {
	if (weight <= 10) {
		weight = 5.25;
	}
	else if (weight <= 20) {
		weight = 7.75;
	}
	else if (weight <= 50) {
		weight = 12.25;
	}
	else {
		weight = 19.75;
	}
	cout << "Sub Total: " << subTotal << endl;
	cout << "Tax Total: " << (subTotal * .075) << endl;
	cout << "Shipping: " << weight << endl;
	cout << "Total Cost: " << (subTotal+(subTotal*.075)+weight) << endl;
}

void OrderInventory(int& largeInv, int& mediumInv, int& smallInv) {
	char chocSize;
	int chocOrder;
	cout << "What size of bars should be ordered (L, M or S)? ";
	cin >> chocSize;
	while (chocSize) {
		if (chocSize == 'L') {
			cout << "How many bars are needed? ";
			cin >> chocOrder;
			largeInv += chocOrder;
			break;
		}
		else if (chocSize == 'M') {
			cout << "How many bars are needed? ";
			cin >> chocOrder;
			mediumInv += chocOrder;
			break;
		}
		else if (chocSize == 'S') {
			cout << "How many bars are needed? ";
			cin >> chocOrder;
			smallInv += chocOrder;
			break;
		}
		else {
			cout << "Invalid Choice!";
			break;
		}
	}
}