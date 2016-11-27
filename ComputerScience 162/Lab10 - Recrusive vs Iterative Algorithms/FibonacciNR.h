/************************************************************************************************************
** Program Filename: FibonacciNR.h
** Author: Peter Moldenhauer
** Date: 11/27/16
** Assignment: Lab 10
** Description: This is the header file that implements a non-recursive function. This code is from the site:
** https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
**************************************************************************************************************/

#ifndef FIBONACCINR_H
#define FIBONACCINR_H


class FibonacciNR {
  public:
     FibonacciNR(const int &n);
     virtual ~FibonacciNR();
     void PrintFibonacci();
  private:
     FibonacciNR();
     int Fibonacci(const int &n);
     const int* n_;
};

#endif // FIBONACCINR_H
