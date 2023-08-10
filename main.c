#include "events.h"

#include <stdio.h>

int main() {
    date_time_t test = {2023, 8, 10, 11, 0};

    printf("%d/%d/%d %d:%02d", test.year, test.month, test.day, test.hour, test.minute);
    return 0;
}