#include <picostd.h>

void *memcpy(void *restrict s1, const void *restrict s2, size_t n)
{
    char *c1 = (char *)s1;
    const char *c2 = (const char *)s2;
    for (size_t i = 0; i < n; ++i)
        c1[i] = c2[i];
    return s1;
}

void *memset(void *s, int c, size_t n)
{
    unsigned char *p = s;
    while (n--)
        *p++ = (unsigned char)c;
    return s;
}

int strcmp(const char *p1, const char *p2)
{
    const unsigned char *s1 = (const unsigned char *)p1;
    const unsigned char *s2 = (const unsigned char *)p2;
    unsigned char c1, c2;

    do
    {
        c1 = (unsigned char)*s1++;
        c2 = (unsigned char)*s2++;
        if (c1 == '\0')
            return c1 - c2;
    } while (c1 == c2);

    return c1 - c2;
}