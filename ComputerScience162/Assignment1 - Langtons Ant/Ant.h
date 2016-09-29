#ifndef ANT_H
#define ANT_H

enum Direction { north, east, south, west };

class Ant
{
private:
    Direction dir;
    char curColor;
    int pRow, pCol, cRow, cCol;

public:
    Ant();
    Ant(int r, int c);
    void setDirection(Direction d);
    Direction getDirection();
    void setCurColor(char c2);
    char getCurColor();
    void setPRow(int pr);
    int getPRow();
    void setPCol(int pc);
    int getPCol();
    void setCRow(int cr);
    int getCRow();
    void setCCol(int cc);
    int getCCol();
};

#endif // ANT_H
