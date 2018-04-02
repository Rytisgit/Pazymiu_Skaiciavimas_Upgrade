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
        std::cout<<(double)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()/1000000000<<" ";
    }
};
bool test(const allMokinys &Mok) {
    return (weightedaverage(Mok.pazymiai,1) > 6);
}
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


template <typename T>
void printarray(const T &Mok){
//    sortIt(Mok,pavTest);
    for (typename T::const_iterator i=Mok.begin(); i!=Mok.end(); ++i)
    {

        printf("%-15s%-15s\n", (i->pavarde).c_str(),(i->vardas).c_str());
    }

}
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
template <typename T,typename U>
void splitLeaveTwoCopies(T & gMok, T &bMok ,U &allMok,std::string filename) {
    Timer timer;
    readToOne(allMok,filename);
    for (auto i = allMok.begin(),e=allMok.end(); i != e; ++i) {
            weightedaverage(i->pazymiai,1) <6
            ? bMok.push_back({i->pavarde,i->vardas})
            : gMok.push_back({i->pavarde,i->vardas});
        }
    }
template <typename iterator,typename container,typename T>
void splitEraseOneByOne(container & lessMok,iterator &allMok,T pred,std::string filename) {
    Timer timer;
    readToOne(allMok,filename);
    auto split = std::partition(allMok.begin(),allMok.end(),pred);
    auto it = allMok.end();
    --it;
    for (; it !=split ; --it) {
        lessMok.push_back(*it);
        allMok.pop_back();
    }

}


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
#endif //PAZYMIAI_SPLIBYGRADES_H
//template<typename T>
//struct pavTest
//{
//bool operator()(const T &Mok,const T &prevMok) {
//    return (Mok.pavarde > prevMok.pavarde);
//}
//};

//bool pavTest(const greitasMokinys &Mok,const greitasMokinys &prevMok) {
//    return (Mok.pavarde > prevMok.pavarde);
//}
//bool pavTest(const allMokinys &Mok,const allMokinys &prevMok) {
//    return (Mok.pavarde > prevMok.pavarde);
//}

//template <typename test,typename T,
//        typename std::enable_if<!std::is_same<test,std::list<greitasMokinys>>::value && !std::is_same<test,std::list<allMokinys>>::value>::type >
//void sortIt(test &notList,T pavTest){
//    std::sort(notList.begin(),notList.end(),pavTest);
//}
//template <typename T>
//void sortIt(std::list<greitasMokinys> &list,T pavTest){
//    list.sort(pavTest);
//}
//template <typename T>
//void sortIt(std::list<allMokinys> &list,T pavTest){
//    list.sort(pavTest);
//}