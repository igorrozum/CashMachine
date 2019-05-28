// --------------------------------------
// Receipt Header File
// --------------------------------------

#ifndef RECEIPTS__H


struct ReceiptInfo
{
    int people;
    double coverCharge;
    double ticketCharge;
    double discount;
    double snackCharge;
    double valletCharge;
    double valletTip;
};

void calcCoverCharge(struct ReceiptInfo *receipt);
void calcTicketCharge(struct ReceiptInfo *receipt, int *daypart);
void calcDiscount(struct ReceiptInfo *receipt);
void calcSnackCharge(struct ReceiptInfo *receipt);
void calcValletCharge(struct ReceiptInfo *receipt, int *daypart);

#endif // !RECEIPTS__H