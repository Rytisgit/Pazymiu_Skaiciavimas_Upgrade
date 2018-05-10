#include <chrono>
#include <deque>
#include <list>
#include "splibygrades.h"
#include "filecheck.h"

int main()
{



            std::list<studentClass> listgMok;
            std::list<studentClass> listbMok;
            std::list<studentClass> listallMok;
            std::list<studentClass> listlessMok;
            std::deque<studentClass> dequegMok;
            std::deque<studentClass> dequebMok;
            std::deque<studentClass> dequeallMok;
            std::deque<studentClass> dequelessMok;
            std::vector<studentClass> gMok;
            std::vector<studentClass> bMok;
            std::vector<studentClass> allMok;
            std::vector<studentClass> lessMok;
            std::vector<studentClass> classMok;
            //studentClass a = {"a","bv"};
            //classMok.push_back(a);
           // std::cout<<classMok[0].getvardas()<<classMok[0].getpavarde()<<classMok[0].galBalas();

            gMok.reserve(50000);
            bMok.reserve(70000);
            allMok.reserve(100000);
            lessMok.reserve(70000);
            std::string filenames= "f10";
            Checkforfiles(filenames);
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
       //  std::cout<<listgMok.size()<<" <- gmok "<<listbMok.size()<<" <-bmok\n";*/

    return 0;
        }





