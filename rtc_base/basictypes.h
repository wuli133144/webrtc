/*
 *  Copyright 2004 The WebRTC Project Authors. All rights reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef RTC_BASE_BASICTYPES_H_
#define RTC_BASE_BASICTYPES_H_

// Detect compiler is for x86 or x64.
#if defined(__x86_64__) || defined(_M_X64) || \
    defined(__i386__) || defined(_M_IX86)
#define CPU_X86 1
#endif

// Detect compiler is for arm.
#if defined(__arm__) || defined(_M_ARM)
#define CPU_ARM 1
#endif

#if defined(CPU_X86) && defined(CPU_ARM)
#error CPU_X86 and CPU_ARM both defined.
#endif

#if !defined(RTC_ARCH_CPU_BIG_ENDIAN) && !defined(RTC_ARCH_CPU_LITTLE_ENDIAN)
// x86, arm or GCC provided __BYTE_ORDER__ macros
#if defined(CPU_X86) || defined(CPU_ARM) ||                             \
  (defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
#define RTC_ARCH_CPU_LITTLE_ENDIAN
#elif defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define RTC_ARCH_CPU_BIG_ENDIAN
#else
#error RTC_ARCH_CPU_BIG_ENDIAN or RTC_ARCH_CPU_LITTLE_ENDIAN should be defined.
#endif
#endif

#if defined(RTC_ARCH_CPU_BIG_ENDIAN) && defined(RTC_ARCH_CPU_LITTLE_ENDIAN)
#error RTC_ARCH_CPU_BIG_ENDIAN and RTC_ARCH_CPU_LITTLE_ENDIAN both defined.
#endif

#endif  // RTC_BASE_BASICTYPES_H_
