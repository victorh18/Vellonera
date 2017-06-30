/**
 * Este es el programa de vellonera para la tarea  5 de Raydelto
 * Victor de la Rosa, 2015-2747
 */
 
 #include <iostream>
 #include <fstream>
 #include <string>
 #include <cstdlib>
 #include <stdio.h>
 #include <stdlib.h>
 
 using namespace std;
 //Estructura que representara la entidad de cancion
 struct cancion{
	cancion* anterior;
	cancion* siguiente;
	string titulo;
	string artista;
	string duracion;
 };
 
cancion * primeraCancion;
cancion * ultimaCancion;
cancion * cancionActual;
//Estas variables me van a mantener el registro de la primera y ultima cancion sin que se manipulen
cancion * primeraPrimera;
cancion * ultimaUltima; 

//Funcion que agrega canciones al sistema
void agregar(cancion* _cancion){
	//Inicializo los parametros para evitar explosiones
	_cancion -> anterior = NULL;
	_cancion -> siguiente = NULL;
	if (primeraCancion == NULL){
		primeraCancion = _cancion;
		ultimaCancion = _cancion;
	} else {
		_cancion -> anterior = ultimaCancion;
		cancionActual -> siguiente = _cancion;
		ultimaCancion = _cancion;
	}
	
}

//Me despliega las canciones de forma FIFO
cancion* extraerAsc(){
	//Si no existen canciones, o se recorrieron todas, que no me deuelva nada
	if (primeraCancion == NULL){
		return NULL;
	}
	/*Declaro otro puntero que apunte a la primera, de manera que tener dos punteros que apunten
	a la primera cancion y se me haga mas facil recorrer*/
	cancion* retorno = primeraCancion;
	/*Declaro que ahora la primera cancion es la siguiente, de manera de uqe cuando vuelvo a
	 * invocar el metodo, me considere la segunda funcion*/
	primeraCancion = retorno -> siguiente;
	/*Realizo esta asignacion en ambos metodos, de manera de que no importa el orden en que se 
	 * recorran las canciones, exista un estandar, en lugar de estar verificando entre la primera
	 * y la ultima*/
	cancionActual = retorno;
	/*Regreso la cancion que estaba identificada como la primera al invocar el metodo
	 * referenciada unicamente ahora por la variable temporal (vlr) retorno*/
	return retorno;
}

//me despliega las canciones de forma LIFO
cancion* extraerDesc(){
	//si no existen canciones y si se recorrieron todas que no me devuelva nada
	if(ultimaCancion == NULL){
		return NULL;
	}
	//declaro una variable temporal y le asigno la ultima cancion para facilitarme su manejo
	cancion* retorno = ultimaCancion;
	/*Declaro la cancion anterior a la ultima como la nueva ultima cancion a considerar cuando
	 * se termine la ejecucion del metodo*/
	ultimaCancion = retorno -> anterior;
	/*Realizo esta asignacion en ambos metodos, de manera de que no importa el orden en que se 
	 * recorran las canciones, exista un estandar, en lugar de estar verificando entre la primera
	 * y la ultima*/
	cancionActual = retorno;
	/*Devuelvo la cancion identificada como ultima al inicio del metodo*/
	return retorno;
	
}

//Este metodo me va a listar todas las canciones
void listarCanciones(){
	//Declaro la variable temporal que va a ser iterada y servira de contenedor para mostrar las canciones
	cancion * i;
	//Le asigno la primera cancion;
	i = extraerAsc();
	
	cout << "Vamos a mostrar las canciones" << endl;
	
	//Itero por las canciones y las muestro
	while(i != NULL){
		cout << i -> artista << ", " << i -> titulo << ", " << i -> duracion << endl;
		i = extraerAsc();
	}
	primeraCancion = primeraPrimera;
	cout << endl;
	
}

//Este metodo toma los parametros y realizar la insercion de la cancion en el sistema
void insertar(string _titulo, string _artista, string _duracion){

	//Iteracion de agregacion de canciones
	//Variable temporal que voy a utilizar para a;adir
	cancion lol;
	cancion * cancionTemporal = &lol; //(cancion *) malloc(sizeof(cancion));
	cout << "hola" << endl;
	//asigno los parametros a la cancion
	cancionTemporal->titulo = _titulo;
	cancionTemporal->artista = _artista;
	cancionTemporal->duracion = _duracion;
	
	agregar(cancionTemporal);
	
}
 
void leer(){
	//variable para controlar la iteracion de agregacion de variables
	string agregarOtro = "S";
	
	while(agregarOtro == "S"){
		
	}
	
}

int main() {
	
	//Variable para controlar la opcion del usuario
	int opcion = 0;
	//Itero las opciones
	while(opcion != 5){
		switch (opcion){
			case 1:
			{
				//variables temporales donde inicialmente ira a parar el input del usuario
				string tituloTemporal = "";
				string artistaTemporal = "";
				string duracionTemporal = "";
				
				//Introduccion del titulo
				cout << "Introduzca el titulo de la cancion" << endl;
				scanf(" %99[0-9a-zA-Z ]s", tituloTemporal);
				
				//Introduccion del artista
				cout << "Introduzca el artista de la cancion" << endl;
				scanf(" %99[0-9a-zA-Z ]s", artistaTemporal);
				
				//Introduccion de la duracion
				cout << "Introduzca la duracion de la cancion" << endl;
				scanf(" %99[0-9a-zA-Z ]s", duracionTemporal);
				
				
				//Agregamos la cancion a la estructura
				insertar(tituloTemporal, artistaTemporal, duracionTemporal);
				
				break;
				
			}
			case 2:
				listarCanciones();
				break;
			case 5:
				break;
			default:
				cout << "Opcion no valida" << endl;
		}
		//Opciones
		cout << "1 - Agregar nueva canción" << endl;
		cout << "2 - Visualizar canciones" << endl;
		cout << "3 - Mostrar cancion actual" << endl;
		cout << "5 - Salir del programa" << endl;
		cin >> opcion;
	}
	
	return 0;
 }