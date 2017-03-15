#include "Vacas.h"
#include <iostream>
#include <string.h> 
#include <stdio.h> 
using namespace std;

Vaca::Vaca()
{
}

Vaca::~Vaca()
{
}

void Vaca::setNombre(string l){
	nombre=l;
}

void Vaca::setRaza(string l){
	raza=l;	
}

void Vaca::setPeso(float l){
	peso=l;	
}

void Vaca::setLitro(float l){
	litro=l;	
}

string Vaca::getNombre(){
	return nombre;
}

string Vaca::getRaza(){
	return raza;
}

float Vaca::getPeso(){
	return peso;
}

float Vaca::getLitro(){
	return litro;
}
