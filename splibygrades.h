//
// Created by SuperPC on 3/19/2018.
//

#ifndef PAZYMIAI_SPLIBYGRADES_H
#define PAZYMIAI_SPLIBYGRADES_H

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <regex>
#include <chrono>

#include "splitbygradesclass.h"

/// Timer is a struct for timing purposes, uses std::chrono and outputs the time between its constructor and destructor
/// being called
struct Timer{
    using clock = std::chrono::steady_clock;
    std::chrono::time_point<clock> start,end;
    Timer(){
        /// starts timing in constructor
        start = clock::now();
    }
    ~Timer(){
        ///outputs time since constructor in destructor
        end =  clock::now();
        std::cout<<(double)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()/1000000000<<" ";
    }
};
/// Reads lines from a file and pushes data into an array
/// \tparam U object into which and object with string, string, vector of ints can be pushed back into
/// \param allMok array of student type objects
/// \param filename name of file from which to read lines containing student objects
template <typename U>
void readToOne(U &allMok,std::string filename) {
    std::string str{};
    std::vector<std::string> tokens;
    std::ifstream f1(filename);
    while(std::getline(f1, str)) { //read file until the end line by line
        std::istringstream ss (str);
        tokens.clear();
        while (ss >> str) {
            tokens.push_back(str);
        }
        allMok.push_back({tokens[0],tokens[1],{std::stoi(tokens[2]),std::stoi(tokens[3]),std::stoi(tokens[4]),std::stoi(tokens[5]),std::stoi(tokens[6])}});
    }
}

///
/// \tparam T object into which and object with string, string, vector of ints can be pushed back into
/// \param gMok array for students which pass the requirements
/// \param bMok array for students which don't pass the requirements
/// \param filename name of file from which to read lines containing student objects
template <typename T>
void splitWhileReading(T & gMok, T &bMok, std::string filename) {
    Timer timer;
    std::string str{};
    std::vector<std::string> word;
    std::ifstream f1(filename);
    while (std::getline(f1, str)) { //read file until the end line by line
        std::istringstream ss(str);
        while (ss >> str)  word.push_back(str);
        weightedaverage({std::stoi(word[2]), std::stoi(word[3]), std::stoi(word[4]), std::stoi(word[5]), std::stoi(word[6])}, 1) < 6
        ? bMok.push_back({word[0], word[1]})
        : gMok.push_back({word[0], word[1]});
        word.clear();
    }
}
/// taken from std::algorithm remove_copy, edited so it pushes back not passing students into another array
/// \tparam _ForwardIterator  mutable forward iterator
/// \tparam _Output object into which and object with string, string, vector of ints can be pushed back into
/// \tparam _Predicate predicate function to test if a requirement is passed
/// \param __first begining of array
/// \param __last  ending of array
/// \param __destination array for students which pass the requirements
/// \param __pred predicate function which specifies the requirement
/// \return calls the function which performs the removing and copying after checkking if the given objects are good
template<typename _ForwardIterator,typename _Output, typename _Predicate>
inline _ForwardIterator
remove_copy_if_done_right(_ForwardIterator __first, _ForwardIterator __last, _Output &__destination,
        _Predicate __pred)
{
// concept requirements
__glibcxx_function_requires(_Mutable_ForwardIteratorConcept<
                            _ForwardIterator>)
__glibcxx_function_requires(_UnaryPredicateConcept<_Predicate,
                            typename iterator_traits<_ForwardIterator>::value_type>)
__glibcxx_requires_valid_range(__first, __last);

return __remove_copy_if_done_right(__first, __last,__destination,
        __gnu_cxx::__ops::__pred_iter(__pred));
}
/// taken from std::algorithm remove_copy, the doing part of the pair of functions
/// \tparam _ForwardIterator  mutable forward iterator
///// \tparam _Output object into which and object with string, string, vector of ints can be pushed back into
///// \tparam _Predicate predicate function to test if a requirement is passed
///// \param __first begining of array
///// \param __last  ending of array
///// \param __destination array for students which pass the requirements
///// \param __pred predicate function which specifies the requirement
/// \return returns iterator to the last good student in the original array
template<typename _ForwardIterator,typename _Output, typename _Predicate>
_ForwardIterator
__remove_copy_if_done_right(_ForwardIterator __first, _ForwardIterator __last, _Output& __destination,
            _Predicate __pred)
{
    __first = std::__find_if(__first, __last, __pred);
    if (__first == __last)
        return __first;
    _ForwardIterator __result = __first;
    ++__first;
    for (; __first != __last; ++__first)
        if (!__pred(__first))

        {
            *__result = _GLIBCXX_MOVE(*__first);
            ++__result;
        }
        else{
        __destination.push_back(*__first);
    }
    return __result;
}


