#ifndef __ASSERT_H__
#define __ASSERT_H__

extern void __assert(const char *, const char *, int);
#define assert(EX)  ((EX)?((void)0):__assert("EX", __FILE__, __LINE__))
#define assert_filename(EX, filename)  ((EX)?((void)0):__assert("EX", filename, __LINE__))

#endif /* !__ASSERT_H__ */
