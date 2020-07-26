/* YOUR NAME HERE | VOTRE NOM ICI */

#include "ids.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	Detection *log = create_anchor();
    for (int m=0; m<20; m++){
        Detection *new = get_next_detection();
        print_one_detection(new);
        add_to( log, new );
        print_entire(log);
    }

    //print_entire(log);
    //remove_oldest(log);
    //print_entire(log);
    erase_all(log);
    print_entire(log);
	return EXIT_SUCCESS;

}
void add_to(Detection *log, Detection *new)
        //void add_to(Detection *log, Detection *new)
{
    if (count_entries(log)== MAX_LOG_LENGTH) {
        remove_oldest(log);
        //print_entire(log);
    }
    //printf("0 new->next %d new->prev %d log->next %d log->prev %d log %d \n", new->next, new->prev, log->next, log->prev,log);
    new->next = log->next;
    new->prev = log;
    log->next = new;
    //printf("00 new->next %d new->prev %d log->next %d log->prev %d log %d \n", new->next, new->prev, log->next, log->prev,log);
    //printf("01 new->next %d new->prev %d log->next %d \n", new->next, new->prev, log->next);
    if ( log->prev==log) {
       // printf("1 log->prev %d log %d new %d \n", log->prev, log, new);
        log->prev=new;
       // printf("11 log->prev %d log %d new %d \n", log->prev, log, new);
    }
    else {
        //printf("2 log->prev %d log %d new %d log->next->prev %d \n", log->prev, log, new, log->next->prev);
        log->next->next->prev=new;
       // printf("21 log->prev %d log %d new %d log->next->prev %d \n", log->prev, log, new, log->next->prev);
    }

   // print_entire(log);

}

void remove_oldest(Detection *anchor) {
    if (anchor == NULL){
        //printf("00 anchor->next %d anchor->prev %d anchor %d \n",  anchor->next, anchor->prev,anchor);
        return;
    }

    Detection * counter = anchor;
    Detection * back = NULL;
    if ( counter->next == anchor) {
       // printf("10 counter->next %d anchor->next %d anchor->prev %d anchor %d \n", counter->next, anchor->next, anchor->prev,anchor);
        //printf("11 anchor->next %d anchor->prev %d anchor %d \n",  anchor->next, anchor->prev,anchor);
        return;
    }
    while ( counter->next->next!=anchor) {
        counter=counter->next;
        //printf("counter->next %d anchor %d sum %d \n", counter->next, anchor, sum);
    }
    //printf("20 anchor->next %d anchor->prev %d anchor %d \n",  anchor->next, anchor->prev,anchor);
    back=counter->next;
    counter->next=anchor;
    anchor->prev=counter;
    free(back);
    back = NULL;

     //   free(counter);
    //printf("21 anchor->next %d anchor->prev %d anchor %d \n",  anchor->next, anchor->prev,anchor);
        // FollowWaypoints(head);


	// to complete | a completer
}

void erase_all(Detection *anchor) {

    //printf("sum %d \n", sum);
    while  (count_entries(anchor)>1){
        remove_oldest(anchor);
        // print_entire(anchor);
    }
    //print_anchor(anchor);
    // to complete | a completer
    return;
        //printf("counter->next %d anchor %d sum %d \n", counter->next, anchor, sum);

	// to complete | a completer
}


int count_entries(Detection *anchor) {
	// to complete | a completer
	Detection * counter = anchor;
	int sum=1;
	while ( counter->next!=anchor) {
	   sum=sum+1;
	   counter=counter->next;
	 //printf("counter->next %d anchor %d sum %d \n", counter->next, anchor, sum);
	}

	return sum;
}


void print_entire(Detection *anchor) {
    Detection *cursor = anchor;
	print_column_headings(cursor);
	int sum=count_entries(cursor);
    //printf("sum %d \n", sum);
    for (int i=0; i < sum; i++ ){
        print_anchor(cursor);
        cursor=cursor->next;
    }
	//print_anchor(anchor);
	// to complete | a completer
    return;
}
