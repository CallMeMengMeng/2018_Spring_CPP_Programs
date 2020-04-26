#include<windows.h>

int WINAPI WinMain(
                   HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow
                  )
                   {
                      int nSelect = MessageBox(NULL,
                                               TEXT("你好，蒙蒙"),
                                                TEXT("我的第一个窗口程序"),
                                                MB_OKCANCEL);
                      if(nSelect == IDOK)
                        {
                             MessageBox(NULL,
                                         TEXT("你点击了“确定”按钮"),
                                         TEXT("提示"),
                                         MB_OK);
                        }
                     else
                        {
                             MessageBox(NULL,
                                        TEXT("你点击了“取消”按钮"),
                                         TEXT("提示"),
                                         MB_OK);
                        }
                    return 0;
                  }
