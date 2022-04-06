/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
* \addtogroup Robot-Device Robot-Device
* @{
*/

/**
\file Robot-DeviceObjects
\author ET9300Utilities.ApplicationHandler (Version 1.6.1.0) | EthercatSSC@beckhoff.com

\brief Robot-Device specific objects<br>
\brief NOTE : This file will be overwritten if a new object dictionary is generated!<br>
*/

#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
#define PROTO
#else
#define PROTO extern
#endif
/******************************************************************************
*                    Object 0x1600 : OUT_GENERIC process data mapping
******************************************************************************/
/**
* \addtogroup 0x1600 0x1600 | OUT_GENERIC process data mapping
* @{
* \brief Object 0x1600 (OUT_GENERIC process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x7000.1<br>
* SubIndex 2 - Reference to 0x7000.2<br>
* SubIndex 3 - Reference to 0x7000.3<br>
* SubIndex 4 - Reference to 0x7000.4<br>
* SubIndex 5 - Reference to 0x7000.5<br>
* SubIndex 6 - Reference to 0x7000.6<br>
* SubIndex 7 - Reference to 0x7000.7<br>
* SubIndex 8 - Reference to 0x7000.8<br>
* SubIndex 9 - Reference to 0x7000.9<br>
* SubIndex 10 - Reference to 0x7000.10<br>
* SubIndex 11 - Reference to 0x7000.11<br>
* SubIndex 12 - Reference to 0x7000.12<br>
* SubIndex 13 - Reference to 0x7000.13<br>
* SubIndex 14 - Reference to 0x7000.14<br>
* SubIndex 15 - Reference to 0x7000.15<br>
* SubIndex 16 - Reference to 0x7000.16<br>
* SubIndex 17 - Reference to 0x7000.17<br>
* SubIndex 18 - Reference to 0x7000.18<br>
* SubIndex 19 - Reference to 0x7000.19<br>
* SubIndex 20 - Reference to 0x7000.20<br>
* SubIndex 21 - Reference to 0x7000.21<br>
* SubIndex 22 - Reference to 0x7000.22<br>
* SubIndex 23 - Reference to 0x7000.23<br>
* SubIndex 24 - Reference to 0x7000.24<br>
* SubIndex 25 - Reference to 0x7000.25<br>
* SubIndex 26 - Reference to 0x7000.26<br>
* SubIndex 27 - Reference to 0x7000.27<br>
* SubIndex 28 - Reference to 0x7000.28<br>
* SubIndex 29 - Reference to 0x7000.29<br>
* SubIndex 30 - Reference to 0x7000.30<br>
* SubIndex 31 - Reference to 0x7000.31<br>
* SubIndex 32 - Reference to 0x7000.32<br>
* SubIndex 33 - Reference to 0x7000.33<br>
* SubIndex 34 - Reference to 0x7000.34<br>
* SubIndex 35 - Reference to 0x7000.35<br>
* SubIndex 36 - Reference to 0x7000.36<br>
* SubIndex 37 - Reference to 0x7000.37<br>
* SubIndex 38 - Reference to 0x7000.38<br>
* SubIndex 39 - Reference to 0x7000.39<br>
* SubIndex 40 - Reference to 0x7000.40<br>
* SubIndex 41 - Reference to 0x7000.41<br>
* SubIndex 42 - Reference to 0x7000.42<br>
* SubIndex 43 - Reference to 0x7000.43<br>
* SubIndex 44 - Reference to 0x7000.44<br>
* SubIndex 45 - Reference to 0x7000.45<br>
* SubIndex 46 - Reference to 0x7000.46<br>
* SubIndex 47 - Reference to 0x7000.47<br>
* SubIndex 48 - Reference to 0x7000.48<br>
* SubIndex 49 - Reference to 0x7000.49<br>
* SubIndex 50 - Reference to 0x7000.50<br>
* SubIndex 51 - Reference to 0x7000.51<br>
* SubIndex 52 - Reference to 0x7000.52<br>
* SubIndex 53 - Reference to 0x7000.53<br>
* SubIndex 54 - Reference to 0x7000.54<br>
* SubIndex 55 - Reference to 0x7000.55<br>
* SubIndex 56 - Reference to 0x7000.56<br>
* SubIndex 57 - Reference to 0x7000.57<br>
* SubIndex 58 - Reference to 0x7000.58<br>
* SubIndex 59 - Reference to 0x7000.59<br>
* SubIndex 60 - Reference to 0x7000.60<br>
* SubIndex 61 - Reference to 0x7000.61<br>
* SubIndex 62 - Reference to 0x7000.62<br>
* SubIndex 63 - Reference to 0x7000.63<br>
* SubIndex 64 - Reference to 0x7000.64<br>
* SubIndex 65 - Reference to 0x7000.65<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1600[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x7000.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - Reference to 0x7000.2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - Reference to 0x7000.3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex4 - Reference to 0x7000.4 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex5 - Reference to 0x7000.5 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex6 - Reference to 0x7000.6 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex7 - Reference to 0x7000.7 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex8 - Reference to 0x7000.8 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex9 - Reference to 0x7000.9 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex10 - Reference to 0x7000.10 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex11 - Reference to 0x7000.11 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex12 - Reference to 0x7000.12 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex13 - Reference to 0x7000.13 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex14 - Reference to 0x7000.14 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex15 - Reference to 0x7000.15 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex16 - Reference to 0x7000.16 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex17 - Reference to 0x7000.17 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex18 - Reference to 0x7000.18 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex19 - Reference to 0x7000.19 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex20 - Reference to 0x7000.20 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex21 - Reference to 0x7000.21 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex22 - Reference to 0x7000.22 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex23 - Reference to 0x7000.23 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex24 - Reference to 0x7000.24 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex25 - Reference to 0x7000.25 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex26 - Reference to 0x7000.26 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex27 - Reference to 0x7000.27 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex28 - Reference to 0x7000.28 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex29 - Reference to 0x7000.29 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex30 - Reference to 0x7000.30 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex31 - Reference to 0x7000.31 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex32 - Reference to 0x7000.32 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex33 - Reference to 0x7000.33 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex34 - Reference to 0x7000.34 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex35 - Reference to 0x7000.35 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex36 - Reference to 0x7000.36 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex37 - Reference to 0x7000.37 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex38 - Reference to 0x7000.38 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex39 - Reference to 0x7000.39 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex40 - Reference to 0x7000.40 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex41 - Reference to 0x7000.41 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex42 - Reference to 0x7000.42 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex43 - Reference to 0x7000.43 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex44 - Reference to 0x7000.44 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex45 - Reference to 0x7000.45 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex46 - Reference to 0x7000.46 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex47 - Reference to 0x7000.47 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex48 - Reference to 0x7000.48 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex49 - Reference to 0x7000.49 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex50 - Reference to 0x7000.50 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex51 - Reference to 0x7000.51 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex52 - Reference to 0x7000.52 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex53 - Reference to 0x7000.53 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex54 - Reference to 0x7000.54 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex55 - Reference to 0x7000.55 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex56 - Reference to 0x7000.56 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex57 - Reference to 0x7000.57 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex58 - Reference to 0x7000.58 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex59 - Reference to 0x7000.59 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex60 - Reference to 0x7000.60 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex61 - Reference to 0x7000.61 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex62 - Reference to 0x7000.62 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex63 - Reference to 0x7000.63 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex64 - Reference to 0x7000.64 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex65 - Reference to 0x7000.65 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1600[] = "OUT_GENERIC process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000"
"SubIndex 005\000"
"SubIndex 006\000"
"SubIndex 007\000"
"SubIndex 008\000"
"SubIndex 009\000"
"SubIndex 010\000"
"SubIndex 011\000"
"SubIndex 012\000"
"SubIndex 013\000"
"SubIndex 014\000"
"SubIndex 015\000"
"SubIndex 016\000"
"SubIndex 017\000"
"SubIndex 018\000"
"SubIndex 019\000"
"SubIndex 020\000"
"SubIndex 021\000"
"SubIndex 022\000"
"SubIndex 023\000"
"SubIndex 024\000"
"SubIndex 025\000"
"SubIndex 026\000"
"SubIndex 027\000"
"SubIndex 028\000"
"SubIndex 029\000"
"SubIndex 030\000"
"SubIndex 031\000"
"SubIndex 032\000"
"SubIndex 033\000"
"SubIndex 034\000"
"SubIndex 035\000"
"SubIndex 036\000"
"SubIndex 037\000"
"SubIndex 038\000"
"SubIndex 039\000"
"SubIndex 040\000"
"SubIndex 041\000"
"SubIndex 042\000"
"SubIndex 043\000"
"SubIndex 044\000"
"SubIndex 045\000"
"SubIndex 046\000"
"SubIndex 047\000"
"SubIndex 048\000"
"SubIndex 049\000"
"SubIndex 050\000"
"SubIndex 051\000"
"SubIndex 052\000"
"SubIndex 053\000"
"SubIndex 054\000"
"SubIndex 055\000"
"SubIndex 056\000"
"SubIndex 057\000"
"SubIndex 058\000"
"SubIndex 059\000"
"SubIndex 060\000"
"SubIndex 061\000"
"SubIndex 062\000"
"SubIndex 063\000"
"SubIndex 064\000"
"SubIndex 065\000\377";
#endif //#ifdef _OBJD_

#ifndef _ROBOT_DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x7000.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x7000.2 */
UINT32 SI3; /* Subindex3 - Reference to 0x7000.3 */
UINT32 SI4; /* Subindex4 - Reference to 0x7000.4 */
UINT32 SI5; /* Subindex5 - Reference to 0x7000.5 */
UINT32 SI6; /* Subindex6 - Reference to 0x7000.6 */
UINT32 SI7; /* Subindex7 - Reference to 0x7000.7 */
UINT32 SI8; /* Subindex8 - Reference to 0x7000.8 */
UINT32 SI9; /* Subindex9 - Reference to 0x7000.9 */
UINT32 SI10; /* Subindex10 - Reference to 0x7000.10 */
UINT32 SI11; /* Subindex11 - Reference to 0x7000.11 */
UINT32 SI12; /* Subindex12 - Reference to 0x7000.12 */
UINT32 SI13; /* Subindex13 - Reference to 0x7000.13 */
UINT32 SI14; /* Subindex14 - Reference to 0x7000.14 */
UINT32 SI15; /* Subindex15 - Reference to 0x7000.15 */
UINT32 SI16; /* Subindex16 - Reference to 0x7000.16 */
UINT32 SI17; /* Subindex17 - Reference to 0x7000.17 */
UINT32 SI18; /* Subindex18 - Reference to 0x7000.18 */
UINT32 SI19; /* Subindex19 - Reference to 0x7000.19 */
UINT32 SI20; /* Subindex20 - Reference to 0x7000.20 */
UINT32 SI21; /* Subindex21 - Reference to 0x7000.21 */
UINT32 SI22; /* Subindex22 - Reference to 0x7000.22 */
UINT32 SI23; /* Subindex23 - Reference to 0x7000.23 */
UINT32 SI24; /* Subindex24 - Reference to 0x7000.24 */
UINT32 SI25; /* Subindex25 - Reference to 0x7000.25 */
UINT32 SI26; /* Subindex26 - Reference to 0x7000.26 */
UINT32 SI27; /* Subindex27 - Reference to 0x7000.27 */
UINT32 SI28; /* Subindex28 - Reference to 0x7000.28 */
UINT32 SI29; /* Subindex29 - Reference to 0x7000.29 */
UINT32 SI30; /* Subindex30 - Reference to 0x7000.30 */
UINT32 SI31; /* Subindex31 - Reference to 0x7000.31 */
UINT32 SI32; /* Subindex32 - Reference to 0x7000.32 */
UINT32 SI33; /* Subindex33 - Reference to 0x7000.33 */
UINT32 SI34; /* Subindex34 - Reference to 0x7000.34 */
UINT32 SI35; /* Subindex35 - Reference to 0x7000.35 */
UINT32 SI36; /* Subindex36 - Reference to 0x7000.36 */
UINT32 SI37; /* Subindex37 - Reference to 0x7000.37 */
UINT32 SI38; /* Subindex38 - Reference to 0x7000.38 */
UINT32 SI39; /* Subindex39 - Reference to 0x7000.39 */
UINT32 SI40; /* Subindex40 - Reference to 0x7000.40 */
UINT32 SI41; /* Subindex41 - Reference to 0x7000.41 */
UINT32 SI42; /* Subindex42 - Reference to 0x7000.42 */
UINT32 SI43; /* Subindex43 - Reference to 0x7000.43 */
UINT32 SI44; /* Subindex44 - Reference to 0x7000.44 */
UINT32 SI45; /* Subindex45 - Reference to 0x7000.45 */
UINT32 SI46; /* Subindex46 - Reference to 0x7000.46 */
UINT32 SI47; /* Subindex47 - Reference to 0x7000.47 */
UINT32 SI48; /* Subindex48 - Reference to 0x7000.48 */
UINT32 SI49; /* Subindex49 - Reference to 0x7000.49 */
UINT32 SI50; /* Subindex50 - Reference to 0x7000.50 */
UINT32 SI51; /* Subindex51 - Reference to 0x7000.51 */
UINT32 SI52; /* Subindex52 - Reference to 0x7000.52 */
UINT32 SI53; /* Subindex53 - Reference to 0x7000.53 */
UINT32 SI54; /* Subindex54 - Reference to 0x7000.54 */
UINT32 SI55; /* Subindex55 - Reference to 0x7000.55 */
UINT32 SI56; /* Subindex56 - Reference to 0x7000.56 */
UINT32 SI57; /* Subindex57 - Reference to 0x7000.57 */
UINT32 SI58; /* Subindex58 - Reference to 0x7000.58 */
UINT32 SI59; /* Subindex59 - Reference to 0x7000.59 */
UINT32 SI60; /* Subindex60 - Reference to 0x7000.60 */
UINT32 SI61; /* Subindex61 - Reference to 0x7000.61 */
UINT32 SI62; /* Subindex62 - Reference to 0x7000.62 */
UINT32 SI63; /* Subindex63 - Reference to 0x7000.63 */
UINT32 SI64; /* Subindex64 - Reference to 0x7000.64 */
UINT32 SI65; /* Subindex65 - Reference to 0x7000.65 */
} OBJ_STRUCT_PACKED_END
TOBJ1600;
#endif //#ifndef _ROBOT_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1600 OUT_GENERICProcessDataMapping0x1600
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
={65,0x70000101,0x70000201,0x70000301,0x70000401,0x70000501,0x70000601,0x70000701,0x70000801,0x70000901,0x70000A01,0x70000B01,0x70000C01,0x70000D01,0x70000E01,0x70000F01,0x70001001,0x70001110,0x70001210,0x70001308,0x70001408,0x70001508,0x70001608,0x70001708,0x70001808,0x70001908,0x70001A08,0x70001B08,0x70001C08,0x70001D08,0x70001E08,0x70001F08,0x70002008,0x70002108,0x70002208,0x70002308,0x70002408,0x70002508,0x70002608,0x70002708,0x70002808,0x70002908,0x70002A08,0x70002B08,0x70002C08,0x70002D08,0x70002E08,0x70002F08,0x70003008,0x70003108,0x70003208,0x70003310,0x70003410,0x70003510,0x70003608,0x70003708,0x70003808,0x70003908,0x70003A08,0x70003B08,0x70003C08,0x70003D08,0x70003E10,0x70003F10,0x70004010,0x70004110}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A00 : IN_GENERIC process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A00 0x1A00 | IN_GENERIC process data mapping
* @{
* \brief Object 0x1A00 (IN_GENERIC process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6000.1<br>
* SubIndex 2 - Reference to 0x6000.2<br>
* SubIndex 3 - Reference to 0x6000.3<br>
* SubIndex 4 - Reference to 0x6000.4<br>
* SubIndex 5 - Reference to 0x6000.5<br>
* SubIndex 6 - Reference to 0x6000.6<br>
* SubIndex 7 - Reference to 0x6000.7<br>
* SubIndex 8 - Reference to 0x6000.8<br>
* SubIndex 9 - Reference to 0x6000.9<br>
* SubIndex 10 - Reference to 0x6000.10<br>
* SubIndex 11 - Reference to 0x6000.11<br>
* SubIndex 12 - Reference to 0x6000.12<br>
* SubIndex 13 - Reference to 0x6000.13<br>
* SubIndex 14 - Reference to 0x6000.14<br>
* SubIndex 15 - Reference to 0x6000.15<br>
* SubIndex 16 - Reference to 0x6000.16<br>
* SubIndex 17 - Reference to 0x6000.17<br>
* SubIndex 18 - Reference to 0x6000.18<br>
* SubIndex 19 - Reference to 0x6000.19<br>
* SubIndex 20 - Reference to 0x6000.20<br>
* SubIndex 21 - Reference to 0x6000.21<br>
* SubIndex 22 - Reference to 0x6000.22<br>
* SubIndex 23 - Reference to 0x6000.23<br>
* SubIndex 24 - Reference to 0x6000.24<br>
* SubIndex 25 - Reference to 0x6000.25<br>
* SubIndex 26 - Reference to 0x6000.26<br>
* SubIndex 27 - Reference to 0x6000.27<br>
* SubIndex 28 - Reference to 0x6000.28<br>
* SubIndex 29 - Reference to 0x6000.29<br>
* SubIndex 30 - Reference to 0x6000.30<br>
* SubIndex 31 - Reference to 0x6000.31<br>
* SubIndex 32 - Reference to 0x6000.32<br>
* SubIndex 33 - Reference to 0x6000.33<br>
* SubIndex 34 - Reference to 0x6000.34<br>
* SubIndex 35 - Reference to 0x6000.35<br>
* SubIndex 36 - Reference to 0x6000.36<br>
* SubIndex 37 - Reference to 0x6000.37<br>
* SubIndex 38 - Reference to 0x6000.38<br>
* SubIndex 39 - Reference to 0x6000.39<br>
* SubIndex 40 - Reference to 0x6000.40<br>
* SubIndex 41 - Reference to 0x6000.41<br>
* SubIndex 42 - Reference to 0x6000.42<br>
* SubIndex 43 - Reference to 0x6000.43<br>
* SubIndex 44 - Reference to 0x6000.44<br>
* SubIndex 45 - Reference to 0x6000.45<br>
* SubIndex 46 - Reference to 0x6000.46<br>
* SubIndex 47 - Reference to 0x6000.47<br>
* SubIndex 48 - Reference to 0x6000.48<br>
* SubIndex 49 - Reference to 0x6000.49<br>
* SubIndex 50 - Reference to 0x6000.50<br>
* SubIndex 51 - Reference to 0x6000.51<br>
* SubIndex 52 - Reference to 0x6000.52<br>
* SubIndex 53 - Reference to 0x6000.53<br>
* SubIndex 54 - Reference to 0x6000.54<br>
* SubIndex 55 - Reference to 0x6000.55<br>
* SubIndex 56 - Reference to 0x6000.56<br>
* SubIndex 57 - Reference to 0x6000.57<br>
* SubIndex 58 - Reference to 0x6000.58<br>
* SubIndex 59 - Reference to 0x6000.59<br>
* SubIndex 60 - Reference to 0x6000.60<br>
* SubIndex 61 - Reference to 0x6000.61<br>
* SubIndex 62 - Reference to 0x6000.62<br>
* SubIndex 63 - Reference to 0x6000.63<br>
* SubIndex 64 - Reference to 0x6000.64<br>
* SubIndex 65 - Reference to 0x6000.65<br>
* SubIndex 66 - Reference to 0x6000.66<br>
* SubIndex 67 - Reference to 0x6000.67<br>
* SubIndex 68 - Reference to 0x6000.68<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A00[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x6000.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - Reference to 0x6000.2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - Reference to 0x6000.3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex4 - Reference to 0x6000.4 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex5 - Reference to 0x6000.5 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex6 - Reference to 0x6000.6 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex7 - Reference to 0x6000.7 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex8 - Reference to 0x6000.8 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex9 - Reference to 0x6000.9 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex10 - Reference to 0x6000.10 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex11 - Reference to 0x6000.11 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex12 - Reference to 0x6000.12 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex13 - Reference to 0x6000.13 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex14 - Reference to 0x6000.14 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex15 - Reference to 0x6000.15 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex16 - Reference to 0x6000.16 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex17 - Reference to 0x6000.17 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex18 - Reference to 0x6000.18 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex19 - Reference to 0x6000.19 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex20 - Reference to 0x6000.20 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex21 - Reference to 0x6000.21 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex22 - Reference to 0x6000.22 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex23 - Reference to 0x6000.23 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex24 - Reference to 0x6000.24 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex25 - Reference to 0x6000.25 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex26 - Reference to 0x6000.26 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex27 - Reference to 0x6000.27 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex28 - Reference to 0x6000.28 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex29 - Reference to 0x6000.29 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex30 - Reference to 0x6000.30 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex31 - Reference to 0x6000.31 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex32 - Reference to 0x6000.32 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex33 - Reference to 0x6000.33 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex34 - Reference to 0x6000.34 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex35 - Reference to 0x6000.35 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex36 - Reference to 0x6000.36 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex37 - Reference to 0x6000.37 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex38 - Reference to 0x6000.38 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex39 - Reference to 0x6000.39 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex40 - Reference to 0x6000.40 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex41 - Reference to 0x6000.41 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex42 - Reference to 0x6000.42 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex43 - Reference to 0x6000.43 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex44 - Reference to 0x6000.44 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex45 - Reference to 0x6000.45 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex46 - Reference to 0x6000.46 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex47 - Reference to 0x6000.47 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex48 - Reference to 0x6000.48 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex49 - Reference to 0x6000.49 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex50 - Reference to 0x6000.50 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex51 - Reference to 0x6000.51 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex52 - Reference to 0x6000.52 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex53 - Reference to 0x6000.53 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex54 - Reference to 0x6000.54 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex55 - Reference to 0x6000.55 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex56 - Reference to 0x6000.56 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex57 - Reference to 0x6000.57 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex58 - Reference to 0x6000.58 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex59 - Reference to 0x6000.59 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex60 - Reference to 0x6000.60 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex61 - Reference to 0x6000.61 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex62 - Reference to 0x6000.62 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex63 - Reference to 0x6000.63 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex64 - Reference to 0x6000.64 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex65 - Reference to 0x6000.65 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex66 - Reference to 0x6000.66 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex67 - Reference to 0x6000.67 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex68 - Reference to 0x6000.68 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A00[] = "IN_GENERIC process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000"
"SubIndex 005\000"
"SubIndex 006\000"
"SubIndex 007\000"
"SubIndex 008\000"
"SubIndex 009\000"
"SubIndex 010\000"
"SubIndex 011\000"
"SubIndex 012\000"
"SubIndex 013\000"
"SubIndex 014\000"
"SubIndex 015\000"
"SubIndex 016\000"
"SubIndex 017\000"
"SubIndex 018\000"
"SubIndex 019\000"
"SubIndex 020\000"
"SubIndex 021\000"
"SubIndex 022\000"
"SubIndex 023\000"
"SubIndex 024\000"
"SubIndex 025\000"
"SubIndex 026\000"
"SubIndex 027\000"
"SubIndex 028\000"
"SubIndex 029\000"
"SubIndex 030\000"
"SubIndex 031\000"
"SubIndex 032\000"
"SubIndex 033\000"
"SubIndex 034\000"
"SubIndex 035\000"
"SubIndex 036\000"
"SubIndex 037\000"
"SubIndex 038\000"
"SubIndex 039\000"
"SubIndex 040\000"
"SubIndex 041\000"
"SubIndex 042\000"
"SubIndex 043\000"
"SubIndex 044\000"
"SubIndex 045\000"
"SubIndex 046\000"
"SubIndex 047\000"
"SubIndex 048\000"
"SubIndex 049\000"
"SubIndex 050\000"
"SubIndex 051\000"
"SubIndex 052\000"
"SubIndex 053\000"
"SubIndex 054\000"
"SubIndex 055\000"
"SubIndex 056\000"
"SubIndex 057\000"
"SubIndex 058\000"
"SubIndex 059\000"
"SubIndex 060\000"
"SubIndex 061\000"
"SubIndex 062\000"
"SubIndex 063\000"
"SubIndex 064\000"
"SubIndex 065\000"
"SubIndex 066\000"
"SubIndex 067\000"
"SubIndex 068\000\377";
#endif //#ifdef _OBJD_

#ifndef _ROBOT_DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6000.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x6000.2 */
UINT32 SI3; /* Subindex3 - Reference to 0x6000.3 */
UINT32 SI4; /* Subindex4 - Reference to 0x6000.4 */
UINT32 SI5; /* Subindex5 - Reference to 0x6000.5 */
UINT32 SI6; /* Subindex6 - Reference to 0x6000.6 */
UINT32 SI7; /* Subindex7 - Reference to 0x6000.7 */
UINT32 SI8; /* Subindex8 - Reference to 0x6000.8 */
UINT32 SI9; /* Subindex9 - Reference to 0x6000.9 */
UINT32 SI10; /* Subindex10 - Reference to 0x6000.10 */
UINT32 SI11; /* Subindex11 - Reference to 0x6000.11 */
UINT32 SI12; /* Subindex12 - Reference to 0x6000.12 */
UINT32 SI13; /* Subindex13 - Reference to 0x6000.13 */
UINT32 SI14; /* Subindex14 - Reference to 0x6000.14 */
UINT32 SI15; /* Subindex15 - Reference to 0x6000.15 */
UINT32 SI16; /* Subindex16 - Reference to 0x6000.16 */
UINT32 SI17; /* Subindex17 - Reference to 0x6000.17 */
UINT32 SI18; /* Subindex18 - Reference to 0x6000.18 */
UINT32 SI19; /* Subindex19 - Reference to 0x6000.19 */
UINT32 SI20; /* Subindex20 - Reference to 0x6000.20 */
UINT32 SI21; /* Subindex21 - Reference to 0x6000.21 */
UINT32 SI22; /* Subindex22 - Reference to 0x6000.22 */
UINT32 SI23; /* Subindex23 - Reference to 0x6000.23 */
UINT32 SI24; /* Subindex24 - Reference to 0x6000.24 */
UINT32 SI25; /* Subindex25 - Reference to 0x6000.25 */
UINT32 SI26; /* Subindex26 - Reference to 0x6000.26 */
UINT32 SI27; /* Subindex27 - Reference to 0x6000.27 */
UINT32 SI28; /* Subindex28 - Reference to 0x6000.28 */
UINT32 SI29; /* Subindex29 - Reference to 0x6000.29 */
UINT32 SI30; /* Subindex30 - Reference to 0x6000.30 */
UINT32 SI31; /* Subindex31 - Reference to 0x6000.31 */
UINT32 SI32; /* Subindex32 - Reference to 0x6000.32 */
UINT32 SI33; /* Subindex33 - Reference to 0x6000.33 */
UINT32 SI34; /* Subindex34 - Reference to 0x6000.34 */
UINT32 SI35; /* Subindex35 - Reference to 0x6000.35 */
UINT32 SI36; /* Subindex36 - Reference to 0x6000.36 */
UINT32 SI37; /* Subindex37 - Reference to 0x6000.37 */
UINT32 SI38; /* Subindex38 - Reference to 0x6000.38 */
UINT32 SI39; /* Subindex39 - Reference to 0x6000.39 */
UINT32 SI40; /* Subindex40 - Reference to 0x6000.40 */
UINT32 SI41; /* Subindex41 - Reference to 0x6000.41 */
UINT32 SI42; /* Subindex42 - Reference to 0x6000.42 */
UINT32 SI43; /* Subindex43 - Reference to 0x6000.43 */
UINT32 SI44; /* Subindex44 - Reference to 0x6000.44 */
UINT32 SI45; /* Subindex45 - Reference to 0x6000.45 */
UINT32 SI46; /* Subindex46 - Reference to 0x6000.46 */
UINT32 SI47; /* Subindex47 - Reference to 0x6000.47 */
UINT32 SI48; /* Subindex48 - Reference to 0x6000.48 */
UINT32 SI49; /* Subindex49 - Reference to 0x6000.49 */
UINT32 SI50; /* Subindex50 - Reference to 0x6000.50 */
UINT32 SI51; /* Subindex51 - Reference to 0x6000.51 */
UINT32 SI52; /* Subindex52 - Reference to 0x6000.52 */
UINT32 SI53; /* Subindex53 - Reference to 0x6000.53 */
UINT32 SI54; /* Subindex54 - Reference to 0x6000.54 */
UINT32 SI55; /* Subindex55 - Reference to 0x6000.55 */
UINT32 SI56; /* Subindex56 - Reference to 0x6000.56 */
UINT32 SI57; /* Subindex57 - Reference to 0x6000.57 */
UINT32 SI58; /* Subindex58 - Reference to 0x6000.58 */
UINT32 SI59; /* Subindex59 - Reference to 0x6000.59 */
UINT32 SI60; /* Subindex60 - Reference to 0x6000.60 */
UINT32 SI61; /* Subindex61 - Reference to 0x6000.61 */
UINT32 SI62; /* Subindex62 - Reference to 0x6000.62 */
UINT32 SI63; /* Subindex63 - Reference to 0x6000.63 */
UINT32 SI64; /* Subindex64 - Reference to 0x6000.64 */
UINT32 SI65; /* Subindex65 - Reference to 0x6000.65 */
UINT32 SI66; /* Subindex66 - Reference to 0x6000.66 */
UINT32 SI67; /* Subindex67 - Reference to 0x6000.67 */
UINT32 SI68; /* Subindex68 - Reference to 0x6000.68 */
} OBJ_STRUCT_PACKED_END
TOBJ1A00;
#endif //#ifndef _ROBOT_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A00 IN_GENERICProcessDataMapping0x1A00
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
={68,0x60000101,0x60000201,0x60000301,0x60000401,0x60000501,0x60000601,0x60000701,0x60000801,0x60000901,0x60000A01,0x60000B01,0x60000C01,0x60000D01,0x60000E01,0x60000F01,0x60001001,0x60001110,0x60001210,0x60001310,0x60001410,0x60001510,0x60001610,0x60001708,0x60001808,0x60001908,0x60001A08,0x60001B08,0x60001C08,0x60001D08,0x60001E08,0x60001F08,0x60002008,0x60002108,0x60002208,0x60002308,0x60002408,0x60002508,0x60002608,0x60002708,0x60002808,0x60002908,0x60002A08,0x60002B08,0x60002C08,0x60002D08,0x60002E08,0x60002F08,0x60003008,0x60003108,0x60003208,0x60003308,0x60003408,0x60003508,0x60003608,0x60003710,0x60003810,0x60003910,0x60003A08,0x60003B08,0x60003C08,0x60003D08,0x60003E08,0x60003F08,0x60004008,0x60004108,0x60004210,0x60004320,0x60004410}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1C12 : SyncManager 2 assignment
******************************************************************************/
/**
* \addtogroup 0x1C12 0x1C12 | SyncManager 2 assignment
* @{
* \brief Object 0x1C12 (SyncManager 2 assignment) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1C12[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x1C12[] = "SyncManager 2 assignment\000\377";
#endif //#ifdef _OBJD_

#ifndef _ROBOT_DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[1];  /**< \brief Subindex 1 - 1 */
} OBJ_STRUCT_PACKED_END
TOBJ1C12;
#endif //#ifndef _ROBOT_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C12 sRxPDOassign
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
={1,{0x1600}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1C13 : SyncManager 3 assignment
******************************************************************************/
/**
* \addtogroup 0x1C13 0x1C13 | SyncManager 3 assignment
* @{
* \brief Object 0x1C13 (SyncManager 3 assignment) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1C13[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x1C13[] = "SyncManager 3 assignment\000\377";
#endif //#ifdef _OBJD_

#ifndef _ROBOT_DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[1];  /**< \brief Subindex 1 - 1 */
} OBJ_STRUCT_PACKED_END
TOBJ1C13;
#endif //#ifndef _ROBOT_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C13 sTxPDOassign
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
={1,{0x1A00}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6000 : IN_GENERIC
******************************************************************************/
/**
* \addtogroup 0x6000 0x6000 | IN_GENERIC
* @{
* \brief Object 0x6000 (IN_GENERIC) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Digital_Inputs_channel 1<br>
* SubIndex 2 - Digital_Inputs_channel 2<br>
* SubIndex 3 - Digital_Inputs_channel 3<br>
* SubIndex 4 - Digital_Inputs_channel 4<br>
* SubIndex 5 - Digital_Inputs_channel 5<br>
* SubIndex 6 - Digital_Inputs_channel 6<br>
* SubIndex 7 - Digital_Inputs_channel 7<br>
* SubIndex 8 - Digital_Inputs_channel 8<br>
* SubIndex 9 - Digital_Inputs_channel 9<br>
* SubIndex 10 - Digital_Inputs_channel 10<br>
* SubIndex 11 - Digital_Inputs_channel 11<br>
* SubIndex 12 - Digital_Inputs_channel 12<br>
* SubIndex 13 - Digital_Inputs_channel 13<br>
* SubIndex 14 - Digital_Inputs_channel 14<br>
* SubIndex 15 - Digital_Inputs_channel 15<br>
* SubIndex 16 - Digital_Inputs_channel 16<br>
* SubIndex 17 - Analog_Voltage_Inputs_channel 1<br>
* SubIndex 18 - Analog_Voltage_Inputs_channel 2<br>
* SubIndex 19 - Analog_Current_Inputs_channel 1<br>
* SubIndex 20 - Analog_Current_Inputs_channel 2<br>
* SubIndex 21 - RS485_Inputs_Count<br>
* SubIndex 22 - RS485_Inputs_Len<br>
* SubIndex 23 - RS485_Inputs_Data_In_1<br>
* SubIndex 24 - RS485_Inputs_Data_In_2<br>
* SubIndex 25 - RS485_Inputs_Data_In_3<br>
* SubIndex 26 - RS485_Inputs_Data_In_4<br>
* SubIndex 27 - RS485_Inputs_Data_In_5<br>
* SubIndex 28 - RS485_Inputs_Data_In_6<br>
* SubIndex 29 - RS485_Inputs_Data_In_7<br>
* SubIndex 30 - RS485_Inputs_Data_In_8<br>
* SubIndex 31 - RS485_Inputs_Data_In_9<br>
* SubIndex 32 - RS485_Inputs_Data_In_10<br>
* SubIndex 33 - RS485_Inputs_Data_In_11<br>
* SubIndex 34 - RS485_Inputs_Data_In_12<br>
* SubIndex 35 - RS485_Inputs_Data_In_13<br>
* SubIndex 36 - RS485_Inputs_Data_In_14<br>
* SubIndex 37 - RS485_Inputs_Data_In_15<br>
* SubIndex 38 - RS485_Inputs_Data_In_16<br>
* SubIndex 39 - RS485_Inputs_Data_In_17<br>
* SubIndex 40 - RS485_Inputs_Data_In_18<br>
* SubIndex 41 - RS485_Inputs_Data_In_19<br>
* SubIndex 42 - RS485_Inputs_Data_In_20<br>
* SubIndex 43 - RS485_Inputs_Data_In_21<br>
* SubIndex 44 - RS485_Inputs_Data_In_22<br>
* SubIndex 45 - RS485_Inputs_Data_In_23<br>
* SubIndex 46 - RS485_Inputs_Data_In_24<br>
* SubIndex 47 - RS485_Inputs_Data_In_25<br>
* SubIndex 48 - RS485_Inputs_Data_In_26<br>
* SubIndex 49 - RS485_Inputs_Data_In_27<br>
* SubIndex 50 - RS485_Inputs_Data_In_28<br>
* SubIndex 51 - RS485_Inputs_Data_In_29<br>
* SubIndex 52 - RS485_Inputs_Data_In_30<br>
* SubIndex 53 - RS485_Inputs_Data_In_31<br>
* SubIndex 54 - RS485_Inputs_Data_In_32<br>
* SubIndex 55 - CAN_RX_Change_Count<br>
* SubIndex 56 - CAN_RX_ID<br>
* SubIndex 57 - CAN_RX_LEN<br>
* SubIndex 58 - CAN Inputs Data In 1<br>
* SubIndex 59 - CAN Inputs Data In 2<br>
* SubIndex 60 - CAN Inputs Data In 3<br>
* SubIndex 61 - CAN Inputs Data In 4<br>
* SubIndex 62 - CAN Inputs Data In 5<br>
* SubIndex 63 - CAN Inputs Data In 6<br>
* SubIndex 64 - CAN Inputs Data In 7<br>
* SubIndex 65 - CAN Inputs Data In 8<br>
* SubIndex 66 - ErrorCode<br>
* SubIndex 67 - INC_AB_CNT<br>
* SubIndex 68 - Board_Temperature<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex1 - Digital_Inputs_channel 1 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex2 - Digital_Inputs_channel 2 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex3 - Digital_Inputs_channel 3 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex4 - Digital_Inputs_channel 4 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex5 - Digital_Inputs_channel 5 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex6 - Digital_Inputs_channel 6 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex7 - Digital_Inputs_channel 7 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex8 - Digital_Inputs_channel 8 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex9 - Digital_Inputs_channel 9 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex10 - Digital_Inputs_channel 10 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex11 - Digital_Inputs_channel 11 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex12 - Digital_Inputs_channel 12 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex13 - Digital_Inputs_channel 13 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex14 - Digital_Inputs_channel 14 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex15 - Digital_Inputs_channel 15 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex16 - Digital_Inputs_channel 16 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex17 - Analog_Voltage_Inputs_channel 1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex18 - Analog_Voltage_Inputs_channel 2 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex19 - Analog_Current_Inputs_channel 1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex20 - Analog_Current_Inputs_channel 2 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex21 - RS485_Inputs_Count */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex22 - RS485_Inputs_Len */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex23 - RS485_Inputs_Data_In_1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex24 - RS485_Inputs_Data_In_2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex25 - RS485_Inputs_Data_In_3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex26 - RS485_Inputs_Data_In_4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex27 - RS485_Inputs_Data_In_5 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex28 - RS485_Inputs_Data_In_6 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex29 - RS485_Inputs_Data_In_7 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex30 - RS485_Inputs_Data_In_8 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex31 - RS485_Inputs_Data_In_9 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex32 - RS485_Inputs_Data_In_10 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex33 - RS485_Inputs_Data_In_11 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex34 - RS485_Inputs_Data_In_12 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex35 - RS485_Inputs_Data_In_13 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex36 - RS485_Inputs_Data_In_14 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex37 - RS485_Inputs_Data_In_15 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex38 - RS485_Inputs_Data_In_16 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex39 - RS485_Inputs_Data_In_17 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex40 - RS485_Inputs_Data_In_18 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex41 - RS485_Inputs_Data_In_19 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex42 - RS485_Inputs_Data_In_20 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex43 - RS485_Inputs_Data_In_21 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex44 - RS485_Inputs_Data_In_22 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex45 - RS485_Inputs_Data_In_23 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex46 - RS485_Inputs_Data_In_24 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex47 - RS485_Inputs_Data_In_25 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex48 - RS485_Inputs_Data_In_26 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex49 - RS485_Inputs_Data_In_27 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex50 - RS485_Inputs_Data_In_28 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex51 - RS485_Inputs_Data_In_29 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex52 - RS485_Inputs_Data_In_30 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex53 - RS485_Inputs_Data_In_31 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex54 - RS485_Inputs_Data_In_32 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex55 - CAN_RX_Change_Count */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex56 - CAN_RX_ID */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex57 - CAN_RX_LEN */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex58 - CAN Inputs Data In 1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex59 - CAN Inputs Data In 2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex60 - CAN Inputs Data In 3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex61 - CAN Inputs Data In 4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex62 - CAN Inputs Data In 5 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex63 - CAN Inputs Data In 6 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex64 - CAN Inputs Data In 7 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex65 - CAN Inputs Data In 8 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex66 - ErrorCode */
{ DEFTYPE_INTEGER32 , 0x20 , ACCESS_READ }, /* Subindex67 - INC_AB_CNT */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }}; /* Subindex68 - Board_Temperature */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6000[] = "IN_GENERIC\000"
"Digital_Inputs_channel 1\000"
"Digital_Inputs_channel 2\000"
"Digital_Inputs_channel 3\000"
"Digital_Inputs_channel 4\000"
"Digital_Inputs_channel 5\000"
"Digital_Inputs_channel 6\000"
"Digital_Inputs_channel 7\000"
"Digital_Inputs_channel 8\000"
"Digital_Inputs_channel 9\000"
"Digital_Inputs_channel 10\000"
"Digital_Inputs_channel 11\000"
"Digital_Inputs_channel 12\000"
"Digital_Inputs_channel 13\000"
"Digital_Inputs_channel 14\000"
"Digital_Inputs_channel 15\000"
"Digital_Inputs_channel 16\000"
"Analog_Voltage_Inputs_channel 1\000"
"Analog_Voltage_Inputs_channel 2\000"
"Analog_Current_Inputs_channel 1\000"
"Analog_Current_Inputs_channel 2\000"
"RS485_Inputs_Count\000"
"RS485_Inputs_Len\000"
"RS485_Inputs_Data_In_1\000"
"RS485_Inputs_Data_In_2\000"
"RS485_Inputs_Data_In_3\000"
"RS485_Inputs_Data_In_4\000"
"RS485_Inputs_Data_In_5\000"
"RS485_Inputs_Data_In_6\000"
"RS485_Inputs_Data_In_7\000"
"RS485_Inputs_Data_In_8\000"
"RS485_Inputs_Data_In_9\000"
"RS485_Inputs_Data_In_10\000"
"RS485_Inputs_Data_In_11\000"
"RS485_Inputs_Data_In_12\000"
"RS485_Inputs_Data_In_13\000"
"RS485_Inputs_Data_In_14\000"
"RS485_Inputs_Data_In_15\000"
"RS485_Inputs_Data_In_16\000"
"RS485_Inputs_Data_In_17\000"
"RS485_Inputs_Data_In_18\000"
"RS485_Inputs_Data_In_19\000"
"RS485_Inputs_Data_In_20\000"
"RS485_Inputs_Data_In_21\000"
"RS485_Inputs_Data_In_22\000"
"RS485_Inputs_Data_In_23\000"
"RS485_Inputs_Data_In_24\000"
"RS485_Inputs_Data_In_25\000"
"RS485_Inputs_Data_In_26\000"
"RS485_Inputs_Data_In_27\000"
"RS485_Inputs_Data_In_28\000"
"RS485_Inputs_Data_In_29\000"
"RS485_Inputs_Data_In_30\000"
"RS485_Inputs_Data_In_31\000"
"RS485_Inputs_Data_In_32\000"
"CAN_RX_Change_Count\000"
"CAN_RX_ID\000"
"CAN_RX_LEN\000"
"CAN Inputs Data In 1\000"
"CAN Inputs Data In 2\000"
"CAN Inputs Data In 3\000"
"CAN Inputs Data In 4\000"
"CAN Inputs Data In 5\000"
"CAN Inputs Data In 6\000"
"CAN Inputs Data In 7\000"
"CAN Inputs Data In 8\000"
"ErrorCode\000"
"INC_AB_CNT\000"
"Board_Temperature\000\377";
#endif //#ifdef _OBJD_

