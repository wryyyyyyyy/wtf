#include <Python.h>

int
main(int argc, char *argv[])
{
    Py_Initialize();
    FILE* f = _Py_fopen("main.py", "r+");
    PyRun_SimpleFile(f, "main.py");
	Py_Finalize();
    return 0;
}
