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
	pausarBorrar();
	int selec, valor,cuentaVaca=0;
	char n[100];
	string g;
	Vaca listaVaca[Definicion];
	Vaca auxiliar;
	string temporalS, temporalN="";
	int rep=1;
		do{
			fflush(stdin);
			cout<<"Bienvenido al sistema de almacenamiento y ordenamiento de vaquitas :D\nPor favor ingrese el numero correspondiente a la tarea que desea realizar\n"<<endl;
			cout<<"1) Ingresar vaquita\n\n2) Ordenar lista de vaquitas\n\n3) Salir\n\n"<<endl<<"Opcion:";
        	cin>>g;
        	if(g.size()>1){
        		system("cls");
        		cout<<"Opcion no valida!!!"<<endl;
        		pausarBorrar();
			}else{
			
            switch (g[0]){
				case '1':
					do{
					    
			            system("cls");
				    	cout<<"Vamos a ingresar los datos de la vaquita numero "<<cuentaVaca+1<<endl<<endl;
				    	pausarBorrar(); 
						int bandera=0;	
				    	do{	    		
					  		fflush( stdin );
					   		system("cls");
				    		cout<<"Ingrese el nombre de la vaquita en mayuscula: ";	    		
					    	fgets(n,100,stdin);	
					    	if(!entradaNombre(n)==true){
					    		imprimirError("ERROR!!! El nombre de la vaquita debe\nestar escrito en mayuscula, no debe comenzar con un numero\nni superar el limite 15 de caracteres\nIngrese los datos requeridos correctamente.");
							}else{
						    	string aux=n;
						    	int dentro=1,contador=0;
						    	do{
						    		if(aux==listaVaca[contador].getNombre()){
						    			system("cls");
						    			cout<<"Nombre ya existe en la lista"<<endl;
						    			pausarBorrar();
						    		    dentro=0;
									}else if(contador>cuentaVaca-2){
										dentro=0;
										listaVaca[cuentaVaca].setNombre(aux);
						    	        bandera=1;
									}
						    		contador++;
						    		
								}while(dentro==1 && contador!=cuentaVaca);	
							}
				        }while(bandera==0);
				    	system("cls");    	
					    do{
					    	bandera=0;					    	
					       	cout<<"Ingrese la raza de la vaquita en mayuscula: ";
					       	cin>>temporalS;
					   		if(entradaRaza(temporalS)==false){
		    					imprimirError("ERROR!!! La raza de la vaquita solo debe contener letras\ny tiene un limite de 15 caracteres.\nIngrese el dato requerido correctamente");
							}else{
								bandera=1;
								listaVaca[cuentaVaca].setRaza(temporalS);		
							}
				        }while(bandera==0);					        	    	
					   	system("cls");
					   	do{
					   		cin.ignore(256,'\n');
		                    bandera=0;   	
				    	 	cout<<"Ingrese el peso de la vaquita : ";
				     		cin>>temporalN;
				     		if(entradaPeso(temporalN)==false){
	                           	system("cls");
							    imprimirError("ERROR!!! El peso de la vaquita solo debe contener valores numericos\ny no puede superar los 10 caracteres.\nIngrese el dato requerido correctamente");
							}else{	
							    float l;
								istringstream(temporalN)>>l;
								listaVaca[cuentaVaca].setPeso(l);
								bandera=1;
                            }
						}while(bandera==0);	
						system("cls");	
				    	do{
		                    bandera=0;   	
				    	 	cout<<"Ingrese los litros promedio de leche que produce la vaquita: ";
				     		cin>>temporalN;
				     		if(entradaPeso(temporalN)==false){
	                           	system("cls");
							    imprimirError("ERROR!!! Los litros de leche de la vaquita solo debe contener valores numericos\ny no puede superar los 10 caracteres.\nIngrese el dato requerido correctamente");
							}else{	
							    float l;
								istringstream(temporalN)>>l;
								listaVaca[cuentaVaca].setLitro(l);
								bandera=1;
                            }
						}while(bandera==0);									     	
				        	cuentaVaca++;
					    	system("cls");
					    do{       
						    fflush(stdin);                                             //Validación de la opción
					    	cout<<"Desea ingresar otra vaquita?s/n"<<endl;
					    	cin>>temporalS;
							if(temporalS!="s"&&temporalS!="n"&&temporalS!="S"&&temporalS!="N"){
								system("cls");
								cout<<"Respuesta no valida, presione la tecla correcta"<<endl;
								system("pause");
								system("cls");
							}	
					    }while(temporalS!="s"&&temporalS!="n"&&temporalS!="S"&&temporalS!="N");
					    system("cls");
				    }while(temporalS=="s" || temporalS=="S");		
				break;	
				break;	
				
				
				case '2':
					cout<<"En construccion..."<<endl;
                    pausarBorrar();	
			    	
				break;
				case '3':
					system("cls");
					g[0]=3;
				break;
				default:
					system("cls");
				    cout<<"Opcion no valida"<<endl;
				    pausarBorrar();
			}
	     }
        }while(g[0]!=3);
    cout<<"Fin del programa.\n\n";
    system("pause");
	return 0;
	
}
}

