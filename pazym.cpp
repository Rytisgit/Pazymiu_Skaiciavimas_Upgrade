//
// Created by SuperPC on 3/6/2018.
//


#include "pazym.h"
#include "calculation.h"

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
//!
//! \param filenames filename to check if exists to know if need to generate new student files
void Checkforfiles(const std::string &filenames) {
    std::ifstream f1;
    f1.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        f1.open (filenames);
        std::__cxx11::string buf;
        getline(f1, buf);
        f1.seekg(0, std::ios_base::beg);
    }
    catch (...){
        std::cout<<"Student files not found, generating new files...\n";
        generateStudentFile("f10",10);
        generateStudentFile("f100",100);
        generateStudentFile("f1000",1000);
        generateStudentFile("f10000",10000);
        generateStudentFile("f100000",100000);
        std::cout<<"Done.\n";
    }
}
int getInput2(const int min, const int max, const int exit){
    int x{};
    std::string a{};
    bool loop=true;

    std::cin.clear();
    while(loop)
    {
        std::string s;
        std::getline(std::cin, s);
        std::stringstream stream(s);
        if(stream >> x)
        {
            if(stream>>a ){
                std::cout<<error<<iveskite;
                if(exit!=INT_MAX)std::cout<<" "<<exit<<baigti;
                else std::cout<<std::endl;
                continue;}
            else if(x==exit || (x>=min&&x<=max)){
                loop=false;}
            else{
                std::cout<<error<<iveskite;
                if(exit!=INT_MAX)std::cout<<" "<<exit<<baigti;
                else std::cout<<std::endl;}

        }
        else{
            std::cout<<error<<iveskite;
            if(exit!=INT_MAX)std::cout<<" "<<exit<<baigti;
            else std::cout<<std::endl;}
    }
//    std::cout<<"grazinam "<<x<<std::endl;
    return x;
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

        while(std::cin.fail() || std::cin.eof() ) {

            if( theInput.find_first_not_of("0123456789-") != std::string::npos) {
                std::cout<<"test";
                std::cin.clear();
                std::cin.ignore(256,'\n');
                std::cout<<iveskite;
                if(exit!=INT_MAX)std::cout<<" "<<exit<<baigti;
                else std::cout<<"\n";
                std::getline(std::cin, theInput);
            }



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
    std::cout<<"grazinam "<<inputAsInt;
    return inputAsInt;

}
 char aORb() {
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

void generateStudentFile(const std::string name, const int length) {
    std::ostringstream ss;
    std::ofstream fs(name);
    randutils::mt19937_rng rng;
    for (int i = 1; length >= i; ++i) {
//        ss<<"Vardas"<<i<<" Pavarde"<<i;
        ss<<"V"<<i<<" P"<<i;
        for (int j = 0; j < 5; ++j) {
            ss<<' '<<rng.uniform(1,10);
        }
        ss<<'\n';
        fs<<ss.str();
        //ss.str(std::string());
        std::ostringstream().swap(ss);
    }

}

void splitbygrades(std::vector<greitasMokinys> &gMok, std::vector<greitasMokinys> &bMok) {
    std::vector<int> pazymiai{};
    int il{};
    std::string file{"f1"};
    std::string str{};
    std::string buf; // Have a buffer string
    std::vector<std::string> tokens; // Create vector to hold our words
    greitasMokinys tempmok;
    for (int i = 0; i < 5; ++i) {
        auto start = std::chrono::steady_clock::now();
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
            weightedaverage(pazymiai,1)<6 ? bMok.push_back(tempmok) : gMok.push_back(tempmok);

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
        auto end = std::chrono::steady_clock::now();
        std::cout <<file<< " Time is " << (double)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()/1000000000 << " seconds egzamino mokiniu skaicius " <<gMok.size() <<" Ne egzamino mokiniu skacius"<<bMok.size()<< std::endl;

    }
}

void splitbygrades(std::deque<greitasMokinys> & gMok, std::deque<greitasMokinys> &bMok) {
    std::vector<int> pazymiai{};
    int il{};
    std::string file{"f1"};
    std::string str{};
    std::string buf; // Have a buffer string
    std::vector<std::string> tokens; // Create vector to hold our words
    greitasMokinys tempmok;
    for (int i = 0; i < 5; ++i) {
        auto start = std::chrono::steady_clock::now();
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
            weightedaverage(pazymiai,1)<6 ? bMok.push_back(tempmok) : gMok.push_back(tempmok);

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
        auto end = std::chrono::steady_clock::now();
        std::cout <<file<< " Time is " << (double)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()/1000000000 << " seconds egzamino mokiniu skaicius " <<gMok.size() <<" Ne egzamino mokiniu skacius"<<bMok.size()<< std::endl;

    }
}
void splitbygrades(std::list<greitasMokinys> & gMok, std::list<greitasMokinys> &bMok) {
    std::vector<int> pazymiai{};
    int il{};
    std::string file{"f1"};
    std::string str{};
    std::string buf; // Have a buffer string
    std::vector<std::string> tokens; // Create vector to hold our words
    greitasMokinys tempmok;
    for (int i = 0; i < 5; ++i) {
        auto start = std::chrono::steady_clock::now();
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
            weightedaverage(pazymiai,1)<6 ? bMok.push_back(tempmok) : gMok.push_back(tempmok);

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
        auto end = std::chrono::steady_clock::now();
        std::cout <<file<< " Time is " << (double)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()/1000000000 << " seconds egzamino mokiniu skaicius " <<gMok.size() <<" Ne egzamino mokiniu skacius"<<bMok.size()<< std::endl;

    }
}
