#include<iostream> //Libreria para oprecaiones de entrada y salida
#include<stdlib.h> //Libreria de memoria dinamica
#include <fstream> //Libreria de ficheros
#include <cstdlib> //
#include <String.h> //Libreria de operaciones de manipulacion de memoria

//Pra facilitar nuestros flujos de entrada y salida sin necesidad de estar poniendo std::cout std::cin
using namespace std;

//Declaracion de la estructura, para la clase A
typedef struct TrabajoNino
{
	string nombre;
	string tipo;
	string remuneracion;
}T; //Variable T que incluye los campos de la estructura TrabajoNino (nombre, tipo, remuneracion)

//Delcaracion de la estructura, para la clase B
typedef struct AntecedenteCriminales
{
	string delito;
	int reincidencias;
	string juzgado;
}A; //Variable A que incluye los campos de la estructura AntecedenteCriminales (delito, reincidencias, juzgado)

//Clase base A
class Persona
{
	//Estos atibutos pueden ser modificados por su propia clase o por las que heredan
	protected:
		string genero;
		string nacionalidad;
		string tes;
		string ojos;
		T trabajo;
		
	//Constructor por default
	public: Persona()
	{
		this->genero=" ";
		this->nacionalidad=" ";
		this->tes=" ";
		this->ojos=" ";
		this->trabajo.nombre=" ";
		this->trabajo.tipo=" ";
		this->trabajo.remuneracion==" ";
	}
	
	//Metodo set
	void setGenero(string gen) {this->genero=gen;}
	void setNacionalidad(string nac) {this->nacionalidad=nac;}
	void setTes(string te) {this->tes=te;}
	void setOjos(string ojo) {this->ojos=ojo;}
	void setTrabajoNombre(string trn) {this->trabajo.nombre=trn;}
	void setTrabajoTipo(string trt) {this->trabajo.tipo=trt;}
	void setTrabajoRemuneracion(string trr) {this->trabajo.remuneracion=trr;}
	
	//Metodo get
	string getGenero() {return this->genero;}
	string getNacionalidad() {return this->nacionalidad;}
	string getTes() {return this->tes;}
	string getOjos() {return this->ojos;}
	string getTrabajoNombre() {return this->trabajo.nombre;}
	string getTrabajoTipo() {return this->trabajo.tipo;}
	string getTrabajoRemuneracion() {return this->trabajo.remuneracion;}
};

//Calse base B
class Criminal
{
	//Estos atibutos pueden ser modificados por su propia clase o por las que heredan
	protected:
		string tipo;
		string crimen;
		string capturado;
		int victimas;
		A antecedentes;
		
	//Constructores por default
	public: Criminal()
	{
		this->tipo=" ";
		this->crimen=" ";
		this->capturado=" ";
		this->victimas= 0;
		this->antecedentes.delito=" ";
		this->antecedentes.reincidencias= 0;
		this->antecedentes.juzgado=" ";
	}
	
	//Metodo set
	public: void setTipo(string tip) {this->tipo=tip;}
	void setCrimen(string cri) {this->crimen=cri;}
	void setCapturado(string cap) {this->capturado=cap;}
	void setVictimas(int vic) {this->victimas=vic;}
	void setAntecedeDelito(string del) {this->antecedentes.delito=del;}
	void setAntecedeReincide(int rei) {this->antecedentes.reincidencias=rei;}
	void setAntecedeJuzgado(string juz) {this->antecedentes.juzgado=juz;}
	
	//Metodo get
	string getTipo() {return this->tipo;}
	string getCrimen() {return this->crimen;}
	string getCapturado() {return this->capturado;}
	int getVictimas() {return this->victimas;}
	string getAntecedeDelito() {return this->antecedentes.delito;}
	int getAntecedeReincide() {return this->antecedentes.reincidencias;}
	string getAntecedeJuzgado() {return this->antecedentes.juzgado;}
};

//Clase heredada A
class Nino: public Persona //El public me permite acceder a todo el apartado public de la clase madre
{
	//Atributos
	private:
		int edad;
		string expediente;
		string padres;
		
