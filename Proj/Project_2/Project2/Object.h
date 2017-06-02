/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Object.h
 * Author: admin
 *
 * Created on May 29, 2017, 1:19 PM
 */

#ifndef OBJECT_H
#define OBJECT_H

class Object {
private:
    char symbol = ' '; /*!< Symbol will be displayed on screen */
    int x; /*!< Coordinates  X */
    int y; /*!< Coordinates  Y */
    int points; /*!< The point receive after collistion */
public:
    /*!
     * \brief Constructor of Object class
     * \param none
     * \return none
     */
    Object();
    /*!
     * \brief set the value of Coordinates Y
     * \param Y - The value of Coordinates Y
     * \return none
     */
    void setY(int);
    /*!
     * \brief Get the Coordinates Y
     * \param none
     * \return none
     */
    int getY() const;
    /*!
     * \brief set the value of Coordinates X
     * \param X - The value of Coordinates X
     * \return none
     */
    void setX(int);
    /*!
     * \brief Get the Coordinates X
     * \param none
     * \return none
     */
    int getX() const;
    /*!
     * \brief Get the symbol
     * \param none
     * \return none
     */
    char getSymbol() const;
    void operator=(const Object&);
    /*!
     * \brief set the value of points
     * \param point - The value of points
     * \return none
     */
    void setPoints(int points);
    /*!
     * \brief Get the next node
     * \param none
     * \return none
     */
    int getPoints() const;
protected:
    /*!
     * \brief set the value of symbol
     * \param symbol - The value of symbol
     * \return none
     */
    void setSymbol(char);
};

#endif /* OBJECT_H */

