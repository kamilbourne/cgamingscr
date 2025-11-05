/*                PL                                                                  Eng
Wygaszacz ekranu napisany dla Ciotusza Gaming Association       Screensaver written for Ciotusza Gaming Association
Autorzy: K. Nowak, R. Michałuszko.                              Authors: K. Nowak, R. Michaluszko
Wszelkie prawa niezastrzeżone                                   All Rights not reserved */
#include <windows.h>
#include <scrnsave.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <math.h>

//Global Var
HINSTANCE g_hInst;
HWND g_hWnd;

BOOL ScreenSaverInit(HWND hWnd)
{
  g_hWnd = hWnd;
  SetTimer(hWnd, 1, 100, NULL); //Timer every 100 ms
  return TRUE;
}

LRESULT WINAPI ScreenSaverProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  switch (message)
  {
    case WM_CREATE:
      ScreenSaverInit(hWnd);
      break;

    case WM_ERASEBKGND:
      return TRUE;

    case WM_TIMER:
      InvalidateRect(hWnd, NULL, TRUE);
      break;
    case WM_PAINT:
      {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        //Drawing Code
        RECT rect; 
        GetClientRect(hWnd, &rect);
        FillRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
        EndPaint(hWnd, &ps);
        break;
      }
    case WM_DESTROY:
      //Clearing
      KillTimer(hWnd, 1);
      break;
  }
  //Handling the inputs
  return DefScreenSaverProc(hWnd, message, wParam, lParam);
}

// Config Window:
BOOL WINAPI ScreenSaverConfigureDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
  return DefDlgProc(hDlg, message, wParam, lParam);
}

//Register Window Class
BOOL WINAPI RegisterDialogClasses(HANDLE hInst)
{
  return TRUE;
}
