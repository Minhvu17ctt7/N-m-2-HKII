#include "Qint.h"
//Bo so 0 dau chuoi
void xoa0(string &a)
{
	while (a[0] == '0')
	{
		a.erase(0, 1);
	}
}
//Chuyen Int sang Char bo tro cho ham tinh tong hai chuoi
char chuyenIntSangChar(int number)
{
	return (char)(number + 48);
}
//Chuyen Char sang Int bo tro cho ham tinh tong hai chuoi
int chuyenCharSangInt(char c)
{
	return c - '0';
}

//Them so 0 vao dau chuoi ngan hon
//Bo tro cho ham tinh tong hai chuoi
void canBang(string &a, string &b)
{
	int len1 = a.length();
	int len2 = b.length();
	if (len1 >= len2)
	{
		b.insert(0, len1 - len2, '0');
	}
	else
	{
		a.insert(0, len2 - len1, '0');
	}
}

//Ham tinh tong hai chuoi he 10
//Bo tro cho ham chuyen co so 2 sang 10
string tong(string a, string b)
{
	canBang(a, b);
	string result;
	int len = a.length() - 1;

	int temp = 0;
	for (int i = len; i >= 0; i--)
	{
		//Tinh tong tung cap
		temp = chuyenCharSangInt(a[i]) + chuyenCharSangInt(b[i]) + temp;
		//Them vao dau
		result.insert(0, 1, chuyenIntSangChar(temp % 10));
		//Phan Nho
		temp = temp / 10;
	}
	//Neu ket qua cuoi du se them vao dau
	if (temp>0)
	{
		result.insert(0, 1, chuyenIntSangChar(temp));
	}
	return result;
}
//Ham tru co so 10 bo tro cho ham chuyen co so 2 sang 10
string tru(string a, string b)
{
	canBang(a, b);
	string result;
	int len = a.length();

	int temp1 = 0;
	int sub;
	for (int i = len - 1; i >= 0; i--)
	{
		int soA = chuyenCharSangInt(a[i]), soB = chuyenCharSangInt(b[i]);
		if (soA >= (soB + temp1))
		{
			sub = soA - (soB + temp1);
			temp1 = 0;
		}
		else
		{
			sub = (soA + 10) - (soB + temp1);
			temp1 = 1;
		}
		result.insert(0, 1, chuyenIntSangChar(sub));
	}
	xoa0(result);
	return result;
}
//Ham chia cho 2 lay phan nguyen
string chiaHai(string a)
{
	string result;
	int div;
	int mod = 0;
	int len = a.length();
	for (int i = 0; i<len; i++)
	{
		if (mod == 0)
		{
			div = chuyenCharSangInt(a[i]) / 2;
			mod = chuyenCharSangInt(a[i]) % 2;
		}
		else
		{
			div = (chuyenCharSangInt(a[i]) + 10) / 2;
			mod = (chuyenCharSangInt(a[i]) + 10) % 2;
		}
		result.push_back(chuyenIntSangChar(div));
	}
	xoa0(result);
	return result;
}
//Nhan so lon voi 2
//Bo tro cho 2^i
string nhanHai(string a)
{
	string result;
	int temp = 0;
	int len = a.length() - 1;
	for (int i = len; i >= 0; i--)
	{
		temp = chuyenCharSangInt(a[i]) * 2 + temp;
		result.insert(0, 1, chuyenIntSangChar(temp % 10));
		temp = temp / 10;
	}

	if (temp>0)
	{
		result.insert(0, 1, chuyenIntSangChar(temp));
	}
	return result;
}
//2^i cho ham chuyen co so 2 sang 10
string haiMu(int n)
{
	string result = "1";
	for (int i = 0; i < n; i++)
	{
		result = nhanHai(result);
	}
	return result;
}
//Ham dung de bat tat bit tai vi tri i tinh tu trai sang phai
void setBit(int arrBit[4], int i)
{
	int div = i / 32, mod = i % 32;
	arrBit[div] = arrBit[div] | (1 << (31 - mod));
	//else arrBit[div] = arrBit[div] & (0 << (31 - mod));
}
//Ham dung de lay bit tai vi tri i tinh tu trai sang phai
int getBit(int arrBit, int i)
{
	return (arrBit >> i) & 1;
}
//Ham lay day bit
string layDayBit(int arrBit[])
{
	string value;
	int j = 0;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 31; i >= 0; i--)
		{
			int bit = getBit(arrBit[j], i);
			value.push_back(chuyenIntSangChar(bit));
		}
	}
	return value;
}
//Bang chuyen doi tu he 16 sang he 2
string bangHexSangBin(char a)
{
	string result;
	switch (a)
	{
	case '0': result = "0000"; break;
	case '1': result = "0001"; break;
	case '2': result = "0010"; break;
	case '3': result = "0011"; break;
	case '4': result = "0100"; break;
	case '5': result = "0101"; break;
	case '6': result = "0110"; break;
	case '7': result = "0111"; break;
	case '8': result = "1000"; break;
	case '9': result = "1001"; break;
	case 'A': result = "1010"; break;
	case 'B': result = "1011"; break;
	case 'C': result = "1100"; break;
	case 'D': result = "1101"; break;
	case 'E': result = "1110"; break;
	case 'F': result = "1111"; break;
	}
	return result;
}
//Bang chuyen doi tu he 2 sang he 16
char bangBinSangHex(string a)
{
	char result;
	if (a == "0000") result = '0';
	else if (a == "0001") result = '1';
	else if (a == "0010") result = '2';
	else if (a == "0011") result = '3';
	else if (a == "0100") result = '4';
	else if (a == "0101") result = '5';
	else if (a == "0110") result = '6';
	else if (a == "0111") result = '7';
	else if (a == "1000") result = '8';
	else if (a == "1001") result = '9';
	else if (a == "1010") result = 'A';
	else if (a == "1011") result = 'B';
	else if (a == "1100") result = 'C';
	else if (a == "1101") result = 'D';
	else if (a == "1110") result = 'E';
	else  result = 'F';
	return result;
}
//Chuyen mot chuoi he 10 sang mot chuoi he 2
string BinPlus(string a, string b)
{
	string ans;
	int gaps = a.size() - b.size();
	if (gaps < 0)
	{
		gaps = abs(gaps);
		a.insert(0, gaps, '0');
	}
	else if (gaps > 0)
	{
		b.insert(0, gaps, '0');
	}
	int A, B, Ans, temp = 0;
	char c;
	for (size_t i = a.size(); i > 0; i--)
	{
		A = a[i - 1] - '0';
		B = b[i - 1] - '0';
		Ans = A + B + temp;
		temp = Ans / 2;
		c = Ans % 2 + '0';
		ans = c + ans;
	}
	return ans;
}
string BinPlus2(string a, string b)
{
	string ans;
	int gaps = a.size() - b.size();
	if (gaps < 0)
	{
		gaps = abs(gaps);
		a.insert(0, gaps, '0');
	}
	else if (gaps > 0)
	{
		b.insert(0, gaps, '0');
	}
	int A, B, Ans, temp = 0;
	char c;
	for (size_t i = a.size(); i > 0; i--)
	{
		A = a[i - 1] - '0';
		B = b[i - 1] - '0';
		Ans = A + B + temp;
		temp = Ans / 2;
		c = Ans % 2 + '0';
		ans = c + ans;
	}
	if (temp > 0)
	{
		c = temp + '0';
		ans = c + ans;
	}
	return ans;
}
//Hàm chuyển nhị phân âm bù 2 về ban đầu
string ChuyenBu2(string a)
{
	if (a.size() < 128) //Chuyển số dương sang số âm bù 2
	{
		for (size_t i = a.size(); i < 128; i++) //Thêm đủ 128bit
		{
			a = '0' + a;
		}
		for (size_t i = 0; i < a.size(); i++)
		{
			a[i] = (a[i] == '1') ? '0' : '1';
		}
		a = BinPlus(a, "1");
	}
	else //Chuyển số âm bù 2 thành số dương
	{
		for (size_t i = 0; i < a.size(); i++)
		{
			a[i] = (a[i] == '1') ? '0' : '1';
		}
		a = BinPlus(a, "1");
		xoa0(a);
	}
	return a;
}
string chuyenDecsangBin(string a)
{
	string result;
	int len;
	bool check = 0;
	if (a[0] == '-')
	{
		a.erase(0, 1);
		check = 1;
	}
	while (a != "")
	{
		len = a.length() - 1;
		//Chia du cho 2
		int bit = (a[len] - 48) % 2;
		//Them phan du vao dau chuoi
		result.insert(0, 1, chuyenIntSangChar(bit));
		a = chiaHai(a);
	}
	if (check == 1)
	{
		result = ChuyenBu2(result);
	}
	return result;
}
//Ham chuyen mot chuoi he so 2 sang mot chuoi he 10
string chuyenBinsangDec(string a)
{
	string result, temp;
	int len;
	//So 0 dau => so duong => xoa cac so 0 dau 
	if (a[0] == '0')
	{
		//Ham xoa so 0 dau
		xoa0(a);
		len = a.length();
		//Neu sau khi xoa len == 0 => chuoi toan so 0 => tra ve 0 
		if (len == 0)
		{
			return "0";
		}
		// Lay +2^i
		for (int i = 0; i < len; i++)
		{
			if (a[i] == '1')
			{
				temp = haiMu(len - i - 1);
				result = tong(result, temp);
			}
		}
	}
	//Nguoc lai la so am
	//lay -[ a[0]* ( 2^127 ) - a[1]*(2^126) -....-a[0]*(2^0)]
	else
	{
		result = haiMu(127);
		for (int i = 1; i < 128; i++)
		{
			if (a[i] == '1')
			{
				temp = haiMu( 127-i);
				result = tru(result, temp);
			}
		}
		result.insert(0, 1, '-');
	}
	return result;
}
//Chuyen mot chuoi he 16 sang he 2
string chuyenHexsangBin(string a)
{
	string result, temp;
	int len = a.length();
	for (int i = 0; i < len; i++)
	{
//Lay tu phan tu so sanh voi bang qua ham bangHexSangBin
		temp = bangHexSangBin(a[i]);
		result += temp;
	}
	xoa0(result);
	return result;
}
//Ham chuyen mot chuoi he 2 sang mot chuoi he 16
string chuyenBinSangHex(string a)
{
	string result, temp;
	int len = a.length();
	int mod = len % 4;
//Neu chia du 4 = n  khac khong thi phai them n so 0 vao dau de du bo 4 so
	if (mod != 0)
	{
		a.insert(0, 4 - mod, '0');
	}
	for (int i = 0; i < len; i += 4)
	{
		temp = a.substr(i, 4);
		result = result + bangBinSangHex(temp);
	}
	xoa0(result);
	return result;
}
//Hàm cộng 2 chuỗi nhị phân, trả về chuỗi nhị phân tổng
//Hàm trừ 2 chuỗi nhị phân, trả về chuỗi nhị phân thương
string BinSubtract(string a, string b)
{
	return BinPlus(a, ChuyenBu2(b));
}
Qint::Qint()
{
// Gan bit 00000000..........
	arrBit[0] = arrBit[1] = arrBit[2] = arrBit[3] = 0;
}
Qint::~Qint()
{
}
//Khoi tao voi tham so truyen vao la co so va chuoi 
Qint::Qint(int mode, string stringBit)
{
	arrBit[0] = 0;
	arrBit[1] = 0;
	arrBit[2] = 0;
	arrBit[3] = 0;
	//chuyen tat ca chuoi ve dang co so 2
	if (mode == 16)
	{
		stringBit = chuyenHexsangBin(stringBit);
	}
	else if (mode == 10)
	{
		stringBit = chuyenDecsangBin(stringBit);
	}
	int len = stringBit.length();
	//Sau khi chuyen ve chuoi co so 2 , ta setBit vao arrBit
	for (int i = 0; i < len; i++)
	{
		if (stringBit[i] == '1')
		{
			int k = (128 - len + i);
			setBit(arrBit, k);
		}
	}
}
Qint& Qint::operator=(Qint a)
{
	//Gan tung phan tu bang nhau
	arrBit[0] = a.arrBit[0];
	arrBit[1] = a.arrBit[1];
	arrBit[2] = a.arrBit[2];
	arrBit[3] = a.arrBit[3];
	return *this;
}
Qint operator+(Qint a,Qint b)
{
	//Lay bit luu vao chuoi
	string stringBinArrBita = layDayBit(a.arrBit);
	string stringBinArrBitb= layDayBit(b.arrBit);
	string sum = BinPlus(stringBinArrBita, stringBinArrBitb); 
	Qint result(2, sum);
	return result;
}
Qint operator-(Qint a, Qint b)
{
	//Lay bit luu vao chuoi
	string stringBinArrBita = layDayBit(a.arrBit);
	string stringBinArrBitb = layDayBit(b.arrBit);
	string sum = BinSubtract(stringBinArrBita, stringBinArrBitb);
	Qint result(2, sum);
	return result;
}
Qint operator&(Qint a, Qint b)
{
	Qint result;
	int temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			temp = ((a.arrBit[i] >> 32 - 1 - j) & 1) & ((b.arrBit[i] >> 32 - 1 - j) & 1);
			if (temp)
			{
				result.arrBit[i] = result.arrBit[i] | (1 << (32 - 1 - j));
			}
		}
	}
	return result;
}
Qint operator|(Qint a, Qint b)
{
	Qint result;
	int temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			temp = ((a.arrBit[i] >> 32 - 1 - j) & 1) | ((b.arrBit[i] >> 32 - 1 - j) & 1);
			if (temp)
			{
				result.arrBit[i] = result.arrBit[i] | (1 << (32 - 1 - j));
			}
		}
	}
	return result;
}
Qint operator^(Qint a, Qint b)
{
	Qint result;
	int temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			temp = ((a.arrBit[i] >> 32 - 1 - j) & 1) ^ ((b.arrBit[i] >> 32 - 1 - j) & 1);
			if (temp)
			{
				result.arrBit[i] =result.arrBit[i] | (1 << (32 - 1 - j));
			}
		}
	}
	return result;
}
//Toán tử NOT
Qint operator~(Qint a)
{
	Qint result;
	int temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			temp = (a.arrBit[i] >> 32 - 1 - j) & 1;
			if (!temp)
			{
				result.arrBit[i] = (result.arrBit[i] | (1 << (32 - 1 - j)));
			}
		}
	}
	return result;
}
//Hàm xoay trái
Qint Qint::ROL()
{
Qint result = *this >> 1;
int temp = ((*this).arrBit[3] >> 0) & 1;
if (temp)
result.arrBit[0] = (result.arrBit[0] | (1 << 31));
return result;
}

