#include <chrono>
#include "pazym.h"
#include "splibygrades.h"
const std::string iveskite = {"Iveskite skaiciu tarp 1 ir 10"};
const std::string baigti = {" - Baigti Ivesti\n"};
const std::string error = {"Klaida, "};
const int exitnumber = -1;
const double eweight = {0.6};
const double pweight = {0.4};


int main()
{
    std::cout<<"Pasirinkimai: a - stress, b - normalus veikimas \n";

        if (aORb()=='a'){
            std::list<greitasMokinys> listgMok;
            std::list<greitasMokinys> listbMok;
            std::list<allMokinys> listallMok;
            std::list<allMokinys> listlessMok;
            std::deque<greitasMokinys> dequegMok;
            std::deque<greitasMokinys> dequebMok;
            std::deque<allMokinys> dequeallMok;
            std::deque<allMokinys> dequelessMok;
            std::vector<greitasMokinys> gMok;
            std::vector<greitasMokinys> bMok;
            std::vector<allMokinys> allMok;
            std::vector<allMokinys> lessMok;
            gMok.reserve(50000);
            bMok.reserve(70000);
            allMok.reserve(100000);
            lessMok.reserve(70000);
            std::string filenames= "f10";
            //generateStudentFile("fmil",1000000);
//            std::cout<<"list times:\n";
//            splitWhileReading(listgMok,listbMok,"f100000");
            for (int i = 0; i <4; ++i) {
                filenames+="0";
                std::cout<<std::endl<<filenames<<std::endl;
                std::cout<<std::endl<<"Vector"<<std::endl;
                testing(gMok,bMok,allMok,lessMok,filenames);
                std::cout<<std::endl<<"List"<<std::endl;
                testing(listgMok,listbMok,listallMok,listlessMok,filenames);
                std::cout<<std::endl<<"Deque"<<std::endl;
                testing(dequegMok,dequebMok,dequeallMok,dequelessMok,filenames);
            }
       //  std::cout<<listgMok.size()<<" <- gmok "<<listbMok.size()<<" <-bmok\n";
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
                    tokens.push_back(buf);
                }
                tempmok.vardas = tokens[0];
                tempmok.pavarde = tokens[1];
                for (int i = 0; i < 5; i++)
                {
                    std::stringstream s_str(tokens[i + 2]);
                    int il;
                    s_str >> il;
                    pazymiai.push_back(il);
                }
                egzaminas = (double)atoi(tokens[7].c_str())*eweight;
                tempmok.vidurkis =  weightedaverage(pazymiai) + egzaminas;
                tempmok.medianas =  weightedmedian(pazymiai, pweight) + egzaminas;
                mok.push_back(tempmok);

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
                int n = {getInput2(1, 100)};
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
                std::cout<<iveskite;
                std::cout<<" "<<exit<<baigti;
                do {
                    std::cin.clear();

                    n = {getInput2(1, 10, -1)};
                    if (n == -1) {
                        if(pazymiai.size()==0){std::cout<<"Iveskite bent 1 pazymi\n";n=0;}
                        else{std::cout << "baigta rasyti pazymius\n";}
                    } else pazymiai.push_back(n);

                } while (n != -1 );
                std::cout << "Irasykite Egzamino ivertinima\n";
                egzaminas = {(double) getInput2(1, 10) * eweight};
            }

            std::cout << "Pasirinkimai: a - Vidurkis, b - Medianas \n";
            char choice = {aORb()};
            if (choice == 'a')grade(vardas, pavarde, weightedaverage(pazymiai), egzaminas, choice);
            else grade(vardas, pavarde, weightedmedian(pazymiai, pweight), egzaminas, choice);
        }

	} return 0;
}
