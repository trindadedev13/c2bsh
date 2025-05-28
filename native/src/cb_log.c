/**
 * Licensed under Apache 2.0.
 * Developed by Aquiles Trindade (trindadedev).
 * Updated in 2025-04-10
 */

#include "cb_log.h"

#include <stdarg.h>

#include "cb_string.h"

#ifdef C2BSH_ANDROID

#include "android/android_log.h"

void log_debug(const cb_string format, ...) {
  va_list args;
  va_start(args, format);
  __android_log_vprint(ANDROID_LOG_DEBUG, "APP", format, args);
  va_end(args);
}

void log_error(const cb_string format, ...) {
  va_list args;
  va_start(args, format);
  __android_log_vprint(ANDROID_LOG_ERROR, "APP", format, args);
  va_end(args);
}

void log_warning(const cb_string format, ...) {
  va_list args;
  va_start(args, format);
  __android_log_vprint(ANDROID_LOG_WARN, "APP", format, args);
  va_end(args);
}

#else

#include <stdio.h>

void log_debug(const cb_string format, ...) {
  va_list args;
  va_start(args, format);
  printf("[DEBUG] ");
  vprintf(format, args);
  printf("\n");
  va_end(args);
}

void log_error(const cb_string format, ...) {
  va_list args;
  va_start(args, format);
  fprintf(stderr, "[ERROR] ");
  vfprintf(stderr, format, args);
  fprintf(stderr, "\n");
  va_end(args);
}

void log_warning(const cb_string format, ...) {
  va_list args;
  va_start(args, format);
  printf("[WARNING] ");
  vprintf(format, args);
  printf("\n");
  va_end(args);
}

#endif