#include <stdio.h>
#include "fraction.h"
#include "../error/error.h"

int euclideanAlgo(int a, int b);

_Fraction createFraction(int numerator, int denominator)
{
    if (denominator == 0)
    {
        throwError("undefined fraction: 0 denominator");
    }

    return (_Fraction) {0, numerator, denominator};
}

void displayFraction(_Fraction fraction)
{
    if (fractionForm(fraction) == MIX_FORM)
    {
        fraction = makeImproperFraction(fraction);
    }

    printf("%d / %d\n", fraction.num, fraction.den);
}

int euclideanAlgo(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

_Fraction sumFraction(_Fraction f1, _Fraction f2)
{
    f1 = makeImproperFraction(f1);
    f2 = makeImproperFraction(f2);
    
    if (f1.num == 0)
    {
        return f2;
    } 

    if (f2.num == 0)
    {
        return f1;
    }

    if (f1.den != f2.den)
    {
        f1 = prodFraction
        (
            f1,
            createFraction(0, f2.den, f2.den)
        );
        f2 = prodFraction
        (
            f2,
            createFraction(0, f1.den, f1.den)
        );
    }

    return createFraction
    (
        f1.num + f2.num,
        f1.den
    );
}

_Fraction diffFraction(_Fraction f1, _Fraction f2)
{
    f2.num *= -1;
    return sumFraction(f1, f2);
}

_Fraction prodFraction(_Fraction f1, _Fraction f2)
{
    f1 = makeImproperFraction(f1);
    f2 = makeImproperFraction(f2);

    return createFraction
    (
        (f1.num * f2.num),
        (f1.den * f2.den)
    );
}

_Fraction quoFraction(_Fraction f1, _Fraction f2)
{
    if (f2.num == 0 || f2.den == 0)
    {
        throwError("error: division by zero");
    }

    return prodFraction(f1, reciprocalFraction(f2));
}

_Fraction reciprocalFraction(_Fraction fraction)
{
    fraction = makeImproperFraction(fraction);
    int temp = fraction.num;
    fraction.num = fraction.den;
    fraction.den = temp;
    return fraction;
}

_Fraction makeMixFraction(_Fraction fraction)
{
    if (fractionForm(fraction) == IMPROPER_FORM)
    {
        fraction.whole = fraction.num / fraction.den;
        fraction.num = fraction.num % fraction.den;

        if (fraction.num == 0)
        {
            fraction.num = fraction.den = 1;
        }
    }

    return simplifyFraction(fraction);
}

_Fraction makeImproperFraction(_Fraction fraction)
{
    if (fractionForm(fraction) == MIX_FORM)
    {
        int n = fraction.whole * fraction.den;
        fraction.num *= n;
        fraction.den *= n;
        fraction.whole = 0;
    }

    return fraction;
}


uShort fractionForm(_Fraction fraction)
{
    if (fraction.whole != 0)
    {
        return MIX_FORM;
    }
    else if (fraction.num > fraction.den)
    {
        return IMPROPER_FORM;
    }
    
    return PROPER_FORM;
}

_Fraction simplifyFraction(_Fraction fraction)
{
    fraction = makeImproperFraction(fraction);
    int common = euclideanAlgo(fraction.num, fraction.den);
    fraction.num /= common;
    fraction.den /= common;

    return fraction;
}
