#include <stdio.h>
#include <assert.h>
#include "product.h"
#include "../string/myString.h"
#include "../date/date.h"

void testCreateProduct() {
    _Date expiryDate = {15, 7, 2025};
    String name = "Milk"; // Use a string literal for simplicity
    Product product = createProduct(1, name, expiryDate, 10, 2.99);
    assert(product->id == 1);
    assert(strcmp(product->name, "Milk") == 0);
    assert(product->expiryDate.day == 15);
    assert(product->expiryDate.month == 7);
    assert(product->expiryDate.year == 2025);
    assert(product->qty == 10);
    assert(product->price == 2.99);
}

void testAddProductInCollection() {
    Product collection[MAX_LEN];
    uInt n = 0;
    _Date expiryDate = {15, 7, 2025};
    String name = "Milk"; // Use a string literal for simplicity
    Product product = createProduct(1, name, expiryDate, 10, 2.99);
    addProductInCollection(collection, &n, product);
    assert(n == 1);
    assert(collection[0]->id == 1);
}

void testSearchProductInCollection() {
    Product collection[MAX_LEN];
    uInt n = 0;
    _Date expiryDate = {15, 7, 2025};
    String name = "Milk"; // Use a string literal for simplicity
    Product product = createProduct(1, name, expiryDate, 10, 2.99);
    addProductInCollection(collection, &n, product);
    Product foundProduct = searchProductInCollection(collection, n, 1);
    assert(foundProduct->id == 1);
    assert(strcmp(foundProduct->name, "Milk") == 0);
}

void testRemoveProductInCollection() {
    Product collection[MAX_LEN];
    uInt n = 0;
    _Date expiryDate = {15, 7, 2025};
    String name = "Milk"; // Use a string literal for simplicity
    Product product = createProduct(1, name, expiryDate, 10, 2.99);
    addProductInCollection(collection, &n, product);
    removeProductInCollection(collection, &n, name);
    assert(n == 0);
}

int main() {
    _Date expiryDate = {15, 7, 2025};
    String name = "Milk"; // Use a string literal for simplicity
    Product product = createProduct(1, name, expiryDate, 10, 2.99);
    testCreateProduct();
    displayProduct(*product);
    testAddProductInCollection();
    testSearchProductInCollection();
    testRemoveProductInCollection();
    printf("All tests passed.\n");
    return 0;
}
