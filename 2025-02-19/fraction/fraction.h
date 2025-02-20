#ifndef FRACTION_H
#define FRACTION_H

/** {whole, num, den} */
typedef struct
{
    int whole;
    int num;
    int den;
} _Fraction, *Fraction;

_Fraction createFraction(int numerator, int denominator);
void displayFraction(_Fraction fraction);
_Fraction sumFraction(_Fraction f1, _Fraction f2);
_Fraction diffFraction(_Fraction f1, _Fraction f2);
_Fraction prodFraction(_Fraction f1, _Fraction f2);
_Fraction quoFraction(_Fraction f1, _Fraction f2);

/**
 * converts an improper fraction
 * to a mix fraction.
 * 3/2 = 1 1/2 
 */
_Fraction makeMixFraction(_Fraction fraction);

#endif
