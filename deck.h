#ifndef _DECK_H_
#define _DECK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

/**
* enum kind_e - kinds of cards
* @SPADE: spade
* @HEART: heart
* @CLUB: club
* @DIAMOND: diamond
*/
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
* struct deck_node_s - Deck of card
* @card: Pointer to the card of the node
* @prev: Pointer to previous node of the list
* @next: Pointer to next node of the list
*/
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/********** Prototypes **********/
void sort_deck(deck_node_t **deck);
int card_value(deck_node_t *node);
int _strcmp(const char *s1, const char *s2);
size_t list_len_deck(deck_node_t *list);

#endif /* _DECK_H_ */
