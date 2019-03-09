#ifndef __EASY_PLUGPAG_H__
#define __EASY_PLUGPAG_H__

#include <stdlib.h>

#include "libPPPagSeguro/PPPagSeguro.h"

#define EASY_PLUGPAG_ERROR_BASE                     0xCABECA * -1
#define EASY_PLUGPAG_ERROR_NULL_PLUGPAG_INSTANCE  EASY_PLUGPAG_ERROR_BASE - 1
#define EASY_PLUGPAG_ERROR_NULL_PAYMENT_DATA      EASY_PLUGPAG_ERROR_BASE - 2
#define EASY_PLUGPAG_ERROR_MALFORMED_PAYMENT_DATA EASY_PLUGPAG_ERROR_BASE - 3
#define EASY_PLUGPAG_ERROR_NULL_RESULT_OUTPUT     EASY_PLUGPAG_ERROR_BASE - 4


struct PlugPagApplicationData
{
    tyAppName appName;
    tyAppVersion appVersion;
};


struct PlugPagPaymentData
{
    enPPPSPaymentMethod paymentMethod;
    enPPPSInstallmentType installmentType;
    unsigned int installments;
    tyAmount amount;
    tyUserReference userReference;
};


struct PlugPag
{
    int (*pay)(struct PlugPag *plugpag, struct PlugPagPaymentData *paymentData, stPPPSTransactionResult *result);
    int (*voidPayment)(struct PlugPag *plugpag, stPPPSTransactionResult *result);
    int (*getLastApprovedTransaction)(struct PlugPag *plugpag, stPPPSTransactionResult *result);

    void *__internal;
};


struct PlugPag *PlugPag(tyComPort port, struct PlugPagApplicationData *applicationData);
struct PlugPagApplicationData *PlugPagApplicationData(tyAppName appName, tyAppVersion appVersion);
struct PlugPagPaymentData *PlugPagPaymentData(enPPPSPaymentMethod paymentMethod, enPPPSInstallmentType installmentType, unsigned int installments, tyAmount amount, tyUserReference userReference);

#endif