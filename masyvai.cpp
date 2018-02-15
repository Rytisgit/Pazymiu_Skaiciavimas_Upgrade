#include "randutils.hpp"
#include <iostream>
#include <cstdio>
const auto iveskite = "Iveskite skaiciu tarp 1 ir 10";
const auto baigti = " - Baigti Ivesti\n";
const int exitnumber = {-1};


inline int median(int * arr,const int size)
{
    //std::sort(medi.begin(), medi.end());     // sort temperatures
    int i{}, j{},k{};
    for (i = 0; i < size-1; i++)

        // Last i elements are already in place
        for (j = 0; j < size-i-1; j++)
            if (arr[j] > arr[j+1])
                // std::swap(&arr[j], &arr[j+1]);
                k=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=k;
    int tmedian{};
    if (size % 2 == 0)           // even
        tmedian = (arr[size / 2 - 1] + arr[size / 2]) / 2;
    else                                // odd
        tmedian = arr[size / 2];

    return tmedian;
}
inline double average(const int * temps,const int size)
{
    double sum{0};
    for (int i = 0; i<size; i++) {
        sum += temps[i];
    }

    return sum / size;
}
inline int getInput(const int min, const int max,const int exit = INT_MAX)
{
    int input{};
    do
    {
        std::cin>>input;
        if(input<min||input>max||std::cin.fail())
        {
            std::cout<<iveskite;
            if(exit!=INT_MAX)std::cout<<" "<<exit<<baigti;
            else std::cout<<"\n";
            std::cin.clear();
            // discard 'bad' character(s)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else break;
    }
    while (input!=exit);
    return input;

}
inline char aORb()
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
    return choice;
}
inline void grade (const std::string vardas,const std::string pavarde,const double pazymiaiapdoroti,const int egzaminas,const char choice)
{   system("cls");
    if(choice =='b')
    {
        double galutinisPazymis = {pazymiaiapdoroti*0.4+egzaminas*0.6};
        std::cout<<vardas<<" "<<pavarde<<"\nGalutinis pazymis su medianu:\n";
        printf("%.2f\n", galutinisPazymis);

    }
    else
    {
        double galutinisPazymis = {pazymiaiapdoroti*0.4+egzaminas*0.6};
        std::cout<<vardas<<" "<<pavarde<<"\nGalutinis pazymis su vidurkiu:\n";
        printf("%.2f\n", galutinisPazymis);
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
    // std::vector<int> pazymiai{};

    //////////////////////////////
    int *a = new int [1];
    int *b {};
    int index{0},size{1};
    bool aistheone=true;
    //////////////////////////////

    double egzaminas{};
    if(aORb() =='b')  //random pazymiai
    {
        aistheone=false;
        std::cout<<"Irasykite pazymiu kieki:";
        index= {getInput(1,100)};
        system("cls");
        //Better random from http://www.pcg-random.org/posts/ease-of-use-without-loss-of-power.html
        b=new int[index];
        randutils::mt19937_rng rng;
        for (int i=0; i<index; ++i)
        {
            b[i]= {rng.uniform(1,10)};
            std::cout<<b[i]<<"\n";
        }
        egzaminas = {rng.uniform(1,10)};
        std::cout<<"egzaminas:"<<egzaminas<<"\n";
    }
    else  // irasyti pazymius
    {
        int n{};
        std::cout<<iveskite<<" "<<exitnumber<<baigti;
        do
        {
            n= {getInput(1,10,-1)};
            if(n != -1)
            {

                if(aistheone) {
                    a[index]=n;
                    // std::cout<<"n is "<<n<<std::endl;
                }
                else b[index]=n;
                index++;
                if (index==size) {
                    if(aistheone) {
                        size*=2;
                        b= new int [size];
                        for(int i = 0; i<size; i++) {
                            b[i]=a[i];
                            for(int i = 0; i<size; i++) {
                                //  cout<<"a"<<a[i]<<endl;
                            }
                        }
                        delete a;
                    }
                    else {
                        size*=2;
                        a= new int [size];
                        for(int i = 0; i<size; i++) {
                            a[i]=b[i];
                            for(int i = 0; i<size; i++) {
                                // cout<<"b"<<b[i]<<endl;
                            }
                        }
                        delete b;
                    }
                }
            }
            else {
                std::cout<<"baigta rasyti pazymius\n";
            }
        }
        while (n!=-1);
        std::cout<<"Irasykite Egzamino ivertinima\n";
        egzaminas= {getInput(1,10)};
    }
    std::cout<<"Pasirinkimai: a - Vidurkis, b - Medianas \n";
    char choice = {aORb()};
    double apdorota{};
    if(aistheone) {
        if(choice =='a')apdorota=average(a,index);
        else {
            apdorota=(double)median(a,index);
        }
    }
    else {
        if(choice =='a')apdorota=average(b,index);
        else {
            apdorota=(double)median(b,index);
        }
    }

    grade(vardas,pavarde,apdorota,egzaminas,choice);
    return 0;
}
