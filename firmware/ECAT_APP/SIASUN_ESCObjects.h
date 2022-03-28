/**
* \addtogroup SIASUN_ESC SIASUN_ESC
* @{
*/

/**
\file SIASUN_ESCObjects
\author ET9300Utilities.ApplicationHandler (Version 1.3.6.0) | EthercatSSC@beckhoff.com

\brief SIASUN_ESC specific objects<br>
\brief NOTE : This file will be overwritten if a new object dictionary is generated!<br>
*/

#if defined(_SIASUN__ESC_) && (_SIASUN__ESC_ == 1)
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
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex52 - Reference to 0x7000.52 */

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
"SubIndex 052\000\377";
#endif //#ifdef _OBJD_

#ifndef _SIASUN__ESC_OBJECTS_H_
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
} OBJ_STRUCT_PACKED_END
TOBJ1600;
#endif //#ifndef _SIASUN__ESC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1600 OUT_GENERICProcessDataMapping0x1600
#if defined(_SIASUN__ESC_) && (_SIASUN__ESC_ == 1)
={52,0x70000110,0x70000210,0x70000310,0x70000410,0x70000510,0x70000610,0x70000710,0x70000810,0x70000910,0x70000A10,0x70000B10,0x70000C10,0x70000D10,0x70000E10,0x70000F10,0x70001010,0x70001110,0x70001210,0x70001310,0x70001410,0x70001501,0x70001601,0x70001701,0x70001801,0x70001901,0x70001A01,0x70001B01,0x70001C01,0x70001D01,0x70001E01,0x70001F01,0x70002001,0x70002101,0x70002201,0x70002301,0x70002401,0x70002501,0x70002601,0x70002701,0x70002801,0x70002901,0x70002A01,0x70002B01,0x70002C01,0x70002D01,0x70002E01,0x70002F01,0x70003001,0x70003101,0x70003201,0x70003301,0x70003401}
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
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex52 - Reference to 0x6000.52 */

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
"SubIndex 052\000\377";
#endif //#ifdef _OBJD_

#ifndef _SIASUN__ESC_OBJECTS_H_
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
} OBJ_STRUCT_PACKED_END
TOBJ1A00;
#endif //#ifndef _SIASUN__ESC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A00 IN_GENERICProcessDataMapping0x1A00
#if defined(_SIASUN__ESC_) && (_SIASUN__ESC_ == 1)
={52,0x60000110,0x60000210,0x60000310,0x60000410,0x60000510,0x60000610,0x60000710,0x60000810,0x60000910,0x60000A10,0x60000B10,0x60000C10,0x60000D10,0x60000E10,0x60000F10,0x60001010,0x60001110,0x60001210,0x60001310,0x60001410,0x60001501,0x60001601,0x60001701,0x60001801,0x60001901,0x60001A01,0x60001B01,0x60001C01,0x60001D01,0x60001E01,0x60001F01,0x60002001,0x60002101,0x60002201,0x60002301,0x60002401,0x60002501,0x60002601,0x60002701,0x60002801,0x60002901,0x60002A01,0x60002B01,0x60002C01,0x60002D01,0x60002E01,0x60002F01,0x60003001,0x60003101,0x60003201,0x60003301,0x60003401}
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

#ifndef _SIASUN__ESC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[1];  /**< \brief Subindex 1 - 1 */
} OBJ_STRUCT_PACKED_END
TOBJ1C12;
#endif //#ifndef _SIASUN__ESC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C12 sRxPDOassign
#if defined(_SIASUN__ESC_) && (_SIASUN__ESC_ == 1)
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

