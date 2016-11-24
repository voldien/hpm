#include"hpmvector.h"
#include<math.h>

HPM_IMP( float, hpm_vec4_dotfv, const hpmvec4f* larg, const hpmvec4f* rarg){
	return (*larg)[0] * (*rarg)[0] + (*larg)[1] * (*rarg)[1] + (*larg)[2] * (*rarg)[2] + (*larg)[3] * (*rarg)[3];
}
HPM_IMP( double, hpm_vec4_dotdv, const hpmvec4d* larg, const hpmvec4d* rarg){
	return (*larg)[0] * (*rarg)[0] + (*larg)[1] * (*rarg)[1] + (*larg)[2] * (*rarg)[2] + (*larg)[3] * (*rarg)[3];
}


HPM_IMP( float, hpm_vec4_lengthfv, const hpmvec4f* arg){
	return sqrtf( (*arg)[0] * (*arg)[0] + (*arg)[1] * (*arg)[1] + (*arg)[2] * (*arg)[2] + (*arg)[3] * (*arg)[3] );
}
HPM_IMP( double, hpm_vec4_lengthdv, const hpmvec4d* arg){
	return sqrt( (*arg)[0] * (*arg)[0] + (*arg)[1] * (*arg)[1] + (*arg)[2] * (*arg)[2] + (*arg)[3] * (*arg)[3] );
}

HPM_IMP( float, hpm_vec4_lengthsqurefv, const hpmvec4f* arg){
	return (*arg)[0] * (*arg)[0] + (*arg)[1] * (*arg)[1] + (*arg)[2] * (*arg)[2] + (*arg)[3] * (*arg)[3] ;
}
HPM_IMP( double, hpm_vec4_lengthsquredv, const hpmvec4d* arg){
	return (*arg)[0] * (*arg)[0] + (*arg)[1] * (*arg)[1] + (*arg)[2] * (*arg)[2] + (*arg)[3] * (*arg)[3] ;
}
