//Name: William Cahill
//Class: CS 201R
//Date: 10/02/2022

#include "Function.h"
using namespace std;

int main() {
	int largeCount = 150, mediumCount = 120, smallCount = 700;
	int chocolateOrderCounter = 1;
	char input;
	bool quit = false;
	cout << "Chocolate Inventory Control Program" << endl;
	cout << "F - Fill Order" << endl;
	cout << "P - Print Inventory" << endl;
	cout << "O - Order Inventory" << endl;
	cout << "E - Exit" << endl;
	cin >> input;

	while (quit != true) {
		switch (input) {
			case 'F':
				FillOrder(largeCount, mediumCount, smallCount, chocolateOrderCounter);
				chocolateOrderCounter += 1;
				cout << endl << endl;
				cout << "Chocolate Inventory Control Program" << endl;
				cout << "F - Fill Order" << endl;
				cout << "P - Print Inventory" << endl;
				cout << "O - Order Inventory" << endl;
				cout << "E - Exit" << endl;
				cin >> input;
				continue;
			case 'f':
				FillOrder(largeCount, mediumCount, smallCount, chocolateOrderCounter);
				chocolateOrderCounter += 1;
				cout << endl << endl;
				cout << "Chocolate Inventory Control Program" << endl;
				cout << "F - Fill Order" << endl;
				cout << "P - Print Inventory" << endl;
				cout << "O - Order Inventory" << endl;
				cout << "E - Exit" << endl;
				cin >> input;
				continue;
			case 'P':
				PrintInventory(largeCount, mediumCount, smallCount);
				cout << endl << endl;
				cout << "Chocolate Inventory Control Program" << endl;
				cout << "F - Fill Order" << endl;
				cout << "P - Print Inventory" << endl;
				cout << "O - Order Inventory" << endl;
				cout << "E - Exit" << endl;
				cin >> input;
				continue;
			case 'p':
				PrintInventory(largeCount, mediumCount, smallCount);
				cout << endl << endl;
				cout << "Chocolate Inventory Control Program" << endl;
				cout << "F - Fill Order" << endl;
				cout << "P - Print Inventory" << endl;
				cout << "O - Order Inventory" << endl;
				cout << "E - Exit" << endl;
				cin >> input;
				continue;
			case 'O':
				OrderInventory(largeCount, mediumCount, smallCount);
				cout << endl << endl;
				cout << "Chocolate Inventory Control Program" << endl;
				cout << "F - Fill Order" << endl;
				cout << "P - Print Inventory" << endl;
				cout << "O - Order Inventory" << endl;
				cout << "E - Exit" << endl;
				cin >> input;
				continue;
			case 'o':
				OrderInventory(largeCount, mediumCount, smallCount);
				cout << endl << endl;
				cout << "Chocolate Inventory Control Program" << endl;
				cout << "F - Fill Order" << endl;
				cout << "P - Print Inventory" << endl;
				cout << "O - Order Inventory" << endl;
				cout << "E - Exit" << endl;
				cin >> input;
				continue;
			case 'E':
				quit = true;
				break;
			case 'e':
				quit = true;
				break;
		}
	}
}