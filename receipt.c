// --------------------------------------
// Receipt Source Code File
// --------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "receipt.h"

#define COVERCHILD 0.50
#define COVERADULT 5.50
#define COVERSENIOR 1.25

#define TICKETMUSMAT 88.00
#define TICKETMUSEVE 175.00
#define TICKETTHEMAT 78.00
#define TICKETTHEEVE 165.00

#define DISKTWO 5
#define DISKTHREE 10
#define DISKFOUR 15
#define DISKFIVE 20

#define NONALCDRINK 3.00
#define ALCDRINK 7.75
#define CANDY 2.5

#define PARKMATSTD 15.00
#define PARKMATVIP 25.00
#define PARKEVESTD 20.00
#define PARKEVEVIP 30.00


void calcCoverCharge(struct ReceiptInfo* receipt)
{
    int childs, adults, seniors;

    receipt->coverCharge = 0;
    receipt->people = 0;

    printf("\nHow many people under 18? ");
    scanf("%d", &childs);
    receipt->people = childs;
    receipt->coverCharge += childs * COVERCHILD;
    printf("How many people above 65? ");
    scanf("%d", &seniors);
    receipt->people += seniors;
    receipt->coverCharge += seniors * COVERSENIOR;
    printf("How many people between 18 and 65? ");
    scanf("%d", &adults);
    receipt->people += adults;
}

void calcTicketCharge(struct ReceiptInfo *receipt, int *daypart)
{
    int choice;

    printf("\nType of entertainment\n");
    printf("---------------------\n");
    printf("1. Musical\n");
    printf("2. Theatre\n\n");
    printf(">selection: ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("\nDay part\n");
        printf("--------\n");
        printf("1. Matinee\n");
        printf("2. Evening\n\n");
        printf(">selection: ");
        scanf("%d", &choice);
        if (choice == 1) {
            *daypart = 1;
            receipt->ticketCharge = receipt->people * TICKETMUSMAT;
        }
        else {
            *daypart = 2;
            receipt->ticketCharge = receipt->people * TICKETMUSEVE;
        }
    } else {
        printf("\nDay part\n");
        printf("--------\n");
        printf("1. Matinee\n");
        printf("2. Evening\n\n");
        printf(">selection: ");
        scanf("%d", &choice);
        if (choice == 1) {
            *daypart = 1;
            receipt->ticketCharge = receipt->people * TICKETTHEMAT;
        }
        else {
            *daypart = 2;
            receipt->ticketCharge = receipt->people * TICKETTHEEVE;
        }
    }
}

void calcDiscount(struct ReceiptInfo *receipt)
{
    receipt->discount = 0.00;

    if (receipt->people == 2) {
        receipt->discount = receipt->ticketCharge *  DISKTWO / 100;
    } else if (receipt->people == 3) {
        receipt->discount = receipt->ticketCharge * DISKTHREE / 100;
    } else if (receipt->people == 4) {
        receipt->discount = receipt->ticketCharge * DISKFOUR / 100;
    } else if (receipt->people >= 5) {
        receipt->discount = receipt->ticketCharge * DISKFIVE / 100;
    }
}

void calcSnackCharge(struct ReceiptInfo *receipt)
{
    int choice, nonAlc, alc, candies;

    receipt->snackCharge = 0.00;

    printf("\nAny snacks?\n");
    printf("-----------\n");
    printf("1. Yes\n");
    printf("2. No\n\n");
    printf(">selection: ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("\nHow many Non-Alcoholic drinks? >_");
        scanf("%d", &nonAlc);
        receipt->snackCharge = (nonAlc * NONALCDRINK);
        printf("How many Alcoholic drinks? >_");
        scanf("%d", &alc);
        receipt->snackCharge += (alc * ALCDRINK);
        printf("How many Candy items? >_");
        scanf("%d", &candies);
        receipt->snackCharge += (candies * CANDY);
    }
}

void calcValletCharge(struct ReceiptInfo *receipt, int *daypart)
{
    int choice;

    receipt->valletCharge = 0.00;
    receipt->valletTip = 0.00;

    printf("\nValet Parking used?\n");
    printf("-------------------\n");
    printf("1. Yes\n");
    printf("2. No\n\n");
    printf(">selection: ");
    scanf("%d", &choice);
    if (choice == 1) {
        if (*daypart == 1) {
            printf("\nStandart of VIP?\n");
            printf("----------------\n");
            printf("1. Standart\n");
            printf("2. VIP\n\n");
            printf(">selection: ");
            scanf("%d", &choice);
            if (choice == 1) {
                receipt->valletCharge = PARKMATSTD;
            } else {
                receipt->valletCharge = PARKMATVIP;
            }
        } else {
            printf("\nStandart of VIP?\n");
            printf("----------------\n");
            printf("1. Standart\n");
            printf("2. VIP\n\n");
            printf(">selection: ");
            scanf("%d", &choice);
            if (choice == 1) {
                receipt->valletCharge = PARKEVESTD;
            } else {
                receipt->valletCharge = PARKEVEVIP;
            }
        }
        printf("\nAny tips?\n");
        printf("---------\n");
        printf("1. Yes\n");
        printf("2. No\n\n");
        printf(">selection: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nAmount: ");
            scanf("%lf", &receipt->valletTip);
        }
    }
}

