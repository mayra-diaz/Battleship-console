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

    virtual ~CSquare()= default;

    carac getSquareForAttack(){ return square;};
    carac getSquareForPrint()
            { if (!active) return ' ';
                if (!show && active) {if (square=='B' || square=='M') return '~'; else return square;}
                else if(active && show) return square;};

    bool getActive(){return active;};
    void setSquare(carac ch){ square = ch;}
    void setShowAndActive(bool shw, bool act= false) { show = shw; active = act;};
    void setShow(bool shw){show = shw;};
};

#endif //POO_I_CSQUARE_H
