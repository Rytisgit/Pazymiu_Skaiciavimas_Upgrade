#include <chrono>
#include "pazym.h"
#include <deque>
const std::string iveskite = {"Iveskite skaiciu tarp 1 ir 10"};
const std::string baigti = {" - Baigti Ivesti\n"};
const int exitnumber = {-1};
const double eweight = {0.6};
const double pweight = {0.4};


int main()
{
    std::cout<<"Pasirinkimai: a - stress, b - normalus veikimas \n";

//        if (aORb()=='a'){
    if (true){
        std::deque<geraasMokinys> deq;

            auto start = std::chrono::steady_clock::now();
            generateStudentFile("f10",10);
            generateStudentFile("f100",100);
            generateStudentFile("f1000",1000);
            generateStudentFile("f10000",10000);
            generateStudentFile("f100000",100000);
            auto end = std::chrono::steady_clock::now();
            std::cout << "Failu irasymo laikas " << (double)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()/1000000000 << " seconds"<< std::endl;
            std::vector<geraasMokinys> gMok;
            std::vector<blogasMokinys> bMok;
            std::vector<int> pazymiai{};
            int il{};
            std::string file{"f1"};
            std::string str{};
            std::string buf; // Have a buffer string
            std::vector<std::string> tokens; // Create vector to hold our words
            geraasMokinys tempmok;
            for (int i = 0; i < 5; ++i) {
                start = std::chrono::steady_clock::now();
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
                    tempmok.pavarde = tokens[1];
                    weightedaverage(pazymiai,1)<6 ? bMok.push_back({tempmok.vardas,tempmok.pavarde}) : gMok.push_back(tempmok);

                    pazymiai.clear();
                }
//            std::cout<<"Egzaminai\n"; //isspausdinti tinkamus / netinkamus
//            for (auto const &it : gMok)
//            {
//                printf("%-15s%-15s\n", it.pavarde.c_str(),it.vardas.c_str());
//            }
//            std::cout<<"Ne egzaminai\n";
//            for (auto const &it : bMok)
//            {
//                printf("%-15s%-15s\n", it.pavarde.c_str(),it.vardas.c_str());
//            }
                end = std::chrono::steady_clock::now();
                std::cout <<file<< " Time is " << (double)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()/1000000000 << " seconds egzamino mokiniu skaicius " <<gMok.size() <<" Ne egzamino mokiniu skacius"<<bMok.size()<< std::endl;

            }

//            auto end = std::chrono::steady_clock::now();
//            std::cout <<file<< " Time is " << (double)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()/1000000000 << " seconds egzamino mokiniu skaicius " <<gMok.size() <<" Ne egzamino mokiniu skacius"<<bMok.size()<< std::endl;
            return 0;
        }


    else{
        std::cout<<"Pasirinkimai: a - Skaityti is failo, b - 1 mokinio duomenu irasymas \n";
        if(aORb()=='a'){
            std::vector<mokinys> mok;
            std::vector<int> pazymiai{};
            int index{0};
            double egzaminas{};
            std::ifstream f1;
            f1.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
            try {
                f1.open ("kursiokai.txt");
                std::string buf;
                std::getline(f1, buf);
                f1.seekg(0, std::ios::beg);
            }
            catch (std::ifstream::failure &e){
                std::cout<<"Failed to open/read file\n";
                return 0;
            }
            std::string str{};
            std::string buf; // Have a buffer string
            std::vector<std::string> tokens; // Create vector to hold our words
            std::string tempstring; int temp{};
            mokinys tempmok;
            try {
            while(std::getline(f1, str)) {
                std::stringstream ss(str);
                tokens.clear();
                while (ss >> buf) {
                  //  str.erase(remove_if(buf.begin(), buf.end(), isspace), buf.end());
                    tokens.push_back(buf);
                }
                tempmok.vardas = tokens[0];
                tempmok.pavarde = tokens[1];
    //            vardai.push_back(tokens[0]);
    //            pavardes.push_back(tokens[1]);
    //            index.push_back(pavardes.size()-1);
                for (int i = 0; i < 5; i++)
                {
                    std::stringstream s_str(tokens[i + 2]);
                    int il;
                    s_str >> il;
                    pazymiai.push_back(il);
                }
    //            egzaminas = (double)std::stoi(tokens[7]);
                egzaminas = (double)atoi(tokens[7].c_str())*eweight;
                tempmok.vidurkis =  weightedaverage(pazymiai) + egzaminas;
                tempmok.medianas =  weightedmedian(pazymiai, pweight) + egzaminas;
                mok.push_back(tempmok);
    //            medianai.push_back( (double)weightedmedian(pazymiai) + egzaminas);
    //            for (int j = 0; j < 5; ++j) {
    //                std::cout<<pazymiai[j]<<" ";
    //            }
                //std::cout<<" "<<average(pazymiai)+egzaminas<<" "<<median(pazymiai)+egzaminas<<std::endl;
                pazymiai.clear();
            }}
            catch (std::ifstream::failure &e){}

            for (int i = 0; i < mok.size(); ++i){
                for (int j = 0; j < mok.size()-1; ++j){
                    if (mok[j].pavarde > mok[j+1].pavarde){
                        std::swap(mok[j],mok[j+1]);

                    }
                }
            }
            printf("%-15s%-15s%s\t%s\n" , "Pavarde","Vardas","Vidurkis","Medianas");
    //		for (int i = 0; i < mok.size(); i++)
    //		{
    //			printf("%-15s%-15s%.2f\t%.2f\n", mok[i].pavarde.c_str(),mok[i].vardas.c_str(),mok[i].vidurkis,mok[i].medianas);
    //		}
            for (auto const &it : mok)
            {
                printf("%-15s%-15s%.2f\t%.2f\n", it.pavarde.c_str(),it.vardas.c_str(),it.vidurkis,it.medianas);
            }
        }
        else {
            std::string vardas{}, pavarde{};
            std::cout << "Irasykite varda:";
            std::cin >> vardas;
            std::cout << "Irasykite pavarde:";
            std::cin >> pavarde;
            std::cout << "Pasirinkimai: a - Irasyti Pazymius, b - Atsitiktinai Sugeneruoti Pazymius \n";
            std::vector<int> pazymiai{};
            double egzaminas{};


            if (aORb() == 'b')  //random pazymiai
            {
                std::cout << "Irasykite pazymiu kieki:";
                int n = {getInput(1, 100)};
                //Better random from http://www.pcg-random.org/posts/ease-of-use-without-loss-of-power.html
                randutils::mt19937_rng rng;
                for (int i = 0; i < n; ++i) {
                    pazymiai.push_back(rng.uniform(1, 10));
                    std::cout << pazymiai[i] << "\n";
                }
                egzaminas = {(double) rng.uniform(1, 10) * eweight};
                std::cout << "egzaminas:" << egzaminas << "\n";
            } else  // irasyti pazymius
            {
                int n{};
                std::cout << iveskite << " " << exitnumber << baigti;
                do {
                    n = {getInput(1, 10, -1)};
                    if (n == -1) {
                        std::cout << "baigta rasyti pazymius\n";
                    } else pazymiai.push_back(n);
                } while (n != -1);
                std::cout << "Irasykite Egzamino ivertinima\n";
                egzaminas = {(double) getInput(1, 10) * eweight};
            }

            std::cout << "Pasirinkimai: a - Vidurkis, b - Medianas \n";
            char choice = {aORb()};
            if (choice == 'a')grade(vardas, pavarde, weightedaverage(pazymiai), egzaminas, choice);
            else grade(vardas, pavarde, weightedmedian(pazymiai, pweight), egzaminas, choice);
        }

	} return 0;
}
