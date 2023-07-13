#include <time.h>

#include <rbgo-time.h>

namespace rbgo {

#if RTD_Ti32
Tu32 tsc_us_u32(){

	timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	return ((ts.tv_sec * 1000000) + (ts.tv_nsec / 1000)) & 0xFFFFFFFF;
}

Tu32 tsc_ns_u32(){

	timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	return ((ts.tv_sec * 1000000000) + ts.tv_nsec) & 0xFFFFFFFF;
}
#endif

#if RTD_Ti32 && RTD_Tf32
Tf32 tsc_us_f32(Tu32 *cnv){

	return ((cnv) ? *cnv : tsc_us_u32()) * 0.000001;
}
#endif

#if RTD_Ti64
Tu64 tsc_ns_u64(){

	timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	return (ts.tv_sec * 1000000000) + ts.tv_nsec;
}
#endif

#if RTD_Ti64 && RTD_Tf64
Tf64 tsc_ns_f64(Tu64 *cnv){

	return ((cnv) ? *cnv : tsc_ns_u64()) * 0.000000001;
}
#endif

}//ns
