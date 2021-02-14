#include "Header.h"
#include "FTP.h"


#include <process.h>

void d() {
    for (int i = 0; i < 100; i++) {
        Sleep(500);
        puts("its b");
    }
}
void b() {
    for (int i = 0; i < 100; i++) {
        Sleep(500);
        puts("its c");
    }
  
}

void main() {
    FTP_RUN();
    // 실행시킬 함수 이름, 스레드 스택 메모리 크기, 스레드 매개변수
    //int num = _beginthread(d, 0, NULL);
    //int ber = _beginthread(b, 0, NULL);
    //printf("%d %d\n", num, ber);
    //getchar();
	d();

    

    return 909;
}