#ifndef _ROBOT_DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
BOOLEAN(Digital_Inputs_channel1); /* Subindex1 - Digital_Inputs_channel 1 */
BOOLEAN(Digital_Inputs_channel2); /* Subindex2 - Digital_Inputs_channel 2 */
BOOLEAN(Digital_Inputs_channel3); /* Subindex3 - Digital_Inputs_channel 3 */
BOOLEAN(Digital_Inputs_channel4); /* Subindex4 - Digital_Inputs_channel 4 */
BOOLEAN(Digital_Inputs_channel5); /* Subindex5 - Digital_Inputs_channel 5 */
BOOLEAN(Digital_Inputs_channel6); /* Subindex6 - Digital_Inputs_channel 6 */
BOOLEAN(Digital_Inputs_channel7); /* Subindex7 - Digital_Inputs_channel 7 */
BOOLEAN(Digital_Inputs_channel8); /* Subindex8 - Digital_Inputs_channel 8 */
BOOLEAN(Digital_Inputs_channel9); /* Subindex9 - Digital_Inputs_channel 9 */
BOOLEAN(Digital_Inputs_channel10); /* Subindex10 - Digital_Inputs_channel 10 */
BOOLEAN(Digital_Inputs_channel11); /* Subindex11 - Digital_Inputs_channel 11 */
BOOLEAN(Digital_Inputs_channel12); /* Subindex12 - Digital_Inputs_channel 12 */
BOOLEAN(Digital_Inputs_channel13); /* Subindex13 - Digital_Inputs_channel 13 */
BOOLEAN(Digital_Inputs_channel14); /* Subindex14 - Digital_Inputs_channel 14 */
BOOLEAN(Digital_Inputs_channel15); /* Subindex15 - Digital_Inputs_channel 15 */
BOOLEAN(Digital_Inputs_channel16); /* Subindex16 - Digital_Inputs_channel 16 */
UINT16 Analog_Voltage_Inputs_channel1; /* Subindex17 - Analog_Voltage_Inputs_channel 1 */
UINT16 Analog_Voltage_Inputs_channel2; /* Subindex18 - Analog_Voltage_Inputs_channel 2 */
UINT16 Analog_Current_Inputs_channel1; /* Subindex19 - Analog_Current_Inputs_channel 1 */
UINT16 Analog_Current_Inputs_channel2; /* Subindex20 - Analog_Current_Inputs_channel 2 */
UINT16 RS485_Inputs_Count; /* Subindex21 - RS485_Inputs_Count */
UINT16 RS485_Inputs_Len; /* Subindex22 - RS485_Inputs_Len */
UINT8 RS485_Inputs_Data_In_1; /* Subindex23 - RS485_Inputs_Data_In_1 */
UINT8 RS485_Inputs_Data_In_2; /* Subindex24 - RS485_Inputs_Data_In_2 */
UINT8 RS485_Inputs_Data_In_3; /* Subindex25 - RS485_Inputs_Data_In_3 */
UINT8 RS485_Inputs_Data_In_4; /* Subindex26 - RS485_Inputs_Data_In_4 */
UINT8 RS485_Inputs_Data_In_5; /* Subindex27 - RS485_Inputs_Data_In_5 */
UINT8 RS485_Inputs_Data_In_6; /* Subindex28 - RS485_Inputs_Data_In_6 */
UINT8 RS485_Inputs_Data_In_7; /* Subindex29 - RS485_Inputs_Data_In_7 */
UINT8 RS485_Inputs_Data_In_8; /* Subindex30 - RS485_Inputs_Data_In_8 */
UINT8 RS485_Inputs_Data_In_9; /* Subindex31 - RS485_Inputs_Data_In_9 */
UINT8 RS485_Inputs_Data_In_10; /* Subindex32 - RS485_Inputs_Data_In_10 */
UINT8 RS485_Inputs_Data_In_11; /* Subindex33 - RS485_Inputs_Data_In_11 */
UINT8 RS485_Inputs_Data_In_12; /* Subindex34 - RS485_Inputs_Data_In_12 */
UINT8 RS485_Inputs_Data_In_13; /* Subindex35 - RS485_Inputs_Data_In_13 */
UINT8 RS485_Inputs_Data_In_14; /* Subindex36 - RS485_Inputs_Data_In_14 */
UINT8 RS485_Inputs_Data_In_15; /* Subindex37 - RS485_Inputs_Data_In_15 */
UINT8 RS485_Inputs_Data_In_16; /* Subindex38 - RS485_Inputs_Data_In_16 */
UINT8 RS485_Inputs_Data_In_17; /* Subindex39 - RS485_Inputs_Data_In_17 */
UINT8 RS485_Inputs_Data_In_18; /* Subindex40 - RS485_Inputs_Data_In_18 */
UINT8 RS485_Inputs_Data_In_19; /* Subindex41 - RS485_Inputs_Data_In_19 */
UINT8 RS485_Inputs_Data_In_20; /* Subindex42 - RS485_Inputs_Data_In_20 */
UINT8 RS485_Inputs_Data_In_21; /* Subindex43 - RS485_Inputs_Data_In_21 */
UINT8 RS485_Inputs_Data_In_22; /* Subindex44 - RS485_Inputs_Data_In_22 */
UINT8 RS485_Inputs_Data_In_23; /* Subindex45 - RS485_Inputs_Data_In_23 */
UINT8 RS485_Inputs_Data_In_24; /* Subindex46 - RS485_Inputs_Data_In_24 */
UINT8 RS485_Inputs_Data_In_25; /* Subindex47 - RS485_Inputs_Data_In_25 */
UINT8 RS485_Inputs_Data_In_26; /* Subindex48 - RS485_Inputs_Data_In_26 */
UINT8 RS485_Inputs_Data_In_27; /* Subindex49 - RS485_Inputs_Data_In_27 */
UINT8 RS485_Inputs_Data_In_28; /* Subindex50 - RS485_Inputs_Data_In_28 */
UINT8 RS485_Inputs_Data_In_29; /* Subindex51 - RS485_Inputs_Data_In_29 */
UINT8 RS485_Inputs_Data_In_30; /* Subindex52 - RS485_Inputs_Data_In_30 */
UINT8 RS485_Inputs_Data_In_31; /* Subindex53 - RS485_Inputs_Data_In_31 */
UINT8 RS485_Inputs_Data_In_32; /* Subindex54 - RS485_Inputs_Data_In_32 */
UINT16 CAN_RX_Change_Count; /* Subindex55 - CAN_RX_Change_Count */
UINT16 CAN_RX_ID; /* Subindex56 - CAN_RX_ID */
UINT16 CAN_RX_LEN; /* Subindex57 - CAN_RX_LEN */
UINT8 CANInputsDataIn1; /* Subindex58 - CAN Inputs Data In 1 */
UINT8 CANInputsDataIn2; /* Subindex59 - CAN Inputs Data In 2 */
UINT8 CANInputsDataIn3; /* Subindex60 - CAN Inputs Data In 3 */
UINT8 CANInputsDataIn4; /* Subindex61 - CAN Inputs Data In 4 */
UINT8 CANInputsDataIn5; /* Subindex62 - CAN Inputs Data In 5 */
UINT8 CANInputsDataIn6; /* Subindex63 - CAN Inputs Data In 6 */
UINT8 CANInputsDataIn7; /* Subindex64 - CAN Inputs Data In 7 */
UINT8 CANInputsDataIn8; /* Subindex65 - CAN Inputs Data In 8 */
UINT16 ErrorCode; /* Subindex66 - ErrorCode */
INT32 INC_AB_CNT; /* Subindex67 - INC_AB_CNT */
UINT16 Board_Temperature; /* Subindex68 - Board_Temperature */
} OBJ_STRUCT_PACKED_END
TOBJ6000;
#endif //#ifndef _ROBOT_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6000 IN_GENERIC0x6000
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
={68,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0000,0x0000,0x0000,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0000,0x00000000,0x0000}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x7000 : OUT_GENERIC
******************************************************************************/
/**
* \addtogroup 0x7000 0x7000 | OUT_GENERIC
* @{
* \brief Object 0x7000 (OUT_GENERIC) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Digital_Outputs_channel_1<br>
* SubIndex 2 - Digital_Outputs_channel_2<br>
* SubIndex 3 - Digital_Outputs_channel_3<br>
* SubIndex 4 - Digital_Outputs_channel_4<br>
* SubIndex 5 - Digital_Outputs_channel_5<br>
* SubIndex 6 - Digital_Outputs_channel_6<br>
* SubIndex 7 - Digital_Outputs_channel_7<br>
* SubIndex 8 - Digital_Outputs_channel_8<br>
* SubIndex 9 - Digital_Outputs_channel_9<br>
* SubIndex 10 - Digital_Outputs_channel_10<br>
* SubIndex 11 - Digital_Outputs_channel_11<br>
* SubIndex 12 - Digital_Outputs_channel_12<br>
* SubIndex 13 - Digital_Outputs_channel_13<br>
* SubIndex 14 - Digital_Outputs_channel_14<br>
* SubIndex 15 - Digital_Outputs_channel_15<br>
* SubIndex 16 - Digital_Outputs_channel_16<br>
* SubIndex 17 - RS485_Outputs_Count<br>
* SubIndex 18 - RS485_Outputs_Len<br>
* SubIndex 19 - RS485_Outputs_Data_Out_1<br>
* SubIndex 20 - RS485_Outputs_Data_Out_2<br>
* SubIndex 21 - RS485_Outputs_Data_Out_3<br>
* SubIndex 22 - RS485_Outputs_Data_Out_4<br>
* SubIndex 23 - RS485_Outputs_Data_Out_5<br>
* SubIndex 24 - RS485_Outputs_Data_Out_6<br>
* SubIndex 25 - RS485_Outputs_Data_Out_7<br>
* SubIndex 26 - RS485_Outputs_Data_Out_8<br>
* SubIndex 27 - RS485_Outputs_Data_Out_9<br>
* SubIndex 28 - RS485_Outputs_Data_Out_10<br>
* SubIndex 29 - RS485_Outputs_Data_Out_11<br>
* SubIndex 30 - RS485_Outputs_Data_Out_12<br>
* SubIndex 31 - RS485_Outputs_Data_Out_13<br>
* SubIndex 32 - RS485_Outputs_Data_Out_14<br>
* SubIndex 33 - RS485_Outputs_Data_Out_15<br>
* SubIndex 34 - RS485_Outputs_Data_Out_16<br>
* SubIndex 35 - RS485_Outputs_Data_Out_17<br>
* SubIndex 36 - RS485_Outputs_Data_Out_18<br>
* SubIndex 37 - RS485_Outputs_Data_Out_19<br>
* SubIndex 38 - RS485_Outputs_Data_Out_20<br>
* SubIndex 39 - RS485_Outputs_Data_Out_21<br>
* SubIndex 40 - RS485_Outputs_Data_Out_22<br>
* SubIndex 41 - RS485_Outputs_Data_Out_23<br>
* SubIndex 42 - RS485_Outputs_Data_Out_24<br>
* SubIndex 43 - RS485_Outputs_Data_Out_25<br>
* SubIndex 44 - RS485_Outputs_Data_Out_26<br>
* SubIndex 45 - RS485_Outputs_Data_Out_27<br>
* SubIndex 46 - RS485_Outputs_Data_Out_28<br>
* SubIndex 47 - RS485_Outputs_Data_Out_29<br>
* SubIndex 48 - RS485_Outputs_Data_Out_30<br>
* SubIndex 49 - RS485_Outputs_Data_Out_31<br>
* SubIndex 50 - RS485_Outputs_Data_Out_32<br>
* SubIndex 51 - CAN_TX_Change_Count<br>
* SubIndex 52 - CAN_TX_ID<br>
* SubIndex 53 - CAN_TX_LEN<br>
* SubIndex 54 - CAN Outputs Data Out 1<br>
* SubIndex 55 - CAN Outputs Data Out 2<br>
* SubIndex 56 - CAN Outputs Data Out 3<br>
* SubIndex 57 - CAN Outputs Data Out 4<br>
* SubIndex 58 - CAN Outputs Data Out 5<br>
* SubIndex 59 - CAN Outputs Data Out 6<br>
* SubIndex 60 - CAN Outputs Data Out 7<br>
* SubIndex 61 - CAN Outputs Data Out 8<br>
* SubIndex 62 - Analog_Voltage_Output_Channel1<br>
* SubIndex 63 - Analog_Voltage_Output_Channel2<br>
* SubIndex 64 - Analog_Current_Output_Channel1<br>
* SubIndex 65 - Analog_Current_Output_Channel2<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex1 - Digital_Outputs_channel_1 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex2 - Digital_Outputs_channel_2 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex3 - Digital_Outputs_channel_3 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex4 - Digital_Outputs_channel_4 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex5 - Digital_Outputs_channel_5 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex6 - Digital_Outputs_channel_6 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex7 - Digital_Outputs_channel_7 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex8 - Digital_Outputs_channel_8 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex9 - Digital_Outputs_channel_9 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex10 - Digital_Outputs_channel_10 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex11 - Digital_Outputs_channel_11 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex12 - Digital_Outputs_channel_12 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex13 - Digital_Outputs_channel_13 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex14 - Digital_Outputs_channel_14 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex15 - Digital_Outputs_channel_15 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex16 - Digital_Outputs_channel_16 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex17 - RS485_Outputs_Count */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex18 - RS485_Outputs_Len */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex19 - RS485_Outputs_Data_Out_1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex20 - RS485_Outputs_Data_Out_2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex21 - RS485_Outputs_Data_Out_3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex22 - RS485_Outputs_Data_Out_4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex23 - RS485_Outputs_Data_Out_5 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex24 - RS485_Outputs_Data_Out_6 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex25 - RS485_Outputs_Data_Out_7 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex26 - RS485_Outputs_Data_Out_8 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex27 - RS485_Outputs_Data_Out_9 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex28 - RS485_Outputs_Data_Out_10 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex29 - RS485_Outputs_Data_Out_11 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex30 - RS485_Outputs_Data_Out_12 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex31 - RS485_Outputs_Data_Out_13 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex32 - RS485_Outputs_Data_Out_14 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex33 - RS485_Outputs_Data_Out_15 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex34 - RS485_Outputs_Data_Out_16 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex35 - RS485_Outputs_Data_Out_17 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex36 - RS485_Outputs_Data_Out_18 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex37 - RS485_Outputs_Data_Out_19 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex38 - RS485_Outputs_Data_Out_20 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex39 - RS485_Outputs_Data_Out_21 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex40 - RS485_Outputs_Data_Out_22 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex41 - RS485_Outputs_Data_Out_23 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex42 - RS485_Outputs_Data_Out_24 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex43 - RS485_Outputs_Data_Out_25 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex44 - RS485_Outputs_Data_Out_26 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex45 - RS485_Outputs_Data_Out_27 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex46 - RS485_Outputs_Data_Out_28 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex47 - RS485_Outputs_Data_Out_29 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex48 - RS485_Outputs_Data_Out_30 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex49 - RS485_Outputs_Data_Out_31 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex50 - RS485_Outputs_Data_Out_32 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex51 - CAN_TX_Change_Count */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex52 - CAN_TX_ID */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex53 - CAN_TX_LEN */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex54 - CAN Outputs Data Out 1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex55 - CAN Outputs Data Out 2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex56 - CAN Outputs Data Out 3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex57 - CAN Outputs Data Out 4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex58 - CAN Outputs Data Out 5 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex59 - CAN Outputs Data Out 6 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex60 - CAN Outputs Data Out 7 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ }, /* Subindex61 - CAN Outputs Data Out 8 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex62 - Analog_Voltage_Output_Channel1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex63 - Analog_Voltage_Output_Channel2 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex64 - Analog_Current_Output_Channel1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }}; /* Subindex65 - Analog_Current_Output_Channel2 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x7000[] = "OUT_GENERIC\000"
"Digital_Outputs_channel_1\000"
"Digital_Outputs_channel_2\000"
"Digital_Outputs_channel_3\000"
"Digital_Outputs_channel_4\000"
"Digital_Outputs_channel_5\000"
"Digital_Outputs_channel_6\000"
"Digital_Outputs_channel_7\000"
"Digital_Outputs_channel_8\000"
"Digital_Outputs_channel_9\000"
"Digital_Outputs_channel_10\000"
"Digital_Outputs_channel_11\000"
"Digital_Outputs_channel_12\000"
"Digital_Outputs_channel_13\000"
"Digital_Outputs_channel_14\000"
"Digital_Outputs_channel_15\000"
"Digital_Outputs_channel_16\000"
"RS485_Outputs_Count\000"
"RS485_Outputs_Len\000"
"RS485_Outputs_Data_Out_1\000"
"RS485_Outputs_Data_Out_2\000"
"RS485_Outputs_Data_Out_3\000"
"RS485_Outputs_Data_Out_4\000"
"RS485_Outputs_Data_Out_5\000"
"RS485_Outputs_Data_Out_6\000"
"RS485_Outputs_Data_Out_7\000"
"RS485_Outputs_Data_Out_8\000"
"RS485_Outputs_Data_Out_9\000"
"RS485_Outputs_Data_Out_10\000"
"RS485_Outputs_Data_Out_11\000"
"RS485_Outputs_Data_Out_12\000"
"RS485_Outputs_Data_Out_13\000"
"RS485_Outputs_Data_Out_14\000"
"RS485_Outputs_Data_Out_15\000"
"RS485_Outputs_Data_Out_16\000"
"RS485_Outputs_Data_Out_17\000"
"RS485_Outputs_Data_Out_18\000"
"RS485_Outputs_Data_Out_19\000"
"RS485_Outputs_Data_Out_20\000"
"RS485_Outputs_Data_Out_21\000"
"RS485_Outputs_Data_Out_22\000"
"RS485_Outputs_Data_Out_23\000"
"RS485_Outputs_Data_Out_24\000"
"RS485_Outputs_Data_Out_25\000"
"RS485_Outputs_Data_Out_26\000"
"RS485_Outputs_Data_Out_27\000"
"RS485_Outputs_Data_Out_28\000"
"RS485_Outputs_Data_Out_29\000"
"RS485_Outputs_Data_Out_30\000"
"RS485_Outputs_Data_Out_31\000"
"RS485_Outputs_Data_Out_32\000"
"CAN_TX_Change_Count\000"
"CAN_TX_ID\000"
"CAN_TX_LEN\000"
"CAN Outputs Data Out 1\000"
"CAN Outputs Data Out 2\000"
"CAN Outputs Data Out 3\000"
"CAN Outputs Data Out 4\000"
"CAN Outputs Data Out 5\000"
"CAN Outputs Data Out 6\000"
"CAN Outputs Data Out 7\000"
"CAN Outputs Data Out 8\000"
"Analog_Voltage_Output_Channel1\000"
"Analog_Voltage_Output_Channel2\000"
"Analog_Current_Output_Channel1\000"
"Analog_Current_Output_Channel2\000\377";
#endif //#ifdef _OBJD_

#ifndef _ROBOT_DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
BOOLEAN(Digital_Outputs_channel_1); /* Subindex1 - Digital_Outputs_channel_1 */
BOOLEAN(Digital_Outputs_channel_2); /* Subindex2 - Digital_Outputs_channel_2 */
BOOLEAN(Digital_Outputs_channel_3); /* Subindex3 - Digital_Outputs_channel_3 */
BOOLEAN(Digital_Outputs_channel_4); /* Subindex4 - Digital_Outputs_channel_4 */
BOOLEAN(Digital_Outputs_channel_5); /* Subindex5 - Digital_Outputs_channel_5 */
BOOLEAN(Digital_Outputs_channel_6); /* Subindex6 - Digital_Outputs_channel_6 */
BOOLEAN(Digital_Outputs_channel_7); /* Subindex7 - Digital_Outputs_channel_7 */
BOOLEAN(Digital_Outputs_channel_8); /* Subindex8 - Digital_Outputs_channel_8 */
BOOLEAN(Digital_Outputs_channel_9); /* Subindex9 - Digital_Outputs_channel_9 */
BOOLEAN(Digital_Outputs_channel_10); /* Subindex10 - Digital_Outputs_channel_10 */
BOOLEAN(Digital_Outputs_channel_11); /* Subindex11 - Digital_Outputs_channel_11 */
BOOLEAN(Digital_Outputs_channel_12); /* Subindex12 - Digital_Outputs_channel_12 */
BOOLEAN(Digital_Outputs_channel_13); /* Subindex13 - Digital_Outputs_channel_13 */
BOOLEAN(Digital_Outputs_channel_14); /* Subindex14 - Digital_Outputs_channel_14 */
BOOLEAN(Digital_Outputs_channel_15); /* Subindex15 - Digital_Outputs_channel_15 */
BOOLEAN(Digital_Outputs_channel_16); /* Subindex16 - Digital_Outputs_channel_16 */
UINT16 RS485_Outputs_Count; /* Subindex17 - RS485_Outputs_Count */
UINT16 RS485_Outputs_Len; /* Subindex18 - RS485_Outputs_Len */
UINT8 RS485_Outputs_Data_Out_1; /* Subindex19 - RS485_Outputs_Data_Out_1 */
UINT8 RS485_Outputs_Data_Out_2; /* Subindex20 - RS485_Outputs_Data_Out_2 */
UINT8 RS485_Outputs_Data_Out_3; /* Subindex21 - RS485_Outputs_Data_Out_3 */
UINT8 RS485_Outputs_Data_Out_4; /* Subindex22 - RS485_Outputs_Data_Out_4 */
UINT8 RS485_Outputs_Data_Out_5; /* Subindex23 - RS485_Outputs_Data_Out_5 */
UINT8 RS485_Outputs_Data_Out_6; /* Subindex24 - RS485_Outputs_Data_Out_6 */
UINT8 RS485_Outputs_Data_Out_7; /* Subindex25 - RS485_Outputs_Data_Out_7 */
UINT8 RS485_Outputs_Data_Out_8; /* Subindex26 - RS485_Outputs_Data_Out_8 */
UINT8 RS485_Outputs_Data_Out_9; /* Subindex27 - RS485_Outputs_Data_Out_9 */
UINT8 RS485_Outputs_Data_Out_10; /* Subindex28 - RS485_Outputs_Data_Out_10 */
UINT8 RS485_Outputs_Data_Out_11; /* Subindex29 - RS485_Outputs_Data_Out_11 */
UINT8 RS485_Outputs_Data_Out_12; /* Subindex30 - RS485_Outputs_Data_Out_12 */
UINT8 RS485_Outputs_Data_Out_13; /* Subindex31 - RS485_Outputs_Data_Out_13 */
UINT8 RS485_Outputs_Data_Out_14; /* Subindex32 - RS485_Outputs_Data_Out_14 */
UINT8 RS485_Outputs_Data_Out_15; /* Subindex33 - RS485_Outputs_Data_Out_15 */
UINT8 RS485_Outputs_Data_Out_16; /* Subindex34 - RS485_Outputs_Data_Out_16 */
UINT8 RS485_Outputs_Data_Out_17; /* Subindex35 - RS485_Outputs_Data_Out_17 */
UINT8 RS485_Outputs_Data_Out_18; /* Subindex36 - RS485_Outputs_Data_Out_18 */
UINT8 RS485_Outputs_Data_Out_19; /* Subindex37 - RS485_Outputs_Data_Out_19 */
UINT8 RS485_Outputs_Data_Out_20; /* Subindex38 - RS485_Outputs_Data_Out_20 */
UINT8 RS485_Outputs_Data_Out_21; /* Subindex39 - RS485_Outputs_Data_Out_21 */
UINT8 RS485_Outputs_Data_Out_22; /* Subindex40 - RS485_Outputs_Data_Out_22 */
UINT8 RS485_Outputs_Data_Out_23; /* Subindex41 - RS485_Outputs_Data_Out_23 */
UINT8 RS485_Outputs_Data_Out_24; /* Subindex42 - RS485_Outputs_Data_Out_24 */
UINT8 RS485_Outputs_Data_Out_25; /* Subindex43 - RS485_Outputs_Data_Out_25 */
UINT8 RS485_Outputs_Data_Out_26; /* Subindex44 - RS485_Outputs_Data_Out_26 */
UINT8 RS485_Outputs_Data_Out_27; /* Subindex45 - RS485_Outputs_Data_Out_27 */
UINT8 RS485_Outputs_Data_Out_28; /* Subindex46 - RS485_Outputs_Data_Out_28 */
UINT8 RS485_Outputs_Data_Out_29; /* Subindex47 - RS485_Outputs_Data_Out_29 */
UINT8 RS485_Outputs_Data_Out_30; /* Subindex48 - RS485_Outputs_Data_Out_30 */
UINT8 RS485_Outputs_Data_Out_31; /* Subindex49 - RS485_Outputs_Data_Out_31 */
UINT8 RS485_Outputs_Data_Out_32; /* Subindex50 - RS485_Outputs_Data_Out_32 */
UINT16 CAN_TX_Change_Count; /* Subindex51 - CAN_TX_Change_Count */
UINT16 CAN_TX_ID; /* Subindex52 - CAN_TX_ID */
UINT16 CAN_TX_LEN; /* Subindex53 - CAN_TX_LEN */
UINT8 CANOutputsDataOut1; /* Subindex54 - CAN Outputs Data Out 1 */
UINT8 CANOutputsDataOut2; /* Subindex55 - CAN Outputs Data Out 2 */
UINT8 CANOutputsDataOut3; /* Subindex56 - CAN Outputs Data Out 3 */
UINT8 CANOutputsDataOut4; /* Subindex57 - CAN Outputs Data Out 4 */
UINT8 CANOutputsDataOut5; /* Subindex58 - CAN Outputs Data Out 5 */
UINT8 CANOutputsDataOut6; /* Subindex59 - CAN Outputs Data Out 6 */
UINT8 CANOutputsDataOut7; /* Subindex60 - CAN Outputs Data Out 7 */
UINT8 CANOutputsDataOut8; /* Subindex61 - CAN Outputs Data Out 8 */
UINT16 Analog_Voltage_Output_Channel1; /* Subindex62 - Analog_Voltage_Output_Channel1 */
UINT16 Analog_Voltage_Output_Channel2; /* Subindex63 - Analog_Voltage_Output_Channel2 */
UINT16 Analog_Current_Output_Channel1; /* Subindex64 - Analog_Current_Output_Channel1 */
UINT16 Analog_Current_Output_Channel2; /* Subindex65 - Analog_Current_Output_Channel2 */
} OBJ_STRUCT_PACKED_END
TOBJ7000;
#endif //#ifndef _ROBOT_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ7000 OUT_GENERIC0x7000
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
={65,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0000,0x0000,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0000,0x0000,0x0000,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0000,0x0000,0x0000,0x0000}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8000 : Parameter Configuration
******************************************************************************/
/**
* \addtogroup 0x8000 0x8000 | Parameter Configuration
* @{
* \brief Object 0x8000 (Parameter Configuration) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - RS485_Baudrate<br>
* SubIndex 2 - CAN_Baudrate<br>
* SubIndex 3 - MotEncPerRotate<br>
* SubIndex 4 - Analog_Input_Switch_Channel1<br>
* SubIndex 5 - Analog_Input_Switch_Channel2<br>
* SubIndex 6 - Analog_Output_Switch_Channel1<br>
* SubIndex 7 - Analog_Output_Switch_Channel2<br>
* SubIndex 8 - Over_Voltage_48V<br>
* SubIndex 9 - Under_Voltage_48V<br>
* SubIndex 10 - Over_Current_48V<br>
* SubIndex 11 - Over_Voltage_24V<br>
* SubIndex 12 - Under_Voltage_24V<br>
* SubIndex 13 - Over_Current_24V<br>
* SubIndex 14 - Over_Temperature<br>
* SubIndex 15 - Res_Over_heat<br>
* SubIndex 16 - Consecutive_Failure_CNT<br>
* SubIndex 17 - Test_Mode<br>
* SubIndex 18 - Delay_Time<br>
* SubIndex 19 - Restart_Time<br>
* SubIndex 20 - Complete_Flag<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x8000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE }, /* Subindex1 - RS485_Baudrate */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE }, /* Subindex2 - CAN_Baudrate */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex3 - MotEncPerRotate */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex4 - Analog_Input_Switch_Channel1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex5 - Analog_Input_Switch_Channel2 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex6 - Analog_Output_Switch_Channel1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex7 - Analog_Output_Switch_Channel2 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex8 - Over_Voltage_48V */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex9 - Under_Voltage_48V */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex10 - Over_Current_48V */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex11 - Over_Voltage_24V */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex12 - Under_Voltage_24V */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex13 - Over_Current_24V */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex14 - Over_Temperature */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex15 - Res_Over_heat */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex16 - Consecutive_Failure_CNT */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex17 - Test_Mode */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex18 - Delay_Time */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex19 - Restart_Time */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }}; /* Subindex20 - Complete_Flag */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x8000[] = "Parameter Configuration\000"
"RS485_Baudrate\000"
"CAN_Baudrate\000"
"MotEncPerRotate\000"
"Analog_Input_Switch_Channel1\000"
"Analog_Input_Switch_Channel2\000"
"Analog_Output_Switch_Channel1\000"
"Analog_Output_Switch_Channel2\000"
"Over_Voltage_48V\000"
"Under_Voltage_48V\000"
"Over_Current_48V\000"
"Over_Voltage_24V\000"
"Under_Voltage_24V\000"
"Over_Current_24V\000"
"Over_Temperature\000"
"Res_Over_heat\000"
"Consecutive_Failure_CNT\000"
"Test_Mode\000"
"Delay_Time\000"
"Restart_Time\000"
"Complete_Flag\000\377";
#endif //#ifdef _OBJD_

