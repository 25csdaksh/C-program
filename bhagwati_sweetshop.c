#include <stdio.h>
#include <string.h>

int main()
{
    int mainChoice, itemChoice;
    float weight, price, total, grandTotal = 0;
    int quantity;
    char again;

    // Summary storage
    char name[100][50];
    float wt[100];
    int qty[100];
    float amt[100];
    int count = 0;

    printf("\n=========== WELCOME TO SWEET SHOP ===========\n");

    do
    {
        printf("\nMain Menu:");
        printf("\n1. Sweet");
        printf("\n2. Farshan");
        printf("\n3. Snacks");
        printf("\nEnter your choice: ");
        scanf("%d", &mainChoice);

        price = 0;

        if(mainChoice == 1)
        {
            printf("\n--- SWEETS ---");
            printf("\n1. Kaju Katli - 2000/kg");
            printf("\n2. Ras Malai - 1500/kg");
            printf("\n3. Rasgulla - 1200/kg");
            printf("\n4. Mohanthal - 1000/kg");
            printf("\n5. Dry Fruit Sweet - 2500/kg");
            printf("\n6. Jalebi - 800/kg");
            printf("\n7. Laddu - 900/kg");

            printf("\nEnter item choice: ");
            scanf("%d", &itemChoice);

            switch(itemChoice)
            {
                case 1: price=2000; strcpy(name[count],"Kaju Katli"); break;
                case 2: price=1500; strcpy(name[count],"Ras Malai"); break;
                case 3: price=1200; strcpy(name[count],"Rasgulla"); break;
                case 4: price=1000; strcpy(name[count],"Mohanthal"); break;
                case 5: price=2500; strcpy(name[count],"Dry Fruit Sweet"); break;
                case 6: price=800; strcpy(name[count],"Jalebi"); break;
                case 7: price=900; strcpy(name[count],"Laddu"); break;
                default: printf("Invalid item!\n"); continue;
            }
        }
        else if(mainChoice == 2)
        {
            printf("\n--- FARSHAN ---");
            printf("\n1. Dhokla - 300/kg");
            printf("\n2. Gathiya - 400/kg");
            printf("\n3. Fafda - 450/kg");
            printf("\n4. Patra - 350/kg");
            printf("\n5. Kachori - 500/kg");
            printf("\n6. Samosa - 600/kg");

            printf("\nEnter item choice: ");
            scanf("%d", &itemChoice);

            switch(itemChoice)
            {
                case 1: price=300; strcpy(name[count],"Dhokla"); break;
                case 2: price=400; strcpy(name[count],"Gathiya"); break;
                case 3: price=450; strcpy(name[count],"Fafda"); break;
                case 4: price=350; strcpy(name[count],"Patra"); break;
                case 5: price=500; strcpy(name[count],"Kachori"); break;
                case 6: price=600; strcpy(name[count],"Samosa"); break;
                default: printf("Invalid item!\n"); continue;
            }
        }
        else if(mainChoice == 3)
        {
            printf("\n--- SNACKS ---");
            printf("\n1. Bhakharwadi - 350/kg");
            printf("\n2. Fulwadi - 400/kg");
            printf("\n3. Aloo Sev - 300/kg");
            printf("\n4. Ratlami Sev - 450/kg");
            printf("\n5. Dry Kachori - 500/kg");
            printf("\n6. Farshpuri - 550/kg");

            printf("\nEnter item choice: ");
            scanf("%d", &itemChoice);

            switch(itemChoice)
            {
                case 1: price=350; strcpy(name[count],"Bhakharwadi"); break;
                case 2: price=400; strcpy(name[count],"Fulwadi"); break;
                case 3: price=300; strcpy(name[count],"Aloo Sev"); break;
                case 4: price=450; strcpy(name[count],"Ratlami Sev"); break;
                case 5: price=500; strcpy(name[count],"Dry Kachori"); break;
                case 6: price=550; strcpy(name[count],"Farshpuri"); break;
                default: printf("Invalid item!\n"); continue;
            }
        }
        else
        {
            printf("Invalid main choice!\n");
            continue;
        }

        printf("Enter weight (grams): ");
        scanf("%f", &weight);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        wt[count] = weight;
        qty[count] = quantity;

        total = (price * weight / 1000) * quantity;
        amt[count] = total;

        grandTotal += total;
        count++;

        printf("Item added! Total = %.2f Rs\n", total);

        printf("\nDo you want to add more items? (y/n): ");
        scanf(" %c", &again);

    } while(again == 'y' || again == 'Y');


    // ===== BILL SUMMARY =====
    float gstRate = 5.0;
    float gstAmount = (grandTotal * gstRate) / 100;
    float finalAmount = grandTotal + gstAmount;

    printf("\n\n================ BILL SUMMARY ================\n");
    printf("%-20s %-10s %-10s %-10s\n","Product","Weight","Qty","Total");

    for(int i=0; i<count; i++)
    {
        printf("%-20s %-10.2f %-10d %-10.2f\n",
               name[i], wt[i], qty[i], amt[i]);
    }

    printf("------------------------------------------------\n");
    printf("Subtotal      = %.2f Rs\n", grandTotal);
    printf("GST (5%%)       = %.2f Rs\n", gstAmount);
    printf("Final Amount  = %.2f Rs\n", finalAmount);
    printf("================================================\n");

    printf("\nThank You! Visit Again!\n");

    return 0;
}
