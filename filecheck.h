//
// Created by SuperPC on 5/9/2018.
//

#ifndef PAZYMIAI_FILECHECK_H
#define PAZYMIAI_FILECHECK_H

#include <string>

/// Generates a student file with default name surname and 5 random marks
/// \param name name of the file to generate
/// \param length  length of file or number of students to generate
void generateStudentFile(const std::string name, const int length);
/**
 * CheckforFiles Checks if file based on the filenames root exists, if it doesnt exist, it generates a new set of files
 * @param [in] filenames root from which to check if files exist
 */
void Checkforfiles(const std::string &filenames);
#endif //PAZYMIAI_FILECHECK_H
