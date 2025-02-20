#ifndef FRACTION_H
#define FRACTION_H

#define PROPER_FORM 1
#define IMPROPER_FORM 2
#define MIX_FORM 3

typedef unsigned short uShort;

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
_Fraction reciprocalFraction(_Fraction fraction);

/**
 * converts an improper fraction
 * to a mix fraction.
 * 3/2 = 1 1/2 
 */
_Fraction makeMixFraction(_Fraction fraction);
_Fraction makeImproperFraction(_Fraction fraction);

_Fraction simplifyFraction(_Fraction fraction);
uShort fractionForm(_Fraction fraction);


#endif
