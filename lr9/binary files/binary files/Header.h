#ifndef __HEADER_H__
#define __HEADER_H__

struct address {
	char street[50];
	int building;
	int number;
};
struct apartment {
	char name[50];
	address built;
	int price;
};

int input();
void input_apa(int &quantity, apartment *house, int sizeOfRecord, char *name);
void show_list(int& quantity, int sizeOfRecord, char *name);
void search_by_price(int quantity, int sizeOfRecord, char *name);
void minimum_price(int quantity, int sizeOfRecord, char *name);
void coincides_apa(int sizeOfRecord, char *name);

#endif