	//Constructor por default
	public: Nino(): Persona()
	{
		this->edad= 0;
		this->expediente=" ";
		this->padres=" ";
	}
	
	//Metodo set
	void setEdad(int ed) {this->edad=ed;}
	void setExpediente(string ex) {this->expediente=ex;}
	void setPadres(string pa) {this->padres=pa;}
	
	//Metodo get
	int getEdad() {return this->edad;}
	string getExpediente() {return this->expediente;}
	string getPadres() {return this->padres;}
};

//Clase heredada B
class Sacerdote: public Criminal //El public me permite acceder a todo el apartado public de la clase madre
{
	//Atributos
	private: 
		string religion;
		string iglesia;
		string nombre;
		bool asoci;
		
	//Objeto para establecer la asociacion
	public: Nino *nin;
		
	//Constructor por default
	public: Sacerdote(): Criminal()
	{
		this->religion=" ";
		this->iglesia=" ";
		this->nombre=" ";
		this->nin=new Nino();
		this->asoci = false;
	}
	
	//Metodo set
	void setReligion(string re) {this->religion=re;}
	void setIglesia(string ig) {this->iglesia=ig;}
	void setNombre(string na) {this->nombre=na;}
	void setAsoci(bool as) {this->asoci=as;}
	void abusa(Nino *nin) {this->nin=nin;}
	void mostrarDatos()
	{
		cout<<"Expediente: "<<nin->getExpediente()<<endl;
		cout<<"Edad: "<<nin->getEdad()<<endl;
		cout<<"Padres: "<<nin->getPadres()<<endl;
	}

	
	//Metodo get
	string getReligion() {return this->religion;}
	string getIglesia() {return this->iglesia;}
	string getNombre() {return this->nombre;}
	bool getAsoci(){return this->asoci;}
};

//Declaracion de funciones a las que accederemos desde nuestra funcion principal
void agregarNino(Nino *p[], int &cont1);
void agregarSacerdote(Sacerdote *c[], int &cont2);
void imprimirNino(Nino *p[], int &cont1);
void imprimirSacerdote(Sacerdote *c[], int &cont2);
void buscarNino(Nino *p[], int &cont1);
void buscaSacerdote(Sacerdote *c[], int &cont2);
void eliminarNino(Nino *p[], int &cont1);
void eliminarSacerdote(Sacerdote *c[], int &cont2);
void asociar(Nino *p[], Sacerdote *c[], int &cont1,  int &cont2);

