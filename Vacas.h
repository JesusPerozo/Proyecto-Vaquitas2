#ifndef VACAS_H
#define VACAS_H
#include <iostream>
using namespace std;

class Vaca
{
	public:
		Vaca();
		~Vaca();
		void setNombre(string l);
		void setRaza(string l);
		void setPeso(float l);
		void setLitro(float l);
		string getNombre();
		string getRaza();
		float getPeso();
		float getLitro();
		
	private:
		string raza;
		string nombre;
		float peso, litro;

};

#endif
