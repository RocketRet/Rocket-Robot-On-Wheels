#include <include_asm.h>
#include <ultra64.h>

unsigned long long __udivmoddi4(unsigned long long, unsigned long long, unsigned long long *);

unsigned long long __udivdi3(unsigned long long a, unsigned long long b)
{
    return __udivmoddi4(a, b, NULL);
}