//Nuestra funcion principal
int main(int argc, char** argv) 
{
	int op=0, op2=0, op3=0, op4=0, cont1=0, cont2=0;
	ofstream archivoOut("datos.dat",ios::out);
	ifstream archivoIn("datos.dat",ios::in);
	
	//Creacion de instancias
	Nino *p[100];
	Sacerdote *c[100];
	
	//Creamos nuestro slogan de bienvenida  las \n son para los saltos de linea y las \t nos sirven para dar espacios en lineas
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\tLOS NOMBRES DE LAS VICTIMAS FUERON OMITIDOS \n";
	cout<<"\t\t\t\tPOR CAUSA DE SEGURIDAD Y PRIVACIDAD, \n";
	cout<<"\t\t\t\tEL CONTENIDO QUE VERA A CONTINUACION ES \n";
	cout<<"\t\t\t\tEXTREMADAMENTE FUERTE SE RECOMIENDA DISCRECION\n\n\n\n\n\n\n";
	
	//Para detenere nuestro programa y que no siga corriendo hasta que se lo indiquemos
	system("pause");
	
	//Creacion de nuestro menu principal en el que escojeremos que expediente queremos revisar, si el de los sacerdotes o el de los niños
	do
	{
		system("cls");//Para borrar la pantalla
		
		//Contenido de nuestro menu principal
		cout<<"\nREGISTRO CRIMINAL DE LIDERES RELIGIOSOS"<<endl;
		cout<<"1. Registro de las victimas"<<endl;
		cout<<"2. Registro de los agresores"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Que quieres hacer: ";
		cin>>op;
		
		//Creacion de nuestro menu secundario ya sea la seccion de niños o sacerdotes, depende del numero que hayamos ingresado en nuestro menu principal
		switch(op)
		{
			//Menu para llamar a las funcionees de los niños
			case 1: //Opcion 1 de nuestro menu principal
				
				system("cls");//Para borrar la pantalla
				//Opciones de nuestro menu secundario, apartdao de niños
				cout<<"1. Agregar"<<endl;
				cout<<"2. Imprimir"<<endl;
				cout<<"3. Buscar"<<endl;
				cout<<"4. Eliminar"<<endl;
				cout<<"5. Salir"<<endl;
				cout<<"Que quieres hacer: ";
				cin>>op2;
				
				//Ingreso a nuestras funciones para niños
				switch(op2)
				{
					//LLamar mandar a nuestra funcion de agregar a un niño
					case 1:
						system("cls");
						agregarNino(p, cont1);
						break;
					//LLamar mandar a nuestra funcion de imprimir a todos los niños registrados
					case 2:
						system("cls");
						imprimirNino(p, cont1);
						break;
					//LLamar mandar a nuestra funcion de buscar a un niño
					case 3:
						system("cls");
						buscarNino(p, cont1);
						break;
					//LLamar mandar a nuestra funcion de eliminar a un niño
					case 4:
						system("cls");
						eliminarNino(p, cont1);
					//Nos indica que cualquier otro numero que ingresemos diferentes a los que establecimos (1, 2, 3, 4) nos regresara a nuestro menu principal
					default:
						break;
				}
				break;
				
			//Menu para llamar a las funciones de los sacerdotes
			case 2: //Opcion 2 de nuestro menu principal
				
				system("cls");//Para borrar la pantalla
				//Opciones de nuestro menu secundario, apartdao de sacerdotes
				cout<<"1. Agregar"<<endl;
				cout<<"2. Imprimir"<<endl;
				cout<<"3. Buscar"<<endl;
				cout<<"4. Eliminar"<<endl;
				cout<<"5. Asociar"<<endl;
				cout<<"6. Salir"<<endl;
				cout<<"Que quieres hacer: ";
				cin>>op3;
				
				//Ingresoa a nuestras funciones para sacerdotes
				switch(op3)
				{
					//LLamar mandar a nuestra funcion de agregar a un sacerdote
					case 1:
						system("cls");
						agregarSacerdote(c, cont2);
						break;
					//LLamar mandar a nuestra funcion de imprimir a todos los sacerdotes registrados
					case 2:
						system("cls");
						imprimirSacerdote(c, cont2);
						break;
					//LLamar mandar a nuestra funcion de buscar a un sacerdote
					case 3:
						system("cls");
						buscaSacerdote(c, cont2);
						break;
					//LLamar mandar a nuestra funcion de eliminar a un sacerdote
					case 4:
						system("cls");
						eliminarSacerdote(c, cont2);
						break;
					//LLamar mandar a nuestra funcion de asociacion
					case 5:
						asociar(p, c, cont1,  cont2);
						break;
					//Nos indica que cualquier otro numero que ingresemos diferentes a los que establecimos (1, 2, 3, 4, 5) nos regresara a nuestro menu principal
					default:
						break;
				}
				break;
			//Este default nos indica que si no es una de las opciones dadas (1, 2, 3) el programa dberia de finalizar, pero para eso tenemos el while de anajo
			default:
			break;
		}
	}
	while(op!=3); //Nos indica que si ingresamos el 3 nuestro programa finalizara, impide que se ingrese otro numero, ya que si se ingresa un numero diferente a las opciones (1, 2, 3) el programa nos seguira mostrando el menu principal
	
	return 0; //Para indicarle al programa que todo a finalizado correctamente
}


