#ifndef LAB_03_SECOND_TASK_H
#define LAB_03_SECOND_TASK_H
#include "class_error.h"
#include <cstdlib>
#include <ctime>
#include <vector>

struct patient{
    string last_name;
    string gender;
    int age;
    string city;
    string diagnosis;

    friend std::ostream& operator<< (std::ostream &out, const patient pt){
        out << pt.last_name << " ";
        out << pt.gender << " ";
        out << pt.age << " ";
        out << pt.city << " ";
        out << pt.diagnosis << endl;

        return out;
    }
};



class hospital_base{

private:
    std::vector<patient> base;

public:
    hospital_base() = default;
    explicit hospital_base(string file_name);
    ~hospital_base()= default;
    int foreign_pat();
    void find_pat(int age, string diagnosis);

    void randGen (const string& name_file, size_t size);

    friend std::istream& operator>> (std::istream &in, hospital_base &hb){
        patient pat;
        cout << "\nEnter last name:";
        in >> pat.last_name;
        cout << "\nEnter gender (m/w):";
        in >> pat.gender;
        cout << "\nEnter age:";
        in >> pat.age;
        cout << "\nEnter city:";
        in >> pat.city;
        cout << "\nEnter diagnosis:";
        in >> pat.diagnosis;
        hb.base.push_back(pat);

        return in;
    }

    friend std::ostream& operator<< (std::ostream &out, const hospital_base hb){
        for (const auto & i : hb.base){
            out << i;
        }
        return out;
    }
};

void hospital_base::randGen(const string& name_file, size_t size) {
    ofstream file (name_file);

    if (!file) throw INPUT_FILE_ERROR;

    srand(time(NULL));
    string str;

    while (size){
        //last name
        switch(rand()% 3 ){
            case 1:
                str = "Pupkin ";
                break;
            case 2:
                str = "Putin ";
                break;
            case 3:
                str = "Ivanov ";
                break;
            default:
                str = "Kiselev ";
        }
        //gender
        switch(rand()% 2 ){
            case 1:
                str+= "m ";
                break;
            default:
                str+= "w ";
                break;
        }
        //age
        str+= to_string(rand()% 69 + 3 );

        //city
        switch(rand()% 3 ){
            case 1:
                str+= " Moscow ";
                break;
            case 2:
                str+= " Vladimir ";
                break;
            case 3:
                str+= " Dubai ";
                break;
            default:
                str+= " Kineshma ";
        }
        //diagnosis
        switch(rand()% 3 ){
            case 1:
                str+= "ORV";
                break;
            case 2:
                str+= "Corona";
                break;
            case 3:
                str+= "Speed";
                break;
            default:
                str +="Syphilis";
        }
        file << str << endl;
        size--;
    }
}

hospital_base::hospital_base( string file_name) {
    ifstream file (file_name);

    if (!file) throw OUTPUT_FILE_ERROR;

    while (file){
        char buf[80];
        string str,str2;

        file.getline(buf,80);
        str = buf;
        if (str.size() == 0) break;

        patient pat;

        auto index = str.find(' ');
        pat.last_name = str2.assign(str,0,index);
        str.erase(0,index + 1);

        pat.gender = str2.assign(str,0,1);
        str.erase(0,2);

        index = str.find(' ');
        pat.age = stoi(str2.assign(str,0,index));
        str.erase(0,index + 1);

        index = str.find(' ');
        pat.city = str2.assign(str,0,index);
        str.erase(0,index + 1);

        pat.diagnosis = str2.assign(str,0,str.size());

        base.push_back(pat);
    }
}

int hospital_base::foreign_pat() {
    int count = 0;
    for (auto & i : base){
        if (i.city != "Vladimir") count++;
    }
    cout << "Hospital has " << count;
    cout << " foreign patients" << endl;
    return count;
}

void hospital_base::find_pat(int age, string diagnosis) {
    cout << "With " << diagnosis << " and older " << age;
    cout << " years patients:" << endl;
    for (auto & i : base){
        if ((i.age > age)&&(i.diagnosis == diagnosis)) {
            cout << (i.last_name) << endl;
        }
    }
}


#endif //LAB_03_SECOND_TASK_H
