/*
 * ComplejoTemplate.h
 *
 *  Created on:
 *      Author: Jesús López
 */

#ifndef COMPLEJOTEMPLATE_H_
#define COMPLEJOTEMPLATE_H_

#include <iostream>
#include <cmath>
#include <fstream>
#include <list>
#include <sstream>
using namespace std;

enum{ ERROR_DIV_CERO , ERROR_FORMATO_DE_ENTRADA };

template <class T>
class Complejo
{
	private:
		T real;
		T imag;
		T modulo;
		T faseGrados;
		void Rect2Polar(Complejo<T>&);
		void Polar2Rect(Complejo<T>&);
	public:
		// Constructores
		Complejo(void);
		Complejo(const T&, const T& im=0.0);
		Complejo(const Complejo<T>&);

		// SetThings
		void SetData(const Complejo<T>& c);
		void SetRealImag(const T& re, const T& im);
		void SetModFase(const T& mod, const T& fase);
		void SetReal(const T&);
		void SetImag(const T&);
		void SetMod(const T&);
		void SetFase(const T&);

		// GetThings
		T GetReal(void) const{return real;}
		T GetImag(void) const{return imag;}
		T GetModulo(void) const{return modulo;}
		T GetFase(void) const{return faseGrados;}

		// Conjugado
		void conj(void);

		// Sobrecarga de operadores aritmeticos
		Complejo<T> operator+ (const Complejo<T>&);
		Complejo<T> operator+ (const T&);
		Complejo<T> operator- (const Complejo<T>&);
		Complejo<T> operator- (const T &);
		Complejo<T> operator* (const Complejo<T>&);
		Complejo<T> operator* (const T&);
		Complejo<T> operator/ (const Complejo<T>&);
		Complejo<T> operator/ (const T&);

		// Sobrecarga de operadores aritmeticos con asignación
		void operator+= (const Complejo<T>&);
		void operator+= (const T&);
		void operator-= (const Complejo<T>&);
		void operator-= (const T &);
		void operator*= (const Complejo<T>&);
		void operator*= (const T&);
		void operator/= (const Complejo<T>&);
		void operator/= (const T&);

		// Sobrecarga del operador de asignacion
		void operator= (const Complejo<T>&);
		void operator= (const T&);

		// Sobrecarga de operadores de comparacion
		bool operator== (const Complejo<T>&) const;
		bool operator!= (const Complejo<T>&) const;
		bool operator> (const Complejo<T>&) const;
		bool operator>= (const Complejo<T>&) const;
		bool operator< (const Complejo<T>&) const;
		bool operator<= (const Complejo<T>&) const;

		// Sobrecarga del operador de insercion en el flujo de salida
		template <class Z>
		friend ostream& operator<< (ostream&, const Complejo<Z>&);
		
		template <class Z>
		friend ofstream& operator<< (ofstream&, const Complejo<Z>&);

		// Sobrecarga del operador de extracción desde el flujo de entrada
		template <class Z>
		friend istream& operator>> (istream&, Complejo<Z>&);


		template <class Z>
		friend ifstream& operator>> (ifstream&, Complejo<Z>&);
};

//implementaciones
// constructor por defecto
template <class T>
Complejo<T>::Complejo(void)
{
	real = 0.0;
	imag = 0.0;
	modulo=0.0;
	faseGrados=0.0;
}

// constructor con argumentos
template <class T>
Complejo<T>::Complejo( const T& re, const T& im)
{
	real = re;
	imag = im;
	Rect2Polar(*this);

}

// constructor de copia
template <class T>
Complejo<T>::Complejo(const Complejo<T>& c)
{
	this->real = c.real;
	this->imag = c.imag;
	this->modulo = c.modulo;
	this->faseGrados = c.faseGrados;
}

//Conversión de coordenadas cartesianas a polares
template <class T>
void Complejo<T>::Rect2Polar(Complejo<T>& c)
{
	c.modulo = sqrt((pow(c.real,2) + pow(c.imag,2)));
	c.faseGrados = (atan2(c.imag,c.real)*180)/M_PI;
}

//Conversión de coordenadas polares a cartesianas
template <class T>
void Complejo<T>::Polar2Rect(Complejo<T>& c)
{
	c.real= c.modulo*(cos(c.faseGrados*(M_PI/180)));
	c.imag= c.modulo*(sin(c.faseGrados*(M_PI/180)));
}

