#include "hash.h"
#include <iostream>
using namespace std;

hash::hash() {
	for(int i = 0; i < table_size; i++) {
		hash_table[i] = new item;
		hash_table[i]->key = "null";
		hash_table[i]->value = "null";
		hash_table[i]->next = NULL;
	}
}

//deallocate memory in destructor
hash::~hash() {
	for(int i = 0; i < table_size; i++) {
		while(hash_table[i] != NULL) {
			item* toDelete = hash_table[i];
			hash_table[i] = hash_table[i]->next;
			delete toDelete;
		}
	}
}

/*Note: Poor hash function because "ash" and "has" placed in same bucket,
but makes for easy implementation. Quick fix: multiply each character by
its position in the string or by a prime number */
int hash::hash_func(string key) {
	int hash_code = 0;
	int index;
	//add up ascii values of each char in string
	for(unsigned int i = 0; i < key.length(); i++) {
		hash_code += key[i];
		hash_code *= 17; //ADDED
	}

	index = hash_code % table_size;
	return index;
}

//adds to end of linked list at a particulat bucket
//improvement: add to front of linked list for O(1) insertion
//improvement: check for duplicate keys
void hash::put(string key, string val) {
	int table_index = hash_func(key);
	//checks if bucket is empty
	if(hash_table[table_index]->key == "null" && hash_table[table_index]->value == "null") {
		hash_table[table_index]->key = key;
		hash_table[table_index]->value = val;
	} else {
		item* curr = hash_table[table_index]; //ptr to head of linked list at that bucket
		item* new_item = new item();
		new_item->key = key;
		new_item->value = val;
		new_item->next = NULL;
		//traverse down linked list to last item
		while(curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = new_item;
	}

}

//returns this key's value stored in hash table
void hash::get(string key) {
	int index = hash_func(key);
	item* curr = hash_table[index];
	string val = "";
	bool foundKey = false;

	while(curr != NULL) {
		if(curr->key == key) {
			foundKey = true;
			val = curr->value;
		}
		curr = curr->next;
	}

	if(foundKey) {
		cout << key << "'s value is " << val << endl;
	} else {
		cout << key << " not found in hash table" << endl;
	}

}

void hash::remove(std::string key) {
	int index = hash_func(key);
	item* curr = hash_table[index];
	item* temp1;
	item* temp2;
	//case where bucket/index is empty
	if(curr->key == "null" && curr->value == "null") {
		cout << key << " cannot be removed because not found in the hash table" << endl;
	} else if(curr->key == key && curr->next == NULL) {
		//case where only 1 item in bucket and item == key
		//just resetting the values
		curr->key = "null";
		curr->value = "null";
		curr->next = NULL;
		cout << key << " was removed from the hash table" << endl;
	} else if(curr->key == key && curr->next != NULL) {
		//case where first item matches key but bucket has additional items
		item* temp = curr->next;
		hash_table[index] = temp;
		delete curr;
		cout << key << " was removed from the hash table" << endl;
	} else {
		//last case is when bucket contains items, but first item not a match
		temp1 = hash_table[index]->next;
		temp2 = hash_table[index];

		while(temp1 != NULL && temp1->key != key) {
			temp2 = temp1;
			temp1 = temp1->next;
		}

		if(temp1 == NULL) {
			//did not find a match once got to end linked list
			cout << key << " cannot be removed because not found in the hash table" << endl;
		} else {
			//know found a match
			curr = temp1;
			temp1 = temp1->next;
			temp2->next = temp1;
			delete curr;
			cout << key << " was removed from the hash table" << endl;
		}

	}
}

int hash::num_items_in_bucket(int index) {
	item* curr = hash_table[index];
	int counter;
	if(curr->key == "null") {
		counter = 0;
	} else {
		counter = 1;
		while(curr->next != NULL) {
			curr = curr->next;
			counter++;
		} 
	}
	return counter;
}
/*initial helper function to make sure put function works*/
void hash::print_table() {
	int num_items = 0;
	for(int i = 0; i < table_size; i++) {
		num_items = num_items_in_bucket(i);
		cout << "-------------------------\n";
		cout << "index = " << i << endl;
		cout << hash_table[i]->key << endl;
		cout << hash_table[i]->value << endl;
		cout << "number of items = " << num_items << endl;
		cout << "-------------------------\n";
	}
}

void hash::print_items_in_bucket(int index) {
	item* curr = hash_table[index];
	if(curr->key == "null" && curr->value == "null") {
		cout << "index = " << index << " is empty" << endl;
	} else {
		cout << "index = " << index << " has the following items\n";
		while(curr != NULL) {
			cout << "-------------------------\n";
			cout << curr->key << endl;
			cout << curr->value << endl;
			cout << "-------------------------\n";
			curr = curr->next;
		}
	}
	
}