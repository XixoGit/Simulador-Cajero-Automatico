#include<stdio.h>                  //peligroso” mezclar órdenes “gets” y “scanf, los números los leeremos “en dos etapas”:
#include<conio.h>                // primero leeremos una cadena con “gets” y luego la convertiremos a número con “sscanf”.
#include<iostream>
#include<string.h>  
#include<fstream>
                                                           
using namespace std;
struct Usuario{
       string nombre;
       string apellido;
       int clave;
       int dni;
       double saldo;
       int numCuenta;
       int flag;
      
};
 
int cargarUsuario(struct Usuario array[],int cant);
void cantReg(int *cant);
void Mostrar(struct Usuario array[],int cant);
void depositar(struct Usuario array[],int cant);
void extraer(struct Usuario array[],int cant);
bool muestraMatriz(int dni);
void depositarDolares(struct Usuario array[],int cant);
void extraerDolares(struct Usuario array[],int cant);
void consultar(struct Usuario array[],int cant);
void guardarDatos(struct Usuario array[],int cant);
void MENU(int *op);

int main(){
      system("COLOR 1E");
    // system("COLOR 16"); color azul oscuro
    struct Usuario array[10];
    ofstream archivo;     
    int  opcion;
    int cant=0;
     
  
    
    MENU(&opcion);
    
	while(opcion!=9){
                     
		switch(opcion){
    	
        case 1: 
            cant=cargarUsuario( array,cant);
	     	MENU(&opcion);
            break;
            
		case 2: 
            Mostrar( array ,  cant);
            MENU(&opcion);
            break;
            
		case 3: 
            consultar( array, cant);
          	MENU(&opcion);
            break;
        case 4: 
            depositar( array, cant);
          	MENU(&opcion);
            break;
        case 5: 
            extraer( array, cant);
          	MENU(&opcion);
            break;
        case 6: 
            depositarDolares( array, cant);
          	MENU(&opcion);
            break;
        case 7: 
            extraerDolares( array, cant);
          	MENU(&opcion);
            break;
		case 8: 
            guardarDatos(array,cant);
          	MENU(&opcion);
            break;
		}
	}
		cout<<" SALIENDO...................."<<endl;
  system("PAUSE");
	return 0;
}

void MENU(int *op){
    // system("cls");
    	cout<<" \n\n   ==========Sistema de simulacon de Cajero automatico Banelco ============\n"<<endl; 
    	cout<<" \n\n \t\t\t  PRESIONE LA TECLA QUE \n\t\t\t INDICA LA OPERACION QUE \n\t\t\t     DESEA EFECTUAR\n"<<endl; 
	cout<<" \n     1 <--------- CARGAR USUARIOS    \t MOSTRAR USUARIOS ---------> 2\n\n\n     3 <--------- CONSULTAR SALDO    \t DEPOSITAR EN PESOS  ------> 4 \n "<<endl;
	cout<<" \n     5 <------ EXTRACION EN PESOS     \t DEPOSITAR EN DOLARES -----> 6   \n\n\n     7 <---- EXTRACION EN DOLARES \t GUARDAR EN ARCHIVO -------> 8   \n\n\n     9 <------------------- SALIR  \n"<<endl;
    cout<<" \n Ingrese Opcion: ";
    fflush( stdin); 
 	scanf("%d",op);
  
 	while(*op<1||*op>10){   //mietras opcion sea menor a 1 o mayor a 8 
     cout<<"\n ERROR !!! - Ingrese opcion: ";
     fflush( stdin); 
     scanf("%d",op);
    }
 	 
}
void cantReg(int *cant){
    //  system("cls");
     cout<<"\n    Ingrese cantidad de usuarios a cargar :  " ;
     fflush( stdin); 
     scanf("%d",cant);
     while(*cant<1||*cant>9){   //mietras opcion sea menor a 1 o mayor a 8 
     cout<<"\n ERROR !!! - Ingrese opcion valida : ";
     fflush( stdin); 
     scanf("%d",cant);
    } 
}     

