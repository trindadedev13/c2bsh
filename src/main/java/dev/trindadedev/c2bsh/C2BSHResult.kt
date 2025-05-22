package dev.trindadedev.c2bsh

/*
 * Copyright 2025 Aquiles Trindade (trindadedev).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

class C2BSHResult(private var nativePtr: Long) : AutoCloseable {

  val code: String
    get() = checkValid { C2BSH.getCode(nativePtr) }

  val includes: Array<String>
    get() = checkValid { C2BSH.getIncludes(nativePtr) }

  override fun close() {
    if (nativePtr != 0L) {
      C2BSH.close(nativePtr)
      nativePtr = 0L
    }
  }

  private fun <T> checkValid(block: () -> T): T {
    if (nativePtr == 0L) throw IllegalStateException("C2BSHResult has been closed or is invalid.")
    return block()
  }
}
