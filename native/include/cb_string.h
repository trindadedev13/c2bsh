/**
 * Licensed under Apache 2.0.
 * Developed by Aquiles Trindade (trindadedev).
 * in 2025-04-08
 */

#ifndef CB_STRING_H
#define CB_STRING_H

#include "cb_bool.h"

typedef char* cb_string;

cb_bool str_starts_with(cb_string str, cb_string prefix);

// Replaces an text in String (cb_string) by moving memory
void str_replace(cb_string str,
                 const cb_string target,
                 const cb_string replacement);

cb_string str_trim(cb_string str);

#endif