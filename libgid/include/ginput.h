#ifndef _GINPUT_H_
#define _GINPUT_H_

#include <stdlib.h>
#include <gglobal.h>
#include <gevent.h>

enum
{
	GINPUT_KEY_LEFT = 37,
	GINPUT_KEY_UP = 38,
	GINPUT_KEY_RIGHT = 39,
	GINPUT_KEY_DOWN = 40,

	GINPUT_KEY_0 = 0x30,
	GINPUT_KEY_1 = 0x31,
	GINPUT_KEY_2 = 0x32,
	GINPUT_KEY_3 = 0x33,
	GINPUT_KEY_4 = 0x34,
	GINPUT_KEY_5 = 0x35,
	GINPUT_KEY_6 = 0x36,
	GINPUT_KEY_7 = 0x37,
	GINPUT_KEY_8 = 0x38,
	GINPUT_KEY_9 = 0x39,

	GINPUT_KEY_A = 0x41,
	GINPUT_KEY_B = 0x42,
	GINPUT_KEY_C = 0x43,
	GINPUT_KEY_D = 0x44,
	GINPUT_KEY_E = 0x45,
	GINPUT_KEY_F = 0x46,
	GINPUT_KEY_G = 0x47,
	GINPUT_KEY_H = 0x48,
	GINPUT_KEY_I = 0x49,
	GINPUT_KEY_J = 0x4a,
	GINPUT_KEY_K = 0x4b,
	GINPUT_KEY_L = 0x4c,
	GINPUT_KEY_M = 0x4d,
	GINPUT_KEY_N = 0x4e,
	GINPUT_KEY_O = 0x4f,
	GINPUT_KEY_P = 0x50,
	GINPUT_KEY_Q = 0x51,
	GINPUT_KEY_R = 0x52,
	GINPUT_KEY_S = 0x53,
	GINPUT_KEY_T = 0x54,
	GINPUT_KEY_U = 0x55,
	GINPUT_KEY_V = 0x56,
	GINPUT_KEY_W = 0x57,
	GINPUT_KEY_X = 0x58,
	GINPUT_KEY_Y = 0x59,
	GINPUT_KEY_Z = 0x5a,

	GINPUT_KEY_BACK = 301,
	GINPUT_KEY_SEARCH = 302,
	GINPUT_KEY_MENU = 303,
	GINPUT_KEY_CENTER = 304,
	GINPUT_KEY_SELECT = 305,
	GINPUT_KEY_START = 306,
	GINPUT_KEY_L1 = 307,
	GINPUT_KEY_R1 = 308,

	GINPUT_KEY_SHIFT = 16,
	GINPUT_KEY_SPACE = 32,
	GINPUT_KEY_BACKSPACE = 8,

	GINPUT_KEY_CTRL = 17,
	GINPUT_KEY_ALT = 18,
	GINPUT_KEY_ESC = 27,
	GINPUT_KEY_TAB = 9,
	GINPUT_KEY_ENTER = 13,

	GINPUT_KEY_HOME = 400,
	GINPUT_KEY_END = 401,
	GINPUT_KEY_INSERT = 402,
	GINPUT_KEY_DELETE = 403,
	GINPUT_KEY_PAGEUP = 404,
	GINPUT_KEY_PAGEDOWN = 405,

	GINPUT_KEY_F1 = 501,
	GINPUT_KEY_F2 = 502,
	GINPUT_KEY_F3 = 503,
	GINPUT_KEY_F4 = 504,
	GINPUT_KEY_F5 = 505,
	GINPUT_KEY_F6 = 506,
	GINPUT_KEY_F7 = 507,
	GINPUT_KEY_F8 = 508,
	GINPUT_KEY_F9 = 509,
	GINPUT_KEY_F10 = 510,
	GINPUT_KEY_F11 = 511,
	GINPUT_KEY_F12 = 512,


    GINPUT_KEY_LAST,
};

enum
{
    GINPUT_NO_BUTTON = 0,
    GINPUT_LEFT_BUTTON = 1,
    GINPUT_RIGHT_BUTTON = 2,
    GINPUT_MIDDLE_BUTTON = 4,
};

enum
{
    GINPUT_NO_MODIFIER = 0,
    GINPUT_SHIFT_MODIFIER = 1,
    GINPUT_ALT_MODIFIER = 2,
    GINPUT_CTRL_MODIFIER = 4,
    GINPUT_META_MODIFIER = 8,
};

typedef struct ginput_MouseEvent
{
    int x, y;
    int button;
    int wheel;
    int modifiers;
} ginput_MouseEvent;

typedef struct ginput_Touch
{
    int x;
    int y;
    int id;
    float pressure;
    int touchType;
    int mouseButton;
    int modifiers;
} ginput_Touch;

typedef struct ginput_TouchEvent
{
    ginput_Touch touch;
    ginput_Touch *allTouches;
    size_t allTouchesCount;
} ginput_TouchEvent;

typedef struct ginput_KeyEvent
{
    int keyCode;
    int realCode;
    char charCode[16]; //UTF-8 sequence generated by this keyChar event, NUL terminated
} ginput_KeyEvent;

#ifdef __cplusplus
extern "C" {
#endif

G_API void ginput_init();
G_API void ginput_cleanup();

G_API int ginput_isAccelerometerAvailable();

// recursive
G_API void ginput_startAccelerometer();

// recursive
G_API void ginput_stopAccelerometer();

// if accelerometer is not running, returns 0
G_API void ginput_getAcceleration(double *x, double *y, double *z);



G_API int ginput_isGyroscopeAvailable();

// recursive
G_API void ginput_startGyroscope();

// recursive
G_API void ginput_stopGyroscope();

// if gyroscope is not running, returns 0
G_API void ginput_getGyroscopeRotationRate(double *x, double *y, double *z);

G_API void ginput_setMouseToTouchEnabled(int enabled);
G_API void ginput_setTouchToMouseEnabled(int enabled);
G_API void ginput_setMouseTouchOrder(int order);    // 0:first mouse then touch (default) 1:first touch then mouse

G_API g_id ginput_addCallback(gevent_Callback callback, void *udata);
G_API void ginput_removeCallback(gevent_Callback callback, void *udata);
G_API void ginput_removeCallbackWithGid(g_id gid);

#ifdef __cplusplus
}
#endif

#endif
