#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
#define PMSIZE 3

typedef struct{
	char promoCode[17];
	float discount;
}PromoCode;

typedef struct{
	char prodID[9];
	char prodName[33];
	float unitPrice;
	int qty;
}Product;

typedef struct{
	Product prodList[50];
	int lastProd; /* When ProdList is empty, lastProd is -1 */
}ProdList;

typedef struct nodeItem{
	Product item;
	struct nodeItem* nextItem;
}nodeItem, *SList;

typedef struct{
	float VAT;	/*12% of totalPrice */
	float discount; /* Value is equal to 0.00 if no Promo code has been used */
	float totalPrice;
}Invoice;

typedef struct{
	SList sCart;
	int numItems;
	char promoCode[17]; /* default value is "" (empty string) */
	Invoice receipt;
}Cart;

void pause(void);

/* Problem 1 */
/* Instructions: 
	1) displayProdList() - Partial Code is provided. The function will display the details of ALL the products in the 
						   passed ProductList.
	2) initProdList() - The function will initialize the passed ProductList.
	3) populateProdList() - Partial Code is provided. The function will populate the passed ProductList with ALL the
							products in the array of products defined within the function.
*/
void displayProdList(ProdList);
void initProdList(ProdList*);
void populateProdList(ProdList*);

/* Problem 2 */
/* Instructions:
	1) initCart() - The function will initialize the passed Cart to be empty.
	2) genReceipt() - The function will calculate for the values of the receipt for the passed Cart.
	3) displayCart() - Partial Code is provided. The function will display all the details of the Cart based on the format
					   given in the output screenshot. Note: The function will call genReceipt to calculate the Receipt details
					   of the given Cart before these details are displayed.
	4) addToCart() - The function will check if the passed productID exists in the ProdList and if there is enough stocks 
					 in the ProdList to accomodate your purchase. If both of these conditions are met, it will insert
					 the item into the FIRST node of your sCart. Update the necessary fields upon insertion. 
					 Note: Machine Problems will not normally say what the necessary fields are. But you can ask me if
					 	   you give up. :)
*/
Cart initCart(void);
void genReceipt(Cart*, PromoCode[], char[]);
void displayCart(Cart*);
void addToCart(Cart*, ProdList*, char[], int);

/* Problem 3 */
/* Instructions:
	1) returnItem() - The function will check if the passed productID exists in the passed Cart. If it does, also check if
					  the qty to be returned does not exceed the quantity you've purchased based on you Cart info. If both
					  these conditions are met, subtract the quantity for that item in your Cart. Also, if the quantity
					  for that item reaches ZERO, delete the item from your cart. Update the necessary fields upon successful
					  item return.
					  Note: Machine Problems will not normally say what the necessary fields are. But you can ask me if
					 	    you give up. :)
*/
void returnItem(Cart*, ProdList*, char[], int);

int main(void)
{
	ProdList groceryStore;
	Cart myCart;
	char prod1[] = "FR000001";
	char prod2[] = "FR000010";
	char prod3[] = "VG000001";

	puts("PROBLEM 1");
	/* Instructions:
		1) Initialize variable groceryStore. 
		2) Populate groceryStore with products.
		3) Display the products in the groceryStore.
		4) Call the pause() function.
	*/

	initProdList(&groceryStore);
	populateProdList(&groceryStore);
	displayProdList(groceryStore);
	pause();
	
	puts("PROBLEM 2");
	/*1) Initialize variable myCart.
		2) Call function addToCart passing prod1 as the string parameter, and 55 as the int parameter.
		3) Call function addToCart passing prod1 as the string parameter, and 10 as the int parameter.
		4) Call function addToCart passing prod2 as the string parameter, and 50 as the int parameter.
		5) Call function addToCart passing prod3 as the string parameter, and 10 as the int parameter.
		6) Display the contents of myCart.
		7) Display the products in the groceryStore.
		8) Call the pause() function.
	*/
	
	myCart = initCart();
	addToCart(&myCart, &groceryStore, prod1, 55);
	addToCart(&myCart, &groceryStore, prod1, 10);
//	addToCart(&myCart, &groceryStore, prod1, 30); this is just a test case based on the Problem 2 Output 
	addToCart(&myCart, &groceryStore, prod2, 50);
	addToCart(&myCart, &groceryStore, prod3, 10);
	displayCart(&myCart);
	displayProdList(groceryStore);
	pause();
	
	puts("PROBLEM 3");
	/* Instructions:
		1) Call function returnItem passing prod1 as the string parameter, and 20 as the int parameter.
		2) Call function returnItem passing prod1 as the string parameter, and 40 as the int parameter.
		3) Call function returnItem passing prod2 as the string parameter, and 10 as the int parameter.
		4) Call function returnItem passing prod3 as the string parameter, and 10 as the int parameter.
		5) Display the contents of myCart.
		6) Display the products in the groceryStore.
		7) Call the pause() function.
	*/

	returnItem(&myCart, &groceryStore, prod1, 20);
	returnItem(&myCart, &groceryStore, prod1, 40);
	returnItem(&myCart, &groceryStore, prod2, 10);
	returnItem(&myCart, &groceryStore, prod3, 10);
	displayCart(&myCart);
	displayProdList(groceryStore);
	pause();
	return 0;
}

