//gcc -I/usr/include/python3.6m -L/usr/lib/x86_64-linux-gnu -lpython3.6m -lpthread -ldl -lutil -lm main.cpp -o embed_python

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
