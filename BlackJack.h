#ifndef BLACKJACK_H_INCLUDED
#define BLACKJACK_H_INCLUDED

class Card
{
private:
    string suit;
    string name;
    int score;
    bool isUpsideDown;
public:
    int getScore();
    void printCard();
    void flip();
};

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
    string text //text that appears after the game. for example "congratulations! you win!" or "you lost all your money, loser!" or something like that
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

#endif // BLACKJACK_H_INCLUDED
