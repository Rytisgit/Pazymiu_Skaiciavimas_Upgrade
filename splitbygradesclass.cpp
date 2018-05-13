//
// Created by SuperPC on 4/16/2018.
//

#include "splitbygradesclass.h"

const double studentClass::galBalas(double (*func)(std::vector<int> &, double))  {
    checkvector();
    auto a = ( func(pazymiai,1));
    return a;

}

std::ostream & operator<<(std::ostream &out,const studentClass &obj) {
    out<<obj.vardas<<" "<<obj.pavarde;
    for(int grade: obj.pazymiai){
        out<<" "<<grade;
    }
    return out<<"\n";
}

bool test(studentClass &Mok) {
    return Mok.galBalas() < 6;
}
bool surnamebinarypred(studentClass &a, studentClass &b) {
    return a.pavarde<b.pavarde;
}

bool namebinarypred(studentClass &a, studentClass &b) {
    return a.vardas<b.vardas;
}
bool gradebinarypred(studentClass &a, studentClass &b){
    return a.galBalas()<b.galBalas();
};
bool operator==(studentClass &a, studentClass &b){
    return a.getpavarde()==b.getpavarde()&&a.getvardas()==b.getvardas()&&a.galBalas()==b.galBalas();
}
