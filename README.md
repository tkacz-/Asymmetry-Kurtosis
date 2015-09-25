# Asymmetry-Kurtosis
Simple class for calculating asymmetry and kurtrosis of vector elements written in C++.

##Asymmetry formula

![here] (/Asymmetry Formula.jpg "Asymmetry formula")

which has these variables:
* sigma (upper-case) - central moment of elements;
* x - arithmetic mean of elemets.
* n - number of elements;
* sigma (lower-case) - standart deviation of elements.

##Kurtosis formula

![here] (/Kurtosis Formula.jpg "Kurtosis formula")

which has these variables:
* sigma (upper-case) - central moment of elements;
* x - arithmetic mean of elemets.
* n - number of elements;
* sigma (lower-case) - standart deviation of elements.

##Class template

`template <class Type, typename Sum> class AsymmetryKurtosis;`

###Template parameters
* **Type** - type of vector elements;
* **Sum** - type of sum vector elemenst;

###Example
```
#include "asymmetrykurtosis.h"`
...
int main()
{
    AsymmetryKurtosis<int, long long> math(v1);
    // AsymmetryKurtosis::calculateAsymmetry always returns double number
    double asymmetryCalculated = math.calculateAsymmetry();
    // AsymmetryKurtosis::calculateKurtosis always returns double number
    double kurtosisCalculated = math.calculateKurtosis();

    std::cout << "Asymmetry: " << asymmetryCalculated << std::endl;
    std::cout << "Kurtosis: " << kurtosisCalculated << std::endl;
    return 0;
}
```
## Copyright 
© Andrei Tkachenko (@tkacz-) include.free@gmail.com
