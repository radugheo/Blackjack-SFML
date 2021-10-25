#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#define _WIN64_WINNT 0x0500

///test

using namespace sf;
using namespace std;

int sumPlayer, nrCardsPlayer, sumDealer, nrCardsDealer, ch, press, bet, balance;
int f[20][20];

bool finish = false, start = true, firstB = true, doubleBool = false;

struct cards {
    int val;
    int tip;
};

cards player[20], dealer[20];

int main() {
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
    Image icon;
    icon.loadFromFile("Pictures/iconn.png");
    RenderWindow window(VideoMode(1024, 728), "Blackjack", Style::Fullscreen);
    int screenX = window.getSize().x;
    int screenY = window.getSize().y;
    window.setIcon(32, 32, icon.getPixelsPtr());
    Font fnt;
    fnt.loadFromFile("Fonts/CallingCards_Reg_sample.ttf");
    //////////////////////////////////////////
    //textures importing
    Texture neagraTexture, rosieTexture, treflaTexture, rombTexture, hitButtonTexture, standButtonTexture, doubleButtonTexture, exitButtonTexture, betButtonTexture, betmaxButtonTexture, backgroundTexture;
    Texture iTexture, vTexture, xTexture, xxvTexture, dTexture, cTexture;
    neagraTexture.loadFromFile("Pictures/neagra.png"), neagraTexture.setSmooth(true);
    rosieTexture.loadFromFile("Pictures/rosie.png"), rosieTexture.setSmooth(true);
    treflaTexture.loadFromFile("Pictures/trefla.png"), treflaTexture.setSmooth(true);
    rombTexture.loadFromFile("Pictures/romb.png"), rombTexture.setSmooth(true);
    hitButtonTexture.loadFromFile("Pictures/hit.png");
    standButtonTexture.loadFromFile("Pictures/stand.png");
    doubleButtonTexture.loadFromFile("Pictures/double.png");
    exitButtonTexture.loadFromFile("Pictures/exit.png");
    betButtonTexture.loadFromFile("Pictures/bet.png");
    betmaxButtonTexture.loadFromFile("Pictures/betmax.png");
    backgroundTexture.loadFromFile("Pictures/green_felt.jpg");
    iTexture.loadFromFile("Pictures/1c.png"), iTexture.setSmooth(true);
    vTexture.loadFromFile("Pictures/5c.png"), vTexture.setSmooth(true);
    xTexture.loadFromFile("Pictures/10c.png"), xTexture.setSmooth(true);
    xxvTexture.loadFromFile("Pictures/25c.png"), xxvTexture.setSmooth(true);
    dTexture.loadFromFile("Pictures/50c.png"), dTexture.setSmooth(true);
    cTexture.loadFromFile("Pictures/100c.png"), cTexture.setSmooth(true);
    //////////////////////////////////////////
    int hitx1, hitx2, hity1, hity2, standx1, standx2, standy1, standy2, exitx1, exitx2, exity1, exity2, betx1, betx2, bety1, bety2, doublex1, doublex2, doubley1, doubley2, betmaxx1, betmaxx2, betmaxy1, betmaxy2;
    int coin1x1, coin1x2, coin1y1, coin1y2, coin5x1, coin5x2, coin5y1, coin5y2, coin10x1, coin10x2, coin10y1, coin10y2;
    int coin25x1, coin25x2, coin25y1, coin25y2, coin50x1, coin50x2, coin50y1, coin50y2, coin100x1, coin100x2, coin100y1, coin100y2;
    betmaxx1 = 480, betmaxy1 = screenY - 285;
    betmaxx2 = betmaxx1 + 240, betmaxy2 = betmaxy1 + 60;
    betx1 = 65, bety1 = screenY - 78;
    betx2 = betx1 + 100, bety2 = bety1 + 60;
    hitx1 = betx2 + 20, hity1 = screenY - 78;
    hitx2 = hitx1 + 100, hity2 = hity1 + 60;
    standx1 = hitx2 + 20, standy1 = screenY - 78;
    standx2 = standx1 + 180, standy2 = standy1 + 60;
    doublex1 = standx2 + 20, doubley1 = screenY - 78;
    doublex2 = doublex1 + 220, doubley2 = doubley1 + 60;
    exitx1 = screenX - 245, exity1 = screenY - 78;
    exitx2 = exitx1 + 180, exity2 = exity1 + 60;
    coin1x1 = 65, coin1y1 = screenY - 200;
    coin1x2 = coin1x1 + 85, coin1y2 = coin1y1 + 85;
    coin5x1 = coin1x2 + 29, coin5y1 = screenY - 200;
    coin5x2 = coin5x1 + 85, coin5y2 = coin5y1 + 85;
    coin10x1 = coin5x2 + 29, coin10y1 = screenY - 200;
    coin10x2 = coin10x1 + 85, coin10y2 = coin10y1 + 85;
    coin25x1 = coin10x2 + 29, coin25y1 = screenY - 200;
    coin25x2 = coin25x1 + 85, coin25y2 = coin25y1 + 85;
    coin50x1 = coin25x2 + 29, coin50y1 = screenY - 200;
    coin50x2 = coin50x1 + 85, coin50y2 = coin50y1 + 85;
    coin100x1 = coin50x2 + 29, coin100y1 = screenY - 200;
    coin100x2 = coin100x1 + 85, coin100y2 = coin100y1 + 85;
    //////////////////////////////////////////
    Sprite hitButton, standButton, doubleButton, exitButton, betmaxButton, betButton, background, coin1, coin5, coin10, coin25, coin50, coin100, cards[6][100];
    background.setTexture(backgroundTexture);
    betmaxButton.setTexture(betmaxButtonTexture), betmaxButton.setPosition(betmaxx1, betmaxy1);
    betButton.setTexture(betButtonTexture), betButton.setPosition(betx1, bety1);
    hitButton.setTexture(hitButtonTexture), hitButton.setPosition(hitx1, hity1);
    standButton.setTexture(standButtonTexture), standButton.setPosition(standx1, standy1); 
    doubleButton.setTexture(doubleButtonTexture), doubleButton.setPosition(doublex1, doubley1);
    exitButton.setTexture(exitButtonTexture), exitButton.setPosition(exitx1, exity1);
    coin1.setTexture(iTexture), coin1.setPosition(coin1x1, coin1y1), coin1.setScale(0.35, 0.35);
    coin5.setTexture(vTexture), coin5.setPosition(coin5x1, coin5y1), coin5.setScale(0.35, 0.35);
    coin10.setTexture(xTexture), coin10.setPosition(coin10x1, coin10y1), coin10.setScale(0.35, 0.35);
    coin25.setTexture(xxvTexture), coin25.setPosition(coin25x1, coin25y1), coin25.setScale(0.35, 0.35);
    coin50.setTexture(dTexture), coin50.setPosition(coin50x1, coin50y1), coin50.setScale(0.35, 0.35);
    coin100.setTexture(cTexture), coin100.setPosition(coin100x1, coin100y1), coin100.setScale(0.35, 0.35);
    //////////////////////////////////////////
    //sprites creating
    {
        cards[0][1].setTexture(neagraTexture), cards[0][1].setTextureRect(IntRect(0, 0, 180, 250));
        cards[0][2].setTexture(neagraTexture), cards[0][2].setTextureRect(IntRect(205, 0, 180, 250));
        cards[0][3].setTexture(neagraTexture), cards[0][3].setTextureRect(IntRect(409, 0, 180, 250));
        cards[0][4].setTexture(neagraTexture), cards[0][4].setTextureRect(IntRect(612, 0, 180, 250));
        cards[0][5].setTexture(neagraTexture), cards[0][5].setTextureRect(IntRect(815, 0, 178, 250));
        cards[0][6].setTexture(neagraTexture), cards[0][6].setTextureRect(IntRect(0, 267, 180, 250));
        cards[0][7].setTexture(neagraTexture), cards[0][7].setTextureRect(IntRect(205, 267, 180, 250));
        cards[0][8].setTexture(neagraTexture), cards[0][8].setTextureRect(IntRect(409, 267, 180, 250));
        cards[0][9].setTexture(neagraTexture), cards[0][9].setTextureRect(IntRect(612, 267, 180, 250));
        cards[0][10].setTexture(neagraTexture), cards[0][10].setTextureRect(IntRect(815, 267, 178, 250));
        cards[0][11].setTexture(neagraTexture), cards[0][11].setTextureRect(IntRect(0, 0, 180, 250));
        cards[0][12].setTexture(neagraTexture), cards[0][12].setTextureRect(IntRect(0, 534, 180, 250));
        cards[0][13].setTexture(neagraTexture), cards[0][13].setTextureRect(IntRect(205, 534, 180, 250));
        cards[0][14].setTexture(neagraTexture), cards[0][14].setTextureRect(IntRect(409, 534, 180, 250));

        cards[1][1].setTexture(rosieTexture), cards[1][1].setTextureRect(IntRect(0, 0, 180, 250));
        cards[1][2].setTexture(rosieTexture), cards[1][2].setTextureRect(IntRect(205, 0, 180, 250));
        cards[1][3].setTexture(rosieTexture), cards[1][3].setTextureRect(IntRect(409, 0, 180, 250));
        cards[1][4].setTexture(rosieTexture), cards[1][4].setTextureRect(IntRect(612, 0, 180, 250));
        cards[1][5].setTexture(rosieTexture), cards[1][5].setTextureRect(IntRect(815, 0, 178, 250));
        cards[1][6].setTexture(rosieTexture), cards[1][6].setTextureRect(IntRect(0, 267, 180, 250));
        cards[1][7].setTexture(rosieTexture), cards[1][7].setTextureRect(IntRect(205, 267, 180, 250));
        cards[1][8].setTexture(rosieTexture), cards[1][8].setTextureRect(IntRect(409, 267, 180, 250));
        cards[1][9].setTexture(rosieTexture), cards[1][9].setTextureRect(IntRect(612, 267, 180, 250));
        cards[1][10].setTexture(rosieTexture), cards[1][10].setTextureRect(IntRect(815, 267, 178, 250));
        cards[1][11].setTexture(rosieTexture), cards[1][11].setTextureRect(IntRect(0, 0, 180, 250));
        cards[1][12].setTexture(rosieTexture), cards[1][12].setTextureRect(IntRect(0, 534, 180, 250));
        cards[1][13].setTexture(rosieTexture), cards[1][13].setTextureRect(IntRect(205, 534, 180, 250));
        cards[1][14].setTexture(rosieTexture), cards[1][14].setTextureRect(IntRect(409, 534, 180, 250));

        cards[2][1].setTexture(treflaTexture), cards[2][1].setTextureRect(IntRect(0, 0, 180, 250));
        cards[2][2].setTexture(treflaTexture), cards[2][2].setTextureRect(IntRect(205, 0, 180, 250));
        cards[2][3].setTexture(treflaTexture), cards[2][3].setTextureRect(IntRect(409, 0, 180, 250));
        cards[2][4].setTexture(treflaTexture), cards[2][4].setTextureRect(IntRect(612, 0, 180, 250));
        cards[2][5].setTexture(treflaTexture), cards[2][5].setTextureRect(IntRect(815, 0, 178, 250));
        cards[2][6].setTexture(treflaTexture), cards[2][6].setTextureRect(IntRect(0, 267, 180, 250));
        cards[2][7].setTexture(treflaTexture), cards[2][7].setTextureRect(IntRect(205, 267, 180, 250));
        cards[2][8].setTexture(treflaTexture), cards[2][8].setTextureRect(IntRect(409, 267, 180, 250));
        cards[2][9].setTexture(treflaTexture), cards[2][9].setTextureRect(IntRect(612, 267, 180, 250));
        cards[2][10].setTexture(treflaTexture), cards[2][10].setTextureRect(IntRect(815, 267, 178, 250));
        cards[2][11].setTexture(treflaTexture), cards[2][11].setTextureRect(IntRect(0, 0, 180, 250));
        cards[2][12].setTexture(treflaTexture), cards[2][12].setTextureRect(IntRect(0, 534, 180, 250));
        cards[2][13].setTexture(treflaTexture), cards[2][13].setTextureRect(IntRect(205, 534, 180, 250));
        cards[2][14].setTexture(treflaTexture), cards[2][14].setTextureRect(IntRect(409, 534, 180, 250));

        cards[3][1].setTexture(rombTexture), cards[3][1].setTextureRect(IntRect(0, 0, 180, 250));
        cards[3][2].setTexture(rombTexture), cards[3][2].setTextureRect(IntRect(205, 0, 180, 250));
        cards[3][3].setTexture(rombTexture), cards[3][3].setTextureRect(IntRect(409, 0, 180, 250));
        cards[3][4].setTexture(rombTexture), cards[3][4].setTextureRect(IntRect(612, 0, 180, 250));
        cards[3][5].setTexture(rombTexture), cards[3][5].setTextureRect(IntRect(815, 0, 178, 250));
        cards[3][6].setTexture(rombTexture), cards[3][6].setTextureRect(IntRect(0, 267, 180, 250));
        cards[3][7].setTexture(rombTexture), cards[3][7].setTextureRect(IntRect(205, 267, 180, 250));
        cards[3][8].setTexture(rombTexture), cards[3][8].setTextureRect(IntRect(409, 267, 180, 250));
        cards[3][9].setTexture(rombTexture), cards[3][9].setTextureRect(IntRect(612, 267, 180, 250));
        cards[3][10].setTexture(rombTexture), cards[3][10].setTextureRect(IntRect(815, 267, 178, 250));
        cards[3][11].setTexture(rombTexture), cards[3][11].setTextureRect(IntRect(0, 0, 180, 250));
        cards[3][12].setTexture(rombTexture), cards[3][12].setTextureRect(IntRect(0, 534, 180, 250));
        cards[3][13].setTexture(rombTexture), cards[3][13].setTextureRect(IntRect(205, 534, 180, 250));
        cards[3][14].setTexture(rombTexture), cards[3][14].setTextureRect(IntRect(409, 534, 180, 250));
        cards[4][1].setTexture(rosieTexture), cards[4][1].setTextureRect(IntRect(815, 534, 178, 250));
    }
    srand(time(0));
    balance = 100;
    while (window.isOpen()){
        Event evnt;
        while (window.pollEvent(evnt)){
            if (evnt.type == Event::Closed) {
                window.close();
            }
            if (evnt.type == Event::MouseButtonPressed) {
                if (evnt.key.code == Mouse::Left) {
                    float x, y;
                    x = Mouse::getPosition(window).x;
                    y = Mouse::getPosition(window).y;
                    //leave
                    if (x >= exitx1 && y >= exity1 && x <= exitx2 && y <= exity2) {
                        window.close();
                    }
                    //start
                    if (x >= betx1 && y >= bety1 && x <= betx2 && y <= bety2 && bet) {
                        if (start == true) {
                            nrCardsPlayer++;
                            int card = rand() % 13 + 2, type = rand() % 4;
                            while (f[type][card] == 1) {
                                card = rand() % 13 + 2, type = rand() % 4;
                            }                          
                            if (card == 11 && sumPlayer + 11 > 21) {
                                card = 1; 
                            }
                            f[type][card] = 1;
                            sumPlayer += (card <= 11 ? card : 10);
                            player[nrCardsPlayer].val = card;
                            player[nrCardsPlayer].tip = type;

                            nrCardsPlayer++;
                            card = rand() % 13 + 2, type = rand() % 4;
                            while (f[type][card] == 1) {
                                card = rand() % 13 + 2, type = rand() % 4;
                            }
                            if (card == 11 && sumPlayer + 11 > 21) {
                                card = 1;
                            }
                            f[type][card] = 1;
                            sumPlayer += (card <= 11 ? card : 10);
                            player[nrCardsPlayer].val = card;
                            player[nrCardsPlayer].tip = type;

                            nrCardsDealer++;
                            card = rand() % 13 + 2, type = rand() % 4;
                            while (f[type][card] == 1) {
                                card = rand() % 13 + 2, type = rand() % 4;
                            }
                            if (card == 11 && sumDealer + 11 > 21) {
                                card = 1;
                            }
                            f[type][card] = 1;
                            sumDealer += (card <= 11 ? card : 10);
                            dealer[nrCardsDealer].val = card;
                            dealer[nrCardsDealer].tip = type;

                            nrCardsDealer++;
                            card = rand() % 13 + 2, type = rand() % 4;
                            while (f[type][card] == 1) {
                                card = rand() % 13 + 2, type = rand() % 4;
                            }
                            if (card == 11 && sumDealer + 11 > 21) {
                                card = 1;
                            }
                            f[type][card] = 1;
                            sumDealer += (card <= 11 ? card : 10);
                            dealer[nrCardsDealer].val = card;
                            dealer[nrCardsDealer].tip = type;
                            start = false;
                            if (sumPlayer == 21 && nrCardsPlayer < 5) {
                                ch = 3;
                                finish = true;
                            }
                        }
                        else {
                            sumPlayer = 0, sumDealer = 0, nrCardsPlayer = 0, nrCardsDealer = 0, bet = 0;
                            start = true, finish = false, firstB = true;
                            for (int i = 0; i < 19; i++) {
                                for (int j = 0; j <= 19; j++) {
                                    f[i][j] = 0;
                                }
                            }
                        }
                    }
                    //double
                    else if (x >= doublex1 && y >= doubley1 && x <= doublex2 && y <= doubley2 && finish == false && nrCardsPlayer >= 2) {
                        if (sumPlayer < 21 && nrCardsPlayer < 5) { //mai ia o carte
                            nrCardsPlayer++;
                            int card = rand() % 13 + 2, type = rand() % 4;
                            while (f[type][card] == 1) {
                                card = rand() % 13 + 2, type = rand() % 4;
                            }
                            if (card == 11 && sumPlayer + 11 > 21) {
                                card = 1;
                            }
                            f[type][card] = 1;
                            sumPlayer += (card <= 11 ? card : 10);
                            player[nrCardsPlayer].val = card;
                            player[nrCardsPlayer].tip = type;
                        }
                        //lose
                        if (sumPlayer > 21 || (sumDealer > sumPlayer && sumDealer <= 21)) {
                            ch = 2;
                        }
                        //win
                        else if ((sumPlayer < 21 && sumPlayer > sumDealer) || sumDealer > 21) {
                            ch = 4;
                        }
                        //tie
                        else if (sumPlayer == sumDealer) {
                            ch = 5;
                        }
                        bet *= 2;
                        finish = true;
                    }
                    //hit
                    else if (x >= hitx1 && y >= hity1 && x <= hitx2 && y <= hity2 && finish == false && nrCardsPlayer >= 2) {
                        if (sumPlayer < 21 && nrCardsPlayer < 5) { //mai ia o carte
                            nrCardsPlayer++;
                            int card = rand() % 13 + 2, type = rand()%4;
                            while (f[type][card] == 1) {
                                card = rand() % 13 + 2, type = rand() % 4;
                            }
                            if (card == 11 && sumPlayer + 11 > 21) {
                                card = 1;
                            }
                            f[type][card] = 1;
                            sumPlayer += (card <= 11 ? card : 10);
                            player[nrCardsPlayer].val = card;
                            player[nrCardsPlayer].tip = type;
                        }
                        if (sumPlayer > 21 || nrCardsPlayer > 5) {
                            ch = 1;
                            finish = true;
                        }
                        if (sumPlayer == 21 && nrCardsPlayer < 5) {
                            ch = 3;
                            finish = true;
                        }
                    }
                    //stand
                    else if (x >= standx1 && y >= standy1 && x <= standx2 && y <= standy2 && finish == false && nrCardsPlayer >= 2) {
                        while (sumDealer < 17) {
                            nrCardsDealer++;
                            int card = rand() % 13 + 2, type = rand() % 4;
                            while (f[type][card] == 1) {
                                card = rand() % 13 + 2, type = rand() % 4;
                            }
                            if (card == 11 && sumDealer + 11 > 21) {
                                card = 1;
                            }
                            f[type][card] = 1;
                            sumDealer += (card <= 11 ? card : 10);
                            dealer[nrCardsDealer].val = card;
                            dealer[nrCardsDealer].tip = type;
                        }
                        //lose
                        if (sumPlayer > 21 || (sumDealer > sumPlayer && sumDealer <= 21)) {
                            ch = 2;
                            finish = true;
                        }
                        //win
                        else if ((sumPlayer < 21 && sumPlayer > sumDealer) || sumDealer > 21) {
                            ch = 4;
                            finish = true;
                        }
                        //tie
                        else if (sumPlayer == sumDealer){
                            ch = 5;
                            finish = true;
                        }
                    }
                    else if (x >= coin1x1 && y >= coin1y1 && x <= coin1x2 && y <= coin1y2 && start == true && balance >= bet + 1) {
                        bet += 1;
                    }
                    else if (x >= coin5x1 && y >= coin5y1 && x <= coin5x2 && y <= coin5y2 && start == true && balance >= bet + 5) {
                        bet += 5;
                    }
                    else if (x >= coin10x1 && y >= coin10y1 && x <= coin10x2 && y <= coin10y2 && start == true && balance >= bet + 10) {
                        bet += 10;
                    }
                    else if (x >= coin25x1 && y >= coin25y1 && x <= coin25x2 && y <= coin25y2 && start == true && balance >= bet + 25) {
                        bet += 25;
                    }
                    else if (x >= coin50x1 && y >= coin50y1 && x <= coin50x2 && y <= coin50y2 && start == true && balance >= bet + 50) {
                        bet += 50;
                    }
                    else if (x >= coin100x1 && y >= coin100y1 && x <= coin100x2 && y <= coin100y2 && start == true && balance >= bet + 100) {
                        bet += 100;
                    }
                    else if (x >= betmaxx1 && y >= betmaxy1 && x <= betmaxx2 && y <= betmaxy2 && start == true && balance > 0) {
                        bet = balance;
                    }
                }
            }
        }
        if (balance < 0) {
            balance = 0;
        }
        window.draw(background);
        window.draw(betButton);
        window.draw(betmaxButton);
        if (start == false) {
            window.draw(hitButton);
            window.draw(standButton);
            window.draw(doubleButton);
        }
        window.draw(exitButton);
        window.draw(coin1), window.draw(coin5), window.draw(coin10), window.draw(coin25), window.draw(coin50), window.draw(coin100);
        string pSc = "Your score: " + to_string(sumPlayer);
        string betV = "Your bet is: " + to_string(bet) + "$";
        string pBalance = "Balance: " + to_string(balance) + "$";
        Text playerScoreText, betPlayerText, balanceText;
        playerScoreText.setString(pSc), playerScoreText.setFont(fnt), playerScoreText.setCharacterSize(50), playerScoreText.setPosition(65, screenY-355), playerScoreText.setOutlineThickness(3);
        betPlayerText.setString(betV), betPlayerText.setFont(fnt), betPlayerText.setCharacterSize(50), betPlayerText.setPosition(65, screenY - 285), betPlayerText.setOutlineThickness(3);
        balanceText.setString(pBalance), balanceText.setFont(fnt), balanceText.setCharacterSize(50), balanceText.setPosition(480, screenY - 355), balanceText.setOutlineThickness(3);
        window.draw(playerScoreText);
        window.draw(betPlayerText);
        window.draw(balanceText);
        int pos = 65;
        for (int i = 1; i <= nrCardsPlayer; i++) {
            int p1 = player[i].tip, c1 = player[i].val;
            cards[p1][c1].setPosition(pos, screenY-630);
            pos += 180;
            window.draw(cards[p1][c1]);
        }
        if (nrCardsDealer > 1) {
            cards[4][1].setPosition(65, screenY-910);
            window.draw(cards[4][1]);
        }
        int pos2 = 65 + 180;
        for (int i = 2; i <= nrCardsDealer; i++) {
            int p1 = dealer[i].tip, c1 = dealer[i].val;
            cards[p1][c1].setPosition(pos2, screenY - 910);
            pos2 += 180;
            window.draw(cards[p1][c1]);
        }
        //finish
        if (finish == true) {
            int p1 = dealer[1].tip, c1 = dealer[1].val;
            cards[p1][c1].setPosition(65, screenY - 910);
            window.draw(cards[p1][c1]);
            string dSc = "Dealer: " + to_string(sumDealer);
            Text dealerScoreText;
            dealerScoreText.setString(dSc), dealerScoreText.setFont(fnt), dealerScoreText.setCharacterSize(50), dealerScoreText.setPosition(65, screenY - 1000), dealerScoreText.setOutlineThickness(3);
            window.draw(dealerScoreText);
            if (ch == 1) {
                Text busted;
                busted.setString("Busted! You lose!"), busted.setFont(fnt), busted.setCharacterSize(100), busted.setPosition(660, 30), busted.setOutlineThickness(3);
                window.draw(busted);
                if (firstB == true) {
                    balance -= bet;
                    firstB = false;
                }
            }
            else if (ch == 2) {
                Text youLose;
                youLose.setString("You lose!"), youLose.setFont(fnt), youLose.setCharacterSize(100), youLose.setPosition(810, 30), youLose.setOutlineThickness(3);
                window.draw(youLose);
                if (firstB == true) {
                    balance -= bet;
                    firstB = false;
                }
            }
            else if (ch == 3) {
                Text blackjack;
                blackjack.setString("Blackjack! You win!"), blackjack.setFont(fnt), blackjack.setCharacterSize(100), blackjack.setPosition(630, 30), blackjack.setOutlineThickness(3);
                window.draw(blackjack);
                if (firstB == true) {
                    balance += bet;
                    firstB = false;
                }
            }
            else if (ch == 4) {
                Text youWin;
                youWin.setString("You win!"), youWin.setFont(fnt), youWin.setCharacterSize(100), youWin.setPosition(820, 30), youWin.setOutlineThickness(3);
                window.draw(youWin);
                if (firstB == true) {
                    balance += bet;
                    firstB = false;
                }
            }
            else if (ch == 5) {
                Text tie;
                tie.setString("Tie!"), tie.setFont(fnt), tie.setCharacterSize(100), tie.setPosition(900, 30), tie.setOutlineThickness(3);
                window.draw(tie);
            }
        }
        window.display();
    }
    return 0;
}
//1920 1080