#include <stdio.h>
#include "fraction.h"
#include "../error/error.h"

_Fraction createFraction(int numerator, int denominator) {
    if (denominator == 0) 
    {
        throwError("undefined fraction: division by 0");
    }

    _Fraction fraction;
    fraction.whole = 0;
    fraction.num = numerator;
    fraction.den = denominator;
    return simplifyFraction(fraction);
}

void displayFraction(_Fraction fraction) {
    if (fraction.whole != 0) {
        printf("%d ", fraction.whole);
    }
    if (fraction.num != 0) {
        printf("%d/%d", fraction.num, fraction.den);
    }
    if (fraction.whole == 0 && fraction.num == 0) {
        printf("0");
    }
    printf("\n");
}

_Fraction sumFraction(_Fraction f1, _Fraction f2) {
    _Fraction result;
    result.num = f1.num * f2.den + f2.num * f1.den;
    result.den = f1.den * f2.den;
    result.whole = 0;
    return simplifyFraction(result);
}

_Fraction diffFraction(_Fraction f1, _Fraction f2) {
    f2.num = -f2.num;
    return sumFraction(f1, f2);
}

_Fraction prodFraction(_Fraction f1, _Fraction f2) {
    _Fraction result;
    result.num = f1.num * f2.num;
    result.den = f1.den * f2.den;
    result.whole = 0;
    return simplifyFraction(result);
}

_Fraction quoFraction(_Fraction f1, _Fraction f2) {
    _Fraction result;
    result.num = f1.num * f2.den;
    result.den = f1.den * f2.num;
    result.whole = 0;
    return simplifyFraction(result);
}

_Fraction reciprocalFraction(_Fraction fraction) {
    _Fraction result;
    result.num = fraction.den;
    result.den = fraction.num;
    result.whole = 0;
    return result;
}

/**
 * converts an improper fraction
 * to a mix fraction.
 * 3/2 = 1 1/2 
 */
_Fraction makeMixFraction(_Fraction fraction) {
    fraction.whole = fraction.num / fraction.den;
    fraction.num = fraction.num % fraction.den;
    return fraction;
}

_Fraction makeImproperFraction(_Fraction fraction) {
    fraction.num = fraction.whole * fraction.den + fraction.num;
    fraction.whole = 0;
    return fraction;
}

_Fraction simplifyFraction(_Fraction fraction) {
    int gcd, a = fraction.num, b = fraction.den;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    gcd = (a < 0) ? -a : a;
    fraction.num /= gcd;
    fraction.den /= (gcd == 0) ? 1 : gcd;
    return fraction;
}

uShort fractionForm(_Fraction fraction) {
    if (fraction.whole != 0) {
        return MIX_FORM;
    } else if (fraction.num < fraction.den) {
        return PROPER_FORM;
    } else {
        return IMPROPER_FORM;
    }
}

