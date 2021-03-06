# Performance #
The following is a list of tables of the performance result from using the 'hpmassert --performance' command.

## Intel I7 2600k ##

|         Function             | NOSIMD |   SSE  |  SSE2  |  SSE3  | SSSE3  | SSE41  | SSE42  |   AVX  |
| :---                         |     :---:  |      ---: |      ---: |      ---: |      ---: |      ---: |      ---: |      ---: |
| hpm_mat4x4_copyfv            |      1.000 |     1.375 |     1.375 |     1.375 |     1.375 |     1.375 |     1.376 |     1.032 |
| hpm_mat4x4_multiply_mat4x4fv |      1.000 |     2.949 |     2.936 |     2.925 |     2.949 |     2.899 |     2.939 |     3.476 |
| hpm_mat4x4_multiply_mat1x4fv |      1.000 |     2.352 |     2.352 |     2.352 |     2.352 |     2.353 |     2.354 |     2.537 |
| hpm_mat4x4_identityfv        |      1.143 |     1.143 |     1.143 |     1.143 |     1.143 |     1.143 |     1.143 |     1.000 |
| hpm_mat4x4_transposefv       |      1.111 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.213 |
| hpm_mat4x4_determinantfv     |      1.111 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.212 |
| hpm_mat4x4_inversefv         |      1.000 |     1.035 |     1.035 |     1.035 |     1.035 |     1.035 |     1.028 |     1.128 |
| hpm_mat4x4_decomposefv       |      1.008 |     1.008 |     1.008 |     1.009 |     1.008 |     1.008 |     1.008 |     1.000 |
| hpm_mat4x4_translationfv     |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |
| hpm_mat4x4_scalefv           |      1.125 |     1.125 |     1.124 |     1.125 |     1.125 |     1.000 |     1.000 |     1.000 |
| hpm_mat4x4_rotationfv        |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.013 |     1.013 |     1.231 |
| hpm_mat4x4_rotationXf        |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.033 |     1.033 |     1.034 |
| hpm_mat4x4_rotationYf        |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.064 |
| hpm_mat4x4_rotationZf        |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.051 |
| hpm_mat4x4_rotationQf        |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.089 |
| hpm_mat4x4_projfv            |      1.004 |     1.004 |     1.004 |     1.004 |     1.004 |     1.000 |     1.000 |     1.003 |
| hpm_mat4x4_orthfv            |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.005 |     1.005 |     1.010 |
| hpm_mat4x4_unprojf           |      1.000 |     1.215 |     1.216 |     1.214 |     1.216 |     1.216 |     1.216 |     1.280 |
| hpm_vec4_com_eqfv            |      1.000 |     6.667 |     6.668 |     6.668 |     6.667 |     6.667 |     6.667 |     6.666 |
| hpm_vec4_eqfv                |      1.000 |     3.906 |     3.906 |     3.905 |     3.906 |     3.906 |     3.906 |     4.464 |
| hpm_vec4_com_neqfv           |      1.000 |     2.572 |     2.572 |     2.572 |     2.571 |     2.571 |     2.571 |     2.571 |
| hpm_vec4_neqfv               |      1.445 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.858 |
| hpm_vec4_com_gfv             |      1.000 |     1.833 |     1.831 |     1.833 |     1.833 |     1.833 |     1.833 |     1.833 |
| hpm_vec4_com_lfv             |      1.000 |     1.714 |     1.714 |     1.714 |     1.714 |     1.714 |     1.714 |     1.714 |
| hpm_mat4_eqfv                |      1.000 |     2.402 |     2.408 |     2.403 |     2.405 |     2.408 |     2.408 |     2.408 |
| hpm_mat4_neqfv               |      1.000 |     2.137 |     2.137 |     2.138 |     2.137 |     2.376 |     2.376 |     2.376 |
| hpm_quat_copyfv              |      1.001 |     1.000 |     1.001 |     1.001 |     1.001 |     1.001 |     1.001 |     1.001 |
| hpm_quat_multi_quatfv        |      1.000 |     1.290 |     1.290 |     1.291 |     1.290 |     1.291 |     1.290 |     1.994 |
| hpm_quat_multi_vec3fv        |      1.000 |     1.256 |     1.256 |     1.250 |     1.249 |     1.254 |     1.255 |     1.289 |
| hpm_quat_directionfv         |      1.000 |     1.214 |     1.214 |     1.214 |     1.214 |     1.214 |     1.214 |     1.164 |
| hpm_quat_get_vectorfv        |      1.000 |     1.188 |     1.188 |     1.188 |     1.188 |     1.188 |     1.188 |     1.156 |
| hpm_quat_conjugatefv         |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |
| hpm_quat_inversefv           |      1.000 |     1.002 |     1.002 |     1.002 |     1.002 |     1.002 |     1.002 |     1.018 |
| hpm_quat_dotfv               |      1.424 |     1.429 |     1.429 |     1.429 |     1.429 |     1.000 |     1.000 |     1.000 |
| hpm_quat_identityfv          |      1.001 |     1.001 |     1.001 |     1.001 |     1.001 |     1.001 |     1.000 |     1.001 |
| hpm_quat_axis_anglefv        |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.046 |
| hpm_quat_from_mat4x4fv       |      1.001 |     1.001 |     1.001 |     1.001 |     1.000 |     1.000 |     1.000 |     1.000 |
| hpm_quat_axisf               |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.104 |
| hpm_quat_lerpfv              |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |
| hpm_quat_slerpfv             |      1.054 |     1.138 |     1.138 |     1.143 |     1.143 |     1.045 |     1.045 |     1.000 |
| hpm_quat_pitchfv             |      1.000 |     1.001 |     1.000 |     1.001 |     1.001 |     1.001 |     1.000 |     1.115 |
| hpm_quat_yawfv               |      1.001 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.116 |
| hpm_quat_rollfv              |      1.001 |     1.000 |     1.000 |     1.001 |     1.000 |     1.000 |     1.001 |     1.115 |
| hpm_quat_eularfv             |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.097 |
| hpm_quat_powfv               |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.003 |
| hpm_vec4_maxfv               |      1.000 |     1.251 |     1.251 |     1.251 |     1.251 |     1.251 |     1.251 |     1.251 |
| hpm_vec8_maxfv               |      1.000 |     1.143 |     1.143 |     1.143 |     1.143 |     1.143 |     1.143 |     1.332 |
| hpm_vec4_minfv               |      1.000 |     1.251 |     1.251 |     1.251 |     1.251 |     1.251 |     1.251 |     1.251 |
| hpm_vec8_minfv               |      1.000 |     2.330 |     2.333 |     2.333 |     2.333 |     2.333 |     2.333 |     2.331 |
| hpm_vec4_sqrtfv              |      1.000 |     3.144 |     3.144 |     3.140 |     3.144 |     3.144 |     3.144 |     1.830 |
| hpm_vec8_sqrtfv              |      1.000 |     8.526 |     8.525 |     8.526 |     8.525 |     8.525 |     8.526 |     3.551 |
| hpm_vec4_fast_sqrtfv         |      1.000 |     7.335 |     7.334 |     7.335 |     7.335 |     7.333 |     7.335 |     7.335 |
| hpm_vec8_fast_sqrtfv         |      1.000 |    14.001 |    14.001 |    14.001 |    14.001 |    14.001 |    14.001 |    14.001 |
| hpm_vec4_copyfv              |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |
| hpm_vec4_dotfv               |      1.375 |     1.567 |     1.572 |     1.571 |     1.572 |     1.000 |     1.000 |     1.000 |
| hpm_vec4_lengthfv            |      1.000 |     1.001 |     1.001 |     1.001 |     1.001 |     1.001 |     1.001 |     1.001 |
| hpm_vec4_lengthsqurefv       |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |
| hpm_vec4_normalizefv         |      1.000 |     1.020 |     1.020 |     1.020 |     1.020 |     1.020 |     1.020 |     1.036 |
| hpm_vec4_negatefv            |      1.043 |     1.000 |     1.043 |     1.005 |     1.005 |     1.014 |     1.010 |     1.014 |
| hpm_vec4_lerpfv              |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |
| hpm_vec4_slerpfv             |      1.000 |     1.021 |     1.020 |     1.021 |     1.021 |     1.021 |     1.021 |     1.031 |
| hpm_vec4_max_compfv          |      1.000 |     1.857 |     1.857 |     1.857 |     1.857 |     1.857 |     1.857 |     1.857 |
| hpm_vec4_min_compfv          |      1.000 |     2.295 |     2.294 |     2.295 |     2.295 |     2.295 |     2.295 |     2.295 |
| hpm_vec3_crossproductfv      |      1.000 |     1.054 |     1.055 |     1.055 |     1.055 |     1.055 |     1.055 |     1.356 |
| hpm_vec3_tripleProductfv     |      1.651 |     1.000 |     1.000 |     1.000 |     1.000 |     1.063 |     1.063 |     1.061 |
| hpm_vec3_dotfv               |      2.746 |     1.000 |     1.000 |     1.000 |     1.000 |     1.081 |     1.081 |     1.081 |
| hpm_vec3_lengthfv            |      3.269 |     1.018 |     1.018 |     1.019 |     1.019 |     1.019 |     1.019 |     1.000 |
| hpm_vec3_lengthsquarefv      |      2.786 |     1.026 |     1.026 |     1.026 |     1.026 |     1.026 |     1.026 |     1.000 |
| hpm_vec3_normalizefv         |      1.226 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.000 |     1.013 |
| hpm_vec3_reflectfv           |      2.738 |     1.000 |     1.000 |     1.000 |     1.000 |     1.048 |     1.048 |     1.179 |
| hpm_vec3_refractfv           |      2.373 |     1.000 |     1.000 |     1.000 |     1.000 |     1.048 |     1.048 |     1.116 |
| hpm_vec3_projfv              |      2.471 |     1.002 |     1.002 |     1.000 |     1.000 |     1.047 |     1.047 |     1.048 |
 


