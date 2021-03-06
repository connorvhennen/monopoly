//
//  player.hpp
//  BruteForceMonopolyCode
//
//  Created by Connor Hennen on 3/18/17.
//  Copyright © 2017 Connor Hennen. All rights reserved.
//
//class Gameboard;

#include <map>

#include "Gameboard.h"
#include "communityChest.h"
#include "chanceDeck.h"
#include "gamescreen.h"
#include "mainwindow.h"
#include <time.h>
#include <QMap>
#include <QString>
#include <QWidget>
#include <string>
#include <algorithm>


class space;
class gamescreen;
class communityCards;
class chanceCard;
class mainwindow;
#ifndef player_hpp
#define player_hpp

class player;
extern std::map<int, player*> playerMap;

#include <string>
#include <time.h>


extern int playerTag;
//extern std::vector<player*> playerList;
//struct playerCount{
//        int playerTag;
//} thisGame

class player{
    friend class gamescreen;
    friend class communityCards;
    friend class chanceCard;
    friend class mainwindow;
public:

    //default constructor
    player();

    player(std::string title, int start=1, int inheritance=1500){
        name = title;
        location = start;
        money = inheritance;
        academicProbation = 0;
        acedMidterms = false;
        dormArrest = false;
        doubles = 0;
        dropLowestMidterm = false;

        /*the player class constructor inserts a pair into the playerMap, where a player's tag
        can be used to retrieve the exact player object
        */
        playerMap.insert(std::pair<int,player*>(playerTag,this));
        playerTag = playerTag + 1;
        eliminated = false;
        netWorth = 1500;
    }

    void turn();
    void turn2();
    void buyProperty(int cost, space mine);

    std::string get_playerName();

    int get_location();

    void rollDice();
    void roll2Dice();

    int getTag();

    void payRent(int rentLoss);

    void communityDraw();

    void chanceDraw();
    int movement;

    std::string name;
    int tag;
    int location;

    int academicProbation;
    bool acedMidterms;
    bool dormArrest;
    bool dropLowestMidterm;
    int money;
    int doubles;
    bool eliminated;
    int netWorth;
    std::vector<space> landOwned;

    void swap(player& other){
           std::swap(name,other.name);
           std::swap(tag,other.tag);
           std::swap(location,other.location);
           std::swap(academicProbation,other.academicProbation);
           std::swap(acedMidterms,other.acedMidterms);
           std::swap(money,other.money);
           std::swap(netWorth,other.netWorth);
           std::swap(eliminated,other.eliminated);
           std::swap(dormArrest,other.dormArrest);
           std::swap(dropLowestMidterm,other.dropLowestMidterm);
           std::swap(landOwned,other.landOwned);
       }

    //assignment operator
       player& operator=(player other)
       {
           swap(other);
           return *this;
       }

       //move constructor
//       player(player&& other)
//           : player()
//       {
//           swap(other);
//       }


private:

};


//templated comparison class, will be used for sorting (shuffling) the chance and community card decks.
template <typename T>
class RandomOrder{
public:
    bool operator()( const T& , const T& ) const{

        return ( rand() % 2 ) == 0 ? true : false ;
    }
};



#endif /* player_hpp */
