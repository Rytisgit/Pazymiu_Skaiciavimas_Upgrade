//
// Created by SuperPC on 3/6/2018.
//

#include "pazym.h"

void grade (const std::string  vardas,const std::string pavarde,const double  pazymiaiapdoroti,const double weightedegzaminas,const char choice)
{
    if(choice =='b')
    {
        double galutinisPazymis = {pazymiaiapdoroti+weightedegzaminas};
        std::cout<<vardas<<" "<<pavarde<<"\nGalutinis pazymis su medianu:\n";
        printf("%.2f\n", galutinisPazymis);

    }
    else
    {
        double galutinisPazymis = {pazymiaiapdoroti+weightedegzaminas};
        std::cout<<vardas<<" "<<pavarde<<"\nGalutinis pazymis su vidurkiu:\n";
        printf("%.2f\n", galutinisPazymis);
    }
}
double weightedmedian(std::vector<int> & medi,const double weight)
{
    std::sort(medi.begin(), medi.end());     // sort temperatures

    int tmedian{};
    if (medi.size() % 2 == 0)           // even
        tmedian = (medi[medi.size() / 2 - 1] + medi[medi.size() / 2]) / 2;
    else                                // odd
        tmedian = medi[medi.size() / 2];

    return weight * tmedian;
}
 double weightedaverage(const std::vector<int> & temps, double weight)
{
    double sum{0};
    for (double x : temps)
        sum += x;

    return weight * sum / temps.size();
}
 int getInput(const int  min, const int  max,const int  exit)
{
    std::string theInput;
    int inputAsInt;
//  b
    //  std::getline(std::cin, theInput);
    //std::cout<<iveskite;
    do
    {
        std::getline(std::cin, theInput);

        while(std::cin.fail() || std::cin.eof() || theInput.find_first_not_of("-0123456789") != std::string::npos) {

            if( theInput.find_first_not_of("-0123456789") == std::string::npos) {

                std::cin.clear();
                std::cin.ignore(256,'\n');
            }
            std::cout<<iveskite;
            if(exit!=INT_MAX)std::cout<<" "<<exit<<baigti;
            else std::cout<<"\n";
            std::getline(std::cin, theInput);
        }

        // std::string::size_type st;
        inputAsInt= atoi(theInput.c_str());
        //inputAsInt = std::stoi(theInput,&st);
        if(inputAsInt == exit) {
            break;
        }
        else {
            if(inputAsInt<min||inputAsInt>max&&exit==INT_MAX){
                std::cout<<iveskite;
                if(exit!=INT_MAX)std::cout<<" "<<exit<<baigti;
                else std::cout<<"\n";}
            else break;
        }
    } while (inputAsInt!=exit||exit!=INT_MAX);

    /* int input{};
     do
     {
         std::cin>>input;
         if(input<min||input>max||std::cin.fail())
         {
             std::cout<<iveskite;
             if(exit!=INT_MAX)std::cout<<" "<<exit<<baigti;
             else std::cout<<"\n";
             //std::cin.clear();
             // discard 'bad' character(s)
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         }
         else break;
     }
     while (input!=exit);
     return input;*/
    std::cout<<"grazinam "<<inputAsInt;
    return inputAsInt;

}
 char aORb()
{
    char choice{};
    do
    {
        std::cin>>choice;
        if(choice!='a'&&choice!='b')
        {
            std::cout<<"Rinkites a arba b\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    while(choice!='a'&&choice!='b');
    std::cin.clear();
    std::cin.ignore(256,'\n');
    return choice;
}
