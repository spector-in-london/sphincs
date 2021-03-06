/*
Optimized Implementations for Haraka256 and Haraka512
*/
#ifndef HARAKA_H_
#define HARAKA_H_

#include "immintrin.h"

#define NUMROUNDS 5

#define u64 unsigned long
#define u128 __m128i

u128 rc[40];

#define LOAD(src) _mm_load_si128((u128 *)(src))
#define STORE(dest,src) _mm_storeu_si128((u128 *)(dest),src)

#define AES2(s0, s1, rci) \
  s0 = _mm_aesenc_si128(s0, rc[rci]); \
  s1 = _mm_aesenc_si128(s1, rc[rci + 1]); \
  s0 = _mm_aesenc_si128(s0, rc[rci + 2]); \
  s1 = _mm_aesenc_si128(s1, rc[rci + 3]);

#define AES2_4x(s0, s1, s2, s3, rci) \
  s0[0] = _mm_aesenc_si128(s0[0], rc[rci]); \
  s1[0] = _mm_aesenc_si128(s1[0], rc[rci]); \
  s2[0] = _mm_aesenc_si128(s2[0], rc[rci]); \
  s3[0] = _mm_aesenc_si128(s3[0], rc[rci]); \
  s0[1] = _mm_aesenc_si128(s0[1], rc[rci + 1]); \
  s1[1] = _mm_aesenc_si128(s1[1], rc[rci + 1]); \
  s2[1] = _mm_aesenc_si128(s2[1], rc[rci + 1]); \
  s3[1] = _mm_aesenc_si128(s3[1], rc[rci + 1]); \
  s0[0] = _mm_aesenc_si128(s0[0], rc[rci + 2]); \
  s1[0] = _mm_aesenc_si128(s1[0], rc[rci + 2]); \
  s2[0] = _mm_aesenc_si128(s2[0], rc[rci + 2]); \
  s3[0] = _mm_aesenc_si128(s3[0], rc[rci + 2]); \
  s0[1] = _mm_aesenc_si128(s0[1], rc[rci + 3]); \
  s1[1] = _mm_aesenc_si128(s1[1], rc[rci + 3]); \
  s2[1] = _mm_aesenc_si128(s2[1], rc[rci + 3]); \
  s3[1] = _mm_aesenc_si128(s3[1], rc[rci + 3]);

#define AES2_8x(s0, s1, s2, s3, s4, s5, s6, s7, rci) \
  s0[0] = _mm_aesenc_si128(s0[0], rc[rci]); \
  s1[0] = _mm_aesenc_si128(s1[0], rc[rci]); \
  s2[0] = _mm_aesenc_si128(s2[0], rc[rci]); \
  s3[0] = _mm_aesenc_si128(s3[0], rc[rci]); \
  s4[0] = _mm_aesenc_si128(s4[0], rc[rci]); \
  s5[0] = _mm_aesenc_si128(s5[0], rc[rci]); \
  s6[0] = _mm_aesenc_si128(s6[0], rc[rci]); \
  s7[0] = _mm_aesenc_si128(s7[0], rc[rci]); \
  s0[1] = _mm_aesenc_si128(s0[1], rc[rci + 1]); \
  s1[1] = _mm_aesenc_si128(s1[1], rc[rci + 1]); \
  s2[1] = _mm_aesenc_si128(s2[1], rc[rci + 1]); \
  s3[1] = _mm_aesenc_si128(s3[1], rc[rci + 1]); \
  s4[1] = _mm_aesenc_si128(s4[1], rc[rci + 1]); \
  s5[1] = _mm_aesenc_si128(s5[1], rc[rci + 1]); \
  s6[1] = _mm_aesenc_si128(s6[1], rc[rci + 1]); \
  s7[1] = _mm_aesenc_si128(s7[1], rc[rci + 1]); \
  s0[0] = _mm_aesenc_si128(s0[0], rc[rci + 2]); \
  s1[0] = _mm_aesenc_si128(s1[0], rc[rci + 2]); \
  s2[0] = _mm_aesenc_si128(s2[0], rc[rci + 2]); \
  s3[0] = _mm_aesenc_si128(s3[0], rc[rci + 2]); \
  s4[0] = _mm_aesenc_si128(s4[0], rc[rci + 2]); \
  s5[0] = _mm_aesenc_si128(s5[0], rc[rci + 2]); \
  s6[0] = _mm_aesenc_si128(s6[0], rc[rci + 2]); \
  s7[0] = _mm_aesenc_si128(s7[0], rc[rci + 2]); \
  s0[1] = _mm_aesenc_si128(s0[1], rc[rci + 3]); \
  s1[1] = _mm_aesenc_si128(s1[1], rc[rci + 3]); \
  s2[1] = _mm_aesenc_si128(s2[1], rc[rci + 3]); \
  s3[1] = _mm_aesenc_si128(s3[1], rc[rci + 3]); \
  s4[1] = _mm_aesenc_si128(s4[1], rc[rci + 3]); \
  s5[1] = _mm_aesenc_si128(s5[1], rc[rci + 3]); \
  s6[1] = _mm_aesenc_si128(s6[1], rc[rci + 3]); \
  s7[1] = _mm_aesenc_si128(s7[1], rc[rci + 3]);

