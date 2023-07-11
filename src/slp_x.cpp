#include <time.h>

#include <rbgo-time.h>

namespace rbgo {

#if RBGOTIME64 /////////////////////////////////////////////////////////////////

void slp_ns_f64(Tf64 s){

	timespec ts;
	ts.tv_sec = (Tu32)s;
	ts.tv_nsec = (Tu32)((s - ts.tv_sec) * 1000000000);
	nanosleep(&ts, 0);
}

#endif /////////////////////////////////////////////////////////////////////////

#if RBGOTIME32 /////////////////////////////////////////////////////////////////

void slp_ns_u32(Tu32 s, Tu32 ns){

	timespec ts = { s, ns };
	nanosleep(&ts, 0);
}

void slp_us_f32(Tf32 s){

	timespec ts;
	ts.tv_sec = (Tu32)s;
	ts.tv_nsec = (Tu32)((s - ts.tv_sec) * 1000000000);
	nanosleep(&ts, 0);
}

#endif /////////////////////////////////////////////////////////////////////////

}//ns
