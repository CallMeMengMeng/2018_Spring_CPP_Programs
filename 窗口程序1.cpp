#include<windows.h>

int WINAPI WinMain(
                   HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow
                  )
                   {
                      int nSelect = MessageBox(NULL,
                                               TEXT("��ã�����"),
                                                TEXT("�ҵĵ�һ�����ڳ���"),
                                                MB_OKCANCEL);
                      if(nSelect == IDOK)
                        {
                             MessageBox(NULL,
                                         TEXT("�����ˡ�ȷ������ť"),
                                         TEXT("��ʾ"),
                                         MB_OK);
                        }
                     else
                        {
                             MessageBox(NULL,
                                        TEXT("�����ˡ�ȡ������ť"),
                                         TEXT("��ʾ"),
                                         MB_OK);
                        }
                    return 0;
                  }
