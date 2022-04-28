#include "Money.h"

void Money::get_cash(double a)
{
	if (a > hrv) {
		cerr << "Non avalable" << endl;
	}
	else {
		cop -= (a - (int)a) * 100;
		hrv -= (int)a;
	}
}

void Money::set_cash(double a)
{
	hrv += (int)a;
	cop+= (a - (int)a) * 100;
}

void Money::doll()
{
	double a = convert();
	a /= 28.78;
	unconvert(a);
}

void Money::evro()
{
	double a = convert();
	a /= 31.22;
	unconvert(a);
}

Money::Money():
	cop(0), hrv(0)
{
}

Money::Money(unsigned int a, unsigned int b):
	cop(a), hrv(b)
{
}

Money::Money(Money& a):
	cop(a.cop), hrv(a.hrv)
{
}

Money::~Money()
{
}

Money Money::operator*(double b)
{
	Money t(*this);
	t.hrv = hrv * b;
	t.cop = cop * b;
	return t;
}

Money Money::operator/(double b)
{
	Money t(*this);
	t.hrv = hrv / b;
	t.cop = cop / b;
	return t;
}

double Money::convert()
{
	double a = hrv;
	double b = cop;
	a += (double)cop / 100;
	return a;
}

void Money::unconvert(double a)
{
	
	hrv = (int)a;
	cop = (a - (int)a) * 100;
}

Money operator-(Money& a, Money& b)
{
	double x = a.convert();
	double y = b.convert();
	Money t;
	t.unconvert(x - y);
	return t;
}

Money operator+(Money& a, Money& b)
{
	double x = a.convert();
	double y = b.convert();
	Money t;
	t.unconvert(x + y);
	return t;
}

Money operator/(Money& a, Money& b)
{
	double x = a.convert();
	double y = b.convert();
	Money t;
	t.unconvert(x / y);
	return t;
}

bool operator>(Money& a, Money& b)
{
	return (a.hrv > b.hrv) ||(a.hrv == b.hrv && a.cop > b.cop);
}

bool operator<(Money& a, Money& b)
{
	return !(a > b) && a != b;
}

bool operator==(Money& a, Money& b)
{
	return a.hrv == b.hrv && a.cop == b.cop;
}

bool operator!=(Money& a, Money& b)
{
	return !(a==b);
}
