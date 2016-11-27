/************************************************************************************************************
** Program Filename: FibonacciR.h
** Author: Peter Moldenhauer
** Date: 11/27/16
** Assignment: Lab 10
** Description: This is the header file that implements a recursive function. This code is from the site:
** https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
**************************************************************************************************************/

#ifndef FIBONACCIR_H
#define FIBONACCIR_H


class FibonacciR {
  public:
     FibonacciR(const int &n);
     virtual ~FibonacciR();
     void PrintFibonacci();
  private:
     FibonacciR();
     int Fibonacci(const int &n);
     const int *n_;
};

#endif // FIBONACCIR_H
