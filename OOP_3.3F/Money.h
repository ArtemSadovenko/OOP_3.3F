#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Money
{
private:
	unsigned int hrv; 
	unsigned int cop;
public:
	void set_hrv(unsigned int a) { hrv = a; }
	void set_cop(unsigned int a) { cop = a; }

	unsigned int get_hrv() { return hrv; }
	unsigned int get_cop() { return cop; }

	void get_cash(double a);
	void set_cash(double a);

	void doll();
	void evro();

	Money();
	Money(unsigned int a, unsigned int b);
	Money(Money& a);
	~Money();

	friend Money operator -(Money& a, Money& b);
	friend Money operator +(Money& a, Money& b);
	friend Money operator /(Money& a, Money& b);

	Money operator *( double b);
	Money operator /(double b);

	double convert();
	void unconvert(double a);

	friend bool operator >(Money& a, Money& b);
	friend bool operator <(Money& a, Money& b);
	friend bool operator ==(Money& a, Money& b);
	friend bool operator !=(Money& a, Money& b);
};

