/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/04
 */

/* ===== Includes ===== */
#include <stdio.h>
#include <gb/gb.h>

/* ===== Functions ===== */

void PrintHex16(const char* tag, const UINT16 number)
{
    UINT8 b0 = 0;
    UINT8 b1 = 0;
    UINT8 b2 = 0;
    UINT8 b3 = 0;

    b0 = (UINT8)(number & 0x000f);
    b1 = (UINT8)(number & 0x00f0);
    b1 = b1 >> 4;
    b2 = (UINT8)((number & 0x0f00) >> 8);
    b3 = (UINT8)(number >> 12);

    b0 += 48;
    b1 += 48;
    b2 += 48;
    b3 += 48;

    if (b0 > 0x39) b0 += 7;
    if (b1 > 0x39) b1 += 7;
    if (b2 > 0x39) b2 += 7;
    if (b3 > 0x39) b3 += 7;

    printf("%s: 0x%c%c%c%c\n", tag, b3, b2, b1, b0);
}
