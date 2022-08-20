#include <iostream>
#include "Operaciones.h"

int Operaciones::MaximoComunDivisor(int num1, int num2) {
	if (num1 == 0) {
		return num2;
	}

	return Operaciones::MaximoComunDivisor(num2 % num1, num1);
}

int Operaciones::MinimoComunMultiplo(int num1, int num2) {
	int t = num1 % num2;

	if (t == 0) return num1;

	return num1 * MinimoComunMultiplo(num2, t) / t;
}