#ifndef _ROBOT_DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 RS485_Baudrate; /* Subindex1 - RS485_Baudrate */
UINT32 CAN_Baudrate; /* Subindex2 - CAN_Baudrate */
UINT16 MotEncPerRotate; /* Subindex3 - MotEncPerRotate */
UINT16 Analog_Input_Switch_Channel1; /* Subindex4 - Analog_Input_Switch_Channel1 */
UINT16 Analog_Input_Switch_Channel2; /* Subindex5 - Analog_Input_Switch_Channel2 */
UINT16 Analog_Output_Switch_Channel1; /* Subindex6 - Analog_Output_Switch_Channel1 */
UINT16 Analog_Output_Switch_Channel2; /* Subindex7 - Analog_Output_Switch_Channel2 */
UINT16 Over_Voltage_48V; /* Subindex8 - Over_Voltage_48V */
UINT16 Under_Voltage_48V; /* Subindex9 - Under_Voltage_48V */
UINT16 Over_Current_48V; /* Subindex10 - Over_Current_48V */
UINT16 Over_Voltage_24V; /* Subindex11 - Over_Voltage_24V */
UINT16 Under_Voltage_24V; /* Subindex12 - Under_Voltage_24V */
UINT16 Over_Current_24V; /* Subindex13 - Over_Current_24V */
UINT16 Over_Temperature; /* Subindex14 - Over_Temperature */
UINT16 Res_Over_heat; /* Subindex15 - Res_Over_heat */
UINT16 Consecutive_Failure_CNT; /* Subindex16 - Consecutive_Failure_CNT */
UINT16 Test_Mode; /* Subindex17 - Test_Mode */
UINT16 Delay_Time; /* Subindex18 - Delay_Time */
UINT16 Restart_Time; /* Subindex19 - Restart_Time */
UINT16 Complete_Flag; /* Subindex20 - Complete_Flag */
} OBJ_STRUCT_PACKED_END
TOBJ8000;
#endif //#ifndef _ROBOT_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ8000 ParameterConfiguration0x8000
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
={20,0x0001C200,0x000001F4,0x07D0,0x0000,0x0000,0x0000,0x0000,0x004B,0x0006,0x0028,0x003C,0x0004,0x0000,0x0055,0x07D0,0x0005,0x0000,0x1388,0x03E8,0x0000}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0xF000 : Modular Device Profile
******************************************************************************/
/**
* \addtogroup 0xF000 0xF000 | Modular Device Profile
* @{
* \brief Object 0xF000 (Modular Device Profile) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Index distance <br>
* SubIndex 2 - Maximum number of modules <br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0xF000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex1 - Index distance  */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }}; /* Subindex2 - Maximum number of modules  */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0xF000[] = "Modular Device Profile\000"
"Index distance \000"
"Maximum number of modules \000\377";
#endif //#ifdef _OBJD_

