#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Libro.h"
#include "Evaluador.h"
#include "NodoBinario.h"

using namespace std;

//Escribe todos los datos del libro en un archivo con nombre nombre_archivo en la posicion dada
void escribir(string nombre_archivo, Libro*libro, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in);
    if(!out.is_open())
    {
        out.open(nombre_archivo.c_str());
    }
    out.seekp(posicion*61);
    out.write((char*)libro->nombre.c_str(),30);
    out.write((char*)libro->autor.c_str(),30);
    out.write((char*)&libro->existencias,1);
    out.close();
}

//Devuelve el libro guardado en el archivo en la posicion dada
Libro* leer(string nombre_archivo, int posicion)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion*61);

    char nombre[30];
    char autor[30];
    int existencias;
    in.read(nombre,30);
    in.read(autor,30);
    in.read((char*)&existencias,1);
    Libro *libro = new Libro(nombre,autor,existencias);
    return libro;

}

//Crea un mapa en base a las llaves y valores dados, asocia cada llave con los valores en la misma posicion
map<string, int> convertirEnMapa(set<string> llaves, set<int> valores)
{
    map<string, int> res;
    set<string>::iterator a = llaves.begin();
    set<int>::iterator b =  valores.begin();
    while(a!=llaves.end()){
        res[*a] = *b;
        b++;
        a++;
    }
    return res;
}

//Devuelve una cola con los mismos valores que el parametro exepto que no tiene el ultimo valor
queue<int> popBack(queue<int> cola)
{
    queue<int> res;
    stack<int> resT;
    stack<int> temporal;
    int agregar,contador;
    while(!cola.empty())
    {
        agregar = cola.front();
        temporal.push(agregar);
        cola.pop();
    }
    temporal.pop();
    while(!temporal.empty())
    {
        agregar = temporal.top();
        resT.push(agregar);
        temporal.pop();
    }
    while(!resT.empty())
    {
        agregar = resT.top();
        res.push(agregar);
        resT.pop();
    }
    return res;
}

//Reemplaza todos los valores del arbol
void reemplazarValores(NodoBinario* raiz, int valor)
{
    if (raiz==NULL){
        return;
    }
    if(raiz->valor = valor){
    }
    reemplazarValores(raiz->derecho,valor);
    reemplazarValores(raiz->izquierdo,valor);
}

//Devuelve la cantidad de bits "encendidos" o con el valores de 1
int contarBits(char byte)
{

    return -1;

}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
