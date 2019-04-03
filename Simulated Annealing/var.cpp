#include "var.h"

double fungsi(double x1, double x2){
    return (  ( (2*(pow(x1,2)))+ ((pow(x2,4)/(double)3) ))*(pow(x1,2))    )- (x1*x2) + (double)(4*(pow(x2,2))*(pow(x2,2)));
}

double fRand(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
