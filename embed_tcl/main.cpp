//gcc -I/usr/include/tcl8.6 -L/usr/lib/x86_64-linux-gnu -ltcl8.6 -lpthread -ldl -lutil -lm main.cpp -o embed_tcl

#include <cstdlib>
#include <tcl.h>

Tcl_Interp *interp;

int ExtendTcl (Tcl_Interp *interp) {
    return TCL_OK;
}

int main (int argc ,char *argv[]) {
    Tcl_FindExecutable(argv[0]);
    interp = Tcl_CreateInterp();
    
    if ((Tcl_Init(interp) || ExtendTcl(interp)) != TCL_OK) {
		fprintf(stderr ,"Tcl_Init error: %s\n" ,Tcl_GetStringResult(interp));
        return EXIT_FAILURE;
    }
    
    Tcl_EvalFile(interp, "main.tcl");
    
    Tcl_Finalize();
    return 0;
}
