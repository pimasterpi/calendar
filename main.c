#include "events.h"

#include <stdio.h>

void adjust_time(time_struct_t *time);

void adjust_date(date_struct_t *date);

void adjust_date_time(date_time_struct_t *date_time);

void advanced_adjustment(date_time_struct_t *date_time);

int is_leap_year(int year);

int days_in_month(date_struct_t date);

void print_time(time_struct_t time);

void print_date(date_struct_t date);

void print_date_time(date_time_struct_t date_time);


int main() {
    date_time_struct_t test = {1900, 14, 29, 24, 60};


    print_time(test.time);
    print_date(test.date);
    print_date_time(test);

    adjust_date_time(&test);

    print_time(test.time);
    print_date(test.date);
    print_date_time(test);

    test = (date_time_struct_t) {1900, 14, 29, 24, 60};

    advanced_adjustment(&test);

    print_time(test.time);
    print_date(test.date);
    print_date_time(test);

    return 0;
}

void advanced_adjustment(date_time_struct_t *date_time) {
    while (date_time->time.minute >= 60) {
        date_time->time.minute -= 60;
        date_time->time.hour++;
    }

    while (date_time->time.hour >= 24) {
        date_time->time.hour -= 24;
        date_time->date.day++;
    }

    while ((date_time->date.day >= )) {

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


void print_time(time_struct_t time) {
    printf("%02d:%02d\n", time.hour, time.minute);
}

void print_date(date_struct_t date) {
    printf("%d/%02d/%02d\n", date.year, date.month, date.day);
}

void print_date_time(date_time_struct_t date_time) {
    printf("%d/%02d/%02d %02d:%02d\n", date_time.date.year, date_time.date.month, date_time.date.day,
           date_time.time.hour, date_time.time.minute);
}