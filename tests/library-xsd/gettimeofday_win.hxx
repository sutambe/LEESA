#ifndef GET_TIME_OF_DAY_WIN_H
#define GET_TIME_OF_DAY_WIN_H

#include <time.h>
#include <windows.h>

#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
  #define DELTA_EPOCH_IN_MICROSECS  11644473600000000Ui64
#else
  #define DELTA_EPOCH_IN_MICROSECS  11644473600000000ULL
#endif

struct timezone 
{
  int  tz_minuteswest; /* minutes W of Greenwich */
  int  tz_dsttime;     /* type of dst correction */
};
 
typedef unsigned long suseconds_t;

int gettimeofday(struct timeval *tv, struct timezone *tz);

#endif // GET_TIME_OF_DAY_WIN_H
