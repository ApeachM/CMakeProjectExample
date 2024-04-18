#include <iostream>
#include <tcl/tcl.h>
#include "myFunction.h"

void myFunctionLibTest() {
    std::cout << "Addition of 5 and 3 is " << add(5, 3) << std::endl;
}

int tclTest() {
    Tcl_Interp *interp = Tcl_CreateInterp(); // Tcl 인터프리터 생성
    if (Tcl_Init(interp) == TCL_ERROR) { // Tcl 인터프리터 초기화
        std::cerr << "Tcl_Init failed: " << Tcl_GetStringResult(interp) << std::endl;
        return -1;
    }

    // Tcl 스크립트 실행
    const char *script =
            "set result [expr {5 + 3}]\n"
            "puts \"The result is $result\""; // 5 + 3을 계산하고 결과를 출력하는 Tcl 스크립트

    if (Tcl_Eval(interp, script) == TCL_ERROR) {
        std::cerr << "Tcl_Eval failed: " << Tcl_GetStringResult(interp) << std::endl;
        return -1;
    }

    // Tcl 스크립트 실행 결과를 가져옴
    const char *result = Tcl_GetStringResult(interp);
    std::cout << "Tcl script result: " << result << std::endl;

    Tcl_DeleteInterp(interp); // Tcl 인터프리터 제거
    Tcl_Finalize(); // Tcl 라이브러리 정리
    return 0;
}

int main() {
    myFunctionLibTest();
    return tclTest();
}