//Funcion para agregar a un niño, entramos en ella desde nuestra funcion principal
void agregarNino(Nino *p[], int &cont1)
{
	system("cls"); //Para borrar pantalla
	
	//Abrir la cadena (p) con el contador (cont1) para acceder a los atributos de la clase heredada niño y a su clase madre persona
	p[cont1]=new Nino();
	
	//Condicionante para ir aumentando el contador hasta un maximo de 100
	if(cont1==99) //Si nuestro contador llega a 99 osea 100 elementos deja de ingresar mas
	{
		cout<<"Ya no tienes espacio";
	}
	else
	{
		//Declaramos variables locales
		string gen, nac, te, ojo, trn, trt, trr, ex, pa;
		int ed;
		
		//Pedimos e ingresamos datos
		cout<<"Genero: ";
		fflush(stdin); //Limpiamos el buffer para no tener errores entre las cadenas y los enteros o caracteres
		getline(cin, gen, '\n'); //Guardar caracteres con espacio ("Casa azul")
		
		cout<<"Nacionalidad: ";
		fflush(stdin); //Limpiamos el buffer para no tener errores entre las cadenas y los enteros o caracteres
		getline(cin, nac, '\n'); //Guardar caracteres con espacio
		
		cout<<"Tes de piel: ";
		fflush(stdin); //Limpiamos el buffer para no tener errores entre las cadenas y los enteros o caracteres
		getline(cin, te, '\n'); //Guardar caracteres con espacio
		
		cout<<"Color de ojos: ";
		fflush(stdin); //Limpiamos el buffer para no tener errores entre las cadenas y los enteros o caracteres
		getline(cin, ojo, '\n'); //Guardar caracteres con espacio
		
		cout<<"Trabajo: ";
		fflush(stdin); //Limpiamos el buffer para no tener errores entre las cadenas y los enteros o caracteres
		getline(cin, trn, '\n'); //Guardar caracteres con espacio
		
		cout<<"Tipo de trabajo: ";
		fflush(stdin); //Limpiamos el buffer para no tener errores entre las cadenas y los enteros o caracteres
		getline(cin, trt, '\n'); //Guardar caracteres con espacio
		
		cout<<"Tipo de remuneracion: ";
		fflush(stdin); //Limpiamos el buffer para no tener errores entre las cadenas y los enteros o caracteres
		getline(cin, trr, '\n'); //Guardar caracteres con espacio
		
		cout<<"Edad: ";
		fflush(stdin); //Limpiamos el buffer para no tener errores entre las cadenas y los enteros o caracteres
		cin>>ed;
		
		cout<<"Expediente: ";
		fflush(stdin); //Limpiamos el buffer para no tener errores entre las cadenas y los enteros o caracteres
		getline(cin, ex, '\n'); //Guardar caracteres con espacio
		
		cout<<"Padres: ";
		fflush(stdin); //Limpiamos el buffer para no tener errores entre las cadenas y los enteros o caracteres
		getline(cin, pa, '\n'); //Guardar caracteres con espacio
		
		//Guardamos los datos que solicitamos en los atributos de nuestra clase
		p[cont1]->setGenero(gen);
		p[cont1]->setNacionalidad(nac);
		p[cont1]->setTes(te);
		p[cont1]->setOjos(ojo);
		p[cont1]->setTrabajoNombre(trn);
		p[cont1]->setTrabajoTipo(trt);
		p[cont1]->setTrabajoRemuneracion(trr);
		p[cont1]->setEdad(ed);
		p[cont1]->setExpediente(ex);
		p[cont1]->setPadres(pa);
		cont1 += 1; //Aumentamos nuestro contador
	}
}

