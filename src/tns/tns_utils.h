//  SPDX-Creator-Person: Remo Dentato (rdentato@gmail.com)
//  SPDX-License-Identifier: MIT


// Macro to handle functions with variable number of arguments
#define TNS_argcnt(x1,x2,x3,x4,x5,x6,x7,x8,xN, ...) xN
#define TNS_argn(...)       TNS_argcnt(__VA_ARGS__,8,7,6,5,4,3,2,1,0)
#define TNS_argjoin(x,y)    x ## y
#define TNS_argcat(x,y)     TNS_argjoin(x,y)
#define TNS_varargs(f,...)  TNS_argcat(f, TNS_argn(__VA_ARGS__))(__VA_ARGS__)

// Mini dbg helper in case the full dbg.h is not available.
#ifndef DBG_VERSION
#ifdef DEBUG
  #define dbginf(...) (fprintf(stderr,"INFO: " __VA_ARGS__), fprintf(stderr," :\xF%s:%d\n",__FILE__,__LINE__))
  #define dbgchk(e,...) \
                    do { \
                      int dbg_err =! (e); \
                      fprintf(stderr,"%s: %s :\xF%s:%d\n",(dbg_err?"FAIL":"PASS"),#e,__FILE__,__LINE__); \
                      if (dbg_err) { fprintf(stderr,"    : " __VA_ARGS__); fputc('\n',stderr); } \
                      errno = dbg_err; \
                    } while(0)
  #define dbgmst(e, ...) do { dbgchk(e, __VA_ARGS__); if (errno) abort(); } while(0)
#else
  #define dbginf(...)
  #define dbgchk(...)
  #define dbgmst(...)
#endif

#define _dbginf(...)
#define _dbgchk(...)
#define _dbgmst(...)
#endif

