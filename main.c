#include "events.h"

#include <stdio.h>


int main() {
    date_time_struct_t test = {1999, 14, 29, 24, 60};


    print_time(test.time);
    print_date(test.date);
    print_date_time(test);

    adjust_date_time(&test);

    print_time(test.time);
    print_date(test.date);
    print_date_time(test);

    test = (date_time_struct_t) {1999, 14, 29, 24, 60};

    advanced_adjustment(&test);

    print_time(test.time);
    print_date(test.date);
    print_date_time(test);

    return 0;
}