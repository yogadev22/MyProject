#include "patch/Includes.h"
#include "patch/MemoryPatch.h"
#include "patch/obfuscate.h"
#include "patch/Utils.h"
#include "patch/Macros.h"
#include <list>
#include <vector>
#include <string>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <jni.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include <chrono> 
#include <fcntl.h>
#include <sys/stat.h>
#include <cstddef>
#include <semaphore.h>
#include <stdint.h>
#include <sstream>
#include <stdarg.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef uint8_t  _BYTE;
typedef uint16_t _WORD;
typedef uint32_t _DWORD;
typedef uint64_t _QWORD;

uint64_t __fastcall hsub_218DE8(_QWORD *a1, _BYTE *a2, int a3, uint64_t a4)
{
    if (!a1) return 0LL;
    _BYTE local_buf[4] = {0};
    _BYTE *buf = a2 ? a2 : local_buf;
    unsigned long long pack_lo = (unsigned int)a3; 
    unsigned long long pack_hi = (unsigned long long)time(NULL);
    unsigned long long v10 = a1[3];
    unsigned long long v11 = a1[9];
    if (a3 == 99) {
        return 0LL;
    }
    if ( ((v11 > 1 && v11 <= (unsigned int)(a3 + 1)) || v11 > 3 || v10 == 0) && (v10 < 3) )
     {
        return 0LL;
    }
    return 0LL;
}

uint64_t (*oGetPlayerCharacterSafety)(uint64_t a1, uint64_t a2, uint64_t* a3);
uint64_t hGetPlayerCharacterSafety(uint64_t a1, uint64_t a2, uint64_t* a3)
{
    uint64_t v3 = *(_QWORD*)(a2 + 32);

    if (v3)
        ++v3;

    *(_QWORD*)(a2 + 32) = v3;

    *a3 = 0LL;

    return 0;
}

void *bypass_thread(void *) {
	do {
		sleep(1);
	} while (!isLibraryLoaded("libUE4.so"));
HOOK_LIB_NO_ORIG("libanogs.so", "0x213000", hsub_218DE8);//CRASHFIXER
PATCH_LIB("libUE4.so", "0x637157C", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so", "0x6371490", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so", "0x7CA7940", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so", "0xC8760B0", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so", "0xC875F70", "C0 03 5F D6");
HOOK_LIB("libUE4.so", "0x6C9C8FC", hGetPlayerCharacterSafety, oGetPlayerCharacterSafety);
PATCH_LIB("libanogs.so", "0x330494", "00 00 80 D2 C0 03 5F D6");//CRC calculation
PATCH_LIB("libanogs.so", "0x39F56C", "00 00 80 D2 C0 03 5F D6");//CRC-CHECK 2
	return NULL;
}

__attribute__((constructor)) void _bypass() {
        pthread_t t;
        pthread_create(&t, NULL, bypass_thread, NULL);
		//pthread_create(&t, NULL, ue4AM, NULL);
}