#ifndef _ROBOT_DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT16 IndexDistance; /* Subindex1 - Index distance  */
UINT16 MaximumNumberOfModules; /* Subindex2 - Maximum number of modules  */
} OBJ_STRUCT_PACKED_END
TOBJF000;
#endif //#ifndef _ROBOT_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJF000 ModularDeviceProfile0xF000
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
={2,0x0010,0}
#endif
;
/** @}*/







#ifdef _OBJD_
TOBJECT    OBJMEM ApplicationObjDic[] = {
/* Object 0x1600 */
{NULL , NULL ,  0x1600 , {DEFTYPE_PDOMAPPING , 65 | (OBJCODE_REC << 8)} , asEntryDesc0x1600 , aName0x1600 , &OUT_GENERICProcessDataMapping0x1600 , NULL , NULL , 0x0000 },
/* Object 0x1A00 */
{NULL , NULL ,  0x1A00 , {DEFTYPE_PDOMAPPING , 68 | (OBJCODE_REC << 8)} , asEntryDesc0x1A00 , aName0x1A00 , &IN_GENERICProcessDataMapping0x1A00 , NULL , NULL , 0x0000 },
/* Object 0x1C12 */
{NULL , NULL ,  0x1C12 , {DEFTYPE_UNSIGNED16 , 1 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C12 , aName0x1C12 , &sRxPDOassign , NULL , NULL , 0x0000 },
/* Object 0x1C13 */
{NULL , NULL ,  0x1C13 , {DEFTYPE_UNSIGNED16 , 1 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C13 , aName0x1C13 , &sTxPDOassign , NULL , NULL , 0x0000 },
/* Object 0x6000 */
{NULL , NULL ,  0x6000 , {DEFTYPE_RECORD , 68 | (OBJCODE_REC << 8)} , asEntryDesc0x6000 , aName0x6000 , &IN_GENERIC0x6000 , NULL , NULL , 0x0000 },
/* Object 0x7000 */
{NULL , NULL ,  0x7000 , {DEFTYPE_RECORD , 65 | (OBJCODE_REC << 8)} , asEntryDesc0x7000 , aName0x7000 , &OUT_GENERIC0x7000 , NULL , NULL , 0x0000 },
/* Object 0x8000 */
{NULL , NULL ,  0x8000 , {DEFTYPE_RECORD , 20 | (OBJCODE_REC << 8)} , asEntryDesc0x8000 , aName0x8000 , &ParameterConfiguration0x8000 , NULL , NULL , 0x0000 },
/* Object 0xF000 */
{NULL , NULL ,  0xF000 , {DEFTYPE_RECORD , 2 | (OBJCODE_REC << 8)} , asEntryDesc0xF000 , aName0xF000 , &ModularDeviceProfile0xF000 , NULL , NULL , 0x0000 },
{NULL,NULL, 0xFFFF, {0, 0}, NULL, NULL, NULL, NULL}};
#endif    //#ifdef _OBJD_

#undef PROTO

/** @}*/
#define _ROBOT_DEVICE_OBJECTS_H_