void pause(void)
{
	printf("\n\nPress any key to continue...");
	getch();
	system("CLS");
}


/* Instructions: 
	1) displayProdList() - Partial Code is provided. The function will display the details of ALL the products in the 
						   passed ProductList. */
void displayProdList(ProdList PL)
{
	printf("\n\n<-- Product List -->\n");
	printf("%-10s", "ProdID");
	printf("%-15s", "ProdName");
	printf("%-10s", "Price");
	printf("%-10s", "Stocks");
	
	int i;
	for(i = 0; i < PL.lastProd; i++){
		printf("\n%-9s %-14s %-9.2f %-10d", PL.prodList[i].prodID, PL.prodList[i].prodName, PL.prodList[i].unitPrice, PL.prodList[i].qty);
	}
}

/* 2) initProdList() - The function will initialize the passed ProductList. */
void initProdList(ProdList* PL)
{
	PL->lastProd = -1;
}

/* 	3) populateProdList() - Partial Code is provided. The function will populate the passed ProductList with ALL the
							products in the array of products defined within the function. */
void populateProdList(ProdList* PL)
{
	int i;
	Product items[] = {{"FR000001", "Apple", 32.00, 60},
					   {"FR000002", "Orange", 25.00, 50},
					   {"FR000003", "Pineapple", 66.00, 30},
					   {"FR000004", "Durian", 45.00, 25},
					   {"FR000005", "Squash", 54.00, 40},
					   {"FR000006", "Grapes", 12.00, 150},
					   {"FR000007", "Mango", 33.00, 80},
					   {"FR000008", "Cherries", 7.00, 150},
					   {"VG000001", "Cabbage", 24.00, 40},
					   {"VG000002", "Broccoli", 18.00, 60},
					  };
					  
	for(i = 0; i < SIZE; i++){
		PL->prodList[i] = items[i];
	}	
	PL->lastProd = i; // 9th index -> VG000002 
}

/*	1) initCart() - The function will initialize the passed Cart to be empty. */
Cart initCart(void)
{
	Cart newCart = {NULL, 0, "", {0.00, 0.00, 0.00}};
	return newCart;
}

/* 	2) genReceipt() - The function will calculate for the values of the receipt for the passed Cart. */
void genReceipt(Cart* C, PromoCode promoList[], char promoCode[])
{
	float lineItemPrice, totalLinePrice;
	
	/* PROMO
		NEWCUSTOMER - 0.33
		FRIYAY - 0.15
		HURRAYFORPAYDAY - 0.20
	*/
	
	SList trav;
	for(trav = C->sCart; trav != NULL; trav = trav->nextItem){
		// line Item Price = qty*Price
		lineItemPrice = trav->item.qty*trav->item.unitPrice;
		// Total Line Price = total amount of Line Item Price
		totalLinePrice += lineItemPrice;
	}

	// Search the passed promoCode if it is available in the promoList
	int i;
	for(i = 0; i < PMSIZE && strcmp(promoList[i].promoCode, promoCode) != 0; i++){}
	
	if(i < PMSIZE) {
		// Set the discount inside cart
		strcpy(C->promoCode, promoList[i].promoCode); 
		// Discount =  totalPrice*discPrice
		C->receipt.discount = totalLinePrice*promoList[i].discount;
	}
	
	// Total Price = Total Line Price - Discount
	C->receipt.totalPrice = totalLinePrice - C->receipt.discount;
	// VAT = .12*totalPrice
	C->receipt.VAT = C->receipt.totalPrice*.12;
}

/* 3) displayCart() - Partial Code is provided. The function will display all the details of the Cart based on the format
					   given in the output screenshot. Note: The function will call genReceipt to calculate the Receipt details
					   of the given Cart before these details are displayed. */
