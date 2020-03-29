/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/04
 */

/* ===== Includes ===== */
#include <stdio.h>
#include <string.h>
#include <gb/gb.h>

#include "Splash.h"

/* ===== MAIN ===== */

int main()
{
    Splash();

    printf("Done");

    while (1)
    {
        /* Do nothing */
        delay(1000);
    }

    return 0;
}
