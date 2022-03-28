/**
* \addtogroup Robot-Device Robot-Device
* @{
*/

/**
\file Robot-DeviceObjects
\author ET9300Utilities.ApplicationHandler (Version 1.3.6.0) | EthercatSSC@beckhoff.com

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
* SubIndex 66 - Reference to 0x7000.66<br>
* SubIndex 67 - Reference to 0x7000.67<br>
* SubIndex 68 - Reference to 0x7000.68<br>
* SubIndex 69 - Reference to 0x7000.69<br>
* SubIndex 70 - Reference to 0x7000.70<br>
* SubIndex 71 - Reference to 0x7000.71<br>
* SubIndex 72 - Reference to 0x7000.72<br>
* SubIndex 73 - Reference to 0x7000.73<br>
* SubIndex 74 - Reference to 0x7000.74<br>
* SubIndex 75 - Reference to 0x7000.75<br>
* SubIndex 76 - Reference to 0x7000.76<br>
* SubIndex 77 - Reference to 0x7000.77<br>
* SubIndex 78 - Reference to 0x7000.78<br>
* SubIndex 79 - Reference to 0x7000.79<br>
* SubIndex 80 - Reference to 0x7000.80<br>
* SubIndex 81 - Reference to 0x7000.81<br>
* SubIndex 82 - Reference to 0x7000.82<br>
* SubIndex 83 - Reference to 0x7000.83<br>
* SubIndex 84 - Reference to 0x7000.84<br>
* SubIndex 85 - Reference to 0x7000.85<br>
* SubIndex 86 - Reference to 0x7000.86<br>
* SubIndex 87 - Reference to 0x7000.87<br>
* SubIndex 88 - Reference to 0x7000.88<br>
* SubIndex 89 - Reference to 0x7000.89<br>
* SubIndex 90 - Reference to 0x7000.90<br>
* SubIndex 91 - Reference to 0x7000.91<br>
* SubIndex 92 - Reference to 0x7000.92<br>
* SubIndex 93 - Reference to 0x7000.93<br>
* SubIndex 94 - Reference to 0x7000.94<br>
* SubIndex 95 - Reference to 0x7000.95<br>
* SubIndex 96 - Reference to 0x7000.96<br>
* SubIndex 97 - Reference to 0x7000.97<br>
* SubIndex 98 - Reference to 0x7000.98<br>
* SubIndex 99 - Reference to 0x7000.99<br>
* SubIndex 100 - Reference to 0x7000.100<br>
* SubIndex 101 - Reference to 0x7000.101<br>
* SubIndex 102 - Reference to 0x7000.102<br>
* SubIndex 103 - Reference to 0x7000.103<br>
* SubIndex 104 - Reference to 0x7000.104<br>
* SubIndex 105 - Reference to 0x7000.105<br>
* SubIndex 106 - Reference to 0x7000.106<br>
* SubIndex 107 - Reference to 0x7000.107<br>
* SubIndex 108 - Reference to 0x7000.108<br>
* SubIndex 109 - Reference to 0x7000.109<br>
* SubIndex 110 - Reference to 0x7000.110<br>
* SubIndex 111 - Reference to 0x7000.111<br>
* SubIndex 112 - Reference to 0x7000.112<br>
* SubIndex 113 - Reference to 0x7000.113<br>
* SubIndex 114 - Reference to 0x7000.114<br>
* SubIndex 115 - Reference to 0x7000.115<br>
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
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex65 - Reference to 0x7000.65 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex66 - Reference to 0x7000.66 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex67 - Reference to 0x7000.67 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex68 - Reference to 0x7000.68 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex69 - Reference to 0x7000.69 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex70 - Reference to 0x7000.70 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex71 - Reference to 0x7000.71 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex72 - Reference to 0x7000.72 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex73 - Reference to 0x7000.73 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex74 - Reference to 0x7000.74 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex75 - Reference to 0x7000.75 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex76 - Reference to 0x7000.76 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex77 - Reference to 0x7000.77 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex78 - Reference to 0x7000.78 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex79 - Reference to 0x7000.79 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex80 - Reference to 0x7000.80 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex81 - Reference to 0x7000.81 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex82 - Reference to 0x7000.82 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex83 - Reference to 0x7000.83 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex84 - Reference to 0x7000.84 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex85 - Reference to 0x7000.85 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex86 - Reference to 0x7000.86 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex87 - Reference to 0x7000.87 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex88 - Reference to 0x7000.88 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex89 - Reference to 0x7000.89 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex90 - Reference to 0x7000.90 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex91 - Reference to 0x7000.91 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex92 - Reference to 0x7000.92 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex93 - Reference to 0x7000.93 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex94 - Reference to 0x7000.94 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex95 - Reference to 0x7000.95 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex96 - Reference to 0x7000.96 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex97 - Reference to 0x7000.97 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex98 - Reference to 0x7000.98 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex99 - Reference to 0x7000.99 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex100 - Reference to 0x7000.100 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex101 - Reference to 0x7000.101 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex102 - Reference to 0x7000.102 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex103 - Reference to 0x7000.103 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex104 - Reference to 0x7000.104 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex105 - Reference to 0x7000.105 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex106 - Reference to 0x7000.106 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex107 - Reference to 0x7000.107 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex108 - Reference to 0x7000.108 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex109 - Reference to 0x7000.109 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex110 - Reference to 0x7000.110 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex111 - Reference to 0x7000.111 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex112 - Reference to 0x7000.112 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex113 - Reference to 0x7000.113 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex114 - Reference to 0x7000.114 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex115 - Reference to 0x7000.115 */

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
"SubIndex 065\000"
"SubIndex 066\000"
"SubIndex 067\000"
"SubIndex 068\000"
"SubIndex 069\000"
"SubIndex 070\000"
"SubIndex 071\000"
"SubIndex 072\000"
"SubIndex 073\000"
"SubIndex 074\000"
"SubIndex 075\000"
"SubIndex 076\000"
"SubIndex 077\000"
"SubIndex 078\000"
"SubIndex 079\000"
"SubIndex 080\000"
"SubIndex 081\000"
"SubIndex 082\000"
"SubIndex 083\000"
"SubIndex 084\000"
"SubIndex 085\000"
"SubIndex 086\000"
"SubIndex 087\000"
"SubIndex 088\000"
"SubIndex 089\000"
"SubIndex 090\000"
"SubIndex 091\000"
"SubIndex 092\000"
"SubIndex 093\000"
"SubIndex 094\000"
"SubIndex 095\000"
"SubIndex 096\000"
"SubIndex 097\000"
"SubIndex 098\000"
"SubIndex 099\000"
"SubIndex 100\000"
"SubIndex 101\000"
"SubIndex 102\000"
"SubIndex 103\000"
"SubIndex 104\000"
"SubIndex 105\000"
"SubIndex 106\000"
"SubIndex 107\000"
"SubIndex 108\000"
"SubIndex 109\000"
"SubIndex 110\000"
"SubIndex 111\000"
"SubIndex 112\000"
"SubIndex 113\000"
"SubIndex 114\000"
"SubIndex 115\000\377";
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
UINT32 SI66; /* Subindex66 - Reference to 0x7000.66 */
UINT32 SI67; /* Subindex67 - Reference to 0x7000.67 */
UINT32 SI68; /* Subindex68 - Reference to 0x7000.68 */
UINT32 SI69; /* Subindex69 - Reference to 0x7000.69 */
UINT32 SI70; /* Subindex70 - Reference to 0x7000.70 */
UINT32 SI71; /* Subindex71 - Reference to 0x7000.71 */
UINT32 SI72; /* Subindex72 - Reference to 0x7000.72 */
UINT32 SI73; /* Subindex73 - Reference to 0x7000.73 */
UINT32 SI74; /* Subindex74 - Reference to 0x7000.74 */
UINT32 SI75; /* Subindex75 - Reference to 0x7000.75 */
UINT32 SI76; /* Subindex76 - Reference to 0x7000.76 */
UINT32 SI77; /* Subindex77 - Reference to 0x7000.77 */
UINT32 SI78; /* Subindex78 - Reference to 0x7000.78 */
UINT32 SI79; /* Subindex79 - Reference to 0x7000.79 */
UINT32 SI80; /* Subindex80 - Reference to 0x7000.80 */
UINT32 SI81; /* Subindex81 - Reference to 0x7000.81 */
UINT32 SI82; /* Subindex82 - Reference to 0x7000.82 */
UINT32 SI83; /* Subindex83 - Reference to 0x7000.83 */
UINT32 SI84; /* Subindex84 - Reference to 0x7000.84 */
UINT32 SI85; /* Subindex85 - Reference to 0x7000.85 */
UINT32 SI86; /* Subindex86 - Reference to 0x7000.86 */
UINT32 SI87; /* Subindex87 - Reference to 0x7000.87 */
UINT32 SI88; /* Subindex88 - Reference to 0x7000.88 */
UINT32 SI89; /* Subindex89 - Reference to 0x7000.89 */
UINT32 SI90; /* Subindex90 - Reference to 0x7000.90 */
UINT32 SI91; /* Subindex91 - Reference to 0x7000.91 */
UINT32 SI92; /* Subindex92 - Reference to 0x7000.92 */
UINT32 SI93; /* Subindex93 - Reference to 0x7000.93 */
UINT32 SI94; /* Subindex94 - Reference to 0x7000.94 */
UINT32 SI95; /* Subindex95 - Reference to 0x7000.95 */
UINT32 SI96; /* Subindex96 - Reference to 0x7000.96 */
UINT32 SI97; /* Subindex97 - Reference to 0x7000.97 */
UINT32 SI98; /* Subindex98 - Reference to 0x7000.98 */
UINT32 SI99; /* Subindex99 - Reference to 0x7000.99 */
UINT32 SI100; /* Subindex100 - Reference to 0x7000.100 */
UINT32 SI101; /* Subindex101 - Reference to 0x7000.101 */
UINT32 SI102; /* Subindex102 - Reference to 0x7000.102 */
UINT32 SI103; /* Subindex103 - Reference to 0x7000.103 */
UINT32 SI104; /* Subindex104 - Reference to 0x7000.104 */
UINT32 SI105; /* Subindex105 - Reference to 0x7000.105 */
UINT32 SI106; /* Subindex106 - Reference to 0x7000.106 */
UINT32 SI107; /* Subindex107 - Reference to 0x7000.107 */
UINT32 SI108; /* Subindex108 - Reference to 0x7000.108 */
UINT32 SI109; /* Subindex109 - Reference to 0x7000.109 */
UINT32 SI110; /* Subindex110 - Reference to 0x7000.110 */
UINT32 SI111; /* Subindex111 - Reference to 0x7000.111 */
UINT32 SI112; /* Subindex112 - Reference to 0x7000.112 */
UINT32 SI113; /* Subindex113 - Reference to 0x7000.113 */
UINT32 SI114; /* Subindex114 - Reference to 0x7000.114 */
UINT32 SI115; /* Subindex115 - Reference to 0x7000.115 */
} OBJ_STRUCT_PACKED_END
TOBJ1600;
#endif //#ifndef _ROBOT_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1600 OUT_GENERICProcessDataMapping0x1600
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
={115,0x70000101,0x70000201,0x70000301,0x70000401,0x70000501,0x70000601,0x70000701,0x70000801,0x70000901,0x70000A01,0x70000B01,0x70000C01,0x70000D01,0x70000E01,0x70000F01,0x70001001,0x70001110,0x70001210,0x70001308,0x70001408,0x70001508,0x70001608,0x70001708,0x70001808,0x70001908,0x70001A08,0x70001B08,0x70001C08,0x70001D08,0x70001E08,0x70001F08,0x70002008,0x70002108,0x70002208,0x70002308,0x70002408,0x70002508,0x70002608,0x70002708,0x70002808,0x70002908,0x70002A08,0x70002B08,0x70002C08,0x70002D08,0x70002E08,0x70002F08,0x70003008,0x70003108,0x70003208,0x70003310,0x70003410,0x70003510,0x70003608,0x70003708,0x70003808,0x70003908,0x70003A08,0x70003B08,0x70003C08,0x70003D08,0x70003E01,0x70003F01,0x70004001,0x70004101,0x70004201,0x70004301,0x70004401,0x70004501,0x70004601,0x70004701,0x70004801,0x70004901,0x70004A01,0x70004B01,0x70004C01,0x70004D01,0x70004E10,0x70004F10,0x70005008,0x70005108,0x70005208,0x70005308,0x70005408,0x70005508,0x70005608,0x70005708,0x70005808,0x70005908,0x70005A08,0x70005B08,0x70005C08,0x70005D08,0x70005E08,0x70005F08,0x70006008,0x70006108,0x70006208,0x70006308,0x70006408,0x70006508,0x70006608,0x70006708,0x70006808,0x70006908,0x70006A08,0x70006B08,0x70006C08,0x70006D08,0x70006E08,0x70006F08,0x70007010,0x70007110,0x70007210,0x70007310}
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
* SubIndex 69 - Reference to 0x6000.69<br>
* SubIndex 70 - Reference to 0x6000.70<br>
* SubIndex 71 - Reference to 0x6000.71<br>
* SubIndex 72 - Reference to 0x6000.72<br>
* SubIndex 73 - Reference to 0x6000.73<br>
* SubIndex 74 - Reference to 0x6000.74<br>
* SubIndex 75 - Reference to 0x6000.75<br>
* SubIndex 76 - Reference to 0x6000.76<br>
* SubIndex 77 - Reference to 0x6000.77<br>
* SubIndex 78 - Reference to 0x6000.78<br>
* SubIndex 79 - Reference to 0x6000.79<br>
* SubIndex 80 - Reference to 0x6000.80<br>
* SubIndex 81 - Reference to 0x6000.81<br>
* SubIndex 82 - Reference to 0x6000.82<br>
* SubIndex 83 - Reference to 0x6000.83<br>
* SubIndex 84 - Reference to 0x6000.84<br>
* SubIndex 85 - Reference to 0x6000.85<br>
* SubIndex 86 - Reference to 0x6000.86<br>
* SubIndex 87 - Reference to 0x6000.87<br>
* SubIndex 88 - Reference to 0x6000.88<br>
* SubIndex 89 - Reference to 0x6000.89<br>
* SubIndex 90 - Reference to 0x6000.90<br>
* SubIndex 91 - Reference to 0x6000.91<br>
* SubIndex 92 - Reference to 0x6000.92<br>
* SubIndex 93 - Reference to 0x6000.93<br>
* SubIndex 94 - Reference to 0x6000.94<br>
* SubIndex 95 - Reference to 0x6000.95<br>
* SubIndex 96 - Reference to 0x6000.96<br>
* SubIndex 97 - Reference to 0x6000.97<br>
* SubIndex 98 - Reference to 0x6000.98<br>
* SubIndex 99 - Reference to 0x6000.99<br>
* SubIndex 100 - Reference to 0x6000.100<br>
* SubIndex 101 - Reference to 0x6000.101<br>
* SubIndex 102 - Reference to 0x6000.102<br>
* SubIndex 103 - Reference to 0x6000.103<br>
* SubIndex 104 - Reference to 0x6000.104<br>
* SubIndex 105 - Reference to 0x6000.105<br>
* SubIndex 106 - Reference to 0x6000.106<br>
* SubIndex 107 - Reference to 0x6000.107<br>
* SubIndex 108 - Reference to 0x6000.108<br>
* SubIndex 109 - Reference to 0x6000.109<br>
* SubIndex 110 - Reference to 0x6000.110<br>
* SubIndex 111 - Reference to 0x6000.111<br>
* SubIndex 112 - Reference to 0x6000.112<br>
* SubIndex 113 - Reference to 0x6000.113<br>
* SubIndex 114 - Reference to 0x6000.114<br>
* SubIndex 115 - Reference to 0x6000.115<br>
* SubIndex 116 - Reference to 0x6000.116<br>
* SubIndex 117 - Reference to 0x6000.117<br>
* SubIndex 118 - Reference to 0x6000.118<br>
* SubIndex 119 - Reference to 0x6000.119<br>
* SubIndex 120 - Reference to 0x6000.120<br>
* SubIndex 121 - Reference to 0x6000.121<br>
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
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex68 - Reference to 0x6000.68 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex69 - Reference to 0x6000.69 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex70 - Reference to 0x6000.70 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex71 - Reference to 0x6000.71 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex72 - Reference to 0x6000.72 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex73 - Reference to 0x6000.73 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex74 - Reference to 0x6000.74 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex75 - Reference to 0x6000.75 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex76 - Reference to 0x6000.76 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex77 - Reference to 0x6000.77 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex78 - Reference to 0x6000.78 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex79 - Reference to 0x6000.79 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex80 - Reference to 0x6000.80 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex81 - Reference to 0x6000.81 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex82 - Reference to 0x6000.82 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex83 - Reference to 0x6000.83 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex84 - Reference to 0x6000.84 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex85 - Reference to 0x6000.85 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex86 - Reference to 0x6000.86 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex87 - Reference to 0x6000.87 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex88 - Reference to 0x6000.88 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex89 - Reference to 0x6000.89 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex90 - Reference to 0x6000.90 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex91 - Reference to 0x6000.91 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex92 - Reference to 0x6000.92 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex93 - Reference to 0x6000.93 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex94 - Reference to 0x6000.94 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex95 - Reference to 0x6000.95 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex96 - Reference to 0x6000.96 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex97 - Reference to 0x6000.97 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex98 - Reference to 0x6000.98 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex99 - Reference to 0x6000.99 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex100 - Reference to 0x6000.100 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex101 - Reference to 0x6000.101 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex102 - Reference to 0x6000.102 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex103 - Reference to 0x6000.103 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex104 - Reference to 0x6000.104 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex105 - Reference to 0x6000.105 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex106 - Reference to 0x6000.106 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex107 - Reference to 0x6000.107 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex108 - Reference to 0x6000.108 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex109 - Reference to 0x6000.109 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex110 - Reference to 0x6000.110 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex111 - Reference to 0x6000.111 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex112 - Reference to 0x6000.112 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex113 - Reference to 0x6000.113 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex114 - Reference to 0x6000.114 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex115 - Reference to 0x6000.115 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex116 - Reference to 0x6000.116 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex117 - Reference to 0x6000.117 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex118 - Reference to 0x6000.118 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex119 - Reference to 0x6000.119 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex120 - Reference to 0x6000.120 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex121 - Reference to 0x6000.121 */

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
"SubIndex 068\000"
"SubIndex 069\000"
"SubIndex 070\000"
"SubIndex 071\000"
"SubIndex 072\000"
"SubIndex 073\000"
"SubIndex 074\000"
"SubIndex 075\000"
"SubIndex 076\000"
"SubIndex 077\000"
"SubIndex 078\000"
"SubIndex 079\000"
"SubIndex 080\000"
"SubIndex 081\000"
"SubIndex 082\000"
"SubIndex 083\000"
"SubIndex 084\000"
"SubIndex 085\000"
"SubIndex 086\000"
"SubIndex 087\000"
"SubIndex 088\000"
"SubIndex 089\000"
"SubIndex 090\000"
"SubIndex 091\000"
"SubIndex 092\000"
"SubIndex 093\000"
"SubIndex 094\000"
"SubIndex 095\000"
"SubIndex 096\000"
"SubIndex 097\000"
"SubIndex 098\000"
"SubIndex 099\000"
"SubIndex 100\000"
"SubIndex 101\000"
"SubIndex 102\000"
"SubIndex 103\000"
"SubIndex 104\000"
"SubIndex 105\000"
"SubIndex 106\000"
"SubIndex 107\000"
"SubIndex 108\000"
"SubIndex 109\000"
"SubIndex 110\000"
"SubIndex 111\000"
"SubIndex 112\000"
"SubIndex 113\000"
"SubIndex 114\000"
"SubIndex 115\000"
"SubIndex 116\000"
"SubIndex 117\000"
"SubIndex 118\000"
"SubIndex 119\000"
"SubIndex 120\000"
"SubIndex 121\000\377";
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
UINT32 SI69; /* Subindex69 - Reference to 0x6000.69 */
UINT32 SI70; /* Subindex70 - Reference to 0x6000.70 */
UINT32 SI71; /* Subindex71 - Reference to 0x6000.71 */
UINT32 SI72; /* Subindex72 - Reference to 0x6000.72 */
UINT32 SI73; /* Subindex73 - Reference to 0x6000.73 */
UINT32 SI74; /* Subindex74 - Reference to 0x6000.74 */
UINT32 SI75; /* Subindex75 - Reference to 0x6000.75 */
UINT32 SI76; /* Subindex76 - Reference to 0x6000.76 */
UINT32 SI77; /* Subindex77 - Reference to 0x6000.77 */
UINT32 SI78; /* Subindex78 - Reference to 0x6000.78 */
UINT32 SI79; /* Subindex79 - Reference to 0x6000.79 */
UINT32 SI80; /* Subindex80 - Reference to 0x6000.80 */
UINT32 SI81; /* Subindex81 - Reference to 0x6000.81 */
UINT32 SI82; /* Subindex82 - Reference to 0x6000.82 */
UINT32 SI83; /* Subindex83 - Reference to 0x6000.83 */
UINT32 SI84; /* Subindex84 - Reference to 0x6000.84 */
UINT32 SI85; /* Subindex85 - Reference to 0x6000.85 */
UINT32 SI86; /* Subindex86 - Reference to 0x6000.86 */
UINT32 SI87; /* Subindex87 - Reference to 0x6000.87 */
UINT32 SI88; /* Subindex88 - Reference to 0x6000.88 */
UINT32 SI89; /* Subindex89 - Reference to 0x6000.89 */
UINT32 SI90; /* Subindex90 - Reference to 0x6000.90 */
UINT32 SI91; /* Subindex91 - Reference to 0x6000.91 */
UINT32 SI92; /* Subindex92 - Reference to 0x6000.92 */
UINT32 SI93; /* Subindex93 - Reference to 0x6000.93 */
UINT32 SI94; /* Subindex94 - Reference to 0x6000.94 */
UINT32 SI95; /* Subindex95 - Reference to 0x6000.95 */
UINT32 SI96; /* Subindex96 - Reference to 0x6000.96 */
UINT32 SI97; /* Subindex97 - Reference to 0x6000.97 */
UINT32 SI98; /* Subindex98 - Reference to 0x6000.98 */
UINT32 SI99; /* Subindex99 - Reference to 0x6000.99 */
UINT32 SI100; /* Subindex100 - Reference to 0x6000.100 */
UINT32 SI101; /* Subindex101 - Reference to 0x6000.101 */
UINT32 SI102; /* Subindex102 - Reference to 0x6000.102 */
UINT32 SI103; /* Subindex103 - Reference to 0x6000.103 */
UINT32 SI104; /* Subindex104 - Reference to 0x6000.104 */
UINT32 SI105; /* Subindex105 - Reference to 0x6000.105 */
UINT32 SI106; /* Subindex106 - Reference to 0x6000.106 */
UINT32 SI107; /* Subindex107 - Reference to 0x6000.107 */
UINT32 SI108; /* Subindex108 - Reference to 0x6000.108 */
UINT32 SI109; /* Subindex109 - Reference to 0x6000.109 */
UINT32 SI110; /* Subindex110 - Reference to 0x6000.110 */
UINT32 SI111; /* Subindex111 - Reference to 0x6000.111 */
UINT32 SI112; /* Subindex112 - Reference to 0x6000.112 */
UINT32 SI113; /* Subindex113 - Reference to 0x6000.113 */
UINT32 SI114; /* Subindex114 - Reference to 0x6000.114 */
UINT32 SI115; /* Subindex115 - Reference to 0x6000.115 */
UINT32 SI116; /* Subindex116 - Reference to 0x6000.116 */
UINT32 SI117; /* Subindex117 - Reference to 0x6000.117 */
UINT32 SI118; /* Subindex118 - Reference to 0x6000.118 */
UINT32 SI119; /* Subindex119 - Reference to 0x6000.119 */
UINT32 SI120; /* Subindex120 - Reference to 0x6000.120 */
UINT32 SI121; /* Subindex121 - Reference to 0x6000.121 */
} OBJ_STRUCT_PACKED_END
TOBJ1A00;
#endif //#ifndef _ROBOT_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A00 IN_GENERICProcessDataMapping0x1A00
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
={121,0x60000101,0x60000201,0x60000301,0x60000401,0x60000501,0x60000601,0x60000701,0x60000801,0x60000901,0x60000A01,0x60000B01,0x60000C01,0x60000D01,0x60000E01,0x60000F01,0x60001001,0x60001110,0x60001210,0x60001310,0x60001410,0x60001510,0x60001610,0x60001710,0x60001810,0x60001910,0x60001A10,0x60001B08,0x60001C08,0x60001D08,0x60001E08,0x60001F08,0x60002008,0x60002108,0x60002208,0x60002308,0x60002408,0x60002508,0x60002608,0x60002708,0x60002808,0x60002908,0x60002A08,0x60002B08,0x60002C08,0x60002D08,0x60002E08,0x60002F08,0x60003008,0x60003108,0x60003208,0x60003308,0x60003408,0x60003508,0x60003608,0x60003708,0x60003808,0x60003908,0x60003A08,0x60003B10,0x60003C10,0x60003D10,0x60003E08,0x60003F08,0x60004008,0x60004108,0x60004208,0x60004308,0x60004408,0x60004508,0x60004601,0x60004701,0x60004801,0x60004901,0x60004A01,0x60004B01,0x60004C01,0x60004D01,0x60004E01,0x60004F01,0x60005001,0x60005101,0x60005201,0x60005301,0x60005401,0x60005501,0x60005610,0x60005710,0x60005808,0x60005908,0x60005A08,0x60005B08,0x60005C08,0x60005D08,0x60005E08,0x60005F08,0x60006008,0x60006108,0x60006208,0x60006308,0x60006408,0x60006508,0x60006608,0x60006708,0x60006808,0x60006908,0x60006A08,0x60006B08,0x60006C08,0x60006D08,0x60006E08,0x60006F08,0x60007008,0x60007108,0x60007208,0x60007308,0x60007408,0x60007508,0x60007608,0x60007708,0x60007820,0x60007910}
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
*                    Object 0x2000 : Software_Version
******************************************************************************/
/**
* \addtogroup 0x2000 0x2000 | Software_Version
* @{
* \brief Object 0x2000 (Software_Version) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x2000 = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x2000[] = "Software_Version\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Software_Version0x2000
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x0400
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x2001 : Hardware_type
******************************************************************************/
/**
* \addtogroup 0x2001 0x2001 | Hardware_type
* @{
* \brief Object 0x2001 (Hardware_type) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x2001 = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x2001[] = "Hardware_type\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Hardware_type0x2001
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
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
* SubIndex 19 - Analog_Voltage_Inputs_channel 3<br>
* SubIndex 20 - Analog_Voltage_Inputs_channel 4<br>
* SubIndex 21 - Analog_Current_Inputs_channel 1<br>
* SubIndex 22 - Analog_Current_Inputs_channel 2<br>
* SubIndex 23 - Analog_Current_Inputs_channel 3<br>
* SubIndex 24 - Analog_Current_Inputs_channel 4<br>
* SubIndex 25 - RS485_Inputs_Count<br>
* SubIndex 26 - RS485_Inputs_Len<br>
* SubIndex 27 - RS485_Inputs_Data_In_1<br>
* SubIndex 28 - RS485_Inputs_Data_In_2<br>
* SubIndex 29 - RS485_Inputs_Data_In_3<br>
* SubIndex 30 - RS485_Inputs_Data_In_4<br>
* SubIndex 31 - RS485_Inputs_Data_In_5<br>
* SubIndex 32 - RS485_Inputs_Data_In_6<br>
* SubIndex 33 - RS485_Inputs_Data_In_7<br>
* SubIndex 34 - RS485_Inputs_Data_In_8<br>
* SubIndex 35 - RS485_Inputs_Data_In_9<br>
* SubIndex 36 - RS485_Inputs_Data_In_10<br>
* SubIndex 37 - RS485_Inputs_Data_In_11<br>
* SubIndex 38 - RS485_Inputs_Data_In_12<br>
* SubIndex 39 - RS485_Inputs_Data_In_13<br>
* SubIndex 40 - RS485_Inputs_Data_In_14<br>
* SubIndex 41 - RS485_Inputs_Data_In_15<br>
* SubIndex 42 - RS485_Inputs_Data_In_16<br>
* SubIndex 43 - RS485_Inputs_Data_In_17<br>
* SubIndex 44 - RS485_Inputs_Data_In_18<br>
* SubIndex 45 - RS485_Inputs_Data_In_19<br>
* SubIndex 46 - RS485_Inputs_Data_In_20<br>
* SubIndex 47 - RS485_Inputs_Data_In_21<br>
* SubIndex 48 - RS485_Inputs_Data_In_22<br>
* SubIndex 49 - RS485_Inputs_Data_In_23<br>
* SubIndex 50 - RS485_Inputs_Data_In_24<br>
* SubIndex 51 - RS485_Inputs_Data_In_25<br>
* SubIndex 52 - RS485_Inputs_Data_In_26<br>
* SubIndex 53 - RS485_Inputs_Data_In_27<br>
* SubIndex 54 - RS485_Inputs_Data_In_28<br>
* SubIndex 55 - RS485_Inputs_Data_In_29<br>
* SubIndex 56 - RS485_Inputs_Data_In_30<br>
* SubIndex 57 - RS485_Inputs_Data_In_31<br>
* SubIndex 58 - RS485_Inputs_Data_In_32<br>
* SubIndex 59 - CAN_RX_Change_Count<br>
* SubIndex 60 - CAN_RX_ID<br>
* SubIndex 61 - CAN_RX_LEN<br>
* SubIndex 62 - CAN Inputs Data In 1<br>
* SubIndex 63 - CAN Inputs Data In 2<br>
* SubIndex 64 - CAN Inputs Data In 3<br>
* SubIndex 65 - CAN Inputs Data In 4<br>
* SubIndex 66 - CAN Inputs Data In 5<br>
* SubIndex 67 - CAN Inputs Data In 6<br>
* SubIndex 68 - CAN Inputs Data In 7<br>
* SubIndex 69 - CAN Inputs Data In 8<br>
* SubIndex 70 - Function_Digital_Inputs_Channel_1<br>
* SubIndex 71 - Function_Digital_Inputs_Channel_2<br>
* SubIndex 72 - Function_Digital_Inputs_Channel_3<br>
* SubIndex 73 - Function_Digital_Inputs_Channel_4<br>
* SubIndex 74 - Function_Digital_Inputs_Channel_5<br>
* SubIndex 75 - Function_Digital_Inputs_Channel_6<br>
* SubIndex 76 - Function_Digital_Inputs_Channel_7<br>
* SubIndex 77 - Function_Digital_Inputs_Channel_8<br>
* SubIndex 78 - Internal_Digital_Inputs_Channel_1<br>
* SubIndex 79 - Internal_Digital_Inputs_Channel_2<br>
* SubIndex 80 - Internal_Digital_Inputs_Channel_3<br>
* SubIndex 81 - Internal_Digital_Inputs_Channel_4<br>
* SubIndex 82 - Internal_Digital_Inputs_Channel_5<br>
* SubIndex 83 - Internal_Digital_Inputs_Channel_6<br>
* SubIndex 84 - Internal_Digital_Inputs_Channel_7<br>
* SubIndex 85 - Internal_Digital_Inputs_Channel_8<br>
* SubIndex 86 - RS232_Inputs_Count<br>
* SubIndex 87 - RS232_Inputs_Len<br>
* SubIndex 88 - RS232_Inputs_Data_In_1<br>
* SubIndex 89 - RS232_Inputs_Data_In_2<br>
* SubIndex 90 - RS232_Inputs_Data_In_3<br>
* SubIndex 91 - RS232_Inputs_Data_In_4<br>
* SubIndex 92 - RS232_Inputs_Data_In_5<br>
* SubIndex 93 - RS232_Inputs_Data_In_6<br>
* SubIndex 94 - RS232_Inputs_Data_In_7<br>
* SubIndex 95 - RS232_Inputs_Data_In_8<br>
* SubIndex 96 - RS232_Inputs_Data_In_9<br>
* SubIndex 97 - RS232_Inputs_Data_In_10<br>
* SubIndex 98 - RS232_Inputs_Data_In_11<br>
* SubIndex 99 - RS232_Inputs_Data_In_12<br>
* SubIndex 100 - RS232_Inputs_Data_In_13<br>
* SubIndex 101 - RS232_Inputs_Data_In_14<br>
* SubIndex 102 - RS232_Inputs_Data_In_15<br>
* SubIndex 103 - RS232_Inputs_Data_In_16<br>
* SubIndex 104 - RS232_Inputs_Data_In_17<br>
* SubIndex 105 - RS232_Inputs_Data_In_18<br>
* SubIndex 106 - RS232_Inputs_Data_In_19<br>
* SubIndex 107 - RS232_Inputs_Data_In_20<br>
* SubIndex 108 - RS232_Inputs_Data_In_21<br>
* SubIndex 109 - RS232_Inputs_Data_In_22<br>
* SubIndex 110 - RS232_Inputs_Data_In_23<br>
* SubIndex 111 - RS232_Inputs_Data_In_24<br>
* SubIndex 112 - RS232_Inputs_Data_In_25<br>
* SubIndex 113 - RS232_Inputs_Data_In_26<br>
* SubIndex 114 - RS232_Inputs_Data_In_27<br>
* SubIndex 115 - RS232_Inputs_Data_In_28<br>
* SubIndex 116 - RS232_Inputs_Data_In_29<br>
* SubIndex 117 - RS232_Inputs_Data_In_30<br>
* SubIndex 118 - RS232_Inputs_Data_In_31<br>
* SubIndex 119 - RS232_Inputs_Data_In_32<br>
* SubIndex 120 - INC_AB_CNT<br>
* SubIndex 121 - ErrorCode<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex1 - Digital_Inputs_channel 1 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex2 - Digital_Inputs_channel 2 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex3 - Digital_Inputs_channel 3 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex4 - Digital_Inputs_channel 4 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex5 - Digital_Inputs_channel 5 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex6 - Digital_Inputs_channel 6 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex7 - Digital_Inputs_channel 7 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex8 - Digital_Inputs_channel 8 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex9 - Digital_Inputs_channel 9 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex10 - Digital_Inputs_channel 10 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex11 - Digital_Inputs_channel 11 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex12 - Digital_Inputs_channel 12 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex13 - Digital_Inputs_channel 13 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex14 - Digital_Inputs_channel 14 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex15 - Digital_Inputs_channel 15 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex16 - Digital_Inputs_channel 16 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex17 - Analog_Voltage_Inputs_channel 1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex18 - Analog_Voltage_Inputs_channel 2 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex19 - Analog_Voltage_Inputs_channel 3 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex20 - Analog_Voltage_Inputs_channel 4 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex21 - Analog_Current_Inputs_channel 1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex22 - Analog_Current_Inputs_channel 2 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex23 - Analog_Current_Inputs_channel 3 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex24 - Analog_Current_Inputs_channel 4 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex25 - RS485_Inputs_Count */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex26 - RS485_Inputs_Len */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex27 - RS485_Inputs_Data_In_1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex28 - RS485_Inputs_Data_In_2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex29 - RS485_Inputs_Data_In_3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex30 - RS485_Inputs_Data_In_4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex31 - RS485_Inputs_Data_In_5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex32 - RS485_Inputs_Data_In_6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex33 - RS485_Inputs_Data_In_7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex34 - RS485_Inputs_Data_In_8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex35 - RS485_Inputs_Data_In_9 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex36 - RS485_Inputs_Data_In_10 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex37 - RS485_Inputs_Data_In_11 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex38 - RS485_Inputs_Data_In_12 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex39 - RS485_Inputs_Data_In_13 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex40 - RS485_Inputs_Data_In_14 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex41 - RS485_Inputs_Data_In_15 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex42 - RS485_Inputs_Data_In_16 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex43 - RS485_Inputs_Data_In_17 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex44 - RS485_Inputs_Data_In_18 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex45 - RS485_Inputs_Data_In_19 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex46 - RS485_Inputs_Data_In_20 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex47 - RS485_Inputs_Data_In_21 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex48 - RS485_Inputs_Data_In_22 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex49 - RS485_Inputs_Data_In_23 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex50 - RS485_Inputs_Data_In_24 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex51 - RS485_Inputs_Data_In_25 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex52 - RS485_Inputs_Data_In_26 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex53 - RS485_Inputs_Data_In_27 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex54 - RS485_Inputs_Data_In_28 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex55 - RS485_Inputs_Data_In_29 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex56 - RS485_Inputs_Data_In_30 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex57 - RS485_Inputs_Data_In_31 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex58 - RS485_Inputs_Data_In_32 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex59 - CAN_RX_Change_Count */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex60 - CAN_RX_ID */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex61 - CAN_RX_LEN */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex62 - CAN Inputs Data In 1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex63 - CAN Inputs Data In 2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex64 - CAN Inputs Data In 3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex65 - CAN Inputs Data In 4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex66 - CAN Inputs Data In 5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex67 - CAN Inputs Data In 6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex68 - CAN Inputs Data In 7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex69 - CAN Inputs Data In 8 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex70 - Function_Digital_Inputs_Channel_1 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex71 - Function_Digital_Inputs_Channel_2 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex72 - Function_Digital_Inputs_Channel_3 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex73 - Function_Digital_Inputs_Channel_4 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex74 - Function_Digital_Inputs_Channel_5 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex75 - Function_Digital_Inputs_Channel_6 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex76 - Function_Digital_Inputs_Channel_7 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex77 - Function_Digital_Inputs_Channel_8 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex78 - Internal_Digital_Inputs_Channel_1 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex79 - Internal_Digital_Inputs_Channel_2 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex80 - Internal_Digital_Inputs_Channel_3 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex81 - Internal_Digital_Inputs_Channel_4 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex82 - Internal_Digital_Inputs_Channel_5 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex83 - Internal_Digital_Inputs_Channel_6 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex84 - Internal_Digital_Inputs_Channel_7 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READ }, /* Subindex85 - Internal_Digital_Inputs_Channel_8 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex86 - RS232_Inputs_Count */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex87 - RS232_Inputs_Len */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex88 - RS232_Inputs_Data_In_1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex89 - RS232_Inputs_Data_In_2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex90 - RS232_Inputs_Data_In_3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex91 - RS232_Inputs_Data_In_4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex92 - RS232_Inputs_Data_In_5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex93 - RS232_Inputs_Data_In_6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex94 - RS232_Inputs_Data_In_7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex95 - RS232_Inputs_Data_In_8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex96 - RS232_Inputs_Data_In_9 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex97 - RS232_Inputs_Data_In_10 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex98 - RS232_Inputs_Data_In_11 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex99 - RS232_Inputs_Data_In_12 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex100 - RS232_Inputs_Data_In_13 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex101 - RS232_Inputs_Data_In_14 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex102 - RS232_Inputs_Data_In_15 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex103 - RS232_Inputs_Data_In_16 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex104 - RS232_Inputs_Data_In_17 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex105 - RS232_Inputs_Data_In_18 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex106 - RS232_Inputs_Data_In_19 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex107 - RS232_Inputs_Data_In_20 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex108 - RS232_Inputs_Data_In_21 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex109 - RS232_Inputs_Data_In_22 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex110 - RS232_Inputs_Data_In_23 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex111 - RS232_Inputs_Data_In_24 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex112 - RS232_Inputs_Data_In_25 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex113 - RS232_Inputs_Data_In_26 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex114 - RS232_Inputs_Data_In_27 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex115 - RS232_Inputs_Data_In_28 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex116 - RS232_Inputs_Data_In_29 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex117 - RS232_Inputs_Data_In_30 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex118 - RS232_Inputs_Data_In_31 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }, /* Subindex119 - RS232_Inputs_Data_In_32 */
{ DEFTYPE_INTEGER32 , 0x20 , ACCESS_READ }, /* Subindex120 - INC_AB_CNT */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }}; /* Subindex121 - ErrorCode */

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
"Analog_Voltage_Inputs_channel 3\000"
"Analog_Voltage_Inputs_channel 4\000"
"Analog_Current_Inputs_channel 1\000"
"Analog_Current_Inputs_channel 2\000"
"Analog_Current_Inputs_channel 3\000"
"Analog_Current_Inputs_channel 4\000"
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
"Function_Digital_Inputs_Channel_1\000"
"Function_Digital_Inputs_Channel_2\000"
"Function_Digital_Inputs_Channel_3\000"
"Function_Digital_Inputs_Channel_4\000"
"Function_Digital_Inputs_Channel_5\000"
"Function_Digital_Inputs_Channel_6\000"
"Function_Digital_Inputs_Channel_7\000"
"Function_Digital_Inputs_Channel_8\000"
"Internal_Digital_Inputs_Channel_1\000"
"Internal_Digital_Inputs_Channel_2\000"
"Internal_Digital_Inputs_Channel_3\000"
"Internal_Digital_Inputs_Channel_4\000"
"Internal_Digital_Inputs_Channel_5\000"
"Internal_Digital_Inputs_Channel_6\000"
"Internal_Digital_Inputs_Channel_7\000"
"Internal_Digital_Inputs_Channel_8\000"
"RS232_Inputs_Count\000"
"RS232_Inputs_Len\000"
"RS232_Inputs_Data_In_1\000"
"RS232_Inputs_Data_In_2\000"
"RS232_Inputs_Data_In_3\000"
"RS232_Inputs_Data_In_4\000"
"RS232_Inputs_Data_In_5\000"
"RS232_Inputs_Data_In_6\000"
"RS232_Inputs_Data_In_7\000"
"RS232_Inputs_Data_In_8\000"
"RS232_Inputs_Data_In_9\000"
"RS232_Inputs_Data_In_10\000"
"RS232_Inputs_Data_In_11\000"
"RS232_Inputs_Data_In_12\000"
"RS232_Inputs_Data_In_13\000"
"RS232_Inputs_Data_In_14\000"
"RS232_Inputs_Data_In_15\000"
"RS232_Inputs_Data_In_16\000"
"RS232_Inputs_Data_In_17\000"
"RS232_Inputs_Data_In_18\000"
"RS232_Inputs_Data_In_19\000"
"RS232_Inputs_Data_In_20\000"
"RS232_Inputs_Data_In_21\000"
"RS232_Inputs_Data_In_22\000"
"RS232_Inputs_Data_In_23\000"
"RS232_Inputs_Data_In_24\000"
"RS232_Inputs_Data_In_25\000"
"RS232_Inputs_Data_In_26\000"
"RS232_Inputs_Data_In_27\000"
"RS232_Inputs_Data_In_28\000"
"RS232_Inputs_Data_In_29\000"
"RS232_Inputs_Data_In_30\000"
"RS232_Inputs_Data_In_31\000"
"RS232_Inputs_Data_In_32\000"
"INC_AB_CNT\000"
"ErrorCode\000\377";
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
UINT16 Analog_Voltage_Inputs_channel3; /* Subindex19 - Analog_Voltage_Inputs_channel 3 */
UINT16 Analog_Voltage_Inputs_channel4; /* Subindex20 - Analog_Voltage_Inputs_channel 4 */
UINT16 Analog_Current_Inputs_channel1; /* Subindex21 - Analog_Current_Inputs_channel 1 */
UINT16 Analog_Current_Inputs_channel2; /* Subindex22 - Analog_Current_Inputs_channel 2 */
UINT16 Analog_Current_Inputs_channel3; /* Subindex23 - Analog_Current_Inputs_channel 3 */
UINT16 Analog_Current_Inputs_channel4; /* Subindex24 - Analog_Current_Inputs_channel 4 */
UINT16 RS485_Inputs_Count; /* Subindex25 - RS485_Inputs_Count */
UINT16 RS485_Inputs_Len; /* Subindex26 - RS485_Inputs_Len */
UINT8 RS485_Inputs_Data_In_1; /* Subindex27 - RS485_Inputs_Data_In_1 */
UINT8 RS485_Inputs_Data_In_2; /* Subindex28 - RS485_Inputs_Data_In_2 */
UINT8 RS485_Inputs_Data_In_3; /* Subindex29 - RS485_Inputs_Data_In_3 */
UINT8 RS485_Inputs_Data_In_4; /* Subindex30 - RS485_Inputs_Data_In_4 */
UINT8 RS485_Inputs_Data_In_5; /* Subindex31 - RS485_Inputs_Data_In_5 */
UINT8 RS485_Inputs_Data_In_6; /* Subindex32 - RS485_Inputs_Data_In_6 */
UINT8 RS485_Inputs_Data_In_7; /* Subindex33 - RS485_Inputs_Data_In_7 */
UINT8 RS485_Inputs_Data_In_8; /* Subindex34 - RS485_Inputs_Data_In_8 */
UINT8 RS485_Inputs_Data_In_9; /* Subindex35 - RS485_Inputs_Data_In_9 */
UINT8 RS485_Inputs_Data_In_10; /* Subindex36 - RS485_Inputs_Data_In_10 */
UINT8 RS485_Inputs_Data_In_11; /* Subindex37 - RS485_Inputs_Data_In_11 */
UINT8 RS485_Inputs_Data_In_12; /* Subindex38 - RS485_Inputs_Data_In_12 */
UINT8 RS485_Inputs_Data_In_13; /* Subindex39 - RS485_Inputs_Data_In_13 */
UINT8 RS485_Inputs_Data_In_14; /* Subindex40 - RS485_Inputs_Data_In_14 */
UINT8 RS485_Inputs_Data_In_15; /* Subindex41 - RS485_Inputs_Data_In_15 */
UINT8 RS485_Inputs_Data_In_16; /* Subindex42 - RS485_Inputs_Data_In_16 */
UINT8 RS485_Inputs_Data_In_17; /* Subindex43 - RS485_Inputs_Data_In_17 */
UINT8 RS485_Inputs_Data_In_18; /* Subindex44 - RS485_Inputs_Data_In_18 */
UINT8 RS485_Inputs_Data_In_19; /* Subindex45 - RS485_Inputs_Data_In_19 */
UINT8 RS485_Inputs_Data_In_20; /* Subindex46 - RS485_Inputs_Data_In_20 */
UINT8 RS485_Inputs_Data_In_21; /* Subindex47 - RS485_Inputs_Data_In_21 */
UINT8 RS485_Inputs_Data_In_22; /* Subindex48 - RS485_Inputs_Data_In_22 */
UINT8 RS485_Inputs_Data_In_23; /* Subindex49 - RS485_Inputs_Data_In_23 */
UINT8 RS485_Inputs_Data_In_24; /* Subindex50 - RS485_Inputs_Data_In_24 */
UINT8 RS485_Inputs_Data_In_25; /* Subindex51 - RS485_Inputs_Data_In_25 */
UINT8 RS485_Inputs_Data_In_26; /* Subindex52 - RS485_Inputs_Data_In_26 */
UINT8 RS485_Inputs_Data_In_27; /* Subindex53 - RS485_Inputs_Data_In_27 */
UINT8 RS485_Inputs_Data_In_28; /* Subindex54 - RS485_Inputs_Data_In_28 */
UINT8 RS485_Inputs_Data_In_29; /* Subindex55 - RS485_Inputs_Data_In_29 */
UINT8 RS485_Inputs_Data_In_30; /* Subindex56 - RS485_Inputs_Data_In_30 */
UINT8 RS485_Inputs_Data_In_31; /* Subindex57 - RS485_Inputs_Data_In_31 */
UINT8 RS485_Inputs_Data_In_32; /* Subindex58 - RS485_Inputs_Data_In_32 */
UINT16 CAN_RX_Change_Count; /* Subindex59 - CAN_RX_Change_Count */
UINT16 CAN_RX_ID; /* Subindex60 - CAN_RX_ID */
UINT16 CAN_RX_LEN; /* Subindex61 - CAN_RX_LEN */
UINT8 CANInputsDataIn1; /* Subindex62 - CAN Inputs Data In 1 */
UINT8 CANInputsDataIn2; /* Subindex63 - CAN Inputs Data In 2 */
UINT8 CANInputsDataIn3; /* Subindex64 - CAN Inputs Data In 3 */
UINT8 CANInputsDataIn4; /* Subindex65 - CAN Inputs Data In 4 */
UINT8 CANInputsDataIn5; /* Subindex66 - CAN Inputs Data In 5 */
UINT8 CANInputsDataIn6; /* Subindex67 - CAN Inputs Data In 6 */
UINT8 CANInputsDataIn7; /* Subindex68 - CAN Inputs Data In 7 */
UINT8 CANInputsDataIn8; /* Subindex69 - CAN Inputs Data In 8 */
BOOLEAN(Function_Digital_Inputs_Channel_1); /* Subindex70 - Function_Digital_Inputs_Channel_1 */
BOOLEAN(Function_Digital_Inputs_Channel_2); /* Subindex71 - Function_Digital_Inputs_Channel_2 */
BOOLEAN(Function_Digital_Inputs_Channel_3); /* Subindex72 - Function_Digital_Inputs_Channel_3 */
BOOLEAN(Function_Digital_Inputs_Channel_4); /* Subindex73 - Function_Digital_Inputs_Channel_4 */
BOOLEAN(Function_Digital_Inputs_Channel_5); /* Subindex74 - Function_Digital_Inputs_Channel_5 */
BOOLEAN(Function_Digital_Inputs_Channel_6); /* Subindex75 - Function_Digital_Inputs_Channel_6 */
BOOLEAN(Function_Digital_Inputs_Channel_7); /* Subindex76 - Function_Digital_Inputs_Channel_7 */
BOOLEAN(Function_Digital_Inputs_Channel_8); /* Subindex77 - Function_Digital_Inputs_Channel_8 */
BOOLEAN(Internal_Digital_Inputs_Channel_1); /* Subindex78 - Internal_Digital_Inputs_Channel_1 */
BOOLEAN(Internal_Digital_Inputs_Channel_2); /* Subindex79 - Internal_Digital_Inputs_Channel_2 */
BOOLEAN(Internal_Digital_Inputs_Channel_3); /* Subindex80 - Internal_Digital_Inputs_Channel_3 */
BOOLEAN(Internal_Digital_Inputs_Channel_4); /* Subindex81 - Internal_Digital_Inputs_Channel_4 */
BOOLEAN(Internal_Digital_Inputs_Channel_5); /* Subindex82 - Internal_Digital_Inputs_Channel_5 */
BOOLEAN(Internal_Digital_Inputs_Channel_6); /* Subindex83 - Internal_Digital_Inputs_Channel_6 */
BOOLEAN(Internal_Digital_Inputs_Channel_7); /* Subindex84 - Internal_Digital_Inputs_Channel_7 */
BOOLEAN(Internal_Digital_Inputs_Channel_8); /* Subindex85 - Internal_Digital_Inputs_Channel_8 */
UINT16 RS232_Inputs_Count; /* Subindex86 - RS232_Inputs_Count */
UINT16 RS232_Inputs_Len; /* Subindex87 - RS232_Inputs_Len */
UINT8 RS232_Inputs_Data_In_1; /* Subindex88 - RS232_Inputs_Data_In_1 */
UINT8 RS232_Inputs_Data_In_2; /* Subindex89 - RS232_Inputs_Data_In_2 */
UINT8 RS232_Inputs_Data_In_3; /* Subindex90 - RS232_Inputs_Data_In_3 */
UINT8 RS232_Inputs_Data_In_4; /* Subindex91 - RS232_Inputs_Data_In_4 */
UINT8 RS232_Inputs_Data_In_5; /* Subindex92 - RS232_Inputs_Data_In_5 */
UINT8 RS232_Inputs_Data_In_6; /* Subindex93 - RS232_Inputs_Data_In_6 */
UINT8 RS232_Inputs_Data_In_7; /* Subindex94 - RS232_Inputs_Data_In_7 */
UINT8 RS232_Inputs_Data_In_8; /* Subindex95 - RS232_Inputs_Data_In_8 */
UINT8 RS232_Inputs_Data_In_9; /* Subindex96 - RS232_Inputs_Data_In_9 */
UINT8 RS232_Inputs_Data_In_10; /* Subindex97 - RS232_Inputs_Data_In_10 */
UINT8 RS232_Inputs_Data_In_11; /* Subindex98 - RS232_Inputs_Data_In_11 */
UINT8 RS232_Inputs_Data_In_12; /* Subindex99 - RS232_Inputs_Data_In_12 */
UINT8 RS232_Inputs_Data_In_13; /* Subindex100 - RS232_Inputs_Data_In_13 */
UINT8 RS232_Inputs_Data_In_14; /* Subindex101 - RS232_Inputs_Data_In_14 */
UINT8 RS232_Inputs_Data_In_15; /* Subindex102 - RS232_Inputs_Data_In_15 */
UINT8 RS232_Inputs_Data_In_16; /* Subindex103 - RS232_Inputs_Data_In_16 */
UINT8 RS232_Inputs_Data_In_17; /* Subindex104 - RS232_Inputs_Data_In_17 */
UINT8 RS232_Inputs_Data_In_18; /* Subindex105 - RS232_Inputs_Data_In_18 */
UINT8 RS232_Inputs_Data_In_19; /* Subindex106 - RS232_Inputs_Data_In_19 */
UINT8 RS232_Inputs_Data_In_20; /* Subindex107 - RS232_Inputs_Data_In_20 */
UINT8 RS232_Inputs_Data_In_21; /* Subindex108 - RS232_Inputs_Data_In_21 */
UINT8 RS232_Inputs_Data_In_22; /* Subindex109 - RS232_Inputs_Data_In_22 */
UINT8 RS232_Inputs_Data_In_23; /* Subindex110 - RS232_Inputs_Data_In_23 */
UINT8 RS232_Inputs_Data_In_24; /* Subindex111 - RS232_Inputs_Data_In_24 */
UINT8 RS232_Inputs_Data_In_25; /* Subindex112 - RS232_Inputs_Data_In_25 */
UINT8 RS232_Inputs_Data_In_26; /* Subindex113 - RS232_Inputs_Data_In_26 */
UINT8 RS232_Inputs_Data_In_27; /* Subindex114 - RS232_Inputs_Data_In_27 */
UINT8 RS232_Inputs_Data_In_28; /* Subindex115 - RS232_Inputs_Data_In_28 */
UINT8 RS232_Inputs_Data_In_29; /* Subindex116 - RS232_Inputs_Data_In_29 */
UINT8 RS232_Inputs_Data_In_30; /* Subindex117 - RS232_Inputs_Data_In_30 */
UINT8 RS232_Inputs_Data_In_31; /* Subindex118 - RS232_Inputs_Data_In_31 */
UINT8 RS232_Inputs_Data_In_32; /* Subindex119 - RS232_Inputs_Data_In_32 */
INT32 INC_AB_CNT; /* Subindex120 - INC_AB_CNT */
UINT16 ErrorCode; /* Subindex121 - ErrorCode */
} OBJ_STRUCT_PACKED_END
TOBJ6000;
#endif //#ifndef _ROBOT_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6000 IN_GENERIC0x6000
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
={121,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
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
* SubIndex 62 - Function_Digital_Outputs_Channel_1<br>
* SubIndex 63 - Function_Digital_Outputs_Channel_2<br>
* SubIndex 64 - Function_Digital_Outputs_Channel_3<br>
* SubIndex 65 - Function_Digital_Outputs_Channel_4<br>
* SubIndex 66 - Function_Digital_Outputs_Channel_5<br>
* SubIndex 67 - Function_Digital_Outputs_Channel_6<br>
* SubIndex 68 - Function_Digital_Outputs_Channel_7<br>
* SubIndex 69 - Function_Digital_Outputs_Channel_8<br>
* SubIndex 70 - Internal_Digital_Outputs_Channel_1<br>
* SubIndex 71 - Internal_Digital_Outputs_Channel_2<br>
* SubIndex 72 - Internal_Digital_Outputs_Channel_3<br>
* SubIndex 73 - Internal_Digital_Outputs_Channel_4<br>
* SubIndex 74 - Internal_Digital_Outputs_Channel_5<br>
* SubIndex 75 - Internal_Digital_Outputs_Channel_6<br>
* SubIndex 76 - Internal_Digital_Outputs_Channel_7<br>
* SubIndex 77 - Internal_Digital_Outputs_Channel_8<br>
* SubIndex 78 - RS232_Outputs_Count<br>
* SubIndex 79 - RS232_Outputs_Len<br>
* SubIndex 80 - RS232_Outputs_Data_Out_1<br>
* SubIndex 81 - RS232_Outputs_Data_Out_2<br>
* SubIndex 82 - RS232_Outputs_Data_Out_3<br>
* SubIndex 83 - RS232_Outputs_Data_Out_4<br>
* SubIndex 84 - RS232_Outputs_Data_Out_5<br>
* SubIndex 85 - RS232_Outputs_Data_Out_6<br>
* SubIndex 86 - RS232_Outputs_Data_Out_7<br>
* SubIndex 87 - RS232_Outputs_Data_Out_8<br>
* SubIndex 88 - RS232_Outputs_Data_Out_9<br>
* SubIndex 89 - RS232_Outputs_Data_Out_10<br>
* SubIndex 90 - RS232_Outputs_Data_Out_11<br>
* SubIndex 91 - RS232_Outputs_Data_Out_12<br>
* SubIndex 92 - RS232_Outputs_Data_Out_13<br>
* SubIndex 93 - RS232_Outputs_Data_Out_14<br>
* SubIndex 94 - RS232_Outputs_Data_Out_15<br>
* SubIndex 95 - RS232_Outputs_Data_Out_16<br>
* SubIndex 96 - RS232_Outputs_Data_Out_17<br>
* SubIndex 97 - RS232_Outputs_Data_Out_18<br>
* SubIndex 98 - RS232_Outputs_Data_Out_19<br>
* SubIndex 99 - RS232_Outputs_Data_Out_20<br>
* SubIndex 100 - RS232_Outputs_Data_Out_21<br>
* SubIndex 101 - RS232_Outputs_Data_Out_22<br>
* SubIndex 102 - RS232_Outputs_Data_Out_23<br>
* SubIndex 103 - RS232_Outputs_Data_Out_24<br>
* SubIndex 104 - RS232_Outputs_Data_Out_25<br>
* SubIndex 105 - RS232_Outputs_Data_Out_26<br>
* SubIndex 106 - RS232_Outputs_Data_Out_27<br>
* SubIndex 107 - RS232_Outputs_Data_Out_28<br>
* SubIndex 108 - RS232_Outputs_Data_Out_29<br>
* SubIndex 109 - RS232_Outputs_Data_Out_30<br>
* SubIndex 110 - RS232_Outputs_Data_Out_31<br>
* SubIndex 111 - RS232_Outputs_Data_Out_32<br>
* SubIndex 112 - Analog_Voltage_Outputs_channel 1<br>
* SubIndex 113 - Analog_Voltage_Outputs_channel 2<br>
* SubIndex 114 - Analog_Current_Outputs_channel 1<br>
* SubIndex 115 - Analog_Current_Outputs_channel 2<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex1 - Digital_Outputs_channel_1 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex2 - Digital_Outputs_channel_2 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex3 - Digital_Outputs_channel_3 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex4 - Digital_Outputs_channel_4 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex5 - Digital_Outputs_channel_5 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex6 - Digital_Outputs_channel_6 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex7 - Digital_Outputs_channel_7 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex8 - Digital_Outputs_channel_8 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex9 - Digital_Outputs_channel_9 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex10 - Digital_Outputs_channel_10 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex11 - Digital_Outputs_channel_11 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex12 - Digital_Outputs_channel_12 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex13 - Digital_Outputs_channel_13 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex14 - Digital_Outputs_channel_14 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex15 - Digital_Outputs_channel_15 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex16 - Digital_Outputs_channel_16 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex17 - RS485_Outputs_Count */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex18 - RS485_Outputs_Len */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex19 - RS485_Outputs_Data_Out_1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex20 - RS485_Outputs_Data_Out_2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex21 - RS485_Outputs_Data_Out_3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex22 - RS485_Outputs_Data_Out_4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex23 - RS485_Outputs_Data_Out_5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex24 - RS485_Outputs_Data_Out_6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex25 - RS485_Outputs_Data_Out_7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex26 - RS485_Outputs_Data_Out_8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex27 - RS485_Outputs_Data_Out_9 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex28 - RS485_Outputs_Data_Out_10 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex29 - RS485_Outputs_Data_Out_11 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex30 - RS485_Outputs_Data_Out_12 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex31 - RS485_Outputs_Data_Out_13 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex32 - RS485_Outputs_Data_Out_14 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex33 - RS485_Outputs_Data_Out_15 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex34 - RS485_Outputs_Data_Out_16 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex35 - RS485_Outputs_Data_Out_17 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex36 - RS485_Outputs_Data_Out_18 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex37 - RS485_Outputs_Data_Out_19 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex38 - RS485_Outputs_Data_Out_20 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex39 - RS485_Outputs_Data_Out_21 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex40 - RS485_Outputs_Data_Out_22 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex41 - RS485_Outputs_Data_Out_23 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex42 - RS485_Outputs_Data_Out_24 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex43 - RS485_Outputs_Data_Out_25 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex44 - RS485_Outputs_Data_Out_26 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex45 - RS485_Outputs_Data_Out_27 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex46 - RS485_Outputs_Data_Out_28 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex47 - RS485_Outputs_Data_Out_29 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex48 - RS485_Outputs_Data_Out_30 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex49 - RS485_Outputs_Data_Out_31 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex50 - RS485_Outputs_Data_Out_32 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex51 - CAN_TX_Change_Count */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex52 - CAN_TX_ID */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex53 - CAN_TX_LEN */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex54 - CAN Outputs Data Out 1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex55 - CAN Outputs Data Out 2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex56 - CAN Outputs Data Out 3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex57 - CAN Outputs Data Out 4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex58 - CAN Outputs Data Out 5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex59 - CAN Outputs Data Out 6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex60 - CAN Outputs Data Out 7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex61 - CAN Outputs Data Out 8 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex62 - Function_Digital_Outputs_Channel_1 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex63 - Function_Digital_Outputs_Channel_2 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex64 - Function_Digital_Outputs_Channel_3 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex65 - Function_Digital_Outputs_Channel_4 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex66 - Function_Digital_Outputs_Channel_5 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex67 - Function_Digital_Outputs_Channel_6 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex68 - Function_Digital_Outputs_Channel_7 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex69 - Function_Digital_Outputs_Channel_8 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex70 - Internal_Digital_Outputs_Channel_1 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex71 - Internal_Digital_Outputs_Channel_2 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex72 - Internal_Digital_Outputs_Channel_3 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex73 - Internal_Digital_Outputs_Channel_4 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex74 - Internal_Digital_Outputs_Channel_5 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex75 - Internal_Digital_Outputs_Channel_6 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex76 - Internal_Digital_Outputs_Channel_7 */
{ DEFTYPE_BOOLEAN , 0x1 , ACCESS_READWRITE }, /* Subindex77 - Internal_Digital_Outputs_Channel_8 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex78 - RS232_Outputs_Count */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex79 - RS232_Outputs_Len */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex80 - RS232_Outputs_Data_Out_1 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex81 - RS232_Outputs_Data_Out_2 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex82 - RS232_Outputs_Data_Out_3 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex83 - RS232_Outputs_Data_Out_4 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex84 - RS232_Outputs_Data_Out_5 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex85 - RS232_Outputs_Data_Out_6 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex86 - RS232_Outputs_Data_Out_7 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex87 - RS232_Outputs_Data_Out_8 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex88 - RS232_Outputs_Data_Out_9 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex89 - RS232_Outputs_Data_Out_10 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex90 - RS232_Outputs_Data_Out_11 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex91 - RS232_Outputs_Data_Out_12 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex92 - RS232_Outputs_Data_Out_13 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex93 - RS232_Outputs_Data_Out_14 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex94 - RS232_Outputs_Data_Out_15 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex95 - RS232_Outputs_Data_Out_16 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex96 - RS232_Outputs_Data_Out_17 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex97 - RS232_Outputs_Data_Out_18 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex98 - RS232_Outputs_Data_Out_19 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex99 - RS232_Outputs_Data_Out_20 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex100 - RS232_Outputs_Data_Out_21 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex101 - RS232_Outputs_Data_Out_22 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex102 - RS232_Outputs_Data_Out_23 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex103 - RS232_Outputs_Data_Out_24 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex104 - RS232_Outputs_Data_Out_25 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex105 - RS232_Outputs_Data_Out_26 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex106 - RS232_Outputs_Data_Out_27 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex107 - RS232_Outputs_Data_Out_28 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex108 - RS232_Outputs_Data_Out_29 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex109 - RS232_Outputs_Data_Out_30 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex110 - RS232_Outputs_Data_Out_31 */
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READWRITE }, /* Subindex111 - RS232_Outputs_Data_Out_32 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex112 - Analog_Voltage_Outputs_channel 1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex113 - Analog_Voltage_Outputs_channel 2 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex114 - Analog_Current_Outputs_channel 1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }}; /* Subindex115 - Analog_Current_Outputs_channel 2 */

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
"Function_Digital_Outputs_Channel_1\000"
"Function_Digital_Outputs_Channel_2\000"
"Function_Digital_Outputs_Channel_3\000"
"Function_Digital_Outputs_Channel_4\000"
"Function_Digital_Outputs_Channel_5\000"
"Function_Digital_Outputs_Channel_6\000"
"Function_Digital_Outputs_Channel_7\000"
"Function_Digital_Outputs_Channel_8\000"
"Internal_Digital_Outputs_Channel_1\000"
"Internal_Digital_Outputs_Channel_2\000"
"Internal_Digital_Outputs_Channel_3\000"
"Internal_Digital_Outputs_Channel_4\000"
"Internal_Digital_Outputs_Channel_5\000"
"Internal_Digital_Outputs_Channel_6\000"
"Internal_Digital_Outputs_Channel_7\000"
"Internal_Digital_Outputs_Channel_8\000"
"RS232_Outputs_Count\000"
"RS232_Outputs_Len\000"
"RS232_Outputs_Data_Out_1\000"
"RS232_Outputs_Data_Out_2\000"
"RS232_Outputs_Data_Out_3\000"
"RS232_Outputs_Data_Out_4\000"
"RS232_Outputs_Data_Out_5\000"
"RS232_Outputs_Data_Out_6\000"
"RS232_Outputs_Data_Out_7\000"
"RS232_Outputs_Data_Out_8\000"
"RS232_Outputs_Data_Out_9\000"
"RS232_Outputs_Data_Out_10\000"
"RS232_Outputs_Data_Out_11\000"
"RS232_Outputs_Data_Out_12\000"
"RS232_Outputs_Data_Out_13\000"
"RS232_Outputs_Data_Out_14\000"
"RS232_Outputs_Data_Out_15\000"
"RS232_Outputs_Data_Out_16\000"
"RS232_Outputs_Data_Out_17\000"
"RS232_Outputs_Data_Out_18\000"
"RS232_Outputs_Data_Out_19\000"
"RS232_Outputs_Data_Out_20\000"
"RS232_Outputs_Data_Out_21\000"
"RS232_Outputs_Data_Out_22\000"
"RS232_Outputs_Data_Out_23\000"
"RS232_Outputs_Data_Out_24\000"
"RS232_Outputs_Data_Out_25\000"
"RS232_Outputs_Data_Out_26\000"
"RS232_Outputs_Data_Out_27\000"
"RS232_Outputs_Data_Out_28\000"
"RS232_Outputs_Data_Out_29\000"
"RS232_Outputs_Data_Out_30\000"
"RS232_Outputs_Data_Out_31\000"
"RS232_Outputs_Data_Out_32\000"
"Analog_Voltage_Outputs_channel 1\000"
"Analog_Voltage_Outputs_channel 2\000"
"Analog_Current_Outputs_channel 1\000"
"Analog_Current_Outputs_channel 2\000\377";
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
BOOLEAN(Function_Digital_Outputs_Channel_1); /* Subindex62 - Function_Digital_Outputs_Channel_1 */
BOOLEAN(Function_Digital_Outputs_Channel_2); /* Subindex63 - Function_Digital_Outputs_Channel_2 */
BOOLEAN(Function_Digital_Outputs_Channel_3); /* Subindex64 - Function_Digital_Outputs_Channel_3 */
BOOLEAN(Function_Digital_Outputs_Channel_4); /* Subindex65 - Function_Digital_Outputs_Channel_4 */
BOOLEAN(Function_Digital_Outputs_Channel_5); /* Subindex66 - Function_Digital_Outputs_Channel_5 */
BOOLEAN(Function_Digital_Outputs_Channel_6); /* Subindex67 - Function_Digital_Outputs_Channel_6 */
BOOLEAN(Function_Digital_Outputs_Channel_7); /* Subindex68 - Function_Digital_Outputs_Channel_7 */
BOOLEAN(Function_Digital_Outputs_Channel_8); /* Subindex69 - Function_Digital_Outputs_Channel_8 */
BOOLEAN(Internal_Digital_Outputs_Channel_1); /* Subindex70 - Internal_Digital_Outputs_Channel_1 */
BOOLEAN(Internal_Digital_Outputs_Channel_2); /* Subindex71 - Internal_Digital_Outputs_Channel_2 */
BOOLEAN(Internal_Digital_Outputs_Channel_3); /* Subindex72 - Internal_Digital_Outputs_Channel_3 */
BOOLEAN(Internal_Digital_Outputs_Channel_4); /* Subindex73 - Internal_Digital_Outputs_Channel_4 */
BOOLEAN(Internal_Digital_Outputs_Channel_5); /* Subindex74 - Internal_Digital_Outputs_Channel_5 */
BOOLEAN(Internal_Digital_Outputs_Channel_6); /* Subindex75 - Internal_Digital_Outputs_Channel_6 */
BOOLEAN(Internal_Digital_Outputs_Channel_7); /* Subindex76 - Internal_Digital_Outputs_Channel_7 */
BOOLEAN(Internal_Digital_Outputs_Channel_8); /* Subindex77 - Internal_Digital_Outputs_Channel_8 */
UINT16 RS232_Outputs_Count; /* Subindex78 - RS232_Outputs_Count */
UINT16 RS232_Outputs_Len; /* Subindex79 - RS232_Outputs_Len */
UINT8 RS232_Outputs_Data_Out_1; /* Subindex80 - RS232_Outputs_Data_Out_1 */
UINT8 RS232_Outputs_Data_Out_2; /* Subindex81 - RS232_Outputs_Data_Out_2 */
UINT8 RS232_Outputs_Data_Out_3; /* Subindex82 - RS232_Outputs_Data_Out_3 */
UINT8 RS232_Outputs_Data_Out_4; /* Subindex83 - RS232_Outputs_Data_Out_4 */
UINT8 RS232_Outputs_Data_Out_5; /* Subindex84 - RS232_Outputs_Data_Out_5 */
UINT8 RS232_Outputs_Data_Out_6; /* Subindex85 - RS232_Outputs_Data_Out_6 */
UINT8 RS232_Outputs_Data_Out_7; /* Subindex86 - RS232_Outputs_Data_Out_7 */
UINT8 RS232_Outputs_Data_Out_8; /* Subindex87 - RS232_Outputs_Data_Out_8 */
UINT8 RS232_Outputs_Data_Out_9; /* Subindex88 - RS232_Outputs_Data_Out_9 */
UINT8 RS232_Outputs_Data_Out_10; /* Subindex89 - RS232_Outputs_Data_Out_10 */
UINT8 RS232_Outputs_Data_Out_11; /* Subindex90 - RS232_Outputs_Data_Out_11 */
UINT8 RS232_Outputs_Data_Out_12; /* Subindex91 - RS232_Outputs_Data_Out_12 */
UINT8 RS232_Outputs_Data_Out_13; /* Subindex92 - RS232_Outputs_Data_Out_13 */
UINT8 RS232_Outputs_Data_Out_14; /* Subindex93 - RS232_Outputs_Data_Out_14 */
UINT8 RS232_Outputs_Data_Out_15; /* Subindex94 - RS232_Outputs_Data_Out_15 */
UINT8 RS232_Outputs_Data_Out_16; /* Subindex95 - RS232_Outputs_Data_Out_16 */
UINT8 RS232_Outputs_Data_Out_17; /* Subindex96 - RS232_Outputs_Data_Out_17 */
UINT8 RS232_Outputs_Data_Out_18; /* Subindex97 - RS232_Outputs_Data_Out_18 */
UINT8 RS232_Outputs_Data_Out_19; /* Subindex98 - RS232_Outputs_Data_Out_19 */
UINT8 RS232_Outputs_Data_Out_20; /* Subindex99 - RS232_Outputs_Data_Out_20 */
UINT8 RS232_Outputs_Data_Out_21; /* Subindex100 - RS232_Outputs_Data_Out_21 */
UINT8 RS232_Outputs_Data_Out_22; /* Subindex101 - RS232_Outputs_Data_Out_22 */
UINT8 RS232_Outputs_Data_Out_23; /* Subindex102 - RS232_Outputs_Data_Out_23 */
UINT8 RS232_Outputs_Data_Out_24; /* Subindex103 - RS232_Outputs_Data_Out_24 */
UINT8 RS232_Outputs_Data_Out_25; /* Subindex104 - RS232_Outputs_Data_Out_25 */
UINT8 RS232_Outputs_Data_Out_26; /* Subindex105 - RS232_Outputs_Data_Out_26 */
UINT8 RS232_Outputs_Data_Out_27; /* Subindex106 - RS232_Outputs_Data_Out_27 */
UINT8 RS232_Outputs_Data_Out_28; /* Subindex107 - RS232_Outputs_Data_Out_28 */
UINT8 RS232_Outputs_Data_Out_29; /* Subindex108 - RS232_Outputs_Data_Out_29 */
UINT8 RS232_Outputs_Data_Out_30; /* Subindex109 - RS232_Outputs_Data_Out_30 */
UINT8 RS232_Outputs_Data_Out_31; /* Subindex110 - RS232_Outputs_Data_Out_31 */
UINT8 RS232_Outputs_Data_Out_32; /* Subindex111 - RS232_Outputs_Data_Out_32 */
UINT16 Analog_Voltage_Outputs_channel1; /* Subindex112 - Analog_Voltage_Outputs_channel 1 */
UINT16 Analog_Voltage_Outputs_channel2; /* Subindex113 - Analog_Voltage_Outputs_channel 2 */
UINT16 Analog_Current_Outputs_channel1; /* Subindex114 - Analog_Current_Outputs_channel 1 */
UINT16 Analog_Current_Outputs_channel2; /* Subindex115 - Analog_Current_Outputs_channel 2 */
} OBJ_STRUCT_PACKED_END
TOBJ7000;
#endif //#ifndef _ROBOT_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ7000 OUT_GENERIC0x7000
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
={115,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8000 : RS485_Baudrate
******************************************************************************/
/**
* \addtogroup 0x8000 0x8000 | RS485_Baudrate
* @{
* \brief Object 0x8000 (RS485_Baudrate) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x8000 = { DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x8000[] = "RS485_Baudrate\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT32 RS485_Baudrate0x8000
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x01C200
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8001 : CAN_Baudrate
******************************************************************************/
/**
* \addtogroup 0x8001 0x8001 | CAN_Baudrate
* @{
* \brief Object 0x8001 (CAN_Baudrate) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x8001 = { DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x8001[] = "CAN_Baudrate\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT32 CAN_Baudrate0x8001
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x01F4
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8002 : RS232_Baudrate
******************************************************************************/
/**
* \addtogroup 0x8002 0x8002 | RS232_Baudrate
* @{
* \brief Object 0x8002 (RS232_Baudrate) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x8002 = { DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x8002[] = "RS232_Baudrate\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT32 RS232_Baudrate0x8002
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x01C200
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8003 : MotEncPerRotate
******************************************************************************/
/**
* \addtogroup 0x8003 0x8003 | MotEncPerRotate
* @{
* \brief Object 0x8003 (MotEncPerRotate) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x8003 = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x8003[] = "MotEncPerRotate\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 MotEncPerRotate0x8003
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x07D0
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8004 : Software_Version
******************************************************************************/
/**
* \addtogroup 0x8004 0x8004 | Software_Version
* @{
* \brief Object 0x8004 (Software_Version) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x8004 = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x8004[] = "Software_Version\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Software_Version0x8004
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8005 : Hardware_Version
******************************************************************************/
/**
* \addtogroup 0x8005 0x8005 | Hardware_Version
* @{
* \brief Object 0x8005 (Hardware_Version) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x8005 = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x8005[] = "Hardware_Version\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Hardware_Version0x8005
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8006 : Analog_Input_Switch_Channel1
******************************************************************************/
/**
* \addtogroup 0x8006 0x8006 | Analog_Input_Switch_Channel1
* @{
* \brief Object 0x8006 (Analog_Input_Switch_Channel1) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x8006 = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x8006[] = "Analog_Input_Switch_Channel1\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Analog_Input_Switch_Channel10x8006
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8007 : Analog_Input_Switch_Channel2
******************************************************************************/
/**
* \addtogroup 0x8007 0x8007 | Analog_Input_Switch_Channel2
* @{
* \brief Object 0x8007 (Analog_Input_Switch_Channel2) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x8007 = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x8007[] = "Analog_Input_Switch_Channel2\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Analog_Input_Switch_Channel20x8007
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8008 : Analog_Output_Switch_Channel1
******************************************************************************/
/**
* \addtogroup 0x8008 0x8008 | Analog_Output_Switch_Channel1
* @{
* \brief Object 0x8008 (Analog_Output_Switch_Channel1) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x8008 = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x8008[] = "Analog_Output_Switch_Channel1\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Analog_Output_Switch_Channel10x8008
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8009 : Analog_Output_Switch_Channel2
******************************************************************************/
/**
* \addtogroup 0x8009 0x8009 | Analog_Output_Switch_Channel2
* @{
* \brief Object 0x8009 (Analog_Output_Switch_Channel2) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x8009 = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x8009[] = "Analog_Output_Switch_Channel2\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Analog_Output_Switch_Channel20x8009
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x800A : Over_Voltage_48V
******************************************************************************/
/**
* \addtogroup 0x800A 0x800A | Over_Voltage_48V
* @{
* \brief Object 0x800A (Over_Voltage_48V) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x800A = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x800A[] = "Over_Voltage_48V\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Over_Voltage_48V0x800A
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x800B : Under_Voltage_48V
******************************************************************************/
/**
* \addtogroup 0x800B 0x800B | Under_Voltage_48V
* @{
* \brief Object 0x800B (Under_Voltage_48V) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x800B = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x800B[] = "Under_Voltage_48V\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Under_Voltage_48V0x800B
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x800C : Over_Current_48V
******************************************************************************/
/**
* \addtogroup 0x800C 0x800C | Over_Current_48V
* @{
* \brief Object 0x800C (Over_Current_48V) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x800C = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x800C[] = "Over_Current_48V\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Over_Current_48V0x800C
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x800D : Over_Voltage_24V
******************************************************************************/
/**
* \addtogroup 0x800D 0x800D | Over_Voltage_24V
* @{
* \brief Object 0x800D (Over_Voltage_24V) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x800D = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x800D[] = "Over_Voltage_24V\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Over_Voltage_24V0x800D
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x800E : Under_Voltage_24V
******************************************************************************/
/**
* \addtogroup 0x800E 0x800E | Under_Voltage_24V
* @{
* \brief Object 0x800E (Under_Voltage_24V) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x800E = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x800E[] = "Under_Voltage_24V\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Under_Voltage_24V0x800E
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x800F : Over_Current_24V
******************************************************************************/
/**
* \addtogroup 0x800F 0x800F | Over_Current_24V
* @{
* \brief Object 0x800F (Over_Current_24V) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x800F = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x800F[] = "Over_Current_24V\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Over_Current_24V0x800F
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8010 : Over_Temperature
******************************************************************************/
/**
* \addtogroup 0x8010 0x8010 | Over_Temperature
* @{
* \brief Object 0x8010 (Over_Temperature) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x8010 = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x8010[] = "Over_Temperature\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Over_Temperature0x8010
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8011 : Res_Over_heat
******************************************************************************/
/**
* \addtogroup 0x8011 0x8011 | Res_Over_heat
* @{
* \brief Object 0x8011 (Res_Over_heat) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x8011 = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x8011[] = "Res_Over_heat\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Res_Over_heat0x8011
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8012 : Consecutive_Failure_CNT
******************************************************************************/
/**
* \addtogroup 0x8012 0x8012 | Consecutive_Failure_CNT
* @{
* \brief Object 0x8012 (Consecutive_Failure_CNT) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x8012 = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x8012[] = "Consecutive_Failure_CNT\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Consecutive_Failure_CNT0x8012
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8013 : Error_Code
******************************************************************************/
/**
* \addtogroup 0x8013 0x8013 | Error_Code
* @{
* \brief Object 0x8013 (Error_Code) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x8013 = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x8013[] = "Error_Code\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Error_Code0x8013
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8014 : Board_Temperature
******************************************************************************/
/**
* \addtogroup 0x8014 0x8014 | Board_Temperature
* @{
* \brief Object 0x8014 (Board_Temperature) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x8014 = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x8014[] = "Board_Temperature\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Board_Temperature0x8014
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8015 : Test_Mode
******************************************************************************/
/**
* \addtogroup 0x8015 0x8015 | Test_Mode
* @{
* \brief Object 0x8015 (Test_Mode) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x8015 = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x8015[] = "Test_Mode\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Test_Mode0x8015
#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
= 0x00
#endif
;
/** @}*/







#ifdef _OBJD_
TOBJECT    OBJMEM ApplicationObjDic[] = {
/* Object 0x1600 */
{NULL , NULL ,  0x1600 , {DEFTYPE_PDOMAPPING , 115 | (OBJCODE_REC << 8)} , asEntryDesc0x1600 , aName0x1600 , &OUT_GENERICProcessDataMapping0x1600, NULL , NULL , 0x0000 },
/* Object 0x1A00 */
{NULL , NULL ,  0x1A00 , {DEFTYPE_PDOMAPPING , 121 | (OBJCODE_REC << 8)} , asEntryDesc0x1A00 , aName0x1A00 , &IN_GENERICProcessDataMapping0x1A00, NULL , NULL , 0x0000 },
/* Object 0x1C12 */
{NULL , NULL ,  0x1C12 , {DEFTYPE_UNSIGNED16 , 1 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C12 , aName0x1C12 , &sRxPDOassign, NULL , NULL , 0x0000 },
/* Object 0x1C13 */
{NULL , NULL ,  0x1C13 , {DEFTYPE_UNSIGNED16 , 1 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C13 , aName0x1C13 , &sTxPDOassign, NULL , NULL , 0x0000 },
/* Object 0x2000 */
{NULL , NULL ,  0x2000 , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x2000 , aName0x2000 , &Software_Version0x2000 , NULL , NULL , 0x0000 },
/* Object 0x2001 */
{NULL , NULL ,  0x2001 , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x2001 , aName0x2001 , &Hardware_type0x2001 , NULL , NULL , 0x0000 },
/* Object 0x6000 */
{NULL , NULL ,  0x6000 , {DEFTYPE_RECORD , 121 | (OBJCODE_REC << 8)} , asEntryDesc0x6000 , aName0x6000 , &IN_GENERIC0x6000, NULL , NULL , 0x0000 },
/* Object 0x7000 */
{NULL , NULL ,  0x7000 , {DEFTYPE_RECORD , 115 | (OBJCODE_REC << 8)} , asEntryDesc0x7000 , aName0x7000 , &OUT_GENERIC0x7000, NULL , NULL , 0x0000 },
/* Object 0x8000 */
{NULL , NULL ,  0x8000 , {DEFTYPE_UNSIGNED32 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x8000 , aName0x8000 , &RS485_Baudrate0x8000 , NULL , NULL , 0x0000 },
/* Object 0x8001 */
{NULL , NULL ,  0x8001 , {DEFTYPE_UNSIGNED32 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x8001 , aName0x8001 , &CAN_Baudrate0x8001 , NULL , NULL , 0x0000 },
/* Object 0x8002 */
{NULL , NULL ,  0x8002 , {DEFTYPE_UNSIGNED32 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x8002 , aName0x8002 , &RS232_Baudrate0x8002 , NULL , NULL , 0x0000 },
/* Object 0x8003 */
{NULL , NULL ,  0x8003 , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x8003 , aName0x8003 , &MotEncPerRotate0x8003 , NULL , NULL , 0x0000 },
/* Object 0x8004 */
{NULL , NULL ,  0x8004 , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x8004 , aName0x8004 , &Software_Version0x8004 , NULL , NULL , 0x0000 },
/* Object 0x8005 */
{NULL , NULL ,  0x8005 , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x8005 , aName0x8005 , &Hardware_Version0x8005 , NULL , NULL , 0x0000 },
/* Object 0x8006 */
{NULL , NULL ,  0x8006 , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x8006 , aName0x8006 , &Analog_Input_Switch_Channel10x8006 , NULL , NULL , 0x0000 },
/* Object 0x8007 */
{NULL , NULL ,  0x8007 , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x8007 , aName0x8007 , &Analog_Input_Switch_Channel20x8007 , NULL , NULL , 0x0000 },
/* Object 0x8008 */
{NULL , NULL ,  0x8008 , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x8008 , aName0x8008 , &Analog_Output_Switch_Channel10x8008 , NULL , NULL , 0x0000 },
/* Object 0x8009 */
{NULL , NULL ,  0x8009 , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x8009 , aName0x8009 , &Analog_Output_Switch_Channel20x8009 , NULL , NULL , 0x0000 },
/* Object 0x800A */
{NULL , NULL ,  0x800A , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x800A , aName0x800A , &Over_Voltage_48V0x800A , NULL , NULL , 0x0000 },
/* Object 0x800B */
{NULL , NULL ,  0x800B , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x800B , aName0x800B , &Under_Voltage_48V0x800B , NULL , NULL , 0x0000 },
/* Object 0x800C */
{NULL , NULL ,  0x800C , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x800C , aName0x800C , &Over_Current_48V0x800C , NULL , NULL , 0x0000 },
/* Object 0x800D */
{NULL , NULL ,  0x800D , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x800D , aName0x800D , &Over_Voltage_24V0x800D , NULL , NULL , 0x0000 },
/* Object 0x800E */
{NULL , NULL ,  0x800E , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x800E , aName0x800E , &Under_Voltage_24V0x800E , NULL , NULL , 0x0000 },
/* Object 0x800F */
{NULL , NULL ,  0x800F , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x800F , aName0x800F , &Over_Current_24V0x800F , NULL , NULL , 0x0000 },
/* Object 0x8010 */
{NULL , NULL ,  0x8010 , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x8010 , aName0x8010 , &Over_Temperature0x8010 , NULL , NULL , 0x0000 },
/* Object 0x8011 */
{NULL , NULL ,  0x8011 , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x8011 , aName0x8011 , &Res_Over_heat0x8011 , NULL , NULL , 0x0000 },
/* Object 0x8012 */
{NULL , NULL ,  0x8012 , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x8012 , aName0x8012 , &Consecutive_Failure_CNT0x8012 , NULL , NULL , 0x0000 },
/* Object 0x8013 */
{NULL , NULL ,  0x8013 , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x8013 , aName0x8013 , &Error_Code0x8013 , NULL , NULL , 0x0000 },
/* Object 0x8014 */
{NULL , NULL ,  0x8014 , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x8014 , aName0x8014 , &Board_Temperature0x8014 , NULL , NULL , 0x0000 },
/* Object 0x8015 */
{NULL , NULL ,  0x8015 , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x8015 , aName0x8015 , &Test_Mode0x8015 , NULL , NULL , 0x0000 },
{NULL,NULL, 0xFFFF, {0, 0}, NULL, NULL, NULL, NULL}};
#endif    //#ifdef _OBJD_
#undef PROTO

/** @}*/
#define _ROBOT_DEVICE_OBJECTS_H_
