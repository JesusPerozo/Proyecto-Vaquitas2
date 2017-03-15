#include <string>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include<cctype>
#include <sstream>
#include "Definicion.h"
#include "Vacas.h"
#include <stdio.h>
#include <string.h>
#include <iomanip>

using namespace std;
void pausarBorrar(){
	system("pause");
	system("cls");
}
void imprimirTitulo(string titulo1,string titulo2,string titulo3,string titulo4){   
	cout <<setw(15)<<left<<titulo1<<setfill(' ')<<setw(15)<<left<<titulo2<<setfill(' ')<<setw(15)<<left<<titulo3<<setfill(' ')<<setw(15)<<left<<titulo4<<endl;		 	
}
bool entradaNombre(char *entrada){
    bool valida=true;
	int tam=0;
    for ( int j=0;entrada[j]!='\0';j++){
    	tam++;
	}
	if(tam>15){
		valida=false;
	}else if(entrada[0]=='\n'){
        valida=false;
		
    }else{
	   for(int i=0;i<tam;i++){
     	    if(entrada[i]=='\n'){
	         	entrada[i]=NULL;
	     	}else if ((entrada[0]>=48 && entrada[0]<=57)){
	            valida=false;      
     		
			}else if(entrada[i]!=32 && entrada[i]!='\0' && entrada[i]!='\n' && entrada[i]!=165 &&(entrada[i]<48||entrada[i]>57) && (entrada[i]<65||entrada[i]>90)){
	     	    valida=false;
	   	    }
		}
	}
	return valida;
}  
bool entradaRaza(string entrada){
    bool valida=true;
	int tam=entrada.size();
	if(tam>15){
		valida=false;
	}else{
		for(int i=0;i<tam;i++){
			if((entrada[i]<65||entrada[i]>90) ){
			    valida=false;
	 	  	}
		}
	}
	return valida;
}
bool entradaPeso(string entrada){
    bool valida=true;
    int tam=entrada.size();   
    if(tam>10){
		valida=false;
	}else{
    	for(int i=0;i<tam;i++){
    		if((entrada[i]<48 || entrada[i]>57) && (entrada[i]!=46)){
	    		valida=false;
	    	}
    	}
    }
	return valida;
}
void imprimirError(string n){
	system("cls");
	cout<<n<<endl<<endl;
	pausarBorrar();	
}
int main(int argc, char** argv) {
	cout<<"COMPILAAAA!!!"<<endl<<endl; 

}

