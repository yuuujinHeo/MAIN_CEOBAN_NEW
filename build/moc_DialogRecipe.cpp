/****************************************************************************
** Meta object code from reading C++ file 'DialogRecipe.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../DialogRecipe.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogRecipe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogRecipe_t {
    QByteArrayData data[120];
    char stringdata0[2824];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogRecipe_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogRecipe_t qt_meta_stringdata_DialogRecipe = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DialogRecipe"
QT_MOC_LITERAL(1, 13, 6), // "cancel"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 14), // "add_ingredient"
QT_MOC_LITERAL(4, 36, 14), // "ST_RECIPE_STEP"
QT_MOC_LITERAL(5, 51, 10), // "ingredient"
QT_MOC_LITERAL(6, 62, 8), // "add_menu"
QT_MOC_LITERAL(7, 71, 12), // "ST_MENU_INFO"
QT_MOC_LITERAL(8, 84, 4), // "menu"
QT_MOC_LITERAL(9, 89, 9), // "edit_menu"
QT_MOC_LITERAL(10, 99, 5), // "index"
QT_MOC_LITERAL(11, 105, 15), // "edit_ingredient"
QT_MOC_LITERAL(12, 121, 22), // "on_BTN_COF_ESP_clicked"
QT_MOC_LITERAL(13, 144, 23), // "on_BTN_COF_ESP2_clicked"
QT_MOC_LITERAL(14, 168, 25), // "on_BTN_COF_ICELAT_clicked"
QT_MOC_LITERAL(15, 194, 22), // "on_BTN_COF_AME_clicked"
QT_MOC_LITERAL(16, 217, 23), // "on_BTN_COF_AME2_clicked"
QT_MOC_LITERAL(17, 241, 22), // "on_BTN_COF_LAT_clicked"
QT_MOC_LITERAL(18, 264, 23), // "on_BTN_COF_MILK_clicked"
QT_MOC_LITERAL(19, 288, 26), // "on_BTN_COF_ICEMILK_clicked"
QT_MOC_LITERAL(20, 315, 25), // "on_BTN_COF_CANCEL_clicked"
QT_MOC_LITERAL(21, 341, 22), // "on_BTN_SODA_OK_clicked"
QT_MOC_LITERAL(22, 364, 26), // "on_BTN_SODA_CANCEL_clicked"
QT_MOC_LITERAL(23, 391, 23), // "on_BTN_SYRUP_OK_clicked"
QT_MOC_LITERAL(24, 415, 27), // "on_BTN_SYRUP_CANCEL_clicked"
QT_MOC_LITERAL(25, 443, 27), // "on_BTN_EDIT_MENU_OK_clicked"
QT_MOC_LITERAL(26, 471, 31), // "on_BTN_EDIT_MENU_CANCEL_clicked"
QT_MOC_LITERAL(27, 503, 26), // "on_BTN_ADD_MENU_OK_clicked"
QT_MOC_LITERAL(28, 530, 30), // "on_BTN_ADD_MENU_CANCEL_clicked"
QT_MOC_LITERAL(29, 561, 25), // "on_BTN_RECIPE_ICE_clicked"
QT_MOC_LITERAL(30, 587, 28), // "on_BTN_RECIPE_COFFEE_clicked"
QT_MOC_LITERAL(31, 616, 26), // "on_BTN_RECIPE_SODA_clicked"
QT_MOC_LITERAL(32, 643, 27), // "on_BTN_RECIPE_SYRUP_clicked"
QT_MOC_LITERAL(33, 671, 21), // "on_BTN_ICE_OK_clicked"
QT_MOC_LITERAL(34, 693, 25), // "on_BTN_ICE_CANCEL_clicked"
QT_MOC_LITERAL(35, 719, 24), // "on_BTN_SODA_OK_2_clicked"
QT_MOC_LITERAL(36, 744, 28), // "on_BTN_SODA_CANCEL_2_clicked"
QT_MOC_LITERAL(37, 773, 23), // "on_BTN_ICE_OK_2_clicked"
QT_MOC_LITERAL(38, 797, 27), // "on_BTN_ICE_CANCEL_2_clicked"
QT_MOC_LITERAL(39, 825, 25), // "on_BTN_SYRUP_OK_2_clicked"
QT_MOC_LITERAL(40, 851, 29), // "on_BTN_SYRUP_CANCEL_2_clicked"
QT_MOC_LITERAL(41, 881, 24), // "on_BTN_COF_ESP_2_clicked"
QT_MOC_LITERAL(42, 906, 25), // "on_BTN_COF_ESP2_2_clicked"
QT_MOC_LITERAL(43, 932, 27), // "on_BTN_COF_ICELAT_2_clicked"
QT_MOC_LITERAL(44, 960, 24), // "on_BTN_COF_AME_2_clicked"
QT_MOC_LITERAL(45, 985, 25), // "on_BTN_COF_AME2_2_clicked"
QT_MOC_LITERAL(46, 1011, 24), // "on_BTN_COF_LAT_2_clicked"
QT_MOC_LITERAL(47, 1036, 25), // "on_BTN_COF_MILK_2_clicked"
QT_MOC_LITERAL(48, 1062, 28), // "on_BTN_COF_ICEMILK_2_clicked"
QT_MOC_LITERAL(49, 1091, 27), // "on_BTN_COF_CANCEL_2_clicked"
QT_MOC_LITERAL(50, 1119, 21), // "on_BTN_COF_E1_clicked"
QT_MOC_LITERAL(51, 1141, 21), // "on_BTN_COF_E2_clicked"
QT_MOC_LITERAL(52, 1163, 22), // "on_BTN_COF_LH1_clicked"
QT_MOC_LITERAL(53, 1186, 22), // "on_BTN_COF_LH2_clicked"
QT_MOC_LITERAL(54, 1209, 22), // "on_BTN_COF_LH3_clicked"
QT_MOC_LITERAL(55, 1232, 22), // "on_BTN_COF_LI1_clicked"
QT_MOC_LITERAL(56, 1255, 22), // "on_BTN_COF_LI2_clicked"
QT_MOC_LITERAL(57, 1278, 22), // "on_BTN_COF_LI3_clicked"
QT_MOC_LITERAL(58, 1301, 22), // "on_BTN_COF_PE1_clicked"
QT_MOC_LITERAL(59, 1324, 22), // "on_BTN_COF_PE2_clicked"
QT_MOC_LITERAL(60, 1347, 23), // "on_BTN_COF_PLH1_clicked"
QT_MOC_LITERAL(61, 1371, 23), // "on_BTN_COF_PLH2_clicked"
QT_MOC_LITERAL(62, 1395, 23), // "on_BTN_COF_PLI1_clicked"
QT_MOC_LITERAL(63, 1419, 23), // "on_BTN_COF_PLI2_clicked"
QT_MOC_LITERAL(64, 1443, 23), // "on_BTN_COF_MFH1_clicked"
QT_MOC_LITERAL(65, 1467, 23), // "on_BTN_COF_MFH2_clicked"
QT_MOC_LITERAL(66, 1491, 23), // "on_BTN_COF_MFI1_clicked"
QT_MOC_LITERAL(67, 1515, 23), // "on_BTN_COF_MFI2_clicked"
QT_MOC_LITERAL(68, 1539, 23), // "on_BTN_COF_MFI3_clicked"
QT_MOC_LITERAL(69, 1563, 23), // "on_BTN_COF_E1_2_clicked"
QT_MOC_LITERAL(70, 1587, 23), // "on_BTN_COF_E2_2_clicked"
QT_MOC_LITERAL(71, 1611, 24), // "on_BTN_COF_LH1_2_clicked"
QT_MOC_LITERAL(72, 1636, 24), // "on_BTN_COF_LH2_2_clicked"
QT_MOC_LITERAL(73, 1661, 24), // "on_BTN_COF_LH3_2_clicked"
QT_MOC_LITERAL(74, 1686, 24), // "on_BTN_COF_LI1_2_clicked"
QT_MOC_LITERAL(75, 1711, 24), // "on_BTN_COF_LI2_2_clicked"
QT_MOC_LITERAL(76, 1736, 24), // "on_BTN_COF_LI3_2_clicked"
QT_MOC_LITERAL(77, 1761, 24), // "on_BTN_COF_PE1_2_clicked"
QT_MOC_LITERAL(78, 1786, 24), // "on_BTN_COF_PE2_2_clicked"
QT_MOC_LITERAL(79, 1811, 25), // "on_BTN_COF_PLH1_2_clicked"
QT_MOC_LITERAL(80, 1837, 25), // "on_BTN_COF_PLH2_2_clicked"
QT_MOC_LITERAL(81, 1863, 25), // "on_BTN_COF_PLI1_2_clicked"
QT_MOC_LITERAL(82, 1889, 25), // "on_BTN_COF_PLI2_2_clicked"
QT_MOC_LITERAL(83, 1915, 25), // "on_BTN_COF_MFH1_2_clicked"
QT_MOC_LITERAL(84, 1941, 25), // "on_BTN_COF_MFH2_2_clicked"
QT_MOC_LITERAL(85, 1967, 25), // "on_BTN_COF_MFI1_2_clicked"
QT_MOC_LITERAL(86, 1993, 25), // "on_BTN_COF_MFI2_2_clicked"
QT_MOC_LITERAL(87, 2019, 25), // "on_BTN_COF_MFI3_2_clicked"
QT_MOC_LITERAL(88, 2045, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(89, 2073, 24), // "on_BTN_SODA_SODA_clicked"
QT_MOC_LITERAL(90, 2098, 24), // "on_BTN_SODA_COLD_clicked"
QT_MOC_LITERAL(91, 2123, 23), // "on_BTN_SODA_HOT_clicked"
QT_MOC_LITERAL(92, 2147, 22), // "on_BTN_SYRUP_1_clicked"
QT_MOC_LITERAL(93, 2170, 22), // "on_BTN_SYRUP_2_clicked"
QT_MOC_LITERAL(94, 2193, 22), // "on_BTN_SYRUP_3_clicked"
QT_MOC_LITERAL(95, 2216, 22), // "on_BTN_SYRUP_4_clicked"
QT_MOC_LITERAL(96, 2239, 22), // "on_BTN_SYRUP_5_clicked"
QT_MOC_LITERAL(97, 2262, 22), // "on_BTN_SYRUP_6_clicked"
QT_MOC_LITERAL(98, 2285, 22), // "on_BTN_SYRUP_7_clicked"
QT_MOC_LITERAL(99, 2308, 22), // "on_BTN_SYRUP_8_clicked"
QT_MOC_LITERAL(100, 2331, 22), // "on_BTN_SYRUP_9_clicked"
QT_MOC_LITERAL(101, 2354, 23), // "on_BTN_SYRUP_10_clicked"
QT_MOC_LITERAL(102, 2378, 23), // "on_BTN_SYRUP_11_clicked"
QT_MOC_LITERAL(103, 2402, 23), // "on_BTN_SYRUP_12_clicked"
QT_MOC_LITERAL(104, 2426, 23), // "on_BTN_SYRUP_13_clicked"
QT_MOC_LITERAL(105, 2450, 23), // "on_BTN_SYRUP_14_clicked"
QT_MOC_LITERAL(106, 2474, 23), // "on_BTN_SYRUP_15_clicked"
QT_MOC_LITERAL(107, 2498, 23), // "on_BTN_SYRUP_16_clicked"
QT_MOC_LITERAL(108, 2522, 23), // "on_BTN_SYRUP_17_clicked"
QT_MOC_LITERAL(109, 2546, 23), // "on_BTN_SYRUP_18_clicked"
QT_MOC_LITERAL(110, 2570, 23), // "on_BTN_SYRUP_19_clicked"
QT_MOC_LITERAL(111, 2594, 23), // "on_BTN_SYRUP_20_clicked"
QT_MOC_LITERAL(112, 2618, 23), // "on_BTN_SYRUP_21_clicked"
QT_MOC_LITERAL(113, 2642, 23), // "on_BTN_SYRUP_22_clicked"
QT_MOC_LITERAL(114, 2666, 23), // "on_BTN_SYRUP_23_clicked"
QT_MOC_LITERAL(115, 2690, 23), // "on_BTN_SYRUP_24_clicked"
QT_MOC_LITERAL(116, 2714, 29), // "on_tabWidget_2_currentChanged"
QT_MOC_LITERAL(117, 2744, 26), // "on_BTN_SODA_SODA_2_clicked"
QT_MOC_LITERAL(118, 2771, 26), // "on_BTN_SODA_COLD_2_clicked"
QT_MOC_LITERAL(119, 2798, 25) // "on_BTN_SODA_HOT_2_clicked"

    },
    "DialogRecipe\0cancel\0\0add_ingredient\0"
    "ST_RECIPE_STEP\0ingredient\0add_menu\0"
    "ST_MENU_INFO\0menu\0edit_menu\0index\0"
    "edit_ingredient\0on_BTN_COF_ESP_clicked\0"
    "on_BTN_COF_ESP2_clicked\0"
    "on_BTN_COF_ICELAT_clicked\0"
    "on_BTN_COF_AME_clicked\0on_BTN_COF_AME2_clicked\0"
    "on_BTN_COF_LAT_clicked\0on_BTN_COF_MILK_clicked\0"
    "on_BTN_COF_ICEMILK_clicked\0"
    "on_BTN_COF_CANCEL_clicked\0"
    "on_BTN_SODA_OK_clicked\0"
    "on_BTN_SODA_CANCEL_clicked\0"
    "on_BTN_SYRUP_OK_clicked\0"
    "on_BTN_SYRUP_CANCEL_clicked\0"
    "on_BTN_EDIT_MENU_OK_clicked\0"
    "on_BTN_EDIT_MENU_CANCEL_clicked\0"
    "on_BTN_ADD_MENU_OK_clicked\0"
    "on_BTN_ADD_MENU_CANCEL_clicked\0"
    "on_BTN_RECIPE_ICE_clicked\0"
    "on_BTN_RECIPE_COFFEE_clicked\0"
    "on_BTN_RECIPE_SODA_clicked\0"
    "on_BTN_RECIPE_SYRUP_clicked\0"
    "on_BTN_ICE_OK_clicked\0on_BTN_ICE_CANCEL_clicked\0"
    "on_BTN_SODA_OK_2_clicked\0"
    "on_BTN_SODA_CANCEL_2_clicked\0"
    "on_BTN_ICE_OK_2_clicked\0"
    "on_BTN_ICE_CANCEL_2_clicked\0"
    "on_BTN_SYRUP_OK_2_clicked\0"
    "on_BTN_SYRUP_CANCEL_2_clicked\0"
    "on_BTN_COF_ESP_2_clicked\0"
    "on_BTN_COF_ESP2_2_clicked\0"
    "on_BTN_COF_ICELAT_2_clicked\0"
    "on_BTN_COF_AME_2_clicked\0"
    "on_BTN_COF_AME2_2_clicked\0"
    "on_BTN_COF_LAT_2_clicked\0"
    "on_BTN_COF_MILK_2_clicked\0"
    "on_BTN_COF_ICEMILK_2_clicked\0"
    "on_BTN_COF_CANCEL_2_clicked\0"
    "on_BTN_COF_E1_clicked\0on_BTN_COF_E2_clicked\0"
    "on_BTN_COF_LH1_clicked\0on_BTN_COF_LH2_clicked\0"
    "on_BTN_COF_LH3_clicked\0on_BTN_COF_LI1_clicked\0"
    "on_BTN_COF_LI2_clicked\0on_BTN_COF_LI3_clicked\0"
    "on_BTN_COF_PE1_clicked\0on_BTN_COF_PE2_clicked\0"
    "on_BTN_COF_PLH1_clicked\0on_BTN_COF_PLH2_clicked\0"
    "on_BTN_COF_PLI1_clicked\0on_BTN_COF_PLI2_clicked\0"
    "on_BTN_COF_MFH1_clicked\0on_BTN_COF_MFH2_clicked\0"
    "on_BTN_COF_MFI1_clicked\0on_BTN_COF_MFI2_clicked\0"
    "on_BTN_COF_MFI3_clicked\0on_BTN_COF_E1_2_clicked\0"
    "on_BTN_COF_E2_2_clicked\0"
    "on_BTN_COF_LH1_2_clicked\0"
    "on_BTN_COF_LH2_2_clicked\0"
    "on_BTN_COF_LH3_2_clicked\0"
    "on_BTN_COF_LI1_2_clicked\0"
    "on_BTN_COF_LI2_2_clicked\0"
    "on_BTN_COF_LI3_2_clicked\0"
    "on_BTN_COF_PE1_2_clicked\0"
    "on_BTN_COF_PE2_2_clicked\0"
    "on_BTN_COF_PLH1_2_clicked\0"
    "on_BTN_COF_PLH2_2_clicked\0"
    "on_BTN_COF_PLI1_2_clicked\0"
    "on_BTN_COF_PLI2_2_clicked\0"
    "on_BTN_COF_MFH1_2_clicked\0"
    "on_BTN_COF_MFH2_2_clicked\0"
    "on_BTN_COF_MFI1_2_clicked\0"
    "on_BTN_COF_MFI2_2_clicked\0"
    "on_BTN_COF_MFI3_2_clicked\0"
    "on_tabWidget_currentChanged\0"
    "on_BTN_SODA_SODA_clicked\0"
    "on_BTN_SODA_COLD_clicked\0"
    "on_BTN_SODA_HOT_clicked\0on_BTN_SYRUP_1_clicked\0"
    "on_BTN_SYRUP_2_clicked\0on_BTN_SYRUP_3_clicked\0"
    "on_BTN_SYRUP_4_clicked\0on_BTN_SYRUP_5_clicked\0"
    "on_BTN_SYRUP_6_clicked\0on_BTN_SYRUP_7_clicked\0"
    "on_BTN_SYRUP_8_clicked\0on_BTN_SYRUP_9_clicked\0"
    "on_BTN_SYRUP_10_clicked\0on_BTN_SYRUP_11_clicked\0"
    "on_BTN_SYRUP_12_clicked\0on_BTN_SYRUP_13_clicked\0"
    "on_BTN_SYRUP_14_clicked\0on_BTN_SYRUP_15_clicked\0"
    "on_BTN_SYRUP_16_clicked\0on_BTN_SYRUP_17_clicked\0"
    "on_BTN_SYRUP_18_clicked\0on_BTN_SYRUP_19_clicked\0"
    "on_BTN_SYRUP_20_clicked\0on_BTN_SYRUP_21_clicked\0"
    "on_BTN_SYRUP_22_clicked\0on_BTN_SYRUP_23_clicked\0"
    "on_BTN_SYRUP_24_clicked\0"
    "on_tabWidget_2_currentChanged\0"
    "on_BTN_SODA_SODA_2_clicked\0"
    "on_BTN_SODA_COLD_2_clicked\0"
    "on_BTN_SODA_HOT_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogRecipe[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     113,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  579,    2, 0x06 /* Public */,
       3,    1,  580,    2, 0x06 /* Public */,
       6,    1,  583,    2, 0x06 /* Public */,
       9,    2,  586,    2, 0x06 /* Public */,
      11,    2,  591,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,  596,    2, 0x08 /* Private */,
      13,    0,  597,    2, 0x08 /* Private */,
      14,    0,  598,    2, 0x08 /* Private */,
      15,    0,  599,    2, 0x08 /* Private */,
      16,    0,  600,    2, 0x08 /* Private */,
      17,    0,  601,    2, 0x08 /* Private */,
      18,    0,  602,    2, 0x08 /* Private */,
      19,    0,  603,    2, 0x08 /* Private */,
      20,    0,  604,    2, 0x08 /* Private */,
      21,    0,  605,    2, 0x08 /* Private */,
      22,    0,  606,    2, 0x08 /* Private */,
      23,    0,  607,    2, 0x08 /* Private */,
      24,    0,  608,    2, 0x08 /* Private */,
      25,    0,  609,    2, 0x08 /* Private */,
      26,    0,  610,    2, 0x08 /* Private */,
      27,    0,  611,    2, 0x08 /* Private */,
      28,    0,  612,    2, 0x08 /* Private */,
      29,    0,  613,    2, 0x08 /* Private */,
      30,    0,  614,    2, 0x08 /* Private */,
      31,    0,  615,    2, 0x08 /* Private */,
      32,    0,  616,    2, 0x08 /* Private */,
      33,    0,  617,    2, 0x08 /* Private */,
      34,    0,  618,    2, 0x08 /* Private */,
      35,    0,  619,    2, 0x08 /* Private */,
      36,    0,  620,    2, 0x08 /* Private */,
      37,    0,  621,    2, 0x08 /* Private */,
      38,    0,  622,    2, 0x08 /* Private */,
      39,    0,  623,    2, 0x08 /* Private */,
      40,    0,  624,    2, 0x08 /* Private */,
      41,    0,  625,    2, 0x08 /* Private */,
      42,    0,  626,    2, 0x08 /* Private */,
      43,    0,  627,    2, 0x08 /* Private */,
      44,    0,  628,    2, 0x08 /* Private */,
      45,    0,  629,    2, 0x08 /* Private */,
      46,    0,  630,    2, 0x08 /* Private */,
      47,    0,  631,    2, 0x08 /* Private */,
      48,    0,  632,    2, 0x08 /* Private */,
      49,    0,  633,    2, 0x08 /* Private */,
      50,    0,  634,    2, 0x08 /* Private */,
      51,    0,  635,    2, 0x08 /* Private */,
      52,    0,  636,    2, 0x08 /* Private */,
      53,    0,  637,    2, 0x08 /* Private */,
      54,    0,  638,    2, 0x08 /* Private */,
      55,    0,  639,    2, 0x08 /* Private */,
      56,    0,  640,    2, 0x08 /* Private */,
      57,    0,  641,    2, 0x08 /* Private */,
      58,    0,  642,    2, 0x08 /* Private */,
      59,    0,  643,    2, 0x08 /* Private */,
      60,    0,  644,    2, 0x08 /* Private */,
      61,    0,  645,    2, 0x08 /* Private */,
      62,    0,  646,    2, 0x08 /* Private */,
      63,    0,  647,    2, 0x08 /* Private */,
      64,    0,  648,    2, 0x08 /* Private */,
      65,    0,  649,    2, 0x08 /* Private */,
      66,    0,  650,    2, 0x08 /* Private */,
      67,    0,  651,    2, 0x08 /* Private */,
      68,    0,  652,    2, 0x08 /* Private */,
      69,    0,  653,    2, 0x08 /* Private */,
      70,    0,  654,    2, 0x08 /* Private */,
      71,    0,  655,    2, 0x08 /* Private */,
      72,    0,  656,    2, 0x08 /* Private */,
      73,    0,  657,    2, 0x08 /* Private */,
      74,    0,  658,    2, 0x08 /* Private */,
      75,    0,  659,    2, 0x08 /* Private */,
      76,    0,  660,    2, 0x08 /* Private */,
      77,    0,  661,    2, 0x08 /* Private */,
      78,    0,  662,    2, 0x08 /* Private */,
      79,    0,  663,    2, 0x08 /* Private */,
      80,    0,  664,    2, 0x08 /* Private */,
      81,    0,  665,    2, 0x08 /* Private */,
      82,    0,  666,    2, 0x08 /* Private */,
      83,    0,  667,    2, 0x08 /* Private */,
      84,    0,  668,    2, 0x08 /* Private */,
      85,    0,  669,    2, 0x08 /* Private */,
      86,    0,  670,    2, 0x08 /* Private */,
      87,    0,  671,    2, 0x08 /* Private */,
      88,    1,  672,    2, 0x08 /* Private */,
      89,    0,  675,    2, 0x08 /* Private */,
      90,    0,  676,    2, 0x08 /* Private */,
      91,    0,  677,    2, 0x08 /* Private */,
      92,    0,  678,    2, 0x08 /* Private */,
      93,    0,  679,    2, 0x08 /* Private */,
      94,    0,  680,    2, 0x08 /* Private */,
      95,    0,  681,    2, 0x08 /* Private */,
      96,    0,  682,    2, 0x08 /* Private */,
      97,    0,  683,    2, 0x08 /* Private */,
      98,    0,  684,    2, 0x08 /* Private */,
      99,    0,  685,    2, 0x08 /* Private */,
     100,    0,  686,    2, 0x08 /* Private */,
     101,    0,  687,    2, 0x08 /* Private */,
     102,    0,  688,    2, 0x08 /* Private */,
     103,    0,  689,    2, 0x08 /* Private */,
     104,    0,  690,    2, 0x08 /* Private */,
     105,    0,  691,    2, 0x08 /* Private */,
     106,    0,  692,    2, 0x08 /* Private */,
     107,    0,  693,    2, 0x08 /* Private */,
     108,    0,  694,    2, 0x08 /* Private */,
     109,    0,  695,    2, 0x08 /* Private */,
     110,    0,  696,    2, 0x08 /* Private */,
     111,    0,  697,    2, 0x08 /* Private */,
     112,    0,  698,    2, 0x08 /* Private */,
     113,    0,  699,    2, 0x08 /* Private */,
     114,    0,  700,    2, 0x08 /* Private */,
     115,    0,  701,    2, 0x08 /* Private */,
     116,    1,  702,    2, 0x08 /* Private */,
     117,    0,  705,    2, 0x08 /* Private */,
     118,    0,  706,    2, 0x08 /* Private */,
     119,    0,  707,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 7,   10,    8,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,   10,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogRecipe::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogRecipe *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cancel(); break;
        case 1: _t->add_ingredient((*reinterpret_cast< ST_RECIPE_STEP(*)>(_a[1]))); break;
        case 2: _t->add_menu((*reinterpret_cast< ST_MENU_INFO(*)>(_a[1]))); break;
        case 3: _t->edit_menu((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< ST_MENU_INFO(*)>(_a[2]))); break;
        case 4: _t->edit_ingredient((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< ST_RECIPE_STEP(*)>(_a[2]))); break;
        case 5: _t->on_BTN_COF_ESP_clicked(); break;
        case 6: _t->on_BTN_COF_ESP2_clicked(); break;
        case 7: _t->on_BTN_COF_ICELAT_clicked(); break;
        case 8: _t->on_BTN_COF_AME_clicked(); break;
        case 9: _t->on_BTN_COF_AME2_clicked(); break;
        case 10: _t->on_BTN_COF_LAT_clicked(); break;
        case 11: _t->on_BTN_COF_MILK_clicked(); break;
        case 12: _t->on_BTN_COF_ICEMILK_clicked(); break;
        case 13: _t->on_BTN_COF_CANCEL_clicked(); break;
        case 14: _t->on_BTN_SODA_OK_clicked(); break;
        case 15: _t->on_BTN_SODA_CANCEL_clicked(); break;
        case 16: _t->on_BTN_SYRUP_OK_clicked(); break;
        case 17: _t->on_BTN_SYRUP_CANCEL_clicked(); break;
        case 18: _t->on_BTN_EDIT_MENU_OK_clicked(); break;
        case 19: _t->on_BTN_EDIT_MENU_CANCEL_clicked(); break;
        case 20: _t->on_BTN_ADD_MENU_OK_clicked(); break;
        case 21: _t->on_BTN_ADD_MENU_CANCEL_clicked(); break;
        case 22: _t->on_BTN_RECIPE_ICE_clicked(); break;
        case 23: _t->on_BTN_RECIPE_COFFEE_clicked(); break;
        case 24: _t->on_BTN_RECIPE_SODA_clicked(); break;
        case 25: _t->on_BTN_RECIPE_SYRUP_clicked(); break;
        case 26: _t->on_BTN_ICE_OK_clicked(); break;
        case 27: _t->on_BTN_ICE_CANCEL_clicked(); break;
        case 28: _t->on_BTN_SODA_OK_2_clicked(); break;
        case 29: _t->on_BTN_SODA_CANCEL_2_clicked(); break;
        case 30: _t->on_BTN_ICE_OK_2_clicked(); break;
        case 31: _t->on_BTN_ICE_CANCEL_2_clicked(); break;
        case 32: _t->on_BTN_SYRUP_OK_2_clicked(); break;
        case 33: _t->on_BTN_SYRUP_CANCEL_2_clicked(); break;
        case 34: _t->on_BTN_COF_ESP_2_clicked(); break;
        case 35: _t->on_BTN_COF_ESP2_2_clicked(); break;
        case 36: _t->on_BTN_COF_ICELAT_2_clicked(); break;
        case 37: _t->on_BTN_COF_AME_2_clicked(); break;
        case 38: _t->on_BTN_COF_AME2_2_clicked(); break;
        case 39: _t->on_BTN_COF_LAT_2_clicked(); break;
        case 40: _t->on_BTN_COF_MILK_2_clicked(); break;
        case 41: _t->on_BTN_COF_ICEMILK_2_clicked(); break;
        case 42: _t->on_BTN_COF_CANCEL_2_clicked(); break;
        case 43: _t->on_BTN_COF_E1_clicked(); break;
        case 44: _t->on_BTN_COF_E2_clicked(); break;
        case 45: _t->on_BTN_COF_LH1_clicked(); break;
        case 46: _t->on_BTN_COF_LH2_clicked(); break;
        case 47: _t->on_BTN_COF_LH3_clicked(); break;
        case 48: _t->on_BTN_COF_LI1_clicked(); break;
        case 49: _t->on_BTN_COF_LI2_clicked(); break;
        case 50: _t->on_BTN_COF_LI3_clicked(); break;
        case 51: _t->on_BTN_COF_PE1_clicked(); break;
        case 52: _t->on_BTN_COF_PE2_clicked(); break;
        case 53: _t->on_BTN_COF_PLH1_clicked(); break;
        case 54: _t->on_BTN_COF_PLH2_clicked(); break;
        case 55: _t->on_BTN_COF_PLI1_clicked(); break;
        case 56: _t->on_BTN_COF_PLI2_clicked(); break;
        case 57: _t->on_BTN_COF_MFH1_clicked(); break;
        case 58: _t->on_BTN_COF_MFH2_clicked(); break;
        case 59: _t->on_BTN_COF_MFI1_clicked(); break;
        case 60: _t->on_BTN_COF_MFI2_clicked(); break;
        case 61: _t->on_BTN_COF_MFI3_clicked(); break;
        case 62: _t->on_BTN_COF_E1_2_clicked(); break;
        case 63: _t->on_BTN_COF_E2_2_clicked(); break;
        case 64: _t->on_BTN_COF_LH1_2_clicked(); break;
        case 65: _t->on_BTN_COF_LH2_2_clicked(); break;
        case 66: _t->on_BTN_COF_LH3_2_clicked(); break;
        case 67: _t->on_BTN_COF_LI1_2_clicked(); break;
        case 68: _t->on_BTN_COF_LI2_2_clicked(); break;
        case 69: _t->on_BTN_COF_LI3_2_clicked(); break;
        case 70: _t->on_BTN_COF_PE1_2_clicked(); break;
        case 71: _t->on_BTN_COF_PE2_2_clicked(); break;
        case 72: _t->on_BTN_COF_PLH1_2_clicked(); break;
        case 73: _t->on_BTN_COF_PLH2_2_clicked(); break;
        case 74: _t->on_BTN_COF_PLI1_2_clicked(); break;
        case 75: _t->on_BTN_COF_PLI2_2_clicked(); break;
        case 76: _t->on_BTN_COF_MFH1_2_clicked(); break;
        case 77: _t->on_BTN_COF_MFH2_2_clicked(); break;
        case 78: _t->on_BTN_COF_MFI1_2_clicked(); break;
        case 79: _t->on_BTN_COF_MFI2_2_clicked(); break;
        case 80: _t->on_BTN_COF_MFI3_2_clicked(); break;
        case 81: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 82: _t->on_BTN_SODA_SODA_clicked(); break;
        case 83: _t->on_BTN_SODA_COLD_clicked(); break;
        case 84: _t->on_BTN_SODA_HOT_clicked(); break;
        case 85: _t->on_BTN_SYRUP_1_clicked(); break;
        case 86: _t->on_BTN_SYRUP_2_clicked(); break;
        case 87: _t->on_BTN_SYRUP_3_clicked(); break;
        case 88: _t->on_BTN_SYRUP_4_clicked(); break;
        case 89: _t->on_BTN_SYRUP_5_clicked(); break;
        case 90: _t->on_BTN_SYRUP_6_clicked(); break;
        case 91: _t->on_BTN_SYRUP_7_clicked(); break;
        case 92: _t->on_BTN_SYRUP_8_clicked(); break;
        case 93: _t->on_BTN_SYRUP_9_clicked(); break;
        case 94: _t->on_BTN_SYRUP_10_clicked(); break;
        case 95: _t->on_BTN_SYRUP_11_clicked(); break;
        case 96: _t->on_BTN_SYRUP_12_clicked(); break;
        case 97: _t->on_BTN_SYRUP_13_clicked(); break;
        case 98: _t->on_BTN_SYRUP_14_clicked(); break;
        case 99: _t->on_BTN_SYRUP_15_clicked(); break;
        case 100: _t->on_BTN_SYRUP_16_clicked(); break;
        case 101: _t->on_BTN_SYRUP_17_clicked(); break;
        case 102: _t->on_BTN_SYRUP_18_clicked(); break;
        case 103: _t->on_BTN_SYRUP_19_clicked(); break;
        case 104: _t->on_BTN_SYRUP_20_clicked(); break;
        case 105: _t->on_BTN_SYRUP_21_clicked(); break;
        case 106: _t->on_BTN_SYRUP_22_clicked(); break;
        case 107: _t->on_BTN_SYRUP_23_clicked(); break;
        case 108: _t->on_BTN_SYRUP_24_clicked(); break;
        case 109: _t->on_tabWidget_2_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 110: _t->on_BTN_SODA_SODA_2_clicked(); break;
        case 111: _t->on_BTN_SODA_COLD_2_clicked(); break;
        case 112: _t->on_BTN_SODA_HOT_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DialogRecipe::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogRecipe::cancel)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DialogRecipe::*)(ST_RECIPE_STEP );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogRecipe::add_ingredient)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DialogRecipe::*)(ST_MENU_INFO );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogRecipe::add_menu)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DialogRecipe::*)(int , ST_MENU_INFO );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogRecipe::edit_menu)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DialogRecipe::*)(int , ST_RECIPE_STEP );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogRecipe::edit_ingredient)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DialogRecipe::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DialogRecipe.data,
    qt_meta_data_DialogRecipe,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogRecipe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogRecipe::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogRecipe.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogRecipe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 113)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 113;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 113)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 113;
    }
    return _id;
}

// SIGNAL 0
void DialogRecipe::cancel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DialogRecipe::add_ingredient(ST_RECIPE_STEP _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DialogRecipe::add_menu(ST_MENU_INFO _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DialogRecipe::edit_menu(int _t1, ST_MENU_INFO _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DialogRecipe::edit_ingredient(int _t1, ST_RECIPE_STEP _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