## i7-8750H ##
Using GCC 9.3

|           Function           | NOSIMD |   SSE  |  SSE2 |  SSE3  | SSSE3  | SSE41  | SSE42  |   AVX  |
| :---                         |     :---:  |      ---: |      ---: |      ---: |      ---: |      ---: |      ---: |      ---: |
| hpm_mat4x4_copyfv            |      1.000 |     1.138 |     1.169 |     1.138 |     1.161 |     1.358 |     1.361 |     1.233 |
| hpm_mat4x4_multiply_mat4x4fv |      1.000 |     2.906 |     2.995 |     2.958 |     2.977 |     3.006 |     2.998 |     3.373 |
| hpm_mat4x4_multiply_mat1x4fv |      1.000 |     2.435 |     2.638 |     2.638 |     2.582 |     2.219 |     2.225 |     2.280 |
| hpm_mat4x4_identityfv        |      1.648 |     1.348 |     1.382 |     1.379 |     1.375 |     1.663 |     1.657 |     1.000 |
| hpm_mat4x4_transposefv       |      1.000 |     1.152 |     1.155 |     1.156 |     1.158 |     1.153 |     1.159 |     1.147 |
| hpm_mat4x4_determinantfv     |      1.000 |     1.166 |     1.183 |     1.182 |     1.170 |     1.180 |     1.172 |     1.181 |
| hpm_mat4x4_inversefv         |      1.000 |     1.083 |     1.086 |     1.086 |     1.083 |     1.082 |     1.084 |     1.110 |
| hpm_mat4x4_decomposefv       |      1.000 |     1.012 |     1.008 |     1.013 |     1.010 |     1.011 |     1.006 |     1.005 |
| hpm_mat4x4_translationfv     |      1.005 |     1.004 |     1.043 |     1.016 |     1.043 |     1.043 |     1.041 |     1.000 |
| hpm_mat4x4_scalefv           |      1.023 |     1.002 |     1.028 |     1.011 |     1.029 |     1.025 |     1.023 |     1.000 |
| hpm_mat4x4_rotationfv        |      1.018 |     1.015 |     1.021 |     1.019 |     1.000 |     1.025 |     1.027 |     1.058 |
| hpm_mat4x4_rotationXf        |      1.000 |     1.003 |     1.020 |     1.021 |     1.018 |     1.030 |     1.029 |     1.013 |
| hpm_mat4x4_rotationYf        |      1.000 |     1.004 |     1.011 |     1.019 |     1.005 |     1.031 |     1.032 |     1.006 |
| hpm_mat4x4_rotationZf        |      1.015 |     1.000 |     1.050 |     1.053 |     1.033 |     1.051 |     1.044 |     1.071 |
| hpm_mat4x4_rotationQf        |      1.000 |     1.000 |     1.016 |     1.010 |     1.005 |     1.009 |     1.009 |     1.083 |
| hpm_mat4x4_projfv            |      1.030 |     1.032 |     1.043 |     1.037 |     1.000 |     1.114 |     1.113 |     1.157 |
| hpm_mat4x4_orthfv            |      1.006 |     1.000 |     1.015 |     1.016 |     1.009 |     1.040 |     1.040 |     1.038 |
| hpm_mat4x4_unprojf           |      1.000 |     1.277 |     1.282 |     1.262 |     1.272 |     1.267 |     1.269 |     1.264 |
| hpm_vec4_com_eqfv            |      1.000 |     6.908 |     6.924 |     6.884 |     6.710 |     6.825 |     6.820 |     6.484 |
| hpm_vec4_eqfv                |      1.000 |     4.100 |     4.161 |     4.213 |     4.199 |     4.125 |     4.172 |     3.499 |
| hpm_vec4_com_neqfv           |      1.000 |     2.850 |     2.911 |     2.958 |     2.888 |     2.818 |     2.912 |     2.911 |
| hpm_vec4_neqfv               |      1.727 |     1.003 |     1.000 |     1.018 |     1.002 |     1.026 |     1.024 |     2.443 |
| hpm_vec4_com_gfv             |      1.000 |     2.240 |     2.252 |     2.244 |     2.239 |     2.244 |     2.222 |     2.237 |
| hpm_vec4_com_lfv             |      1.000 |     2.074 |     2.064 |     2.039 |     2.034 |     2.066 |     2.052 |     2.059 |
| hpm_mat4_eqfv                |      1.000 |     2.303 |     2.340 |     2.350 |     2.307 |     2.664 |     2.615 |     2.286 |
| hpm_mat4_neqfv               |      1.000 |     2.224 |     2.279 |     2.288 |     2.293 |     2.626 |     2.625 |     2.606 |
| hpm_quat_copyfv              |      1.025 |     1.029 |     1.025 |     1.015 |     1.023 |     1.025 |     1.000 |     1.025 |
| hpm_quat_multi_quatfv        |      1.000 |     1.863 |     1.911 |     1.904 |     1.903 |     1.894 |     1.827 |     2.153 |
| hpm_quat_multi_vec3fv        |      1.000 |     1.128 |     1.130 |     1.098 |     1.117 |     1.141 |     1.138 |     1.133 |
| hpm_quat_directionfv         |      1.000 |     1.088 |     1.085 |     1.064 |     1.060 |     1.073 |     1.063 |     1.073 |
| hpm_quat_get_vectorfv        |      1.000 |     1.152 |     1.165 |     1.131 |     1.148 |     1.162 |     1.167 |     1.161 |
| hpm_quat_conjugatefv         |      1.008 |     1.000 |     1.023 |     1.021 |     1.023 |     1.016 |     1.016 |     1.015 |
| hpm_quat_inversefv           |      1.010 |     1.056 |     1.057 |     1.006 |     1.000 |     1.007 |     1.007 |     1.007 |
| hpm_quat_dotfv               |      1.141 |     1.164 |     1.199 |     1.439 |     1.429 |     1.028 |     1.028 |     1.000 |
| hpm_quat_identityfv          |      1.026 |     1.011 |     1.012 |     1.015 |     1.005 |     1.006 |     1.008 |     1.000 |
| hpm_quat_axis_anglefv        |      1.000 |     1.025 |     1.023 |     1.019 |     1.018 |     1.022 |     1.023 |     1.027 |
| hpm_quat_from_mat4x4fv       |      1.000 |     1.009 |     1.043 |     1.007 |     1.037 |     1.040 |     1.035 |     1.065 |
| hpm_quat_axisf               |      1.005 |     1.000 |     1.009 |     1.009 |     1.008 |     1.006 |     1.008 |     1.029 |
| hpm_quat_lerpfv              |      1.038 |     1.026 |     1.019 |     1.024 |     1.035 |     1.000 |     1.032 |     1.017 |
| hpm_quat_slerpfv             |      1.024 |     1.048 |     1.049 |     1.125 |     1.118 |     1.039 |     1.061 |     1.000 |
| hpm_quat_pitchfv             |      1.013 |     1.012 |     1.007 |     1.007 |     1.004 |     1.012 |     1.000 |     1.033 |
| hpm_quat_yawfv               |      1.000 |     1.018 |     1.014 |     1.016 |     1.022 |     1.014 |     1.013 |     1.059 |
| hpm_quat_rollfv              |      1.011 |     1.015 |     1.027 |     1.000 |     1.022 |     1.024 |     1.026 |     1.076 |
| hpm_quat_eularfv             |      1.025 |     1.023 |     1.037 |     1.000 |     1.028 |     1.031 |     1.044 |     1.055 |
| hpm_quat_powfv               |      1.019 |     1.007 |     1.004 |     1.005 |     1.000 |     1.010 |     1.007 |     1.003 |
| hpm_vec4_maxfv               |      1.000 |     1.242 |     1.249 |     1.261 |     1.266 |     1.266 |     1.265 |     1.246 |
| hpm_vec8_maxfv               |      1.000 |     1.076 |     1.124 |     1.097 |     1.206 |     1.152 |     1.046 |     1.180 |
| hpm_vec4_minfv               |      1.000 |     1.177 |     1.176 |     1.167 |     1.188 |     1.186 |     1.194 |     1.144 |
| hpm_vec8_minfv               |      1.000 |     2.266 |     2.262 |     2.169 |     2.258 |     1.883 |     1.883 |     2.239 |
| hpm_vec4_sqrtfv              |      1.000 |     7.948 |     7.919 |     7.750 |     7.907 |     7.863 |     7.971 |     7.876 |
| hpm_vec8_sqrtfv              |      1.000 |    19.047 |    19.114 |    18.933 |    19.109 |    18.955 |    19.114 |    15.880 |
| hpm_vec4_fast_sqrtfv         |      1.000 |     9.611 |     9.617 |     9.617 |     9.549 |     9.613 |     9.614 |     9.647 |
| hpm_vec8_fast_sqrtfv         |      1.000 |    18.969 |    19.035 |    19.035 |    18.831 |    18.970 |    18.910 |    18.970 |
| hpm_vec4_copyfv              |      1.015 |     1.006 |     1.005 |     1.003 |     1.003 |     1.000 |     1.003 |     1.000 |
| hpm_vec4_dotfv               |      1.277 |     1.338 |     1.342 |     1.605 |     1.604 |     1.004 |     1.000 |     1.002 |
| hpm_vec4_lengthfv            |      1.000 |     1.145 |     1.144 |     1.100 |     1.101 |     1.105 |     1.097 |     1.084 |
| hpm_vec4_lengthsqurefv       |      1.024 |     1.019 |     1.028 |     1.225 |     1.225 |     1.229 |     1.225 |     1.000 |
| hpm_vec4_normalizefv         |      1.000 |     1.056 |     1.059 |     1.014 |     1.003 |     1.013 |     1.015 |     1.009 |
| hpm_vec4_negatefv            |      1.093 |     1.000 |     1.069 |     1.050 |     1.074 |     1.066 |     1.097 |     1.036 |
| hpm_vec4_lerpfv              |      1.000 |     1.062 |     1.060 |     1.070 |     1.062 |     1.070 |     1.070 |     1.070 |
| hpm_vec4_slerpfv             |      1.000 |     1.074 |     1.077 |     1.044 |     1.045 |     1.035 |     1.038 |     1.034 |
| hpm_vec4_max_compfv          |      1.000 |     2.705 |     2.769 |     2.295 |     2.313 |     2.771 |     2.710 |     2.662 |
| hpm_vec4_min_compfv          |      1.000 |     1.808 |     1.844 |     2.213 |     2.181 |     1.865 |     1.824 |     1.835 |
| hpm_vec3_crossproductfv      |      1.000 |     1.328 |     1.333 |     1.319 |     1.318 |     1.329 |     1.314 |     1.552 |
| hpm_vec3_tripleProductfv     |      1.703 |     1.042 |     1.040 |     1.000 |     1.004 |     1.063 |     1.058 |     1.063 |
| hpm_vec3_dotfv               |      3.234 |     1.072 |     1.068 |     1.014 |     1.000 |     1.099 |     1.094 |     1.097 |
| hpm_vec3_lengthfv            |      3.415 |     1.067 |     1.064 |     1.020 |     1.020 |     1.021 |     1.015 |     1.000 |
| hpm_vec3_lengthsquarefv      |      2.768 |     1.092 |     1.090 |     1.034 |     1.036 |     1.022 |     1.033 |     1.000 |
| hpm_vec3_normalizefv         |      1.279 |     1.037 |     1.040 |     1.004 |     1.003 |     1.000 |     1.005 |     1.004 |
| hpm_vec3_reflectfv           |      2.805 |     1.051 |     1.045 |     1.000 |     1.009 |     1.061 |     1.062 |     1.138 |
| hpm_vec3_refractfv           |      2.775 |     1.036 |     1.059 |     1.000 |     1.012 |     1.074 |     1.062 |     1.141 |
| hpm_vec3_projfv              |      2.730 |     1.060 |     1.069 |     1.000 |     1.026 |     1.078 |     1.078 |     1.079 |


