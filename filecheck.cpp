//
// Created by SuperPC on 5/9/2018.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "filecheck.h"
#include "randutils.hpp"

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


void Checkforfiles(const std::string &filenames) {
    std::ifstream f1;
    f1.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        f1.open (filenames);
        std::__cxx11::string buf;
        getline(f1, buf);
        f1.seekg(0, std::ios_base::beg);
    }
    catch (std::ios_base::failure &e){
        std::cout<<"Student files not found, generating new files...\n";
        std::string name = filenames;
        int length;
        for (size_t count = 0; count < 5 ; ++count) {
            generateStudentFile(name,10);
            name+="0";

        }
        std::cout<<"Done.\n";
    }
}