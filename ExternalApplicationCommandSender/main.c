#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include <shlwapi.h>




BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam){

    char windowName[500] = {'\0'};
    char windowClassName[500] = {'\0'};
    GetClassName(hwnd, windowClassName, 500);
    GetWindowText(hwnd, windowName, 500);
    size_t windowNameSize = strlen(windowName);

    printf("Got handle for application %s (class name: %s)\n", windowName, windowClassName);

    
    if(strcmp(windowClassName, "MozillaWindowClass") == 0){
       int result = PostMessage(hwnd, WM_KEYDOWN, VK_F5, 0);
       printf("Sent message with result: %i \n", result);
    }


    return TRUE;
}


int main(){
    EnumWindows(EnumWindowsProc, 0);
    return 0;
}


