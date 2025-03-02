#ifndef PRODUCT_H
#define PRODUCT_H

#include <stdlib.h>
#include "../string/myString.h"
#include "../date/date.h"

#define MAX_LEN 100

typedef unsigned int uInt;

typedef struct 
{
    uInt id;
    String name;
    _Date expiryDate;
    uInt qty;
    double price; 
} _Product, *Product;

Product createProduct
(
    uInt id,
    String name,
    _Date expiryDate,
    uInt qty,
    double price
);

void displayProduct(_Product product);

Product addProductInCollection
(
    Product collection[],
    uInt *n,
    Product newProduct
);

Product searchProductInCollection
(
    Product collection[],
    const uInt N,
    uInt productId
);

/**
 * assume product only exist once
 * in the collection
 */
Product removeProductInCollection
(
    Product collection[],
    uInt *n,
    String productName
);

#endif
