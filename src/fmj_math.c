
#include "fmj_types.h"

f2 f2_create(f32 a,f32 b)
{
    f2 result = {0};
    result.x = a;
    result.y = b;
    return result;
}

f2 f2_add(f2 a,f2 b)
{
    f2 r = {0};
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}

f2 f2_s_add(f32 a,f2 b)
{
    f2 r = {0};
    return f2_add(f2_create(a,a),b);
}

f2 f2_add_s(f2 b,f32 a)
{
    f2 r = {0};
    return f2_add(f2_create(a,a),b);
}

f2 f2_sub(f2 a,f2 b)
{
    f2 r = {0};
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    return r;
}

f2 f2_s_sub(f32 a,f2 b)
{
    f2 r = {0};
    return f2_sub(f2_create(a,a),b);
}

f2 f2_sub_s(f2 a,f32 b)
{
    return f2_sub(a,f2_create(b,b));
}

f2 f2_mul(f2 a,f2 b)
{
    f2 r = {0};
    r.x = a.x * b.x;
    r.y = a.y * b.y;
    return r;
}

f2 f2_s_mul(f32 a,f2 b)
{
    return f2_mul(f2_create(a,a),b);    
}

f2 f2_mul_s(f2 b,f32 a)
{
    return f2_mul(f2_create(a,a),b);    
}

f2 f2_div(f2 a,f2 b)
{
    f2 r = {0};
    r.x = a.x / b.x;
    r.y = b.x / b.y;
    return r;
}

f2 f2_s_div(f32 a,f2 b)
{
    return f2_div(f2_create(a,a),b);
}

f2 f2_div_s(f2 a,f32 b)
{
    return f2_div(a,f2_create(b,b));
}

f3 f3_create(f32 a,f32 b,f32 c)
{
    f3 r = {0};
    r.x = a;
    r.y = b;
    r.z = c;
    return r;
}

