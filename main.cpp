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


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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
					    	fflush(stdin);
					    	bandera=0;					    	
					       	cout<<"Ingrese el numero que corresponde a la raza de su vaquita:\n\n";
					       	cout<<"1) Guernsey\n\n2) Jersey\n\n3) Pasiega\n\n4) Simmental\n\nOpcion: ";
					       	cin>>temporalS;
					       	
					   		if(temporalS=="1"){
					   			temporalS="GUERNSEY";
					   			listaVaca[cuentaVaca].setRaza(temporalS);
					   			bandera=1;
					   			
							}else if(temporalS=="2"){
								temporalS="JERSEY";
					   			listaVaca[cuentaVaca].setRaza(temporalS);
					   			bandera=1;
							}else if(temporalS=="3"){
								temporalS="PASIEGA";
					   			listaVaca[cuentaVaca].setRaza(temporalS);
					   			bandera=1;
							}else if(temporalS=="4"){
								temporalS="SIMMENTAL";
					   			listaVaca[cuentaVaca].setRaza(temporalS);
					   			bandera=1;
							}else{
								system("cls");
         						cout<<"Seleccione una opcion valida\n\n";
         						pausarBorrar();
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
					system("cls");
					if(cuentaVaca==0){
						cout<<"No hay vaquitas en la lista."<<endl;
						pausarBorrar();
					}else{
					do{
					 
						cout<<"Por favor ingrese el numero correspondiente a la tarea que desea realizar\n\n"<<endl;
						cout<<"1) Ordenar por nombre\n\n2)Ordenar por raza\n\n3) Ordenar por peso\n\n4) Ordenar por litros de leche\n\n5) Volver al menu anterior"<<endl<<endl<<"Opcion: ";
						cin>>g;
				   		 if(g.size()>1){
        	       		 	g[0]=6;
		           		}
                   		switch (g[0]){
                    		case '1':
                    			system("cls");
                    			cout<<"Lista ordenada por nombre\n\n";
					      		for (int i = 0; i < cuentaVaca; i++) {
	                     	 	    for (int j = 0; j <= cuentaVaca-2; j++) {
	                        	    	string aux1=listaVaca[j].getNombre();
	                        	    	string aux2=listaVaca[j+1].getNombre();
	                        	  	 	char comparar1[15];//=listaVaca[j].getNombre();
						   	   		   	char comparar2[15];//=listaVaca[j+1].getNombre();
						   		   		int tam1=aux1.size();
				   		   			   	int tam2=aux2.size();
				   		   			   	for(int x=0;x<=tam1;x++){
                    	         	   	  	comparar1[x]=aux1[x];
                    	       	  	    }
						    	  	   	for(int x=0;x<=tam2;x++){
	                      	  		   	   	comparar2[x]=aux2[x];
                       	     		    } 	                     	 	    	
	                                 	if (strncmp(comparar1, comparar2,15)>0){
	                 	    	 	   			auxiliar = listaVaca[j];
		             	   		       			listaVaca[j] =listaVaca[j+1];
		            			           		listaVaca[j+1] = auxiliar;
			        	    	        }
	                	    	    } 
                   	       		}
							    imprimirTitulo("Nombre","Raza","Peso","Litros"); 
								for (int i=0;i<cuentaVaca;i++){
	                                cout <<setw(15)<<left<< listaVaca[i].getNombre()<<setfill(' ')<<setw(15)<<left<<listaVaca[i].getRaza()<<setfill(' ')<<setw(15)<<left<<listaVaca[i].getPeso()<<setfill(' ')<<setw(15)<<left<<listaVaca[i].getLitro()<<endl;			    
                            	}
                            pausarBorrar();                   		
                    		break;
                    		case '2':
                    			system("cls");
                    			cout<<"Lista ordenada por raza\n\n";
					      		for (int i = 0; i < cuentaVaca; i++) {
	                     	 	    for (int j = 0; j <= cuentaVaca-2; j++) {
	                        	    	string aux1=listaVaca[j].getRaza();
	                        	    	string aux2=listaVaca[j+1].getRaza();
	                        	  	 	char comparar1[15];//=listaVaca[j].getNombre();
						   	   		   	char comparar2[15];//=listaVaca[j+1].getNombre();
						   		   		int tam1=aux1.size();
				   		   			   	int tam2=aux2.size();
				   		   			   	for(int x=0;x<=tam1;x++){
                    	         	   	  	comparar1[x]=aux1[x];
                    	       	  	    }
						    	  	   	for(int x=0;x<=tam2;x++){
	                      	  		   	   	comparar2[x]=aux2[x];
                       	     		    } 	                     	 	    	
	                                 	if (strncmp(comparar1, comparar2,15)>0){
	                 	    	 	   			auxiliar = listaVaca[j];
		             	   		       			listaVaca[j] =listaVaca[j+1];
		            			           		listaVaca[j+1] = auxiliar;
			        	    	        }
	                	    	    } 
                   	       		}
				       		  	for(int x =0;x<cuentaVaca;x=x+rep){  
				   	  	 		   	rep=0;  	
				       	  	 		for(int y = x; y<cuentaVaca;y++){
				       			   		string h=listaVaca[y+1].getRaza();
				      	 	   			string g=listaVaca[x].getRaza();
				      	 		   		if(g==h){
				      	 		   			rep++;
				   				   		}
				   			   		}
					   			   	if(rep>0){	
					   		  	 		for (int i = 0 ; i < rep; i++) {
	                           		 	 	for (int j = x; j <=x+rep-1; j++) {
	                           		 	  		string aux1=listaVaca[j].getNombre();
	                            		  		string aux2=listaVaca[j+1].getNombre();
	                            		 	 	char comparar1[15];//=listaVaca[j].getNombre();
						   	   				   	char comparar2[15];//=listaVaca[j+1].getNombre();
						   	   			   		int tam1=aux1.size();
						   	   				   	int tam2=aux2.size();
						   		   			   	for(int x=0;x<=tam1;x++){
	                       		      	     	  	comparar1[x]=aux1[x];
                            	    	  	    }
							    		  	   	for(int x=0;x<=tam2;x++){
	                            		  	      	comparar2[x]=aux2[x];
                              	     		    }  	                           		
	                   		     	   		    if (strncmp(comparar1, comparar2,15)>0){
	                    	     	   			    auxiliar = listaVaca[j];
		               	            		   	   	listaVaca[j] =listaVaca[j+1];
		         	   		          	           	listaVaca[j+1] = auxiliar;
			           	            	 	    }
	                    	           	    } 
                          	        	}
						   	   		}else{
							   	   		rep=1;
							      	}		
				   			    }                   	       		
							     imprimirTitulo("Raza","Nombre","Peso","Litros"); 
								for (int i=0;i<cuentaVaca;i++){
	                                cout <<setw(15)<<left<< listaVaca[i].getRaza()<<setfill(' ')<<setw(15)<<left<<listaVaca[i].getNombre()<<setfill(' ')<<setw(15)<<left<<listaVaca[i].getPeso()<<setfill(' ')<<setw(15)<<left<<listaVaca[i].getLitro()<<endl;			    
                            	}
                                pausarBorrar();                      			
                   		 	break;
                    	
                    		case '3'://ORDENA POR PESO 3
                    			system("cls");
                    			cout<<"Lista ordenada por peso\n"<<endl;
					      		for (int i = 0; i < cuentaVaca; i++) {
					      			
					      			
	                     	 	    for (int j = 0; j <= cuentaVaca-2; j++) {
	                   	   		   		if (listaVaca[j].getPeso() > listaVaca[j+1].getPeso()){
	                    	     	   			    auxiliar = listaVaca[j];
		               	            		   	   	listaVaca[j] =listaVaca[j+1];
		         	   		          	           	listaVaca[j+1] = auxiliar;
			        	    	        }
	                	    	    } 
                   	       		}
				       		  	for(int x =0;x<cuentaVaca;x=x+rep){  
				   	  	 		   	rep=0;  	
				       	  	 		for(int y = x; y<cuentaVaca;y++){
				       			   		float h=listaVaca[y+1].getPeso();
				      	 	   			float g=listaVaca[x].getPeso();
				      	 		   		if(g==h){
				      	 		   			rep++;
				   				   		}
				   			   		}
					   			   	if(rep>0){	
					   		  	 		for (int i = 0 ; i < rep; i++) {
	                           		 	 	for (int j = x; j <=x+rep-1; j++) {
	                           		 	  		string aux1=listaVaca[j].getNombre();
	                            		  		string aux2=listaVaca[j+1].getNombre();
	                            		 	 	char comparar1[15];//=listaVaca[j].getNombre();
						   	   				   	char comparar2[15];//=listaVaca[j+1].getNombre();
						   	   			   		int tam1=aux1.size();
						   	   				   	int tam2=aux2.size();
						   		   			   	for(int x=0;x<=tam1;x++){
	                       		      	     	  	comparar1[x]=aux1[x];
                            	    	  	    }
							    		  	   	for(int x=0;x<=tam2;x++){
	                            		  	      	comparar2[x]=aux2[x];
                              	     		    }  	                           		
	                   		     	   		    if (strncmp(comparar1, comparar2,15)>0){
	                    	     	   			    auxiliar = listaVaca[j];
		               	            		   	   	listaVaca[j] =listaVaca[j+1];
		         	   		          	           	listaVaca[j+1] = auxiliar;
			           	            	 	    }
	                    	           	    } 
                          	        	}
						   	   		}else{
							   	   		rep=1;
							      	}		
				   			    }
				   			    imprimirTitulo("Peso","Nombre","Raza","Litros");
								for (int i=0;i<cuentaVaca;i++){
	                                cout <<setw(15)<<left<< listaVaca[i].getPeso()<<setfill(' ')<<setw(15)<<left<<listaVaca[i].getNombre()<<setfill(' ')<<setw(15)<<left<<listaVaca[i].getRaza()<<setfill(' ')<<setw(15)<<left<<listaVaca[i].getLitro()<<endl;			    
                            	}
                            pausarBorrar();   				   			    
				   			break;
							case '4':
								system("cls");
								cout<<"Lista ordenada por litros de leche\n\n";
					   		   	for (int i = 0; i < cuentaVaca; i++) {
	                     	 	    for (int j = 0; j <= cuentaVaca-2; j++) {
	                   	   		   		if (listaVaca[j].getLitro() > listaVaca[j+1].getLitro()){
	                 	  			   	   		auxiliar = listaVaca[j];
		             	 		           		listaVaca[j] =listaVaca[j+1];
		            			           		listaVaca[j+1] = auxiliar;
			        	   		        }
	                	    	    }  
                   	       		}
				    	     	for(int x =0;x<cuentaVaca;x=x+rep){  
				   	  	 		   	rep=0;  	
				       		   		for(int y = x; y<cuentaVaca;y++){
				       			   		float h=listaVaca[y+1].getLitro();
				      	 		   		float g=listaVaca[x].getLitro();
				      	 	   			if(g==h){
				      	 	   				rep++;
				   				   		}
				   		   			}
					   			   	if(rep>0){	
					   			   		for (int i = 0 ; i < rep; i++) {
	                        	    	 	for (int j = x; j <=x+rep-1; j++) {
	                        	    	  		string aux1=listaVaca[j].getNombre();
	                        	    	  		string aux2=listaVaca[j+1].getNombre();
	                        	    	 	 	char comparar1[15];//=listaVaca[j].getNombre();
						   		   			   	char comparar2[15];//=listaVaca[j+1].getNombre();
						   		   		   		int tam1=aux1.size();
						   		   			   	int tam2=aux2.size();
						   		   			   	for(int x=0;x<=tam1;x++){
	                    	         	     	  	comparar1[x]=aux1[x];
                    	            	  	    }
								    	  	   	for(int x=0;x<=tam2;x++){
	                            	  		   	   	comparar2[x]=aux2[x];
                              	     		    }  	                           		
	                        	   			    if (strncmp(comparar1, comparar2,15)>0){
	                         	   				    auxiliar = listaVaca[j];
		                           			   	   	listaVaca[j] =listaVaca[j+1];
		         	             		           	listaVaca[j+1] = auxiliar;
			                     	  	 	    }
	                            	   	    } 
                                	  	}
					   		   		}else{
							   	   		rep=1;
							      	}		
				   			    }
                   	    	   	imprimirTitulo("Litros","Nombre","Raza","Peso");
								for (int i=0;i<cuentaVaca;i++){
	                                cout <<setw(15)<<left<<listaVaca[i].getLitro()<<setw(15)<<left<< listaVaca[i].getNombre()<<setfill(' ')<<setw(15)<<left<<listaVaca[i].getRaza()<<setfill(' ')<<setw(15)<<left<<listaVaca[i].getPeso()<<setfill(' ')<<setw(15)<<left<<listaVaca[i].getLitro()<<endl;			    
                            	}
                            pausarBorrar();                      	    	   	
							break;
							case '5':
								g[0]=5;
							break;
							default:
						    system("cls");
					        cout<<"Opcion no valida"<<endl;
				    	    pausarBorrar();	
						}//CIERRA EL SWITCH SECUNDARIO
			    	}while(g[0]!=5);
			    	system("cls");
			}
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
