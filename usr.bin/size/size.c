/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * %sccs.include.redist.c%
 */

#ifndef lint
char copyright[] =
"@(#) Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "@(#)size.c	4.7 (Berkeley) 06/01/90";
#endif /* not lint */

#include <sys/param.h>
#include <sys/file.h>
#include <a.out.h>
#include <stdio.h>

main(argc, argv)
	int argc;
	char **argv;
{
	struct exec head;
	u_long total;
	int exval, fd, first;

	if (!*argv[1])
		*argv = "a.out";
	else
		++argv;
	for (first = 1, exval = 0; *argv; ++argv) {
		if ((fd = open(*argv, O_RDONLY, 0)) < 0) {
			fprintf(stderr, "size: ");
			perror(*argv);
			exval = 1;
			continue;
		}
		if (read(fd, (char *)&head, sizeof(head)) != sizeof(head) ||
		    N_BADMAG(head)) {
			fprintf(stderr, "size: %s: not in a.out format.\n",
			    *argv);
			exval = 1;
			continue;
		}
		(void)close(fd);
		if (first) {
			first = 0;
			printf("text\tdata\tbss\tdec\thex\n");
		}
		total = head.a_text + head.a_data + head.a_bss;
		printf("%lu\t%lu\t%lu\t%lu\t%lx", head.a_text, head.a_data,
		    head.a_bss, total, total);
		if (argc > 2)
			printf("\t%s", *argv);
		printf("\n");
	}
	exit(exval);
}