//Hàm xoay phải
Qint Qint::ROR()
{
	Qint result = (*this) >> 1;
	int temp = ((*this).arrBit[3] >> 0) & 1;
	if (temp)
		result.arrBit[0] = (result.arrBit[0] | (1 << 31));
	return result;
}
//Phép dịch trái số học
Qint operator<<(Qint a, int pos)
{

	string b;
	int repeat = 0;
	for (int i = pos / 32; i < 4; i++)
	{
		for (int j = pos % 32 - repeat; j < 32; j++)
		{
			int temp = (a.arrBit[i] >> 32 - 1 - j) & 1;
			b += temp + '0';
		}
		repeat = pos % 32;
	}
	for (size_t i = b.size(); i < 128; i++)
	{
		b += '0';
	}
	xoa0(b);
	Qint result(2, b);
	return result;
}

//Phép dịch phải số học
Qint operator>>(Qint a, int pos)
{
	string b;
	int repeat = 0;
	for (int i = 0; i < 4 - pos / 32; i++)
	{
		if ((i + 1) == 4 - pos / 32) repeat = pos % 32;
		for (int j = 0; j < 32 - repeat; j++)
		{
			int temp = (a.arrBit[i] >> 32 - 1 - j) & 1;
			b += temp + '0';
		}
	}
	for (size_t i = b.size(); i < 128; i++)
	{
		if ((a.arrBit[0] >> 31) & 1)
			b = '1' + b;
		else
			b = '0' + b;
	}
	Qint result(2, b);
	return result;
}
void Qint::xuat(int mode, ostream &os)
{
	if (mode == 2)
	{
		string temp = layDayBit(arrBit);
		xoa0(temp);
		os << temp;
	}
	else if (mode == 10)
	{
		string temp = chuyenBinsangDec(layDayBit(arrBit));
		xoa0(temp);
		os << temp;
	}
	else
	{
		os << chuyenBinSangHex(layDayBit(arrBit));
	}
}
void Qint::nhap(istream& is, ostream& os)
{
	vector<string> arrOp;
	while (is.peek() != EOF)
	{
		while (is.peek() != '\n' && is.peek() != EOF)
		{
			string temp;
			is >> temp;
			arrOp.push_back(temp);
		}
		is.seekg(2, 1);
		Qint result;
		string tempOp = arrOp[2];
		if (tempOp == "+" || tempOp == "-" || tempOp == "*" || tempOp == "/" || tempOp == "&" || tempOp == "|" || tempOp == "^")
		{
			int mode = stoi(arrOp[0]);
			Qint a(mode, arrOp[1]), b(mode, arrOp[3]);
			if (tempOp[0] == '+')
			{
				result = a + b;
			}
			else if (tempOp[0] == '-')
				result = a - b;
			else if (tempOp[0] == '*')
				result = a*b;
			else if (tempOp[0] == '/')
				result = a / b;
			else if (tempOp[0] == '&')
				result = a&b;
			else if (tempOp[0] == '|')
				result = a | b;
			else
				result = a^b;
			result.xuat(mode, os);
			os << "\n";
		}
		else if (tempOp == ">>" || tempOp == "<<")
		{
			int mode = stoi(arrOp[0]);
			Qint a(mode, arrOp[1]);
			int step = stoi(arrOp[3]);
			if (tempOp == ">>")
				result = a >> step;
			else if (tempOp == "<<")
				result = a << step;
			result.xuat(mode, os);
			os << "\n";
		}
		else
		{
			tempOp = arrOp[1];
			if (tempOp == "~" || tempOp == "rol" || tempOp == "ror")
			{
				int mode = stoi(arrOp[0]);
				Qint a(mode, arrOp[2]);
				if (tempOp == "~")
					result = ~a;
				else if (tempOp == "rol")
					result = a.ROL();
				else if (tempOp == "ror")
					result = a.ROR();
				result.xuat(mode, os);
				os << "\n";
			}
			else
			{
				int mode = stoi(arrOp[0]), mode2 = stoi(arrOp[1]);
				Qint a(mode, arrOp[2]);
				a.xuat(mode2, os);
				os << "\n";
			}
		}
		arrOp.clear();
	}
}
//Ham nhan 2 Qint
Qint operator*(Qint a, Qint b)
{
	//lay day bit chuyen sang he 10
	string stringBita = chuyenBinsangDec(a.lay()), stringBitb = chuyenBinsangDec(b.lay()), result = "0";
	bool checka = 0, checkb = 0;
	//kiem tra a phai so am khong?
	if (stringBita[0] == '-')
	{
		//Neu phai xoa ki tu -
		checka = 1;
		stringBita.erase(0, 1);
	}
	//Kiem tra b phai so am khong
	if (stringBitb[0] == '-')
	{
		//Neu phai xoa ki tu -
		checka = 1;
		stringBitb.erase(0, 1);
	}
	//chuyen lai thanh day bit
	stringBita = chuyenDecsangBin(stringBita);
	stringBitb = chuyenDecsangBin(stringBitb);
	//lay chuoi bit tu toan tu a va b
	xoa0(stringBita);
	xoa0(stringBitb);
	int lena = stringBita.length(), lenb = stringBitb.length();
	for (int i = 0; i < lenb; i++)
	{
		string temp = stringBita;
		//Lay tung b[len-i-1] x a
		//Sau do cong lai
		if (stringBitb[lenb - i - 1] == '1')
		{
			string temp2 = temp.insert(lena, i, '0');
			result = BinPlus2(result, temp2);
		}
	}
	//Kiem tra neu 1 trong 2 laf so am thi bu 2 cua div
	if ((checka == 1 && checkb == 0) || (checka == 0 && checkb == 1))
	{
		result = ChuyenBu2(result);
	}
	xoa0(result);
	Qint x(2, result);
	return x;
}
//Ham so sanh 2 chuoi bit
bool compareStringBit(string a, string b)
{
	if (a.length() > b.length())
		return 1;
	else if (a.length() < b.length())
		return 0;
	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] == '1' &&b[i] == '0')
				return 1;
			else if (a[i] == '0'&& b[i] == '1')
				return 0;
		}
	}
	return 1;
}
Qint operator/(Qint a, Qint b)
{
	//lay day bit chuyen sang he 10
	string stringBita = chuyenBinsangDec(a.lay()), stringBitb = chuyenBinsangDec(b.lay()), div, mod;
	bool checka = 0, checkb = 0;
	//kiem tra a phai so am khong?
	if (stringBita[0] == '-')
	{
		//Neu phai xoa ki tu -
		checka = 1;
		stringBita.erase(0, 1);
	}
	//Kiem tra b phai so am khong
	if (stringBitb[0] == '-')
	{
		//Neu phai xoa ki tu -
		checka = 1;
		stringBitb.erase(0, 1);
	}
	//chuyen lai thanh day bit
	stringBita = chuyenDecsangBin(stringBita);
	stringBitb = chuyenDecsangBin(stringBitb);
	xoa0(stringBita);
	xoa0(stringBitb);
	int lena = stringBita.length(), lenb = stringBitb.length();
	//Thuc hien phep chia
	for (int i = 0; i < lena; i++)
	{
		//them phan tu thi i vao mod
		mod.push_back( stringBita[i]);
		xoa0(mod);
		if (compareStringBit(mod, stringBitb) == 1)
		{
			//Neu mod > b lay mod=mod-b
			//Them 1 vao div
			div.push_back('1');
			mod = BinPlus(mod, ChuyenBu2(stringBitb));
			mod.erase(0, mod.length() - stringBitb.length());
		}
		//Nguoc lai them 0 vao div
		else div.push_back('0');
	}
	//Kiem tra neu 1 trong 2 laf so am thi bu 2 cua div
	if ((checka == 1 && checkb == 0) || (checka == 0 && checkb == 1))
	{ 
		div = ChuyenBu2(div);
	}
	xoa0(div);
	Qint result(2, div);
	return result;
}
string Qint::lay()
{
	return layDayBit(arrBit);
}