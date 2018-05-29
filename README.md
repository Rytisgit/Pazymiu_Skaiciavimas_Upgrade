
# Pazymiu_Skaiciavimas_Upgrade v1.0

## Description

This is an update to Pazymiu_skaiciavimas it implements a class student object instead of the struct used previuosly.

## Cool stuff
```c++
struct Timer{
    using clock = std::chrono::steady_clock;
    std::chrono::time_point<clock> start,end;
    Timer(){
        /// starts timing in constructor
        start = clock::now();
    }
    ~Timer(){
        ///outputs time since constructor in destructor
        end =  clock::now();
        std::cout<<(double)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()/1000000000<<" ";
    }
};
template<typename _ForwardIterator,typename _Output, typename _Predicate>
_ForwardIterator
__remove_copy_if_done_right(_ForwardIterator __first, _ForwardIterator __last, _Output& __destination,
            _Predicate __pred)
{
    __first = std::__find_if(__first, __last, __pred);
    if (__first == __last)
        return __first;
    _ForwardIterator __result = __first;
    ++__first;
    for (; __first != __last; ++__first)
        if (!__pred(__first))

        {
            *__result = _GLIBCXX_MOVE(*__first);
            ++__result;
        }
        else{
        __destination.push_back(*__first);
    }
    return __result;
}

```

# Times Comparison -O3 current vs -O2 struct(in seconds)(also available raw times of -O1 and no optimization)
### Vector  

 Name\Size| 100       | 1000     | 10000      | 100000
-|---------- |-----------|-------------|----------
**splitWhileReading**  |0.000648274  vs 0.000420074  | 0.00549175   vs  0.00286732    |  0.0612904 vs  0.0256167 | 0.575433  vs   0.270532   
**splitErasebyRange** |0.000745875 vs  0.000341327 |  0.00679495  vs  0.00268625    | 0.0701569 vs  0.0260706 |   0.657086   vs  0.278586    
**splitLeaveTwoCopies** |0.000845695 vs 0.000338554  | 0.00724802   vs    0.00267489   | 0.0906164 vs   0.0262359   |  0.729387    vs   0.282615  
**splitEraseOneByOne** | 0.000821573 vs 0.000331068  |0.00677111  vs  0.00268099  |  0.121893   vs   0.0263707  | 0.712371    vs   0.297115  

### List

 Name\Size| 100       | 1000     | 10000      | 100000
-|---------- |-----------|-------------|----------
**splitWhileReading**  |0.00095522 vs 0.000331623   |  0.00520699 vs    0.00271398   | 0.0648493   vs  0.027574  | 0.515373  vs 0.273249
**splitErasebyRange** |0.000821849  vs  0.00035436 | 0.0067151   vs   0.00288617  | 0.0674845 vs   0.02722    |0.672073 vs  0.286076
**splitLeaveTwoCopies** | 0.000934701 vs 0.000330514  | 0.00853736  vs   0.002826  |  0.0943713  vs   0.0278901| 0.826433 vs  0.289449
**splitEraseOneByOne** | 0.000847081   vs 0.000330514  | 0.00731208 vs  0.00283266 |   0.0913179   vs    0.0283829  |0.793027   vs  0.28891 

### Deque 

 Name\Size| 100       | 1000     | 10000      | 100000
-|---------- |-----------|-------------|----------
**splitWhileReading**  | 0.000629419  vs 0.000318036   | 0.00529405    vs 0.00266435  |  0.053705   vs 0.026176 |0.497515   vs 0.273003 
**splitErasebyRange** | 0.000728407    vs 0.000320255 |    0.00684681   vs 0.00272424  |  0.0679462   vs 0.0309005   |0.796156    vs 0.281683 
**splitLeaveTwoCopies** |0.000848191  vs 0.000330237   |0.00731845  vs  0.00273145  | 0.0754108     vs 0.0285229 |0.786287   vs  0.282105
**splitEraseOneByOne** | 0.000836822  vs 0.000316649  | 0.00739914  vs  0.00277776 |   0.072399       vs 0.0271104 | 0.838799  vs 0.283125 

# Results
After testing on intel based machine(previously tested on amd) the speeds become very close, newest results in raw -o3 intel


### Changelog v1.0
#### Added
 - catch testing

### Changelog v0.2
#### Added
 - doxygen documentation
### Changes
- comments in doxygen style



### Changelog v0.1
#### Added
 - Studentclass
### Changes
- fixed file checking and reformatted it to be a function
 - changed splitting styles to work with a class


