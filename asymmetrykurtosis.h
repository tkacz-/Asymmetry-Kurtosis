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
template <class Type>
class AsymmetryKurtosis
{
private:
    std::vector<Type> vector;

    long long size;

    /** Absolute value of vector elements.
     * @param v - vector of elements
     */
    void absVector (std::vector<Type> &v)
    {
        for (long long i = 0; i < size; i++)
            v[i] = std::abs(v[i]);
    }

    /** Sum of vector elements
     * @param v - vector of elements
     * @return number - sum of vector elements, 0 otherwise.
     */
    double sumVector (const std::vector<Type> &v)
    {
        double s = 0;
        for (long long i = 0; i < size; i++)
            s += v[i];
        return s;
    }

    /** Sum of vector elements
     * @param v - vector of elements (double)
     * @return number - sum of vector elements, 0 otherwise.
     */
    double sum(const std::vector<double> &v)
    {
        double s = 0;
        for (long long i = 0; i < size; i++)
            s += v[i];
        return s;
    }

    /** Arithemic mean of vector elements
     * @param s - sum of vector elements
     * @return number - arithmetic mean  of vector elements, 0 otherwise.
     */
    double arithmeticMean (double s)
    {
        double res = s / size;
        return res;
    }

    /** Central moment of vector elements
     * @param v - vector of elements
     * @param mx - arithmetic mean of vector elements
     * @param temp - central moment of vector elements.
     */
    void centralMoment (const std::vector<Type> &v, double mx, std::vector<double> &temp)
    {
        for (long long i = 0; i < size; i++)
            temp[i] = (double) v[i] - mx;
    }

    /** Exponentiation of vector elements.
     * @param s - sum of vector elements
     * @param y - degree
     * @param temp - vector after exponentiation.
     */
    void exponentiation (const std::vector<double> &v, int y, std::vector<double> &temp)
    {
        for (long long i = 0; i < size; i++)
            temp[i] = std::pow(v[i], y);
    }

    /** Standart deviation of vector elements.
     * @param s - sum of vector elements
     * @return number - standart deviation.
     */
    double deviation (double s)
    {
        double res = std::sqrt( (double) s / (size - 1) );
        return res;
    }

    /** Asymmetry of vector elements
     * @param s - sum of vector elements
     * @param sig - standart deviation
     * @return number - calculated kurtosis of vector elements.
     */
    double asymmetry (double s, double sig)
    {
        double res = s / (size * sig * sig * sig);
        return res;
    }

    /** Kurtosis of vector elements
     * @param s - sum of vector elements
     * @param sig - standart deviation
     * @return number - calculated kurtosis of vector elements.
     */
    double kurtosis(double s, double sig)
    {
        double res = s / (size * sig * sig * sig * sig) - 3;
        return res;
    }
public:
    AsymmetryKurtosis(std::vector <Type> &v)
    {
        setVector(v);
    }

    //Calculate asymmetry of vector elements
    double calculateAsymmetry()
    {
        //absVector(vector);
        double s1 = sumVector(vector);
        double Mx = arithmeticMean(s1);
        std::vector<double> v2(size);
        centralMoment(vector, Mx, v2);
        std::vector<double> v3(size);
        exponentiation(v2, 2, v3);
        double s2 = sum(v3);
        double sig = deviation(s2);

        exponentiation(v2, 3, v3);
        double s3 = sum(v3);
        double asymmetryCalculated = asymmetry(s3, sig);

        v2.clear();
        v3.clear();
        return asymmetryCalculated;
    }

    //Calculate kurtosis of vector elements
    double calculateKurtosis()
    {
        //absVector(vector);
        double s1 = sumVector(vector);
        double Mx = arithmeticMean(s1);
        std::vector<double> v2(size);
        centralMoment(vector, Mx, v2);
        std::vector<double> v3(size);
        exponentiation(v2, 2, v3);

        double s2 = sum(v3);
        double sig = deviation(s2);

        exponentiation(v2, 4, v3);
        double s4 = sum(v3);
        double kurtosisCalculated = kurtosis(s4, sig);

        v2.clear();
        v3.clear();
        return kurtosisCalculated;
    }

    //Set vector
    void setVector(std::vector<Type> &v)
    {
        vector = v;
        size = v.size();
    }

    //Get vector
    void getVector(std::vector<Type> &temp)
    {
        temp = vector;
    }

    ~AsymmetryKurtosis()
    {
        vector.clear();
    }
};

#endif // ASYMMETRYKURTOSIS_H
