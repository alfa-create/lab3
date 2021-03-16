#include <iostream>
#include "first_task.h"
#include "class_error.h"
#include "second_task.h"

int main() {
    first_task ss;
    ss.writer();

    hospital_base ss2("patients");
    ss2.foreign_pat();
    ss2.find_pat(12,"Corona");
        //ss2.randGen("patients", 15);



    return 0;
}
