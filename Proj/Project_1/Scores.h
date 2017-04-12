/**
 * @file   Scores.h
 * @Author Nhan Mac
 * @date   April, 2017
 * @brief  Information of high score
 *
 * Structure Score stores the information of user
 * who has the high score in game with name, score, and rank
 */

#ifndef SCORES_H
#define	SCORES_H

struct Scores {
    int rank;/*!< The rank of user depend on score */
    string name;/*!< Name of user */
    int scores;/*!< Score of user */
};

#endif	/* SCORES_H */

