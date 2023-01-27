#include <iostream>

using namespace std;

int main()
{
	string opcion = "";
	int opcionnum = 0;
	while (true) {
		int meses[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		int difdias = 0;
		double sueldo = 0;
		double promediosueldo = 0;
		int diasfaltados = 0;
		int promediodiasfaltados = 0;
		double promedioultimos6 = 0;
		cout << "Menu Principal" << endl;
		cout << "1. Ejercicio 1" << endl;
		cout << "2. Ejercicio 2" << endl;
		cout << "3. Ejercicio 3" << endl;
		cout << "4.Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		if (opcion == "1") {
			opcionnum = 1;
		}
		else if (opcion == "2") {
			opcionnum = 2;
		}
		else if (opcion == "3") {
			opcionnum = 3;
		}
		else if (opcion == "4") {
			opcionnum = 4;
		}
		else {
			opcionnum = 1000;
		}
		switch (opcionnum) {
		case 1:
			for (int i = 0; i < 12; i++) {
				
				cout << "Ingrese el sueldo bruto recibido el mes "<< i+1 <<": ";
				double valor;
				cin >> valor;
				sueldo += valor;
				cout << "Ingrese las veces que estuvo ausente en el mes " << i + 1 << ": ";
				int valorr;
				cin >> valorr;
				diasfaltados += valorr;
			}
			promediosueldo = sueldo / 12;
			promediodiasfaltados = diasfaltados / 12;
			promedioultimos6 = sueldo / 6 / 2;
			cout << "El aguinaldo del empleado es: Lps." << promediosueldo << endl;
			if (promediodiasfaltados > 2) {
				cout << "No hay bonificacion" <<endl;
			}
			else {
				cout << "El bono que recibe el empleado es: Lps." << (promedioultimos6 * .05) << endl;
			}
			
			break;
		case 2:
			//Construir línea calculada mediante una pendiente
			cout << "Construir linea calculada mediante una pendiente." << endl;
			int yMax, xMax, m, x, y;
			cout << "Ingrese el valor de yMax: ";
			cin >> yMax;
			while (yMax <= 0) {
				cout << "Ingrese un valor mayor a 0:";
				cin >> yMax;
			}
			cout << "Ingrese el valor de xMax: ";
			cin >> xMax;
			while (xMax > yMax) {
				cout << "Ingrese un valor menor o igual a yMax:";
				cin >> xMax;
			}
				m = yMax / xMax;
				for (y = 0; y < yMax; y++) {
					x = y / m;
					for (int i = 0; i < x; i++) {
						cout << "X";
					}
					cout << "*" << endl;
				}
			break;
		case 3:
			int anio1, dia1, mes1, anio2, dia2, mes2;
			cout << "Ingrese el dia 1: ";
			cin >> dia1;
			cout << "Ingrese el mes 1: ";
			cin >> mes1;
			cout << "Ingrese el anio 1: ";
			cin >> anio1;
			while (anio1 < 2000) {
				cout << "Ingrese un anio mayor o igual a 2000:";
					cin >> anio1;
			}
			cout << "Ingrese el dia 2: ";
			cin >> dia2;
			cout << "Ingrese el mes 2: ";
			cin >> mes2;
			cout << "Ingrese el anio 2: ";
			cin >> anio2;
			while (anio2 < anio1) {
				cout << "Ingrese un anio mayor o igual al anio 1:";
				cin >> anio2;
			}
			if (dia1 > 0 && dia1 <= 31 && dia2 > 0 && dia2 <= 31 && mes1 > 0 && mes1 <= 12 && mes2 > 0 && mes2 <= 12 && anio1 > 0 && anio2 > 0) {
				if (anio1 == anio2) {
					if (mes1 == mes2) {
						difdias = dia2 - dia1;
					}
					else {
						for (int i = mes1; i < mes2; i++) {
							difdias += meses[i - 1];
						}
						difdias += dia2 - dia1;
					}
				}
				else {
					for (int i = mes1; i <= 12; i++) {
						difdias += meses[i - 1];
					}
					difdias += dia2 - dia1;
					for (int i = anio1 + 1; i < anio2; i++) {
						if (i % 4 == 0) {
							difdias += 366;
						}
						else {
							difdias += 365;
						}
					}
					for (int i = 1; i < mes2; i++) {
						difdias += meses[i - 1];
					}
				}
				cout << "Hay " << difdias << " dias de diferencia." << endl;
			}
			break;
		case 4:
			cout << "Saliendo del programa!" << endl;
			exit(0);
			break;
		}
	}
}