//Funcion para registarar un sacerdote, entramos en ella desde nuestra funcion principal
void agregarSacerdote(Sacerdote *c[], int &cont2)
{
	system("cls");//Para borrar pantalla
	
	//Abrir la cadena (c) con el contador (cont2) para acceder a los atributos de la clase heredada sacerdote y a su clase madre criminal
	c[cont2]=new Sacerdote();
	
	//Condicionante para ir aumentando el contador hasta un maximo de 100
	if(cont2==99) //Si nuestro contador llega a 99 osea 100 elementos deja de ingresar mas
	{
		cout<<"Ya no tienes espacio";
	}
	else
	{
		//Declaramos variables locales
		string tip, cri, cap, del, juz, re, ig, na;
		int vic, rei;
		
		//Pedimos e ingresamos datos
		cout<<"Tipo de crimen: ";
		fflush(stdin); //Limpiamos el buffer para no tener errores entre las cadenas y los enteros o caracteres
		getline(cin, tip, '\n'); //Guardar caracteres con espacio ("Casa azul")
		
		cout<<"Crimen: ";
		fflush(stdin);
		getline(cin, cri, '\n');
		
		cout<<"Capturado: ";
		fflush(stdin);
		getline(cin, cap, '\n');
		
		cout<<"Victimas: ";
		fflush(stdin);
		cin>>vic;
		
		cout<<"Antecedente: ";
		fflush(stdin);
		getline(cin, del, '\n');
		
		cout<<"Reincidencias: ";
		fflush(stdin);
		cin>>rei;
		
		cout<<"A sido juzgado: ";
		fflush(stdin);
		getline(cin, juz, '\n');
		
		cout<<"Religion: ";
		fflush(stdin);
		getline(cin, re, '\n');
		
		cout<<"Iglesia: ";
		fflush(stdin);
		getline(cin, ig, '\n');
		
		cout<<"Nombre: ";
		fflush(stdin);
		getline(cin, na, '\n');
		
		//Guardamos los datos que solicitamos en los atributos de nuestra clase
		c[cont2]->setTipo(tip);
		c[cont2]->setCrimen(cri);
		c[cont2]->setCapturado(cap);
		c[cont2]->setVictimas(vic);
		c[cont2]->setAntecedeDelito(del);
		c[cont2]->setAntecedeReincide(rei);
		c[cont2]->setAntecedeJuzgado(juz);
		c[cont2]->setReligion(re);
		c[cont2]->setIglesia(ig);
		c[cont2]->setNombre(na);
		cont2 += 1;//Aumentamos nuestro contador
	}
}

//Funcion para imprimir a todos los niños que tenemos registrados, entramos en ella desde nuestra funcion principal
void imprimirNino(Nino *p[], int &cont1)
{
	//Ciclo para mostrar todos los atributos de todos los niños
	for(int i=0; i<cont1; i++) //Iniciamos en 0 hasta el numero maximo de niños
	{
		cout<<endl;
		cout<<"Genero: "<<p[i]->getGenero()<<endl;
		cout<<"Nacionalidad: "<<p[i]->getNacionalidad()<<endl;
		cout<<"Tes de piel: "<<p[i]->getTes()<<endl;
		cout<<"Color de ojos: "<<p[i]->getOjos()<<endl;
		cout<<"Trabajo: "<<p[i]->getTrabajoNombre()<<endl;
		cout<<"Tipo de trabajo: "<<p[i]->getTrabajoTipo()<<endl;
		cout<<"tipo de remuneracion: "<<p[i]->getTrabajoRemuneracion()<<endl;
		cout<<"Edad: "<<p[i]->getEdad()<<endl;
		cout<<"Expediente: "<<p[i]->getExpediente()<<endl;
		cout<<"Padres: "<<p[i]->getPadres()<<endl;
	}
	system("pause");
}

