#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_147", func_80046500);

// Converts a number between 0 and 999 to a string
void func_80046578(char *digitsOut, s32 value) {
    s32 divisor = 100;
    char *curDigit = digitsOut;

    // Decrease the divisor until it's no bigger than the input value
    while ((value / divisor) == 0) {
        divisor /= 10;
        if (divisor <= 1) break;
    }

    // Repeatedly divide the input until we get to the ones place
    do {
        // Divide the value by the current divisor and offset by ascii '0' to get the digit's character
        *curDigit = (value / divisor) + '0';
        // Remove the highest digit by taking the remainder of the previous division
        value %= divisor;
        // Move the divisor down by 1 digit
        divisor /= 10;
        // Increment the output position
        curDigit++;
    } while (divisor != 0);

    // Null-terminate the string
    *curDigit = '\0';
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_147", func_8004667C);
