#include "Ant.h"
#include <iostream>
using namespace std;

Ant::Ant(){
}

Ant::Ant(int r, int c){
    setDirection(north);
    setCurColor(' ');
    setPRow(r);
    setPCol(c);
    setCRow(r);
    setCCol(c);
}

void Ant::setDirection(Direction d){
    dir = d;
}

Direction Ant::getDirection(){
    return dir;
}

void Ant::setCurColor(char c2){
    curColor = c2;
}

char Ant::getCurColor(){
    return curColor;
}

void Ant::setPRow(int pr){
    pRow = pr;
}

int Ant::getPRow(){
    return pRow;
}

void Ant::setPCol(int pc){
    pCol = pc;
}

int Ant::getPCol(){
    return pCol;
}

void Ant::setCRow(int cr){
    cRow = cr;
}

int Ant::getCRow(){
    return cRow;
}

void Ant::setCCol(int cc){
    cCol = cc;
}

int Ant::getCCol(){
    return cCol;
}
