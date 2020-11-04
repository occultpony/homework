#ifndef BLACKJACK_H_INCLUDED
#define BLACKJACK_H_INCLUDED

using namespace std;

enum cardsuit
{
    diamonds,
    hearts,
    spades,
    clubs
};

enum cardname
{
    ace = 1,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king
};

class Card
{
private:
    cardsuit suit;
    cardname name;
    int value;
    bool isUpsideDown;
public:
    Card();
    Card(cardsuit s, cardname n);
    void setValue();
    int getValue();
    void flip();
};
/*
class Deck
{
private:
    Card* cards;
public:
    Card getCard();
    void generateDeck();
};

class Player
{
private:
    Card* cards; //array of cards
    int score;
public:
    void takeCard();
    void printScore();
    void printCards();
    virtual void move();
};

class Dealer : public Player
{
public:
    void move();
};

class Gamer : public Player
{
public:
    void move();
};

struct GameResult
{
    int dealer_score;
    int gamer_score;
    int bet;
    bool isWin;
    string text; //text that appears after the game. for example "congratulations! you win!" or "you lost all your money, loser!" or something like that
};

class Game
{
private:
    int winsCount;
    int losesCount;
    int bet;
    int money;
    GameResult result;
public:
    void play();
    void setBet();
    void setMoney(); //money can be set only one time in contrast of bet(?)
    void printResult();
    void calculateResult();

};
*/
#endif // BLACKJACK_H_INCLUDED
