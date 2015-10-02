/*
  COPY PASTED CODE FROM https://cmake.org/cmake-tutorial/
  For tutorial usage
*/
  
// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float mysqrt(const float x)  
{
  float result;
  #if defined (HAVE_LOG) && defined (HAVE_EXP)
  result = exp(log(x)*0.5);
  return result;
  #else
  result = sqrt(x);
  return result;
  #endif
  // union
  // {
  //   int i;
  //   float x;
  // } u;
  // u.x = x;
  // u.i = (1<<29) + (u.i >> 1) - (1<<22); 
  
  // // Two Babylonian Steps (simplified from:)
  // // u.x = 0.5f * (u.x + x/u.x);
  // // u.x = 0.5f * (u.x + x/u.x);
  // u.x =       u.x + x/u.x;
  // u.x = 0.25f*u.x + x/u.x;

  // return u.x;
}  


