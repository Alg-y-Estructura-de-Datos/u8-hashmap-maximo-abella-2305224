#include <iostream>
using namespace std;
#include "HashMap/HashMap.h"
#include "menu.h"

unsigned int giveID(int anterior) {
    return anterior +1;
}


int main() {
    cout << "Ejercicio N° 2" << endl;
    int anterior = 0;
    unsigned int tam = 10;
    HashMap<int,std::string> Empleados(tam,giveID);

    UiMenu::Menu m1[5] {
        {1,"Agregar un empleado"},
        {2,"Buscar empleado"},
        {3,"Eliminar empleado"},
        {4,"Imprimir lista de empleados"},
        {0,"Salir"}
    };
    UiMenu::MostrarMenu(4,m1);
while (true)
{
    int seleccion = UiMenu::selection(m1,5);
    switch (seleccion)
    {
    case 0:{
        return 0;
        break;
    }
    case 1:{
        try
        {
            int id;
            std::string nombre;
            std::cout<<"Ingrese el nombre del empleado"<<std::endl;
            std::cin>>nombre;
            Empleados.put(anterior,nombre);
            anterior++;
        }
        catch(...)
        {
            std::cout<<"El id ingresado ya existe"<<std::endl;
        }
        break;
    }
    case 2:{
        std::cout<<"Ingrese el id de empleado a buscar"<<std::endl;
        int id;
        std::cin>>id;
        try
        {
            std::string nombre = Empleados.get(id);
            std::cout<<"El nombre del empleado con id "<<id<<" es "<<nombre<<std::endl;
        }
        catch(...)
        {
            std::cout<<"El empleado no existe"<<std::endl;
        }
        
        break;
    }
    case 3:{
        std::cout<<"Ingrese un id a eliminar"<<std::endl;
        int id;
        std::cin>>id;
        try
        {
            Empleados.remove(id);
            std::cout<<"Empleado removido"<<std::endl;
        }
        catch(...)
        {
            std::cout<<"La persona ingresada no existe"<<std::endl;
        }
        
        break;
    }
    case 4:{
        Empleados.print();
        break;
    }
    default:
        break;
    }

}
    return 0;
}