#ifndef _SIASUN__ESC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[1];  /**< \brief Subindex 1 - 1 */
} OBJ_STRUCT_PACKED_END
TOBJ1C13;
#endif //#ifndef _SIASUN__ESC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C13 sTxPDOassign
#if defined(_SIASUN__ESC_) && (_SIASUN__ESC_ == 1)
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
* SubIndex 1 - U485_AI1<br>
* SubIndex 2 - U485_AI2<br>
* SubIndex 3 - U485_AI3<br>
* SubIndex 4 - U485_AI4<br>
* SubIndex 5 - IN_BOX_AI1<br>
* SubIndex 6 - IN_BOX_AI2<br>
* SubIndex 7 - IN_BOX_AI3<br>
* SubIndex 8 - IN_BOX_AI4<br>
* SubIndex 9 - IN_BOX_AI5<br>
* SubIndex 10 - IN_BOX_AI6<br>
* SubIndex 11 - IN_BOX_AI7<br>
* SubIndex 12 - IN_BOX_AI8<br>
* SubIndex 13 - IN_BOX_AI9<br>
* SubIndex 14 - IN_BOX_AI10<br>
* SubIndex 15 - OUT_BOX_AI1<br>
* SubIndex 16 - OUT_BOX_AI2<br>
* SubIndex 17 - CAN_AI1<br>
* SubIndex 18 - CAN_AI2<br>
* SubIndex 19 - CAN_AI3<br>
* SubIndex 20 - CAN_AI4<br>
* SubIndex 21 - U485_DI1<br>
* SubIndex 22 - U485_DI2<br>
* SubIndex 23 - U485_DI3<br>
* SubIndex 24 - U485_DI4<br>
* SubIndex 25 - U485_DI5<br>
* SubIndex 26 - U485_DI6<br>
* SubIndex 27 - U485_DI7<br>
* SubIndex 28 - U485_DI8<br>
* SubIndex 29 - IN_BOX_DI1<br>
* SubIndex 30 - IN_BOX_DI2<br>
* SubIndex 31 - IN_BOX_DI3<br>
* SubIndex 32 - IN_BOX_DI4<br>
* SubIndex 33 - IN_BOX_DI5<br>
* SubIndex 34 - IN_BOX_DI6<br>
* SubIndex 35 - IN_BOX_DI7<br>
* SubIndex 36 - IN_BOX_DI8<br>
* SubIndex 37 - OUT_BOX_DI1<br>
* SubIndex 38 - OUT_BOX_DI2<br>
* SubIndex 39 - OUT_BOX_DI3<br>
* SubIndex 40 - OUT_BOX_DI4<br>
* SubIndex 41 - CAN_DI1<br>
* SubIndex 42 - CAN_DI2<br>
* SubIndex 43 - CAN_DI3<br>
* SubIndex 44 - CAN_DI4<br>
* SubIndex 45 - SPARE_DI1<br>
* SubIndex 46 - SPARE_DI2<br>
* SubIndex 47 - SPARE_DI3<br>
* SubIndex 48 - SPARE_DI4<br>
* SubIndex 49 - SPARE_DI5<br>
* SubIndex 50 - SPARE_DI6<br>
* SubIndex 51 - SPARE_DI7<br>
* SubIndex 52 - SPARE_DI8<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex1 - U485_AI1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex2 - U485_AI2 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex3 - U485_AI3 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex4 - U485_AI4 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex5 - IN_BOX_AI1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex6 - IN_BOX_AI2 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex7 - IN_BOX_AI3 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex8 - IN_BOX_AI4 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex9 - IN_BOX_AI5 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex10 - IN_BOX_AI6 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex11 - IN_BOX_AI7 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex12 - IN_BOX_AI8 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex13 - IN_BOX_AI9 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex14 - IN_BOX_AI10 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex15 - OUT_BOX_AI1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex16 - OUT_BOX_AI2 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex17 - CAN_AI1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex18 - CAN_AI2 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex19 - CAN_AI3 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex20 - CAN_AI4 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex21 - U485_DI1 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex22 - U485_DI2 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex23 - U485_DI3 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex24 - U485_DI4 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex25 - U485_DI5 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex26 - U485_DI6 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex27 - U485_DI7 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex28 - U485_DI8 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex29 - IN_BOX_DI1 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex30 - IN_BOX_DI2 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex31 - IN_BOX_DI3 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex32 - IN_BOX_DI4 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex33 - IN_BOX_DI5 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex34 - IN_BOX_DI6 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex35 - IN_BOX_DI7 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex36 - IN_BOX_DI8 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex37 - OUT_BOX_DI1 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex38 - OUT_BOX_DI2 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex39 - OUT_BOX_DI3 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex40 - OUT_BOX_DI4 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex41 - CAN_DI1 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex42 - CAN_DI2 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex43 - CAN_DI3 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex44 - CAN_DI4 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex45 - SPARE_DI1 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex46 - SPARE_DI2 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex47 - SPARE_DI3 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex48 - SPARE_DI4 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex49 - SPARE_DI5 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex50 - SPARE_DI6 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex51 - SPARE_DI7 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }}; /* Subindex52 - SPARE_DI8 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6000[] = "IN_GENERIC\000"
"U485_AI1\000"
"U485_AI2\000"
"U485_AI3\000"
"U485_AI4\000"
"IN_BOX_AI1\000"
"IN_BOX_AI2\000"
"IN_BOX_AI3\000"
"IN_BOX_AI4\000"
"IN_BOX_AI5\000"
"IN_BOX_AI6\000"
"IN_BOX_AI7\000"
"IN_BOX_AI8\000"
"IN_BOX_AI9\000"
"IN_BOX_AI10\000"
"OUT_BOX_AI1\000"
"OUT_BOX_AI2\000"
"CAN_AI1\000"
"CAN_AI2\000"
"CAN_AI3\000"
"CAN_AI4\000"
"U485_DI1\000"
"U485_DI2\000"
"U485_DI3\000"
"U485_DI4\000"
"U485_DI5\000"
"U485_DI6\000"
"U485_DI7\000"
"U485_DI8\000"
"IN_BOX_DI1\000"
"IN_BOX_DI2\000"
"IN_BOX_DI3\000"
"IN_BOX_DI4\000"
"IN_BOX_DI5\000"
"IN_BOX_DI6\000"
"IN_BOX_DI7\000"
"IN_BOX_DI8\000"
"OUT_BOX_DI1\000"
"OUT_BOX_DI2\000"
"OUT_BOX_DI3\000"
"OUT_BOX_DI4\000"
"CAN_DI1\000"
"CAN_DI2\000"
"CAN_DI3\000"
"CAN_DI4\000"
"SPARE_DI1\000"
"SPARE_DI2\000"
"SPARE_DI3\000"
"SPARE_DI4\000"
"SPARE_DI5\000"
"SPARE_DI6\000"
"SPARE_DI7\000"
"SPARE_DI8\000\377";
#endif //#ifdef _OBJD_

#ifndef _SIASUN__ESC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT16 U485_AI1; /* Subindex1 - U485_AI1 */
UINT16 U485_AI2; /* Subindex2 - U485_AI2 */
UINT16 U485_AI3; /* Subindex3 - U485_AI3 */
UINT16 U485_AI4; /* Subindex4 - U485_AI4 */
UINT16 IN_BOX_AI1; /* Subindex5 - IN_BOX_AI1 */
UINT16 IN_BOX_AI2; /* Subindex6 - IN_BOX_AI2 */
UINT16 IN_BOX_AI3; /* Subindex7 - IN_BOX_AI3 */
UINT16 IN_BOX_AI4; /* Subindex8 - IN_BOX_AI4 */
UINT16 IN_BOX_AI5; /* Subindex9 - IN_BOX_AI5 */
UINT16 IN_BOX_AI6; /* Subindex10 - IN_BOX_AI6 */
UINT16 IN_BOX_AI7; /* Subindex11 - IN_BOX_AI7 */
UINT16 IN_BOX_AI8; /* Subindex12 - IN_BOX_AI8 */
UINT16 IN_BOX_AI9; /* Subindex13 - IN_BOX_AI9 */
UINT16 IN_BOX_AI10; /* Subindex14 - IN_BOX_AI10 */
UINT16 OUT_BOX_AI1; /* Subindex15 - OUT_BOX_AI1 */
UINT16 OUT_BOX_AI2; /* Subindex16 - OUT_BOX_AI2 */
UINT16 CAN_AI1; /* Subindex17 - CAN_AI1 */
UINT16 CAN_AI2; /* Subindex18 - CAN_AI2 */
UINT16 CAN_AI3; /* Subindex19 - CAN_AI3 */
UINT16 CAN_AI4; /* Subindex20 - CAN_AI4 */
BOOLEAN(U485_DI1); /* Subindex21 - U485_DI1 */
BOOLEAN(U485_DI2); /* Subindex22 - U485_DI2 */
BOOLEAN(U485_DI3); /* Subindex23 - U485_DI3 */
BOOLEAN(U485_DI4); /* Subindex24 - U485_DI4 */
BOOLEAN(U485_DI5); /* Subindex25 - U485_DI5 */
BOOLEAN(U485_DI6); /* Subindex26 - U485_DI6 */
BOOLEAN(U485_DI7); /* Subindex27 - U485_DI7 */
BOOLEAN(U485_DI8); /* Subindex28 - U485_DI8 */
BOOLEAN(IN_BOX_DI1); /* Subindex29 - IN_BOX_DI1 */
BOOLEAN(IN_BOX_DI2); /* Subindex30 - IN_BOX_DI2 */
BOOLEAN(IN_BOX_DI3); /* Subindex31 - IN_BOX_DI3 */
BOOLEAN(IN_BOX_DI4); /* Subindex32 - IN_BOX_DI4 */
BOOLEAN(IN_BOX_DI5); /* Subindex33 - IN_BOX_DI5 */
BOOLEAN(IN_BOX_DI6); /* Subindex34 - IN_BOX_DI6 */
BOOLEAN(IN_BOX_DI7); /* Subindex35 - IN_BOX_DI7 */
BOOLEAN(IN_BOX_DI8); /* Subindex36 - IN_BOX_DI8 */
BOOLEAN(OUT_BOX_DI1); /* Subindex37 - OUT_BOX_DI1 */
BOOLEAN(OUT_BOX_DI2); /* Subindex38 - OUT_BOX_DI2 */
BOOLEAN(OUT_BOX_DI3); /* Subindex39 - OUT_BOX_DI3 */
BOOLEAN(OUT_BOX_DI4); /* Subindex40 - OUT_BOX_DI4 */
BOOLEAN(CAN_DI1); /* Subindex41 - CAN_DI1 */
BOOLEAN(CAN_DI2); /* Subindex42 - CAN_DI2 */
BOOLEAN(CAN_DI3); /* Subindex43 - CAN_DI3 */
BOOLEAN(CAN_DI4); /* Subindex44 - CAN_DI4 */
BOOLEAN(SPARE_DI1); /* Subindex45 - SPARE_DI1 */
BOOLEAN(SPARE_DI2); /* Subindex46 - SPARE_DI2 */
BOOLEAN(SPARE_DI3); /* Subindex47 - SPARE_DI3 */
BOOLEAN(SPARE_DI4); /* Subindex48 - SPARE_DI4 */
BOOLEAN(SPARE_DI5); /* Subindex49 - SPARE_DI5 */
BOOLEAN(SPARE_DI6); /* Subindex50 - SPARE_DI6 */
BOOLEAN(SPARE_DI7); /* Subindex51 - SPARE_DI7 */
BOOLEAN(SPARE_DI8); /* Subindex52 - SPARE_DI8 */
} OBJ_STRUCT_PACKED_END
TOBJ6000;
#endif //#ifndef _SIASUN__ESC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6000 IN_GENERIC0x6000
#if defined(_SIASUN__ESC_) && (_SIASUN__ESC_ == 1)
={52,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
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
* SubIndex 1 - U485_AO1<br>
* SubIndex 2 - U485_AO2<br>
* SubIndex 3 - U485_AO3<br>
* SubIndex 4 - U485_AO4<br>
* SubIndex 5 - IN_BOX_AO1<br>
* SubIndex 6 - IN_BOX_AO2<br>
* SubIndex 7 - IN_BOX_AO3<br>
* SubIndex 8 - IN_BOX_AO4<br>
* SubIndex 9 - IN_BOX_AO5<br>
* SubIndex 10 - IN_BOX_AO6<br>
* SubIndex 11 - IN_BOX_AO7<br>
* SubIndex 12 - IN_BOX_AO8<br>
* SubIndex 13 - OUT_BOX_AO1<br>
* SubIndex 14 - OUT_BOX_AO2<br>
* SubIndex 15 - OUT_BOX_AO3<br>
* SubIndex 16 - OUT_BOX_AO4<br>
* SubIndex 17 - CAN_AO1<br>
* SubIndex 18 - CAN_AO2<br>
* SubIndex 19 - CAN_AO3<br>
* SubIndex 20 - CAN_AO4<br>
* SubIndex 21 - U485_DO1<br>
* SubIndex 22 - U485_DO2<br>
* SubIndex 23 - U485_DO3<br>
* SubIndex 24 - U485_DO4<br>
* SubIndex 25 - U485_DO5<br>
* SubIndex 26 - U485_DO6<br>
* SubIndex 27 - U485_DO7<br>
* SubIndex 28 - U485_DO8<br>
* SubIndex 29 - IN_BOX_DO1<br>
* SubIndex 30 - IN_BOX_DO2<br>
* SubIndex 31 - IN_BOX_DO3<br>
* SubIndex 32 - IN_BOX_DO4<br>
* SubIndex 33 - IN_BOX_DO5<br>
* SubIndex 34 - IN_BOX_DO6<br>
* SubIndex 35 - IN_BOX_DO7<br>
* SubIndex 36 - IN_BOX_DO8<br>
* SubIndex 37 - OUT_BOX_DO1<br>
* SubIndex 38 - OUT_BOX_DO2<br>
* SubIndex 39 - OUT_BOX_DO3<br>
* SubIndex 40 - OUT_BOX_DO4<br>
* SubIndex 41 - CAN_DO1<br>
* SubIndex 42 - CAN_DO2<br>
* SubIndex 43 - CAN_DO3<br>
* SubIndex 44 - CAN_DO4<br>
* SubIndex 45 - SPARE_DO1<br>
* SubIndex 46 - SPARE_DO2<br>
* SubIndex 47 - SPARE_DO3<br>
* SubIndex 48 - SPARE_DO4<br>
* SubIndex 49 - SPARE_DO5<br>
* SubIndex 50 - SPARE_DO6<br>
* SubIndex 51 - SPARE_DO7<br>
* SubIndex 52 - SPARE_DO8<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex1 - U485_AO1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex2 - U485_AO2 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex3 - U485_AO3 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex4 - U485_AO4 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex5 - IN_BOX_AO1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex6 - IN_BOX_AO2 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex7 - IN_BOX_AO3 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex8 - IN_BOX_AO4 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex9 - IN_BOX_AO5 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex10 - IN_BOX_AO6 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex11 - IN_BOX_AO7 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex12 - IN_BOX_AO8 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex13 - OUT_BOX_AO1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex14 - OUT_BOX_AO2 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex15 - OUT_BOX_AO3 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex16 - OUT_BOX_AO4 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex17 - CAN_AO1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex18 - CAN_AO2 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex19 - CAN_AO3 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex20 - CAN_AO4 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex21 - U485_DO1 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex22 - U485_DO2 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex23 - U485_DO3 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex24 - U485_DO4 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex25 - U485_DO5 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex26 - U485_DO6 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex27 - U485_DO7 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex28 - U485_DO8 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex29 - IN_BOX_DO1 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex30 - IN_BOX_DO2 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex31 - IN_BOX_DO3 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex32 - IN_BOX_DO4 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex33 - IN_BOX_DO5 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex34 - IN_BOX_DO6 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex35 - IN_BOX_DO7 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex36 - IN_BOX_DO8 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex37 - OUT_BOX_DO1 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex38 - OUT_BOX_DO2 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex39 - OUT_BOX_DO3 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex40 - OUT_BOX_DO4 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex41 - CAN_DO1 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex42 - CAN_DO2 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex43 - CAN_DO3 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex44 - CAN_DO4 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex45 - SPARE_DO1 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex46 - SPARE_DO2 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex47 - SPARE_DO3 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex48 - SPARE_DO4 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex49 - SPARE_DO5 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex50 - SPARE_DO6 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex51 - SPARE_DO7 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }}; /* Subindex52 - SPARE_DO8 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x7000[] = "OUT_GENERIC\000"
"U485_AO1\000"
"U485_AO2\000"
"U485_AO3\000"
"U485_AO4\000"
"IN_BOX_AO1\000"
"IN_BOX_AO2\000"
"IN_BOX_AO3\000"
"IN_BOX_AO4\000"
"IN_BOX_AO5\000"
"IN_BOX_AO6\000"
"IN_BOX_AO7\000"
"IN_BOX_AO8\000"
"OUT_BOX_AO1\000"
"OUT_BOX_AO2\000"
"OUT_BOX_AO3\000"
"OUT_BOX_AO4\000"
"CAN_AO1\000"
"CAN_AO2\000"
"CAN_AO3\000"
"CAN_AO4\000"
"U485_DO1\000"
"U485_DO2\000"
"U485_DO3\000"
"U485_DO4\000"
"U485_DO5\000"
"U485_DO6\000"
"U485_DO7\000"
"U485_DO8\000"
"IN_BOX_DO1\000"
"IN_BOX_DO2\000"
"IN_BOX_DO3\000"
"IN_BOX_DO4\000"
"IN_BOX_DO5\000"
"IN_BOX_DO6\000"
"IN_BOX_DO7\000"
"IN_BOX_DO8\000"
"OUT_BOX_DO1\000"
"OUT_BOX_DO2\000"
"OUT_BOX_DO3\000"
"OUT_BOX_DO4\000"
"CAN_DO1\000"
"CAN_DO2\000"
"CAN_DO3\000"
"CAN_DO4\000"
"SPARE_DO1\000"
"SPARE_DO2\000"
"SPARE_DO3\000"
"SPARE_DO4\000"
"SPARE_DO5\000"
"SPARE_DO6\000"
"SPARE_DO7\000"
"SPARE_DO8\000\377";
#endif //#ifdef _OBJD_

#ifndef _SIASUN__ESC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT16 U485_AO1; /* Subindex1 - U485_AO1 */
UINT16 U485_AO2; /* Subindex2 - U485_AO2 */
UINT16 U485_AO3; /* Subindex3 - U485_AO3 */
UINT16 U485_AO4; /* Subindex4 - U485_AO4 */
UINT16 IN_BOX_AO1; /* Subindex5 - IN_BOX_AO1 */
UINT16 IN_BOX_AO2; /* Subindex6 - IN_BOX_AO2 */
UINT16 IN_BOX_AO3; /* Subindex7 - IN_BOX_AO3 */
UINT16 IN_BOX_AO4; /* Subindex8 - IN_BOX_AO4 */
UINT16 IN_BOX_AO5; /* Subindex9 - IN_BOX_AO5 */
UINT16 IN_BOX_AO6; /* Subindex10 - IN_BOX_AO6 */
UINT16 IN_BOX_AO7; /* Subindex11 - IN_BOX_AO7 */
UINT16 IN_BOX_AO8; /* Subindex12 - IN_BOX_AO8 */
UINT16 OUT_BOX_AO1; /* Subindex13 - OUT_BOX_AO1 */
UINT16 OUT_BOX_AO2; /* Subindex14 - OUT_BOX_AO2 */
UINT16 OUT_BOX_AO3; /* Subindex15 - OUT_BOX_AO3 */
UINT16 OUT_BOX_AO4; /* Subindex16 - OUT_BOX_AO4 */
UINT16 CAN_AO1; /* Subindex17 - CAN_AO1 */
UINT16 CAN_AO2; /* Subindex18 - CAN_AO2 */
UINT16 CAN_AO3; /* Subindex19 - CAN_AO3 */
UINT16 CAN_AO4; /* Subindex20 - CAN_AO4 */
BOOLEAN(U485_DO1); /* Subindex21 - U485_DO1 */
BOOLEAN(U485_DO2); /* Subindex22 - U485_DO2 */
BOOLEAN(U485_DO3); /* Subindex23 - U485_DO3 */
BOOLEAN(U485_DO4); /* Subindex24 - U485_DO4 */
BOOLEAN(U485_DO5); /* Subindex25 - U485_DO5 */
BOOLEAN(U485_DO6); /* Subindex26 - U485_DO6 */
BOOLEAN(U485_DO7); /* Subindex27 - U485_DO7 */
BOOLEAN(U485_DO8); /* Subindex28 - U485_DO8 */
BOOLEAN(IN_BOX_DO1); /* Subindex29 - IN_BOX_DO1 */
BOOLEAN(IN_BOX_DO2); /* Subindex30 - IN_BOX_DO2 */
BOOLEAN(IN_BOX_DO3); /* Subindex31 - IN_BOX_DO3 */
BOOLEAN(IN_BOX_DO4); /* Subindex32 - IN_BOX_DO4 */
BOOLEAN(IN_BOX_DO5); /* Subindex33 - IN_BOX_DO5 */
BOOLEAN(IN_BOX_DO6); /* Subindex34 - IN_BOX_DO6 */
BOOLEAN(IN_BOX_DO7); /* Subindex35 - IN_BOX_DO7 */
BOOLEAN(IN_BOX_DO8); /* Subindex36 - IN_BOX_DO8 */
BOOLEAN(OUT_BOX_DO1); /* Subindex37 - OUT_BOX_DO1 */
BOOLEAN(OUT_BOX_DO2); /* Subindex38 - OUT_BOX_DO2 */
BOOLEAN(OUT_BOX_DO3); /* Subindex39 - OUT_BOX_DO3 */
BOOLEAN(OUT_BOX_DO4); /* Subindex40 - OUT_BOX_DO4 */
BOOLEAN(CAN_DO1); /* Subindex41 - CAN_DO1 */
BOOLEAN(CAN_DO2); /* Subindex42 - CAN_DO2 */
BOOLEAN(CAN_DO3); /* Subindex43 - CAN_DO3 */
BOOLEAN(CAN_DO4); /* Subindex44 - CAN_DO4 */
BOOLEAN(SPARE_DO1); /* Subindex45 - SPARE_DO1 */
BOOLEAN(SPARE_DO2); /* Subindex46 - SPARE_DO2 */
BOOLEAN(SPARE_DO3); /* Subindex47 - SPARE_DO3 */
BOOLEAN(SPARE_DO4); /* Subindex48 - SPARE_DO4 */
BOOLEAN(SPARE_DO5); /* Subindex49 - SPARE_DO5 */
BOOLEAN(SPARE_DO6); /* Subindex50 - SPARE_DO6 */
BOOLEAN(SPARE_DO7); /* Subindex51 - SPARE_DO7 */
BOOLEAN(SPARE_DO8); /* Subindex52 - SPARE_DO8 */
} OBJ_STRUCT_PACKED_END
TOBJ7000;
#endif //#ifndef _SIASUN__ESC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ7000 OUT_GENERIC0x7000
#if defined(_SIASUN__ESC_) && (_SIASUN__ESC_ == 1)
={52,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
#endif
;
/** @}*/







#ifdef _OBJD_
TOBJECT    OBJMEM ApplicationObjDic[] = {
/* Object 0x1600 */
{NULL , NULL ,  0x1600 , {DEFTYPE_PDOMAPPING , 52 | (OBJCODE_REC << 8)} , asEntryDesc0x1600 , aName0x1600 , &OUT_GENERICProcessDataMapping0x1600, NULL , NULL , 0x0000 },
/* Object 0x1A00 */
{NULL , NULL ,  0x1A00 , {DEFTYPE_PDOMAPPING , 52 | (OBJCODE_REC << 8)} , asEntryDesc0x1A00 , aName0x1A00 , &IN_GENERICProcessDataMapping0x1A00, NULL , NULL , 0x0000 },
/* Object 0x1C12 */
{NULL , NULL ,  0x1C12 , {DEFTYPE_UNSIGNED16 , 1 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C12 , aName0x1C12 , &sRxPDOassign, NULL , NULL , 0x0000 },
/* Object 0x1C13 */
{NULL , NULL ,  0x1C13 , {DEFTYPE_UNSIGNED16 , 1 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C13 , aName0x1C13 , &sTxPDOassign, NULL , NULL , 0x0000 },
/* Object 0x6000 */
{NULL , NULL ,  0x6000 , {DEFTYPE_RECORD , 52 | (OBJCODE_REC << 8)} , asEntryDesc0x6000 , aName0x6000 , &IN_GENERIC0x6000, NULL , NULL , 0x0000 },
/* Object 0x7000 */
{NULL , NULL ,  0x7000 , {DEFTYPE_RECORD , 52 | (OBJCODE_REC << 8)} , asEntryDesc0x7000 , aName0x7000 , &OUT_GENERIC0x7000, NULL , NULL , 0x0000 },
{NULL,NULL, 0xFFFF, {0, 0}, NULL, NULL, NULL, NULL}};
#endif    //#ifdef _OBJD_
#undef PROTO

/** @}*/
#define _SIASUN__ESC_OBJECTS_H_
