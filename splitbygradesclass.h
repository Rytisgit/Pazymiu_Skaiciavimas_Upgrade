//
// Created by SuperPC on 4/16/2018.
//

#ifndef PAZYMIAI_SPLITBYGRADESCLASS_H
#define PAZYMIAI_SPLITBYGRADESCLASS_H


#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "calculation.h"
/*!
 * Class for a Student keeps a students name, surname, grades
 * @pavarde a students surname
 * @vardas a students name
 * @pazymiai a students marks in a vector of ints
 */
class studentClass{
    /// a students name
    std::string pavarde;
    std::string vardas;
    std::vector<int> pazymiai;
    void checkvector()const {if(pazymiai.empty())throw std::invalid_argument("this doesnt have a vector");}
public:
    /// Full student with marks
    /// \param pav surname
    /// \param var name
    /// \param vec vector of ints with marks
    studentClass( std::string pav,  std::string var, std::vector<int> vec ) : pavarde(pav),vardas(var),pazymiai(vec){}
    /// Constructor for faster student without marks
    /// \param pav surname
    /// \param var name
    studentClass( std::string pav,  std::string var) : pavarde(pav),vardas(var){}
    ///Destructor, deletes vector
    ~studentClass(){std::vector<int>().swap(pazymiai);}
    /// surname getter
    /// \return surname
    std::string getpavarde()const { return pavarde;}
    /// name gettter
    /// \return name
    std::string getvardas()const { return vardas;}
/// Calculates a final mark based on a students previous marks
/// \param func specifies which function to call to use in calculating the final mark
/// \return return the final mark as a double
    const double galBalas  ( double (*func) (std::vector<int>&,double )= weightedaverage);
/// output name surname and marks if there are any into and std::ostream
/// \param out output stream
/// \return new outsput stream position
    friend std::ostream & operator<<(std::ostream &out,const studentClass &obj);
/// predicate for comparing by surname
/// \param a first class
/// \param b second class
/// \return if a's surname is < than b's surname
    friend bool surnamebinarypred(studentClass &a, studentClass &b);
/// predicate for comparing by name
/// \param a first class
/// \param b second class
/// \return if a's name is < than b's name
    friend bool namebinarypred(studentClass &a, studentClass &b);
};
/// predicate for splitting an array of students by their marks
/// \param Mok an instance of student class with the array filled
/// \return return true or false on whether a student passes
bool test(studentClass &Mok);
/// predicate for comparing by grade
/// \param a first class
/// \param b second class
/// \return if a's final grade is < than b's final grade
bool gradebinarypred(studentClass &a, studentClass &b);
/// Checks if two students data is equal
/// \param a first class
/// \param b second class
/// \return true if name surname and final grade is equal otherwise false
bool operator==(studentClass &a, studentClass &b){
    return a.getpavarde()==b.getpavarde()&&a.getvardas()==b.getvardas()&&a.galBalas()==b.galBalas();
}

#endif //PAZYMIAI_SPLITBYGRADESCLASS_H
