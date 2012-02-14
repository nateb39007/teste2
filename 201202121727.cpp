/*
 * rationalNumbers.cpp
 *
 *  Created on: Nov 3, 2011
 *      Author: chocobogummy
 */

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "rationalNumbers.h"
using namespace std;

//====================Public Month member functions====================//
//====================Constructors====================//

RationalNumber :: RationalNumber(){
	a = 0;
	b = 1;
}

RationalNumber :: RationalNumber(int n) : a(n), b(1){
	;
}

RationalNumber :: RationalNumber(int num, int den){
	a = num;
	b = den;
	checkRationalNumber();
	makeNeat();

}

//====================Functions===================//
/* Function returns a RationalNumber that is the sum of two RationalNumbers
   Pre: r is a RationalNumber
   Post: returns a RationalNumber that is the sum of the calling RationalNumber and r
*/
RationalNumber RationalNumber :: add(const RationalNumber &r) const{
	int num, dem;

	num = a * r.b + r.a * b;
	dem = b * r.b;

	return RationalNumber(num, dem);
}

/* Function returns a RationalNumber that is the difference of two RationalNumbers
   Pre: r is a RationalNumber
   Post: returns a RationalNumber that is the difference of the calling RationalNumber and r
*/
RationalNumber RationalNumber :: sub(const RationalNumber &r) const{
	int num, dem;

	num = a * r.b - r.a * b;
	dem = b * r.b;

	return RationalNumber(num, dem);
}

RationalNumber RationalNumber :: mul(const RationalNumber &r) const{
	return RationalNumber(a * r.a, b * r.b);
}

RationalNumber RationalNumber :: div(const RationalNumber &r) const{
	return RationalNumber(a * r.b, b * r.a);
}

RationalNumber RationalNumber :: neg(void){
	return RationalNumber(-a, b);
}

/* Function returns a whether a rational number is less than another
   Pre: r is a RationalNumber
   Post: returns whether the calling Rational Number is less than r
*/
bool RationalNumber :: less(const RationalNumber &r) const{
	return ((a * r.b) < (b * r.a));
}

/* Function puts a rational number in an output stream
   Pre: stream in an ostream
   Post: puts the representation of the calling rational number in the stream
*/
void RationalNumber :: output(ostream &stream) const{
	if (b != 1)
		stream << a << '/' << b;
	else
		stream << a;
	return;
}

/* Function gets a rational number from an input stream
   Pre: stream in an istream
   Post: gets rational number
*/
void RationalNumber :: input(istream &stream){
	cin >> a >> b;
	checkRationalNumber();
	makeNeat();
	return;
}

//====================Private Month member functions====================//
/* Function fixes negative sign in numerator and denominator of calling RationalNumber.
 * 	Pre: calling RationalNumber.
 * 	Post: numerator and denominator signs fixed.
 */
void RationalNumber :: fixNeg(void){
	if (b < 0){
		a = -a;
		b = -b;
	}
	return;
}

/* Function determines the gcd of the numerator and denominator using
 * Euclid's method of determining gcd.
 * 	Pre: calling RationalNumber.
 * 	Post: returns gcd of calling RationalNumber's numerator and denominator.
 */
int RationalNumber :: gcd(void) const{
	int temp, n1 = abs(a), n2 = abs(b);

	while ((temp = n1 % n2)){
		n1 = n2;
		n2 = temp;
	}
	return n2;
}

/* Function fixes negative sign and reduces numerator and denominator of calling RationalNumber.
 * 	Pre: calling RationalNumber.
 * 	Post: calling RationalNumber reduced and negative sign fixed.
 */
void RationalNumber :: makeNeat(void){
	int n;

	fixNeg();
	n = gcd();
	a /= n;
	b /= n;
	return;

}
void RationalNumber :: checkRationalNumber(void) const{
	if (!b){
		cout << "Illegal input!\nExiting...\n";
		exit(1);
	}
}
