#ifndef __QINT_H__
#define __QINT_H__
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
string BinPlus(string, string);
string ChuyenBu2(string a);
string tong(string, string);
string tru(string, string);
string nhanHai(string);
string chiahHai(string );
void setBit(int a[], int);
string layDayBit(int a[]);
string bangHexSangBin(char);
char bangBinSangHex(string);
string chuyenBinsangDec(string);
string chuyenDecsangBin(string);
string chuyenBinsangHex(string);
string chuyenHexsangBin(string);
class Qint
{
private:
	int arrBit[4];
public:
	Qint();
	~Qint();
	Qint(int, string);
    Qint& operator=(Qint);
	friend Qint operator+(Qint, Qint);
	friend Qint operator-(Qint, Qint);
	friend Qint operator*(Qint, Qint);
	friend Qint operator/(Qint,Qint);
	friend Qint operator&(Qint, Qint);
	friend Qint operator|(Qint, Qint);
	friend Qint operator^(Qint, Qint);
	friend Qint operator~(Qint);
	friend Qint operator>>(Qint,int);
	friend Qint operator<<(Qint,int);
	Qint ROR();
	Qint ROL();
	string lay();
	void xuat(int,ostream&);
	void nhap(istream&, ostream&);
};
#endif
