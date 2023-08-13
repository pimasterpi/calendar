#include "events.h"

#include <stdio.h>

void adjust_time(time_struct_t *time);
void adjust_date(date_struct_t *date);
void adjust_date_time(date_time_struct_t *date_time);
int is_leap_year(int year);

void print_time(time_struct_t time);
void print_date(date_struct_t date);
void print_date_time(date_time_struct_t date_time);


int main() {
    date_time_struct_t test = {2023, 2, 29, 24, 0};


    print_time(test.time);
    print_date(test.date);
    print_date_time(test);

    adjust_date_time(&test);

    print_time(test.time);
    print_date(test.date);
    print_date_time(test);


    return 0;
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


    if (((date->month < 8) && (date->month % 2)) || ((date->month >= 8) && !(date->month % 2))) {
        date->day = date->day % 31;

        if (!(date->day % 31)) {
            date->day += 31;
        }
    }
    else if (date->month == 2) {
        if (is_leap_year(date->year)) {
            date->day = date->day % 29;

            if (!(date->day % 29)) {
                date->day += 29;
            }
        }
        else {
            date->day = date->day % 28;

            if (!(date->day % 28)) {
                date->day += 28;
            }
        }
    }
    else {
        date->day = date->day % 30;

        if (!(date->day % 30)) {
            date->day += 30;
        }
    }
}

void adjust_date_time(date_time_struct_t *date_time) {
    adjust_time(&date_time->time);
    adjust_date(&date_time->date);
}

int is_leap_year(int year) {
    if (!(year % 100)) {
        if (!(year % 4)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (!(year % 4)) {
        return 1;
    }
    else {
        return 0;
    }

}


void print_time(time_struct_t time) {
    printf("%02d:%02d\n", time.hour, time.minute);
}

void print_date(date_struct_t date) {
    printf("%d/%02d/%02d\n", date.year, date.month, date.day);
}

void print_date_time(date_time_struct_t date_time) {
    printf("%d/%02d/%02d %02d:%02d\n", date_time.date.year, date_time.date.month, date_time.date.day, date_time.time.hour, date_time.time.minute);
}