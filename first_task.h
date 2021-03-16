#ifndef LAB_03_FIRST_TASK_H
#define LAB_03_FIRST_TASK_H
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "class_error.h"


using namespace std;

class first_task{
public:
    explicit first_task();
    ~first_task() = default;
    void writer ();
};

first_task::first_task() {
    ofstream file ("f");

    if (!file) throw INPUT_FILE_ERROR;

    srand(time(NULL));
    for (int i = 0; i < 101; i++){
        file << rand() % 100 - 50 << endl;
    }
}

void first_task::writer() {
    ifstream in_file ("f");
    ofstream out_file ("g");

    if (!in_file) throw OUTPUT_FILE_ERROR;
    else if (!out_file) throw INPUT_FILE_ERROR;

    vector<int> nums;

    while (in_file){
        char buf[5];

        in_file.getline(buf, 5);

        if (nums.size() == 0){
            out_file << buf << endl;
            nums.push_back(atoi(buf));
        }

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == atoi(buf)) break;

            if (i == nums.size() - 1)  {
                out_file << buf << endl;
                nums.push_back(atoi(buf));
            }
        }
    }


}

#endif //LAB_03_FIRST_TASK_H

