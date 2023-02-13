#include <Windows.h>
#include <Psapi.h>
#include <TlHelp32.h>
#include <string.h>

int anticheat()
{
    PROCESSENTRY32 pe32 = { sizeof(PROCESSENTRY32) };
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnapshot == INVALID_HANDLE_VALUE)
        return FALSE;
    if (Process32First(hSnapshot, &pe32)) {
        do {
            if (strstr(pe32.szExeFile, "cheatengine") != NULL) {
                CloseHandle(hSnapshot);
                return TRUE;
            }
        } while (Process32Next(hSnapshot, &pe32));
    }
    CloseHandle(hSnapshot);
    return FALSE;
}