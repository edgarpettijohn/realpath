/*
 * Copyright (c) 2022 Edgar Pettijohn <edgar@pettijohn-web.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR 
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * cc -o realpath realpath.c && mv ./realpath ~/bin
 */

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int
main(int argc, char **argv)
{
	int ch;
	char resolved[PATH_MAX];

	while ((ch = getopt(argc, argv, "szhv")) != -1) {
		switch (ch) {
		case 's':
		case 'z':
		case 'h':
		case 'v':
		default:
			break;
		}
	}
	argc -= optind;
	argv += optind;

	if (argc != 1)
		return 1;

	if ((realpath(argv[0], resolved)) == NULL)
		return 1;

	printf("%s\n", resolved);

	return 0;
}
