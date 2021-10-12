struct struct_type
{
	int a, b;
	char ch3;
};

int f1(int x, char ch, bool f);
int f2(int &x, char &ch, bool &f);
void f3(int*, char *ch, bool *f);
int* f4(int x, char ch, bool f);
char* f5(int &x, char &ch, bool &f);
void f6(int arr[], int size);
void f7(int &arr, int size);
void f8(int *arr, int size);
void f9(struct struct_type parm);
void f10(struct_type *arg);
void f11(struct_type &arg);