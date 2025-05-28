/**
 * Licensed under Apache 2.0.
 * Developed by Aquiles Trindade (trindadedev).
 * Updated in 2025-04-10
 */

#ifndef CB_LOG_H
#define CB_LOG_H

#include <stdarg.h>

#include "cb_string.h"

void log_debug(const cb_string format, ...);

void log_error(const cb_string format, ...);

void log_warning(const cb_string format, ...);

#endif