template <class T>
void Complejo<T>::SetData(const Complejo<T>& c)
{
	*this = c; //Tiene que estar sobrecargado el operador =
}

template <class T>
void Complejo<T>::SetRealImag(const T& re, const T& im)
{
	real = re;
	imag = im;
	Rect2Polar(*this);

}

template <class T>
void Complejo<T>::SetModFase(const T& mod, const T& fase)
{
	modulo = mod;
	faseGrados = fase;
	Polar2Rect(*this);

}

template <class T>
void Complejo<T>::SetReal(const T& re)
{
	real = re;
	Rect2Polar(*this);
}

template <class T>
void Complejo<T>::SetImag(const T& im)
{
	imag = im;
	Rect2Polar(*this);
}

template <class T>
void Complejo<T>::SetMod(const T& mod)
{
	modulo = mod;
	Polar2Rect(*this);
}

template <class T>
void Complejo<T>::SetFase(const T& fase)
{
	faseGrados = fase;
	Polar2Rect(*this);
}

//Conjugado
template <class T>
void Complejo<T>::conj ()
{
	imag = -imag;
	Rect2Polar(*this);
}

// operadores artméticos
template <class T>
Complejo<T> Complejo<T>::operator+ (const Complejo<T>& c)
{
	Complejo<T> suma;
	suma.real = real + c.real;
	suma.imag = imag + c.imag;
	Rect2Polar(suma);

	return suma;
}

template <class T>
Complejo<T> Complejo<T>::operator+ (const T& re)
{
	Complejo<T> suma;
	suma.real = real + re;
	suma.imag = imag;
	Rect2Polar(suma);

	return suma;
}

template <class T>
Complejo<T> Complejo<T>::operator- (const Complejo<T>& c)
{
	Complejo<T> resta;
	resta.real = real - c.real;
	resta.imag = imag - c.imag;
	Rect2Polar(resta);

	return resta;
}

template <class T>
Complejo<T> Complejo<T>::operator- (const T& re)
{
	Complejo<T> resta;
	resta.real = real - re;
	resta.imag = imag;
	Rect2Polar(resta);

	return resta;
}

template <class T>
Complejo<T> Complejo<T>::operator* (const Complejo<T>& c)
{
	Complejo<T> mul;
	mul.real = real * c.real - imag * c.imag;
	mul.imag = imag * c.real + real * c.imag;
	Rect2Polar(mul);

	return mul;
}

template <class T>
Complejo<T> Complejo<T>::operator* (const T& a)
{
	Complejo<T> mul;
	mul.real = real * a;
	mul.imag = imag * a;
	Rect2Polar(mul);

	return mul;
}

template <class T>
Complejo<T> Complejo<T>::operator/ (const Complejo<T>& c)
{
	Complejo<T> div;

	if( c.modulo==0 )
	{
		throw( int(ERROR_DIV_CERO) );
	}

	div.real= ((real*c.real)+(imag*c.imag))/(pow(c.real,2)+pow(c.imag,2));
	div.imag= ((imag*c.real)-(real*c.imag))/(pow(c.real,2)+pow(c.imag,2));
	Rect2Polar(div);

	//Otra forma puede ser:
	//if( !(pow(c.real,2)+pow(c.imag,2)) )
	//{
	//	throw( int(ERROR_DIV_CERO) );
	//}

	//div.modulo=modulo/c.modulo;
	//div.faseGrados= faseGrados- c.faseGrados;
	//Polar2Rect(div);

	return div;
}

template <class T>
Complejo<T> Complejo<T>::operator/ (const T& a)
{
	Complejo<T> div;
	if( a==0 )
		{
			throw( int(ERROR_DIV_CERO) );
		}

		div.real= real/a;
		div.imag= imag/a;
		Rect2Polar(div);

	return div;
}

// operadores compuestos
template <class T>
void Complejo<T>::operator+= (const Complejo<T>& c)
{
	real += c.real;
	imag += c.imag;
	Rect2Polar(*this);
}

template <class T>
void Complejo<T>::operator+= (const T& re)
{

	real += re;
	Rect2Polar(*this);
}

template <class T>
void Complejo<T>::operator-= (const Complejo<T>& c)
{
	real -= c.real;
	imag -= c.imag;
	Rect2Polar(*this);
}

template <class T>
void Complejo<T>::operator-= (const T& re)
{
	real -= re;
	Rect2Polar(*this);
}

