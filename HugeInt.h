#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

class HugeInt
{
	friend ostream &operator << (ostream&, const HugeInt&);
	friend istream &operator >> (istream&, HugeInt&);
	public:
		HugeInt();
		HugeInt(long int num);
		HugeInt(const char *Snum);

		const HugeInt operator + (const HugeInt&);
		const HugeInt operator - (const HugeInt&);
		const HugeInt &operator = (const HugeInt&);
	private:
		short integer[25];
};

