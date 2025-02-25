#include <stdio.h>
#include <assert.h>
#include "fraction/fraction.h"

int main() {
    // Test createFraction
    _Fraction f1 = createFraction(3, 4);
    _Fraction f2 = createFraction(5, 6);
    _Fraction f3 = createFraction(7, 2);
    _Fraction f4 = createFraction(9, 3);
    _Fraction f5 = createFraction(4, 8);
    _Fraction f6 = createFraction(10, 20);

    // Test displayFraction
    printf("Test displayFraction:\n");
    displayFraction(f1);
    displayFraction(f2);
    displayFraction(f3);

    // Test sumFraction
    printf("\nTest sumFraction:\n");
    _Fraction sum1 = sumFraction(f1, f2);
    _Fraction sum2 = sumFraction(f3, f4);
    _Fraction sum3 = sumFraction(f5, f6);
    assert(sum1.num == 19 && sum1.den == 12);
    assert(sum2.num == 13 && sum2.den == 2);
    assert(sum3.num == 1 && sum3.den == 1);

    // Test diffFraction
    printf("\nTest diffFraction:\n");
    _Fraction diff1 = diffFraction(f1, f2);
    _Fraction diff2 = diffFraction(f3, f4);
    _Fraction diff3 = diffFraction(f5, f6);
    assert(diff1.num == -1 && diff1.den == 12);
    assert(diff2.num == 1 && diff2.den == 2);
    assert(diff3.num == 0 && diff3.den == 1);

    // Test prodFraction
    printf("\nTest prodFraction:\n");
    _Fraction prod1 = prodFraction(f1, f2);
    _Fraction prod2 = prodFraction(f3, f4);
    _Fraction prod3 = prodFraction(f5, f6);
    assert(prod1.num == 5 && prod1.den == 8);
    assert(prod2.num == 21 && prod2.den == 2);
    assert(prod3.num == 1 && prod3.den == 4);

    // Test quoFraction
    printf("\nTest quoFraction:\n");
    _Fraction quo1 = quoFraction(f1, f2);
    _Fraction quo2 = quoFraction(f3, f4);
    _Fraction quo3 = quoFraction(f5, f6);
    assert(quo1.num == 9 && quo1.den == 10);
    assert(quo2.num == 7 && quo2.den == 6);
    assert(quo3.num == 1 && quo3.den == 1);

    // Test reciprocalFraction
    printf("\nTest reciprocalFraction:\n");
    _Fraction rec1 = reciprocalFraction(f1);
    _Fraction rec2 = reciprocalFraction(f3);
    _Fraction rec3 = reciprocalFraction(f5);
    assert(rec1.num == 4 && rec1.den == 3);
    assert(rec2.num == 2 && rec2.den == 7);
    assert(rec3.num == 2 && rec3.den == 1);

    // Test makeMixFraction
    printf("\nTest makeMixFraction:\n");
    _Fraction mix1 = makeMixFraction(f3);
    _Fraction mix2 = makeMixFraction(f4);
    _Fraction mix3 = makeMixFraction(f6);
    assert(mix1.whole == 3 && mix1.num == 1 && mix1.den == 2);
    assert(mix2.whole == 3 && mix2.num == 0 && mix2.den == 1);

    // Test makeImproperFraction
    printf("\nTest makeImproperFraction:\n");
    _Fraction improper1 = makeImproperFraction(mix1);
    _Fraction improper2 = makeImproperFraction(mix2);
    _Fraction improper3 = makeImproperFraction(mix3);
    assert(improper1.num == 7 && improper1.den == 2);
    assert(improper2.num == 3 && improper2.den == 1);
    assert(improper3.num == 1 && improper3.den == 2);

    // Test simplifyFraction
    printf("\nTest simplifyFraction:\n");
    _Fraction unsimplified1 = createFraction(8, 12);
    _Fraction unsimplified2 = createFraction(18, 24);
    _Fraction unsimplified3 = createFraction(50, 100);
    _Fraction simplified1 = simplifyFraction(unsimplified1);
    _Fraction simplified2 = simplifyFraction(unsimplified2);
    _Fraction simplified3 = simplifyFraction(unsimplified3);
    assert(simplified1.num == 2 && simplified1.den == 3);
    assert(simplified2.num == 3 && simplified2.den == 4);
    assert(simplified3.num == 1 && simplified3.den == 2);

    // Test fractionForm
    printf("\nTest fractionForm:\n");
    uShort form1 = fractionForm(f1);
    uShort form2 = fractionForm(f3);
    uShort form3 = fractionForm(mix1);
    assert(form1 == PROPER_FORM);
    assert(form2 == IMPROPER_FORM);
    assert(form3 == MIX_FORM);

    printf("All tests passed!\n");

    return 0;
}
