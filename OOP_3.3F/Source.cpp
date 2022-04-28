#include "Accaunt.h"
#include "Accaunt_priv.h"

int main() {
	Accaunt a("Misk", "13044332", 32, 123, 33);
	Accaunt b(a);
	Accaunt_priv c("Misk", "13044332", 32, 123, 33);
	Accaunt_priv d(c);

	cout << a;
	cin >> a;
	a.doll();
	cout << a;
	b.evro();
	cout << b;
}