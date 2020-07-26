/* DO NOT MODIFY THIS FILE | NE MODIFIEZ PAS CE FICHIER */

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "ids.h"

const unsigned char HOME_NETWORK[2] = { 137, 94 };

Detection *create_anchor() {
	Detection *a = (Detection *) malloc(sizeof(Detection));
	a->next = a;
	a->prev = a;
	return a;
}

Detection *get_next_detection() {
	static bool initialized = false;
	if (!initialized) {
		initialized = true;
		srand(time(0));
	}
	Detection *detection = (Detection *) malloc(sizeof(Detection));
	detection->category = rand() % 3;
	bool internal_destination = rand() % 2;
	for (int ix = 0; ix < 4; ix++) {
		if (ix < 2) {
			detection->source[ix] = HOME_NETWORK[ix];
		} else {
			detection->source[ix] = rand() % 256;
		}
		if (ix < 2 && internal_destination) {
			detection->destination[ix] = HOME_NETWORK[ix];
		} else {
			detection->destination[ix] = rand() % 256;
		}
	}
	return detection;
}

void print_column_headings() {
	printf("%-4s  %-4s  %-4s  %-15s   %-15s   %-25s\n", "ID", "Next", "Prev",
			"Source", "Destination", "Category");
	printf("----  ----  ----  ---------------"
			"   ---------------   -----------------------\n");
}

void last_4_of_ptr(void *p, char *buff) {
	char local_buffer[20];
	sprintf(local_buffer, "%p", p);
	strncpy(buff, local_buffer + strlen(local_buffer) - 4, 4);
	buff[4] = '\0';
}

void print_anchor(Detection *anchor) {
	char id[5], next[5], prev[5];
	last_4_of_ptr(anchor, id);
	last_4_of_ptr(anchor->next, next);
	last_4_of_ptr(anchor->prev, prev);
	printf("%4s  %4s  %4s  anchor\n", id, next, prev);
}

void print_one_detection(Detection *node) {
	const char *category_names[3] = { "Denial of service",
			"Malware command channel", "Data exfiltration" };
	const char *format = "%4s  %4s  %4s  %d.%3d.%3d.%3d   %3d.%3d.%3d.%3d   %s\n";
	char id[5], next[5], prev[5];
	last_4_of_ptr(node, id);
	last_4_of_ptr(node->next, next);
	last_4_of_ptr(node->prev, prev);
	printf(format, id, next, prev, node->source[0], node->source[1], node->source[2],
			node->source[3], node->destination[0], node->destination[1],
			node->destination[2], node->destination[3],
			category_names[node->category]);
}

