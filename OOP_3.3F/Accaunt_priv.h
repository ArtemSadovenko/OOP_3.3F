#pragma once
#include "Money.h"
class Accaunt_priv: private Money
{
private:
    string name;
    string code;
    double per;
public:
    void set_name(string a) { name = a; }
    void set_code(string a) { code = a; }
    void set_per(double a) { per = a; }

    string get_name() { return name; }
    string get_code() { return code; }
    double get_per() { return per; }

    void get_cash(double a) { Money::get_cash(a); }
    void set_cash(double a) { Money::set_cash(a); }

    void doll() { Money::doll(); }
    void evro() { Money::evro(); }

    Accaunt_priv();
    Accaunt_priv(string n, string c, double p, int h, int co);
    Accaunt_priv(Accaunt_priv& a);
    ~Accaunt_priv();

    friend ostream& operator <<(ostream& out, Accaunt_priv& a);
    friend istream& operator >>(istream& in, Accaunt_priv& a);

    operator string();
};

