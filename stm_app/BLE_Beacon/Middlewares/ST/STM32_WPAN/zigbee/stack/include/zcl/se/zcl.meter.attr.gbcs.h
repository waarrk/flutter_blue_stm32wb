/* Copyright [2009 - 2021] Exegin Technologies Limited. All rights reserved. */

#include "zcl/se/zcl.meter.h"

#ifndef ZCL_METER_ATTR_GBCS_LIST_NAME
#define ZCL_METER_ATTR_GBCS_LIST_NAME               zcl_meter_server_gbcs_attr_list
#endif

#ifdef ZCL_METER_ATTR_GBCS_CALLBACK
#ifndef ZCL_METER_ATTR_GBCS_FLAGS
/* If callback is not NULL, Should define one or both of ZCL_ATTR_FLAG_CB_READ | ZCL_ATTR_FLAG_CB_WRITE */
#error "If ZCL_METER_ATTR_GBCS_CALLBACK defined, must also define ZCL_METER_ATTR_GBCS_FLAGS. E.g. ZCL_ATTR_FLAG_CB_READ | ZCL_ATTR_FLAG_CB_WRITE"
#endif
#else
#define ZCL_METER_ATTR_GBCS_CALLBACK                NULL
#endif

#ifndef ZCL_METER_ATTR_GBCS_FLAGS
#define ZCL_METER_ATTR_GBCS_FLAGS                   ZCL_ATTR_FLAG_REPORTABLE
#endif

/* Minimum reporting interval for all attributes. If an attribute changes, its
 * report will be sent at least this much time since the last report.
 * This value should be less than the sleep cycle for a sleepy Meter device, so
 * when the Meter wakes up and calls ZbZclAttrReportKick, any modified attributes
 * since the last wake cycle will be reported on. */
#ifndef ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN
#define ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN        900U /* 15 minutes, assuming a sleepy cycle of 30 minutes. */
#endif

/* Maximum reporting interval for attributes that should never change once
 * configured by application. Only report if they do change. */
#ifndef ZCL_METER_ATTR_GBCS_REPORT_INTVL_STATIC
#define ZCL_METER_ATTR_GBCS_REPORT_INTVL_STATIC     ZCL_ATTR_REPORT_MAX_INTVL_CHANGE /* change only */
#endif

/* Maximum reporting interval for attributes that rarely change, but good to
 * keep the COMMs Hub up to date in case a previous report was missed.
 * If your application wants to only report when these attributes change,
 * redefine this to ZCL_ATTR_REPORT_MAX_INTVL_CHANGE, and these extra redundant
 * reports won't be sent. */
#ifndef ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG
#define ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG       ZCL_ATTR_REPORT_MAX_INTVL_MAXIMUM /* ~18 hours */
#endif

/* Maximum reporting interval for attributes that may change more frequently, but
 * good to keep the COMMs Hub up to date, in case a previous report was missed.
 * If your application wants to only report when these attributes change,
 * redefine this to ZCL_ATTR_REPORT_MAX_INTVL_CHANGE, and these extra redundant
 * reports won't be sent. */
#ifndef ZCL_METER_ATTR_GBCS_REPORT_INTVL_SHORT
#define ZCL_METER_ATTR_GBCS_REPORT_INTVL_SHORT      14400U /* 4 hours */
#endif

/*-----------------------------------------------------------------------------
 * GBCS Required Attribute List
 *-----------------------------------------------------------------------------
 */
/* Use this as-is to append the GBCS Metering Attributes to the
 * Metering Server. Or use this as a template to create the
 * attribute's as your application requires. */

/* NOTE: Use ZCL_ATTR_LIST_LEN(list) to get the length of the list (number of attributes) */

