#include "randutils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
const auto iveskite = "Iveskite skaiciu tarp 1 ir 10";
const auto baigti = " - Baigti Ivesti\n";
const int exitnumber = {-1};
const double eweight = 0.6;
const double pweight = 0.4;

inline int weightedmedian(std::vector<int> medi, double weight = 0.4)
{
    std::sort(medi.begin(), medi.end());     // sort temperatures

    int tmedian{};
    if (medi.size() % 2 == 0)           // even
        tmedian = (medi[medi.size() / 2 - 1] + medi[medi.size() / 2]) / 2;
    else                                // odd
        tmedian = medi[medi.size() / 2];

    return weight * tmedian;
}
inline double weightedaverage(const std::vector<int> & temps, double weight = 0.4)
{
    double sum{0};
    for (double x : temps)
        sum += x;

    return weight * sum / temps.size();
}
inline int getInput(const int min, const int max,const int exit = INT_MAX)
{


    std::string theInput;
    int inputAsInt;
    std::getline(std::cin, theInput);
    //std::cout<<iveskite;
    do
    {
        std::getline(std::cin, theInput);


        while(std::cin.fail() || std::cin.eof() || theInput.find_first_not_of("0123456789") != std::string::npos) {



            if( theInput.find_first_not_of("0123456789") == std::string::npos) {

                std::cin.clear();
                std::cin.ignore(256,'\n');
            }
            std::cout<<iveskite;
            if(exit!=INT_MAX)std::cout<<" "<<exit<<baigti;
            else std::cout<<"\n";
            std::getline(std::cin, theInput);
        }

        std::string::size_type st;
        inputAsInt= atoi(theInput.c_str());
    //inputAsInt = std::stoi(theInput,&st);
        if(inputAsInt<min||inputAsInt>max)
        { std::cout<<iveskite;
            if(exit!=INT_MAX)std::cout<<" "<<exit<<baigti;
            else std::cout<<"\n";

        }
        else break;
    } while (inputAsInt!=exit);

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
    return inputAsInt;

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
    std::cin.clear();
    std::cin.ignore(256,'\n');
    return choice;
}
inline void grade (const std::string vardas,const std::string pavarde,const double pazymiaiapdoroti,const int weightedegzaminas,const char choice)
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
int main()
{
    std::cout<<"Pasirinkimai: a - Skaityti is failo, b - 1 mokinio duomenu irasymas \n";
    if(aORb()=='a'){
        std::vector<int> pazymiai{};
        std::vector<std::string> pavardes{};
        std::vector<std::string> vardai{};
        std::vector<double> vidurkiai{};
        std::vector<double> medianai{};
        std::vector<int> index{};
        double egzaminas{};
		std::ifstream f1("kursiokai2.txt");
		std::string str{};
        std::string buf; // Have a buffer string
        std::vector<std::string> tokens; // Create vector to hold our words
		std::string tempstring; int temp{};
        while(std::getline(f1, str)) {
			std::stringstream ss(str);
			tokens.clear();
			while (ss >> buf) { str.erase(remove_if(buf.begin(), buf.end(), isspace), buf.end()); tokens.push_back(buf);}
            vardai.push_back(tokens[0]);
            pavardes.push_back(tokens[1]);
            index.push_back(pavardes.size()-1);
			for (int i = 0; i < 5; i++)
			{
				std::stringstream s_str(tokens[i + 2]);
				int il;
				s_str >> il;
				pazymiai.push_back(il);
			}
            //egzaminas = (double)std::stoi(tokens[7]);
			egzaminas = (double)atoi(tokens[7].c_str())*eweight;
            vidurkiai.push_back( weightedaverage(pazymiai) + egzaminas);
            medianai.push_back( (double)weightedmedian(pazymiai) + egzaminas);
            for (int j = 0; j < 5; ++j) {
                std::cout<<pazymiai[j]<<" ";
            }
            //std::cout<<" "<<average(pazymiai)+egzaminas<<" "<<median(pazymiai)+egzaminas<<std::endl;
            pazymiai.clear();
        }
        double tem{};
        for (int i = 0; i < pavardes.size()-1; ++i){
            for (int j = 0; j < pavardes.size()-i-1; j++){
				if (pavardes[j] > pavardes[j+1]){
					std::swap(pavardes[j],pavardes[j+1]);
					std::swap(vardai[j], vardai[j + 1]);
                    tem = vidurkiai[j];
                    vidurkiai[j] = vidurkiai [j+1];
                    vidurkiai[j+1]=tem;
                    tem = medianai[j];
                    medianai[j] = medianai [j+1];
                    medianai[j+1]=tem;
				}
			}
		}
        printf("%-15s%-15s%s\t%s\n" , "Pavarde","Vardas","Vidurkis","Medianas");
		for (int i = 0; i < pavardes.size()-1; i++)
		{
			printf("%-15s%-15s%.2f\t%.2f\n", pavardes[i].c_str(),vardai[i].c_str(),vidurkiai[i],medianai[i]);
		}
		//int a;
		//std::cin >> a;
    }
    else {
    std::string vardas{},pavarde{};
    std::cout<<"Irasykite varda:";
    std::cin>>vardas;
    std::cout<<"Irasykite pavarde:";
    std::cin>>pavarde;
    std::cout<<"Pasirinkimai: a - Irasyti Pazymius, b - Atsitiktinai Sugeneruoti Pazymius \n";
    std::vector<int> pazymiai{};
    double egzaminas{};


        if(aORb() =='b')  //random pazymiai
        {
            std::cout<<"Irasykite pazymiu kieki:";
            int n= {getInput(1,100)};
            //Better random from http://www.pcg-random.org/posts/ease-of-use-without-loss-of-power.html
            randutils::mt19937_rng rng;
            for (int i=0; i<n; ++i)
            {
                pazymiai.push_back(rng.uniform(1,10));
                std::cout<<pazymiai[i]<<"\n";
            }
            egzaminas = {(double)rng.uniform(1,10)*eweight};
            std::cout<<"egzaminas:"<<egzaminas<<"\n";
        }
        else  // irasyti pazymius
        {
            int n{};
            std::cout<<iveskite<<" "<<exitnumber<<baigti;
            do
            {
                n= {getInput(1,10,-1)};
                if(n == -1)
                {
                    std::cout<<"baigta rasyti pazymius\n";
                }
                else pazymiai.push_back(n);
            }
            while (n!=-1);
            std::cout<<"Irasykite Egzamino ivertinima\n";
            egzaminas= {(double)getInput(1,10)*eweight};
        }
   
    std::cout<<"Pasirinkimai: a - Vidurkis, b - Medianas \n";
    char choice = {aORb()};
    if(choice =='a')grade(vardas,pavarde,weightedaverage(pazymiai),egzaminas,choice);
    else grade(vardas,pavarde,(double)weightedmedian(pazymiai),egzaminas,choice);
    return 0;
	}
}
