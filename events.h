//
// Last Modified by pimasterpi on 8/15/2023.
//

#include "date_time.h"

#ifndef CALENDAR_EVENTS_H
#define CALENDAR_EVENTS_H

typedef struct event {
    char *name;
    date_time_struct_t start;
    date_time_struct_t end;
} event_t;

typedef struct event_list {
    event_t event_info;
    struct event_list *prev;
    struct event_list *next;
} event_list_t;

typedef struct event_tree {
    event_t event_info;
    struct event_list *left;
    struct event_list *right;
} event_tree_t;

#endif //CALENDAR_EVENTS_H