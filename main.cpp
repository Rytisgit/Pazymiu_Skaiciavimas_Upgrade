#include "randutils.hpp"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <cfloat>
#include <stdlib.h>
#include <random>

const auto iveskite = "Iveskite skaiciu tarp 1 ir 10";
const auto baigti = " - Baigti Ivesti\n";
const int end = {-1};

inline int median(std::vector<int> medi)
{
    std::sort(medi.begin(), medi.end());     // sort temperatures

    int tmedian{};
    if (medi.size() % 2 == 0)           // even
        tmedian = (medi[medi.size() / 2 - 1] + medi[medi.size() / 2]) / 2;
    else                                // odd
        tmedian = medi[medi.size() / 2];

    return tmedian;
}

inline double average(const std::vector<int> & temps)
{
    double sum{0};
    for (double x : temps)
        sum += x;

    return sum / temps.size();
}
inline int getInput(const int min, const int max,const int exit = INT_MAX){
    int input{};
do
    {
        std::cin>>input;
         if(input<min||input>max||std::cin.fail()){
            std::cout<<iveskite;
            if(exit!=INT_MAX)std::cout<<" "<<exit<<baigti;
            else std::cout<<"\n";
            std::cin.clear();
             // discard 'bad' character(s)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');}
            else break;
    }
     while (input!=exit);
     return input;

}
inline char aORb(){
    char choice{};
do
    {
        std::cin>>choice;
        if(choice!='a'&&choice!='b'){std::cout<<"Rinkites a arba b\n"; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');}
    }
    while(choice!='a'&&choice!='b');
    return choice;
}
inline void grade (const std::string vardas,const std::string pavarde,const double pazymiaiapdoroti,const int egzaminas,const char choice){
    std::cout<<"help";
 if(choice =='b')
    {
        double galutinisPazymis = {pazymiaiapdoroti*0.4+egzaminas*0.6};
        std::cout<<vardas<<" "<<pavarde<<"\nGalutinis pazymis su medianu:"<<std::endl<<galutinisPazymis;
    }
    else
    {
        double galutinisPazymis = {pazymiaiapdoroti*0.4+egzaminas*0.6};
        std::cout<<vardas<<" "<<pavarde<<"\nGalutinis pazymis su vidurkiu:"<<std::endl<<galutinisPazymis;
    }
}
int main()
{
    std::string vardas{},pavarde{};
    std::cout<<"Irasykite varda:";
    std::cin>>vardas;
    std::cout<<"Irasykite pavarde:";
    std::cin>>pavarde;
    std::cout<<"Pasirinkimai: a - Irasyti Pazymius, b - Atsitiktinai Sugeneruoti Pazymius \n";
    char choice{aORb()};
    std::vector<int> pazymiai{};
    double egzaminas{};
    if(choice =='b')  //random pazymiai
    {
        std::cout<<"Irasykite pazymiu kieki:";
        int n={getInput(1,100)};
        system("cls");
        //Better random from http://www.pcg-random.org/posts/ease-of-use-without-loss-of-power.html
        randutils::mt19937_rng rng;
        for (int i=0; i<n; ++i)
        {
            pazymiai.push_back(rng.uniform(1,10));
            std::cout<<pazymiai[i]<<"\n";

        }
        egzaminas = {rng.uniform(1,10)};
        std::cout<<"egzaminas:"<<egzaminas<<"\n";
    }
    if(choice =='a')  // irasyti pazymius
    {
        int n{};
        std::cout<<iveskite<<" "<<end<<baigti;
        do
    {
        n={getInput(1,10,-1)};
        if(n == -1){std::cout<<"baigta rasyti pazymius\n";}
        else pazymiai.push_back(n);
    }
     while (n!=-1);
     std::cout<<"Irasykite Egzamino ivertinima\n";
         egzaminas={getInput(1,10)};
    }
    std::cout<<"Pasirinkimai: a - Vidurkis, b - Medianas \n";
    choice = {aORb()};
    system("cls");
    if(choice =='a')grade(vardas,pavarde,average(pazymiai),egzaminas,choice);
        else grade(vardas,pavarde,(double)median(pazymiai),egzaminas,choice);

    return 0;
}