int cargarUsuario(struct Usuario array[],int cant){
    system("cls");
    if (cant>0){  
                  
              cout<<"\n  Ya hay usuarios cargados     "; 
              cout<<"\nPresione una tecla para continuar... \n"<<endl;   
              getch();
      return cant;
     }            
     cantReg(&cant);
    
     for(int i=0;i<cant;i++){
            
          // archivo.open("archivo.txt",ios::out|ios::app);  
           cout<<"\n    Ingrese nombre del  usuario  nro "<<i+1<<"         :     ";
           fflush(stdin);            
           cin>>array[i].nombre;            //  gets(array[i].nombre);    
           cout<<"    Ingrese DNI                                :     ";
           fflush(stdin);
           cin>>array[i].dni;
           cout<<"    Ingrese monto para inicializar cuenta      :   $ ";
           fflush(stdin);
           cin>>array[i].saldo;
           cout<<"    Ingrese clave (numerica)                   :     ";
           fflush(stdin);
           cin>>array[i].clave;
           array[i].numCuenta= 2400000 + i+2;
           
           array[i].flag=1;
             
       }
     cout<<"\n\n\n    Usuarios cargados, presione una tecla para continuar...     ";
     getch();
      return cant;
}

void Mostrar(struct Usuario array[],int cant){
     
     if(cant==0){
           system("cls");
          cout<<"\n----------------No hay Usuarios Cargados----------------\n"<<endl;
          cout<<"\nPresione una tecla para continuar... \n"<<endl;
          getch();
     }else{
           system("cls");
      cout<<"\n\t---------------Listado de Usuarios----------------\n"<<endl;
     for(int i=0;i<cant;i++){
           cout<<"    Usuario nro "<<i+1<<"  ---------------nro cuenta: 5000"<< array[i].numCuenta<<endl;   
           cout<<"    -------------------------------"<<endl;   
           cout<<"    Nombre      : \t"<< array[i].nombre<<endl;         
           cout<<"    DNI         : \t" <<array[i].dni<<endl;
           cout<<"    Saldo disp. : $ \t" << array[i].saldo<<" pesos"<<endl;   
                  
           cout<<"    -------------------------------"<<endl;    
             
     }
     cout<<"\nPresione una tecla para continuar... \n"<<endl;
          getch();
   }  
}
 

 void depositar(struct Usuario array[],int cant){  // metodo agragado deposita un mondo al saldo del usuario
 system("cls");
     if(cant==0){
           system("cls");
          cout<<"\n----------------No hay Usuarios Cargados----------------\n"<<endl;
          cout<<"\nPresione una tecla para continuar... \n"<<endl;
          getch();
          return;
     }
      cout<<"\n -----------DEPOSITO EN PESOS -----------"<<endl;
      int c=0;                                             // traemos como parametro a la estructura y a cant , por q la vamosa  usar
    
     int clave2=0;      //creamos una clave auxiliar
     int monto=0;   
     int correctClave=1;     //si la clave no es correcta
  
                
          
     cout<<"\n Ingrese clave :  ";
     cin>>clave2;
     
    do{
     for(int i=0;i<cant;i++){   // recorremos la estruct. ,   en realidad recorremos el vector persona 
     
	   if(clave2==array[i].clave){   // en su recorrido comparamos las claves q se guardaron en la carga con la ingresada 
             int valor=0;
             bool m=false;
           system("cls"); 
          cout<<"\n   Cliente : "<<  array[i].nombre<< " \t\t  num. Cuenta :  xxxxx-240000xxxxxxxx\n"<<endl; 
          cout<<"\n\n   Recuerde que los billetes deben ser multiplos de 10 \t "<<endl;
           valor=array[i].dni;
           
       
           
            // cout<<"\n Su saldo actual es  :$ "<<array[i].saldo<<" pesos\n"<<endl;  
            cout<<"\n\n\n   Ingrese monto a depositar en pesos :\n\n\n\t $ ";     
            cin>>monto;
             m=muestraMatriz( valor);
          if(m){
               cout<<"\   nopcion correcta"<<endl;   
                  
           }else {
            cout<<"   opcion incorrecta"<<endl; 
            cout<<"\nPresione una tecla para continuar... \n"<<endl;
            getch();
            return;   
            }
            system("cls");
             cout<<"\n   Cliente : "<<  array[i].nombre<< " \t\t  num. Cuenta :  xxxxx-240000xxxxxxxx\n"<<endl;
             
            array[i].saldo = array[i].saldo + monto;            // sumamos el momto a la cuenta         
          //  cout<<"\n Su saldo actual es  : $  "<<array[i].saldo<< " pesos"<<endl; 
          cout<<"\n\n\n\n   Su deposito de :$ "<<monto<<" se ha realizado con exito"<<endl;   
            // cout<<"\n Deposito Realizado \n"; 
            cout<<"\n\n\n\n\n   Operacion Exitosa \n"; 
            
           	cout<<"\n\n\n------------- * FIN OPERACION * ---------------\n"<<endl; 
           	cout<<"\n\n  Presione una tecla para salir...\n"<<endl; 
           getch();
          
           correctClave=0;       //cambiamos el estado de la variable a 0 que indica q la clave fue correcta
       }else{
            int correctClave=1;        
       }         
    }
    if(correctClave==1){
     cout<<"!Clave incorrecta!  - Ingrese clave  \t Recuerde que tiene hasta 3 ingresos"<<endl;
     cin>>clave2;     
    c=c+1;
    }
 

  }while(correctClave!=0 && c<=2);
    if(c==3){ cout<< " Ha agotado las opciones ... saliendo..."<<endl;}
             
}
     
