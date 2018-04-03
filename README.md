# Vertinimo komentarai

Pastabos:

1. Darė daugiau negu užduotys prašė, į strategijas įkorporavo algoritmus, todėl laikai gavosi panašūs (bet labai maži).

Privalumai:

1. Visur su Templeitais
2. Pats prisiderino `remove_if` prie savo konteksto
3. Savo splitinimo strategiją sugalvojo
4. Veikia labai greitai


# Pazymiu_Skaiciavimas

## Description

The program generates a students final grade by calculating it from the marks which it is either given or it randomly generates.
It also can read from files for mass grading and sorting

## Launching the program
##### A cmake file is included so for linux all one would need to do is run the following commands in order in the source directory:

```mkdir build-dir  ```

```cd build-dir ```

```cmake .. ```

```make ```

##### On windows if compiler and cmake tools are installed:
```cd {source directory}```

```g++ -std=c++11 *.cpp -o main```

```./main```
###### Otherwise Import the project into a cmake compatible ide or if thats not possible set it up by hand

## Interface
The program is navigated by selecting a or b. It also asks for input of names of students or their marks when necessary

## Functions for reading and sorting
### readToOne()
Reads a student file by the format:

Name | Surname | Mark 1 | Mark 2| Mark 3 | Mark 4 | Mark 5
--- | ---- | ---- | ---- | ---- | ---- | ----| 

it reads it to a string by getline then stringstream splits into words which are used to fill a student file, std::stoi() is used to convert marks to integers.
### splitWhileReading()
The function reads by the same method as readToOne, but after every line it calls the average function to decide into which container to put in the students data, sorting it.
### splitErasebyRange()
Calls readToOne(), then remove_copy_if_done_right() which is remove_copy_if and remove_if combined to both sort the containers items by predicate and copy over items which are not to be left in that container, then container.erase is called to free up space which was made from this operation in the first container
### splitLeaveTwoCopies()
This is a function for the first strategy outlined in the guide
### splitEraseOneByOne()
This is a function for the second strategy outlined in the guide

# Times (in seconds)
### Vector  

 Name\Size| 100       | 1000     | 10000      | 100000
-|---------- |-----------|-------------|----------
**splitWhileReading**  |0.000420074  |   0.00286732    |   0.0256167 |  0.270532   
**splitErasebyRange** | 0.000341327 |    0.00268625    |  0.0260706 |     0.278586    
**splitLeaveTwoCopies** |0.000338554  |    0.00267489   |   0.0262359   |     0.282615  
**splitEraseOneByOne** |0.000331068  |  0.00268099  |     0.0263707  |     0.297115  

### List

 Name\Size| 100       | 1000     | 10000      | 100000
-|---------- |-----------|-------------|----------
**splitWhileReading**  |0.000331623   |    0.00271398   |  0.027574  |0.273249
**splitErasebyRange** |  0.00035436 |     0.00288617  |   0.02722    | 0.286076
**splitLeaveTwoCopies** |0.000330514  |   0.002826  |     0.0278901| 0.289449
**splitEraseOneByOne** |0.000330514  |  0.00283266 |       0.0283829  |  0.28891 

### Deque 

 Name\Size| 100       | 1000     | 10000      | 100000
-|---------- |-----------|-------------|----------
**splitWhileReading**  |0.000318036   |    0.00266435  |  0.026176 | 0.273003 
**splitErasebyRange** |  0.000320255 |     0.00272424  |   0.0309005   | 0.281683 
**splitLeaveTwoCopies** | 0.000330237   |  0.00273145  |    0.0285229 |  0.282105
**splitEraseOneByOne** |0.000316649  |   0.00277776 |        0.0271104 | 0.283125 


### Changelog v1.0
#### Added
 - 3 new sorting functions
- readToOne -  New funtion to read from file into a single container to then be manipulated
 - Testing funtion to track times of reading to all types of containers of all sizes of files
### Changes
- Improved GetInput should no longer fail on a faulty input of a number followed by letters when only a number is asked (for input of  "1a" would accept the 1 then throw a message as if it was rejected)
 - improved splitbygrades() , renamed to splitWhileReading()
### Changelog v0.5.1
#### Added
 - Templates to use std::list and std::deque along with std::vector
 - Default student files for speed testing
### Changelog v0.4
#### Added
 - Mass student file generation with random marks (10/100/1000/10000/100000 length files)
 - This data is read and stored into 2 vectors of student structs 1 for passing grades, the other not
 - Timing with these actions with <chrono>
 ### Removed
  -Unnecesarry files from project
### Changelog v0.3.1
#### Added
 ##### Header and secondary source file
Split extra functions to a second file connected with header to the main file
###### Try catch
Enabled exceptions on fstream and added try catch guards to exit the program when file is empty or non existent.
### Changelog v0.2
#### Added
- Added file reading and calculating marks for several students using the same functions as for typing by hand
### Changelog v0.1 
#### Added
- Calculation of final score of random Marks (generated from from http://www.pcg-random.org/posts/ease-of-use-without-loss-of-power.html) or by user input
- Selection of media or average for final mark calculation
- Also added masyvai.cpp which uses dynamic arrays instead of vectors but behaves the same otherwise

