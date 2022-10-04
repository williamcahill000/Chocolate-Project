#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>

void FillOrder(int &largeInv, int &mediumInv, int &smallInv, int &counter);
//pre: Asks users for how much chocolate they want to order
//post: prints reciept and updates chocolate warehouse inventory, returns weight for shipping cost to use.

void ShippingCost(int subTotal, int weight);
//pre: Gets weight from FillOrder function
//post: total costs for shipping, tax, and sub total.

void PrintInventory(int largeInv, int mediuminv, int smallInv);
//pre: gets updated inventory counts
//post: prints inventory counts

void OrderInventory(int& largeInv, int& mediumInv, int& smallInv);
//pre: Asks user how much chocolate they want to order for size specified
//post: updates inventory count for the size specified