bool muestraMatriz(int dni){
     
  int randomNum=0+rand()%(2-1); // random entre 0 y 1 
   if(randomNum==1){
     
     int a;
     int num=dni;
     int num2=num/1000;  //num2=27982
     int tercera= num-(num2*1000); // tercera=999 
 
     int ri=0+rand()%(9-1); // random entre 0 y 8 [8] 
     
   
     int array[8];
    
  for (int i = 0;i<8;i++){   //recorremos la matriz 4x2 y vamos  generando n aleatorios de 3 cifras
        
            array[i]=100+rand()%(900-1); // random entre 100 y 999
             if(array[i]==array[ri]){ 
                  array[i]=tercera;        //guardamos los 3 numeros del DNI XXX en una pos de la matriz                         
             }
       
  }
   system("cls");
    
   cout<<"\n\t-------------matriz-------------\n"<<endl;
      
      cout<<"\t0->> "<<array[0]<<"\t\t "<<array[1]<<" <<-1\n"<<endl;
       cout<<"\t2->> "<<array[2]<<"\t\t "<<array[3]<<" <<-3\n"<<endl;
        cout<<"\t4->> "<<array[4]<<"\t\t "<<array[5]<<" <<-5\n"<<endl;
         cout<<"\t6->> "<<array[6]<<"\t\t "<<array[7]<<" <<-7\n"<<endl;                                       // mostramos la matriz con los n aleatorios  y el XXX del DNI
    
   cout<<"\n\t-------------matri--z-----------\n"<<endl;
  cout<<"  DNI: "<<num2<<".XXX"<<endl;
  cout<<"\n\n\n  Los 3 utimos nª de su DNI estan en la posicion...? "<<endl;
  cin>>a;
 
     if(ri==a  ){           // si se selecciona la pos donde esta guardado el XXX del dni retorna true
        return true;  
     }else{
           return false;
       }
    
   }else{
      int b;
       int dni2=dni; 
        
       dni2=dni2/1000; //27982
       int ultima=dni-dni2*1000;//316
       
       int primera=dni2/1000; //27
     int   segunda= dni2-primera*1000;  //982
     int ri=0+rand()%(9-1); // random entre 0 y 8 [8] 
     
   
     int array2[8];
    
  for (int i = 0;i<8;i++){   //recorremos la matriz 4x2 y vamos  generando n aleatorios de 3 cifras
    
            array2[i]=100+rand()%(900-1); // random entre 100 y 999
             if(array2[i]==array2[ri]){ 
                  array2[i]=segunda;        //guardamos los 3 numeros del DNI XXX en una pos de la matriz                         
             }
   
  }
  system("cls");
     
  cout<<"\n\t-------------matriz-------------\n"<<endl;
      cout<<"\t0->> "<<array2[0]<<"\t\t "<<array2[1]<<" <<-1\n"<<endl;
       cout<<"\t2->> "<<array2[2]<<"\t\t "<<array2[3]<<" <<-3\n"<<endl;
        cout<<"\t4->> "<<array2[4]<<"\t\t "<<array2[5]<<" <<-5\n"<<endl;
         cout<<"\t6->> "<<array2[6]<<"\t\t "<<array2[7]<<" <<-7\n"<<endl;                                       // mostramos la matriz con los n aleatorios  y el XXX del DNI
    
  cout<<"\n\t-------------matriz-------------\n"<<endl;
  cout<<"\tDNI: "<<primera<<".XXX."<<ultima <<endl;
  cout<<"\n\n\n  Los 3 utimos nª de su DNI estan en la posicion...? "<<endl;
  cin>>b;
 
     if(ri==b  ){           // si se selecciona la pos donde esta guardado el XXX del dni retorna true
        return true;  
     }else{
           return false;
       }
          
   } 
 }
  void extraer(struct Usuario array[],int cant){  // metodo agragado deposita un mondo al saldo del usuario
   if(cant==0){
          system("cls");
          cout<<"\n----------------No hay Usuarios Cargados----------------\n"<<endl;
          cout<<"\n  Presione una tecla para continuar... \n"<<endl;
          getch();
          return;
     }
    system("cls");
     cout<<"\n--------------- EXTRACCION EN PESOS ----------------\n\n"<<endl;
      int c=0;                                             // traemos como parametro a la estructura y a cant , por q la vamosa  usar
    
     int clave2=0;      //creamos una clave auxiliar
     int monto=0;   
     int correctClave=1;     //si la clave no es correcta
  
                
          
     cout<<"Ingrese clave :  ";
     cin>>clave2;
     
    do{
     for(int i=0;i<cant;i++){   // recorremos la estruct. ,   en realidad recorremos el vector persona 
     
	   if(clave2==array[i].clave){   // en su recorrido comparamos las claves q se guardaron en la carga con la ingresada 
             int valor=0;
             bool m=false;
          system("cls");
           cout<<"\n   Cliente : "<<  array[i].nombre<< " \t\t  num. Cuenta :  xxxxx-240000xxxxxxxx\n"<<endl;
           cout<<"\n\n   Recuerde que debe seleccionar multiplos de diez \t "<<endl;
           valor=array[i].dni;
           
              cout<<"\n\n\n\n\t   Ingrese monto a extraer en pesos :\n\n\n\t $ ";       
            cin>>monto;
             m=muestraMatriz( valor);
          if(m){
               cout<<"opcion correcta"<<endl;      
           }else {
            cout<<"opcion incorrecta"<<endl; 
            cout<<"\nPresione una tecla para continuar... \n"<<endl;
            getch();
            return;   
            }
            if(monto<array[i].saldo ){
            array[i].saldo = array[i].saldo -monto;            // sumamos el momto a la cuenta         
           system("cls");
           cout<<"\n\n Extraccion Realizada \n"; 
            cout<<"\n\n\n\n\n Operacion Exitosa "<<endl; 
            
           	cout<<"\n\n\n----------------FIN OPERACION ---------------\n"<<endl; 
           	cout<<"\nPresione una tecla para continuar... \n"<<endl;
          
             cout<<" Saliendo ... "<<endl; 
             getch();
            }else{
             cout<<" Saldo insuficiente "<<endl;  
             cout<<"\nPresione una tecla para continuar... \n"<<endl;
          
             cout<<" Saliendo ... "<<endl;   
              getch();
             return;
            }     
            
           correctClave=0;       //cambiamos el estado de la variable a 0 que indica q la clave fue correcta
       }else{
            int correctClave=1;        
       }         
    }
    if(correctClave==1){
     cout<<"!Clave incorrecta!  - Ingrese clave : \t\t Recuerde que tiene hasta 3 ingresos"<<endl;
     cin>>clave2;     
    c=c+1;
    }
 

  }while(correctClave!=0 && c<=2);
    if(c==3){ cout<< " Ha agotado las opciones ... saliendo..."<<endl;}
             
}
 void depositarDolares(struct Usuario array[],int cant){  // metodo agragado deposita un mondo al saldo del usuario
 system("cls");
     if(cant==0){
          system("cls");
          cout<<"\n----------------No hay Usuarios Cargados----------------\n"<<endl;
          cout<<"\nPresione una tecla para continuar... \n"<<endl;
          getch();
          return;
      }
     cout<<"\n ----------------DEPOSITO EN DOLARES -------------------\n"<<endl;
      int c=0;                                             // traemos como parametro a la estructura y a cant , por q la vamosa  usar
    
     int clave2=0;      //creamos una clave auxiliar
     int monto=0;   
     int correctClave=1;     //si la clave no es correcta
  
                
          
     cout<<"  Ingrese clave :  ";
     cin>>clave2;
     
    do{
     for(int i=0;i<cant;i++){   // recorremos la estruct. ,   en realidad recorremos el vector persona 
     
	   if(clave2==array[i].clave){   // en su recorrido comparamos las claves q se guardaron en la carga con la ingresada 
             int valor=0;
             bool m=false;
            
           cout<<"\n Bienvenido SR :\t "<<  array[i].nombre<<endl;
           valor=array[i].dni;
             cout<<"\t\t\t\t\t\t Cotizacion oficial a la fecha\n\t\t\t\t\t\t  US$ 1 dolar..............$ 6,90 pesos ARG."<<endl; 
       
           m=muestraMatriz( valor);
          if(m){
               cout<<"\n opcion correcta\n"<<endl;      
           }else {
            cout<<"\n opcion incorrectaºn"<<endl; 
            cout<<"\n Presione una tecla para continuar... \n"<<endl;
            getch();
            return;   
            }
           
           system("cls");
            cout<<"\n   Cliente : "<<  array[i].nombre<< " \t\t  num. Cuenta :  xxxxx-240000xxxxxxxx\n"<<endl;
           cout<<"\n\n   Recuerde que debe seleccionar multiplos de diez \t "<<endl;
            cout<<"\n\n\n\t Ingrese monto a depositar Dolares  \n\t: $Us  "<<endl;     
            cin>>monto;
            
           
            array[i].saldo = array[i].saldo + monto*6.90;   
            system("cls");         
           cout<<"\n\n Deposito Realizado \n";  
            cout<<"\n\n\n\n Operacion Exitosa \n";
             
           	cout<<"\n\n----------------FIN OPERACION --------------------\n"<<endl; 
          cout<<"\nPresione una tecla para continuar... \n"<<endl;
            getch();
           correctClave=0;       //cambiamos el estado de la variable a 0 que indica q la clave fue correcta
       }else{
            int correctClave=1;        
       }         
    }
    if(correctClave==1){
     cout<<"!Clave incorrecta!  - Ingrese clave : \t\t Recuerde que tiene hasta 3 ingresos"<<endl;
     cin>>clave2;     
    c=c+1;
    }
 

  }while(correctClave!=0 && c<=2);
    if(c==3){ cout<< " Ha agotado las opciones ... saliendo..."<<endl;}
             
}
  void extraerDolares(struct Usuario array[],int cant){  // metodo agragado deposita un mondo al saldo del usuario
  system("cls");
  if(cant==0){
          system("cls");
          cout<<"\n----------------No hay Usuarios Cargados----------------\n"<<endl;
          cout<<"\nPresione una tecla para continuar... \n"<<endl;
          getch();
          return;
      }
     cout<<"\n -------------$$ EXTRACCION EN DOLARES $$ ------------------\n"<<endl;
      int c=0;                                             // traemos como parametro a la estructura y a cant , por q la vamosa  usar
    
     int clave2=0;      //creamos una clave auxiliar
     int monto=0;   
     int correctClave=1;     //si la clave no es correcta
  
                
          
     cout<<"Ingrese clave :  ";
     cin>>clave2;
     
    do{
     for(int i=0;i<cant;i++){   // recorremos la estruct. ,   en realidad recorremos el vector persona 
     
	   if(clave2==array[i].clave){   // en su recorrido comparamos las claves q se guardaron en la carga con la ingresada 
             int valor=0;
             bool m=false;
              system("cls");
            cout<<"\n   Cliente : "<<  array[i].nombre<< " \t\t  num. Cuenta :  xxxxx-240000xxxxxxxx\n"<<endl;
            
           cout<<"\n   Bienvenido SR :\t "<<  array[i].nombre<<endl;
           cout<<"\n\n\n   Recuerde que debe seleccionar multiplos de diez \t "<<endl;
           valor=array[i].dni;
           
            cout<<"\n\n\n\t Ingrese monto a extraer en dolares  \n\t : $    ";     
            cin>>monto;
             m=muestraMatriz( valor);
          if(m){
               cout<<"opcion correcta"<<endl;      
           }else {
            cout<<"opcion incorrecta"<<endl; 
            cout<<"\nPresione una tecla para continuar... \n"<<endl;
            getch();
            return;   
            }
            if(monto*6,90<array[i].saldo ){
            array[i].saldo = array[i].saldo -monto;            // sumamos el momto a la cuenta         
           system("cls");
            cout<<"\n\n Extraccion Realizada \n";  
            cout<<"\n\n\n\n\n\n\n Operacion Exitosa "<<endl;
             
           	cout<<"\n\n---------------$$ FIN OPERACION  $$-------------------\n "<<endl; 
           	cout<<"\nPresione una tecla para continuar... \n"<<endl;
            getch();
            }else{
       
            
           	cout<<"\n\n\n------------- * FIN OPERACION * ---------------\n"<<endl; 
            cout<<" Saldo insuficiente "<<endl;  
             cout<<" Saliendo ... "<<endl; 
            getch();     
             
              
             return;
            }     
            
           correctClave=0;       //cambiamos el estado de la variable a 0 que indica q la clave fue correcta
       }else{
            int correctClave=1;        
       }         
    }
    if(correctClave==1){
     cout<<"!Clave incorrecta!  - Ingrese clave : \t\t Recuerde que tiene hasta 3 ingresos"<<endl;
     cin>>clave2;     
    c=c+1;
    }
 

  }while(correctClave!=0 && c<=2);
    if(c==3){ cout<< " Ha agotado las opciones ... saliendo..."<<endl;}
             
}

