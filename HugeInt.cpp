#include "HugeInt.h"

HugeInt::HugeInt()
{
	for(int i = 0; i < 25; ++i)
		integer[i] = 0;
}

HugeInt::HugeInt(long int num)
{
	for(int i = 0; i < 25; ++i)
		integer[i] = 0;
	for(int i = 24; (num != 0)&&(i >= 0); --i){                  
		integer[i] = num % 10;
		num /= 10;
	}
}	
HugeInt::HugeInt(const char *sum)
{
	for(int i = 0; i < 25; ++i)
		integer[i] = 0;
	int length = strlen (sum);
	for (int i = 25-length, j = 0; i < 25; ++i, ++j){
		if ( isdigit( sum[ j ] ) )
			integer[ i ] = sum[ j ] - '0';
	}
}
ostream &operator << (ostream &output, const HugeInt &x)
{
	int i;
	for(i = 0; (i < 25) && (x.integer[i] == 0); ++i);
	if(i == 25)	
		output << 0;
	else{
		while(i < 25){
			if(x.integer[i] < 0){
				output << "-";
				++i;
			}
			else{
				output << x.integer[i];
				++i;
			}
		}
	}
	return output;
}

istream &operator >> (istream &input, HugeInt &y){
	long temp;
	input >> temp;
	int i;
	for(i = 0; i < 25; ++i)
		y.integer[i] = 0;
	for(i = 24; (temp != 0)&&(i >= 0); --i){                  
		y.integer[i] = temp % 10;
		temp /= 10;
	}
	return input;
}

const HugeInt HugeInt::operator + (const HugeInt &a)
{
	int carry = 0;
	int i;
	HugeInt add;		
	for (i = 24; i >= 0; --i)
	{
		add.integer[i] = integer[i] + a.integer[i] + carry;
		if(add.integer[i] >= 10){
			add.integer[i] %= 10;
			carry = 1;
		}
		else
			carry = 0;
	}
	return add;
}

const HugeInt HugeInt::operator - (const HugeInt &b)
{
	HugeInt sub;
	for (int i = 24; i >= 0; --i){
		sub.integer[i] += (integer[i] - b.integer[i]);
		if(sub.integer[i] < 0){
			sub.integer[i] += 10;
			sub.integer[i - 1] -= 1;
		}
	}
	return sub;
}

const HugeInt& HugeInt::operator = (const HugeInt &c)
{
	if(&c != this){
		for(int i = 24; i >= 0; --i)
			integer[i] = c.integer[i];
	}
	return *this;
}





