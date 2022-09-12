//This problem was created by Cris Militante for CSIT1201 Second Semester AY 2019-2020
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRSIZE 10

typedef struct ProductDetails
{
    char prodID[9];
    char prodName[32];
    char shelf[5];
} ProductDetails;

typedef struct Product
{
    ProductDetails details;
    float price;
    int stocks;
    int itemsSold;
} Product;

void displayProduct(Product prod)
{
    char buffer[300];
    sprintf(buffer, "ID: %s\nName: %s\nPrice: %.2f\nShelf: %s\nStocks: %d\nItems Sold: %d\n\n",
            prod.details.prodID, prod.details.prodName, prod.price, prod.details.shelf,
            prod.stocks, prod.itemsSold);
    puts(buffer);
}

Product *getAllShelfItems(Product P[], char shelf[])
{

    /*This function receives an array of products and a specific shelf. The function goes through the entire array of products and returns to the calling function all the Products that can be found on that shelf. */

    int i, x;
    for (i = 0; i < (sizeof(shelf) / 4); i++)
    {
        for (x = 0; x < (sizeof(P) / 4); x++)
        {
            if (shelf[i] == P[x])
            {
            }
        }
    }
}

Product *getLowStockItems(Product P[], int threshold);
/* This function receives an array of products and an int threshold. The function goes through the entire array of products and returns to the calling function all the Products that have stocks equal to or below the threshold. */

int findProd(Product P[], char id[]);
/* This function receives an array of products an a specific id. The function goes through the entire array of products and checks if there is a product in the list with the same id as the parameter passed. If there is, return the index of that product. Else, return 0 */

void updatePrices(Product P[], int salesThresh, float multiplier);
/* This function receives an array of products, a sales threshold, and a multiplier. The function goes through the entire array of products, and updates the prices of ALL products who’s sales go BEYOND the sales threshold. New price is calculated as follows: price * multiplier. */

void setVals(Product *product) {}

int main()
{
    char arr[] = "upper";
    Product product;
    Product *ptrProd;
    setVals(&product);
    displayProduct(product);
    ptrProd = getAllShelfItems(product.details.shelf, arr);
    return 0;
}