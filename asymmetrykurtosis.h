#ifndef ASYMMETRYKURTOSIS_H
#define ASYMMETRYKURTOSIS_H

/*
 * asymmetrykurtosis.h
 *
 * Copyright 2015 Andrei Tkachenko(@tkacz-) include.free@gmail.com
 * Calculate asymmetry and kurtosis of vector elements
 */

#include <vector>
#include <cmath>

/**
 * Class for calculating asymmetry and kurtosis in vector
 */
template <class Type, typename Sum>
class AsymmetryKurtosis
{
private:
    std::vector<Type> vector;

    long long size;

    /** Absolute value of vector elements.
     * @param v - vector of elements
     */
    void absVector (std::vector<Type> v)
    {
        Type* data = v.data();
        for (long long i = 0; i < size; i++)
            data[i] = std::abs(data[i]);
    }

    /** Sum of vector elements
     * @param v - vector of elements
     * @param n - size of vector
     * @return number - sum of vector elements, 0 otherwise.
     */
    Sum sumVector (std::vector<Type> v)
    {
        Type* data = v.data();
        Sum s = 0;
        for (long long i = 0; i < size; i++)
            s += data[i];
        return s;
    }

    /** Arithemic mean of vector elements
     * @param s - sum of vector elements
     * @return number - arithmetic mean  of vector elements, 0 otherwise.
     */
    double arithmeticMean (Sum s)
    {
        double res = s / size;
        return res;
    }

    /** Central moment of vector elements
     * @param v - vector of elements
     * @param mx - arithmetic mean of vector elements
     * @return vector - Central moment of vector elements.
     */
    std::vector<Type> centralMoment (std::vector<Type> v, double mx)
    {
        std::vector<Type> temp(size);
        Type* data = v.data();
        for (long long i = 0; i < size; i++)
            temp[i] = data[i] - mx;
        return temp;
    }

    /** Exponentiation of vector elements.
     * @param s - sum of vector elements
     * @param y - degree
     * @return vector - after exponentiation.
     */
    std::vector<Type> exponentiation (std::vector<Type> v, int y)
    {
        std::vector<Type> temp(size);
        Type* data = v.data();
        for (long long i = 0; i < size; i++)
            temp[i] = std::pow(data[i], y);
        return temp;
    }

    /** Standart deviation of vector elements.
     * @param s - sum of vector elements
     * @return number - standart deviation.
     */
    double deviation (Sum s)
    {
        double res = std::sqrt( (double) s / (size - 1));
        return res;
    }

    /** Asymmetry of vector elements
     * @param s - sum of vector elements
     * @param sig - standart deviation
     * @return number - calculated kurtosis of vector elements.
     */
    double asymmetry (Sum s, double sig)
    {
        double res = s / (size * sig * sig * sig);
        return res;
    }

    /** Kurtosis of vector elements
     * @param s - sum of vector elements
     * @param sig - standart deviation
     * @return number - calculated kurtosis of vector elements.
     */
    double kurtosis(Sum s, double sig)
    {
        double res = s / (size * sig * sig * sig * sig) - 3;
        return res;
    }
public:
    AsymmetryKurtosis(std::vector <Type> v)
    {
        setVector(v);
    }

    //Calculate asymmetry of vector elements
    double calculateAsymmetry()
    {
        absVector(vector);
        Sum s1 = sumVector(vector);
        double Mx = arithmeticMean(s1);
        std::vector<Type> v2 = centralMoment(vector, Mx);
        std::vector<Type> v3 = exponentiation(v2, 2);
        Type s2 = sumVector(v3);
        double sig = deviation(s2);

        v3 = exponentiation(v2, 3);
        Sum s3 = sumVector(v3);
        double asymmetryCalculated = asymmetry(s3, sig);

        v2.clear();
        v3.clear();
        return asymmetryCalculated;       
    }

    //Calculate kurtosis of vector elements
    double calculateKurtosis()
    {
        absVector(vector);
        Sum s1 = sumVector(vector);
        double Mx = arithmeticMean(s1);
        std::vector<Type> v2 = centralMoment(vector, Mx);
        std::vector<Type> v3 = exponentiation(v2, 2);
        Type s2 = sumVector(v3);
        double sig = deviation(s2);

        v3 = exponentiation(v2, 4);
        Sum s4 = sumVector(v3);
        double kurtosisCalculated = kurtosis(s4, sig);

        v2.clear();
        v3.clear();
        return kurtosisCalculated;
    }

    //Set vector
    void setVector(std::vector<Type> v)
    {
        vector = v;
        size = v.size();
    }

    //Get vector
    std::vector<Type> getVector()
    {
        return vector;
    }

    ~AsymmetryKurtosis()
    {
        vector.clear();
    }
};

#endif // ASYMMETRYKURTOSIS_H