f3 f3_add(f3 a,f3 b)
{
    f3 r = {0};
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

f3 f3_s_add(f32 a,f3 b)
{
    return f3_add(f3_create(a,a,a),b);
}

f3 f3_add_s(f3 b,f32 a)
{
    return f3_add(f3_create(a,a,a),b);
}

f3 f3_sub(f3 a,f3 b)
{
    f3 r = {0};
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

f3 f3_s_sub(f32 a,f3 b)
{
    return f3_sub(f3_create(a,a,a),b);
}

f3 f3_sub_s(f3 a,f32 b)
{
    return f3_sub(a,f3_create(b,b,b));
}

f3 f3_mul(f3 a,f3 b)
{
    f3 r = {0};
    r.x = a.x * b.x;
    r.y = a.y * b.y;
    r.z = a.z * b.z;
    return r;
}

f3 f3_s_mul(f32 a,f3 b)
{
    return f3_mul(f3_create(a,a,a),b);
}

f3 f3_mul_s(f3 b,f32 a)
{
    return f3_mul(f3_create(a,a,a),b);
}

f3 f3_div(f3 a,f3 b)
{
    f3 r = {0};
    r.x = a.x / b.x;
    r.y = a.y / b.y;
    r.z = a.z / b.z;
    return r;
}

f3 f3_s_div(f32 a,f3 b)
{
    return f3_div(f3_create(a,a,a),b);
}

f3 f3_div_s(f3 a,f32 b)
{
    return f3_div(a,f3_create(b,b,b));
}


f4 f4_create(f32 a,f32 b,f32 c,f32 d)
{
    f4 r = {0};
    r.x = a;
    r.y = b;
    r.z = c;
    r.w = d;
    return r;
}

f4 f4_add(f4 a,f4 b)
{
    f4 r = {0};
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    r.w = a.w + b.w;
    return r;
}

f4 f4_s_add(f32 a,f4 b)
{
    return f4_add(f4_create(a,a,a,a),b);    
}

f4 f4_add_s(f4 b,f32 a)
{
    return f4_add(f4_create(a,a,a,a),b);    
}

f4 f4_sub(f4 a,f4 b)
{
    f4 r = {0};
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    r.w = a.w - b.w; 
    return r;
}

f4 f4_s_sub(f32 a,f4 b)
{
    return f4_sub(f4_create(a,a,a,a),b);    
}

f4 f4_sub_s(f4 a,f32 b)
{
    return f4_sub(a,f4_create(b,b,b,b));    
}

f4 f4_mul(f4 a,f4 b)
{
    f4 r = {0};
    r.x = a.x * b.x;
    r.y = a.y * b.y;
    r.z = a.z * b.z;
    r.w = a.w * b.w;
    return r;    
}

f4 f4_s_mul(f32 a,f4 b)
{
    return f4_mul(f4_create(a,a,a,a),b);
}

f4 f4_mul_s(f4 b,f32 a)
{
    return f4_mul(f4_create(a,a,a,a),b);
}

f4 f4_div(f4 a,f4 b)
{
    f4 r = {0};
    r.x = a.x / b.x;
    r.y = a.y / b.y;
    r.z = a.z / b.z;
    r.w = a.w / b.w;
    return r;    
}

f4 f4_s_div(f32 a,f4 b)
{
    return f4_div(f4_create(a,a,a,a),b);    
}

f4 f4_div_s(f4 a,f32 b)
{
    return f4_div(a,f4_create(b,b,b,b));    
}

f3 cross(f3 a, f3 b)
{
	return f3_create(a.y * b.z - a.z * b.y,
		             a.z * b.x - a.x * b.z,
		             a.x * b.y - a.y * b.x);
}

f32 safe_ratio_zero(f32 a,f32 b){ if (a == 0.0f || b == 0.0f) { return 0.0f; } else { return a / b; } }

f32 f2_sum(f2 a)
{
    return a.x + a.y;
}

f32 f3_sum(f3 a)
{
    return a.x + a.y + a.z;
}

f32 f4_sum(f4 a)
{
    return a.x + a.y + a.z + a.w;
}

f32 f2_length(f2 a)
{
    return sqrtf(f2_dot(a, a));    
}

f32 f3_length(f3 a)
{
    return sqrtf(f3_dot(a, a));
}
f32 f4_length(f4 a)
{
    return sqrtf(f4_dot(a, a));
}

f32 f2_dot(f2 a, f2 b)
{
    return f2_sum(f2_mul(a,b));    
}

f32 f3_dot(f3 a, f3 b)
{
    return f3_sum(f3_mul(a,b));
}

f32 f4_dot(f4 a, f4 b)
{
    return f4_sum(f4_mul(a,b));
}

f2 f2_normalize(f2 a){return f2_mul_s(a,(safe_ratio_zero(1.0f , f2_length(a))));}
f3 f3_normalize(f3 a){return f3_mul_s(a,(safe_ratio_zero(1.0f , f3_length(a))));}
f4 f4_normalize(f4 a){return f4_mul_s(a,(safe_ratio_zero(1.0f , f4_length(a))));}

f32 clamp(f32 x,f32 a,f32 b){ return fmax(a, fmin(b, x));}

f32 f2_length_sq(f2 a){ return f2_dot(a, a);}
f32 f3_length_sq(f3 a){ return f3_dot(a, a);}
f32 f4_length_sq(f4 a){ return f4_dot(a, a);}

f32 lerp(f32 a,f32 b,f32 t){ return a + (b-a)*t;}
f2 f2_lerp(f2 a, f2 b,f2 t){ return f2_add(a,f2_mul(f2_sub(b,a),t));}
f3 f3_lerp(f3 a, f3 b,f3 t){ return f3_add(a,f3_mul(f3_sub(b,a),t));}
f4 f4_lerp(f4 a, f4 b,f4 t){ return f4_add(a,f4_mul(f4_sub(b,a),t));}

f32 unlerp(float  a, float  b, float  x) { return (x - a) / (b - a); }
f2 f2_unlerp(f2 a, f2 b, f2 x) { return f2_div(f2_sub(x,a),f2_sub(b,a)); }
f3 f3_unlerp(f3 a, f3 b, f3 x) { return f3_div(f3_sub(x,a),f3_sub(b,a)); }
f4 f4_unlerp(f4 a, f4 b, f4 x) { return f4_div(f4_sub(x,a),f4_sub(b,a)); }

f32 f2_distance(f2 a, f2 b){ return f2_length(f2_sub(b,a)); }
f32 f3_distance(f3 a, f3 b){ return f3_length(f3_sub(b,a)); }

f2  f2_sin(f2 x) { return f2_create(sinf(x.x), sinf(x.y)); }
f3  f3_sin(f3 x) { return f3_create(sinf(x.x), sinf(x.y), sinf(x.z)); }
f4  f4_sin(f4 x) { return f4_create(sin(x.x), sinf(x.y), sinf(x.z), sinf(x.w)); }

f2  f2_cos(f2 x) { return f2_create(cosf(x.x), cosf(x.y)); }
f3  f3_cos(f3 x) { return f3_create(cosf(x.x), cosf(x.y), cosf(x.z)); }
f4  f4_cos(f4 x) { return f4_create(cosf(x.x), cosf(x.y), cosf(x.z), cosf(x.w)); }

void  sincos(f32  x,f32* s,f32* c) { *s = sinf(x); *c = cosf(x); }
void  f2_sincos(f2 x,f2* s,f2* c) { *s = f2_sin(x); *c = f2_cos(x); }
void  f3_sincos(f3 x,f3* s,f3* c) { *s = f3_sin(x); *c = f3_cos(x); }
void  f4_sincos(f4 x,f4* s,f4* c) { *s = f4_sin(x); *c = f4_cos(x); }


f32 remap(f32  a, f32  b, f32  c, f32  d, f32  x)  { return lerp(c, d, unlerp(a, b, x)); }
f2  f2_remap(f2 a, f2 b, f2 c, f2 d, f2 x) { return f2_lerp(c, d, f2_unlerp(a, b, x)); }
f3  f3_remap(f3 a, f3 b, f3 c, f3 d, f3 x) { return f3_lerp(c, d, f3_unlerp(a, b, x)); }
f4  f4_remap(f4 a, f4 b, f4 c, f4 d, f4 x) { return f4_lerp(c, d, f4_unlerp(a, b, x)); }

f32 mad(f32  a, f32  b, f32  c) { return a * b + c; }
f2  f2_mad(f2 a, f2 b, f2 c) { return f2_add(f2_mul(a,b),c); }
f3  f3_mad(f3 a, f3 b, f3 c) { return f3_add(f3_mul(a,b),c); }
f4  f4_mad(f4 a, f4 b, f4 c) { return f4_add(f4_mul(a,b),c); }

f2  f2_tan(f2 x) { return f2_create(tanf(x.x), tanf(x.y)); }
f3  f3_tan(f3 x) { return f3_create(tanf(x.x), tanf(x.y), tanf(x.z)); }
f4  f4_tan(f4 x) { return f4_create(tanf(x.x), tanf(x.y), tanf(x.z), tanf(x.w)); }


f2  f2_atan(f2 x) { return f2_create(atanf(x.x), atanf(x.y)); }
f3  f3_atan(f3 x) { return f3_create(atanf(x.x), atanf(x.y), atanf(x.z)); }
f4  f4_atan(f4 x) { return f4_create(atanf(x.x), atanf(x.y), atanf(x.z), atanf(x.w)); }


f2  f2_atan2(f2 y, f2 x) { return f2_create(atan2f(y.x, x.x), atan2f(y.y, x.y)); }
f3  f3_atan2(f3 y, f3 x) { return f3_create(atan2f(y.x, x.x), atan2f(y.y, x.y), atan2f(y.z, x.z)); }
f4  f4_atan2(f4 y, f4 x) { return f4_create(atan2f(y.x, x.x), atan2f(y.y, x.y), atan2f(y.z, x.z), atan2f(y.w, x.w)); }


f2  f2_cosh(f2 x) { return f2_create(coshf(x.x), coshf(x.y)); }
f3  f3_cosh(f3 x) { return f3_create(coshf(x.x), coshf(x.y), coshf(x.z)); }
f4  f4_cosh(f4 x) { return f4_create(coshf(x.x), coshf(x.y), coshf(x.z), coshf(x.w)); }

f2  f2_acos(f2 x) { return f2_create(acosf(x.x), acosf(x.y)); }
f3  f3_acos(f3 x) { return f3_create(acosf(x.x), acosf(x.y), acosf(x.z)); }
f4  f4_acos(f4 x) { return f4_create(acosf(x.x), acosf(x.y), acosf(x.z), acosf(x.w)); }

f2  f2_asin(f2 x) { return f2_create(asinf(x.x), asinf(x.y)); }
f3  f3_asin(f3 x) { return f3_create(asinf(x.x), asinf(x.y), asinf(x.z)); }
f4  f4_asin(f4 x) { return f4_create(asinf(x.x), asinf(x.y), asinf(x.z), asinf(x.w)); }

f2  f2_floor(f2 x) { return f2_create(floorf(x.x), floorf(x.y)); }
f3  f3_floor(f3 x) { return f3_create(floorf(x.x), floorf(x.y), floorf(x.z)); }
f4  f4_floor(f4 x) { return f4_create(floorf(x.x), floorf(x.y), floorf(x.z), floorf(x.w)); }

f2  f2_ceil(f2 x) { return  f2_create(ceilf(x.x), ceilf(x.y)); }
f3  f3_ceil(f3 x) { return  f3_create(ceilf(x.x), ceilf(x.y), ceilf(x.z)); }
f4  f4_ceil(f4 x) { return  f4_create(ceilf(x.x), ceilf(x.y), ceilf(x.z), ceilf(x.w)); }

f2  f2_round(f2 x) { return f2_create(roundf(x.x), roundf(x.y)); }
f3  f3_round(f3 x) { return f3_create(roundf(x.x), roundf(x.y), roundf(x.z)); }
f4  f4_round(f4 x) { return f4_create(roundf(x.x), roundf(x.y), roundf(x.z), roundf(x.w)); }

f2  f2_trunc(f2 x) { return f2_create(truncf(x.x), truncf(x.y)); }
f3  f3_trunc(f3 x) { return f3_create(truncf(x.x), truncf(x.y), truncf(x.z)); }
f4  f4_trunc(f4 x) { return f4_create(truncf(x.x), truncf(x.y), truncf(x.z), truncf(x.w)); }

f32 frac(f32 x) { return x - floorf(x); }
f2  f2_frac(f2 x) { return f2_sub(x,f2_floor(x)); }
f3  f3_frac(f3 x) { return f3_sub(x,f3_floor(x)); }
f4  f4_frac(f4 x) { return f4_sub(x,f4_floor(x)); }

f32 rcp(f32 x) { return 1.0f / x; }
f2  f2_rcp(f2 x) { return f2_s_div(1.0f,x); }
f3  f3_rcp(f3 x) { return f3_s_div(1.0f,x); }
f4  f4_rcp(f4 x) { return f4_s_div(1.0f,x); }

f32  sign(f32 x) { return x == 0.0f ? 0.0f : (x > 0.0f ? 1.0f : 0.0f) - (x < 0.0f ? 1.0f : 0.0f); }
f2  f2_sign(f2 x) { return f2_create(sign(x.x), sign(x.y)); }
f3  f3_sign(f3 x) { return f3_create(sign(x.x), sign(x.y), sign(x.z)); }
f4  f4_sign(f4 x) { return f4_create(sign(x.x), sign(x.y), sign(x.z), sign(x.w)); }

f2  f2_pow(f2 x, f2 y) { return  f2_create(powf(x.x, y.x), powf(x.y, y.y)); }
f3  f3_pow(f3 x, f3 y) { return  f3_create(powf(x.x, y.x), powf(x.y, y.y), powf(x.z, y.z)); }
f4  f4_pow(f4 x, f4 y) { return  f4_create(powf(x.x, y.x), powf(x.y, y.y), powf(x.z, y.z), powf(x.w, y.w)); }

f2 f2_exp(f2 x) { return f2_create(expf(x.x), expf(x.y)); }
f3 f3_exp(f3 x) { return f3_create(expf(x.x), expf(x.y), expf(x.z)); }
f4 f4_exp(f4 x) { return f4_create(expf(x.x), expf(x.y), expf(x.z), expf(x.w)); }

 f2  f2_exp2(f2 x) { return  f2_create(exp2f(x.x), exp2f(x.y)); }
 f3  f3_exp2(f3 x) { return  f3_create(exp2f(x.x), exp2f(x.y), exp2f(x.z)); }
 f4  f4_exp2(f4 x) { return  f4_create(exp2f(x.x), exp2f(x.y), exp2f(x.z), exp2f(x.w)); }

 f2  f2_fmod(f2 x, f2 y) { return  f2_create(fmodf(x.x,y.x), fmodf(x.y , y.y)); }
 f3  f3_fmod(f3 x, f3 y) { return  f3_create(fmodf(x.x, y.x), fmodf(x.y, y.y),fmodf(x.z, y.z)); }
 f4  f4_fmod(f4 x, f4 y) { return  f4_create(fmodf(x.x,y.x), fmodf(x.y,y.y), fmodf(x.z,y.z), fmodf(x.w,y.w)); }

f2 f2_reflect(f2 i, f2 n) { return f2_mul(f2_sub_s(i,2.0f),f2_mul_s(n,f2_dot(i,n))); }
f3 f3_reflect(f3 i, f3 n) { return f3_mul(f3_sub_s(i,2.0f),f3_mul_s(n,f3_dot(i,n))); }
f4 f4_reflect(f4 i, f4 n) { return f4_mul(f4_sub_s(i,2.0f),f4_mul_s(n,f4_dot(i,n))); }

f32  radians(f32 x) { return x * 0.0174532925f; }
f2  f2_radians(f2 x) { return f2_mul_s(x,0.0174532925f); }
f3  f3_radians(f3 x) { return f3_mul_s(x,0.0174532925f); }
f4  f4_radians(f4 x) { return f4_mul_s(x,0.0174532925f); }

f32  degrees(f32 x) { return x * 57.295779513f; }
f2  f2_degrees(f2 x) { return f2_mul_s(x,57.295779513f); }
f3  f3_degrees(f3 x) { return f3_mul_s(x,57.295779513f); }
f4  f4_degrees(f4 x) { return f4_mul_s(x,57.295779513f); }

f3x3 f3x3_identity()
{
    f3x3 r = {0};
    r.c0 = f3_create(1,0,0);
    r.c1 = f3_create(0,1,0);
    r.c2 = f3_create(0,0,1);
    return r;
}

f3x3 f3x3_create_zero()
{
    f3x3 r = {0};
    return r;
}

f3x3 f3x3_create_row(f32 a,f32 b,f32 c)
{
    f3x3 r = {0};
    r.c0 = f3_create(a,0,0);
    r.c1 = f3_create(0,b,0);
    r.c2 = f3_create(0,0,c);
    return r;    
}

f3x3 f3x3_create_vector(f3 a,f3 b,f3 c)
{
    f3x3 r = {0};
    r.c0 = a;
    r.c1 = b;
    r.c2 = c;
    return r;        
}

f3x3 f3x3_create(f32 m00, f32 m01, f32 m02,
                 f32 m10, f32 m11, f32 m12, 
                 f32 m20, f32 m21, f32 m22)
{
    f3x3 r = {0};
    r.c0 = f3_create(m00,m01,m02);
    r.c1 = f3_create(m10,m11,m12);
    r.c2 = f3_create(m20,m21,m22);
    return r;
}

f3x3 f3x3_create_from_quaternion(quaternion a)
{
    f3x3 r = {0};
    float x = a.x * 2.0f;
	float y = a.y * 2.0f;
	float z = a.z * 2.0f;
	float xx = a.x * x;
	float yy = a.y * y;
	float zz = a.z * z;
	float xy = a.x * y;
	float xz = a.x * z;
	float yz = a.y * z;
	float wx = a.w * x;
	float wy = a.w * y;
	float wz = a.w * z;

	r.c0 = f3_create(1.0f - (yy + zz), xy + wz, xz - wy);
	r.c1 = f3_create(xy - wz, 1.0f - (xx + zz), yz + wx);
	r.c2 = f3_create(xz + wy, yz - wx, 1.0f - (xx + yy));
    //Needed due to doing row major matrices.
    r = f3x3_transpose(r);
    return r;
}

f3x3 f3x3_transpose(f3x3 a)
{
	return f3x3_create(a.c0.x, a.c1.x, a.c2.x,
		               a.c0.y, a.c1.y, a.c2.y,
		               a.c0.z, a.c1.z, a.c2.z);
}

f3x3 f3x3_look_rotation(f3 forward, f3 up)
{
    const f32 epsilon = 0.000001F;
    f3 z = forward;
    // compute u0
    f32 mag = f3_length(z);
    if (mag < epsilon)
        return f3x3_identity();
    z = f3_div_s(z,mag);

    f3 x = cross(up, z);
    mag = f3_length(x);
    if (mag < epsilon)
        return f3x3_identity();
    x = f3_div_s(x,mag);

    f3 y = cross(z, x);
    f32 y_length = f3_length(y);
    if (y_length < 0.9F || y_length > 1.1F)
        return f3x3_identity();
    return f3x3_create_vector(x, y, z);    
}

f4x4 f4x4_identity()
{
    f4x4 r = {0};
    r.c0 = f4_create(1,0,0,0);
    r.c1 = f4_create(0,1,0,0);
    r.c2 = f4_create(0,0,1,0);
    r.c3 = f4_create(0,0,0,1);
    return r;
}

f4x4 f4x4_create_zero()
{
    f4x4 r = {0};
    return r;
}

f4x4 f4x4_create_row(f32 a,f32 b,f32 c,f32 d)
{
    f4x4 r = {0};
    r.c0 = f4_create(a,0,0,0);
    r.c1 = f4_create(0,b,0,0);
    r.c2 = f4_create(0,0,c,0);
    r.c3 = f4_create(0,0,0,d);    
    return r;    
}

f4x4 f4x4_create_vector(f4 a,f4 b,f4 c,f4 d)
{
    f4x4 r = {0};
    r.c0 = a;
    r.c1 = b;
    r.c2 = c;
    r.c3 = d;
    return r;        
}

f4x4 f4x4_create(f32 m00, f32 m01, f32 m02,f32 m03,
                 f32 m10, f32 m11, f32 m12,f32 m13, 
                 f32 m20, f32 m21, f32 m22,f32 m23,
                 f32 m30, f32 m31, f32 m32,f32 m33)
{
    f4x4 r = {0};
    r.c0 = f4_create(m00,m01,m02,m03);
    r.c1 = f4_create(m10,m11,m12,m13);
    r.c2 = f4_create(m20,m21,m22,m23);
    r.c3 = f4_create(m30,m31,m32,m33);    
    return r;
}

f4x4 f4x4_create_from_quaternion_translation(quaternion r,f3 t)
{
    f4x4 result = {0};
    f3x3 rot = f3x3_create_from_quaternion(r);
	rot = f3x3_transpose(rot);
	result.c0 = f4_create(rot.c0.x,rot.c0.y,rot.c0.z,0.0f);
    result.c1 = f4_create(rot.c1.x,rot.c1.y,rot.c1.z,0.0f);
	result.c2 = f4_create(rot.c2.x,rot.c2.y,rot.c2.z,0.0f);
    result.c3 = f4_create(t.x,t.y,t.z,1.0f);
    return result;
}

f4x4 f4x4_create_from_f3x3rotation_translation(f3x3 r,f3 t)
{
    f4x4 result = {0};
    result.c0 = f4_create(r.c0.x,r.c0.y,r.c0.z,0.0f);
    result.c1 = f4_create(r.c1.x,r.c1.y,r.c1.z,0.0f);
    result.c2 = f4_create(r.c2.x,r.c2.y,r.c2.z,0.0f);
    result.c3 = f4_create(t.x,t.y,t.z,1.0f);
    return result;
}

f4x4 f4x4_create_with_scale(f32 x, f32 y, f32 z)
{
    return f4x4_create(x,    0.0f, 0.0f, 0.0f,
                       0.0f, y,    0.0f, 0.0f,
                       0.0f, 0.0f, z,    0.0f,
                       0.0f, 0.0f, 0.0f, 1.0f);
}

f4x4 f4x4_create_with_translate(f3 a)
{
    return f4x4_create(1.0f,0.0f,0.0f,0.0f,
                       0.0f,1.0f,0.0f,0.0f,
                       0.0f,0.0f,1.0f,0.0f,
                       a.x,a.y,a.z,1.0f);
}

f4x4 f4x4_transpose(f4x4 a)
{
	return f4x4_create(a.c0.x, a.c1.x, a.c2.x, a.c3.x,
                       a.c0.y, a.c1.y, a.c2.y, a.c3.y,
                       a.c0.z, a.c1.z, a.c2.z, a.c3.z,
                       a.c0.w, a.c1.w, a.c2.w, a.c3.w);
}

f4x4 f4x4_mul(f4x4 a,f4x4 b)
{
	return f4x4_create_vector(
		f4_add(f4_add(f4_add(f4_mul_s(a.c0,b.c0.x),f4_mul_s(a.c1,b.c0.y)),f4_mul_s(a.c2,b.c0.z)),f4_mul_s(a.c3,b.c0.w)),
		f4_add(f4_add(f4_add(f4_mul_s(a.c0,b.c1.x),f4_mul_s(a.c1,b.c1.y)),f4_mul_s(a.c2,b.c1.z)),f4_mul_s(a.c3,b.c1.w)),
        f4_add(f4_add(f4_add(f4_mul_s(a.c0,b.c2.x),f4_mul_s(a.c1,b.c2.y)),f4_mul_s(a.c2,b.c2.z)),f4_mul_s(a.c3,b.c2.w)),
		f4_add(f4_add(f4_add(f4_mul_s(a.c0,b.c3.x),f4_mul_s(a.c1,b.c3.y)),f4_mul_s(a.c2,b.c3.z)),f4_mul_s(a.c3,b.c3.w)));
}

#if 0

//f4 f4x4_mul_f4(f4 a,f4x4 b);
f4 f4x4_mul_f4(f4x4 a,f4 b)
{
	return a.c0 * b.x() + a.c1 * b.y() + a.c2 * b.z() + a.c3 * b.w();
}

#endif


