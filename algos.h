#ifndef ALGOS_H
#define ALGOS_H

#include <string.h>
#include "compat.h"

enum sha_algos {
	ALGO_KECCAK,
	ALGO_SHA256D,
	ALGO_AUTO,
	ALGO_COUNT
};

extern volatile enum sha_algos opt_algo;

static const char *algo_names[] = {
	"keccak",
	"sha256d",
	"auto", /* reserved for multi algo */
	""
};

// string to int/enum
static inline int algo_to_int(char* arg)
{
	int i;

	for (i = 0; i < ALGO_COUNT; i++) {
		if (algo_names[i] && !strcasecmp(arg, algo_names[i])) {
			return i;
		}
	}

	if (i == ALGO_COUNT) {
		// some aliases...
		if (!strcasecmp("all", arg))
			i = ALGO_AUTO;
		else if (!strcasecmp("bitcoin", arg))
			i = ALGO_SHA256D;
		else if (!strcasecmp("sha256", arg))
			i = ALGO_SHA256D;
		else
			i = -1;
	}

	return i;
}

#endif
