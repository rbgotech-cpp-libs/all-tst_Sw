#pragma once
#include <rbgo-types.h>

#define RBGOTIME64	(!!((RBGOTYPEDEFS & 0x4000) && (RBGOTYPEDEFS & 0x0010)))//Tf64 Tu64
#define RBGOTIME32	(!!((RBGOTYPEDEFS & 0x8000) && (RBGOTYPEDEFS & 0x0004)))//Tf32 Tu32


namespace rbgo {

#if RBGOTIME64 /////////////////////////////////////////////////////////////////

//SLEEP 64
void slp_ns_f64(Tf64 s);

//TIME STAMP COUNTERS 64
//11 digits seconds
//9 digits nano seconds 0...999999999
Tu64 tsc_ns_u64();
//same but expressed in float64; also Tu64 to Tf64 converter.
Tf64 tsc_ns_f64(Tu64 *cnv=0);

//Stopwatch with nano precision.
class Sw64 {
	Tu64 ns=0;
public:
	void start();
	Tf64 stop();
	void stopb(char* buf, const char *pfx="", const char *sfx="");
	void stopp(const char *pfx="", const char *sfx="");
};

#endif /////////////////////////////////////////////////////////////////////////

#if RBGOTIME32 /////////////////////////////////////////////////////////////////

//SLEEP 32
//nano; separated seconds and nanoseconds input
void slp_ns_u32(Tu32 s, Tu32 ns);
//micro; expressed in float
void slp_us_f32(Tf32 s);

//TIME STAMP COUNTERS 32
//1 digit seconds 0...4;
//9 digits nano seconds 0...999999999;
Tu32 tsc_ns_u32();//excellent for rseed.
//4 digits seconds 0...4294;
//6 digits micro seconds 0...999999;
Tu32 tsc_us_u32();
//same but expressed in float32; also Tu32 to Tf32 converter.
Tf32 tsc_us_f32(Tu32 *cnv=0);


//Stopwatch with micro precision.
class Sw32 {
	Tu32 us=0;
public:
	void start();
	Tf32 stop();
	void stopb(char* buf, const char *pfx="", const char *sfx="");
	void stopp(const char *pfx="", const char *sfx="");
};

#endif /////////////////////////////////////////////////////////////////////////

}//ns
