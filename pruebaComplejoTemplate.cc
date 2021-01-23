/*
 * pruebaComplejoTemplate.cc
 *
 *  Created on:
 *      Author: Jesús López
 */
#include "ComplejoTemplate.h"

int main( int argc, char **argv )
{
	Complejo<float> c1(2,3);
	Complejo<float> c2(c1);
	Complejo<float> c3;
	Complejo<float>	c4;

	//Operadores << y >>
	//Archivos
	std::ifstream ifs("archivo_lectura.txt");
	std::ofstream ofs("archivo_escritura.txt");

	if( !ifs )cout << "Error al abrir archivo de lectura" << endl;
	ifs >> c3;

	if( !ofs )cout << "Error al abrir archivo de escritura" << endl;
	ofs << c3;

	//Por teclado
	try
	{
		cout << "Ingresar c3:" << endl;
		cin >> c3;

	}
	catch( int e )
	{
		std::cout << "Error Formato de entrada, sale ordenadamente\n";
		return 1;
	}

	cout << c3;

	//Operadores aritméticos
	cout << "c1 + c2 = " << c1 + c2 << endl ;
	cout << "c1 - c2 = " << c1 - c2 << endl ;
	cout << "c1 * c2 = " << c1 * c2 << endl ;


	//c2.SetData(c4);
	try
	{
		cout << "c1 / c2 = " << c1/c2 << endl ;

	}
	catch( int e )
	{
		std::cout << "Evita division por cero, sale ordenadamente\n";
		return 1;
	}

	//Operadores aritméticos con asignación
	c4 = c1;

	c4 += c2;
	cout << "c1 += c2 = " << c4 << endl ;
	c4 -= c2;
	cout << "c1 -= c2 = " << c4 << endl ;
	c4 *= c2;
	cout << "c1 *= c2 = " << c4 << endl ;

	//c2.SetRealImag(0,0);
	try
	{
		c4 /= c2;
		cout << "c1 /= c2 = " << c4 << endl ;

	}
	catch( int e )
	{
		std::cout << "Evita division por cero, sale ordenadamente\n";
		return 1;
	}

	//Operadores de comparación
	if(c1 == c4){
		cout << "c1 = c4" << endl ;
	}

	if(c3 > c1){
		cout << "c3 > c1" << endl ;
	}

	if(c1 < c3){
		cout << "c1 < c3" << endl ;
	}

	if(c1 != c3){
		cout << "c1 != c3" << endl ;
	}

	//Operaciones con constantes y otras

	c1.conj();
	cout << "El conjugado de c1 es: " << c1 << endl;

	c1.conj();
	cout << "c1 + 5 = " << c1+5.0 << endl ;
	cout << "c1 - 5 = " << c1-5.0 << endl ;
	cout << "c1 * 3 = " << c1*3.0 << endl ;
	cout << "c1 / 3  = " << c1/3 << endl ;

	c1.SetRealImag(4,4);
	cout << "Usando c1.SetRealImag(4,4)  " << c1 << endl ;

	c2.SetModFase(2,60);
	cout << "Usando c2.SetModFase(2,60)  " << c2 << endl ;

	c3.SetReal(4);
	c3.SetImag(4);

	cout << "\nUsando c3.SetReal y c3.SetImag ->  " << c3 << endl ;

	if(c3 >= c1){
		cout << "c3 >= c1" << endl ;
	}

	c4.SetMod(2);
	c4.SetFase(60);

	cout << "\nUsando c4.SetMod y c3.SetFase ->  " << c4 << endl ;

	if(c4 <= c2){
		cout << "c4 <= c2" << endl ;
	}

	c1 += 3;
	cout << "c1 += 3 = " << c1 << endl ;
	c1 -= 3;
	cout << "c1 - 3 = " << c1 << endl ;
	c1 *= 3;
	cout << "c1 * 3 = " << c1 << endl ;
	c1 /= 3;
	cout << "c1 / 3  = " << c1 << endl ;


	try
	{

		cout << "c1 / 0  = " << c1/0 << endl ;

	}
	catch( int e )
	{
		std::cout << "Evita division por cero, sale ordenadamente\n";
		return 1;
	}


	return 0;
}