/// reads student data into 1 array, then splits it into 2 by calling remove_copy_if_done_right
/// \tparam iterator forward iterator
/// \tparam container object into which and object with string, string, vector of ints can be pushed back into
/// \tparam T  predicate function to test if a requirement is passed
/// \param lessMok array for students which pass the requirements
/// \param allMok array for students which pass the requirements
/// \param pred predicate function which specifies the requirement
/// \param filename name of file from which to read data
template <typename iterator,typename container,typename T>
void splitErasebyRange(container & lessMok,iterator &allMok,T pred,std::string filename) {
    Timer timer;
    readToOne(allMok,filename);
    allMok.erase (
            remove_copy_if_done_right(
                    allMok.begin(),
                    allMok.end(),
                    lessMok,
                    pred),
            allMok.end()
    );
}
///
/// \tparam U container object into which and object with string, string, vector of ints can be pushed back into
/// \param gMokarray for students which pass the requirements
/// \param bMok array for students which dont't pass the requirements
/// \param allMok array for all students from which to split into 2 arrays
/// \param filename file from which to read students into allmok
template <typename T>
void splitLeaveTwoCopies(T & gMok, T &bMok ,T &allMok,std::string filename) {
    Timer timer;
    readToOne(allMok,filename);
    for (auto i = allMok.begin(),e=allMok.end(); i != e; ++i) {
            i->galBalas() <6
            ? bMok.push_back({i->getpavarde(),i->getvardas()})
            : gMok.push_back({i->getpavarde(),i->getvardas()});
    }
}
///
/// \tparam iterator forward iterator of student array object
/// \tparam container object into which and object with string, string, vector of ints can be pushed back into
/// \tparam T predicate function to test if a requirement is passed
/// \param lessMok array for students which pass the requirements
/// \param allMok array for students all students, from which to insert into other array and delete one by one
/// leaving only students which dont pass the requirements
/// \param pred predicate function which specifies the requirement
/// \param filename name of file from which to read students
template <typename iterator,typename container,typename T>
void splitEraseOneByOne(container & lessMok,iterator &allMok,T pred,std::string filename) {
    Timer timer;
    readToOne(allMok,filename);
    auto split = std::partition(allMok.begin(),allMok.end(),pred);
    auto it = allMok.end();
    --it;
    for (; it != split ; --it) {
        lessMok.push_back(*it);
        allMok.pop_back();
    }

}

///
/// \tparam greitas object into which and object with string, string, vector of ints can be pushed back into
/// \tparam pilnas object into which and object with string, string, vector of ints can be pushed back into
/// \param geri array for students which pass the requirements (no grades)
/// \param blogi array for students which don't pass the requirements (no grades)
/// \param visi array for students which pass the requirements (grades)
/// \param maziau array for students which don't pass the requirements (grades)
/// \param filename root name of file from which to read students
template <typename greitas, typename pilnas>
void testing(greitas &geri,greitas &blogi,pilnas &visi, pilnas &maziau,std::string filename){
    std::cout<<"1: ";splitWhileReading(geri,blogi,filename);std::cout<<" s\t";
    geri.clear();blogi.clear();
    std::cout<<"2: ";splitLeaveTwoCopies(geri,blogi,visi,filename);std::cout<<" s\t";
    geri.clear();blogi.clear();visi.clear();
    std::cout<<"3: ";splitErasebyRange(maziau,visi,test,filename);std::cout<<" s\t";
    maziau.clear();visi.clear();
    std::cout<<"4: ";splitEraseOneByOne(maziau,visi,test,filename);std::cout<<" s\t\n";
    std::cout<<maziau.size()<<" <- maziau "<<visi.size()<<" <-visi\n";
    maziau.clear();visi.clear();
};
#endif