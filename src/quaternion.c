#include"hpmquaternion.h"


#define QuaternionYaw(lf_quad)  (float)atan2f(2.0f * (lf_quad[QUAD_W] * lf_quad[QUAD_X] + lf_quad[QUAD_Y] * lf_quad[QUAD_W]),( 1.0f - ( 2.0f * (lf_quad[QUAD_X] * lf_quad[QUAD_X] + lf_quad[QUAD_Y] * lf_quad[QUAD_Y]))))
#define QuaternionPitch(lf_quad) (float)asinf(-2.0f * (lf_quad[QUAD_Z] * lf_quad[QUAD_Y] + lf_quad[QUAD_W] * lf_quad[QUAD_X]))
#define QuaternionRoll(lf_quad) (float)atan2f(2.0f * (lf_quad[QUAD_W] * lf_quad[QUAD_Z] + lf_quad[QUAD_X] * lf_quad[QUAD_Y]), 1.0f - (2.0f * (lf_quad[QUAD_Y] * lf_quad[QUAD_Y] + lf_quad[QUAD_Z] * lf_quad[QUAD_Z])))

