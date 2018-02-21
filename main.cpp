#include "randutils.hpp"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <sstream>
const auto iveskite = "Iveskite skaiciu tarp 1 ir 10";
const auto baigti = " - Baigti Ivesti\n";
const int exitnumber = {-1};

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
{
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
inline double gradea (const double pazymiaiapdoroti,const int egzaminas)
{
    double galutinisPazymis = {pazymiaiapdoroti*0.4+egzaminas*0.6};
    return galutinisPazymis;
}
inline double gradem (const double pazymiaiapdoroti,const int egzaminas)
{
        double galutinisPazymis = {pazymiaiapdoroti*0.4+egzaminas*0.6};
    return galutinisPazymis;
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
		std::ifstream f1("kursiokai.txt");
		//f1.open;
		std::string str("Split me by whitespaces");
			std::string buf; // Have a buffer string
			//std::stringstream ss(str); // Insert the string into a stream

			std::vector<std::string> tokens; // Create vector to hold our words
		std::string tempstring; int temp{};
		
        while(std::getline(f1, str)) {
			f1.ignore();
			
			
			
			std::stringstream ss(str);
			//std::cout << str;
			tokens.clear();
			while (ss >> buf) { str.erase(remove_if(buf.begin(), buf.end(), isspace), buf.end()); tokens.push_back(buf);}
            //f1>>tempstring;
			
			
		//	std::cout <<tempstring;
            vardai.push_back(tokens[0]);

           // f1>>tempstring; 
			
			
			
            pavardes.push_back(tokens[1]);
			
            index.push_back(pavardes.size()-1);

			
			
               
			for (int i = 0; i < 5; i++)
			{
			//pazymiai.push_back(std::stoi( tokens[i + 2]));
				std::stringstream s_str(tokens[i + 2]);
				int il;
				s_str >> il;
				std::cout << tokens[i + 2];
				pazymiai.push_back(il);

				
			}
				//std::cout << "A";
            //f1>>egzaminas;
			//egzaminas = (double)std::stoi(tokens[7]);
			egzaminas = atoi(tokens[7].c_str());
            egzaminas*=0.6;
            vidurkiai.push_back( average(pazymiai) * 0.4 + egzaminas);
			double a = (double)median(pazymiai)*0.4;
            medianai.push_back( a+ egzaminas); 
			//medianai.push_back(0.1); std::cout << "A";
			
        }
		
		
        int i{};
        int j{};
        for (i = 0; i < pavardes.size()-1; ++i){
			// Last i elements are already in place
            for (j = 0; j < pavardes.size()-i-1; j++){ 
				if (pavardes[j] > pavardes[j+1]){
					std::swap(pavardes[j],pavardes[j+1]);
					std::swap(vardai[j], vardai[j + 1]);
					std::swap(vidurkiai[j], vidurkiai[j + 1]);
					std::swap(medianai[j], medianai[j + 1]);
				}
			}
		}

		char t = { '\t' };
		std::cout << "Pavarde" << t << "Vardas" << t << "Vidurkis" << t << "Medianas" << std::endl;
		for (int i = 0; i < pavardes.size()-1; i++)
		{
			std::cout << pavardes[i] << t << vardai[i] << t;
			printf("%.2f\t%.2f\n", vidurkiai[i],medianai[i]);
			
		}

            
		int a;
		std::cin >> a;
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
            egzaminas = {(double)rng.uniform(1,10)};
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
            egzaminas= {(double)getInput(1,10)};
        }
   
    std::cout<<"Pasirinkimai: a - Vidurkis, b - Medianas \n";
    char choice = {aORb()};
    if(choice =='a')grade(vardas,pavarde,average(pazymiai),egzaminas,choice);
    else grade(vardas,pavarde,(double)median(pazymiai),egzaminas,choice);
    return 0;
	}
}
