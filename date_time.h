//
// Last Modified by pimasterpi on 8/15/2023.
//

#include <stdio.h>
#include <time.h>

#ifndef CALENDAR_DATE_TIME_H
#define CALENDAR_DATE_TIME_H

typedef struct time_struct {
    int hour;
    long long minute;
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



void adjust_time(time_struct_t *time);
void adjust_date(date_struct_t *date);
void adjust_date_time(date_time_struct_t *date_time);
void advanced_adjustment(date_time_struct_t *date_time);

int is_leap_year(int year);
int days_in_month(date_struct_t date);
date_time_struct_t current_time();

void print_time(time_struct_t time);
void print_date(date_struct_t date);
void print_date_time(date_time_struct_t date_time);



void advanced_adjustment(date_time_struct_t *date_time) {
    while (date_time->time.minute >= 60) {
        date_time->time.minute -= 60;
        date_time->time.hour++;
    }

    while (date_time->time.hour >= 24) {
        date_time->time.hour -= 24;
        date_time->date.day++;
    }

    while (date_time->date.month > 12) {
        date_time->date.month -= 12;
        date_time->date.year++;
    }

    while (date_time->date.day > days_in_month(date_time->date)) {
        date_time->date.day -= days_in_month(date_time->date);
        date_time->date.month++;
        if (date_time->date.month > 12) {
            date_time->date.month -= 12;
            date_time->date.year++;
        }
    }
}

void adjust_time(time_struct_t *time) {
    time->hour = time->hour % 24;
    time->minute = time->minute % 60;
}

void adjust_date(date_struct_t *date) {

    date->month = date->month % 12;

    if (!(date->month % 12)) {
        date->month += 12;
    }


    int days = days_in_month(*date);

    date->day = date->day % days;
}

void adjust_date_time(date_time_struct_t *date_time) {
    adjust_time(&date_time->time);
    adjust_date(&date_time->date);
}

int is_leap_year(int year) {
    if (!(year % 100)) {
        if (!(year % 400)) {
            return 1;
        } else {
            return 0;
        }
    } else if (!(year % 4)) {
        return 1;
    } else {
        return 0;
    }
}

int days_in_month(date_struct_t date) {
    switch (date.month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: {
            return 31;
        }
        case 4:
        case 6:
        case 9:
        case 11: {
            return 30;
        }
        case 2: {
            return (is_leap_year(date.year)) ? 29 : 28;
        }
    }
}

date_time_struct_t current_time() {
    date_time_struct_t current_time = {1970, 1, 1, 0,0};

    time_t seconds = time(NULL);

    current_time.time.minute = seconds / 60;

    advanced_adjustment(&current_time);

    return current_time;
}

void print_time(time_struct_t time) {
    printf("%02d:%02lld\n", time.hour, time.minute);
}

void print_date(date_struct_t date) {
    printf("%d/%02d/%02d\n", date.year, date.month, date.day);
}

void print_date_time(date_time_struct_t date_time) {
    printf("%d/%02d/%02d %02d:%02lld\n", date_time.date.year, date_time.date.month, date_time.date.day,
           date_time.time.hour, date_time.time.minute);
}

#endif //CALENDAR_DATE_TIME_H