## Intel Atom CPU D525 ##
Using GCC 8.3

|           Function           | NOSIMD  |   SSE  |  SSE2  |  SSE3  | SSSE3  |
| :---                         |     :---:  |      ---: |      ---: |      ---: |      ---: | 
| hpm_mat4x4_copyfv            |      1.000 |     1.002 |     1.000 |     1.000 |     1.000 |
| hpm_mat4x4_multiply_mat4x4fv |      1.000 |     2.210 |     2.207 |     2.206 |     2.206 |
| hpm_mat4x4_multiply_mat1x4fv |      1.000 |     1.897 |     1.895 |     1.895 |     1.895 |
| hpm_mat4x4_identityfv        |      1.000 |     1.001 |     1.000 |     1.000 |     1.000 |
| hpm_mat4x4_transposefv       |      1.000 |     1.231 |     1.230 |     1.229 |     1.229 |
| hpm_mat4x4_determinantfv     |      1.000 |     1.231 |     1.228 |     1.229 |     1.229 |
| hpm_mat4x4_inversefv         |      1.020 |     1.001 |     1.000 |     1.000 |     1.000 |
| hpm_mat4x4_decomposefv       |      1.000 |     1.001 |     1.000 |     1.000 |     1.000 |
| hpm_mat4x4_translationfv     |      1.000 |     1.001 |     1.001 |     1.000 |     1.000 |
| hpm_mat4x4_scalefv           |      1.000 |     1.001 |     1.000 |     1.000 |     1.000 |
| hpm_mat4x4_rotationfv        |      1.000 |     1.002 |     1.001 |     1.001 |     1.001 |
| hpm_mat4x4_rotationXf        |      1.005 |     1.005 |     1.000 |     1.004 |     1.005 |
| hpm_mat4x4_rotationYf        |      1.012 |     1.012 |     1.000 |     1.012 |     1.012 |
| hpm_mat4x4_rotationZf        |      1.010 |     1.011 |     1.000 |     1.010 |     1.010 |
| hpm_mat4x4_rotationQf        |      1.009 |     1.010 |     1.000 |     1.009 |     1.009 |
| hpm_mat4x4_projfv            |      1.008 |     1.007 |     1.000 |     1.008 |     1.008 |
| hpm_mat4x4_orthfv            |      1.007 |     1.007 |     1.000 |     1.006 |     1.006 |
| hpm_mat4x4_unprojf           |      1.000 |     1.202 |     1.197 |     1.202 |     1.202 |
| hpm_vec4_com_eqfv            |      1.000 |     4.398 |     4.386 |     4.396 |     4.393 |
| hpm_vec4_eqfv                |      1.000 |     2.323 |     2.317 |     2.322 |     2.322 |
| hpm_vec4_com_neqfv           |      1.000 |     1.959 |     1.954 |     1.958 |     1.958 |
| hpm_vec4_neqfv               |      1.061 |     1.003 |     1.000 |     1.002 |     1.002 |
| hpm_vec4_com_gfv             |      1.000 |     1.855 |     1.850 |     1.854 |     1.854 |
| hpm_vec4_com_lfv             |      1.000 |     1.858 |     1.853 |     1.857 |     1.857 |
| hpm_mat4_eqfv                |      1.707 |     1.002 |     1.000 |     1.002 |     1.002 |
| hpm_mat4_neqfv               |      1.706 |     1.002 |     1.000 |     1.001 |     1.001 |
| hpm_quat_copyfv              |      1.001 |     1.001 |     1.000 |     1.001 |     1.001 |
| hpm_quat_multi_quatfv        |      1.000 |     1.275 |     1.273 |     1.275 |     1.275 |
| hpm_quat_multi_vec3fv        |      1.000 |     1.007 |     1.005 |     1.006 |     1.007 |
| hpm_quat_directionfv         |      1.000 |     1.017 |     1.015 |     1.017 |     1.015 |
| hpm_quat_get_vectorfv        |      1.000 |     1.006 |     1.005 |     1.007 |     1.006 |
| hpm_quat_conjugatefv         |      1.001 |     1.001 |     1.000 |     1.001 |     1.001 |
| hpm_quat_inversefv           |      1.000 |     1.033 |     1.032 |     1.008 |     1.008 |
| hpm_quat_dotfv               |      1.000 |     1.038 |     1.037 |     1.000 |     1.000 |
| hpm_quat_identityfv          |      1.001 |     1.001 |     1.000 |     1.001 |     1.001 |
| hpm_quat_axis_anglefv        |      1.001 |     1.001 |     1.000 |     1.001 |     1.000 |
| hpm_quat_from_mat4x4fv       |      1.001 |     1.001 |     1.000 |     1.001 |     1.001 |
| hpm_quat_axisf               |      1.002 |     1.002 |     1.002 |     1.002 |     1.000 |
| hpm_quat_lerpfv              |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |
| hpm_quat_slerpfv             |      1.000 |     1.009 |     1.009 |     1.001 |     1.000 |
| hpm_quat_pitchfv             |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |
| hpm_quat_yawfv               |      1.000 |     1.000 |     1.001 |     1.000 |     1.000 |
| hpm_quat_rollfv              |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |
| hpm_quat_eularfv             |      1.000 |     1.000 |     1.000 |     1.000 |     1.000 |
| hpm_quat_powfv               |      1.019 |     1.000 |     1.020 |     1.020 |     1.019 |
| hpm_vec4_maxfv               |      1.000 |     1.328 |     1.333 |     1.333 |     1.333 |
| hpm_vec8_maxfv               |      1.000 |     1.112 |     1.117 |     1.117 |     1.117 |
| hpm_vec4_minfv               |      1.000 |     1.328 |     1.334 |     1.334 |     1.333 |
| hpm_vec8_minfv               |      1.000 |     1.577 |     1.584 |     1.584 |     1.583 |
| hpm_vec4_sqrtfv              |      1.000 |     2.171 |     2.173 |     2.173 |     2.173 |
| hpm_vec8_sqrtfv              |      1.000 |     4.865 |     4.865 |     4.865 |     4.862 |
| hpm_vec4_fast_sqrtfv         |      1.000 |     4.515 |     4.520 |     4.521 |     4.519 |
| hpm_vec8_fast_sqrtfv         |      1.000 |     7.177 |     7.199 |     7.200 |     7.199 |
| hpm_vec4_copyfv              |      1.003 |     1.000 |     1.002 |     1.004 |     1.004 |
| hpm_vec4_dotfv               |      1.000 |     1.033 |     1.038 |     1.001 |     1.000 |
| hpm_vec4_lengthfv            |      1.000 |     1.158 |     1.162 |     1.135 |     1.135 |
| hpm_vec4_lengthsqurefv       |      1.000 |     1.072 |     1.076 |     1.035 |     1.035 |
| hpm_vec4_normalizefv         |      1.000 |     1.097 |     1.102 |     1.078 |     1.077 |
| hpm_vec4_negatefv            |      1.007 |     1.000 |     1.004 |     1.004 |     1.004 |
| hpm_vec4_lerpfv              |      1.008 |     1.000 |     1.005 |     1.005 |     1.005 |
| hpm_vec4_slerpfv             |      1.000 |     1.060 |     1.061 |     1.049 |     1.048 |
| hpm_vec4_max_compfv          |      1.000 |     1.303 |     1.303 |     1.303 |     1.303 |
| hpm_vec4_min_compfv          |      1.000 |     1.304 |     1.303 |     1.303 |     1.303 |
| hpm_vec3_crossproductfv      |      1.000 |     1.072 |     1.072 |     1.072 |     1.072 |
| hpm_vec3_tripleProductfv     |      1.028 |     1.018 |     1.018 |     1.000 |     1.000 |
| hpm_vec3_dotfv               |      1.002 |     1.029 |     1.029 |     1.000 |     1.000 |
| hpm_vec3_lengthfv            |      1.000 |     1.131 |     1.131 |     1.110 |     1.110 |
| hpm_vec3_lengthsquarefv      |      1.000 |     1.070 |     1.069 |     1.026 |     1.025 |
| hpm_vec3_normalizefv         |      1.000 |     1.098 |     1.098 |     1.075 |     1.075 |
| hpm_vec3_reflectfv           |      1.054 |     1.025 |     1.025 |     1.000 |     1.000 |
| hpm_vec3_refractfv           |      1.049 |     1.013 |     1.013 |     1.000 |     1.000 |
| hpm_vec3_projfv              |      1.049 |     1.034 |     1.033 |     1.000 |     1.000 |

