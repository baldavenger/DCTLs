// DCTL Functions

#define PI 			3.14159265359f
#define TWO_PI 		6.28318530718f
#define INV_PI 		0.31830988618f
#define INV2_PI 	0.15915494309f
#define INV4_PI 	0.07957747155f
#define PHI			1.61803398875f
#define SQRT3		1.73205080757f

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

__DEVICE__ inline float4 CLAMP( float4 in, float clampMin, float clampMax)
{
float4 out;
out.x = _clampf( in.x, clampMin, clampMax);
out.y = _clampf( in.y, clampMin, clampMax);
out.z = _clampf( in.z, clampMin, clampMax);
out.w = _clampf( in.w, clampMin, clampMax);
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

__DEVICE__ inline float4 COS( float4 A)
{
return make_float4(_cosf(A.x), _cosf(A.y), _cosf(A.z), _cosf(A.w));
}

__DEVICE__ inline float distance( float2 A, float2 B)
{
return _sqrtf(dot(A, B));
}

__DEVICE__ inline float distance( float3 A, float3 B)
{
return _sqrtf(dot(A, B));
}

__DEVICE__ inline float3 EXP( float3 A)
{
return make_float3(_expf(A.x), _expf(A.y), _expf(A.z));
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

__DEVICE__ inline float4 fract( float4 A)
{
float4 B;
B.x = A.x - _floor(A.x);
B.y = A.y - _floor(A.y);
B.z = A.z - _floor(A.z);
B.w = A.w - _floor(A.w);
return B;
}

__DEVICE__ inline float3 LOG( float3 A)
{
return make_float3(_logf(A.x), _logf(A.y), _logf(A.z));
}

__DEVICE__ inline float4 Make_float4( float A, float3 B)
{
return make_float4(A, B.x, B.y, B.z);
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

__DEVICE__ inline mat3 make_mat3( float m00, float m01, float m02, 
float m10, float m11, float m12, float m20, float m21, float m22)
{
mat3 M;
M.r0 = make_float3(m00, m01, m02);
M.r1 = make_float3(m10, m11, m12);
M.r2 = make_float3(m20, m21, m22);
return M;
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

__DEVICE__ inline float2 MIN( float2 in, float Max)
{
float2 out;
out.x = _fminf(in.x, Max);
out.y = _fminf(in.y, Max);
return out;
}

__DEVICE__ inline float2 MIN( float2 in, float2 Max)
{
float2 out;
out.x = _fminf(in.x, Max.x);
out.y = _fminf(in.y, Max.y);
return out;
}

__DEVICE__ inline float3 MIN( float3 in, float Max)
{
float3 out;
out.x = _fminf(in.x, Max);
out.y = _fminf(in.y, Max);
out.z = _fminf(in.z, Max);
return out;
}

__DEVICE__ inline float3 MIN( float3 in, float3 Max)
{
float3 out;
out.x = _fminf(in.x, Max.x);
out.y = _fminf(in.y, Max.y);
out.z = _fminf(in.z, Max.z);
return out;
}

__DEVICE__ inline float4 MIN( float4 in, float4 Max)
{
float4 out;
out.x = _fminf(in.x, Max.x);
out.y = _fminf(in.y, Max.y);
out.z = _fminf(in.z, Max.z);
out.w = _fminf(in.w, Max.w);
return out;
}

__DEVICE__ inline float2 MOD( float2 A, float B)
{
float2 C;
C.x = _fmod(A.x, B);
C.y = _fmod(A.y, B);
return C;
}

__DEVICE__ inline float2 MOD( float2 A, float2 B)
{
float2 C;
C.x = _fmod(A.x, B.x);
C.y = _fmod(A.y, B.y);
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

__DEVICE__ inline float3 MOD( float3 A, float3 B)
{
float3 C;
C.x = _fmod(A.x, B.x);
C.y = _fmod(A.y, B.y);
C.z = _fmod(A.z, B.z);
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

__DEVICE__ inline float3 mix(float3 A, float3 B, float3 C)
{
return A * (1.0f - C) + B * C;
}

__DEVICE__ inline float4 mix( float4 A, float4 B, float C)
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

__DEVICE__ inline float2 multi( mat2 B, float2 A)
{
float2 C;
C.x = A.x * B.r0.x + A.y * B.r0.y;
C.y = A.x * B.r1.x + A.y * B.r1.y;
return C;
}

__DEVICE__ inline mat2 multi( mat2 A, float B)
{
return make_mat2(A.r0.x * B, A.r0.y * B, A.r1.x * B, A.r1.y * B);
}

__DEVICE__ inline mat3 multi( mat3 A, float B)
{
return make_mat3(A.r0 * B, A.r1 * B, A.r2 * B);
}

__DEVICE__ inline mat3 multi( float B, mat3 A)
{
return make_mat3(A.r0 * B, A.r1 * B, A.r2 * B);
}

__DEVICE__ inline float3 multi( float3 A, mat3 B)
{
float3 C;
C.x = A.x * B.r0.x + A.y * B.r0.y + A.z * B.r0.z;
C.y = A.x * B.r1.x + A.y * B.r1.y + A.z * B.r1.z;
C.z = A.x * B.r2.x + A.y * B.r2.y + A.z * B.r2.z;
return C;
}

__DEVICE__ inline float3 multi( mat3 B, float3 A)
{
float3 C;
C.x = A.x * B.r0.x + A.y * B.r0.y + A.z * B.r0.z;
C.y = A.x * B.r1.x + A.y * B.r1.y + A.z * B.r1.z;
C.z = A.x * B.r2.x + A.y * B.r2.y + A.z * B.r2.z;
return C;
}

__DEVICE__ inline float4 multi( float4 A, mat4 B)
{
float4 C;
C.x = A.x * B.r0.x + A.y * B.r0.y + A.z * B.r0.z + A.w * B.r0.w;
C.y = A.x * B.r1.x + A.y * B.r1.y + A.z * B.r1.z + A.w * B.r1.w;
C.z = A.x * B.r2.x + A.y * B.r2.y + A.z * B.r2.z + A.w * B.r2.w;
C.w = A.x * B.r3.x + A.y * B.r3.y + A.z * B.r3.z + A.w * B.r3.w;
return C;
}

__DEVICE__ inline float4 multi( mat4 B, float4 A)
{
float4 C;
C.x = A.x * B.r0.x + A.y * B.r0.y + A.z * B.r0.z + A.w * B.r0.w;
C.y = A.x * B.r1.x + A.y * B.r1.y + A.z * B.r1.z + A.w * B.r1.w;
C.z = A.x * B.r2.x + A.y * B.r2.y + A.z * B.r2.z + A.w * B.r2.w;
C.w = A.x * B.r3.x + A.y * B.r3.y + A.z * B.r3.z + A.w * B.r3.w;
return C;
}

//__DEVICE__ inline float4 multi( mat4 A, float4 B)
//{
//return multi(B, A);
//}

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

__DEVICE__ inline void multi( float* A, float* B, mat2 C)
{
float a = *A;
float b = *B;
float2 AB = multi(make_float2(a, b), C);
*A = AB.x;
*B = AB.y;
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

__DEVICE__ inline float radians( float degrees)
{
return (degrees * PI) / 180;
}

/*
__DEVICE__ inline float3 reflect(float3 A, float3 B)
{
float3 C;
C.x = A.x - 2.0f * dot(B, A) * B.x;
C.y = A.y - 2.0f * dot(B, A) * B.y;
C.z = A.z - 2.0f * dot(B, A) * B.z;
return C;
}
*/

__DEVICE__ inline float sign( float A)
{
return (A < 0.0f ? -1.0f : A > 0.0f ? 1.0f : 0.0f);
}

__DEVICE__ inline float2 sign( float2 A)
{
float2 sn;
sn.x = A.x == 0.0f ? 0.0f : A.x < 0.0f ? -1.0f : 1.0f;
sn.y = A.y == 0.0f ? 0.0f : A.y < 0.0f ? -1.0f : 1.0f;
return sn;
}

__DEVICE__ inline float3 sign( float3 A)
{
float3 sn;
sn.x = A.x < 0.0f ? -1.0f : A.x > 0.0f ? 1.0f : 0.0f;
sn.y = A.y < 0.0f ? -1.0f : A.y > 0.0f ? 1.0f : 0.0f;
sn.z = A.z < 0.0f ? -1.0f : A.z > 0.0f ? 1.0f : 0.0f;
return sn;
}

__DEVICE__ inline float2 SIN( float2 A)
{
return make_float2(_sinf(A.x), _sinf(A.y));
}

__DEVICE__ inline float3 SIN( float3 A)
{
return make_float3(_sinf(A.x), _sinf(A.y), _sinf(A.z));
}

__DEVICE__ inline float4 SIN( float4 A)
{
return make_float4(_sinf(A.x), _sinf(A.y), _sinf(A.z), _sinf(A.w));
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

__DEVICE__ inline mat3 inverse( mat3 A)
{
  mat3 R;
  float result[3][3];
  float a[3][3] =	{{A.r0.x, A.r0.y, A.r0.z},
  		 {A.r1.x, A.r1.y, A.r1.z},
  		 {A.r2.x, A.r2.y, A.r2.z}};
  		 
  float det =   a[0][0] * a[1][1] * a[2][2]
              + a[0][1] * a[1][2] * a[2][0]
              + a[0][2] * a[1][0] * a[2][1]
              - a[2][0] * a[1][1] * a[0][2]
              - a[2][1] * a[1][2] * a[0][0]
              - a[2][2] * a[1][0] * a[0][1];
  if( det != 0.0 )
  {
    result[0][0] = a[1][1] * a[2][2] - a[1][2] * a[2][1];
    result[0][1] = a[2][1] * a[0][2] - a[2][2] * a[0][1];
    result[0][2] = a[0][1] * a[1][2] - a[0][2] * a[1][1];
    result[1][0] = a[2][0] * a[1][2] - a[1][0] * a[2][2];
    result[1][1] = a[0][0] * a[2][2] - a[2][0] * a[0][2];
    result[1][2] = a[1][0] * a[0][2] - a[0][0] * a[1][2];
    result[2][0] = a[1][0] * a[2][1] - a[2][0] * a[1][1];
    result[2][1] = a[2][0] * a[0][1] - a[0][0] * a[2][1];
    result[2][2] = a[0][0] * a[1][1] - a[1][0] * a[0][1];
    
    R = make_mat3(make_float3(result[0][0], result[0][1], result[0][2]), 
    make_float3(result[1][0], result[1][1], result[1][2]), make_float3(result[2][0], result[2][1], result[2][2]));
    return multi( 1.0f / det, R);
  }
  R = make_mat3(make_float3(1.0f, 0.0f, 0.0f), make_float3(0.0f, 1.0f, 0.0f), make_float3(0.0f, 0.0f, 1.0f));
  return R;
}

__DEVICE__ inline void rgb_to_hsv( float r, float g, float b, float *h, float *s, float *v)
{
float min = _fminf(_fminf(r, g), b);
float max = _fmaxf(_fmaxf(r, g), b);
*v = max;
float delta = max - min;
if (max != 0) {
*s = delta / max;
} else {
*s = 0;
*h = 0;
return;
}
if (delta == 0) {
*h = 0;
} else if (r == max) {
*h = (g - b) / delta;
} else if (g == max) {
*h = 2 + (b - r) / delta;
} else {
*h = 4 + (r - g) / delta;
}
*h *= 1.0f / 6;
if (*h < 0) {
*h += 1;
}
}

__DEVICE__ inline void hsv_to_rgb(float H, float S, float V, float *r, float *g, float *b)
{
if (S == 0.0f) {
*r = *g = *b = V; return;
}
H *= 6;
int i = _floor(H);
float f = H - i;
i = (i >= 0) ? (i % 6) : (i % 6) + 6;
float p = V * (1 - S);
float q = V * (1 - S * f);
float t = V * (1 - S * (1 - f));
*r = i == 0 ? V : i == 1 ? q : i == 2 ? p : i == 3 ? p : i == 4 ? t : V;
*g = i == 0 ? t : i == 1 ? V : i == 2 ? V : i == 3 ? q : i == 4 ? p : p;
*b = i == 0 ? p : i == 1 ? p : i == 2 ? t : i == 3 ? V : i == 4 ? V : q;
}

__DEVICE__ inline float3 hsv( float H, float S, float V)
{
float3 rgb;
if (S == 0) return make_float3(V);
H = H > 1 ? H - 1 : H < 0 ? H + 1 : H;
H *= 6;
int i = _floor(H);
float f = H - i;
i = (i >= 0) ? (i % 6) : (i % 6) + 6;
float p = V * (1 - S);
float q = V * (1 - S * f);
float t = V * (1 - S * (1 - f));
rgb.x = i == 0 ? V : i == 1 ? q : i == 2 ? p : i == 3 ? p : i == 4 ? t : V;
rgb.y = i == 0 ? t : i == 1 ? V : i == 2 ? V : i == 3 ? q : i == 4 ? p : p;
rgb.z = i == 0 ? p : i == 1 ? p : i == 2 ? t : i == 3 ? V : i == 4 ? V : q;
return rgb;
}

__DEVICE__ inline void rotate( float* ax, float* ay, float b)
{
float AX = *ax;
float AY = *ay;
float c = _cosf(b);
float s = _sinf(b);
*ax = AX * c - AY * s;
*ay = AX * s + AY * c;
}