void consultar(struct Usuario array[],int cant){  // metodo agragado deposita un mondo al saldo del usuario
system("cls");
if(cant==0){
           system("cls");
          cout<<"\n----------------No hay Usuarios Cargados----------------\n"<<endl;
          cout<<"\n  Presione una tecla para continuar... \n"<<endl;
          getch();
          return;
     }
    cout<<"\n --------------- CONSULTAR SALDO  -----------------"<<endl;
      int c=0;                                             // traemos como parametro a la estructura y a cant , por q la vamosa  usar
    
     int clave2=0;      //creamos una clave auxiliar
     int monto=0;   
     int correctClave=1;     //si la clave no es correcta
  
                
          
     cout<<"\n  Ingrese clave : ";
     cin>>clave2;
     
    do{
     for(int i=0;i<cant;i++){   // recorremos la estruct. ,   en realidad recorremos el vector persona 
     
	   if(clave2==array[i].clave){   // en su recorrido comparamos las claves q se guardaron en la carga con la ingresada 
             int valor=0;
             bool m=false;
           
           cout<<"\n Bienvenido Sr :\t "<<  array[i].nombre<<endl;
           valor=array[i].dni;
           
             
             m=muestraMatriz( valor);
          if(m){
               cout<<"\nopcion correcta\n"<<endl;      
           }else {
            cout<<"\nopcion incorrecta\n"<<endl; 
            cout<<"\n  Presione una tecla para continuar... \n"<<endl;
            getch();
            return;   
            }
               system("cls"); 
              cout<<"\n   Cliente : "<<  array[i].nombre<< " \t\t  num. Cuenta :  xxxxx-240000xxxxxxxx\n"<<endl;
              cout<<"\n \n \n \t SU SALDO ES   : "<<endl;                    
               cout<<"\n \n \n \t $ "<<array[i].saldo<<" pesos\n"<<endl;  
              
            // cout<<"\n Consulta realizada"<<endl; 
               cout<<"\n \n\tOperacion Exitosa "<<endl; 
           	cout<<"\n\n\n  --------------* FIN OPERACION * ----------------\n\n"<<endl; 
           	cout<<"\n\n  Presione una tecla para continuar...\n"<<endl; 
           getch();
           
         
            
           correctClave=0;       //cambiamos el estado de la variable a 0 que indica q la clave fue correcta
       }else{
            int correctClave=1;        
       }         
    }
    if(correctClave==1){
     cout<<"!Clave incorrecta!  - Ingrese clave : \t\t Recuerde que tiene hasta 3 ingresos"<<endl;
     cin>>clave2;     
    c=c+1;
    }
 

  }while(correctClave!=0 && c<=2);
    if(c==3){ cout<< " Ha agotado las opciones ... saliendo..."<<endl;}
             
}
void guardarDatos(struct Usuario array[],int cant){
     system("cls");
     if(cant==0){
           system("cls");
          cout<<"\n----------------No hay Usuarios Cargados----------------\n"<<endl;
          cout<<"\n  Presione una tecla para continuar... \n"<<endl;
          getch();
          return;
          }
     ofstream entrada2;  
                           
     
     if(cant>0){
      cout<<"Espere mientras se guardan los datos...\t\tpresione una tecla para continuar...\n\n";           
     entrada2.open("entrada2.txt",ios::out|ios::app);  //ios::app 
      if(entrada2.fail()){
         cout<<"el archivo no se creo correctamente";
         //getch();
       }else{
         entrada2<<"*****Simulacion Cajero Automatico*****\n\n-Archivo de Registro de datos-\n\n "<<"Cantidad Usuarios: "<<cant<<"\n"<<endl;      
        for(int i=0;i<cant;i++){     
          
          entrada2<<"Usuario nro: "<<i+1<<"\n\n Nombre: "<<array[i].nombre  <<"\n Saldo: "<< array[i].saldo<<"\n DNI:"<<array[i].dni<<endl;
           time_t tiempo = time(0);
          struct tm *tlocal = localtime(&tiempo);
          char output[128];
          strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
          
          entrada2<<"\nFecha Operacion : "<<output <<" "<<endl; 
           entrada2<<" ---------------------------------------- "<<endl;  
         
         getch();
        }
         entrada2.close();
           cout<<"los datos se guardaron correctamente\n";
       }      
 }
     
}
