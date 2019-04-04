#include "Qint.h"
int main()
{
	Qint a;
	fstream input, output;
	input.open("input.txt", ios::in);
	output.open("output.txt", ios::out);
	if (input)
	{ 
		a.nhap(input, output);
	}
	input.close();
	output.close();
	//Qint a(10,"-4647"), b(10, "430237189691661331451779261410858");
	//Qint c = a*b;
	//c.xuat(10, cout);
	system("pause");
		return 0;
}