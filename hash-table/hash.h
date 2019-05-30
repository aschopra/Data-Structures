#include <string>

class hash {
public:
	hash();
	~hash();
	int hash_func(std::string key); //returns the index number in a hash table
	void put(std::string key, std::string val);
	int num_items_in_bucket(int index);
	void print_table();
	void print_items_in_bucket(int index);
	void get(std::string key); //determines if person in hash table and prints food if so
	void remove(std::string key);

private:
	static const int table_size = 4;
	struct item {
		std::string key;
		std::string value;
		item* next;
	};
	item* hash_table[table_size]; //arr of ptrs to items


};