#include "Accaunt.h"

Accaunt::Accaunt():
	name(""), code(""), per(0)
{
	set_cop(0);
	set_hrv(0);

}

Accaunt::Accaunt(string n, string c, double p, int h, int co):
	name(n), code(c), per(p)
{
	set_cop(co);
	set_hrv(h);

}

Accaunt::Accaunt(Accaunt& a):
	name(a.name), code(a.code), per(a.per)
{
	set_cop(a.get_cop());
	set_hrv(a.get_hrv());
}

Accaunt::~Accaunt()
{
}

Accaunt::operator string()
{
	stringstream ss;
	ss << name << endl << code << endl << per << endl << get_hrv() << "," << get_cop() << endl;
	return ss.str();
}

ostream& operator<<(ostream& out, Accaunt& a)
{
	out << (string)a;
	// TODO: вставьте здесь оператор return
	return out;
}

istream& operator>>(istream& in, Accaunt& a)
{
	int h;
	int c;
	cout << "Name:"; cin >> a.name;
	cout << "Code: "; cin >> a.code;
	cout << "Percent: "; cin >> a.per;
	cout << "hrv: "; cin >> h; a.set_hrv(h);
	cout << "cop: "; cin >> c; a.set_cop(c);
	return in;
	// TODO: вставьте здесь оператор return
}
