// gcc -I/usr/lib/x86_64-linux-gnu/perl/5.26.1/CORE -L/usr/lib/x86_64-linux-gnu -s -O2 main.cpp -o embed_perl -lperl -lm -lpthread

#define PERL_NO_GET_CONTEXT
#include <EXTERN.h>
#include <perl.h>
#include "XSUB.h"

EXTERN_C void xs_init(pTHX);
EXTERN_C void boot_DynaLoader(pTHX_ CV* cv); // dynamically loading modules
//EXTERN_C void boot_Socket (pTHX_ CV* cv);  // or just one-per-line?
///EXTERN_C void bootWin32CORE(pTHX_ CV* cv); /// Win/MinGW ///

EXTERN_C void xs_init(pTHX) {
	static const char file[] = __FILE__;
	dXSUB_SYS;
	PERL_UNUSED_CONTEXT;
	
	newXS("DynaLoader::boot_DynaLoader", boot_DynaLoader, file); // well, dynamically
	//newXS("Socket::bootstrap", boot_Socket, file); // skipped
///	newXS("Win32CORE::bootstrap", boot_Win32CORE, file); /// Win/MinGW ///
}

static PerlInterpreter *my_perl;

int main(int argc, char **argv, char **env) {
	char *my_argv[] = {"", "main.pl"};
	PERL_SYS_INIT3(&argc, &argv, &env);
	my_perl = perl_alloc();
	perl_construct(my_perl);
	perl_parse(my_perl, xs_init, 2, my_argv, (char **)NULL);
	PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
	perl_run(my_perl);
	perl_destruct(my_perl);
	perl_free(my_perl);
	PERL_SYS_TERM();
}
