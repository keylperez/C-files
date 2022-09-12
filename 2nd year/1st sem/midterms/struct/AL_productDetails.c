#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 150

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

typedef struct ProductList
{
	Product listItems[MAX];
	int count;
} ProductList;

typedef struct WarehouseDetails
{
	char warehouseName[32];
	char warehouseID[3];
	char address[128];
} WarehouseDetails;

typedef struct Warehouse
{
	WarehouseDetails details;
	ProductList inventory;
} Warehouse;

typedef struct WarehouseList
{
	Warehouse wh[2];
	int count;
} WarehouseList;

typedef struct TransferOrder
{
	char srcWarehouseID[3];
	char destWarehouseID[3];
	char prodID[9];
	int lineItemQty; /* number of items to be transfered*/
} TO;

typedef struct TOList
{
	TO listOrders[MAX];
	int count;
} TOList;

void displayProduct(Product prod);
void initProdList(ProductList *inv);
void addProduct(ProductList *inv, Product newProd);
void populateWarehouseInventoryBL(ProductList *inv);
void populateWarehouseInventoryKL(ProductList *inv);
void displayProdList(ProductList inv);
int *getMostStocks(WarehouseList whList, char prodId[]);
ProductList getLowStocks(ProductList inv, int threshold);
Product *deleteProdsUnderQuota(ProductList *PL, int quota);
int findProduct(ProductList inv, char id[]);
int findWarehouse(WarehouseList whList, char ID[]);
void clearStocks(ProductList *inv);
void initTOList(TOList *list);
void insertTO(TOList *list, TO newOrder);
TOList generateTOListForLowStocks(WarehouseList whList, char whID[], int threshold);
void transferStocks(TO order, WarehouseList *whList);
void execTOList(TOList list, WarehouseList *whList);

int main(void)
{
	WarehouseList whList = {{{"Blankedale", "BL", "Germany"}, {{"Kilboure", "KL", "Berlin"}}}, 2};
	populateWarehouseInventoryBL(&whList);

	return 0;
}

void displayProduct(Product prod)
{
	char buffer[300];
	printf("ID: %s\nName: %s\nPrice: %.2f\nShelf: %s\nStocks: %d\nItems Sold: %d\n\n",
		   prod.details.prodID, prod.details.prodName, prod.price, prod.details.shelf,
		   prod.stocks, prod.itemsSold);
}

//Initializes the passed ProductList to be empty.
void initProdList(ProductList *inv)
{
}

//Adds a newProd to the end of the ProductList if the product does not exist, or if there is still space.
//Print an error message if the product exists.
//Print an error message if there is no more space to add new products.
void addProduct(ProductList *inv, Product newProd)
{
}

void populateWarehouseInventoryBL(ProductList *inv)
{
	int i;
	Product items[5] = {
		{{
			 "00000001",
			 "Fishing Rod",
			 "BL01",
		 },
		 150.00,
		 7,
		 8},
		{{
			 "00000002",
			 "Fishing Hook",
			 "BL02",
		 },
		 25.00,
		 5,
		 30},
		{{
			 "00000003",
			 "Fish Lure",
			 "BL03",
		 },
		 35.00,
		 120,
		 50},
		{{
			 "00000004",
			 "Fish Bait",
			 "BL04",
		 },
		 5.00,
		 1000,
		 100},
		{{
			 "00000005",
			 "Fishing Net",
			 "BL05",
		 },
		 200.00,
		 9,
		 3}};

	for (i = 0; i < 5; i++)
	{
		addProduct(inv, items[i]);
	}
}

void populateWarehouseInventoryKL(ProductList *inv)
{
	int i;
	Product items[5] = {
		{{
			 "00000001",
			 "Fishing Rod",
			 "BL01",
		 },
		 150.00,
		 21,
		 8},
		{{
			 "00000002",
			 "Fishing Hook",
			 "BL02",
		 },
		 25.00,
		 27,
		 30},
		{{
			 "00000003",
			 "Fish Lure",
			 "BL03",
		 },
		 35.00,
		 12,
		 50},
		{{
			 "00000004",
			 "Fish Bait",
			 "BL04",
		 },
		 5.00,
		 300,
		 100},
		{{
			 "00000005",
			 "Fishing Net",
			 "BL05",
		 },
		 200.00,
		 5,
		 3}};

	for (i = 0; i < 5; i++)
	{
		addProduct(inv, items[i]);
	}
}

void displayProdList(ProductList inv)
{
	int i;
	printf("Product List: \n");
	for (i = 0; i < inv.count; i++)
	{
		displayProduct(inv.listItems[i]);
	}
}

//The function will check each warehouse in whList for stocks of a certain prodID.
//The function will return an array of 2 integers:
//The 1st integer holds the INDEX of the Warehouse in whList which contains the MOST stocks.
//The 2nd integer holds the INDEX of the Product in the Warehouse which contains the most stocks.
int *getMostStocks(WarehouseList whList, char prodId[])
{
}

//The function will receive a ProductList, and return a new ProductList containing any Product that has stocks
//below the passed threshold.
ProductList getLowStocks(ProductList inv, int threshold)
{
}

//The function will delete ALL Products in the passed ProductList whose itemsSold are below the quota.
//Return an array of Products containing all the deleted items.
Product *deleteProdsUnderQuota(ProductList *PL, int quota)
{
}

//The function  will check if the passed PRODUCT id exists in the given ProductList. Return the index if found, else -1.
int findProduct(ProductList inv, char id[])
{
}

//The function will check if the passed WAREHOUSE id exists in the given Warehouse List. Return the index if found, else -1.
int findWarehouse(WarehouseList whList, char ID[])
{
}

//The function will set to 0 all the stocks of each Product in a given ProductList.
void clearStocks(ProductList *inv)
{
}

//The function will initialize a given Transfer Order List to empty.
void initTOList(TOList *list)
{
}

//The function will insert a new TRANSFER ORDER into the end of the TOList.
void insertTO(TOList *list, TO newOrder)
{
}

//Given a WarehouseList and a certain whID
//The function will go through the ProductList of the passed whID, and check for the low stock products.
//For each LOW STOCK Product, it will check the other warehouses in whList, and see if they have more stocks
//than the current warehouse. If they do, then insert into a TOList, a new transfer order for transfering stock
//from that warehouse(SRC), to the current warehouse(DEST). The transferred amount should be half of the
//current stock of the SRC warehouse. Return the TOList to the calling function.
TOList generateTOListForLowStocks(WarehouseList whList, char whID[], int threshold)
{
}

//Given a transfer order and a warehouseList
//The function will execute the passed Transfer Order, thereby formally transfering stock from
//the SRC warehouse to the DEST warehouse as highlight in the passed TO.
void transferStocks(TO order, WarehouseList *whList)
{
}

void execTOList(TOList list, WarehouseList *whList)
{
	int i;

	for (i = 0; i < list.count; i++)
	{
		transferStocks(list.listOrders[i], whList);
	}
}