## Intel Core i5 M 520 ##
Using GCC 8.3


|           Function           | NOSIMD  |   SSE  |  SSE2  |  SSE3  | SSSE3  | SSE41 | SSE42  |
| :---                         |     :---:  |      ---: |      ---: |      ---: |      ---: |      ---: |      ---: | 
| hpm_mat4x4_copyfv            |      1.000 |     1.078 |     1.090 |     1.068 |     1.144 |     1.068 |     1.072 |
| hpm_mat4x4_multiply_mat4x4fv |      1.312 |     1.000 |     1.004 |     1.003 |     1.005 |     1.003 |     1.003 |
| hpm_mat4x4_multiply_mat1x4fv |      1.000 |     2.068 |     2.069 |     2.060 |     2.066 |     2.053 |     2.064 |
| hpm_mat4x4_identityfv        |      1.000 |     1.014 |     1.009 |     1.011 |     1.005 |     1.003 |     1.009 |
| hpm_mat4x4_transposefv       |      1.000 |     1.358 |     1.348 |     1.361 |     1.359 |     1.360 |     1.359 |
| hpm_mat4x4_determinantfv     |      1.000 |     1.358 |     1.352 |     1.357 |     1.343 |     1.356 |     1.358 |
| hpm_mat4x4_inversefv         |      1.000 |     1.021 |     1.021 |     1.021 |     1.020 |     1.010 |     1.010 |
| hpm_mat4x4_decomposefv       |      1.018 |     1.014 |     1.016 |     1.016 |     1.000 |     1.020 |     1.019 |
| hpm_mat4x4_translationfv     |      1.000 |     1.017 |     1.017 |     1.018 |     1.020 |     1.059 |     1.054 |
| hpm_mat4x4_scalefv           |      1.066 |     1.066 |     1.076 |     1.055 |     1.070 |     1.076 |     1.000 |
| hpm_mat4x4_rotationfv        |      1.000 |     1.014 |     1.012 |     1.014 |     1.012 |     1.048 |     1.053 |
| hpm_mat4x4_rotationXf        |      1.015 |     1.019 |     1.024 |     1.012 |     1.023 |     1.002 |     1.000 |
| hpm_mat4x4_rotationYf        |      1.005 |     1.005 |     1.000 |     1.003 |     1.004 |     1.021 |     1.030 |
| hpm_mat4x4_rotationZf        |      1.000 |     1.006 |     1.004 |     1.005 |     1.000 |     1.152 |     1.161 |
| hpm_mat4x4_rotationQf        |      1.001 |     1.002 |     1.007 |     1.002 |     1.007 |     1.004 |     1.000 |
| hpm_mat4x4_projfv            |      1.000 |     1.005 |     1.004 |     1.004 |     1.004 |     1.063 |     1.074 |
| hpm_mat4x4_orthfv            |      1.006 |     1.001 |     1.004 |     1.000 |     1.005 |     1.007 |     1.005 |
| hpm_mat4x4_unprojf           |      1.040 |     1.074 |     1.074 |     1.070 |     1.073 |     1.075 |     1.000 |
| hpm_vec4_com_eqfv            |      1.000 |    20.728 |    20.862 |    20.657 |    20.946 |    20.906 |    16.953 |
| hpm_vec4_eqfv                |      1.000 |     4.595 |     4.571 |     4.561 |     4.591 |     2.954 |     2.489 |
| hpm_vec4_com_neqfv           |      1.000 |     2.826 |     2.811 |     2.817 |     2.774 |     2.821 |     2.479 |
| hpm_vec4_neqfv               |      3.529 |     1.589 |     1.594 |     1.590 |     1.592 |     1.135 |     1.000 |
| hpm_vec4_com_gfv             |      1.000 |     2.988 |     3.000 |     2.980 |     3.026 |     3.015 |     2.604 |
| hpm_vec4_com_lfv             |      1.000 |     2.932 |     2.925 |     2.930 |     2.948 |     2.953 |     2.557 |
| hpm_mat4_eqfv                |      1.688 |     1.255 |     1.255 |     1.256 |     1.254 |     1.231 |     1.000 |
| hpm_mat4_neqfv               |      1.623 |     1.217 |     1.214 |     1.217 |     1.219 |     1.195 |     1.000 |
| hpm_quat_copyfv              |      1.252 |     1.265 |     1.264 |     1.264 |     1.265 |     1.254 |     1.000 |
| hpm_quat_multi_quatfv        |      1.090 |     1.188 |     1.184 |     1.187 |     1.179 |     1.189 |     1.000 |
| hpm_quat_multi_vec3fv        |      1.000 |     1.197 |     1.204 |     1.200 |     1.202 |     1.276 |     1.056 |
| hpm_quat_directionfv         |      1.000 |     1.192 |     1.186 |     1.191 |     1.185 |     1.166 |     1.010 |
| hpm_quat_get_vectorfv        |      1.000 |     1.161 |     1.164 |     1.163 |     1.165 |     1.243 |     1.034 |
| hpm_quat_conjugatefv         |      1.131 |     1.136 |     1.145 |     1.145 |     1.142 |     1.147 |     1.000 |
| hpm_quat_inversefv           |      2.012 |     1.000 |     1.002 |     1.183 |     1.183 |     1.186 |     1.061 |
| hpm_quat_dotfv               |      1.863 |     1.000 |     1.002 |     1.297 |     1.305 |     2.717 |     2.374 |
| hpm_quat_identityfv          |      1.830 |     1.836 |     1.823 |     1.817 |     1.818 |     1.824 |     1.000 |
| hpm_quat_axis_anglefv        |      1.189 |     1.191 |     1.188 |     1.192 |     1.169 |     1.200 |     1.000 |
| hpm_quat_from_mat4x4fv       |      1.152 |     1.156 |     1.152 |     1.153 |     1.155 |     1.143 |     1.000 |
| hpm_quat_axisf               |      1.152 |     1.167 |     1.169 |     1.167 |     1.170 |     1.169 |     1.000 |
| hpm_quat_lerpfv              |      1.145 |     1.151 |     1.150 |     1.154 |     1.156 |     1.153 |     1.000 |
| hpm_quat_slerpfv             |      1.347 |     1.000 |     1.006 |     1.074 |     1.080 |     1.554 |     1.077 |
| hpm_quat_pitchfv             |      1.193 |     1.196 |     1.191 |     1.194 |     1.192 |     1.190 |     1.000 |
| hpm_quat_yawfv               |      1.255 |     1.250 |     1.249 |     1.251 |     1.255 |     1.253 |     1.000 |
| hpm_quat_rollfv              |      1.207 |     1.204 |     1.209 |     1.206 |     1.203 |     1.206 |     1.000 |
| hpm_quat_eularfv             |      1.176 |     1.178 |     1.177 |     1.178 |     1.175 |     1.174 |     1.000 |
| hpm_quat_powfv               |      1.200 |     1.205 |     1.205 |     1.195 |     1.205 |     1.211 |     1.000 |
| hpm_vec4_maxfv               |      1.000 |     1.912 |     1.943 |     1.935 |     1.934 |     1.935 |     1.713 |
| hpm_vec8_maxfv               |      1.000 |     2.296 |     2.298 |     2.300 |     2.307 |     2.294 |     2.021 |
| hpm_vec4_minfv               |      1.000 |     1.946 |     1.942 |     1.922 |     1.931 |     1.944 |     1.736 |
| hpm_vec8_minfv               |      1.000 |     2.325 |     2.329 |     2.324 |     2.324 |     2.321 |     2.073 |
| hpm_vec4_sqrtfv              |      1.000 |     3.115 |     3.104 |     3.115 |     3.111 |     3.115 |     2.819 |
| hpm_vec8_sqrtfv              |      1.000 |     3.851 |     3.814 |     3.848 |     3.853 |     3.850 |     3.503 |
| hpm_vec4_fast_sqrtfv         |      1.000 |     6.193 |     5.675 |     6.240 |     6.232 |     6.257 |     5.349 |
| hpm_vec8_fast_sqrtfv         |      1.000 |     6.769 |     6.757 |     6.773 |     6.753 |     6.757 |     5.943 |
| hpm_vec4_copyfv              |      1.117 |     1.118 |     1.118 |     1.117 |     1.112 |     1.120 |     1.000 |
| hpm_vec4_dotfv               |      1.862 |     1.002 |     1.000 |     1.312 |     1.285 |     2.745 |     2.421 |
| hpm_vec4_lengthfv            |      2.131 |     1.000 |     1.003 |     1.343 |     1.345 |     1.343 |     1.194 |
| hpm_vec4_lengthsqurefv       |      1.838 |     1.000 |     1.000 |     1.283 |     1.308 |     1.309 |     1.160 |
| hpm_vec4_normalizefv         |      1.947 |     1.002 |     1.000 |     1.169 |     1.166 |     1.168 |     1.067 |
| hpm_vec4_negatefv            |      1.103 |     1.083 |     1.106 |     1.102 |     1.091 |     1.101 |     1.000 |
| hpm_vec4_lerpfv              |      1.165 |     1.156 |     1.156 |     1.164 |     1.001 |     1.168 |     1.000 |
| hpm_vec4_slerpfv             |      1.532 |     1.112 |     1.113 |     1.263 |     1.262 |     1.269 |     1.000 |
| hpm_vec4_max_compfv          |      1.000 |     1.619 |     1.630 |     1.627 |     1.630 |     1.619 |     1.371 |
| hpm_vec4_min_compfv          |      1.000 |     1.559 |     1.559 |     1.556 |     1.545 |     1.551 |     1.397 |
| hpm_vec3_crossproductfv      |      1.000 |     1.287 |     1.287 |     1.283 |     1.286 |     1.284 |     1.163 |
| hpm_vec3_tripleProductfv     |      1.280 |     1.004 |     1.000 |     1.132 |     1.135 |     1.628 |     1.444 |
| hpm_vec3_dotfv               |      2.416 |     1.000 |     1.004 |     1.141 |     1.138 |     1.962 |     1.669 |
| hpm_vec3_lengthfv            |      3.215 |     1.024 |     1.023 |     1.189 |     1.192 |     1.189 |     1.000 |
| hpm_vec3_lengthsquarefv      |      2.585 |     1.000 |     1.002 |     1.172 |     1.173 |     1.170 |     1.023 |
| hpm_vec3_normalizefv         |      2.250 |     1.054 |     1.056 |     1.181 |     1.181 |     1.181 |     1.000 |
| hpm_vec3_reflectfv           |      2.368 |     1.003 |     1.000 |     1.088 |     1.085 |     1.487 |     1.238 |
| hpm_vec3_refractfv           |      2.435 |     1.000 |     1.001 |     1.107 |     1.110 |     1.521 |     1.321 |
| hpm_vec3_projfv              |      2.067 |     1.000 |     1.002 |     1.117 |     1.115 |     1.695 |     1.486 |
