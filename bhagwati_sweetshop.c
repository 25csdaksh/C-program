#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float weight;   // in grams
    int quantity;
    float total;
} Item;

void printHeader() {
    printf("\n============================================\n");
    printf("         🍬 WELCOME TO SWEET SHOP 🍬         \n");
    printf("============================================\n");
}

void printMenu() {
    printf("\nMain Menu:\n");
    printf("1. Sweets\n");
    printf("2. Farshan\n");
    printf("3. Snacks\n");
    printf("Enter your choice: ");
}

void printCategory(int choice) {
    if (choice == 1) {
        printf("\n--- SWEETS ---\n");
        printf("1. Kaju Katli - 2000/kg\n");
        printf("2. Ras Malai - 1500/kg\n");
        printf("3. Rasgulla - 1200/kg\n");
        printf("4. Mohanthal - 1000/kg\n");
        printf("5. Dry Fruit Sweet - 2500/kg\n");
        printf("6. Jalebi - 800/kg\n");
        printf("7. Laddu - 900/kg\n");
    } else if (choice == 2) {
        printf("\n--- FARSHAN ---\n");
        printf("1. Dhokla - 300/kg\n");
        printf("2. Gathiya - 400/kg\n");
        printf("3. Fafda - 450/kg\n");
        printf("4. Patra - 350/kg\n");
        printf("5. Kachori - 500/kg\n");
        printf("6. Samosa - 600/kg\n");
    } else if (choice == 3) {
        printf("\n--- SNACKS ---\n");
        printf("1. Bhakharwadi - 350/kg\n");
        printf("2. Fulwadi - 400/kg\n");
        printf("3. Aloo Sev - 300/kg\n");
        printf("4. Ratlami Sev - 450/kg\n");
        printf("5. Dry Kachori - 500/kg\n");
        printf("6. Farshpuri - 550/kg\n");
    }
}

float getPrice(int mainChoice, int itemChoice, char *itemName) {
    switch(mainChoice) {
        case 1: // Sweets
            switch(itemChoice) {
                case 1: strcpy(itemName,"Kaju Katli"); return 2000;
                case 2: strcpy(itemName,"Ras Malai"); return 1500;
                case 3: strcpy(itemName,"Rasgulla"); return 1200;
                case 4: strcpy(itemName,"Mohanthal"); return 1000;
                case 5: strcpy(itemName,"Dry Fruit Sweet"); return 2500;
                case 6: strcpy(itemName,"Jalebi"); return 800;
                case 7: strcpy(itemName,"Laddu"); return 900;
            }
            break;
        case 2: // Farshan
            switch(itemChoice) {
                case 1: strcpy(itemName,"Dhokla"); return 300;
                case 2: strcpy(itemName,"Gathiya"); return 400;
                case 3: strcpy(itemName,"Fafda"); return 450;
                case 4: strcpy(itemName,"Patra"); return 350;
                case 5: strcpy(itemName,"Kachori"); return 500;
                case 6: strcpy(itemName,"Samosa"); return 600;
            }
            break;
        case 3: // Snacks
            switch(itemChoice) {
                case 1: strcpy(itemName,"Bhakharwadi"); return 350;
                case 2: strcpy(itemName,"Fulwadi"); return 400;
                case 3: strcpy(itemName,"Aloo Sev"); return 300;
                case 4: strcpy(itemName,"Ratlami Sev"); return 450;
                case 5: strcpy(itemName,"Dry Kachori"); return 500;
                case 6: strcpy(itemName,"Farshpuri"); return 550;
            }
            break;
    }
    return 0;
}

void printBill(Item items[], int count, float grandTotal) {
    float gstRate = 5.0;
    float gstAmount = (grandTotal * gstRate) / 100;
    float finalAmount = grandTotal + gstAmount;

    printf("\n\n================ BILL SUMMARY ================\n");
    printf("%-20s %-10s %-10s %-10s\n","Product","Weight(g)","Qty","Total(Rs)");

    for(int i=0; i<count; i++) {
        printf("%-20s %-10.2f %-10d %-10.2f\n",
               items[i].name, items[i].weight, items[i].quantity, items[i].total);
    }

    printf("------------------------------------------------\n");
    printf("Subtotal      = %.2f Rs\n", grandTotal);
    printf("GST (5%%)       = %.2f Rs\n", gstAmount);
    printf("Final Amount  = %.2f Rs\n", finalAmount);
    printf("================================================\n");
    printf("\n✨ Thank You! Visit Again! ✨\n");
}

int main() {
    Item items[MAX_ITEMS];
    int count = 0;
    float grandTotal = 0;
    char again;

    printHeader();

    do {
        int mainChoice, itemChoice;
        float weight, price;
        int quantity;

        printMenu();
        scanf("%d", &mainChoice);

        if(mainChoice < 1 || mainChoice > 3) {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        printCategory(mainChoice);
        printf("Enter item choice: ");
        scanf("%d", &itemChoice);

        price = getPrice(mainChoice, itemChoice, items[count].name);
        if(price == 0) {
            printf("Invalid item!\n");
            continue;
        }

        printf("Enter weight (grams): ");
        scanf("%f", &weight);
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        items[count].weight = weight;
        items[count].quantity = quantity;
        items[count].total = (price * weight / 1000) * quantity;

        grandTotal += items[count].total;
        count++;

        printf("✅ Item added! Total = %.2f Rs\n", items[count-1].total);

        printf("\nDo you want to add more items? (y/n): ");
        scanf(" %c", &again);

    } while(again == 'y' || again == 'Y');

    printBill(items, count, grandTotal);

    return 0;
}
