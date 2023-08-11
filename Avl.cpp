#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <limits> 
#include "Nodo.h"
#include "Arbol.h"

using namespace std;

int main()
{
    Arbol arbol;
    string nombre, apellido, nac;
    int registro = 0;
    int op = 0, eliArbol = 0, opMostrar = 0, NumRand = 0, registroBuscado = 0;
    char res = 0;
    cout << "***** Software: Hecho por FEEH *****" << endl;
    do {
        cout << "Ingrese que accion quiere realizar: " << endl;
        cout << "[1] Agregar Nodo\t [2] Eliminar Nodo" << endl;
        cout << "[3] Eliminar Arbol\t [4] Mostrar" << endl;
        cout << "[5] Contar\t\t [6] Altura Arbol" << endl;
        cout << "[7] Buscar\t\t [0] Terminar" << endl;
        cout << "[8] VER (Padre / HijoIzquierdo / HijoDerecho)" << endl;
        cin >> op;
        switch (op) {
        case 1:
        {
            cout << "Seleccionaste la opcion 1: Insertar" << endl;
            cout << "Quieres llenar el nodo de forma automatica si [Y] o no [N]" << endl;
            cin >> res;
            if (res == 'Y' or res == 'y')
            {
                srand(time(NULL));
                NumRand = rand() % 5 + 1;
                switch (NumRand) {
                case 1:
                    nombre = "Fernando";
                    break;
                case 2:
                    nombre = "Esteban";
                    break;
                case 3:
                    nombre = "Diego";
                    break;
                case 4:
                    nombre = "Aaron";
                    break;
                case 5:
                    nombre = "Alan";
                    break;
                }
                NumRand = rand() % 5 + 1;
                switch (NumRand) {
                case 1:
                    apellido = "Esquivel";
                    break;
                case 2:
                    apellido = "Hernandez";
                    break;
                case 3:
                    apellido = "Perez";
                    break;
                case 4:
                    apellido = "Dominguez";
                    break;
                case 5:
                    apellido = "Uribe";
                    break;
                }
                NumRand = rand() % 5 + 1;
                switch (NumRand) {
                case 1:
                    nac = "11/03/2005";
                    break;
                case 2:
                    nac = "15/05/2005";
                    break;
                case 3:
                    nac = "01/02/2003";
                    break;
                case 4:
                    nac = "16/12/2006";
                    break;
                case 5:
                    nac = "18/04/2004";
                    break;
                }
                registro = (rand() % (10000 - 1 + 1));
                Persona persona(nombre, apellido, nac, registro);
                arbol.Insertar(persona);
                cout << "Tu nodo random quedo como: " << endl;

                cout << "Nombre: " << persona.GetNombre() << endl;
                cout << "Apellido: " << persona.GetApellido() << endl;
                cout << "Fecha de nacimiento: " << persona.GetNac() << endl;
                cout << "Registro: " << persona.GetRegistro() << endl;
            }
            else
            {
                cout << "Ingrese los datos del nuevo nodo:" << endl;
                cout << "Nombre: ";
                cin >> nombre;
                cout << "Apellido: ";
                cin >> apellido;
                cout << "Fecha de nacimiento: (dd/mm/aaaa)";
                cin >> nac;
                cout << "Registro: ";
                cin >> registro;
                while (registro == 0)
                {
                    cout << "0 no es un registro valido" << endl;
                    cout << "Ingrese de nuevo el Registro: ";
                    cin >> registro;
                }
                Persona persona(nombre, apellido, nac, registro);
                arbol.Insertar(persona);
                cout << "\nNodo agregado correctamente" << endl;
            }
            cout << endl;
            break;
        }
        case 2:
        {
            cout << "Seleccionaste la opcion 2: Elimina" << endl;
            if (arbol.EsVacia())
            {
                cout << "El arbol esta vacio, no hay nada que eliminar" << endl;
                cout << endl;
                break;
            }
            cout << "Ingrese el registro que desea eliminar: ";
            cin >> registroBuscado;
            while (registroBuscado == 0)
            {
                cout << "0 no es un registro valido" << endl;
                cout << "Ingrese el registro que desea buscar: ";
                cin >> registroBuscado;
            }
            Persona personaEncontrada = arbol.BuscarNodo(registroBuscado);
            if (personaEncontrada.GetRegistro() == registroBuscado) {
                cout << "Usuario encontrado: " << endl;
                cout << "Nombre: " << personaEncontrada.GetNombre() << endl;
                cout << "Apellido: " << personaEncontrada.GetApellido() << endl;
                cout << "Fecha de nacimiento: " << personaEncontrada.GetNac() << endl;
                cout << "Registro: " << personaEncontrada.GetRegistro() << endl;
                cout << endl;
                cout << "Ahora lo vamos a eliminar." << endl;
                arbol.EliminarNodo(registroBuscado);
                cout << "Se ha eliminado correctamente." << endl;
            }
            else {
                cout << "Registro no encontrado, no se puede eliminar." << endl;
            }
            cout << endl;
            break;
        }
        case 3:
        {
            eliArbol = 0;
            cout << "Seleccionaste la opcion 3: Eliminar Arbol: " << endl;
            cout << "Estas seguro que quieres eliminar el arbol completo?" << endl;
            cout << "Presiona 1, si deseas cancelar" << endl;
            cin >> eliArbol;
            if (eliArbol == 1)
            {
                break;
            }
            arbol.EliminarArbol();
            cout << "Se ha eliminado el arbol correctamente" << endl;
            cout << endl;
            break;
        }
        case 4:
        {
            cout << "Seleccionaste la opcion 4: Mostrar" << endl;
            if (arbol.EsVacia())
            {
                cout << "El arbol esta vacio, no hay nada que mostrar" << endl;
                cout << endl;
                break;
            }
            do {
                opMostrar = 0;
                cout << "-------MENU MOSTRAR-------" << endl;
                cout << "Como quiere mostrar: " << endl;
                cout << "[1] InOrder\t [3] PostOrden" << endl;
                cout << "[2] PreOrden\t [4] Salir" << endl;
                cout << "--------------------------" << endl;
                cin >> opMostrar;
                switch (opMostrar) {
                case 1:
                    cout << "Arbol en orden:" << endl;
                    arbol.MostrarInOrden();
                    break;
                case 2:
                    cout << "Arbol en orden:" << endl;
                    arbol.MostrarPostorden();
                    break;
                case 3:
                    cout << "Arbol en preorden:" << endl;
                    arbol.MostrarPreorden();
                    break;
                case 4:
                    cout << "saliendo del MENU MOSTRAR.\n" << endl;
                    break;
                default:
                    cout << "Opcion no valida." << endl;
                    break;
                }
                cout << endl;
            } while (opMostrar != 4);
            break;
        }
        case 5:
        {
            cout << "Seleccionaste la opcion 5: Contar" << endl;
            int num = arbol.ContarNodos();
            cout << "La cantidad de nodos es: " << num << endl;
            cout << endl;
            break;
        }
        case 6:
        {
            cout << "Seleccionaste la opcion 6: Altura Arbol" << endl;
            int altura = arbol.CalcularAltura();
            cout << "Altura del arbol: " << altura << endl;
            cout << endl;
            break;
        }
        case 7:
        {
            cout << "Seleccionaste la opcion 7: Busqueda" << endl;
            if (arbol.EsVacia())
            {
                cout << "El arbol esta vacio, no hay nada que buscar" << endl;
                cout << endl;
                break;
            }
            cout << "Ingrese el registro que desea buscar: ";
            cin >> registroBuscado;
            while (registroBuscado == 0)
            {
                cout << "0 no es un registro valido" << endl;
                cout << "Ingrese el registro que desea buscar: ";
                cin >> registroBuscado;
            }
            Persona personaEncontrada = arbol.BuscarNodo(registroBuscado);
            if (personaEncontrada.GetRegistro() == registroBuscado) {
                cout << "Usuario encontrado: " << endl;
                cout << "Nombre: " << personaEncontrada.GetNombre() << endl;
                cout << "Apellido: " << personaEncontrada.GetApellido() << endl;
                cout << "Fecha de nacimiento: " << personaEncontrada.GetNac() << endl;
                cout << "Registro: " << personaEncontrada.GetRegistro() << endl;
            }
            else {
                cout << "Registro no encontrado." << endl;
            }
            cout << endl;
            break;
        }
        case 8:
        {
            cout << "Seleccionaste la opcion 8: VER" << endl;
            if (arbol.EsVacia())
            {
                cout << "El arbol esta vacio, no hay nada que ver" << endl;
                cout << endl;
                break;
            }
            cout << "Ingrese el nodo del que quiere ver:\nSu padre o hijos." << endl;
            cin >> registroBuscado;
            while (registroBuscado == 0)
            {
                cout << "0 no es un registro valido" << endl;
                cout << "Ingrese el nodo del que quiere ver:\n Su padre o hijos." << endl;
                cin >> registroBuscado;
            }
            Persona personaEncontrada = arbol.BuscarNodo(registroBuscado);
            if (personaEncontrada.GetRegistro() == registroBuscado) {
                cout << "Usuario encontrado: " << endl;
                cout << "Nombre: " << personaEncontrada.GetNombre() << endl;
                cout << "Apellido: " << personaEncontrada.GetApellido() << endl;
                cout << "Fecha de nacimiento: " << personaEncontrada.GetNac() << endl;
                cout << "Registro: " << personaEncontrada.GetRegistro() << endl;
                cout << endl;
                do {
                    cout << "-------MENU VER-------" << endl;
                    cout << "Que quieres ver de este nodo: " << endl;
                    cout << "[1] Padre\t [3] HijoIzquierdo" << endl;
                    cout << "[2] HijoDerecho\t [4] Salir" << endl;
                    cout << "--------------------------" << endl;
                    cin >> opMostrar;
                    switch (opMostrar) {
                    case 1:
                    {
                        cout << "Seleccionaste la opcion 1: Padre" << endl;
                        Persona personaEncontrada = arbol.GetPadre(registroBuscado);
                        if (personaEncontrada.GetRegistro() == 0)
                        {
                            cout << "El nodo no tiene padre:" << endl;
                            break;
                        }
                        cout << "Padre encontrado: " << endl;
                        cout << "Nombre: " << personaEncontrada.GetNombre() << endl;
                        cout << "Apellido: " << personaEncontrada.GetApellido() << endl;
                        cout << "Fecha de nacimiento: " << personaEncontrada.GetNac() << endl;
                        cout << "Registro: " << personaEncontrada.GetRegistro() << endl;
                        cout << endl;
                        break;
                    }
                    case 2:
                    {
                        cout << "Seleccionaste la opcion 2: Hijo Izquierdo" << endl;
                        Persona personaEncontrada = arbol.GetHijoIzq(registroBuscado);
                        if (personaEncontrada.GetRegistro() == 0)
                        {
                            cout << "El nodo no hijo izquierdo:" << endl;
                            break;
                        }
                        cout << "Hijo izquierdo encontrado: " << endl;
                        cout << "Nombre: " << personaEncontrada.GetNombre() << endl;
                        cout << "Apellido: " << personaEncontrada.GetApellido() << endl;
                        cout << "Fecha de nacimiento: " << personaEncontrada.GetNac() << endl;
                        cout << "Registro: " << personaEncontrada.GetRegistro() << endl;
                        cout << endl;
                        break;
                    }
                    case 3:
                    {
                        cout << "Seleccionaste la opcion 3: Hijo Derecho" << endl;
                        Persona personaEncontrada = arbol.GetHijoDer(registroBuscado);
                        if (personaEncontrada.GetRegistro() == 0)
                        {
                            cout << "El nodo no tiene hijo derecho:" << endl;
                            break;
                        }
                        cout << "Hijo derecho encontrado: " << endl;
                        cout << "Nombre: " << personaEncontrada.GetNombre() << endl;
                        cout << "Apellido: " << personaEncontrada.GetApellido() << endl;
                        cout << "Fecha de nacimiento: " << personaEncontrada.GetNac() << endl;
                        cout << "Registro: " << personaEncontrada.GetRegistro() << endl;
                        cout << endl;
                        break;
                    }
                    case 4:
                    {
                        cout << "Seleccionaste la opcion 4: Saliendo del menu" << endl;
                        cout << "saliendo del MENU VER.\n" << endl;
                        break;
                    }
                    default:
                        cout << "Opcion no valida." << endl;
                        break;
                    }
                    cout << endl;
                } while (opMostrar != 4);
                break;
            }
            else {
                cout << "Registro no encontrado." << endl;
            }
            cout << endl;
            break;
        }
        case 0:
        {
            cout << "Seleccionaste la opcion 0: SALIR" << endl;
            cout << "Saliendo del programa ";
            break;
        }
        default:
        {
            cout << "Opcion no valida." << endl;
            cout << endl;
            break;
        }
        }
    } while (op != 0);
    return 0;
}
