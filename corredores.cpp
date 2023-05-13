#include<iostream>
#include<stdlib.h>
#include<malloc.h>


using namespace std;

struct corredores  
{
    char nombre[30];
    float tiempo,promedio;
    corredores *siguiente; 
};
corredores *primero,*aux,*aux2; 

void registrar();
void consultar();

int op1,op2;

int main(){
     
     do
     {
        system("cls");
        cout<<"********************************"<<"\n\n";
        cout<<"*******MENU PRINCIPAL************"<<endl;
        cout<<"1.REGISTRAR CORREDORES"<<endl;
        cout<<"2.CONSULTAR TIEMPO CORREDORES"<<endl;
        cout<<"3.SALIR "<<endl;
        cout<<"*********************************"<<endl;
        cout<<"->";cin>>op1;


        switch (op1)
        {
          case 1: registrar();
          break;
          case 2: consultar();
          break;
          case 3: exit(0);
        }

        if(op1>3)
        {
           cout<<" LA OPCION SELECCIONADA NO EXISTE VUELVA A INTENTARLO"<<endl;
           cout<<"DESEA CONTINUAR 1.SI/2.NO -> ";cin>>op2;
        }
     }while(op2==1);
  
    return 0;
}

void registrar()
{
    system("cls");
     
     if (primero==NULL)
     {
        
        
        primero = (struct corredores *) malloc(sizeof(struct corredores));
        cout<<"\n";
        cout<<"INGRESE SU NOMBRE -> ";cin>>primero->nombre;
        cout<<"\n";
        cout<<"INGRESE SU TIEMPO -> ";cin>>primero->tiempo;

        primero->siguiente=NULL;

        cout<<"\n";

             cout<<" DESEA CONTINUAR "<<endl;
            cout<<"1.VOLVER AL MENU"<<endl;
            cout<<"2.CONTINUAR "<<endl;
            cout<<"3.SALIR "<<endl;
            cin>>op1;

            if(op1==1)
            {
                main();
            }else if(op1==2)
            {
                registrar();
            }else if(op1==3)
            {
                exit(0);
            }

     }else
     {
        

        aux = (struct corredores *) malloc(sizeof(struct corredores));
        cout<<"\n";
        cout<<" INGRESE SU NOMBRE -> ";cin>>aux->nombre;
        cout<<"\n";
        cout<<"INGRESE SU TIEMPO -> ";cin>>aux->tiempo;

        aux->siguiente = NULL;
        aux2 = primero;

        while(aux2->siguiente!=NULL)
        
            aux2 = aux2->siguiente;
            aux2->siguiente = aux;
            aux2 = aux = NULL;

            free(aux);
            free(aux2);

            cout<<"\n";


             cout<<" DESEA CONTINUAR "<<endl;
            cout<<"1.VOLVER AL MENU"<<endl;
            cout<<"2.CONTINUAR "<<endl;
            cout<<"3.SALIR "<<endl;
            cin>>op1;

            if(op1==1)
            {
                main();
            }else if(op1==2)
            {
                registrar();
            }else if(op1==3)
            {
                exit(0);
            }

     }

     
       
     


}

void consultar()
{
   system("cls");

  
   for(aux = primero;aux!=NULL;aux = aux->siguiente)
   {
    
    cout<<"*****************************************"<<endl;
    cout<<" SU NOMBRE ES -> "<<aux->nombre<<endl;
    cout<<" su tiempo es  -> "<<aux->tiempo<<endl;
    cout<<"******************************************"<<endl;
    cout<<"\n";

    
  
     
   }
 
   

     cout<<" DESEA CONTINUAR "<<endl;
            cout<<"1.VOLVER AL MENU"<<endl;
            cout<<"2.CONTINUAR "<<endl;
            cout<<"3.SALIR "<<endl;
            cin>>op1;

            if(op1==1)
            {
                main();
            }else if(op1==2)
            {
                consultar();
            }else if(op1==3)
            {
                exit(0);
            }

}