// DCTL Functions

#define PI 			3.14159265359f
#define TWO_PI 		6.28318530718f
#define INV_PI 		0.31830988618f
#define INV2_PI 	0.15915494309f
#define INV4_PI 	0.07957747155f

typedef struct
{
float2 r0, r1;
} mat2;

typedef struct
{
float3 r0, r1, r2;
} mat3;

typedef struct
{
float4 r0, r1,r2, r3;
} mat4;

__DEVICE__ inline float2 ABS( float2 A)
{
return make_float2(_fabs(A.x), _fabs(A.y));
}

__DEVICE__ inline float3 ABS( float3 A)
{
return make_float3(_fabs(A.x), _fabs(A.y), _fabs(A.z));
}

__DEVICE__ inline float3 CLAMP( float3 in, float clampMin, float clampMax)
{
float3 out;
out.x = _clampf( in.x, clampMin, clampMax);
out.y = _clampf( in.y, clampMin, clampMax);
out.z = _clampf( in.z, clampMin, clampMax);   
return out;
}

__DEVICE__ inline float2 COS( float2 A)
{
return make_float2(_cosf(A.x), _cosf(A.y));
}

__DEVICE__ inline float3 COS( float3 A)
{
return make_float3(_cosf(A.x), _cosf(A.y), _cosf(A.z));
}

__DEVICE__ inline float2 floor( float2 A)
{
return make_float2(_floor(A.x), _floor(A.y));
}

__DEVICE__ inline float3 floor( float3 A)
{
return make_float3(_floor(A.x), _floor(A.y), _floor(A.z));
}

__DEVICE__ inline float fract( float A)
{
return A - _floor(A);
}

__DEVICE__ inline float2 fract( float2 A)
{
float2 B;
B.x = A.x - _floor(A.x);
B.y = A.y - _floor(A.y);
return B;
}

__DEVICE__ inline float3 fract( float3 A)
{
float3 B;
B.x = A.x - _floor(A.x);
B.y = A.y - _floor(A.y);
B.z = A.z - _floor(A.z);
return B;
}

__DEVICE__ inline mat2 make_mat2( float A1, float A2, float B1, float B2)
{
mat2 C;
C.r0 = make_float2(A1, A2);
C.r1 = make_float2(B1, B2);
return C;
}

__DEVICE__ inline mat3 make_mat3( float3 A, float3 B, float3 C)
{
mat3 D;
D.r0 = A;
D.r1 = B;
D.r2 = C;
return D;
}

__DEVICE__ inline mat4 make_mat4( float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, 
float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33)
{
mat4 M;
M.r0 = make_float4(m00, m01, m02, m03);
M.r1 = make_float4(m10, m11, m12, m13);
M.r2 = make_float4(m20, m21, m22, m23);
M.r3 = make_float4(m30, m31, m32, m33);
return M;
}

__DEVICE__ inline mat3 MAT3( mat4 A)
{
mat3 B;
B.r0 = make_float3(A.r0.x, A.r0.y, A.r0.z);
B.r1 = make_float3(A.r1.x, A.r1.y, A.r1.z);
B.r2 = make_float3(A.r2.x, A.r2.y, A.r2.z);
return B;
}

__DEVICE__ inline float2 MAX( float2 in, float Min)
{
float2 out;
out.x = _fmaxf(in.x, Min);
out.y = _fmaxf(in.y, Min);
return out;
}

__DEVICE__ inline float2 MAX( float2 in, float2 Min)
{
float2 out;
out.x = _fmaxf(in.x, Min.x);
out.y = _fmaxf(in.y, Min.y);
return out;
}

__DEVICE__ inline float3 MAX( float3 in, float Min)
{
float3 out;
out.x = _fmaxf(in.x, Min);
out.y = _fmaxf(in.y, Min);
out.z = _fmaxf(in.z, Min);
return out;
}

__DEVICE__ inline float3 MAX( float3 in, float3 Min)
{
float3 out;
out.x = _fmaxf(in.x, Min.x);
out.y = _fmaxf(in.y, Min.y);
out.z = _fmaxf(in.z, Min.z);
return out;
}

