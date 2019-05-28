// --------------------------------------
// A La Carte Entertainment Application
// --------------------------------------

#include <stdio.h>
#include "receipt.h"


int main(void)
{
    struct ReceiptInfo rec = { 0 };
    int daypart, option;

    printf("\n*** A LA CARTE Cash Mashine ***\n\n");

    do {
        printf("Choose the option:\n");
        printf("-----------------\n");
        printf("1. New receipt\n");
        printf("2. Show the last receipt\n");
        printf("0. Exit\n\n");
        printf(">selection: ");
        scanf("%d", &option);

        
        switch (option) {
            case 0:
                printf("\nExiting Cash Mashine program. Bye!\n");
                break;
            case 1:
                calcCoverCharge(&rec);
                calcTicketCharge(&rec, &daypart);
                calcDiscount(&rec);
                calcSnackCharge(&rec);
                calcValletCharge(&rec, &daypart);

                // Need to make a "display" function that shows the itemized receipt
                printf("\n\nRECEIPT\n");
                printf("-------\n");
                printf("    Cover Charges: $%10.2lf\n", rec.coverCharge);
                printf("   Ticket Charges: $%10.2lf\n", rec.ticketCharge);
                printf("    Snack Charges: $%10.2lf\n", rec.snackCharge);
                printf("   Vallet Charges: $%10.2lf\n", rec.valletCharge + rec.valletTip);
                printf("   ---------------------------\n");
                printf("        Sub-Total: $%10.2lf\n", rec.coverCharge + rec.ticketCharge + rec.snackCharge + rec.valletCharge + rec.valletTip);
                printf("        Discounts: $%10.2lf\n", rec.discount * (-1));
                printf("        ----------------------\n");
                printf("            Total: $%10.2lf\n\n", rec.coverCharge + rec.ticketCharge + rec.snackCharge + rec.valletCharge + rec.valletTip - rec.discount);
                break;
            case 2:
                printf("\nRECEIPT\n");
                printf("-------\n");
                printf("    Cover Charges: $%10.2lf\n", rec.coverCharge);
                printf("   Ticket Charges: $%10.2lf\n", rec.ticketCharge);
                printf("    Snack Charges: $%10.2lf\n", rec.snackCharge);
                printf("   Vallet Charges: $%10.2lf\n", rec.valletCharge + rec.valletTip);
                printf("   ---------------------------\n");
                printf("        Sub-Total: $%10.2lf\n", rec.coverCharge + rec.ticketCharge + rec.snackCharge + rec.valletCharge + rec.valletTip);
                printf("        Discounts: $%10.2lf\n", rec.discount * (-1));
                printf("        ----------------------\n");
                printf("            Total: $%10.2lf\n\n", rec.coverCharge + rec.ticketCharge + rec.snackCharge + rec.valletCharge + rec.valletTip - rec.discount);
                break;
            default:
                printf("Incorrect option. Please try again.\n\n");
                break;
        }
    } while (option != 0);

    return 0;
}