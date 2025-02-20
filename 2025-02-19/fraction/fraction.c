#include "fraction.h"
#include <stdio.h>

_Fraction createFraction(int numerator, int denominator)
{
    return (_Fraction) {0, numerator, denominator};
}

void displayFraction(_Fraction fraction)
{
    printf("%d / %d\n", fraction.num, fraction.den);
}

_Fraction sumFraction(_Fraction f1, _Fraction f2)
{
    _Fraction sum;
    sum.whole = f1.whole + f2.whole;

    if (f1.den == f2.den)
    {
        sum.num = f1.num + f2.num;
        sum.den = f1.den;
    }
    else
    {

    }

    return sum;
}

_Fraction diffFraction(_Fraction f1, _Fraction f2)
{

}

_Fraction prodFraction(_Fraction f1, _Fraction f2)
{
    
}

_Fraction quoFraction(_Fraction f1, _Fraction f2)
{

}

/**
 * converts an improper fraction
 * to a mix fraction.
 * 3/2 = 1 1/2 
 */
_Fraction makeMixFraction(_Fraction fraction)
{
    if (fraction.whole == 0)
    {
        return fraction;
    }

    int num = (fraction.den * fraction.whole) + fraction.num;

    return (_Fraction) {0, num, fraction.den};
}