void displayCart(Cart* C)
{
	PromoCode promos[PMSIZE] = {{"NEWCUSTOMER", 0.33},
						  {"FRIYAY", 0.15},
						  {"HURRAYFORPAYDAY", 0.20}
						 };
	
	// calling genReceipt to make calculations					 
	genReceipt(C, promos, "NEWCUSTOMER");
	
	printf("\n\n<-- Your Cart -->\n");
	printf("%-10s", "ProdID");
	printf("%-15s", "ProdName");
	printf("%-10s", "Price");
	printf("%-10s", "Qty");
	printf("%-15s", "Line Item Price");	/* Line item Price is the product of qty and price */
	
	SList trav;
	for(trav = C->sCart; trav != NULL; trav = trav->nextItem){
		float lineItemPrice = trav->item.qty*trav->item.unitPrice;
		printf("\n%-10s%-15s%-10.2f%-10d%-15.2f", trav->item.prodID, trav->item.prodName, trav->item.unitPrice, trav->item.qty, lineItemPrice);
	}
	
	printf("\n\nNumber of items: %d\n\nPromo Code: %s\nVAT: %.2f\nDiscount: %.2f\nTotal Price: %.2f\n", C->numItems, C->promoCode, C->receipt.VAT, C->receipt.discount, C->receipt.totalPrice);
}

/*	4) addToCart() - The function will check if the passed productID exists in the ProdList and if there is enough stocks 
					 in the ProdList to accomodate your purchase. If both of these conditions are met, it will insert
					 the item into the FIRST node of your sCart. Update the necessary fields upon insertion. 
					 Note: Machine Problems will not normally say what the necessary fields are. But you can ask me if
					 	   you give up. :) */
void addToCart(Cart* C, ProdList* PL, char prodID[], int itemQty)
{
	//1. Check if the passed prodID is valid, else prompt a message
	int i;
	for(i = 0; i <= PL->lastProd && strcmp(prodID, PL->prodList[i].prodID) != 0; i++){}
	
	if(i <= PL->lastProd){
		//2. Check it has enought stock
		if(itemQty <= PL->prodList[i].qty){
			// Additional: if the cart has the existing prodID, add the qty
			SList trav;
			for(trav = C->sCart; trav != NULL && strcmp(prodID, trav->item.prodID) != 0; trav = trav->nextItem){}
			
			if(trav != NULL) {
				// Only add the qty to the existing qty in the Cart and reduce the socks inside the groceryStore
				trav->item.qty += itemQty;
				PL->prodList[i].qty -=itemQty;
			} else {
				//3. insert to cart
				SList temp;
				temp = (SList) malloc(sizeof(nodeItem));
			
				if(temp != NULL){
					temp->item = PL->prodList[i];
					temp->item.qty = itemQty;
					temp->nextItem = C->sCart;
					C->sCart = temp;
				
					// Reduce the stocks inside the groceryStore
					PL->prodList[i].qty -= itemQty;
					// Increment the number of elements inside the cart
					C->numItems++;
					// Get the total line		
				} else {
					printf("Initialization of temp unsuccessful");
				}
			}
		} else {
			printf("\nNot enough stocks to complete the transaction\n");
		}
	} else {
		printf("\nProduct ID [%s] not found]\n", prodID);
	}
}

/* 1) returnItem() - The function will check if the passed productID exists in the passed Cart. If it does, also check if
					  the qty to be returned does not exceed the quantity you've purchased based on you Cart info. If both
					  these conditions are met, subtract the quantity for that item in your Cart. Also, if the quantity
					  for that item reaches ZERO, delete the item from your cart. Update the necessary fields upon successful
					  item return.
					  Note: Machine Problems will not normally say what the necessary fields are. But you can ask me if
					 	    you give up. :)
*/
void returnItem(Cart* C, ProdList* PL, char prodID[], int qty)
{	
	// Additional: Get the prodID for the qty to be added if there are any stocks to be returned
	int i;
	for(i = 0; i <= PL->lastProd && strcmp(prodID, PL->prodList[i].prodID) != 0; i++){}
	
	// 1. Check if the passed prodID exists in passed Cart
	SList *trav, temp;
	for(trav = &C->sCart; *trav != NULL && strcmp(prodID, (*trav)->item.prodID) != 0; trav = &(*trav)->nextItem){}
	
	// 2. Check if the qty does not exceed what is already inside the cart
	if(*trav != NULL){
		if(qty <= (*trav)->item.qty){
			// 3. Subtract the qty in the cart
			(*trav)->item.qty -= qty;
			PL->prodList[i].qty += qty;
			// 4. If the qty reaches zero, remove item from the cart
			if((*trav)->item.qty == 0){
				temp = *trav;
				*trav = temp->nextItem;
				free(temp);
			}
		} else {
			printf("\nYou cannot return a quantity greater than your purchase.\n");
		}
	} else {
		printf("\nYou are returning an item that isn't in your cart.\n");
	}
}
