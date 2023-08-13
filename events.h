//
// Created by pimasterpi on 8/10/2023.
//

#ifndef CALENDAR_EVENTS_H
#define CALENDAR_EVENTS_H


typedef struct time_struct {
    int hour;
    int minute;
} time_struct_t;

typedef struct date_struct {
    int year;
    int month;
    int day;
} date_struct_t;

typedef struct date_time_struct {
    date_struct_t date;
    time_struct_t time;
} date_time_struct_t;

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

#endif //CALENDAR_EVENTS_H