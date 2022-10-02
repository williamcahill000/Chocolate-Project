#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	//variable decleration / initilization
	float largePrice = 30.50, mediumPrice = 25.99, smallPrice = 10.50;
	int largeCount = 150, mediumCount = 120, smallCount = 700;
	int largeWeight = 5, mediumWeight = 3, smallWeight = 1;
	int largeOrder = 0, mediumOrder = 0, smallOrder = 0;
	bool quit = false;
	int temp1;

	while (quit != true) {
		//Gets amount of chocolate for order
		cout << "Enter total number of pounds of chocolate you would like: ";
		cin >> temp1;

		//Measures large inputs and filters it down for medium and small chocolate weights
		if (temp1 / 5 >= 1) {
			largeOrder = floor(temp1 / 5);
			if ((largeCount * 5) - temp1 < 0) {
				largeOrder = 150;
			}
			if ((temp1 - (largeOrder * 5)) / 3 >= 1 || temp1-(largeOrder*5) <= 2) {
				mediumOrder = floor((temp1 - (largeOrder * 5)) / 3);
				if (((temp1 - ((largeOrder * 5) + (mediumOrder * 3))) >= 1) || (temp1 - (mediumOrder*3+largeOrder*5) == 0)) {
					smallOrder = (temp1 - (largeOrder * 5 + mediumOrder * 3));
					cout << "Your order has been filled:" << endl;
					cout << "Small bars: " << fixed << setw(5) << setprecision(2) << smallOrder << " = " << smallPrice * smallOrder << endl;
					cout << "Medium bars: " << fixed << setw(4) << setprecision(2) << mediumOrder << " = " << mediumPrice * mediumOrder << endl;
					cout << "Large bars: " << fixed << setw(5) << setprecision(2) << largeOrder << " = " << largePrice * largeOrder << endl;
					cout << "Total cost: " << fixed << setw(15) << setprecision(2) << (smallOrder * smallPrice) + (mediumOrder * mediumPrice) + (largeOrder * largePrice) << endl;
					cout << endl;

					//Subtracting chocolate orders from inventory
					largeCount -= largeOrder;
					mediumCount -= mediumOrder;
					smallCount -= smallOrder;

					//Prints inventory count post chocolate order
					cout << "Remaining inventory:" << endl;
					cout << "Small bars: " << setw(5) << smallCount << endl;
					cout << "Medium bars: " << setw(4) << mediumCount << endl;
					cout << "Large bars: " << setw(5) << largeCount << endl;
					break;
				}
			}
		}
		//Measuring medium chocolate and small chocolate weight only for smaller inputs
		if (temp1 / 3 >= 1) {
			mediumOrder = floor(temp1 / 3);
			if (temp1 - (mediumOrder * 3) >= 1 || (temp1-(mediumOrder*3) == 0)) {
				smallOrder = temp1 - (mediumOrder * 3);
				cout << "Your order has been filled:" << endl;
				cout << "Small bars: " << fixed << setw(5) << setprecision(2) << smallOrder << " = " << smallPrice * smallOrder << endl;
				cout << "Medium bars: " << fixed << setw(4) << setprecision(2) << mediumOrder << " = " << mediumPrice * mediumOrder << endl;
				cout << "Large bars: " << fixed << setw(5) << setprecision(2) << largeOrder << " = " << largePrice * largeOrder << endl;
				cout << "Total cost: " << fixed << setw(15) << setprecision(2) << (smallOrder * smallPrice) + (mediumOrder * mediumPrice) + (largeOrder * largePrice) << endl;
				cout << endl;

				//Subtracting chocolate orders from inventory
				mediumCount -= mediumOrder;
				smallCount -= smallOrder;

				//Prints inventory count post chocolate order
				cout << "Remaining inventory:" << endl;
				cout << "Small bars: " << setw(5) << smallCount << endl;
				cout << "Medium bars: " << setw(4) << mediumCount << endl;
				cout << "Large bars: " << setw(5) << largeCount << endl;
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
			cout << "Total cost: " << fixed << setw(15) << setprecision(2) << (smallOrder * smallPrice) + (mediumOrder * mediumPrice) + (largeOrder * largePrice) << endl;
			cout << endl;

			//Subtracting chocolate orders from inventory
			smallCount -= smallOrder;

			//Prints inventory count post chocolate order
			cout << "Remaining inventory:" << endl;
			cout << "Small bars: " << setw(5) << smallCount << endl;
			cout << "Medium bars: " << setw(4) << mediumCount << endl;
			cout << "Large bars: " << setw(5) << largeCount << endl;
			break;
		}
	}
}