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
#include "pazym.h"

struct Timer{
    std::chrono::time_point<std::chrono::steady_clock> start,end;
    Timer(){
        start = std::chrono::steady_clock::now();
    }
    ~Timer(){
        end =  std::chrono::steady_clock::now();
        std::cout <<"Time is " << (double)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()/1000000000 << " seconds"<< std::endl;

    }
};

template <typename T>
void printarray(const T &gMok){
    for (typename T::const_iterator i=gMok.begin(); i!=gMok.end(); ++i)
    {
        printf("%-15s%-15s\n", (i->pavarde).c_str(),(i->vardas).c_str());
    }

}
template <typename T>
void splitbygrades2(T & gMok, T &bMok) {
    std::vector<int> pazymiai{};
    int il{};
    std::string file{"f1"};
    std::string str{};
    std::string buf; // Have a buffer string
    std::vector<std::string> tokens; // Create vector to hold our words
    greitasMokinys tempmok;
    for (int i = 0; i < 5; ++i) {
        file+='0';
        std::ifstream f1(file);
        while(std::getline(f1, str)) { //read file until the end line by line

            std::stringstream ss (str);
            tokens.clear();
            while (ss >> buf) {
                tokens.push_back(buf);
            }
            for (int k = 0; k < 5; ++k) {
                std::stringstream s_str(tokens[k + 2]);
                s_str >> il;
                pazymiai.push_back(il);
            }
            tempmok.vardas = tokens[0];
          //a
            // a std::cout<<tokens[0];
            tempmok.pavarde = tokens[1];
            weightedaverage(pazymiai,1)>6 ? bMok.push_back(tempmok) : gMok.push_back(tempmok);
            pazymiai.clear();
        }
    }
}


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

bool test(const allMokinys &Mok) {
    return (weightedaverage(Mok.pazymiai,1) > 6);
}

template <typename iterator,typename container,typename T>
void splitbygrades3(container & lessMok,iterator &allMok,T pred) {
    allMok.erase (
            remove_copy_if_done_right(
                    allMok.begin(),
                    allMok.end(),
                    lessMok,
                    pred),
            allMok.end()
    );
}
template <typename T,typename U>
void splitbygrades2(T & gMok, T &bMok ,U &allMok) {

    for (auto i = allMok.begin(),e=allMok.end(); i != e; ++i) {
            weightedaverage(i->pazymiai,1) <6
            ? bMok.push_back({i->pavarde,i->vardas})
            : gMok.push_back({i->pavarde,i->vardas});
        }
    }


template <typename U>
void readToOne(U &allMok) {
    std::vector<int> pazymiai{};
    std::string file{"f1"};
    std::string str{};
    std::vector<std::string> tokens;
    for (int i = 0; i < 5; ++i) {
        file+='0';
        std::ifstream f1(file);
        while(std::getline(f1, str)) { //read file until the end line by line
            std::istringstream ss (str);
            tokens.clear();
            while (ss >> str) {
                tokens.push_back(str);
            }
            for (int k = 0; k < 5; ++k) {
                pazymiai.push_back(std::stoi(tokens[k+2]));
            }
            allMok.push_back({tokens[0],tokens[1],pazymiai});
            pazymiai.clear();
        }
    }
}
#endif //PAZYMIAI_SPLIBYGRADES_H
