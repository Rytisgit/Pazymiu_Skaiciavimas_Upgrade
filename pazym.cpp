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
    std::sort(medi.begin(), medi.end());     // sort

    int tmedian{};
    if (medi.size() % 2 == 0)           // even
        tmedian = (medi[medi.size() / 2 - 1] + medi[medi.size() / 2]) / 2;
    else                                // odd
        tmedian = medi[medi.size() / 2];

    return weight * tmedian;
}
 double weightedaverage(const std::vector<int> & temps, double weight)
{
    return weight * std::accumulate(temps.begin(),temps.end(),0.0) / temps.size();
}
int getInput2(const int min, const int max, const int exit){
    int x{};
    std::string a{};
    bool loop=true;
    std::stringstream stream;
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
 //   std::getline(std::cin, a);
    while(loop)
    {
//        while(std::cin.fail() || std::cin.eof() ) {
//        }
        std::cout<<"test";
        std::string s;

        if(std::getline(std::cin, s)){stream.str(s);std::cin.clear();}
        s.clear();
        if(stream >> x)
        {
            if(stream>>a ){
                std::cout<<"test";
                std::cout<<iveskite;
                if(exit!=INT_MAX)std::cout<<" "<<exit<<baigti;
                else std::cout<<std::endl;
                continue;}
            else if(x==exit || (x>=min&&x<=max)){
                std::cout<<"test2";
                loop=false;}
            else{
                std::cout<<"test4";
                std::cout<<iveskite;
                if(exit!=INT_MAX)std::cout<<" "<<exit<<baigti;
                else std::cout<<std::endl;}

        }
        else{
            std::cout<<iveskite;
            if(exit!=INT_MAX)std::cout<<" "<<exit<<baigti;
            else std::cout<<std::endl;}
       // if(!loop)break;
      //  std::cout << "Invalid!" << std::endl;
    }

    std::cout<<"grazinam "<<x;
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
