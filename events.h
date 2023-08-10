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
    char * name;
    date_time_struct_t start;
    date_time_struct_t end;
} event_struct_t;



#endif //CALENDAR_EVENTS_H