#define AES4(s0, s1, s2, s3, rci) \
  s0 = _mm_aesenc_si128(s0, rc[rci]); \
  s1 = _mm_aesenc_si128(s1, rc[rci + 1]); \
  s2 = _mm_aesenc_si128(s2, rc[rci + 2]); \
  s3 = _mm_aesenc_si128(s3, rc[rci + 3]); \
  s0 = _mm_aesenc_si128(s0, rc[rci + 4]); \
  s1 = _mm_aesenc_si128(s1, rc[rci + 5]); \
  s2 = _mm_aesenc_si128(s2, rc[rci + 6]); \
  s3 = _mm_aesenc_si128(s3, rc[rci + 7]); \

#define AES4_4x(s0, s1, s2, s3, rci) \
  AES4(s0[0], s0[1], s0[2], s0[3], rci); \
  AES4(s1[0], s1[1], s1[2], s1[3], rci); \
  AES4(s2[0], s2[1], s2[2], s2[3], rci); \
  AES4(s3[0], s3[1], s3[2], s3[3], rci);

#define AES4_8x(s0, s1, s2, s3, s4, s5, s6, s7, rci) \
  AES4_4x(s0, s1, s2, s3, rci); \
  AES4_4x(s4, s5, s6, s7, rci);

#define MIX2(s0, s1) \
  tmp = _mm_unpacklo_epi32(s0, s1); \
  s1 = _mm_unpackhi_epi32(s0, s1); \
  s0 = tmp;

#define MIX4(s0, s1, s2, s3) \
  tmp  = _mm_unpacklo_epi32(s0, s1); \
  s0 = _mm_unpackhi_epi32(s0, s1); \
  s1 = _mm_unpacklo_epi32(s2, s3); \
  s2 = _mm_unpackhi_epi32(s2, s3); \
  s3 = _mm_unpacklo_epi32(s0, s2); \
  s0 = _mm_unpackhi_epi32(s0, s2); \
  s2 = _mm_unpackhi_epi32(s1, tmp); \
  s1 = _mm_unpacklo_epi32(s1, tmp);

#define TRUNCSTORE(out, s0, s1, s2, s3) \
  *(u64*)(out) = (u64*)(s0)[1]; \
  *(u64*)(out + 8) = (u64*)(s1)[1]; \
  *(u64*)(out + 16) = (u64*)(s2)[0]; \
  *(u64*)(out + 24) = (u64*)(s3)[0];

void load_constants();
void test_implementations();

void haraka_f(unsigned char *out, const unsigned char *in);
void haraka_f_4x(unsigned char *out, const unsigned char *in);
void haraka_f_8x(unsigned char *out, const unsigned char *in);

void haraka_h(unsigned char *out, const unsigned char *in);
void haraka_h_4x(unsigned char *out, const unsigned char *in);
void haraka_h_8x(unsigned char *out, const unsigned char *in);


#endif
