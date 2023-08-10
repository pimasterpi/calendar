//
// Created by pimasterpi on 8/10/2023.
//

#ifndef CALENDAR_EVENTS_H
#define CALENDAR_EVENTS_H

#define JAN = 31;
#define FEB = 28;
#define MAR = 31;
#define APR = 30;
#define MAY = 31;
#define JUN = 30;
#define JUL = 31;
#define AUG = 31;
#define SEP = 30;
#define OCT = 31;
#define NOV = 30;
#define DEC = 31;

typedef struct date_time {
    int year;
    int month;
    int day;
    int hour;
    int minute;
} date_time_t;

typedef struct event {
    char * name;
    date_time_t start;
    date_time_t end;
} event_struct_t;

#endif //CALENDAR_EVENTS_H