#include "events.h"

#include <stdio.h>

void print_time(time_struct_t time);
void print_date(date_struct_t date);
void print_date_time(date_time_struct_t date_time);



int main() {
    date_time_struct_t test = {2023, 8, 10, 11, 0};


    print_time(test.time);
    print_date(test.date);
    print_date_time(test);
    return 0;
}



void print_time(time_struct_t time) {
    printf("%d:%02d\n", time.hour, time.minute);
}

void print_date(date_struct_t date) {
    printf("%d/%02d/%d\n", date.year, date.month, date.day);
}

void print_date_time(date_time_struct_t date_time) {
    printf("%d/%02d/%d %d:%02d\n", date_time.date.year, date_time.date.month, date_time.date.day, date_time.time.hour, date_time.time.minute);
}