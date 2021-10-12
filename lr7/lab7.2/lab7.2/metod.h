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

void input_apa(int& quantity, apartment *house);
void output_apa(int& quantity, apartment *house);
void search_by_price(int& quantity, apartment *house);
void minimum_price(int& quantity, apartment *house);
void coincides_apa(int& quantity, apartment *house);