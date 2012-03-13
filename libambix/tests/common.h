#ifndef TESTS_COMMON_H
#define TESTS_COMMON_H

#include <ambix/ambix.h>

#include <stdlib.h>
static inline void pass(void) {exit(0); }
static inline void fail(void) {exit(1); }
static inline void skip(void) {exit(77); }

#include <stdio.h>
#include <stdarg.h>
static inline void pass_if (int test, int line, const char *format, ...)
{
  if (test) {
    va_list argptr ;
    printf("@%d: ", line);
    va_start (argptr, format) ;
    vprintf (format, argptr) ;
    va_end (argptr) ;
    printf("\n");
    pass();
  } ;
} /* pass_if */
static inline void skip_if (int test, int line, const char *format, ...)
{
  if (test) {
    va_list argptr ;
    printf("@%d: ", line);
    va_start (argptr, format) ;
    vprintf (format, argptr) ;
    va_end (argptr) ;
    printf("\n");
    skip();
  } ;
} /* skip_if */
static inline void fail_if (int test, int line, const char *format, ...)
{
  if (test) {
    va_list argptr ;
    printf("@%d: ", line);
    va_start (argptr, format) ;
    vprintf (format, argptr) ;
    va_end (argptr) ;
    printf("\n");
    fail();
  } ;
} /* fail_if */

void matrix_print(const ambixmatrix_t*mtx);
float32_t*data_sine(uint32_t frames, float32_t periods);

#endif /* TESTS_COMMON_H */

