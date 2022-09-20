#include "fmj_types.h"
#include <stdbool.h>

#ifdef WINDOWS
#include <windows.h>
#endif

typedef struct{
	void* ptr;
}FMJWindowHandle; 

typedef struct{
	FMJWindowHandle window; 
	bool is_running; 
}FMJApp;

FMJApp fmj_app_create(){
	FMJApp result = {0};

#ifdef WINDOWS
	WNDCLASSEXA wc = {0};
	wc.cbSize = sizeof(WNDCLASSEXA);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = DefWindowProcA;
	wc.hInstance = GetModuleHandleA(NULL);
	wc.lpszClassName = "FMJWindowClass";

	if (RegisterClassExA(&wc)){
		HWND hr = CreateWindowEx(0, "STATIC", "FMJ", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, NULL, NULL);
		result.window.ptr = hr;
		int ErrorCode = GetLastError();
		if (ErrorCode != 0){
			printf("Error: %d", ErrorCode);
		}
		 ShowWindow(hr,SW_SHOWNORMAL);
	}
#elif DARWIN
#elif LINUX
#endif
	return result;
}

#ifdef WINDOWS
void fmj_app_handle_windows_messages(FMJApp* app){
    MSG message;
    while(PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
    {
        if(message.message == WM_QUIT)
        {
            app->is_running = false;
        }
        TranslateMessage(&message);
        DispatchMessageA(&message);
    }
}
#endif

void fmj_app_update(FMJApp* app){
	// Update the app
#ifdef WINDOWS
	fmj_app_handle_windows_messages(app);
#endif
}

