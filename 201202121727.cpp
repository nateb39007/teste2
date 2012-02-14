/* Created on: Nov 3, 2011
 *      Author: chocobogummy
 */

#ifndef RATIONALNUMBERS_H_
#define RATIONALNUMBERS_H_

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

class RationalNumber{
public:
  // Constructor Declaration
	RationalNumber();
	RationalNumber(int n);
	RationalNumber(int num, int den);

	// Member function Declaration
	RationalNumber add(const RationalNumber &r) const;
	RationalNumber sub(const RationalNumber &r) const;
	RationalNumber mul(const RationalNumber &r) const;
	RationalNumber div(const RationalNumber &r) const;
	RationalNumber neg(void);
	bool less(const RationalNumber &r) const;
	void input(istream &stream);
	void output(ostream &stream) const;


private:
	// Variable Declaration
	int a;
	int b;

	// Member function Declaration
	void fixNeg(void);
	int gcd(void) const;
	void makeNeat(void);
	void checkRationalNumber(void) const;
};

#endif /* RATIONALNUMBERS_H_ */
