#include <stdio.h>
#include "../error/error.h"
#include "product.h"

Product createProduct
(
    uInt id,
    String name,
    _Date expiryDate,
    uInt qty,
    double price
)
{
    if (name == NULL)
    {
        throwError("null pointer: name");
    }
    else if (price < 0)
    {
        throwError("invalid price");
    }

    Product product = malloc(sizeof(_Product));

    if (product != NULL)
    {
        product->id = id;
        product->name = name;
        product->expiryDate = expiryDate;
        product->qty = qty;
        product->price = price;
    }

    return product;
}

void displayProduct(_Product product)
{
    printf("ID: %u\n", product.id);
    printf("Name: %s\n", product.name);
    printf("Expiry _Date: ");
    displayDate(product.expiryDate);
    printf("Quantity: %u\n", product.qty);
    printf("Price: %lf\n", product.price);
}

Product addProductInCollection
(
    Product collection[],
    uInt *n,
    Product newProduct
)
{
    if (*n == MAX_LEN) 
    {
        throwError("Cannot add new product. Array of products is full");
    }
    else if (newProduct == NULL)
    {
        throwError("null pointer: newProduct");
    }

    int i = *n;
    while ((i > 0) && (strcmp(collection[i]->name, newProduct->name) > 0))
    {
        collection[i] = collection[i-1];
        --i;
    }

    collection[i] = newProduct;
    ++(*n);

    return newProduct;
}

Product searchProductInCollection
(
    Product collection[], 
    const uInt N, 
    uInt productId
)
{
    uInt left = 0;
    uInt right = N - 1;
    uInt mid;

    while (left <= right)
    {
        mid = left + ((right - left) >> 1);

        if (collection[mid]->id == productId)
        {
            return collection[mid];
        }
        else if (collection[mid]->id > productId)
        {
            right = mid - 1;
        }
        else 
        {
            left = mid + 1;
        }
    }

    return NULL;
}

Product removeProductInCollection
(
    Product collection[],
    uInt *n,
    String productName
)
{
    uInt left = 0;
    uInt right =  *n - 1;
    uInt mid;
    int result = -1;
    Product product = NULL;

    while (left <= right)
    {
        mid = left + ((right - left) >> 1);
        result = strcmp(collection[mid]->name, productName);

        if (result == 0)
        {
            break;
        }
        else if (result > 0)
        {
            right = mid - 1;
        }
        else 
        {
            left = mid + 1;
        }
    }

    if (result == 0)
    {
        product = collection[mid];

        for (int i = mid+1; i < *n; ++i)
        {
            collection[i-1] = collection[i];
        }

        --(*n);
    }


    return product;
}

