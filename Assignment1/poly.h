/**----------------------------------header-----------------------------------------------
 *A Poly object holds one polynomial of arbitrary length (Hardware/memory constrined)
 *@author Joshua Landron
 *@date 3Apr2019 
 *Created for CSS 343 B at UWB with Dr. Min Chen
 *Last modified 6Arp2019
**/
#ifndef POLY_H
#define POLY_H
#include <iostream>

using namespace std;
/**-------------------------------------------------------------------------------------------------
 * Polynomials: Defined as expressions consisting of terms that are a sum of 
 * coefficients leading different powers of the same variable.
 * example: +5x^7 -4x^3 +10x -2
 * 
 * Implementation and assumptions:
 * --Polynomials are stored as an array of coefficients with their index being the power
 * --Polynomials will only have nonnegative whole number powers, and integer coefficients
 * --All polynomial outputs will be mathmatically correct.
 * --array will expand as needed to exactly the size needed, but will not shrink.
 * --Polynomials will always be at least 0.
 * --Polynomials will be able to be added, subtracted and multiplied 
 * --Assumed that input using istream is formatted correctly, no error checking.
**/
class Poly{
// overloaded >>: takes in a string of spaced integers, always in coefficient power pairs.
friend istream &operator>>( istream &in, Poly &rhs );
// overloaded <<: prints polynomials in their entirety, does not prints zero coefficient powers
// prints Ax for power 1, and A for power 0.
// prints 0 if polynomial has all zero values.
friend ostream &operator<<( ostream &out, const Poly &rhs );

public:
    // default constructor:  no parameters, sets polynomial size to 1, and value to 0
    Poly();
    // 0 power constructor:  parameters are the 0 power coefficient
    Poly(int coeff);
    // selected power constructor:  parameters are
    Poly(int coeff, int power);
    // copy constructor:  parameters are
    Poly(const Poly &other);
    // destructor: 
    virtual ~Poly();

    // Arithmetic binary operators
    Poly operator+( const Poly &rhs ) const; //adds 2 polynomials
    Poly operator-( const Poly &rhs ) const; //subtracts 2 polynomials
    Poly operator*( const Poly &rhs ) const; //multiplies 2 polynomials

    Poly &operator+=( const Poly &rhs );    //adds another polynomials to this polynomial
    Poly &operator-=( const Poly &rhs );    //subtracts another polynomials from this polynomial
    Poly &operator*=( const Poly &rhs );    //multpilies another polynomials with this polynomial

    // assignment operators
    const Poly &operator=( const Poly &rhs ); //changes all values of this polynomial to be that of another

    // Logical binary operators
    bool operator==( const Poly & rhs ) const; //compares Polynomial mathmatical equality, not object equality
    bool operator!=( const Poly & rhs ) const; //compares Polynomial mathmatical inequality

    //getter and setter
    int getCoeff(int power); //returns the coefficient of an arbitrary power
    void setCoeff(int coeff, int power); //sets the coefficient of any nonzero power, will do nothing if
                                        //negative power is passed

private:
    int * coeffs = NULL; //coeffs initialized to nullptr
    int size; //size keeps track of the true size of the coeff array
    void expandArr(int maxPower); //expands the array to a new size and changes size value
    void clear(); //makes all values in coeffs 0
};

#endif