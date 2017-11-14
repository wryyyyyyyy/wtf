//gcc -I/usr/lib/x86_64-linux-gnu/perl/5.26.1/CORE -L/usr/lib/x86_64-linux-gnu -s -O2 main.cpp -o embed_perl -lperl -lm

#include <EXTERN.h>
#include <perl.h>

static PerlInterpreter *my_perl;

int main(int argc, char **argv, char **env) {
	char *my_argv[] = {"", "main.pl"};
	PERL_SYS_INIT3(&argc, &argv, &env);
	my_perl = perl_alloc();
	perl_construct(my_perl);
	perl_parse(my_perl, NULL, 2, my_argv, (char **)NULL);
	PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
	perl_run(my_perl);
	perl_destruct(my_perl);
	perl_free(my_perl);
	PERL_SYS_TERM();
}
