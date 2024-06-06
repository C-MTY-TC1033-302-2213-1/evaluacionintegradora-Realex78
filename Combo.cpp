#include "Combo.h"

Combo::Combo() : Producto() {
	clave = 0;
}

Combo::Combo(string _nombre, int _precio, int _peso, int _clave) : Producto(_nombre, _precio, _peso) {
	clave = _clave;
}

string Combo::str() {
	return nombre + "-$" + to_string(precio) + '-' + to_string(peso) + "-$" + to_string(calculaTotalPagar()) + '-' + to_string(clave);
}

int Combo::calculaTotalPagar() {
	int totalPagar = precio * peso * clave;
	int descuento = 0;

	if (clave == 1) {
		descuento = (totalPagar / 100) * 25;
	} else if (clave == 2) {
		descuento = (totalPagar / 100) * 30;
	}
	
	totalPagar = totalPagar - descuento;
	return totalPagar;
}