//Funcion para imprimir a todos los sacerdotes que tenemos registrados, entramos en ella desde nuestra funcion principal
void imprimirSacerdote(Sacerdote *c[], int &cont2)
{
	//Ciclo para mostrar tosod los atributos de todos los sacerdotes
	for(int i=0; i<cont2; i++) //Iniciamos en 0 hasta el numero maximo de sacerdotes
	{
		cout<<endl;
		cout<<"Tipo de crimen: "<<c[i]->getTipo()<<endl;
		cout<<"Crimen: "<<c[i]->getCrimen()<<endl;
		cout<<"Capturado: "<<c[i]->getCapturado()<<endl;
		cout<<"Victimas: "<<c[i]->getVictimas()<<endl;
		cout<<"Antecedente: "<<c[i]->getAntecedeDelito()<<endl;
		cout<<"Reincidencias: "<<c[i]->getAntecedeReincide()<<endl;
		cout<<"A sido juzgado: "<<c[i]->getAntecedeJuzgado()<<endl;
		cout<<"Religion: "<<c[i]->getReligion()<<endl;
		cout<<"Iglesia: "<<c[i]->getIglesia()<<endl;
		cout<<"Nombre: "<<c[i]->getNombre()<<endl;
		
		if(c[i]->getAsoci()){//Valida la asociacion
			//Mostramos la asociacion
			cout<<"### VICTIMA ###"<<endl;
			c[i]->mostrarDatos(); //LLamamos los datos de los niños por nuestra funcion mostrar que se encuentra dentro de nuestra clse sacerdote (expediente, edad, padres)
			cout<<endl;
		}
	}
	system("pause");
}

//Funcion para buscar a un niño, entramos en ella desde nuestra funcion principal
void buscarNino(Nino *p[], int &cont1)
{
	system("cls");//Para borrar pantalla
	string expe; //Declaramos variables locales
	cout<<"Que expediente quieres buscar: ";
	fflush(stdin); //Limpiamos el buffer
	getline(cin, expe, '\n'); //Captura de cadena de caracteres
	
	bool existe=false; //Declaracion de variable tipo booleano
	
	//Ciclo para comoprobar el valor ingresado
	for(int i=0; i<cont1; i++)
	{
		//Si el expediente existe nos muestra sus atributos
		if(p[i]->getExpediente()==expe)
		{
			existe=true;
			cout<<endl;
			cout<<"Expediente: "<<p[i]->getExpediente()<<endl;
			cout<<"Genero: "<<p[i]->getGenero()<<endl;
			cout<<"Nacionalidad: "<<p[i]->getNacionalidad()<<endl;
			cout<<"Tes de piel: "<<p[i]->getTes()<<endl;
			cout<<"Color de ojos: "<<p[i]->getOjos()<<endl;
			cout<<"Trabajo: "<<p[i]->getTrabajoNombre()<<endl;
			cout<<"Tipo de trabajo: "<<p[i]->getTrabajoTipo()<<endl;
			cout<<"tipo de remuneracion: "<<p[i]->getTrabajoRemuneracion()<<endl;
			cout<<"Edad: "<<p[i]->getEdad()<<endl;
			cout<<"Padres: "<<p[i]->getPadres()<<endl;
		
			break;
		}
	}
	
	//Si el expediente no existe
	if(!existe)
	{
		cout<<endl;
		cout<<"No tenemos registros de este expediente"<<endl;
		cout<<endl;
	}
	
	system("pause");
}

//Funcion para buscar un sacerdote, entramos en ella desde nuestra funcion principal
void buscaSacerdote(Sacerdote *c[], int &cont2)

{
	system("cls");//Para borrar pantalla
	string sacer; //Declaramos variables locales
	cout<<"Que sacerdote quieres buscar: ";
	fflush(stdin);
	getline(cin, sacer, '\n');
	
	bool existe=false; //Declaramos variable de tipo booleano
	//Ciclo para comoprobar el valor ingresado
	for(int i=0; i<cont2; i++)
	{
		//Si el expediente existe nos muestra sus atributos
		if(c[i]->getNombre()==sacer)
		{
			existe=true;
			cout<<endl;
			cout<<"Nombre: "<<c[i]->getNombre()<<endl;
			cout<<"Tipo de crimen: "<<c[i]->getTipo()<<endl;
			cout<<"Crimen: "<<c[i]->getCrimen()<<endl;
			cout<<"Capturado: "<<c[i]->getCapturado()<<endl;
			cout<<"Victimas: "<<c[i]->getVictimas()<<endl;
			cout<<"Antecedente: "<<c[i]->getAntecedeDelito()<<endl;
			cout<<"Reincidencias: "<<c[i]->getAntecedeReincide()<<endl;
			cout<<"A sido juzgado: "<<c[i]->getAntecedeJuzgado()<<endl;
			cout<<"Religion: "<<c[i]->getReligion()<<endl;
			cout<<"Iglesia: "<<c[i]->getIglesia()<<endl;
		
			if(c[i]->getAsoci()){//Valida la asociacion
				//Mostramos la asociacion
				cout<<"### VICTIMA ###"<<endl;
				c[i]->mostrarDatos(); //LLamamos los datos de los niños por nuestra funcion mostrar que se encuentra dentro de nuestra clse sacerdote (expediente, edad, padres)
				cout<<endl;
			}
		}
	}
	
	//Si el expediente no existe
	if(!existe)
	{
		cout<<endl;
		cout<<"No tenemos registros de este expediente"<<endl;
		cout<<endl;
	}
	
	system("pause");
}