__DEVICE__ inline float2 MOD( float2 A, float B)
{
float2 C;
C.x = _fmod(A.x, B);
C.y = _fmod(A.y, B);
return C;
}

__DEVICE__ inline float3 MOD( float3 A, float B)
{
float3 C;
C.x = _fmod(A.x, B);
C.y = _fmod(A.y, B);
C.z = _fmod(A.z, B);
return C;
}

__DEVICE__ inline float mix( float A, float B, float C)
{
return A * (1.0f - C) + B * C;
}

__DEVICE__ inline float2 mix( float2 A, float2 B, float C)
{
return A * (1.0f - C) + B * C;
}

__DEVICE__ inline float3 mix( float3 A, float3 B, float C)
{
return A * (1.0f - C) + B * C;
}

__DEVICE__ inline float2 multi( float2 A, mat2 B)
{
float2 C;
C.x = A.x * B.r0.x + A.y * B.r0.y;
C.y = A.x * B.r1.x + A.y * B.r1.y;
return C;
}

__DEVICE__ inline float3 multi( float3 A, mat3 B)
{
float3 C;
C.x = A.x * B.r0.x + A.y * B.r0.y + A.z * B.r0.z;
C.y = A.x * B.r1.x + A.y * B.r1.y + A.z * B.r1.z;
C.z = A.x * B.r2.x + A.y * B.r2.y + A.z * B.r2.z;
return C;
}

__DEVICE__ inline mat3 multi( mat3 A, mat3 B)
{
float r[3][3];
float a[3][3] =	{{A.r0.x, A.r0.y, A.r0.z},
{A.r1.x, A.r1.y, A.r1.z},
{A.r2.x, A.r2.y, A.r2.z}};
float b[3][3] =	{{B.r0.x, B.r0.y, B.r0.z},
{B.r1.x, B.r1.y, B.r1.z},
{B.r2.x, B.r2.y, B.r2.z}};

for( int i = 0; i < 3; ++i)
{
for( int j = 0; j < 3; ++j)
{
r[i][j] = 0.0f;
for( int k = 0; k < 3; ++k)
{
r[i][j] = r[i][j] + a[i][k] * b[k][j];
}
}
}
mat3 R = make_mat3(make_float3(r[0][0], r[0][1], r[0][2]), 
make_float3(r[1][0], r[1][1], r[1][2]), make_float3(r[2][0], r[2][1], r[2][2]));
return R;
}

__DEVICE__ inline float2 POW( float2 A, float B)
{
return make_float2(_powf(A.x, B), _powf(A.y, B));
}

__DEVICE__ inline float2 POW( float2 A, float2 B)
{
return make_float2(_powf(A.x, B.x), _powf(A.y, B.y));
}

__DEVICE__ inline float3 POW( float3 A, float B)
{
return make_float3(_powf(A.x, B), _powf(A.y, B), _powf(A.z, B));
}

__DEVICE__ inline float3 POW( float3 A, float3 B)
{
return make_float3(_powf(A.x, B.x), _powf(A.y, B.y), _powf(A.z, B.z));
}

__DEVICE__ inline float2 SIN( float2 A)
{
return make_float2(_sinf(A.x), _sinf(A.y));
}

__DEVICE__ inline float3 SIN( float3 A)
{
return make_float3(_sinf(A.x), _sinf(A.y), _sinf(A.z));
}

__DEVICE__ inline float2 SQRT( float2 A)
{
return make_float2(_sqrtf(A.x), _sqrtf(A.y));
}

__DEVICE__ inline float3 SQRT( float3 A)
{
return make_float3(_sqrtf(A.x), _sqrtf(A.y), _sqrtf(A.z));
}

__DEVICE__ inline mat2 transpose(mat2 A)
{
mat2 B;
B.r0 = make_float2(A.r0.x, A.r1.x);
B.r1 = make_float2(A.r0.y, A.r1.y);
return B;
}

__DEVICE__ inline mat3 transpose( mat3 A)
{
mat3 B;
B.r0 = make_float3(A.r0.x, A.r1.x, A.r2.x);
B.r1 = make_float3(A.r0.y, A.r1.y, A.r2.y);
B.r2 = make_float3(A.r0.z, A.r1.z, A.r2.z);
return B;
}