const struct ZbZclAttrT ZCL_METER_ATTR_GBCS_LIST_NAME[] = {
    /* CurrentNoTierBlock1-4SummationDelivered */
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(0, 1), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(0, 2), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(0, 3), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(0, 4), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },

    /* CurrentTier1Block1-4SummationDelivered */
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(1, 1), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(1, 2), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(1, 3), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(1, 4), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },

    /* CurrentTier2Block1-4SummationDelivered */
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(2, 1), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(2, 2), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(2, 3), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(2, 4), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },

    /* CurrentTier3Block1-4SummationDelivered */
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(3, 1), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(3, 2), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(3, 3), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(3, 4), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },

    /* CurrentTier4Block1-4SummationDelivered */
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(4, 1), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(4, 2), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(4, 3), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(4, 4), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },

    /* CurrentTier5Block1-4SummationDelivered */
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(5, 1), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(5, 2), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(5, 3), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(5, 4), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },

    /* CurrentTier6Block1-4SummationDelivered */
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(6, 1), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(6, 2), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(6, 3), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(6, 4), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },

    /* CurrentTier7Block1-4SummationDelivered */
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(7, 1), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(7, 2), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(7, 3), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(7, 4), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },

    /* Misc */
    {
        ZCL_METER_SVR_ATTR_MULTIPLIER, ZCL_DATATYPE_UNSIGNED_24BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_DIVISOR, ZCL_DATATYPE_UNSIGNED_24BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        /* NOTE: not ZCL_DATATYPE_ENUMERATION_8BIT as one would expect. Zero-day bug in Spec. */
        ZCL_METER_SVR_ATTR_DEVICE_TYPE, ZCL_DATATYPE_BITMAP_8BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_STATIC}
    },
    {
        ZCL_METER_SVR_ATTR_SITE_ID, ZCL_DATATYPE_STRING_OCTET, ZCL_METER_ATTR_GBCS_FLAGS, 32,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_STATIC}
    },
    {
        ZCL_METER_SVR_ATTR_SUMMATION_FORMAT, ZCL_DATATYPE_BITMAP_8BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    /* DemandFormatting is not listed, but providing since
     * InstantaneousDemand is included. */
    {
        ZCL_METER_SVR_ATTR_DEMAND_FORMAT, ZCL_DATATYPE_BITMAP_8BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    /* HistoricalConsumptionFormatting is not listed, but providing since
     * various consumption attributes are included. */
    {
        ZCL_METER_SVR_ATTR_HISTORICAL_CONSUMPTION_FORMAT, ZCL_DATATYPE_BITMAP_8BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_UNIT_OF_MEASURE, ZCL_DATATYPE_ENUMERATION_8BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_CUSTOMER_ID_NUMBER, ZCL_DATATYPE_STRING_OCTET, ZCL_METER_ATTR_GBCS_FLAGS, 24,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_STATIC}
    },
    {
        ZCL_METER_SVR_ATTR_INSTANTANEOUS_DEMAND, ZCL_DATATYPE_SIGNED_24BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_SHORT}
    },
    {
        ZCL_METER_SVR_ATTR_BILL_DELIV_TRAILING_DIGIT, ZCL_DATATYPE_BITMAP_8BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_BTD_DELIV, ZCL_DATATYPE_UNSIGNED_32BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_AMBIENT_CONSUMPTION_INDICATOR, ZCL_DATATYPE_ENUMERATION_8BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_METER_STATUS, ZCL_DATATYPE_BITMAP_8BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_SHORT}
    },
    {
        ZCL_METER_SVR_ATTR_CURSUM_DELIV, ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_SHORT}
    },
    {
        ZCL_METER_SVR_ATTR_CURSUM_RECV, ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_SHORT}
    },
    {
        ZCL_METER_SVR_ATTR_SUPPLY_STATUS, ZCL_DATATYPE_ENUMERATION_8BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_SHORT}
    },

    /* CurrentDayConsumption */
    {
        ZCL_METER_SVR_ATTR_CURDAY_DM_DELIV, ZCL_DATATYPE_UNSIGNED_24BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_SHORT}
    },
    /* PreviousDayConsumption */
    {
        ZCL_METER_SVR_ATTR_PRVDAY_DM_DELIV, ZCL_DATATYPE_UNSIGNED_24BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    /* PreviousDay[2..8]Consumption */
    {
        ZCL_METER_SVR_ATTR_PRVDAY_N_DELIV_CONSUMP(2), ZCL_DATATYPE_UNSIGNED_24BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_PRVDAY_N_DELIV_CONSUMP(3), ZCL_DATATYPE_UNSIGNED_24BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_PRVDAY_N_DELIV_CONSUMP(4), ZCL_DATATYPE_UNSIGNED_24BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_PRVDAY_N_DELIV_CONSUMP(5), ZCL_DATATYPE_UNSIGNED_24BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_PRVDAY_N_DELIV_CONSUMP(6), ZCL_DATATYPE_UNSIGNED_24BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_PRVDAY_N_DELIV_CONSUMP(7), ZCL_DATATYPE_UNSIGNED_24BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_PRVDAY_N_DELIV_CONSUMP(8), ZCL_DATATYPE_UNSIGNED_24BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },

    /* CurrentMonthConsumptionDelivered and
     * PreviousMonthConsumption and
     * PreviousMonth[2..13]Consumption*/
    {
        ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(0), ZCL_DATATYPE_UNSIGNED_32BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_SHORT}
    },
    {
        ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(1), ZCL_DATATYPE_UNSIGNED_32BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(2), ZCL_DATATYPE_UNSIGNED_32BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(3), ZCL_DATATYPE_UNSIGNED_32BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(4), ZCL_DATATYPE_UNSIGNED_32BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(5), ZCL_DATATYPE_UNSIGNED_32BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(6), ZCL_DATATYPE_UNSIGNED_32BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(7), ZCL_DATATYPE_UNSIGNED_32BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(8), ZCL_DATATYPE_UNSIGNED_32BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(9), ZCL_DATATYPE_UNSIGNED_32BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(10), ZCL_DATATYPE_UNSIGNED_32BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(11), ZCL_DATATYPE_UNSIGNED_32BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(12), ZCL_DATATYPE_UNSIGNED_32BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(13), ZCL_DATATYPE_UNSIGNED_32BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },

    /* CurrentWeekConsumptionDelivered and
     * PreviousWeekConsumption and
     * PreviousWeek[2..5]Consumption */
    {
        ZCL_METER_SVR_ATTR_WEEK_N_CONSUMP_DELIV(0), ZCL_DATATYPE_UNSIGNED_24BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_SHORT}
    },
    {
        ZCL_METER_SVR_ATTR_WEEK_N_CONSUMP_DELIV(1), ZCL_DATATYPE_UNSIGNED_24BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_WEEK_N_CONSUMP_DELIV(2), ZCL_DATATYPE_UNSIGNED_24BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_WEEK_N_CONSUMP_DELIV(3), ZCL_DATATYPE_UNSIGNED_24BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_WEEK_N_CONSUMP_DELIV(4), ZCL_DATATYPE_UNSIGNED_24BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_WEEK_N_CONSUMP_DELIV(5), ZCL_DATATYPE_UNSIGNED_24BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },

    /* CurrentTier1-9SummationDelivered */
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(1), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(2), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(3), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(4), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(5), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(6), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(7), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(8), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(9), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },

    /* CurrentTier10-19SummationDelivered */
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(10), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(11), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(12), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(13), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(14), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(15), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(16), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(17), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(18), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(19), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },

    /* CurrentTier20-29SummationDelivered */
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(20), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(21), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(22), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(23), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(24), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(25), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(26), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(27), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(28), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(29), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },

    /* CurrentTier30-39SummationDelivered */
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(30), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(31), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(32), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(33), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(34), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(35), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(36), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(37), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(38), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(39), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },

    /* CurrentTier40-48SummationDelivered */
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(40), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(41), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(42), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(43), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(44), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(45), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(46), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(47), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
    {
        ZCL_METER_SVR_ATTR_TIERN_DELIV(48), ZCL_DATATYPE_UNSIGNED_48BIT, ZCL_METER_ATTR_GBCS_FLAGS, 0,
        ZCL_METER_ATTR_GBCS_CALLBACK, {0, 0},
        {ZCL_METER_ATTR_GBCS_REPORT_INTVL_MIN, ZCL_METER_ATTR_GBCS_REPORT_INTVL_LONG}
    },
};