//Funcion para asociar un sacerdote con un niño, entramos en ella desde nuestra funcion principal
void asociar(Nino *p[], Sacerdote *c[], int &cont1,  int &cont2)
{
	string pedobear, aunqueseadepollo; //Declaramos variables locales
	bool ped=false, aunq=false; //Declaramos variable de tipo booleano
	system("cls");
	
	cout<<"ASOCIACION"<<endl;
	cout<<"Que sacerdote esta siendo culpado: ";
	fflush(stdin);
	getline(cin, pedobear, '\n');
	
	//Ciclo para realizar la asociacion
	for(int i=0; i<cont2; i++) //Busca el sacerdote
	{
		//Comprobar si el sacerdote esta registrado
		if(c[i]->getNombre()==pedobear)
		{
			ped=true; //Indica que el sacerdote si esta registrado
			cout<<"A que expediente de victima quieres agregarlo: ";
			fflush(stdin);
			getline(cin, aunqueseadepollo, '\n');
			
			//Ciclo para buscar el expediente
			for(int j=0; j<cont1; j++)
			{
				//Comprobar si el expediente esta registrado
				if(p[j]->getExpediente()==aunqueseadepollo)
				{
					aunq=true; //Indica que el expediente si esta registrado
					c[i]->abusa(p[j]); //Asociamos, el sacerdote ingresado apunta al expediente ingresado
					cout<<"Asociacion realizada con exito"<<endl;
					c[i]->setAsoci(true);
					break;
				}
			}
			break;
		}
	}
	
	//Si el sacerdote no esta registrado
	if(!ped) 
		cout<<"El sacerdote que desea asociar no se encuentra registrado"<<endl;
	
	//Si el sacerdote esta registrado
	else 
		if(!aunq) //Si el expediente no esta registrado
			cout<<"El expediente que desea asociar no se encuentra registrado"<<endl;	
		
	system("pause");
}

//Funcion eliminar un niño, entramos en ella desde nuestra funcion principal
void eliminarNino(Nino *p[], int &cont1)
{
	string x;
	cout<<"Ingresa el expediente de la victima, que deseas eliminar: ";
	cin>>x;
	
	//Buscamos el expediente
	for(int i=0; i<cont1; i++)
	{
		//El expediente que ingresamos (x) lo compara con los que tenemos
		if(p[i]->getExpediente()==x) //Si esiste
		{
			for(int j=i; j<cont1; j++) //Lo borra
			{
				p[j]=p[j+1];
			}
			cont1--; //Reduce nuestro contador una vez
		}
	}
}

//Funcion para eliminar a un sacerdote, entramos en ella desde nuestra funcion principal
void eliminarSacerdote(Sacerdote *c[], int &cont2)
{
	string x;
	cout<<"Ingresa el Nombre del Sacerdote que quieres elminar: ";
	cin>>x;
	
	//Buscamosa el sacerdote
	for(int i=0; i<cont2; i++)
	{
		//El nombre que ingresamos (x) lo compara con los que tenemos
		if(c[i]->getNombre()==x) //Si existe
		{
			for(int j=i; j<cont2; j++) //Lo borra
			{
				c[j]=c[j+1];
			}
			cont2--; //Reduce nuestro contador una vez
		}
	}
}
