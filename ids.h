/* DO NOT MODIFY THIS FILE | NE MODIFIEZ PAS CE FICHIER */

#ifndef IDS_H_
#define IDS_H_

#include <stdbool.h>

#define MAX_LOG_LENGTH 4

extern const unsigned char HOME_NETWORK[2];

typedef enum { DENIAL, COMMAND, EXFIL } ThreatCategory;

typedef struct DETECTION {
	unsigned char source[4];
	unsigned char destination[4];
	ThreatCategory category;
	struct DETECTION *next;
	struct DETECTION *prev;
} Detection;

Detection *create_anchor();

Detection *get_next_detection();

void add_to(Detection *anchor, Detection *new);

void remove_oldest(Detection *anchor);

void erase_all(Detection *anchor);

int count_entries(Detection *anchor);

void print_entire(Detection *anchor);

void print_column_headings();

void print_anchor(Detection *anchor);

void print_one_detection(Detection *node);

#endif /* IDS_H_ */
