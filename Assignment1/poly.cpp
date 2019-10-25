//---------------------program definitions--------------------------
// a Poly object holds one Polynomial

#include "poly.h"
using namespace std;
/**---------------------------------- Constructor -------------------------------------------------
 * Poly
 * @param none
 * creates a Poly object with zero value
**/
Poly::Poly(){
    size = 1;
    coeffs = new int[size];
	coeffs[0] = 0;
}
/**---------------------------------- Constructor -------------------------------------------------
 * Overloaded Poly
 * @param coeff
 * creates a Poly object with passed coeff value at power 0
**/
Poly::Poly(int coeff){
    size = 1;
    coeffs = new int[size];
    coeffs[0] = coeff;
}
/**---------------------------------- Constructor -------------------------------------------------
 * Overloaded Poly
 * @param coeff, power
 * creates a Poly object with passed coeff value at passed power
**/
Poly::Poly(int coeff, int power){
    size = power + 1;
    coeffs = new int[size];
	clear();
    coeffs[power] = coeff;
}
/**---------------------------------- Copy Constructor --------------------------------------------
 * Overloaded Poly
 * @param &other
 * creates a Poly object deep copy of passed Poly object
**/
Poly::Poly(const Poly &other){
	if (coeffs != NULL) {
		delete[] coeffs;
		coeffs = NULL;
	}
	this->size = other.size;
    coeffs = new int[other.size];
    for(int i = 0; i < other.size; i++){
        coeffs[i] = other.coeffs[i];
    }
}
/**----------------------------------- destructor -------------------------------------------------
 * overloaded destructor
 * frees memory in heap taken by poly objects coeffs array
**/
Poly::~Poly(){
    delete[] coeffs;
}
/**----------------------------------- operator>> -------------------------------------------------
 * overloaded >>: input of an arbitrary number of coefficient-power pair. 
 * input is assumed to be pairs, ending with -1 -1
 * input using this operator completely replaces the stored polynomial, for modification of 
 * existing polynomial, use setCoeff
**/
istream &operator>>( istream &in, Poly &rhs ){
    int coeff;
    int power;
    in >> coeff >> power;
	rhs.clear();
    while(power > -1){
        if(power > rhs.size){
            rhs.expandArr(power);
        }
        rhs.coeffs[power] = coeff;
        in >> coeff >> power;
    }
	return in;
}
/**------------------------------------ operator<< -----------------------------------------------
 * overloaded << : prints a mathmatically correct expression representing polynomial
 * zero coefficients are not printed
 * zero value polynomials are printed out as 0.
**/
ostream &operator<<( ostream &out, const Poly &rhs ){ //print out entire polynomial
    if(rhs.size > 2){
        for(int i = rhs.size - 1; i > 1; i--){
            if(rhs.coeffs[i] != 0){
                if(rhs.coeffs[i] > 0){
                    out << " +";
                }else{
                    out << " ";
                }
                out << rhs.coeffs[i] << "x^" << i;
            }
        }
    }
    if(rhs.size > 1){
        if(rhs.coeffs[1] != 0){
            if(rhs.coeffs[1] > 0){
                out << " +";
            }else{
                out << " ";
            }
            out << rhs.coeffs[1] << "x";
        }
    }
    if(rhs.coeffs[0] != 0){
        if(rhs.coeffs[0] > 0){
            out << " +";
        }else{
            out << " ";
        }
        out << rhs.coeffs[0];
    }
    if(rhs.size == 1 && rhs.coeffs[0] == 0){
        out << " " << 0;
    }
    return out;
}
// Arithmetic binary operators
/**------------------------------- operator+ ----------------------------------------------------
 * overloaded + : addition of 2 polynomials, current object and parameter
 * result will be the length of the larger polynomial
**/
Poly Poly::operator+( const Poly &rhs ) const{
    int large;
    int small;
	Poly result;
    if(rhs.size >= this->size){
        large = rhs.size;
        small = this->size;
        result = Poly(0, large - 1);
        for(int i = large - 1; i >= 0; i--){
            if(i >= small){
                result.coeffs[i] = rhs.coeffs[i];
            }else{
                result.coeffs[i] = this->coeffs[i] + rhs.coeffs[i];
            }
        }
    }else{
        large = this->size;
        small = rhs.size;
        result = Poly(0, large - 1);
        for(int i = large - 1; i >= 0; i--){
            if(i >= small){
                result.coeffs[i] = this->coeffs[i];
            }else{
                result.coeffs[i] = this->coeffs[i] + rhs.coeffs[i];
            }
        }
    }
    return result;
}
/**-------------------------------- operator- ------------------------------------------------------
 * overloaded - : subtraction of 2 polynomials, current object and parameter
 * result will be the length of the larger polynomial
**/
Poly Poly::operator-( const Poly &rhs ) const{
	int large;
    int small;
    Poly result;
    if(rhs.size >= this->size){
        large = rhs.size;
        small = this->size;
        result =  Poly(0, large - 1);
        for(int i = large - 1; i >= 0; i--){
            if(i >= small){
                result.coeffs[i] = -(rhs.coeffs[i]);
            }else{
                result.coeffs[i] = this->coeffs[i] - rhs.coeffs[i];
            }
        }
    }else{
        large = this->size;
        small = rhs.size;
        result = Poly(0, large - 1);
        for(int i = large - 1; i >= 0; i--){
            if(i >= small){
                result.coeffs[i] = -(this->coeffs[i]);
            }else{
                result.coeffs[i] = this->coeffs[i] - rhs.coeffs[i];
            }
        }
    }
    return result;
}
/**---------------------------------- operator* ---------------------------------------------------
 * overloaded * : multiplication of 2 polynomials, current object and parameter
 * result will be the length of the the sum of the two larger powers
**/
Poly Poly::operator*( const Poly &rhs ) const{
    //find new size, sum of max powers with nonzero value
	int thisMaxPower = 0;
    int rhsMaxPower = 0;
    for(int i = 0; i < this->size; i++){
        this->coeffs[i] == 0 ? thisMaxPower = thisMaxPower : thisMaxPower = i;
    }
    for(int i = 0; i < rhs.size; i++){
        rhs.coeffs[i] == 0 ? rhsMaxPower = rhsMaxPower : rhsMaxPower = i;
    }
    //make new poly with new highest order term
    Poly result = Poly(0, thisMaxPower + rhsMaxPower);
    //work through this array multiplying all nonzero coeffs with...
    for(int i = 0; i < this->size; i++){
        if(this->coeffs[i] != 0){
            //all nonzero coeffs in rhs array
            for(int j = 0; j < rhs.size; j++){
                if(rhs.coeffs[j] != 0){
                    //new power            //new coeff
                    result.coeffs[i + j] = (this->coeffs[i] * rhs.coeffs[j]);
                }
            }
        }
    }
    return result;
}
/**------------------------------------ operator+= --------------------------------------------------
 * overloaded += : adding current object and parameter
 * length of current will change if needed
**/
Poly &Poly::operator+=( const Poly &rhs ){
	Poly result = Poly(*this + rhs);
    if(this->size < result.size){
        expandArr(result.size - 1);
        this->size = result.size;
    }
    clear();
    for(int i = 0; i < result.size; i++){
            this->coeffs[i] = result.coeffs[i];
    }
    return *this;
}
/**------------------------------------ operator-= -------------------------------------------------
 * overloaded -= : subtracting current object and parameter
 * length of current will change if needed
**/
Poly &Poly::operator-=( const Poly &rhs ){
	Poly result = Poly(*this - rhs);
    if(this->size < result.size){
        expandArr(result.size - 1);
        this->size = result.size;
    }
    clear();
    for(int i = 0; i < result.size; i++){
            this->coeffs[i] = result.coeffs[i];
    }
    return *this;
}
/**------------------------------------ operator*= --------------------------------------------------
 * overloaded *= : multiplying current object and parameter
 * length of current will change if needed
**/
Poly &Poly::operator*=( const Poly &rhs ){
	Poly result = Poly(*this * rhs);
    if(this->size < result.size){
        expandArr(result.size - 1);
        this->size = result.size;
    }
    clear();
    for(int i = 0; i < result.size; i++){
            this->coeffs[i] = result.coeffs[i];
    }
    return *this;
}
/**--------------------------------- operator= ----------------------------------------------------
 * overloaded = : assignment of current object to be equal to parameter
**/
const Poly &Poly::operator=( const Poly &rhs ){
    if(this != &rhs){
        delete[] coeffs;
        size = rhs.size;
        coeffs = NULL;
        coeffs = new int[size];
        for(int i = 0; i < size; i++){
            this->coeffs[i] = rhs.coeffs[i];
        }
    }
    return *this;
}
/**----------------------------------- operator== --------------------------------------------------
 * overloaded == : equality comparison of current and paramter polynomials
 * returns mathmatical equality, not object equality
**/
bool Poly::operator==( const Poly & rhs ) const{
	int large;
    int small;
    if(rhs.size >= this->size){
        large = rhs.size;
        small = this->size;
        
        for(int i = large - 1; i >= 0; i--){
            if(i > small - 1){
                if(rhs.coeffs[i] != 0){
                    return false;
                }
            }else{
                if(this->coeffs[i] != rhs.coeffs[i]){
                    return false;
                }
            }
        }
    }else{
        large = this->size;
        small = rhs.size;
        for(int i = large - 1; i >= 0; i--){
            if(i > small - 1){
                if(this->coeffs[i] != 0){
                    return false;
                }
            }else{
                if(this->coeffs[i] != rhs.coeffs[i]){
                    return false;
                }
            }
        }
    }
	return true;
}
/**------------------------------------- operator!-------------------------------------------------
 * overloaded != : inequality comparison of current and paramter polynomials
 * returns mathmatical inequality, not object inequality
**/
bool Poly::operator!=( const Poly & rhs ) const{
	return !(*this == rhs);
}

