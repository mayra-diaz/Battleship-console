#ifndef POO_I_CSQUARE_H
#define POO_I_CSQUARE_H

using carac = char;

class CSquare{
private:
    carac square;
    bool active;
    bool show;
public:
    explicit CSquare(){ square = '~'; active = true; show = true;};

    carac getSquareForAttack(){ return square;};
    carac getSquareForPrint()
            { if (!active) return ' '; else if(active && show) return square;
                else if (!show && active) {if (square=='B') return '~'; else return square;}};

    bool getActive(){ return active;}
    void setSquare(carac ch){ square = ch;}
    void setShowAndActive(bool shw, bool act= false) { show = shw; active = act;};
    void setShow(bool shw){show = shw; square='~';};
};

#endif //POO_I_CSQUARE_H
