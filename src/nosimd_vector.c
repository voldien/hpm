#include"hpmvector.h"
#include<math.h>

HPM_IMP( float, hpm_vec4_dotf, const hpmvec4f* larg, const hpmvec4f* rarg){
	return (*larg)[0] * (*rarg)[0] + (*larg)[1] * (*rarg)[1] + (*larg)[2] * (*rarg)[2] + (*larg)[3] * (*rarg)[3];
}
HPM_IMP( double, hpm_vec4_dotd, const hpmvec4d* larg, const hpmvec4d* rarg){
	return (*larg)[0] * (*rarg)[0] + (*larg)[1] * (*rarg)[1] + (*larg)[2] * (*rarg)[2] + (*larg)[3] * (*rarg)[3];
}


HPM_IMP( float, hpm_vec4_lengthf, const hpmvec4f* arg){
	return sqrtf( (*arg)[0] * (*arg)[0] + (*arg)[1] * (*arg)[1] + (*arg)[2] * (*arg)[2] + (*arg)[3] * (*arg)[3] );
}
HPM_IMP( double, hpm_vec4_lengthd, const hpmvec4d* arg){
	return sqrt( (*arg)[0] * (*arg)[0] + (*arg)[1] * (*arg)[1] + (*arg)[2] * (*arg)[2] + (*arg)[3] * (*arg)[3] );
}

HPM_IMP( float, hpm_vec4_lengthsquref, const hpmvec4f* arg){
	return (*arg)[0] * (*arg)[0] + (*arg)[1] * (*arg)[1] + (*arg)[2] * (*arg)[2] + (*arg)[3] * (*arg)[3] ;
}
HPM_IMP( double, hpm_vec4_lengthsqured, const hpmvec4d* arg){
	return (*arg)[0] * (*arg)[0] + (*arg)[1] * (*arg)[1] + (*arg)[2] * (*arg)[2] + (*arg)[3] * (*arg)[3] ;
}