/**------------------------------------- getCoeff -------------------------------------------------
 * @param power
 * returns the coefficient of the parameter, if parameter is outside of the existing array, 0 is
 * returned as mathmatically correct
**/
int Poly::getCoeff(int power){
    if(power < size - 1 && power >= 0){
        return coeffs[power];
    }
    return 0;
}
/**------------------------------------- setCoeff -------------------------------------------------
 * @param coeff, power
 * sets the coefficient of the passed power to the passed coefficient. If passed power is outside
 * of the range of the current Poly, the coeff array is resized
**/
void Poly::setCoeff(int coeff, int power){
    if(power < size - 1 && power >= 0){
        coeffs[power] = coeff;
    }else if(power < 0){
        return;
    }else{
        expandArr(power);
        coeffs[power] = coeff;
    }
}
/**------------------------------------ expandArr --------------------------------------------------
 * @param maxPower
 * creates a new array in the heap that is of the parameter length + 1. copies all values of current
 * array to the new array then deletes the old array.
**/
void Poly::expandArr(int maxPower){
    int * temp = new int[maxPower + 1];
    int * old = coeffs;
    for(int i = 0; i < maxPower; i++){
        if(i < size){
            temp[i] = old[i];
        }else{
            temp[i] = 0;
        }
    }
    size = maxPower + 1;
    coeffs = temp;
    delete[] old;
}
/**-------------------------------------- clear -----------------------------------------------------
 * sets all values of current coefficient array to 0.
**/
void Poly::clear(){
    for(int i = 0; i < size; i++){
        this->coeffs[i] = 0;
    }
}