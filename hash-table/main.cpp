#include <iostream>
#include <string>
#include "hash.h"
using namespace std;

int main(int argc, char* argv[]) {
	hash* hash_table = new hash();
	string name = "";

	hash_table->put("Paul", "Locha");
	hash_table->put("Kim", "Iced Mocha");
	hash_table->put("Emma", "Strawberry Smoothie");
	hash_table->put("Annie", "Hot Chocolate");
	hash_table->put("Sarah", "Passion Tea");
	hash_table->put("Pepper", "Caramel Mocha");
	hash_table->put("Mike", "Chai Tea");
	hash_table->put("Steve", "Apple Cider");
	hash_table->put("Bill", "Root Beer");
	hash_table->put("Marie", "Skinny Latte");
	hash_table->put("Susan", "Water");
	hash_table->put("Joe", "Green Tea");

	hash_table->print_items_in_bucket(2);

	while(name != "exit") {
		cout << "Remove item ";
		cin >> name;
		if(name != "exit") {
			hash_table->remove(name);
		}
	}

	hash_table->print_items_in_bucket(2);

	delete hash_table;
	return 0;

}