template <class T>
void Complejo<T>::operator*= (const Complejo<T>& c)
{
	*this = *this * c;

	//Complejo<T> mul;
	//mul.real = real * c.real - imag * c.imag;
	//mul.imag = imag * c.real + real * c.imag;
	//Rect2Polar(mul);
	//*this = mul;
}

template <class T>
void Complejo<T>::operator*= (const T& a)
{
	real *= a;
	imag *= a;
	Rect2Polar(*this);
}

template <class T>
void Complejo<T>::operator/= (const Complejo<T>& c)
{
	*this = *this / c;

	//Complejo<T> div;
	//if( c.modulo==0 )
	//{
	//	throw( int(ERROR_DIV_CERO) );
	//}
	//div.real= ((real*c.real)+(imag*c.imag))/(pow(c.real,2)+pow(c.imag,2));
	//div.imag= ((imag*c.real)-(real*c.imag))/(pow(c.real,2)+pow(c.imag,2));
	//Rect2Polar(div);

	//*this = div;
}

template <class T>
void Complejo<T>::operator/= (const T& a)
{
	Complejo<T> div;
	if( a==0 )
		{
			throw( int(ERROR_DIV_CERO) );
		}

		real /= a;
		imag /= a;
		Rect2Polar(*this);

}

// operador de asignación
template <class T>
void Complejo<T>::operator= (const Complejo<T>& c)
{
	real = c.real;
	imag = c.imag;
	modulo = c.modulo;
	faseGrados = c.faseGrados;

	return *this;
}

template <class T>
void Complejo<T>::operator= (const T& re)
{
	real = re;
	imag = 0.0;
	Rect2Polar(*this);

	return *this;
}

// sobrecarga de operadores de comparación
template <class T>
bool Complejo<T>::operator== (const Complejo<T>& c1) const
{
	return((real==c1.real)&&(imag==c1.imag));
}

template <class T>
bool Complejo<T>::operator!= (const Complejo<T>& c1) const
{
	return((real!=c1.real)||(imag!=c1.imag));
}

template <class T>
bool Complejo<T>::operator< (const Complejo<T>& c1) const
{
	return(modulo<c1.modulo);
}

template <class T>
bool Complejo<T>::operator<= (const Complejo<T>& c1) const
{
	return(modulo<=c1.modulo);
}

template <class T>
bool Complejo<T>::operator> (const Complejo<T>& c1) const
{
	return(modulo>c1.modulo);
}

template <class T>
bool Complejo<T>::operator>= (const Complejo<T>& c1) const
{
	return(modulo>=c1.modulo);
}

//sobrecarga operadores de inserción y extracción
template <class T>
ostream& operator<< (ostream& os, const Complejo<T>& c1)
{
	os << "(" <<  c1.real << "," << c1.imag << ")";
	os << " ; Modulo: " <<  c1.modulo << " ; Fase: " << c1.faseGrados << endl ;
	return os;
}

template <class T>
ofstream& operator<< (ofstream& os, const Complejo<T>& c1)
{
	os << "(" <<  c1.real << "," << c1.imag << ")";
	os << " ; Modulo: " <<  c1.modulo << " ; Fase: " << c1.faseGrados << endl ;
	return os;
}

template <class T>
istream& operator>> (istream& is, Complejo<T>& c1)
{
	char aux;
	cout << "\nIngresar en formato (real,imag)" << endl;
	is >> aux;
	if (aux!= '(') throw (ERROR_FORMATO_DE_ENTRADA);
	is >> c1.real;
	is >> aux;
	if (aux!= ',') throw (ERROR_FORMATO_DE_ENTRADA);
	is >> c1.imag;
	is >> aux;
	if (aux!= ')') throw (ERROR_FORMATO_DE_ENTRADA);
	c1.Rect2Polar(c1);

	return is;

}

template <class T>
ifstream& operator>> (ifstream& is, Complejo<T>& c1)
{
	char aux;
	is >> aux;
	if (aux!= '(') throw (ERROR_FORMATO_DE_ENTRADA);
	is >> c1.real;
	is >> aux;
	if (aux!= ',') throw (ERROR_FORMATO_DE_ENTRADA);
	is >> c1.imag;
	is >> aux;
	if (aux!= ')') throw (ERROR_FORMATO_DE_ENTRADA);
	c1.Rect2Polar(c1);

	return is;

}

#endif 

// COMPLEJOTEMPLATE
