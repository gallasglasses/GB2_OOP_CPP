// HW2.cpp

#include <iostream>

//This is 1 exercise
#include "Person.h"
#include "Student.h"
#include <algorithm> 
#include <vector>
#include <functional>

int Student::s_idGenerator = 1;
void printStudentByID(std::vector <Student> list);

//This is 2 exercise
#include "Fruit.h"
#include "Apple.h"
#include "Banana.h"
#include "GrannySmith.h"

int main()
{
    //This is 1 exercise

    std::vector <Student> listStudent;
    Student Ivan("Ivanov Ivan Ivanovich", 26, 75.6, 5, MALE);
    listStudent.push_back(Ivan);
    Student Petr("Petrov Petr Petrovich", 21, 66.6, 3, MALE);
    listStudent.push_back(Petr);
    Student Maxim("Maximov Maxim Maximovich", 19, 57.2, 1, MALE);
    Maxim.incrementYearStudy();
    Maxim.setAge(20);
    Maxim.setWeight(59.0);
    listStudent.push_back(Maxim);

    printStudentByID(listStudent);

    //This is 2 exercise

    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColour() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColour() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColour() << ".\n";


    //This is 3 exercise
    {
        void Game()
        {
            void Hit();
            void Stand();
            void DoubleDown();
            void Surrender();
        }

        class Card
        {
        private:
            std::string cardFace; //rank: Ace, King, Queen, Jack, 10, 9, 8, 7, 6, 5, 4, 3, 2
            std::string cardSuit; //suit: clubs, diamonds, hearts, and spades

        public:
            Card(std::string face = "", std::string suit = "")
                : cardFace(face),
                cardSuit(suit)
            {

            }
            std::string printCard() const
            {
                return cardFace + " of " + cardSuit;
            }
            Card()
            {

            }
        };

        const size_t SIZE_DECK_1 = 52; // if 1 deck -> size_of_deck
        const size_t SIZE_DECK_2 = 260; // if 6 decks -> size_of_deck

        class Deсk
        {
        private:
            Card* deck;
            int currentCard;
        public: 
            Deck()
            {
                currentCard = 0;
                for (size_t i = 0; i < size_of_deck; i++)
                {
                    // deck[i] = card(face [countFace % 13], suit[countSuit % 4] }
                }
            }

            void RandomShuffling()
            {
                currentCard = 0;
                for (size_t i = 0; i < size_of_deck; i++)
                {
                    int j = (rand() + time(0)) % size_of_deck;
                    Card freshDeck = deck[i];
                    deck[i] = deck[j];
                    deck[j] = freshDeck;
                }
            }

            void printCard() const
            {

            }
            
            Card distributionOfCards()
            {
                if (size_of_deck == SIZE_DECK_1)
                {
                    if (!roundGame) // if the game round is over, then the decks must be shuffled 
                        RandomShuffling();
                    if (roundGame) //if the game round is continue, a new card is dealt
                        return (deck[currentCard++]);
                    return (deck[0]);
                }
                if (size_of_deck == SIZE_DECK_2)
                {
                    if (currentCard > ((2 * size_of_deck) / 3))
                        RandomShuffling();
                    if (currentCard < ((2 * size_of_deck) / 3))
                        return deck[currentCard++];
                    return deck[0];
                }

            }
        };

        class Hand
        {
            Card* handCard;
        };

        class PatternPlayer : public Hand
        {
        private:
            std::string m_name;

        protected:
            int m_money;

        public:
            PatternPlayer(std::string name, int money)
                : m_name(name),
                m_money(money)
            {
                
            }

            std::string getName()
            {
                return m_name;
            }

            int getMoney()
            {
                return m_money;
            }
        };

        class Player : public PatternPlayer
        {
        private:
            int m_bet;

        protected:
            Player(std::string name, int money, int bet)
                : PatternPlayer(name, money), 
                m_bet(bet)
            {

            }

        public:
            Player(std::string name)
                : PatternPlayer(name, 25000),
                m_bet(0)
            {

            }

            void minusMoney()
            {
                m_money = m_money - m_bet;
            }

            void plusMoney()
            {
                m_money = m_money + m_bet;
            }
        };

        class Dealer : public PatternPlayer
        {
        protected:
            Dealer(std::string name, int money)
                : PatternPlayer(name, money)
            {

            }

        public:
            Dealer()
                : PatternPlayer("Dealer", 0)
            {

            }
        };
    }

    return 0;
}

//This is 1 exercise
void printStudentByID(std::vector <Student> list)
{
    std::cout << "Enter student ID : ";
    int numberID;
    std::cin >> numberID;

    for (int count = 0; count < list.size(); ++count)
    {
        if (list[count].getID() == numberID)
        {
            std::cout << "Student ID " << list[count].getID() << "\n";
            std::cout << "Name : " << list[count].getName() << "\n";
            std::cout << "Year : " << list[count].getYearStudy() << "\n";
            std::cout << "Age : " << list[count].getAge() << "\n";
            std::cout << "Weight : " << list[count].getWeight() << "\n" << std::endl;
        }
    }
}



    
