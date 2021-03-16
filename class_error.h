#ifndef LAB_02_CLASS_ERROR_H
#define LAB_02_CLASS_ERROR_H
#include <string>

enum TypeErrors {INPUT_FILE_ERROR, OUTPUT_FILE_ERROR};

class ErrorHandler{
private:
    std::string err {};
public:
    ErrorHandler(const TypeErrors& incoming_error) {
        switch (incoming_error) {
            case INPUT_FILE_ERROR:
                err = " <ERROR> Ошибка записи в файл";
                break;
            case OUTPUT_FILE_ERROR:
                err = " <ERROR> Ошибка чтения из файла";
                break;
            default:
                err = " <<ERROR> Unknown type of error";
                break;
        }
    }
    ~ErrorHandler() = default;

    std::string print_error (){
        return  err;
    }

};

#endif //LAB_02_CLASS_ERROR_H
