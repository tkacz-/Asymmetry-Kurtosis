# Asymmetry-Kurtosis
Simple class for calculating asymmetry and kurtrosis of vector elements written in C++.

## Asymmetry formula

![here](/Asymmetry%20Formula.jpg "Asymmetry formula")

which has these variables:
* sigma (upper-case) - central moment of elements;
* x - arithmetic mean of elemets.
* n - number of elements;
* sigma (lower-case) - standart deviation of elements.

## Kurtosis formula

![here](/Kurtosis%20Formula.jpg "Kurtosis formula")

which has these variables:
* sigma (upper-case) - central moment of elements;
* x - arithmetic mean of elemets.
* n - number of elements;
* sigma (lower-case) - standart deviation of elements.

### Standart deviation, sigma(lower-case)

[Formula for calculating standart deviation](/Standart%20Deviation.jpg "Standart deviation")

## Class template

`template <class Type> class AsymmetryKurtosis;`

### Template parameters
* **Type** - type of vector elements;

### Example
```
#include "asymmetrykurtosis.h"`
...
int main()
{
    AsymmetryKurtosis<int> math(v1);
    // AsymmetryKurtosis::calculateAsymmetry always returns double number
    double asymmetryCalculated = math.calculateAsymmetry();
    // AsymmetryKurtosis::calculateKurtosis always returns double number
    double kurtosisCalculated = math.calculateKurtosis();

    std::cout << "Asymmetry: " << asymmetryCalculated << std::endl;
    std::cout << "Kurtosis: " << kurtosisCalculated << std::endl;
    return 0;
}
```
