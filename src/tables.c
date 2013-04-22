/* File: tables.c */

/* Purpose: Angband Tables */

/*
 * Copyright (c) 1989 James E. Wilson, Robert A. Koeneke
 *
 * This software may be copied and distributed for educational, research, and
 * not for profit purposes provided that this copyright and statement are
 * included in all such copies.
 */

#include "angband.h"




/*
 * Global array for looping through the "keypad directions"
 */
s16b ddd[9] =
{ 2, 8, 6, 4, 3, 1, 9, 7, 5 };

/*
 * Global arrays for converting "keypad direction" into offsets
 */
s16b ddx[10] =
{ 0, -1, 0, 1, -1, 0, 1, -1, 0, 1 };

s16b ddy[10] =
{ 0, 1, 1, 1, 0, 0, 0, -1, -1, -1 };

/*
 * Global arrays for optimizing "ddx[ddd[i]]" and "ddy[ddd[i]]"
 */
s16b ddx_ddd[9] =
{ 0, 0, 1, -1, 1, -1, 1, -1, 0 };

s16b ddy_ddd[9] =
{ 1, -1, 0, 0, 1, 1, -1, -1, 0 };



/*
* Global array for converting numbers to uppercase hexadecimal digit
 * This array can also be used to convert a number to an octal digit
 */
char hexsym[16] =
{
	'0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};


/*
 * Stat Table (INT/WIS) -- Number of half-spells per level
 */
byte adj_mag_study[] =
{
	0	/* 3 */,
	0	/* 4 */,
	0	/* 5 */,
	0	/* 6 */,
	0	/* 7 */,
	1	/* 8 */,
	1	/* 9 */,
	1	/* 10 */,
	1	/* 11 */,
	2	/* 12 */,
	2	/* 13 */,
	2	/* 14 */,
	2	/* 15 */,
	2	/* 16 */,
	2	/* 17 */,
	2	/* 18/00-18/09 */,
	2	/* 18/10-18/19 */,
	2	/* 18/20-18/29 */,
	2	/* 18/30-18/39 */,
	2	/* 18/40-18/49 */,
	3	/* 18/50-18/59 */,
	3	/* 18/60-18/69 */,
	3	/* 18/70-18/79 */,
	3	/* 18/80-18/89 */,
	4	/* 18/90-18/99 */,
	4	/* 18/100-18/109 */,
	4	/* 18/110-18/119 */,
	5	/* 18/120-18/129 */,
	5	/* 18/130-18/139 */,
	5	/* 18/140-18/149 */,
	5	/* 18/150-18/159 */,
	5	/* 18/160-18/169 */,
	5	/* 18/170-18/179 */,
	5	/* 18/180-18/189 */,
	5	/* 18/190-18/199 */,
	5	/* 18/200-18/209 */,
	6	/* 18/210-18/219 */,
	6	/* 18/220+ */
};


/*
 * Stat Table (INT/WIS) -- extra half-mana-points per level
 */
byte adj_mag_mana[] =
{
	0       /* 3 */,
	0       /* 4 */,
	0       /* 5 */,
	0       /* 6 */,
	0       /* 7 */,
	1       /* 8 */,
	2       /* 9 */,
	2       /* 10 */,
	2       /* 11 */,
	2       /* 12 */,
	2       /* 13 */,
	2       /* 14 */,
	2       /* 15 */,
	2       /* 16 */,
	2       /* 17 */,
	3       /* 18/00-18/09 */,
	3       /* 18/10-18/19 */,
	3       /* 18/20-18/29 */,
	3       /* 18/30-18/39 */,
	3       /* 18/40-18/49 */,
	4       /* 18/50-18/59 */,
	4       /* 18/60-18/69 */,
	5       /* 18/70-18/79 */,
	6       /* 18/80-18/89 */,
	7       /* 18/90-18/99 */,
	8       /* 18/100-18/109 */,
	9       /* 18/110-18/119 */,
	10      /* 18/120-18/129 */,
	11      /* 18/130-18/139 */,
	12      /* 18/140-18/149 */,
	13      /* 18/150-18/159 */,
	14      /* 18/160-18/169 */,
	15      /* 18/170-18/179 */,
	16      /* 18/180-18/189 */,
	16      /* 18/190-18/199 */,
	17      /* 18/200-18/209 */,
	17      /* 18/210-18/219 */,
	18      /* 18/220+ */
};


/*
 * Stat Table (INT/WIS) -- Minimum failure rate (percentage)
 */
byte adj_mag_fail[] =
{
	99      /* 3 */,
	99      /* 4 */,
	99      /* 5 */,
	99      /* 6 */,
	99      /* 7 */,
	50      /* 8 */,
	30      /* 9 */,
	20      /* 10 */,
	15      /* 11 */,
	12      /* 12 */,
	11      /* 13 */,
	10      /* 14 */,
	9       /* 15 */,
	8       /* 16 */,
	7       /* 17 */,
	6       /* 18/00-18/09 */,
	6       /* 18/10-18/19 */,
	5       /* 18/20-18/29 */,
	5       /* 18/30-18/39 */,
	5       /* 18/40-18/49 */,
	4       /* 18/50-18/59 */,
	4       /* 18/60-18/69 */,
	4       /* 18/70-18/79 */,
	4       /* 18/80-18/89 */,
	3       /* 18/90-18/99 */,
	3       /* 18/100-18/109 */,
	2       /* 18/110-18/119 */,
	2       /* 18/120-18/129 */,
	2       /* 18/130-18/139 */,
	2       /* 18/140-18/149 */,
	1       /* 18/150-18/159 */,
	1       /* 18/160-18/169 */,
	1       /* 18/170-18/179 */,
	1       /* 18/180-18/189 */,
	1       /* 18/190-18/199 */,
	0       /* 18/200-18/209 */,
	0       /* 18/210-18/219 */,
	0       /* 18/220+ */
};


/*
 * Stat Table (INT/WIS) -- Various things
 */
byte adj_mag_stat[] =
{
	0       /* 3 */,
	0       /* 4 */,
	0       /* 5 */,
	0       /* 6 */,
	0       /* 7 */,
	1       /* 8 */,
	1       /* 9 */,
	1       /* 10 */,
	1       /* 11 */,
	1       /* 12 */,
	1       /* 13 */,
	1       /* 14 */,
	2       /* 15 */,
	2       /* 16 */,
	2       /* 17 */,
	3       /* 18/00-18/09 */,
	3       /* 18/10-18/19 */,
	3       /* 18/20-18/29 */,
	3       /* 18/30-18/39 */,
	3       /* 18/40-18/49 */,
	4       /* 18/50-18/59 */,
	4       /* 18/60-18/69 */,
	5       /* 18/70-18/79 */,
	6       /* 18/80-18/89 */,
	7       /* 18/90-18/99 */,
	8       /* 18/100-18/109 */,
	9       /* 18/110-18/119 */,
	10      /* 18/120-18/129 */,
	11      /* 18/130-18/139 */,
	12      /* 18/140-18/149 */,
	13      /* 18/150-18/159 */,
	14      /* 18/160-18/169 */,
	15      /* 18/170-18/179 */,
	16      /* 18/180-18/189 */,
	17      /* 18/190-18/199 */,
	18      /* 18/200-18/209 */,
	19      /* 18/210-18/219 */,
	20      /* 18/220+ */
};


/*
 * Stat Table (CHR) -- payment percentages
 */
byte adj_chr_gold[] =
{
	130     /* 3 */,
	125     /* 4 */,
	122     /* 5 */,
	120     /* 6 */,
	118     /* 7 */,
	116     /* 8 */,
	114     /* 9 */,
	112     /* 10 */,
	110     /* 11 */,
	108     /* 12 */,
	106     /* 13 */,
	104     /* 14 */,
	103     /* 15 */,
	102     /* 16 */,
	101     /* 17 */,
	100     /* 18/00-18/09 */,
	99      /* 18/10-18/19 */,
	98      /* 18/20-18/29 */,
	97      /* 18/30-18/39 */,
	96      /* 18/40-18/49 */,
	95      /* 18/50-18/59 */,
	94      /* 18/60-18/69 */,
	93      /* 18/70-18/79 */,
	92      /* 18/80-18/89 */,
	91      /* 18/90-18/99 */,
	90      /* 18/100-18/109 */,
	89      /* 18/110-18/119 */,
	88      /* 18/120-18/129 */,
	87      /* 18/130-18/139 */,
	86      /* 18/140-18/149 */,
	85      /* 18/150-18/159 */,
	84      /* 18/160-18/169 */,
	83      /* 18/170-18/179 */,
	82      /* 18/180-18/189 */,
	81      /* 18/190-18/199 */,
	80      /* 18/200-18/209 */,
	79      /* 18/210-18/219 */,
	78      /* 18/220+ */
};


/*
 * Stat Table (INT) -- Magic devices
 */
byte adj_int_dev[] =
{
	0       /* 3 */,
	0       /* 4 */,
	0       /* 5 */,
	0       /* 6 */,
	0       /* 7 */,
	1       /* 8 */,
	1       /* 9 */,
	1       /* 10 */,
	1       /* 11 */,
	1       /* 12 */,
	1       /* 13 */,
	1       /* 14 */,
	2       /* 15 */,
	2       /* 16 */,
	2       /* 17 */,
	3       /* 18/00-18/09 */,
	3       /* 18/10-18/19 */,
	4       /* 18/20-18/29 */,
	4       /* 18/30-18/39 */,
	5       /* 18/40-18/49 */,
	5       /* 18/50-18/59 */,
	6       /* 18/60-18/69 */,
	6       /* 18/70-18/79 */,
	7       /* 18/80-18/89 */,
	7       /* 18/90-18/99 */,
	8       /* 18/100-18/109 */,
	9       /* 18/110-18/119 */,
	10      /* 18/120-18/129 */,
	11      /* 18/130-18/139 */,
	12      /* 18/140-18/149 */,
	13      /* 18/150-18/159 */,
	14      /* 18/160-18/169 */,
	15      /* 18/170-18/179 */,
	16      /* 18/180-18/189 */,
	17      /* 18/190-18/199 */,
	18      /* 18/200-18/209 */,
	19      /* 18/210-18/219 */,
	20      /* 18/220+ */
};


/*
 * Stat Table (WIS) -- Saving throw
 */
byte adj_wis_sav[] =
{
	0       /* 3 */,
	0       /* 4 */,
	0       /* 5 */,
	0       /* 6 */,
	0       /* 7 */,
	1       /* 8 */,
	1       /* 9 */,
	1       /* 10 */,
	1       /* 11 */,
	1       /* 12 */,
	1       /* 13 */,
	1       /* 14 */,
	2       /* 15 */,
	2       /* 16 */,
	2       /* 17 */,
	3       /* 18/00-18/09 */,
	3       /* 18/10-18/19 */,
	3       /* 18/20-18/29 */,
	3       /* 18/30-18/39 */,
	3       /* 18/40-18/49 */,
	4       /* 18/50-18/59 */,
	4       /* 18/60-18/69 */,
	5       /* 18/70-18/79 */,
	5       /* 18/80-18/89 */,
	6       /* 18/90-18/99 */,
	7       /* 18/100-18/109 */,
	8       /* 18/110-18/119 */,
	9       /* 18/120-18/129 */,
	10      /* 18/130-18/139 */,
	11      /* 18/140-18/149 */,
	12      /* 18/150-18/159 */,
	13      /* 18/160-18/169 */,
	14      /* 18/170-18/179 */,
	15      /* 18/180-18/189 */,
	16      /* 18/190-18/199 */,
	17      /* 18/200-18/209 */,
	18      /* 18/210-18/219 */,
	19      /* 18/220+ */
};


/*
 * Stat Table (DEX) -- disarming
 */
byte adj_dex_dis[] =
{
	0       /* 3 */,
	0       /* 4 */,
	0       /* 5 */,
	0       /* 6 */,
	0       /* 7 */,
	0       /* 8 */,
	0       /* 9 */,
	0       /* 10 */,
	0       /* 11 */,
	0       /* 12 */,
	1       /* 13 */,
	1       /* 14 */,
	1       /* 15 */,
	2       /* 16 */,
	2       /* 17 */,
	4       /* 18/00-18/09 */,
	4       /* 18/10-18/19 */,
	4       /* 18/20-18/29 */,
	4       /* 18/30-18/39 */,
	5       /* 18/40-18/49 */,
	5       /* 18/50-18/59 */,
	5       /* 18/60-18/69 */,
	6       /* 18/70-18/79 */,
	6       /* 18/80-18/89 */,
	7       /* 18/90-18/99 */,
	8       /* 18/100-18/109 */,
	8       /* 18/110-18/119 */,
	8       /* 18/120-18/129 */,
	8       /* 18/130-18/139 */,
	8       /* 18/140-18/149 */,
	9       /* 18/150-18/159 */,
	9       /* 18/160-18/169 */,
	9       /* 18/170-18/179 */,
	9       /* 18/180-18/189 */,
	9       /* 18/190-18/199 */,
	10      /* 18/200-18/209 */,
	10      /* 18/210-18/219 */,
	10      /* 18/220+ */
};


/*
 * Stat Table (INT) -- disarming
 */
byte adj_int_dis[] =
{
	0       /* 3 */,
	0       /* 4 */,
	0       /* 5 */,
	0       /* 6 */,
	0       /* 7 */,
	1       /* 8 */,
	1       /* 9 */,
	1       /* 10 */,
	1       /* 11 */,
	1       /* 12 */,
	1       /* 13 */,
	1       /* 14 */,
	2       /* 15 */,
	2       /* 16 */,
	2       /* 17 */,
	3       /* 18/00-18/09 */,
	3       /* 18/10-18/19 */,
	3       /* 18/20-18/29 */,
	4       /* 18/30-18/39 */,
	4       /* 18/40-18/49 */,
	5       /* 18/50-18/59 */,
	6       /* 18/60-18/69 */,
	7       /* 18/70-18/79 */,
	8       /* 18/80-18/89 */,
	9       /* 18/90-18/99 */,
	10      /* 18/100-18/109 */,
	10      /* 18/110-18/119 */,
	11      /* 18/120-18/129 */,
	12      /* 18/130-18/139 */,
	13      /* 18/140-18/149 */,
	14      /* 18/150-18/159 */,
	15      /* 18/160-18/169 */,
	16      /* 18/170-18/179 */,
	17      /* 18/180-18/189 */,
	18      /* 18/190-18/199 */,
	19      /* 18/200-18/209 */,
	19      /* 18/210-18/219 */,
	20      /* 18/220+ */
};


/*
 * Stat Table (DEX) -- bonus to ac (plus 128)
 */
byte adj_dex_ta[] =
{
	128 + -4        /* 3 */,
	128 + -3        /* 4 */,
	128 + -2        /* 5 */,
	128 + -1        /* 6 */,
	128 + 0 /* 7 */,
	128 + 0 /* 8 */,
	128 + 0 /* 9 */,
	128 + 0 /* 10 */,
	128 + 0 /* 11 */,
	128 + 0 /* 12 */,
	128 + 0 /* 13 */,
	128 + 0 /* 14 */,
	128 + 1 /* 15 */,
	128 + 1 /* 16 */,
	128 + 1 /* 17 */,
	128 + 2 /* 18/00-18/09 */,
	128 + 2 /* 18/10-18/19 */,
	128 + 2 /* 18/20-18/29 */,
	128 + 2 /* 18/30-18/39 */,
	128 + 2 /* 18/40-18/49 */,
	128 + 3 /* 18/50-18/59 */,
	128 + 3 /* 18/60-18/69 */,
	128 + 3 /* 18/70-18/79 */,
	128 + 4 /* 18/80-18/89 */,
	128 + 5 /* 18/90-18/99 */,
	128 + 6 /* 18/100-18/109 */,
	128 + 7 /* 18/110-18/119 */,
	128 + 8 /* 18/120-18/129 */,
	128 + 9 /* 18/130-18/139 */,
	128 + 9 /* 18/140-18/149 */,
	128 + 10        /* 18/150-18/159 */,
	128 + 11        /* 18/160-18/169 */,
	128 + 12        /* 18/170-18/179 */,
	128 + 13        /* 18/180-18/189 */,
	128 + 14        /* 18/190-18/199 */,
	128 + 15        /* 18/200-18/209 */,
	128 + 15        /* 18/210-18/219 */,
	128 + 16        /* 18/220+ */
};


/*
 * Stat Table (STR) -- bonus to dam (plus 128)
 */
byte adj_str_td[] =
{
	128 + -2        /* 3 */,
	128 + -2        /* 4 */,
	128 + -1        /* 5 */,
	128 + -1        /* 6 */,
	128 + 0 /* 7 */,
	128 + 0 /* 8 */,
	128 + 0 /* 9 */,
	128 + 0 /* 10 */,
	128 + 0 /* 11 */,
	128 + 0 /* 12 */,
	128 + 0 /* 13 */,
	128 + 0 /* 14 */,
	128 + 0 /* 15 */,
	128 + 1 /* 16 */,
	128 + 2 /* 17 */,
	128 + 2 /* 18/00-18/09 */,
	128 + 2 /* 18/10-18/19 */,
	128 + 3 /* 18/20-18/29 */,
	128 + 3 /* 18/30-18/39 */,
	128 + 3 /* 18/40-18/49 */,
	128 + 3 /* 18/50-18/59 */,
	128 + 3 /* 18/60-18/69 */,
	128 + 4 /* 18/70-18/79 */,
	128 + 5 /* 18/80-18/89 */,
	128 + 5 /* 18/90-18/99 */,
	128 + 6 /* 18/100-18/109 */,
	128 + 7 /* 18/110-18/119 */,
	128 + 8 /* 18/120-18/129 */,
	128 + 9 /* 18/130-18/139 */,
	128 + 10        /* 18/140-18/149 */,
	128 + 11        /* 18/150-18/159 */,
	128 + 12        /* 18/160-18/169 */,
	128 + 13        /* 18/170-18/179 */,
	128 + 14        /* 18/180-18/189 */,
	128 + 15        /* 18/190-18/199 */,
	128 + 16        /* 18/200-18/209 */,
	128 + 18        /* 18/210-18/219 */,
	128 + 20        /* 18/220+ */
};


/*
 * Stat Table (DEX) -- bonus to hit (plus 128)
 */
byte adj_dex_th[] =
{
	128 + -3        /* 3 */,
	128 + -2        /* 4 */,
	128 + -2        /* 5 */,
	128 + -1        /* 6 */,
	128 + -1        /* 7 */,
	128 + 0 /* 8 */,
	128 + 0 /* 9 */,
	128 + 0 /* 10 */,
	128 + 0 /* 11 */,
	128 + 0 /* 12 */,
	128 + 0 /* 13 */,
	128 + 0 /* 14 */,
	128 + 0 /* 15 */,
	128 + 1 /* 16 */,
	128 + 2 /* 17 */,
	128 + 3 /* 18/00-18/09 */,
	128 + 3 /* 18/10-18/19 */,
	128 + 3 /* 18/20-18/29 */,
	128 + 3 /* 18/30-18/39 */,
	128 + 3 /* 18/40-18/49 */,
	128 + 4 /* 18/50-18/59 */,
	128 + 4 /* 18/60-18/69 */,
	128 + 4 /* 18/70-18/79 */,
	128 + 4 /* 18/80-18/89 */,
	128 + 5 /* 18/90-18/99 */,
	128 + 6 /* 18/100-18/109 */,
	128 + 7 /* 18/110-18/119 */,
	128 + 8 /* 18/120-18/129 */,
	128 + 9 /* 18/130-18/139 */,
	128 + 9 /* 18/140-18/149 */,
	128 + 10        /* 18/150-18/159 */,
	128 + 11        /* 18/160-18/169 */,
	128 + 12        /* 18/170-18/179 */,
	128 + 13        /* 18/180-18/189 */,
	128 + 14        /* 18/190-18/199 */,
	128 + 15        /* 18/200-18/209 */,
	128 + 15        /* 18/210-18/219 */,
	128 + 16        /* 18/220+ */
};


/*
 * Stat Table (STR) -- bonus to hit (plus 128)
 */
byte adj_str_th[] =
{
	128 + -3        /* 3 */,
	128 + -2        /* 4 */,
	128 + -1        /* 5 */,
	128 + -1        /* 6 */,
	128 + 0 /* 7 */,
	128 + 0 /* 8 */,
	128 + 0 /* 9 */,
	128 + 0 /* 10 */,
	128 + 0 /* 11 */,
	128 + 0 /* 12 */,
	128 + 0 /* 13 */,
	128 + 0 /* 14 */,
	128 + 0 /* 15 */,
	128 + 0 /* 16 */,
	128 + 0 /* 17 */,
	128 + 1 /* 18/00-18/09 */,
	128 + 1 /* 18/10-18/19 */,
	128 + 1 /* 18/20-18/29 */,
	128 + 1 /* 18/30-18/39 */,
	128 + 1 /* 18/40-18/49 */,
	128 + 1 /* 18/50-18/59 */,
	128 + 1 /* 18/60-18/69 */,
	128 + 2 /* 18/70-18/79 */,
	128 + 3 /* 18/80-18/89 */,
	128 + 4 /* 18/90-18/99 */,
	128 + 5 /* 18/100-18/109 */,
	128 + 6 /* 18/110-18/119 */,
	128 + 7 /* 18/120-18/129 */,
	128 + 8 /* 18/130-18/139 */,
	128 + 9 /* 18/140-18/149 */,
	128 + 10        /* 18/150-18/159 */,
	128 + 11        /* 18/160-18/169 */,
	128 + 12        /* 18/170-18/179 */,
	128 + 13        /* 18/180-18/189 */,
	128 + 14        /* 18/190-18/199 */,
	128 + 15        /* 18/200-18/209 */,
	128 + 15        /* 18/210-18/219 */,
	128 + 16        /* 18/220+ */
};


/*
 * Stat Table (STR) -- weight limit in deca-pounds
 */
byte adj_str_wgt[] =
{
	5       /* 3 */,
	6       /* 4 */,
	7       /* 5 */,
	8       /* 6 */,
	9       /* 7 */,
	10      /* 8 */,
	11      /* 9 */,
	12      /* 10 */,
	13      /* 11 */,
	14      /* 12 */,
	15      /* 13 */,
	16      /* 14 */,
	17      /* 15 */,
	18      /* 16 */,
	19      /* 17 */,
	20      /* 18/00-18/09 */,
	22      /* 18/10-18/19 */,
	24      /* 18/20-18/29 */,
	26      /* 18/30-18/39 */,
	28      /* 18/40-18/49 */,
	30      /* 18/50-18/59 */,
	31      /* 18/60-18/69 */,
	31      /* 18/70-18/79 */,
	32      /* 18/80-18/89 */,
	32      /* 18/90-18/99 */,
	33      /* 18/100-18/109 */,
	33      /* 18/110-18/119 */,
	34      /* 18/120-18/129 */,
	34      /* 18/130-18/139 */,
	35      /* 18/140-18/149 */,
	35      /* 18/150-18/159 */,
	36      /* 18/160-18/169 */,
	36      /* 18/170-18/179 */,
	37      /* 18/180-18/189 */,
	37      /* 18/190-18/199 */,
	38      /* 18/200-18/209 */,
	38      /* 18/210-18/219 */,
	39      /* 18/220+ */
};


/*
 * Stat Table (STR) -- weapon weight limit in pounds
 */
byte adj_str_hold[] =
{
	4       /* 3 */,
	5       /* 4 */,
	6       /* 5 */,
	7       /* 6 */,
	8       /* 7 */,
	10      /* 8 */,
	12      /* 9 */,
	14      /* 10 */,
	16      /* 11 */,
	18      /* 12 */,
	20      /* 13 */,
	22      /* 14 */,
	24      /* 15 */,
	26      /* 16 */,
	28      /* 17 */,
	30      /* 18/00-18/09 */,
	30      /* 18/10-18/19 */,
	35      /* 18/20-18/29 */,
	40      /* 18/30-18/39 */,
	45      /* 18/40-18/49 */,
	50      /* 18/50-18/59 */,
	55      /* 18/60-18/69 */,
	60      /* 18/70-18/79 */,
	65      /* 18/80-18/89 */,
	70      /* 18/90-18/99 */,
	80      /* 18/100-18/109 */,
	80      /* 18/110-18/119 */,
	80      /* 18/120-18/129 */,
	80      /* 18/130-18/139 */,
	80      /* 18/140-18/149 */,
	90      /* 18/150-18/159 */,
	90      /* 18/160-18/169 */,
	90      /* 18/170-18/179 */,
	90      /* 18/180-18/189 */,
	90      /* 18/190-18/199 */,
	100     /* 18/200-18/209 */,
	100     /* 18/210-18/219 */,
	100     /* 18/220+ */
};


/*
 * Stat Table (STR) -- digging value
 */
byte adj_str_dig[] =
{
	0       /* 3 */,
	0       /* 4 */,
	1       /* 5 */,
	2       /* 6 */,
	3       /* 7 */,
	4       /* 8 */,
	4       /* 9 */,
	5       /* 10 */,
	5       /* 11 */,
	6       /* 12 */,
	6       /* 13 */,
	7       /* 14 */,
	7       /* 15 */,
	8       /* 16 */,
	8       /* 17 */,
	9       /* 18/00-18/09 */,
	10      /* 18/10-18/19 */,
	12      /* 18/20-18/29 */,
	15      /* 18/30-18/39 */,
	20      /* 18/40-18/49 */,
	25      /* 18/50-18/59 */,
	30      /* 18/60-18/69 */,
	35      /* 18/70-18/79 */,
	40      /* 18/80-18/89 */,
	45      /* 18/90-18/99 */,
	50      /* 18/100-18/109 */,
	55      /* 18/110-18/119 */,
	60      /* 18/120-18/129 */,
	65      /* 18/130-18/139 */,
	70      /* 18/140-18/149 */,
	75      /* 18/150-18/159 */,
	80      /* 18/160-18/169 */,
	85      /* 18/170-18/179 */,
	90      /* 18/180-18/189 */,
	95      /* 18/190-18/199 */,
	100     /* 18/200-18/209 */,
	100     /* 18/210-18/219 */,
	100     /* 18/220+ */
};


/*
 * Stat Table (STR) -- help index into the "blow" table
 */
byte adj_str_blow[] =
{
	3       /* 3 */,
	4       /* 4 */,
	5       /* 5 */,
	6       /* 6 */,
	7       /* 7 */,
	8       /* 8 */,
	9       /* 9 */,
	10      /* 10 */,
	11      /* 11 */,
	12      /* 12 */,
	13      /* 13 */,
	14      /* 14 */,
	15      /* 15 */,
	16      /* 16 */,
	17      /* 17 */,
	20 /* 18/00-18/09 */,
	30 /* 18/10-18/19 */,
	40 /* 18/20-18/29 */,
	50 /* 18/30-18/39 */,
	60 /* 18/40-18/49 */,
	70 /* 18/50-18/59 */,
	80 /* 18/60-18/69 */,
	90 /* 18/70-18/79 */,
	100 /* 18/80-18/89 */,
	110 /* 18/90-18/99 */,
	120 /* 18/100-18/109 */,
	130 /* 18/110-18/119 */,
	140 /* 18/120-18/129 */,
	150 /* 18/130-18/139 */,
	160 /* 18/140-18/149 */,
	170 /* 18/150-18/159 */,
	180 /* 18/160-18/169 */,
	190 /* 18/170-18/179 */,
	200 /* 18/180-18/189 */,
	210 /* 18/190-18/199 */,
	220 /* 18/200-18/209 */,
	230 /* 18/210-18/219 */,
	240 /* 18/220+ */
};


/*
 * Stat Table (DEX) -- index into the "blow" table
 */
byte adj_dex_blow[] =
{
	0       /* 3 */,
	0       /* 4 */,
	0       /* 5 */,
	0       /* 6 */,
	0       /* 7 */,
	0       /* 8 */,
	0       /* 9 */,
	1       /* 10 */,
	1       /* 11 */,
	1       /* 12 */,
	1       /* 13 */,
	1       /* 14 */,
	1       /* 15 */,
	1       /* 16 */,
	1       /* 17 */,
	1       /* 18/00-18/09 */,
	2       /* 18/10-18/19 */,
	2       /* 18/20-18/29 */,
	2       /* 18/30-18/39 */,
	2       /* 18/40-18/49 */,
	3       /* 18/50-18/59 */,
	3       /* 18/60-18/69 */,
	4       /* 18/70-18/79 */,
	4       /* 18/80-18/89 */,
	5       /* 18/90-18/99 */,
	6       /* 18/100-18/109 */,
	7       /* 18/110-18/119 */,
	8       /* 18/120-18/129 */,
	9       /* 18/130-18/139 */,
	10      /* 18/140-18/149 */,
	11      /* 18/150-18/159 */,
	12      /* 18/160-18/169 */,
	14      /* 18/170-18/179 */,
	16      /* 18/180-18/189 */,
	18      /* 18/190-18/199 */,
	20      /* 18/200-18/209 */,
	20      /* 18/210-18/219 */,
	20      /* 18/220+ */
};


/*
 * Stat Table (DEX) -- chance of avoiding "theft" and "falling"
 */
byte adj_dex_safe[] =
{
	0       /* 3 */,
	1       /* 4 */,
	2       /* 5 */,
	3       /* 6 */,
	4       /* 7 */,
	5       /* 8 */,
	5       /* 9 */,
	6       /* 10 */,
	6       /* 11 */,
	7       /* 12 */,
	7       /* 13 */,
	8       /* 14 */,
	8       /* 15 */,
	9       /* 16 */,
	9       /* 17 */,
	10      /* 18/00-18/09 */,
	10      /* 18/10-18/19 */,
	15      /* 18/20-18/29 */,
	15      /* 18/30-18/39 */,
	20      /* 18/40-18/49 */,
	25      /* 18/50-18/59 */,
	30      /* 18/60-18/69 */,
	35      /* 18/70-18/79 */,
	40      /* 18/80-18/89 */,
	45      /* 18/90-18/99 */,
	50      /* 18/100-18/109 */,
	60      /* 18/110-18/119 */,
	70      /* 18/120-18/129 */,
	80      /* 18/130-18/139 */,
	90      /* 18/140-18/149 */,
	100     /* 18/150-18/159 */,
	100     /* 18/160-18/169 */,
	100     /* 18/170-18/179 */,
	100     /* 18/180-18/189 */,
	100     /* 18/190-18/199 */,
	100     /* 18/200-18/209 */,
	100     /* 18/210-18/219 */,
	100     /* 18/220+ */
};


/*
 * Stat Table (CON) -- base regeneration rate
 */
byte adj_con_fix[] =
{
	0       /* 3 */,
	0       /* 4 */,
	0       /* 5 */,
	0       /* 6 */,
	0       /* 7 */,
	0       /* 8 */,
	0       /* 9 */,
	0       /* 10 */,
	0       /* 11 */,
	0       /* 12 */,
	0       /* 13 */,
	1       /* 14 */,
	1       /* 15 */,
	1       /* 16 */,
	1       /* 17 */,
	2       /* 18/00-18/09 */,
	2       /* 18/10-18/19 */,
	2       /* 18/20-18/29 */,
	2       /* 18/30-18/39 */,
	2       /* 18/40-18/49 */,
	3       /* 18/50-18/59 */,
	3       /* 18/60-18/69 */,
	3       /* 18/70-18/79 */,
	3       /* 18/80-18/89 */,
	3       /* 18/90-18/99 */,
	4       /* 18/100-18/109 */,
	4       /* 18/110-18/119 */,
	5       /* 18/120-18/129 */,
	6       /* 18/130-18/139 */,
	6       /* 18/140-18/149 */,
	7       /* 18/150-18/159 */,
	7       /* 18/160-18/169 */,
	8       /* 18/170-18/179 */,
	8       /* 18/180-18/189 */,
	8       /* 18/190-18/199 */,
	9       /* 18/200-18/209 */,
	9       /* 18/210-18/219 */,
	9       /* 18/220+ */
};


/*
 * Stat Table (CON) -- extra half-hitpoints per level (plus 128)
 */
byte adj_con_mhp[] =
{
	128 + -5        /* 3 */,
	128 + -3        /* 4 */,
	128 + -2        /* 5 */,
	128 + -1        /* 6 */,
	128 + 0 /* 7 */,
	128 + 0 /* 8 */,
	128 + 0 /* 9 */,
	128 + 0 /* 10 */,
	128 + 0 /* 11 */,
	128 + 0 /* 12 */,
	128 + 0 /* 13 */,
	128 + 0 /* 14 */,
	128 + 1 /* 15 */,
	128 + 1 /* 16 */,
	128 + 2 /* 17 */,
	128 + 3 /* 18/00-18/09 */,
	128 + 4 /* 18/10-18/19 */,
	128 + 4 /* 18/20-18/29 */,
	128 + 4 /* 18/30-18/39 */,
	128 + 4 /* 18/40-18/49 */,
	128 + 5 /* 18/50-18/59 */,
	128 + 6 /* 18/60-18/69 */,
	128 + 7 /* 18/70-18/79 */,
	128 + 8 /* 18/80-18/89 */,
	128 + 9 /* 18/90-18/99 */,
	128 + 10        /* 18/100-18/109 */,
	128 + 11        /* 18/110-18/119 */,
	128 + 12        /* 18/120-18/129 */,
	128 + 13        /* 18/130-18/139 */,
	128 + 14        /* 18/140-18/149 */,
	128 + 15        /* 18/150-18/159 */,
	128 + 16        /* 18/160-18/169 */,
	128 + 18        /* 18/170-18/179 */,
	128 + 20        /* 18/180-18/189 */,
	128 + 22        /* 18/190-18/199 */,
	128 + 25        /* 18/200-18/209 */,
	128 + 26        /* 18/210-18/219 */,
	128 + 27        /* 18/220+ */
};


/*
 * This table is used to help calculate the number of blows the player can
 * make in a single round of attacks (one player turn) with a normal weapon.
 *
 * This number ranges from a single blow/round for weak players to up to six
 * blows/round for powerful warriors.
 *
 * Note that certain artifacts and ego-items give "bonus" blows/round.
 *
 * First, from the player class, we extract some values:
 *
 *    Warrior --> num = 6; mul = 5; div = MAX(30, weapon_weight);
 *    Mage    --> num = 4; mul = 2; div = MAX(40, weapon_weight);
 *    Priest  --> num = 5; mul = 3; div = MAX(35, weapon_weight);
 *    Rogue   --> num = 5; mul = 3; div = MAX(30, weapon_weight);
 *    Ranger  --> num = 5; mul = 4; div = MAX(35, weapon_weight);
 *    Paladin --> num = 5; mul = 4; div = MAX(30, weapon_weight);
 *
 * To get "P", we look up the relevant "adj_str_blow[]" (see above),
 * multiply it by "mul", and then divide it by "div", rounding down.
 *
 * To get "D", we look up the relevant "adj_dex_blow[]" (see above),
 * note especially column 6 (DEX 18/101) and 11 (DEX 18/150).
 *
 * The player gets "blows_table[P][D]" blows/round, as shown below,
 * up to a maximum of "num" blows/round, plus any "bonus" blows/round.
 */
byte blows_table[12][12] =
{
	/* P/D */
	/* 0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11+ */

	/* 0  */
	{  1,   1,   1,   1,   1,   1,   2,   2,   2,   2,   2,   3 },

	/* 1  */
	{  1,   1,   1,   1,   2,   2,   3,   3,   3,   4,   4,   4 },

	/* 2  */
	{  1,   1,   2,   2,   3,   3,   4,   4,   4,   5,   5,   5 },

	/* 3  */
	{  1,   2,   2,   3,   3,   4,   4,   4,   5,   5,   5,   5 },

	/* 4  */
	{  1,   2,   2,   3,   3,   4,   4,   5,   5,   5,   5,   5 },

	/* 5  */
	{  2,   2,   3,   3,   4,   4,   5,   5,   5,   5,   5,   6 },

	/* 6  */
	{  2,   2,   3,   3,   4,   4,   5,   5,   5,   5,   5,   6 },

	/* 7  */
	{  2,   3,   3,   4,   4,   4,   5,   5,   5,   5,   5,   6 },

	/* 8  */
	{  3,   3,   3,   4,   4,   4,   5,   5,   5,   5,   6,   6 },

	/* 9  */
	{  3,   3,   4,   4,   4,   4,   5,   5,   5,   5,   6,   6 },

	/* 10 */
	{  3,   3,   4,   4,   4,   4,   5,   5,   5,   6,   6,   6 },

	/* 11+ */
	{  3,   3,   4,   4,   4,   4,   5,   5,   6,   6,   6,   6 },
};


s16b arena_monsters[MAX_ARENA_MONS] =
{
	 30,	 43,	102,	118,	126,	149,	173,
	183,	188,	191,	216,	230,	238,	244,
	255,	262,	293,	297,	321,	349,	372,
	401,	415,	454,	464,	485,	538,	631,
	641
};


/*
 * This table allows quick conversion from "speed" to "energy"
 * The basic function WAS ((S>=110) ? (S-110) : (100 / (120-S)))
 * Note that table access is *much* quicker than computation.
 *
 * Note that the table has been changed at high speeds.  From
 * "Slow (-40)" to "Fast (+30)" is pretty much unchanged, but
 * at speeds above "Fast (+30)", one approaches an asymptotic
 * effective limit of 50 energy per turn.  This means that it
 * is relatively easy to reach "Fast (+30)" and get about 40
 * energy per turn, but then speed becomes very "expensive",
 * and you must get all the way to "Fast (+50)" to reach the
 * point of getting 45 energy per turn.  After that point,
 * further increases in speed are more or less pointless,
 * except to balance out heavy inventory.
 *
 * Note that currently the fastest monster is "Fast (+30)".
 *
 * It should be possible to lower the energy threshold from
 * 100 units to 50 units, though this may interact badly with
 * the (compiled out) small random energy boost code.  It may
 * also tend to cause more "clumping" at high speeds.
 */
byte extract_energy[300] =
{
	/* Slow */     1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
	/* Slow */     1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
	/* Slow */     1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
	/* Slow */     1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
	/* Slow */     1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
	/* Slow */     1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
	/* S-50 */     1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
	/* S-40 */     2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
	/* S-30 */     2,  2,  2,  2,  2,  2,  2,  3,  3,  3,
	/* S-20 */     3,  3,  3,  3,  3,  4,  4,  4,  4,  4,
	/* S-10 */     5,  5,  5,  5,  6,  6,  7,  7,  8,  9,
	/* Norm */    10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
	/* F+10 */    20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
	/* F+20 */    30, 31, 32, 33, 34, 35, 36, 36, 37, 37,
	/* F+30 */    38, 38, 39, 39, 40, 40, 40, 41, 41, 41,
	/* F+40 */    42, 42, 42, 43, 43, 43, 44, 44, 44, 44,
	/* F+50 */    45, 45, 45, 45, 45, 46, 46, 46, 46, 46,
	/* F+60 */    47, 47, 47, 47, 47, 48, 48, 48, 48, 48,
	/* F+70 */    49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
	/* Fast */    49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
        /* Virtual */  49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
        /* Virtual */  49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
        /* Virtual */  49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
        /* Virtual */  49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
        /* Virtual */  49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
        /* Virtual */  49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
        /* Virtual */  49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
        /* Virtual */  49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
        /* Virtual */  49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
        /* Virtual */  49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
};




/*
 * Base experience levels, may be adjusted up for race and/or class
 */
s32b player_exp[PY_MAX_LEVEL] =
{
	10,
	25,
	45,
	70,
	100,
	140,
	200,
	280,
	380,
	500,
	650,
	850,
	1100,
	1400,
	1800,
	2300,
	2900,
	3600,
	4400,
	5400,
	6800,
	8400,
	10200,
	12500,
	17500,
	25000,
	35000L,
	50000L,
	75000L,
	100000L,
	150000L,
	200000L,
	275000L,
	350000L,
	450000L,
	550000L,
	700000L,
	850000L,
	1000000L,
	1250000L,
	1500000L,
	1800000L,
	2100000L,
	2400000L,
	2700000L,
	3000000L,
	3500000L,
	4000000L,
	4500000L,
	5000000L
};


/*
 * Player Sexes
 *
 *      Title,
 *      Winner
 */
player_sex sex_info[MAX_SEXES] =
{
	{
		"Female",
		"Queen"
	},

	{
		"Male",
		"King"
        },
        {
                "Neuter",
                "Ruler"
        }
};


/*
 * Player Races
 *
 *      Title,
 *      Desc,
 *      {STR,INT,WIS,DEX,CON,CHR},
 *      r_dis, r_dev, r_sav, r_stl, r_srh, r_fos, r_thn, r_thb,
 *      hitdie, exp base,
 *      Age (Base, Mod),
 *      Male (Hgtbase, Hgtmod, Wgtbase, Wgtmod),
 *      Female (Hgtbase, Hgtmod, Wgtbase, Wgtmod),
 *      infra,
 *      class-choices
 *      race powers(4)
 *      body parts(weapon, torso, arms, finger, head, legs)
 */
player_race race_info[MAX_RACES] =
{
	{
		"Human",
                "Humans are the second born, the Edain.\nThey are the basic race to which all others are compared.\nAverage in ability, they can be any class.",
		{  0,  0,  0,  0,  0,  0 },
		0,  0,  0,  0,  0,  10,  0,  0,
		10,  100,
		14,  6,
		72,  6, 180, 25,
		66,  4, 150, 20,
		0,
                0xFFFFFFFF,	/* All classes */
                { -1, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
	},
	{
		"Half-Elf",
                "A crossbreed of elf and human, they get the best of the two races.",
                { 0,  1,  1,  1, -1,  1 },
		2,  3,  3,  1, 6,  11, -1,  5,
		9,  110,
		24, 16,
		66,  6, 130, 15,
		62,  6, 100, 10,
		2,
                0xFFFFFFFF - BIT(CLASS_POWERMAGE) - BIT(CLASS_NECRO) - BIT(CLASS_UNBELIEVER),
                { -1, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
	},
	{
		"Elf",
                "Elves are the first born, the Eldar.\nMore spiritual than physical beings, they are weaker than humans\nbut are more intelligent.",
		{ -1,  2,  2,  1, -2,  2 },
		5,  6,  6,  2, 8,  12, -5, 15,
		8,  120,
		75, 75,
		60,  4, 100,  6,
		54,  4, 80,  6,
		3,
                0xFFFFFFFF - BIT(CLASS_PALADIN)- BIT(CLASS_CHAOS_WARRIOR) - BIT(CLASS_POWERMAGE) - BIT(CLASS_NECRO) - BIT(CLASS_UNBELIEVER),
                { -1, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
	},
	{
		"Hobbit",
                "An old but quiet race related to humans.\nThey are small and quite weak but good at many things.",
		{ -2,  2,  1,  3,  2,  1 },
		15, 18, 18, 5, 12,  15, -10, 20,
		7,  110,
		21, 12,
		36,  3, 60,  3,
		33,  3, 50,  3,
		4,
                0xFFFFFFFF - BIT(CLASS_PRIEST) - BIT(CLASS_RANGER) - BIT(CLASS_PALADIN) - BIT(CLASS_WARLOCK) - BIT(CLASS_CHAOS_WARRIOR) - BIT(CLASS_MONK) - BIT(CLASS_MINDCRAFTER) - BIT(CLASS_BEASTMASTER) - BIT(CLASS_POWERMAGE) - BIT(CLASS_RUNECRAFTER) - BIT(CLASS_POSSESSOR) - BIT(CLASS_SORCERER) - BIT(CLASS_DRUID) - BIT(CLASS_NECRO) - BIT(CLASS_DAEMONOLOGIST) - BIT(CLASS_WEAPONMASTER),
                { PWR_COOK_FOOD, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
	},
	{
		"Gnome",
                "Related to dwarves, Gnomes are between Dwarves and Hobbits in size.\nVery good at magic use they are poor as fighters.",
		{ -1,  2,  0,  2,  1, -2 },
		10, 12, 12,  3, 6,  13, -8, 12,
		8,  135,
		50, 40,
		42,  3, 90,  6,
		39,  3, 75,  3,
		4,
                0xFFFFFFFF - BIT(CLASS_RANGER) - BIT(CLASS_PALADIN) - BIT(CLASS_WARLOCK) - BIT(CLASS_CHAOS_WARRIOR) - BIT(CLASS_MONK) - BIT(CLASS_BEASTMASTER) - BIT(CLASS_HARPER) - BIT(CLASS_POWERMAGE) - BIT(CLASS_RUNECRAFTER) - BIT(CLASS_POSSESSOR) - BIT(CLASS_ARCHER) - BIT(CLASS_DRUID) - BIT(CLASS_NECRO) - BIT(CLASS_UNBELIEVER) - BIT(CLASS_WEAPONMASTER),
                { PWR_BLINK, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
	},
	{
		"Dwarf",
                "The children of Aule, a strong but small race.\nMiners and fighters of legend.",
                {  2, -2,  2, -2,  2, -3 },
		2,  9,  10,  -1,  7,  10, 15,  0,
		11,  125,
		35, 15,
		48,  3, 150, 10,
		46,  3, 120, 10,
		5,
                0xFFFFFFFF - BIT(CLASS_MAGE) - BIT(CLASS_ROGUE) - BIT(CLASS_RANGER) - BIT(CLASS_PALADIN) - BIT(CLASS_WARLOCK) - BIT(CLASS_CHAOS_WARRIOR) - BIT(CLASS_MONK) - BIT(CLASS_MINDCRAFTER) - BIT(CLASS_HIGH_MAGE) - BIT(CLASS_BEASTMASTER) - BIT(CLASS_POWERMAGE) - BIT(CLASS_RUNECRAFTER) - BIT(CLASS_POSSESSOR) - BIT(CLASS_SORCERER) - BIT(CLASS_ARCHER) - BIT(CLASS_ILLUSIONIST) - BIT(CLASS_NECRO) - BIT(CLASS_DAEMONOLOGIST),
                { PWR_PASSWALL, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
	},
	{
                "Orc",
                "Quite strong but not very smart.",
                {  2, -1,  0,  1,  1, -4 },
		-3, -3, -3,  -1,  0, 7, 12, -5,
		10,  110,
		11,  4,
		66,  1, 150,  5,
		62,  1, 120,  5,
		3,
                0xFFFFFFFF - BIT(CLASS_MAGE) - BIT(CLASS_RANGER) - BIT(CLASS_PALADIN) - BIT(CLASS_WARLOCK) - BIT(CLASS_MINDCRAFTER) - BIT(CLASS_HIGH_MAGE) - BIT(CLASS_BEASTMASTER) - BIT(CLASS_ALCHEMIST) - BIT(CLASS_SYMBIANT) - BIT(CLASS_HARPER) - BIT(CLASS_POSSESSOR) - BIT(CLASS_SORCERER) - BIT(CLASS_ARCHER) - BIT(CLASS_ILLUSIONIST) - BIT(CLASS_DRUID) - BIT(CLASS_DAEMONOLOGIST) - BIT(CLASS_MERCHANT),
                { PWR_UNFEAR, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
	},
	{
                "Troll",
                "They can bear the light of the sun.\nThey are extremely strong and dumb.",
		{ 4, -4, -2, -4,  3, -6 },
		-5, -8, -8, -2,  -1, 5, 20, -10,
		12,  137,
		20, 10,
		96, 10, 250, 50,
		84,  8, 225, 40,
		3,
                0xFFFFFFFF - BIT(CLASS_MERCHANT) - BIT(CLASS_MAGE) - BIT(CLASS_ROGUE) - BIT(CLASS_RANGER) - BIT(CLASS_PALADIN) - BIT(CLASS_WARLOCK) - BIT(CLASS_CHAOS_WARRIOR) - BIT(CLASS_MONK) - BIT(CLASS_MINDCRAFTER) - BIT(CLASS_HIGH_MAGE) - BIT(CLASS_BEASTMASTER) - BIT(CLASS_ALCHEMIST) - BIT(CLASS_MIMIC) - BIT(CLASS_SYMBIANT) - BIT(CLASS_HARPER) - BIT(CLASS_RUNECRAFTER) - BIT(CLASS_POSSESSOR) - BIT(CLASS_SORCERER) - BIT(CLASS_ARCHER) - BIT(CLASS_ILLUSIONIST) - BIT(CLASS_DRUID) - BIT(CLASS_DAEMONOLOGIST),
                { PWR_BERSERK, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
	},
	{
                "Dunadan",
                "The greatest of the Edain, humans in all respects but\nstronger, smarter and wiser.",
		{  1,  2,  2,  2,  3,  2 },
		4,  5,  5,  2, 3, 13, 15, 10,
                10,  180,
		50, 50,
		82, 5, 190, 20,
		78,  6, 180, 15,
		0,
                0xFFFFFFFF - BIT(CLASS_MIMIC) - BIT(CLASS_POWERMAGE) - BIT(CLASS_NECRO),
                { -1, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
	},
	{
		"High-Elf",
                "Elves are the first born, the Eldar.\nHigh elves are the best of the Eldar, strong, fast, intellectual, though\nthey sometimes lack wisdom.",
		{  1,  3,  2,  3,  1,  5 },
		4,  20, 20,  4,  3, 14, 10, 25,
		10,  200,
		100, 30,
		90, 10, 190, 20,
		82, 10, 180, 15,
		4,
                0xFFFFFFFF - BIT(CLASS_PALADIN) - BIT(CLASS_CHAOS_WARRIOR) - BIT(CLASS_POWERMAGE) - BIT(CLASS_NECRO) - BIT(CLASS_UNBELIEVER),
                { -1, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
	},
/**/	{
		"Half-Ogre",
                "A crossbreed between a human and an ogre.\nThey are similar to half-trolls, strong and dumb.",
		{ 3, -1, -1, -1, 3, -3 },
		-3, -5, -5, -2, -1, 5, 20, 0,
		12,  130,
		40, 10,
		92, 10, 255, 60,
		80,  8, 235, 60,
		3,
                0xFFFFFFFF - BIT(CLASS_MERCHANT) - BIT(CLASS_ROGUE) - BIT(CLASS_RANGER) - BIT(CLASS_PALADIN) - BIT(CLASS_WARLOCK) - BIT(CLASS_CHAOS_WARRIOR) - BIT(CLASS_MONK) - BIT(CLASS_MINDCRAFTER) - BIT(CLASS_BEASTMASTER) - BIT(CLASS_ALCHEMIST) - BIT(CLASS_MIMIC) - BIT(CLASS_SYMBIANT) - BIT(CLASS_HARPER) - BIT(CLASS_RUNECRAFTER) - BIT(CLASS_POSSESSOR) - BIT(CLASS_SORCERER) - BIT(CLASS_ARCHER) - BIT(CLASS_ILLUSIONIST) - BIT(CLASS_DRUID) - BIT(CLASS_UNBELIEVER) - BIT(CLASS_DAEMONOLOGIST) - BIT(CLASS_WEAPONMASTER),
                { PWR_EXPL_RUNE, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
	},
/**/	{
		"Half-Giant",
                "A crossbreed between a human and a giant.\nThey are similar to half-trolls, strong and dumb.",
		{ 4, -2, -2, -2, 3, -3 },
		-6, -8, -6, -2, -1, 5, 25, 5,
		13, 150,
		40, 10,
		100,10, 255, 65,
		80, 10, 240, 64,
		3,
                0xFFFFFFFF - BIT(CLASS_MERCHANT) - BIT(CLASS_MAGE) - BIT(CLASS_PRIEST) - BIT(CLASS_ROGUE) - BIT(CLASS_PALADIN) - BIT(CLASS_WARLOCK) - BIT(CLASS_CHAOS_WARRIOR) - BIT(CLASS_MONK) - BIT(CLASS_MINDCRAFTER) - BIT(CLASS_HIGH_MAGE) - BIT(CLASS_BEASTMASTER) - BIT(CLASS_ALCHEMIST) - BIT(CLASS_MIMIC) - BIT(CLASS_SYMBIANT) - BIT(CLASS_HARPER) - BIT(CLASS_RUNECRAFTER) - BIT(CLASS_POSSESSOR) - BIT(CLASS_SORCERER) - BIT(CLASS_ARCHER) - BIT(CLASS_ILLUSIONIST) - BIT(CLASS_DRUID) - BIT(CLASS_DAEMONOLOGIST) - BIT(CLASS_WEAPONMASTER),
                { PWR_STM, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
	},
/**/	{
		"Kobold",
                "A weaker kind of goblin, related to orcs.",
		{ 1, -1, 0, 1, 0, -4 },
		-2, -3, -2, -1, 1, 8, 10, -8,
		9, 125,
		11,  3,
		60,  1, 130,  5,
		55,  1, 100,  5,
		3,
                0xFFFFFFFF - BIT(CLASS_MAGE) - BIT(CLASS_PRIEST) - BIT(CLASS_RANGER) - BIT(CLASS_PALADIN) - BIT(CLASS_WARLOCK) - BIT(CLASS_CHAOS_WARRIOR) - BIT(CLASS_MONK) - BIT(CLASS_MINDCRAFTER) - BIT(CLASS_HIGH_MAGE) - BIT(CLASS_BEASTMASTER) - BIT(CLASS_ALCHEMIST) - BIT(CLASS_POSSESSOR) - BIT(CLASS_SORCERER) - BIT(CLASS_ARCHER) - BIT(CLASS_DRUID) - BIT(CLASS_DAEMONOLOGIST) - BIT(CLASS_WEAPONMASTER),
                { PWR_POIS_DART, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
	},
/**/	{
                "Petty Dwarf",
                "A nearly extinct subrace of dwarves.\nThey prefer to live in the darkness.",
		{ 1, -1, 2, 0, 2, -4 },
		3, 5, 10, 1, 5, 10, 9, 0,
		11, 135,
		40, 12,
		43,  3, 92,  6,
		40,  3, 78,  3,
		5,
                0xFFFFFFFF - BIT(CLASS_RANGER) - BIT(CLASS_PALADIN) - BIT(CLASS_WARLOCK) - BIT(CLASS_CHAOS_WARRIOR) - BIT(CLASS_MONK) - BIT(CLASS_MINDCRAFTER) - BIT(CLASS_BEASTMASTER) - BIT(CLASS_POWERMAGE) - BIT(CLASS_RUNECRAFTER) - BIT(CLASS_POSSESSOR) - BIT(CLASS_SORCERER) - BIT(CLASS_ARCHER) - BIT(CLASS_DRUID) - BIT(CLASS_NECRO)
                - BIT(CLASS_UNBELIEVER) - BIT(CLASS_DAEMONOLOGIST) - BIT(CLASS_SORCERER),
                { PWR_DETECT_TD, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
	},
/**/	{
		"Dark Elf",
                "Elves are the first born, the Eldar.\nDark elves are rare on Middle Earth and even though not evil\nthey are not good.",
		{ -1, 3, 2, 2, -2, 1 },
		5, 15, 20, 3, 8, 12, -5, 10,
		9, 150,
		75, 75,
		60,  4, 100,  6,
		54,  4, 80,  6,
		5,
                0xFFFFFFFF - BIT(CLASS_PALADIN) - BIT(CLASS_POWERMAGE) - BIT(CLASS_DRUID) - BIT(CLASS_UNBELIEVER),
                { PWR_MAGIC_MISSILE, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
	},
	{
                "Ent",
                "Guardian of the forests of Middle Earth, summoned by Yavanna before\neven the elves awoke. It is said 'Trolls are strong, Ents are STRONGER'.",
                { +10, -3, +2, -5, +11, -3 },
                5, 5, 20, -6, 5, 4, 15, 5,
                12, 210,
                255, 70,
		72, 6, 100, 25,
		66, 4, 100, 20,
		5,
                0xFFFFFFFF - BIT(CLASS_MERCHANT) - BIT(CLASS_MAGE) - BIT(CLASS_ROGUE) - BIT(CLASS_RANGER) - BIT(CLASS_CHAOS_WARRIOR) - BIT(CLASS_MONK) - BIT(CLASS_MINDCRAFTER) - BIT(CLASS_MIMIC) - BIT(CLASS_HARPER) - BIT(CLASS_POWERMAGE) - BIT(CLASS_RUNECRAFTER) - BIT(CLASS_POSSESSOR) - BIT(CLASS_SORCERER) - BIT(CLASS_ARCHER) - BIT(CLASS_ILLUSIONIST) - BIT(CLASS_NECRO) - BIT(CLASS_DAEMONOLOGIST) - BIT(CLASS_WEAPONMASTER),
                { PWR_GROW_TREE, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
	},
	{
                "RohanKnight",
                "Humans from the land of Rohan, riding the great Mearas.\nFast and powerful in battle.",
                { 4, -2, 3, 1, 4, 2 },
                10, 5, 5, -8, 1, 1, 5, 5,
                10, 220,
		20, 3,
		60,  3, 80,  4,
		54,  3, 70,  4,
                0,
                0xFFFFFFFF - BIT(CLASS_MAGE) - BIT(CLASS_PRIEST) - BIT(CLASS_ROGUE) - BIT(CLASS_MONK) - BIT(CLASS_MINDCRAFTER) - BIT(CLASS_BEASTMASTER) - BIT(CLASS_ALCHEMIST) - BIT(CLASS_MIMIC) - BIT(CLASS_SYMBIANT) - BIT(CLASS_POWERMAGE) - BIT(CLASS_POSSESSOR) - BIT(CLASS_DRUID) - BIT(CLASS_DAEMONOLOGIST),
                { PWR_ROHAN, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
	},
/**/	{
                "DragonRider",
                "In the distant system of the star Rukbat orbits the planet Pern, home of the\nDragonRiders. Mounting huge, powerful but friendly dragons they are masters of\nteleporatation.",
                {  6,  3,  -10,  0,  6,  8 },
                6,  0,  10,  -16,  30,  10,  15,  5,
                15,  400,
		14,  6,
                180,  6, 255, 25,
                150,  4, 230, 20,
                0,
                0xFFFFFFFF - BIT(CLASS_MERCHANT) - BIT(CLASS_MAGE) - BIT(CLASS_PRIEST) - BIT(CLASS_ROGUE) - BIT(CLASS_CHAOS_WARRIOR) - BIT(CLASS_MONK) - BIT(CLASS_ALCHEMIST) - BIT(CLASS_MIMIC) - BIT(CLASS_SYMBIANT) - BIT(CLASS_POWERMAGE) - BIT(CLASS_POSSESSOR) - BIT(CLASS_ILLUSIONIST) - BIT(CLASS_DRUID) - BIT(CLASS_NECRO) - BIT(CLASS_DAEMONOLOGIST) - BIT(CLASS_WEAPONMASTER),
                { PWR_DRAGON, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
        },

/**/	{
                "DeathMold",
                "A pure mass of evilness, DeathMolds cannot move, but they have much more\npower than an average race.",
                { 10, 0, 10, 0, 10, -15 },
                15, -5, 15, 25, 0, 10, 25, 25,
                15, 250,
                5, 15,
                10, 1, 50, 1,
                10, 1, 50, 1,
                10,
                0xFFFFFFFF - BIT(CLASS_MERCHANT) - BIT(CLASS_WARRIOR) - BIT(CLASS_RANGER) - BIT(CLASS_PALADIN) - BIT(CLASS_WARLOCK) - BIT(CLASS_CHAOS_WARRIOR) - BIT(CLASS_MONK) - BIT(CLASS_ALCHEMIST) - BIT(CLASS_MIMIC) - BIT(CLASS_HARPER) - BIT(CLASS_RUNECRAFTER) - BIT(CLASS_POSSESSOR) - BIT(CLASS_ARCHER) - BIT(CLASS_ILLUSIONIST) - BIT(CLASS_DRUID) - BIT(CLASS_UNBELIEVER) - BIT(CLASS_DAEMONOLOGIST) - BIT(CLASS_WEAPONMASTER),
                { PWR_DEATHMOLD, -1, -1, -1},
                {1, 1, 1, 4, 0, 0},
        },
/**/    {
                "Yeek",
                "The weakest of all the races, bad at everything except gaining levels quickly.",
                {-5, -5, -5, -5, -5, -5},
                -5, -5, -10, 0, -5, 0, -10, -10,
                6, 25,
                10,  4,
                40, 5, 50, 10,
                35, 4, 45, 10,
                2,
                0xFFFFFFFF - BIT(CLASS_MERCHANT) - BIT(CLASS_MIMIC) - BIT(CLASS_POWERMAGE) - BIT(CLASS_NECRO) - BIT(CLASS_WEAPONMASTER),
                { -1, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
        },
	{
                "Wood Elf",
                "Elves are the first born, the Eldar.\nWood elves live in the great forests of Middle Earth.",
                { -3,  2,  1,  5, -4,  1 },
                5,  6,  6,  5, 8,  12, -25, 40,
                7,  130,
		75, 75,
		60,  4, 100,  6,
		54,  4, 80,  6,
                4,
                0xFFFFFFFF - BIT(CLASS_PALADIN) - BIT(CLASS_CHAOS_WARRIOR) - BIT(CLASS_POWERMAGE) - BIT(CLASS_NECRO) - BIT(CLASS_UNBELIEVER) - BIT(CLASS_DAEMONOLOGIST) - BIT(CLASS_WEAPONMASTER),
                { -1, -1, -1, -1},
                {1, 1, 1, 2, 1, 1},
	},
};
/*
 * Player Races
 *
 *      Title,
 *      Desc,
 *      {STR,INT,WIS,DEX,CON,CHR},
 *      r_dis, r_dev, r_sav, r_stl, r_srh, r_fos, r_thn, r_thb,
 *      hitdie, exp base,
 *      Age (Base, Mod),
 *      Male (Hgtbase, Hgtmod, Wgtbase, Wgtmod),
 *      Female (Hgtbase, Hgtmod, Wgtbase, Wgtmod),
 *      infra,
 *      class-choices
 *      race powers(4)
 *      body parts(weapon, torso, arms, finger, head, legs)
 */

/*
 * Player Race Mods
 *
 *      Title,
 *      Position of the text(TRUE = after, FALSE = before),
 *      {STR,INT,WIS,DEX,CON,CHR},
 *      r_dis, r_dev, r_sav, r_stl, r_srh, r_fos, r_thn, r_thb,
 *      hitdie, exp base,
 *      Age (Base, Mod),
 *      Male (Hgt, Wgt),
 *      Female (Hgt, Wgt)
 *      infra,
 *      race-choices,
 *      class-choice to add,
 *      class-choice to del,
 *      body parts(weapon, torso, arms, finger, head, legs)
 */
player_race_mod race_mod_info[MAX_RACE_MODS] =
{
	{
                "",
                "A normal member of the race.",
                TRUE,
		{  0,  0,  0,  0,  0,  0 },
                0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,
                0,  0,
                0,  0, 0, 0,
                0, 0, 0, 0,
                0,
                0xFFFFFFF,     /* All races */
                0,
                0,
                { -1, -1, -1, -1},
                {0, 0, 0, 0, 0, 0},
	},

	{
		"Vampire",
                "Vampires are powerful undead, wielding great powers they still fear the\nsunlight and cannot easily satiate their hunger.",
                TRUE,
		{ 3, 3, -1, -1, 1, 2 },
                1, 3, 3, 1, 1, 4, 2, 0,
                +1, 100,
                50, 15,
                0,  0, 0, 0,
                0,  0, 0, 0,
                3,
                0xFFFFFFF - BIT(RACE_MOLD) - BIT(RACE_ENT) - BIT(RACE_DRAGONRIDDER),
                0,
                BIT(CLASS_MERCHANT),
                { PWR_VAMPIRISM, -1, -1, -1},
                {0, 0, 0, 0, 0, 0},
	},

	{
		"Spectre",
                "Spectres only partially exist in the mortal world and so they can\npass through walls. They are somewhat physically weak.",
                TRUE,
		{ -5, 4, 4, 2, -3, -6 },
                2, 8, 7, 2, 2, 7, -5, -2,
                -3, 80,
                50, 15,
                0, 0, -10, -5,
                0, 0, -10, -5,
                3,
                0xFFFFFFFF - BIT(RACE_ENT) - BIT(RACE_DRAGONRIDDER) - BIT(RACE_MOLD),
                0,
                BIT(CLASS_WARRIOR) + BIT(CLASS_UNBELIEVER) + BIT(CLASS_WEAPONMASTER) + BIT(CLASS_ARCHER) + BIT(CLASS_MERCHANT),
                { PWR_SCARE, -1, -1, -1},
                {0, 0, 0, -1, 0, 0},
	},

	{
		"Skeleton",
                "Yet an other kind of undead. Their physical 'body' is not very vulnerable\nto sharp things.",
                TRUE,
		{ 0, -2, -2, 0, 1, -4 },
		-5, -5, 5, -1, -1, 8, 8, 0,
                0, 45,
                50, 15,
                0,  0, -10, -5,
                0,  0, -10, -5,
                1,
                0xFFFFFFF - BIT(RACE_MOLD) - BIT(RACE_ENT) - BIT(RACE_DRAGONRIDDER),
                0,
                BIT(CLASS_SORCERER) + BIT(CLASS_MAGE) + BIT(CLASS_POWERMAGE) + BIT(CLASS_HIGH_MAGE) +
                BIT(CLASS_ILLUSIONIST) + BIT(CLASS_MERCHANT),
                { PWR_REST_LIFE, -1, -1, -1},
                {0, 0, 0, 0, 0, 0},
	},

	{
		"Zombie",
                "Strong and dumb is a zombie.",
                TRUE,
		{ 2, -6, -6, 1, 4, -5 },
                -2, -2, 5, -1, -1, 2, 5, 0,
                3, 45,
                50, 15,
                0, 0, 0, 0,
                0, 0, 0, 0,
                1,
                0xFFFFFFF - BIT(RACE_MOLD) - BIT(RACE_ENT) - BIT(RACE_DRAGONRIDDER),
                0,
                BIT(CLASS_MERCHANT),
                { PWR_REST_LIFE, -1, -1, -1},
                {0, 0, 0, 0, 0, 0},
	},

	{
		"Barbarian",
                "Hardy members of their race they are strong fighters but poor spellcasters.",
                TRUE,
                { 2, -3,  -2,  1,  1, -3 },
                -2, -10, 2,  -2,  0, 1, 12, 5,
                1, 25,
                0, 0,
                0, 0, 0, 0,
                0, 0, 0, 0,
		0,
                BIT(RACE_HUMAN) + BIT(RACE_DWARF) + BIT(RACE_HALF_ORC) + BIT(RACE_HALF_TROLL)
                + BIT(RACE_HALF_OGRE) + BIT(RACE_HALF_GIANT),
                0,
                BIT(CLASS_SORCERER) + BIT(CLASS_MAGE) + BIT(CLASS_POWERMAGE) + BIT(CLASS_HIGH_MAGE) +
                + BIT(CLASS_ILLUSIONIST),
                { PWR_BERSERK, -1, -1, -1},
                {0, 0, 0, 0, 0, 0},
        },

	{
                "Hermit",
"Through years of isolation hermits can manage to increase their mana\nreserves but at the cost of an increased physical weakness.",
                TRUE,
                { -3, +1, +1, -3, -3, +1 },
                5, 10, 5,  3,  4,  10, -5, -5,
                -3,  20,
                0,  0,
                0,  0, 0, 0,
                0, 0, 0, 0,
                1,
                0xFFFFFFF - BIT(RACE_HALF_ORC) - BIT(RACE_HALF_TROLL) -
                        BIT(RACE_HALF_OGRE) - BIT(RACE_HALF_GIANT) -
                        BIT(RACE_KOBOLD),
                BIT(CLASS_SORCERER) + BIT(CLASS_MAGE) + BIT(CLASS_MAGE) + BIT(CLASS_RUNECRAFTER),
                BIT(CLASS_WARRIOR) + BIT(CLASS_UNBELIEVER),
                { -1, -1, -1, -1},
                {0, 0, 0, 0, 0, 0},
	},

	{
		"Corrupted",
                "Infused with the corruption of Morgoth, these unfortunates randomly gain\nand lose corruptions as they gain expirience.",
                TRUE,
		    {  0,  0,  0,  0,  0,  0 },
                0,  0,  0,  0,  0,  0,  0,  0,
                0,  20, 
               /* Note that while it could be higher, the EXP reflects the large number of harmful corruptions in addition to the good ones. */
                0,  0,
                0,  0, 0, 0,
                0, 0, 0, 0,
                0,
                0xFFFFFFF - BIT(RACE_MOLD) - BIT(RACE_ENT),
                /* Ents and Death Molds are incorruptable for our purposes. */
                0,
                0,
                { -1, -1, -1, -1},
                {0, 0, 0, 0, 0, 0},
	},

};
/*
 * Player Race Mods
 *
 *      Title,
 *      Position of the text(TRUE = after, FALSE = before),
 *      {STR,INT,WIS,DEX,CON,CHR},
 *      r_dis, r_dev, r_sav, r_stl, r_srh, r_fos, r_thn, r_thb,
 *      hitdie, exp base,
 *      Age (Base, Mod),
 *      Male (Hgt, Wgt),
 *      Female (Hgt, Wgt)
 *      infra,
 *      race-choices,
 *      class-choice to add,
 *      class-choice to del,
 *      body parts(weapon, torso, arms, finger, head, legs)
 */

/*
 * Player Classes
 *
 *      Title,
 *      Desc,
 *      {STR,INT,WIS,DEX,CON,CHR},
 *      c_dis, c_dev, c_sav, c_stl, c_srh, c_fos, c_thn, c_thb,
 *      x_dis, x_dev, x_sav, x_stl, x_srh, x_fos, x_thn, x_thb,
 *      HD, Exp
 */
player_class class_info[MAX_CLASS] =
{
	{
		"Warrior",
                "Simple fighters, they hack away with their trusty weapon.",
		{ 5, -2, -2, 2, 2, -1},
		25, 18, 18, 1,  14, 2, 70, 55,
                12, 7,  10, 0,  0,  0,  45, 45,
                9,  0,
                { -1, -1, -1, -1},
                0,
	},

	{
		"Mage",
                "The basic spellcaster, able to learn 64 spells from\none major and one minor magic realm.",
		{-5, 3, 0, 1, -2, 1},
		30, 36, 30, 2,  16, 20, 34, 20,
		7,  13, 9,  0,  0,  0,  15, 15,
                0, 30,
                { -1, -1, -1, -1},
                CF1_NO_GLOVES | CF1_ZERO_FAIL,
	},

	{
		"Priest",
                "A priest serves a god (Vala or Maia) to bring down the empire of\nfear and shadows of Morgoth. They can use various prayer realms\nof which they can learn up to 64 prayers.",
		{-1, -3, 3, -1, 0, 2},
		25, 30, 32, 2,  16, 8, 48, 35,
		7,  10, 12, 0,  0,  0, 20, 20,
                2, 20,
                { PWR_DET_CURSE, -1, -1, -1},
                CF1_BLESS_WEAPON | CF1_ZERO_FAIL,
	},

	{
		"Rogue",
                "Rogues are masters of tricks, they can steal from shops and monsters\nand lure monsters into deadly monster traps.\nThey can learn up to 24 spells.",
		{ 2, 1, -2, 3, 1, -1},
		45, 32, 28, 5, 32, 24, 60, 66,
		15, 10, 10, 0,  0,  0, 40, 30,
                6, 25,
                { PWR_LAY_TRAP, -1, -1, -1},
                0,
	},

	{
		"Ranger",
                "Warriors/archers/mages, a bit of everything helps them survive.\nThey can use the unique tribal magic and learn up to 32 spells.",
		{ 2, 2, 0, 1, 1, 1},
		30, 32, 28, 3,  24, 16, 56, 72,
		8,  10, 10, 0,  0,  0,  30, 45,
                4, 30,
                { -1, -1, -1, -1},
                0,
	},

	{
		"Paladin",
                "The paladin is a holy warrior, using the crusade realm to battle all\nthat is evil on Middle Earth. They can learn up to 32 prayers.",
		{ 3, -3, 1, 0, 2, 2},
		20, 24, 26, 1,  12, 2, 68, 40,
		7,  10, 11, 0,  0,  0,  35, 30,
                6, 35,
                { -1, -1, -1, -1},
                0,
	},

/**/	{
                "Warlock",
                "Warrior mages, trained in both melee and some forms of magic.\nThey can learn up to 48 spells.",
		{ 2, 2, 0, 1, 0, 1},
		30, 30, 28, 2,  18, 16, 50, 25,
		7,  10,  9, 0,  0,  0,  20, 20,
                4, 50,
                { -1, -1, -1, -1},
                0,
	},

/**/	{
		"Chaos-Warrior",
                "Fighters of chaos, followed by the somewhat unreliable chaos\npatrons they can use the chaos realm to enhance their destructive powers.",
		{ 2, 1, 0, 1, 2, -2},
		20, 25, 25, 1,  14, 12, 65, 40,
		7,  11, 10, 0,  0,  0,  34, 29,
                6, 35,
                { -1, -1, -1, -1},
                0,
	},

	{
		"Monk",
                "Barehanded, lightly armored fighters they wreak havok with\ntheir bare fists, and can also use a few prayers.\nThey can learn up to 24 prayers.",
		{ 2, -1, 1, 3, 2, 1},
		45, 32, 28, 5, 32, 24, 64, 60,
		15, 11, 10, 0,  0,  0, 40, 30,
                6, 40,
                { -1, -1, -1, -1},
                CF1_BLESS_WEAPON,
	},

/**/    {
                "Mindcrafter",
                "From within comes the power of a mindcrafter, using his own psychic\nenergies to battle monsters.",
                {-1, 0, 3, -1, -1, 2},   /* note: spell stat is Wis */
                30, 30, 30, 3,  22, 16, 50, 40,
                10, 10, 10, 0,   0,  0, 20, 30,
                2, 25,
                { -1, -1, -1, -1},
                0,
        },

/**/	{
	        "High-Mage",
                "A high mage can learn 64 spells and only from one realm\nbut they learn them much better and can get them to higher levels.",
        	{-5, 4, 0, 0, -2, 1},
		30, 36, 30, 2,  16, 20, 34, 20,
		7,  13, 9,  0,  0,  0,  15, 15,
                0, 30,
                { -1, -1, -1, -1},
                CF1_NO_GLOVES | CF1_ZERO_FAIL | CF1_BEAM,
	},

/**/	{
                "Mimic",
                "Disguise is the way of the mimic, through the use of cloaks of mimicry\nthey can change shape for a limited time. They also can temporarily\nchange part of their anatomy.",
                {2, 0, 0, 5, -1, 1},
                10, 6, 30, 22,  26, 20, 64, 40,
                11, 13, 9,  0,  0,  0,  25, 25,
                0, 40,
                { -1, -1, -1, -1},
                0,
	},

	{
                "BeastMaster",
                "A beastmaster is a warrior that chose to make peace with some monsters.\nHe can thus summon them at will when in need.",
                {2, -4, -2, 2, 2, 5},
                20, 36, 30, 4,  16, 20, 56, 20,
		7,  13, 9,  0,  0,  0,  15, 15,
                0, 20,
                { PWR_SUMMON_MONSTER, PWR_COMPANION, -1, -1},
                0,
	},

	{
                "Alchemist",
                "An alchemists can quickly create powerful magic items through the correct use\nof the essences of magic they can extract from magical objects.",
                {-2, 3, 4, 2, -2, 0},
                30, 60, 10, 2,  26, 20, 34, 30,
                7,  30, 9,  0,  0,  0,  15, 15,
                0, 40,
                { -1, -1, -1, -1},
                0,
	},

	{
                "Symbiant",
                "A symbiant can merge his/her body with one of a monster unable to move\nby itself. They also have a few spells to help the symbiosis.",
                {0, 2, -2, 2, 2, -3},
                10, 12, 30, 10, 16, 10, 36, 20,
                4,  3,  9,  0,  0,  0,  15, 15,
                0, 20,
                { -1, -1, -1, -1},
                0,
	},

	{
                "Harper",              /* Note : spell stat is Charisma */
                "Harpers can read complex music books and sing songs\nfull of power, beauty or sadness to affect everything that can hear them.",
                {-4, 3, -1, 2, 0, 4},
                10, 16, 20, -5, 16, 20, 34, 20,
                8,  13, 12, 0,  0,  0,  15, 15,
                0, 75,
                { -1, -1, -1, -1},
                CF1_ZERO_FAIL,
	},

	{
/**/            "Power-Mage",
                "Powermage spells come from within and are different for each character.\nSince attack is the best defence, all their spells are offensive.",
                {-5, 5, -2, 0, -2, -1},
                20, 36, 30, 2,  16, 20, 14, 10,
                7,  13, 9,  0,  0,  0,   7,  7,
                0, 20,
                { -1, -1, -1, -1},
                0,
	},

/**/	{
                "Runecrafter",         /* Note : spell stat is Dexterity */
                "Runecrafters use the runes found in Middle Earth to create\nfinely tuned spells for each specific situation.",
                {-3, 0, 0, 3, -3, 1},
                15, 36, 20, 6,  16, 30, 20, 18,
                7,  13, 9,  0,  0,  0,   7,  7,
                0, 40,
                { -1, -1, -1, -1},
                0,
	},

	{
                "Possessor",
                "Only the soul matters, a possessor can abandon his/her current body to\nincarnate in the body of a dead monster, thus gaining its powers\nand weaknesses.",
                { 1, -2, -2, 1, 1, 0},
                25, 18, 18, 1,  14, 2, 30, 25,
                12, 7,  10, 0,  0,  0,  25, 25,
                9, 40,
                { -1, -1, -1, -1},
                0,
	},

	{
                "Sorceror",
                "Masters of the Art of Sorcery, they devote their life to magic.\nSorcerors can use every magic realm, but at the cost of being\nhopeless at hand to hand combat.",
                { -5, 6, 4, 2, -5, 1},
                35, 48, 38, 3, 22, 12, 10, 15,
                22, 17, 20, 0,  0,  0, 15, 15,
                4, 60,
                { -1, -1, -1, -1},
                CF1_ZERO_FAIL,
	},

	{
                "Archer",
                "'Kill them before they see you' could be the motto of the archer class.\nAs deadly with a bow as a warrior is with a sword.",
                { 2, 1, 0, 2, 1, 1},
                30, 32, 28, 3,  24, 16, 56, 82,
		8,  10, 10, 0,  0,  0,  30, 45,
                4, 30,
                { -1, -1, -1, -1},
                0,
	},

/**/	{ /* Added -KMW- */
		"Illusionist",
                "The illusionist is similar to a mage but prefers to confuse and trick monsters.",
		{-5, 3, 0, 1, -2, 1},
		30, 36, 30, 2,  16, 20, 34, 20,
		7,  13, 9,  0,  0,  0,  15, 15,
                0, 30,
                { -1, -1, -1, -1},
                CF1_ZERO_FAIL,
	},

/**/	{
                "Druid",
                "The druids respect Yavanna, Vala of the forests and nature. They are\nprotectors of nature and as such they gain access to the druid stones\nas the source of their power.",
                {-2, -2, 3, 1, 1, 2},
                20, 20, 38, 4,  8, 16, 42, 35,
                7,  10, 10, 0,  0,  0, 18, 20,
                3, 30,
                { -1, -1, -1, -1},
                CF1_ZERO_FAIL,
	},

/**/	{
                "Necromancer",
                "A necromancer's main goal is to be able to avoid death. When killed they\ncan resurrect themselves if they kill enough monsters in their undead\n form. They can also use the nether magic realm.",
                {-3, 3, -1, 3, -1, -5},
                16, 40, 42, 3,  10, 8, 35, 20,
                9,  16, 3, 0,  0,  0, 10, 5,
                1, 40,
                { PWR_NECRO, PWR_COMPANION, -1, -1},
                CF1_ZERO_FAIL,
	},

	{
                "Unbeliever",
                "Disbelieve so much in magic that they generate an antimagic field\naround themselves to prevent the use of most magics and thus they are\nforbidden the use of most magical items.",
                { 5, -10, -10, 4, 5, 1},
                25,  0, 40, 1,  30, 10, 80, 60,
                12,  0, 18, 0,  4,  5, 45, 45,
                10, 20,
                { -1, -1, -1, -1},
                0,
	},

/**/	{ /* Added -SC- */
		"Daemonologist",
                "The goal of a daemonologist is to control demons as pets.\nThey use the terrific daemon blades to achieve that goal thus gaining\naccess to the daemon magic realm.",
		{-2, 3, -1, 1, -1, -1},
		20, 36, 35, 3,  15, 12, 35, 25,
		7,  15, 10,  0,  0,  0,  15, 10,
                0, 30,
                { -1, -1, -1, -1},
                0,
	},

/**/	{
		"Weaponmaster",
                "Master of one type of weapon (sword, axe, polearms, hafted, blunt)\nbut very poor with anything else.",
                { 4, -3, -3, 2, 2, -1},
                23,  10, 16,  1, 14,  2, 70, 15,
                10,   3,  8,  0,  0,  0, 45, 10,
                9, 30,
                { -1, -1, -1, -1},
                0,
	},

	{ /* -SC- */
		"Merchant",
                "Money can't buy everything... wait, it can!",
		{ -2, 3, 0, -3, -2, 6},
		20, 36, 30, 1, 30, 10, 34, 20,
		9,  13, 10, 0, 0,  0,  15, 15,
                3, 35,
                { PWR_MERCHANT, PWR_MIDAS_TCH, -1, -1},
                0,
	},
};

/*
 * Player Classes
 *
 *      Title,
 *      {STR,INT,WIS,DEX,CON,CHR},
 *      c_dis, c_dev, c_sav, c_stl, c_srh, c_fos, c_thn, c_thb,
 *      x_dis, x_dev, x_sav, x_stl, x_srh, x_fos, x_thn, x_thb,
 *      HD, Exp
 */

/*
 * Info on the spells/realms
 */
magic_type realm_info_base[MAX_REALM][64] =
{
        /* Nothing */
        {
                {NULL}
        },

        /* Valarin */
        {
                {  1,  1, 10,   4},
                {  1,  1, 20,   4},
                {  1,  2, 15,   4},
                {  1,  2, 25,   4},
                {  3,  2, 25,   4},
                {  3,  3, 27,   4},
                {  3,  3, 27,   4},
                {  3,  3, 28,   4},

                {  5,  4, 29,   4},
                {  5,  4, 30,   4},
                {  5,  5, 32,   4},
                {  5,  5, 34,   4},
                {  7,  6, 36,   4},
                {  7,  7, 38,   4},
                {  7,  7, 38,   4},
                {  7,  7, 38,   4},

                {  9,  6, 38,   4},
                {  9,  7, 38,   4},
                {  9,  7, 40,   4},
                { 11,  8, 42,   4},
                { 11,  9, 42,   4},
                { 13,  9, 45,   4},
                { 15, 11, 45,   4},
                { 15, 12, 50,   4},

                { 15, 14, 50,   5},
                { 17, 15, 55,   7},
                { 21, 16, 60,   7},
                { 23, 20, 65,   9},
                { 25, 25, 70,  12},
                { 33, 25, 90,  15},
                { 39, 32, 95,  20},

                {  7,  5, 30,   4},
                {  9,  5, 35,   5},
                { 13,  6, 45,   5},
                { 17, 25, 55,  10},
                { 23, 12, 70,  15},
                { 31, 35, 85,  20},
                { 35, 65, 90,  30},

                { 11,  8, 42,   4},
                { 13, 10, 45,   4},
                { 15, 10, 50,   4},
                { 19, 15, 55,   5},
                { 21, 20, 60,  10},
                { 29, 30, 75,  20},
                { 35, 35, 85,  30},

                {  7, 10, 35,   4},
                { 15, 21, 60,  10},
                { 15, 21, 60,  10},
                { 25, 25, 75,  10},
                { 30, 25, 85,  10},
                { 40, 50, 95, 100},
                { 47, 100,90, 250},

                { 12, 12, 38,   4},
                { 21, 21, 38,   4},
                { 22, 22, 40,   4},
                { 32, 28, 42,   4},
                { 32, 30, 42,   4},
                { 32, 35, 90,   4},

                { 12, 10, 45,   4},
                { 20, 25, 60,  10},
                { 25, 25, 70,  10},
                { 28, 25, 80,  20},
                { 35, 50, 90,  50},
                { 49, 75, 95, 250},
        },

        /* Magery Magic */
        {
                { 1, 1, 10, 4 },
                { 1, 1, 12, 4 },
                { 2, 2, 12, 4 },
                { 2, 2, 12, 4 },
                { 3, 2, 14, 4 },
                { 3, 3, 14, 6 },
                { 4, 3, 15, 8 },
                { 5, 6, 25, 12 },

                { 6, 5, 18, 10 },
                { 6, 6, 20, 12 },
                { 7, 7, 22, 15 },
                { 7, 7, 22, 15 },
                { 8, 7, 25, 16 },
                { 8, 9, 30, 16 },
                { 9, 8, 35, 18 },
                { 10, 10, 50, 20 },

                { 11, 8, 40, 25 },
                { 12, 9, 35, 35 },
                { 13, 10, 70, 50 },
                { 13, 15, 45, 37 },
                { 14, 15, 45, 39 },
                { 16, 18, 50, 43 },
                { 17, 13, 40, 35 },
                { 18, 15, 50, 45 },

                { 20, 30, 65, 50 },
                { 22, 5, 30, 25 },
                { 23, 13, 50, 40 },
                { 24, 20, 55, 50 },
                { 25, 21, 50, 40 },
                { 25, 25, 55, 50 },
                { 27, 35, 75, 75 },
                { 27, 28, 60, 65 },

                { 24, 25, 45, 75 },
                { 30, 15, 44, 90 },
                { 33, 24, 50, 90 },
                { 35, 25, 75, 100 },
                { 35, 26, 35, 75 },
                { 36, 33, 65, 140 },
                { 38, 24, 50, 100 },
                { 40, 28, 66, 125 },

                { 16, 12, 35, 40 },
                { 18, 14, 44, 50 },
                { 23, 24, 48, 75 },
                { 24, 10, 30, 50 },
                { 28, 27, 55, 100 },
                { 35, 40, 65, 150 },
                { 38, 25, 10, 175 },
                { 44, 50, 65, 250 },

                { 10, 12, 22, 25 },
                { 15, 16, 30, 45 },
                { 18, 20, 45, 60 },
                { 22, 26, 65, 80 },
                { 28, 50, 35, 100 },
                { 33, 35, 50, 150 },
                { 36, 32, 85, 200 },
                { 45, 60, 88, 210 },

                { 32, 28, 50, 220 },
                { 36, 44, 55, 230 },
                { 39, 50, 65, 235 },
                { 42, 65, 50, 240 },
                { 44, 45, 70, 245 },
                { 45, 50, 65, 250 },
                { 47, 66, 75, 253 },
                { 49, 70, 95, 255 },
        },

        /* Shadow Magic */
        {
                {1, 1, 10, 4},
                {1, 2, 10, 4},
                {2, 2, 11, 4},
                {2, 4, 15, 5},
                {3, 4, 18, 6},
                {3, 4, 20, 7},
                {4, 6, 22, 7},
                {5, 8, 30, 8},

                { 7, 10, 30, 10},
                { 9, 15, 32, 12},
                {10, 15, 35, 15},
                {12, 18, 38, 19},
                {14, 23, 39, 24},
                {15, 23, 40, 28},
                {17, 24, 43, 30},
                {19, 25, 46, 31},

                {21, 25, 50, 40},
                {23,  0, 53, 45},
                {25, 30, 56, 52},
                {28, 32, 60, 59},
                {30, 34, 62, 63},
                {31, 36, 64, 68},
                {32, 36, 68, 70},
                {34, 45, 70, 75},

                {36, 30, 73, 80},
                {38, 36, 78, 92},
                {40, 39, 81, 100},
                {43, 45, 84, 112},
                {45, 56, 86, 123},
                {47, 70, 90, 135},
                {48, 80, 92, 145},
                {49, 100, 93, 200},

                {21, 35, 50, 90},
                {25, 48, 59, 100},
                {26, 49, 62, 102},
                {40, 60, 75, 112},
                {50, 70, 92, 220},

                { 3,   1, 12,  5},
                { 8,  12, 21, 10},
                {15,  20, 35, 21},
                {25,  36, 52, 35},
                {32,  40, 68, 45},
                {41, 100, 80, 122},

                {25, 40, 50, 40},
                {30, 45, 55, 50},
                {35, 50, 60, 60},
                {40, 55, 65, 70},
                {45, 60, 70, 80},
                {50, 65, 75, 90},

                {13, 11, 53,  9},
                {20, 19, 60, 13},
                {26, 26, 63, 18},
                {29, 34, 69, 23},
                {34, 45, 75, 45},
                {38, 50, 80, 56},
                {46, 67, 86, 95},

                {30, 32, 68, 70},
                {32, 35, 70, 80},
                {34, 38, 73, 89},
                {38, 42, 80, 98},
                {42, 43, 83, 105},
                {45, 44, 84, 116},
                {47, 50, 86, 129},
                {50, 59, 90, 150},
        },

				/* Mage: Chaos Magic */

			{
				{ 1, 1, 20, 4 },
				{ 1, 2, 22, 4 },
				{ 2, 2, 25, 4 },
				{ 5, 5, 30, 1 },
				{ 9, 6, 50, 1 },
				{ 13, 9, 45, 6 },
				{ 14, 9, 45, 6 },
				{ 15, 9, 35, 5 },

				{ 17, 10, 25, 5 },
				{ 19, 12, 45, 9 },
				{ 21, 13, 45, 10 },
				{ 23, 15, 50, 11 },
				{ 25, 16, 50, 12 },
				{ 25, 18, 60, 8 },
				{ 30, 20, 80, 15 },
				{ 35, 40, 85, 40 },

				{ 11, 7, 45, 9 },
				{ 15, 15, 80, 35 },
				{ 16, 14, 80, 35 },
				{25, 25, 85, 100 },
				{ 30, 25, 85, 150 },
				{ 42, 50, 85, 250 },
				{ 45, 90, 80, 250 },
				{ 47, 100, 90, 250 },

				{ 20, 20, 66, 8 },
				{ 35, 32, 85, 35 },
				{ 37, 34, 75, 40 },
				{ 41, 42, 85, 100 },
				{ 43, 44, 80, 150 },
				{ 45, 48, 85, 200 },
				{ 47, 75, 80, 200 },
				{ 49, 100, 85, 250 }
			},

        /* Nether Magic */
        {
                {  1,  1, 10,   4},
                {  1,  1, 20,   4},
                {  1,  2, 15,   4},
                {  1,  2, 25,   4},
                {  3,  2, 25,   4},
                {  3,  3, 27,   4},
                {  3,  3, 27,   4},
                {  3,  3, 28,   4},

                {  5,  4, 29,   4},
                {  5,  4, 30,   4},
                {  5,  5, 32,   4},
                {  5,  5, 34,   4},
                {  7,  6, 36,   4},
                {  7,  7, 38,   4},
                {  7,  7, 38,   4},
                {  7,  7, 38,   4},

                {  9,  6, 38,   4},
                {  9,  7, 38,   4},
                {  9,  7, 40,   4},
                { 11,  8, 42,   4},
                { 11,  9, 42,   4},
                { 13,  9, 45,   4},
                { 15, 11, 45,   4},
                { 15, 12, 50,   4},

                { 15, 14, 50,   5},
                { 17, 15, 55,   7},
                { 21, 16, 60,   7},
                { 23, 20, 65,   9},
                { 25, 25, 70,  12},
                { 33, 25, 90,  15},
                { 39, 32, 95,  20},

                {  1,  1, 10,   4},
                {  9,  5, 35,   4},
                { 11,  7, 45,   4},
                { 15, 10, 55,   4},
                { 20, 10, 60,   4},
                { 25, 20, 70,   4},
                { 35, 50, 85,   4},

                {  5,  4, 30,   4},
                {  7,  5, 35,   4},
                { 15,  8, 45,   4},
                { 21, 13, 55,   4},
                { 25, 20, 60,  10},
                { 39, 50, 90,  50},
                { 45, 75, 95,  50},

                {  5,  4, 30,   4},
                {  9,  7, 40,   4},
                { 19, 12, 55,   4},
                { 21, 12, 60,  10},
                { 23, 15, 65,  10},
                { 31, 20, 80,  10},

                {  3,  5, 30,   4},
                {  7,  5, 40,   4},
                { 15, 10, 55,   4},
                { 23, 25, 65,  10},
                { 31, 30, 80,  15},
                { 39, 40, 90,  20},
                { 42, 50, 95,  20},

                { 11, 10, 40,   4},
                { 21, 15, 50,   6},
                { 25, 25, 60,   8},
                { 33, 30, 70,  10},
                { 39, 60, 90,  35},
                { 44, 60, 95,  30},
        },

        /* Crusade Magic */

        {
                {  1,  1, 20,   4},
                {  1,  2, 25,   4},
                {  1,  2, 25,   4},
                {  3,  2, 25,   5},
                {  3,  2, 25,   5},
                {  3,  2, 30,   5},
                {  5,  3, 30,   6},
                {  5,  3, 35,   6},

                {  5,  3, 35,   6},
                {  7,  5, 40,   7},
                {  7,  5, 41,   7},
                {  7,  5, 42,   8},
                {  9,  7, 44,   5},
                {  9,  7, 45,   8},
                {  9,  9, 46,   8},
                { 11,  9, 48,   9},

                { 11,  5, 49,   5},
                { 11,  5, 50,   5},
                { 13,  9, 51,   9},
                { 13, 11, 53,   9},
                { 15, 11, 55,   9},
                { 15,  7, 57,  10},
                { 17, 11, 59,  10},
                { 17, 15, 60,  12},

                { 19, 11, 62,  12},
                { 21, 11, 65,  15},
                { 23, 13, 67,  15},
                { 25, 15, 69,  15},
                { 25, 20, 71,  20},
                { 29, 20, 75,  30},
                { 35, 39, 85,  40},
                { 42, 45, 90,  50},
        },

        /* Sigaldry Magic */
        {
                {  1,  1, 20,   4},
                {  1,  2, 25,   4},
                {  1,  2, 25,   4},
                {  3,  2, 25,   5},
                {  3,  2, 25,   5},
                {  3,  2, 30,   5},
                {  5,  3, 30,   6},
                {  5,  3, 35,   6},

                {  5,  3, 35,   6},
                {  7,  5, 40,   7},
                {  7,  5, 41,   7},
                {  7,  5, 42,   8},
                {  9,  7, 44,   5},
                {  9,  7, 45,   8},
                {  9,  9, 46,   8},
                { 11,  9, 48,   9},

                { 11,  5, 49,   5},
                { 11,  5, 50,   5},
                { 13,  9, 51,   9},
                { 13, 11, 53,   9},
                { 15, 11, 55,   9},
                { 15,  7, 57,  10},
                { 17, 11, 59,  10},
                { 17, 15, 60,  12},

                { 19, 11, 62,  12},
                { 21, 11, 65,  15},
                { 23, 13, 67,  15},
                { 25, 15, 69,  15},
                { 25, 20, 71,  20},
                { 29, 20, 75,  30},
                { 35, 39, 85,  40},
                { 42, 45, 90,  50},
        },
                        /* Symbiotic */
			{
                                {  1,  2, 25,   4},
                                {  3,  3, 30,   5},
                                {  6,  7, 35,   7},
                                {  9, 10, 40,  10},
                                { 12, 20, 50,  15},
                                { 16, 20, 55,  20},
                                { 20, 26, 40,  15},
				{ 99,  0,  0,   0},

				{ 99,  0,  0,   0},
				{ 99,  0,  0,   0},
				{ 99,  0,  0,   0},
				{ 99,  0,  0,   0},
				{ 99,  0,  0,   0},
				{ 99,  0,  0,   0},
				{ 99,  0,  0,   0},
				{ 99,  0,  0,   0},

                                { 24, 30, 60,  36},
                                { 26, 35, 60,  30},
                                { 30, 40, 60,  40},
                                { 35, 43, 63,  50},
                                { 36, 90, 40, 100},
                                { 50,100, 50, 200},
				{ 99,  0,  0,   0},
				{ 99,  0,  0,   0},

				{ 99,  0,  0,   0},
				{ 99,  0,  0,   0},
				{ 99,  0,  0,   0},
				{ 99,  0,  0,   0},
				{ 99,  0,  0,   0},
				{ 99,  0,  0,   0},
				{ 99,  0,  0,   0},
				{ 99,  0,  0,   0}
			},
                        /* Music */
			{
                                { 1,  1,  10,   2},
                                { 2,  0,   0,   0},
                                { 3,  2,  20,   3},
                                { 4,  3,  20,   4},
                                { 5,  3,  20,   6},
                                { 7,  3,  30,   8},
                                { 9,  3,  30,   10},
                                { 10,  3,  30,   12},

                                { 12,  5,   40,   20},
                                { 16,  10,  40,   25},
                                { 18,  16,  45,   30},
                                { 20,  20,  50,   35},
                                { 23,  3,  50,   38},
                                { 24,  4,   50,   41},
                                { 26,  8,  60,   42},
                                { 27,  9,  70,   46},

                                { 10, 100,  20,   13},
                                { 22,  23,  30,   26},
                                { 23,  18,  35,   27},
                                { 26,  12,  37,   29},
                                { 32,  30,  41,   36},
                                { 33,  18,  43,   40},
                                { 38,  50,  46,   42},
                                { 45,  60,  50,   56},

                                { 23,   6,  20,   23},
                                { 26,  25,  30,   26},
                                { 29,   8,  41,   30},
                                { 34,  16,  43,   35},
                                { 35,  40,  46,   50},
                                { 40,  20,  50,   68},
                                { 42,  20,  62,   73},
                                { 50,  20,  70,  200}
			},
                        /* Magic */
                {
                        {  1,  1, 22,   4},
                        {  1,  1, 23,   4},
                        {  1,  2, 24,   4},
                        {  1,  2, 26,   4},
                        { 99,  0,  0,   0},
			{  3,  3, 25,   3},
			{ 99,  0,  0,   0},
			{  3,  3, 25,   1},
			{  3,  3, 27,   3},

			{  3,  4, 30,   1},
			{  5,  4, 30,   4},
			{  5,  5, 30,   6},
			{  5,  5, 30,   4},
			{  5,  5, 35,   4},
			{  7,  6, 35,   5},
			{  7,  6, 30,   5},
			{  7,  6, 40,   6},
			{  9,  7, 44,   8},

			{  9,  7, 45,   8},
			{  9,  7, 75,   9},
			{  9,  7, 45,   8},
			{ 11,  7, 45,   9},
			{ 11,  7, 75,   6},
			{ 13,  7, 50,   6},
			{ 15,  9, 50,   6},
			{ 17,  9, 50,   7},

			{ 19, 12, 55,   8},
			{ 21, 12, 90,   8},
			{ 23, 12, 60,   8},
			{ 25, 12, 65,  10},
			{ 29, 18, 65,  12},
			{ 33, 21, 80,  15},
			{ 37, 25, 95,  21},

			{  7,  7, 20,  28},
			{  9, 12, 40,  44},
			{ 15, 17, 60,  29},
			{ 20, 18, 60,  24},
			{ 25, 25, 75,  19},

			{ 10,  6, 50,  12},
			{ 12,  9, 60,  16},
			{ 20, 15, 70,  20},
			{ 27, 25, 75,  29},
			{ 35, 35, 85,  34},
			{ 42, 45, 95, 200},

			{ 5,  5,  50,   8},
			{ 10, 10, 70,  40},
			{ 25, 30, 95, 160},
			{ 30, 50, 70,  40},
			{ 40, 75, 80, 100},

			{  4,  5, 50,  20},
			{  4,  5, 50,  20},
			{  4,  5, 50,  20},
			{  8, 10, 75,  40},
			{ 15, 20, 85,  60},

			{  5,  5, 50,  80},
			{ 10, 12, 75, 120},
			{ 15, 20, 80, 200},
			{ 22, 30, 50, 250},	/* 350 */
			{ 45, 70, 75, 250},	/* 450 */

			{ 99,  0,  0,   0},
			{ 99,  0,  0,   0},
			{ 99,  0,  0,   0},
			{ 99,  0,  0,   0},
			{ 99,  0,  0,   0}
                },
                        /* Prayer */
                {
			{  1,  1, 10,   4},
			{  1,  2, 15,   4},
			{  1,  2, 20,   4},
			{  1,  2, 25,   4},
			{  3,  2, 25,   1},
			{  3,  3, 27,   2},
			{  3,  3, 27,   2},
			{  3,  3, 28,   4},

			{  5,  4, 29,   3},
			{  5,  4, 30,   4},
			{  5,  4, 32,   4},
			{  5,  5, 34,   4},
			{  7,  5, 36,   3},
			{  7,  5, 38,   4},
			{  7,  6, 38,   5},
			{  7,  7, 38,   5},

			{  9,  6, 38,   4},
			{  9,  7, 38,   4},
			{  9,  7, 40,   4},
			{ 11,  8, 42,   4},
			{ 11,  8, 42,   4},
			{ 11,  9, 55,   5},
			{ 13, 10, 45,   4},
			{ 13, 11, 45,   4},
			{ 15, 12, 50,   5},

			{ 15, 14, 50,   5},
			{ 17, 14, 55,   7},
			{ 21, 16, 60,   7},
			{ 25, 20, 70,  12},
			{ 33, 55, 90,  15},
			{ 39, 32, 95,  20},

			{  3,  3, 50,   2},
			{ 10, 10, 80,  20},
			{ 20, 20, 80,  20},
			{ 25, 10, 80, 150},
			{ 35, 50, 80, 230},

			{ 15,  5, 50,  25},
			{ 17,  7, 60,  45},
			{ 30, 50, 80, 130},
			{ 35, 70, 90, 230},
			{ 35, 70, 90, 250},	/* 350 */

			{ 15,  7, 70,  25},
			{ 20, 10, 75,  60},
			{ 25, 25, 80, 250},
			{ 35, 35, 80, 115},
			{ 45, 60, 75, 250},	/* 350 */

			{  5,  6, 50,  40},
			{ 15, 20, 80,  25},
			{ 25, 40, 80, 160},
			{ 35, 50, 80, 230},
			{ 37, 60, 85, 250},	/* 325 */
			{ 45, 95, 85, 250},	/* 530 */

			{  3,  3, 50,   6},
			{ 10, 10, 50,   8},
			{ 20, 20, 80,  16},
			{ 30, 40, 75, 133},
			{ 35, 50, 75,  11},
			{ 40, 60, 75, 250},	/* 300 */

			{ 99,  0,  0,    0},
			{ 99,  0,  0,    0},
			{ 99,  0,  0,    0},
			{ 99,  0,  0,    0},
			{ 99,  0,  0,    0},
			{ 99,  0,  0,    0}
                },
                /* Illusion */
		{
			{  1,  1, 22,   4},
			{  1,  1, 23,   4},
			{  1,  2, 24,   4},
			{  1,  2, 26,   4},
			{  1,  2, 25,   3},
			{  3,  3, 25,   3},
			{  3,  3, 26,   3},
			{  3,  3, 25,   1},
			{  3,  3, 27,   3},

			{  3,  4, 30,   1},
			{  5,  4, 30,   4},
			{  5,  5, 30,   6},
			{  5,  5, 30,   4},
			{  5,  5, 35,   4},
			{  7,  6, 35,   5},
			{  7,  6, 30,   5},
			{  7,  6, 40,   6},
			{  9,  7, 44,   8},

			{  9,  7, 45,   8},
			{  9,  7, 75,   9},
			{  9,  7, 45,   8},
			{ 11,  7, 45,   9},
			{ 11,  7, 75,   6},
			{ 13,  7, 50,   6},
			{ 15,  9, 50,   6},
			{ 17,  9, 50,   7},

			{ 19, 12, 55,   8},
			{ 21, 12, 90,   8},
			{ 23, 12, 60,   8},
			{ 25, 12, 65,  10},
			{ 29, 18, 65,  12},
			{ 33, 21, 80,  15},
			{ 37, 25, 95,  21},

			{  7,  7, 20,  28},
			{  9, 12, 40,  44},
			{ 15, 17, 60,  29},
			{ 20, 18, 60,  24},
			{ 25, 25, 75,  19},
			{ 45, 50, 60,  30},

			{ 10,  6, 50,  12},
			{ 12,  9, 60,  16},
			{ 20, 15, 70,  20},
			{ 27, 25, 75,  29},
			{ 35, 35, 85,  34},
			{ 40, 40, 80,  50},
			{ 42, 45, 95, 200},

			{ 5,  5,  50,   8},
			{ 10, 10, 70,  40},
			{ 15, 20, 80,  50},
			{ 25, 30, 95, 160},
			{ 30, 50, 70,  40},
			{ 40, 75, 80, 100},

			{  4,  5, 50,  20},
			{  4,  5, 50,  20},
			{  4,  5, 50,  20},
			{  8, 10, 75,  40},
			{ 15, 15, 90,  45},
			{ 15, 20, 85,  60},

			{  5,  5, 50,  80},
			{ 10, 12, 75, 120},
			{ 15, 20, 80, 200},
			{ 20, 30, 50,  75},
			{ 22, 30, 50, 250},	/* 350 */
			{ 45, 70, 75, 250}	/* 450 */
                },

        /* Tribal Magic */
        {
                {  1,  1, 10,   4},
                {  2,  2, 12,   4},
                {  2,  1, 16,   4},
                {  3,  3, 18,   4},
                {  3,  4, 18,   4},
                {  4,  1, 20,   6},
                {  5,  7, 22,   7},
                {  7,  9, 25,   7},

                {  8,  4, 26,   8},
                {  9, 10, 28,   9},
                { 11, 13, 30,   9},
                { 12, 10, 34,  10},
                { 14,  7, 36,  13},
                { 16,  5, 38,  15},
                { 16,  7, 42,  16},
                { 18, 18, 43,  17},

                { 20,  8, 45,  18},
                { 20, 30, 48,  20},
                { 22,  5, 50,  22},
                { 25, 25, 52,  25},
                { 27, 35, 54,  28},
                { 32, 25, 55,  30},
                { 34, 10, 56,  34},
                { 36, 20, 70,  37},

                { 40, 50, 80,  45},
                { 41, 70, 85,  50},
                { 43, 25, 86,  53},
                { 45, 25, 87,  55},
                { 46, 35, 88,  60},
                { 48, 90, 89,  70},
                { 50, 90, 90,  78},
                { 99,  0, 92,  80},
        },

        /* Druidistic */
        {
                { 1, 1, 10,  4},
                { 2, 0, 15,  6},
                { 4, 4, 18,  8},
                { 5, 2, 20, 10},
                { 6, 8, 24, 13},
                { 8, 9, 26, 16},
                { 9, 10, 28, 20},
                { 10, 12, 34, 25},

                { 11, 11, 30, 30},
                { 12, 10, 35, 38},
                { 14, 14, 38, 42},
                { 15, 12, 40, 46},
                { 16, 18, 45, 49},
                { 18, 19, 46, 55},
                { 19, 20, 48, 58},
                { 20, 22, 54, 62},

                { 21,  8, 57, 68},
                { 22, 26, 60, 75},
                { 24, 26, 62, 78},
                { 25, 30, 65, 82},
                { 26, 35, 68, 85},
                { 28, 38, 70, 90},
                { 29, 41, 73, 93},
                { 30, 43, 75, 96},

                { 31, 45, 80, 100},
                { 32, 46, 82, 103},
                { 34, 50, 83, 110},
                { 35, 51, 85, 115},
                { 36, 53, 86, 119},
                { 38, 60, 89, 123},
                { 39, 65, 90, 128},
                { 40, 80, 91, 130},

                { 41, 80, 92, 130},
                { 42, 86, 93, 135},
                { 44, 20, 94, 145},
                { 45, 90, 95, 165},
                { 46,  2, 95, 180},
                { 48, 100, 95, 200},
                { 49, 105, 95, 210},
                { 50, 255, 95, 220},
        },

	/* Daemon -SCSCSC- */
	{
		{ 1, 1, 10, 4},
		{ 2, 2, 12, 4},
		{ 3, 4, 16, 6},
		{ 3, 7, 20, 8},
		{ 4, 4, 22, 8},
		{ 5, 8, 25, 8},
		{ 7, 9, 28, 10},
		{ 12, 10, 32, 15},

		{ 3, 2, 15, 6},
		{ 5, 6, 18, 8},
		{ 6, 6, 20, 10},
		{ 10, 14, 30, 12},
		{ 12, 8, 34, 14},
		{ 16, 12, 36, 16},
		{ 18, 16, 40, 18},
		{ 20, 18, 50, 19},

		{ 20, 25, 55, 45},
		{ 25, 20, 60, 52},
		{ 28, 25, 64, 55},
		{ 32, 44, 68, 59},
		{ 38, 35, 72, 65},
		{ 44, 75, 85, 80},
		{ 22, 18, 50, 50},
		{ 25, 25, 60, 65},

		{ 26, 18, 55, 55},
		{ 30, 28, 63, 67},
		{ 38, 34, 70, 75},
		{ 45, 72, 85, 110},
		{ 40, 35, 90, 120},
		{ 42, 58, 92, 130},
		{ 45, 40, 94, 140},
		{ 48, 60, 95, 150},
        },

        /* Spirit */
        {
                {  1,  1, 10,  4 },
                {  5,  6, 18,  4 },
                { 12,  8, 26, 10 },
                { 20, 18, 30, 15 },
                { 26, 25, 45, 26 },
                { 32, 30, 68, 50 },
                { 37, 50, 80, 70 },
                { 43, 65, 95, 90 },

                {  1,  1, 10,   4},
                {  7,  7, 18,   8},
                { 14, 10, 28,  14},
                { 22, 18, 38,  24},
                { 28, 25, 48,  23},
                { 35, 32, 58,  45},
                { 40, 42, 68,  68},
                { 42, 50, 78,  95},

                {  5,  3, 10,   4},
                {  9,  7, 18,   7},
                { 18, 12, 28,  14},
                { 25, 15, 38,  24},
                { 31, 20, 58,  34},
                { 36, 30, 68,  54},
                { 42, 42, 78,  64},
                { 48, 50, 95,  74},

                {  5,  3, 10,   4},
                { 12,  7, 18,  12},
                { 18, 12, 28,  24},
                { 25, 20, 38,  34},
                { 28, 25, 58,  44},
                { 32, 30, 68,  54},
                { 35, 33, 78,  64},
                { 40, 50, 88,  74},
        },
};


/*
 * Hack -- the spell information table.
 *
 *   Class Name
 *
 *   Spell Book
 *   Spell Xtra
 *
 *   Spell Stat,
 *   Spell Type,
 *
 *   Spell Level,
 *   Spell Encumbrance,
 */
player_magic magic_info[MAX_CLASS] =
{
	{
		/*** Warrior ***/

		0,
		0,

		A_STR,
		0,

                0,
                0,
                0,
		99,
		0,

                1,
	},

	{
		/*** Mage ***/

                TV_MAGERY_BOOK,
		0,

		A_INT,
		0,

                0,
                0,
                0,
		1,
		300,

                6,
	},

	{
		/*** Priest ***/

                TV_VALARIN_BOOK,
		0,

		A_WIS,
		1,

                0,
                -5,
                -5,
		1,
		350,

                6,
	},


	{
		/*** Rogue ***/

        TV_MAGERY_BOOK,
		0,

		A_INT,
		0,

                4,
                26,
                20,
		5,
		350,

                3,
	},


	{
		/*** Ranger ***/

        TV_MAGERY_BOOK,
		0,

		A_INT,
		0,

                2,
                13,
                10,
		3,
		400,

                3,
	},


	{
		/*** Paladin ***/

        TV_VALARIN_BOOK,
		0,

		A_WIS,
		1,

                1,
                9,
                10,
		1,
		400,

                3,
    },

    {
        /*** Warrior-Mage ***/

        TV_MAGERY_BOOK,
		0,

		A_INT,
		0,

                3,
                18,
                13,
		1,
                350,

                4,
	},

	{
                /*** Chaos Warrior ***/
                TV_MAGERY_BOOK,
		0,

		A_INT,
		0,

                1,
                9,
                5,
                2,
                400,

                4,
	},


	{
        /*** Monk ***/

        TV_VALARIN_BOOK,
		0,

                A_WIS,
		0,

                1,
                7,
                6,
		1,
		300,

                3,
	},

	{
        /*** Mindcrafter ***/

        TV_VALARIN_BOOK,
		0,

		A_WIS,
                0,

                0,
                0,
                0,
                99,
                300,

                1,
        },
	{
        /*** High Mage ***/

        TV_MAGERY_BOOK,
		0,

		A_INT,
		0,

                -2,
                -16,
                -12,
		1,
		300,

                12,
	},

	{
                /*** Mimic ***/

		0,
		0,

                A_DEX,
		0,

                0,
                0,
                0,
		99,
                200,

                1,
	},
	{
                /*** BeastMaster ***/

                TV_MAGERY_BOOK,
		0,

                A_CHR,
		0,

                2,
                0,
                0,
                2,
                250,

                2,
	},
	{
                /*** Alchemist ***/

		0,
		0,

		A_STR,
		0,

                0,
                0,
                0,
		99,
		0,

                1,
	},
	{
                /*** Symbiant ***/

                TV_MAGERY_BOOK,
		0,

		A_INT,
		0,

                0,
                0,
                0,
		1,
		300,

                5,
	},
	{
                /*** Harper ***/

                TV_MAGERY_BOOK,
		0,

                A_CHR,
		0,

                0,
                0,
                0,
                1,
                300,

                1,
	},
        {
                /*** Power Mage ***/

		0,
		0,

                A_INT,
		0,

                0,
                0,
                0,
		99,
		300,

                1,
	},
        {
                /*** Runecrafter ***/

		0,
		0,

                A_DEX,
		0,

                0,
                0,
                0,
                1,
                300,

                1,
	},

	{
                /*** Possessor ***/

		0,
		0,

                A_WIS,
		0,

                0,
                0,
                0,
		99,
                400,

                1,
	},

	{
        /*** Sorceror ***/

                TV_MAGERY_BOOK,
		0,

		A_INT,
		0,

                -1,
                -8,
                -9,
		1,
                100,

                1,
	},
	{
                /*** Archer ***/

		0,
		0,

                A_DEX,
		0,

                0,
                0,
                0,
		99,
		0,

                1,
	},

	{	/* Added this class -KMW- */
		/*** Illusionist ***/

                TV_MAGERY_BOOK,
		0,

                A_INT,
		2,

                0,
                0,
                0,
		1,
		300,

                9,
	},

	{
                /*** Druid ***/

                TV_VALARIN_BOOK,
		0,

		A_WIS,
		1,

                0,
                0,
                0,
		1,
		350,

                4,
	},

	{
                /*** Necromancer ***/

                TV_MAGERY_BOOK,
		0,

                A_CON,
		1,

                0,
                0,
                0,
		1,
		350,

                3,
	},

	{
                /*** Unbeliever ***/

		0,
		0,

		A_STR,
		0,

                0,
                0,
                0,
		99,
		0,

                0,
	},

	{
                /*** Daemonologist ***/
                TV_MAGERY_BOOK,
		0,

		A_INT,
		0,

                0,
                0,
                0,
                1,
                300,

                4,
	},

	{
                /*** Weaponmaster ***/

		0,
		0,

		A_STR,
		0,

                0,
                0,
                0,
		99,
		0,

                0,
	},

	{
		/*** Merchant ***/

		0,
		0,

		A_STR,
		0,

                0,
                0,
                0,
		99,
		0,
	},
};


/*
 * PernAngband uses this array instead of the spell flags table -- DG
 */
u32b fake_spell_flags[MAX_REALM][9][2]=
{
        {
                {NULL}
        },

        {       /* Valarin */
                { 0x00000000 ,0x000000ff },
                { 0x00000000 ,0x0000ff00 },
                { 0x00000000 ,0x00ff0000 },
                { 0x00000000 ,0x7f000000 },

                { 0x0000003f ,0x80000000 },
                { 0x00001fc0, 0x00000000 },
                { 0x000fe000, 0x00000000 },
                { 0x03f00000, 0x00000000 },
                { 0xfc000000, 0x00000000 },
        },

        {
                /* Magery, only 8 books */
                {0x00000000, 0x000000ff},
                {0x00000000, 0x0000ff00},
                {0x00000000, 0x00ff0000},
                {0x00000000, 0xff000000},

                {0x000000ff, 0x00000000},
                {0x0000ff00, 0x00000000},
                {0x00ff0000, 0x00000000},
                {0xff000000, 0x00000000},
        },

        /* Shadow */
        {
                {0x00000000, 0x000000ff},
                {0x00000000, 0x0000ff00},
                {0x00000000, 0x00ff0000},
                {0x00000000 ,0xff000000},

                {0x0000001f, 0x00000000},
                {0x000007e0, 0x00000000},
                {0x0001f800, 0x00000000},
                {0x00fe0000, 0x00000000},
                {0xff000000, 0x00000000},
        },

        {
                {0x00000000, 0x000000ff},
                {0x00000000, 0x0000ff00},
                {0x00000000, 0x00ff0000},
                {0x00000000, 0xff000000},
        },

        /* Nether */
        {
                { 0x00000000, 0x000000ff },
                { 0x00000000, 0x0000ff00 },
                { 0x00000000, 0x00ff0000 },
                { 0x00000000, 0x7f000000 },

                { 0x0000003f, 0x80000000 },
                { 0x00001fc0, 0x00000000 },
                { 0x0007e000, 0x00000000 },
                { 0x03f80000, 0x00000000 },
                { 0xfc000000 ,0x00000000 },
        },

        /* Crusade */
        {
                {0x00000000, 0x000000ff},
                {0x00000000, 0x0000ff00},
                {0x00000000, 0x00ff0000},
                {0x00000000, 0xff000000},
        },

        /* Sigaldry */
        {
                {0x00000000, 0x000000ff},
                {0x00000000, 0x0000ff00},
                {0x00000000, 0x00ff0000},
                {0x00000000, 0xff000000},
        },

        {
                {0x00000000, 0x000000ff},
                {0x00000000, 0x0000ff00},
                {0x00000000, 0x00ff0000},
                {0x00000000, 0xff000000},
        },

        {
                {0x00000000, 0x000000ff},
                {0x00000000, 0x0000ff00},
                {0x00000000, 0x00ff0000},
                {0x00000000, 0xff000000},
        },

	{
		/*** Mage spell books ***/
                { 0x00000000, 0x000001ff },
                { 0x00000000, 0x0003fe00 },
                { 0x00000000, 0x03fc0000 },
                { 0x00000001, 0xfc000000 },

                { 0x003e0000, 0x00000000 },
                { 0x0000003e, 0x00000000 },
                { 0x0001f000, 0x00000000 },
                { 0x07c00000, 0x00000000 },
                { 0x00000fc0, 0x00000000 }
	},

	{
		/*** Priest spell books ***/
                { 0x00000000, 0x000000ff },
                { 0x00000000, 0x0000ff00 },
                { 0x00000000, 0x01ff0000 },
                { 0x00000000, 0x7e000000 },

                { 0x03f00000, 0x00000000 },
                { 0x0000000f, 0x80000000 },
                { 0x000001f0, 0x00000000 },
                { 0x000fc000, 0x00000000 },
                { 0x00003e00, 0x00000000 }
        },

	{	/* Added these books -KMW- */
		/*** Illusionist spell books ***/
                { 0x00000000, 0x000001ff },
                { 0x00000000, 0x0003fe00 },
                { 0x00000000, 0x03fc0000 },
                { 0x00000001, 0xfc000000 },

                { 0x03f00000, 0x00000000 },
                { 0x0000007e, 0x00000000 },
                { 0x000fc000, 0x00000000 },
                { 0xfc000000, 0x00000000 },
                { 0x00003f80, 0x00000000 }
	},

        /* Tribal */
        {
                {0x00000000, 0x000000ff},
                {0x00000000, 0x0000ff00},
                {0x00000000, 0x00ff0000},
                {0x00000000, 0xff000000},
        },

        /* Druidistic */
        {
                {0x00000000, 0x000000ff},
                {0x00000000, 0x0000ff00},
                {0x00000000, 0x00ff0000},
                {0x00000000, 0xff000000},
                {0x000000ff, 0x00000000},
        },

        /* Daemon */
        {
                {0x00000000, 0x000000ff},
                {0x00000000, 0x0000ff00},
                {0x00000000, 0x003f0000},
                {0x00000000, 0x0fc00000},
                {0x00000000, 0xf0000000},
        },

        /* Spirit */
        {
                {0x00000000, 0x000000ff},
                {0x00000000, 0x0000ff00},
                {0x00000000, 0x00ff0000},
                {0x00000000, 0xff000000},
        },
};


u32b Mrealm_choices[MAX_CLASS]=
{
/* Warrior */       (CH_NONE),
/* Mage */          (CH_MAGERY | CH_SHADOW | CH_NETHER | CH_MAGIC),
/* Priest */        (CH_VALARIN | CH_NETHER | CH_PRAYER),
/* Rogue */         (CH_MAGERY | CH_SHADOW | CH_NETHER | CH_ILLUSION | CH_SPIRIT | CH_SIGALDRY),
/* Ranger */        (CH_ILLUSION | CH_TRIBAL),
/* Paladin */       (CH_CRUSADE),
/* Warrior-Mage */  (CH_SIGALDRY),
/* Chaos Warrior */ (CH_CHAOS),
/* Monk */          (CH_VALARIN | CH_SPIRIT | CH_ILLUSION | CH_TRIBAL),
/* Mindcrafter */   (CH_NONE),
/* High Mage */     (CH_MAGERY | CH_SHADOW | CH_NETHER | CH_SIGALDRY | CH_SPIRIT | CH_ILLUSION),
/* Mimic       */   (CH_NONE),
/* BeastMaster */   (CH_TRIBAL),
/* Alchemist   */   (CH_NONE),
/* Symbiant    */   (CH_NONE),
/* Harper      */   (CH_NONE),
/* Power Mage  */   (CH_NONE),
/* Runecrafter */   (CH_NONE),
/* Possessor */     (CH_NONE),
/* Sorceror */      (CH_MAGERY | CH_SHADOW | CH_NETHER | CH_CHAOS | CH_SIGALDRY |
                     CH_ILLUSION | CH_SPIRIT),
/* Archer */        (CH_NONE),
/* Illusionist */   (CH_ILLUSION),
/* Druid */         (CH_DRUID),
/* Necromancer */   (CH_NETHER),
/* Unbeliever  */   (CH_NONE),
/* Daemonologist */ (CH_DAEMON),
/* Weaponmaster */  (CH_NONE),
/* Merchant  */     (CH_NONE),
};

u32b mrealm_choices[MAX_CLASS]=
{
/* Warrior */       (CH_NONE),
/* Mage */          (CH_SIGALDRY | CH_SPIRIT),
/* Priest */        (CH_CRUSADE | CH_ILLUSION),
/* Rogue */         (CH_NONE),
/* Ranger */        (CH_NONE),
/* Paladin */       (CH_NONE),
/* Warrior-Mage */  (CH_SPIRIT | CH_ILLUSION),
/* Chaos Warrior */ (CH_NONE),
/* Monk */          (CH_NONE),
/* Mindcrafter */   (CH_NONE),
/* High Mage */     (CH_NONE),
/* Mimic       */   (CH_NONE),
/* BeastMaster */   (CH_NONE),
/* Alchemist   */   (CH_NONE),
/* Symbiant    */   (CH_SYMBIOTIC),
/* Harper      */   (CH_MUSIC),
/* Power Mage  */   (CH_NONE),
/* Runecrafter */   (CH_NONE),
/* Possessor */     (CH_NONE),
/* Sorceror */      (CH_NONE),
/* Archer */        (CH_NONE),
/* Illusionist */   (CH_NONE),
/* Druid */         (CH_NONE),
/* Necromancer */   (CH_NONE),
/* Unbeliever  */   (CH_NONE),
/* Daemonologist */ (CH_CHAOS),
/* Weaponmaster */  (CH_NONE),
/* Merchant  */     (CH_NONE),
};

cptr realm_names [] =
{
	"no magic",
        "Valarin",
        "Magery",
        "Shadow",
	"Chaos",
        "Nether",
        "Crusade",
        "Sigaldry",
        "Symbiotic",
        "Music",
        "Magic",
        "Prayer",
        "Illusion",
        "Tribal",
        "Druidic",
	"Daemon",
        "Spirit",
};


/*
 * Names of the spells
 */
cptr spell_names[MAX_REALM][64][2] =
{
        /*** Nothing ***/
        {
                {NULL, NULL},
        },

        /*** Valarin Spells ***/
	{
                /* Common Valarin Spellbooks */
                {"Detect Evil", "Detects all evil monsters, even invisible ones."},
                {"Call Light", "Permanently lights up the area lit by your light source or a room."},
                {"Bless", "Bonus to fighting ability and armour class."},
                {"Remove Fear", "Removes any fear you currently feel."},
                {"Cure Light Wounds", "Reduces cuts and heals you a little."},
                {"Slow Poison", "Reduces the amount of poison in your system."},
                {"Reveal Doors and Stairs", "Detects all doors and stairs on the current panel."},
                {"Reveal Traps", "Detects hidden traps and doors on the current screen."},

                {"Spear of Light", "Create a ray of light in a given direction."},
                {"Remove Curse", "Removes normal curses."},
                {"Cure Serious Wounds", "Removes cuts and heals you."},
                {"Satisfy Hunger", "Magically feeds you."},
                {"Holy Chant", "Bonus to fighting ability and armour class."},
                {"Sense Surroundings", "Maps the local area."},
                {"Neutralize Poison", "Stops the effect of poison."},
                {"Resist Fire and Cold", "Provides temporary fire and cold resists."},

                {"Cure Critical Wounds", "Removes cuts and heals you."},
                {"Holy Orb", "Fires an orb of holy force that does extra damage to evil creatures."},
                {"Portal", "Teleports your randomly."},
                {"Sense Unseen", "Provides temporary see invisible"},
                {"Holy Blade", "Creates a temporary holy avenger."},
                {"Turn Undead", "Attempts to make an undead monster to turn and run."},
                {"Perception", "Gives knowledge about an item."},
                {"Holy Aura", "Temporary protects you form evil monsters and sustain your life force"},

                {"Heroism", "Temporary increase your combat abilities."},
                {"Word of Recall", "Recalls you to wilderness, or in the last visited dungeon."},
                {"Dispel Undead", "Harms all undead in line of sight."},
                {"Heal", "Removes cuts and heals you."},
                {"Banish", "Teleports away all monsters in line of sight."},
                {"Dispel Evil", "Harms all evil monsters in line of sight."},
                {"Holy Word", "Dispels evil, heals you and cures you from fear, poison, stunning and cuts."},

                {"Animal Taming", "Charm an animal."},
                {"Stone to Mud", "Digs a wall."},
                {"Sterilization", "Stops breeders from breeding."},
                {"Summon Animal", "Call animals to your help."},
                {"Haste Self", "Temporary speeds you."},
                {"Call Hounds", "Call hounds to your help."},
                {"Whirlwind Attack", "Attack every monsters around you."},

                {"Unbarring Ways", "Destroy doors and traps around you."},
                {"Sanctuary", "Tries to sleep all monsters around you."},
                {"Dispel Curse", "Removes some of the most powerful curses."},
                {"Tread Waters", "Lets you walk over water for a limited time."},
                {"Healing", "Greatly heals you and cure from nearly anything."},
                {"Bless Weapon", "Ask your god to bless a weapon."},
                {"Glyph of Warding", "Places a glyph on the floor that monsters cannot pass over until it is broken."},

                {"Invisibility", "Your god temporary hides you from the eyes of mortals."},
                {"Cure Mortal Wounds", "Removes cuts and heals you."},
                {"Mass Sleep", "Tries to sleep all monsters in line of sight."},
                {"Remembrance", "Restores your lost experience."},
                {"Restoration", "Restores your lost stats."},
                {"Mass Charm", "Tries to charm all monsters in line of sight."},
                {"Wraithform", "Turns you into a wraith being, letting you pass in walls."},

                {"Chain Lightning", "Fires beams of lightning all around you."},
                {"Disintegration", "Fires a ball of disintegration."},
                {"Blizzard", "Creates a sphere of coldness aimed at your opponents."},
                {"Whirlpool", "Creates a sphere of water aimed at your opponents."},
                {"Lightning Storm", "Creates a sphere of lightning aimed at your opponents."},
                {"Meteor Swarm", "Hurls meteors all around you."},

                {"Infusion", "Recharges magical items."},
                {"Alter Reality", "Regenerates the current level"},
                {"Restore Life", "Restores your lost experience and heals you."},
                {"Call Angel", "Call an angel to your help."},
                {"Earendil's Star", "Calls upon the light of the Silmaril to light the level and burn enemies."},
                {"Divinity", "Temporary grants you Vala-like powers."},
	},

        /*** Magery Spells ***/

	{
                /* Apprentice Handbook */
                {"Magic Missile", "The very basic of spells, this hurls a magical missile towards a target."},
                {"Phase Door", "This spell teleports you a short distance away from your current location."},
                {"Detect Monsters", "Detects monsters in your nearby surroundings."},
                {"Detect Traps", "Detects traps in your nearby surroundings."},
                {"Light Area", "Permanently lights an area around you."},
                {"Detect Doors/Stairs", "Detects doors and stairs in your nearby surroundings."},
                {"Confuse Monster", "This will confuse the target, causing it to stagger around."},
                {"Scan Object", "This spell will give you your feeling about the item."},

                /* Mystical Words */
                {"Noxious Cloud", "This spell causes an area poison effect centered around the target."},
                {"Teleport", "This spell teleports you a long distance away from your current location."},
                {"Beam of Light", "Creates a beam of light aimed at the target."},
                {"Sleep Monster", "This spell will cause the target to fall asleep instantly."},
                {"Lightning Bolt", "Creates a bolt of lightning aimed at the target."},
                {"Stone to Mud", "Causes a section of a wall to crumble to mud, creating a passage."},
                {"Frost Bolt", "Creates a bolt of ice aimed at the target."},
                {"Recharging", "Adds a number of charges to an item."},

                /* Arcane Chants */
                {"Ethereal Eye", "This spell will magically map your surroundings, and give you see invisible."},
                {"Fire Bolt", "Creates a bolt of fire aimed at the target."},
                {"Identification", "This spell identifies an item."},
                {"Typhoon Daze", "This spell creates a confusion area effect centered on you."},
                {"Time Distortion", "This spell slows all monsters in your immediate area."},
                {"Haste Self", "This spell makes you move faster for a short amount of time."},
                {"Elemental Blast", "This spell fires a fire, cold, acid and lightning bolt at the target."},
                {"Teleport Away", "This spell is will teleport the target away from you."},

                /* Locus of Force */
                {"Scan Monster", "This spell will give you some knowledge about the abilities of the monster."},
                {"Meditation", "This will give you extra SP and speed up SP regeneration, for a short time."},
                {"Gravitic Distortion", "This causes a area spell centered on you that slows down monsters."},
                {"Doppelganger", "This spell will create a unmoving mirror copy of yourself."},
                {"Firestorm", "This spell causes a large bonfire centered on the target."},
                {"Force Shield", "This spell increases your armor class for a short time."},
                {"Crippling Gaze", "This spell causes the target to be stunned and confused."},
                {"Collapse Ceiling", "This causes the ceiling to crumble around a targeted zone."},

                /* Powerful Sigils */
                {"Gravitic Beam", "This spell distorts space."},
                {"Sanctuary", "This spell surrounds you with stone walls."},
                {"Starburst", "This spell radiates light in all directions."},
                {"Stasis Cage", "This spell tries to sleep the target."},
                {"Elemental Shield", "This spell temporary protects you from the elements and poison."},
                {"Mirror Guard", "This spell creates a shield of mana that reflects projectiles."},
                {"Sunfire", "This spell calls upon Arien, goddess of sun, to burn your foes with holy light."},
                {"Force of the Elements", "This spell will fire powerful beams of elements."},

                /* Disruptive Forces */
                {"Earthquake", "This spell shakes the world around you."},
                {"Polymorph", "This spell change the physical form of a monster."},
                {"Wall of Stone", "This spell will create a wall."},
                {"Warp Space", "This spell distorts space around you."},
                {"Chaos Blast", "This spell creates an explosion of chaos around you."},
                {"Lava Flow", "This spell calls upon the fire of the underworld to create streams of lava."},
                {"Pyrrhic Blast", "This spell will create a ball of pure mana, at the cost of your life."},
                {"Word of Destruction", "This spell shakes the world around you."},

                /* Forces of the Mind */
                {"Radiate Fear", "This spell strikes fear in the heart of your foes."},
                {"Probing", "This spell informs you about monsters life."},
                {"Forceful Gaze", "This spell will stun a monster."},
                {"Recharging II", "This spell can recharge a magic item."},
                {"Transmutation", "This spell turns objects into gold."},
                {"Self-Scan", "This spell reveals a lot about yourself."},
                {"Identify II", "This spell fully identify an item."},
                {"Clairvoyance", "This spell maps the whole level for you."},

                /* Power of Ancient Sorcerors */
                {"Volcano Flow", "This spell creates a terrific volcanic explosion with a lava flow."},
                {"Plasma Eruption", "This spell surrounds you with pure plasma."},
                {"Annihilate", "This spell fires a powerful missile."},
                {"Oblivion Blast", "This spell removes your foes from existence."},
                {"Mana Spin", "This spell throws bolts of mana all around you."},
                {"Tidal Wave", "This spell calls upon Ulmo, god of water, to create a blast of water."},
                {"Anarchy Force", "This spell creates an Armageddon of chaos."},
                {"Mana Strike", "This ultimate spell will concentrate ambient mana into a bolt."},
	},

        /*** Shadow Spellbooks ***/
	{
                /* Inner Void */
                {"Dark Hand", "A bolt of living darkness blasts your enemy"},
                {"Sense the Unseen", "You are able to sense unseen monsters nearby"},
                {"Dark Light", "A shadowy radiance bathes your surroundings"},
                {"Armor of Void", "A dim protective aura surrounds you"},
                {"Fear of the Shadows", "Your aspect takes on a dark and fearsome cast"},
                {"Sense Shadows", "You are able to sense unseen objects nearby"},
                {"Shadow Spikes", "Tangible darkness flies from your outstretched hand"},
                {"Shadow hiding", "The darkness bends around your form"},

                /* Lurkings of the Night */
                {"Illusory Ball", "Spinning motes of darkness baffle your foes"},
                {"Darkness Storm", "Dark energy explodes in the midst of your opponents"},
                {"Energies Channeling", "Your command of the shadows lends you knowledge of your surroundings"},
                {"Immaterial Beings", "The faded image of an ancestor rallies to your cause"},
                {"Shadow Enlightenment", "You obtain knowledge through contemplation of the night"},
                {"Dissolve Matter", "Obscure energies rend the very fabric of your foes"},
                {"Invoke the Night", "The shadows leech energy from your foes, inducing slumber"},
                {"Resist Light & Dark", "You feel less vulnerable to the components of shadow"},

                /* Beings of Darkness */
                {"Teleportation", "You can move from place to place via the shadows"},
                {"Absorb Light", "You soak up the surrounding light and store it as magical energy"},
                {"Shadow Regeneration", "You draw sustenance from the night"},
                {"Steal Shadow", "All things must have a shadow, and without it, they vanish!"},
                {"Storm in the Shadows", "Unseen energies assault your foes"},
                {"Shadow of Life", "You infuse your foes with darkness so that they may serve your ends"},
                {"Shadow of Dragon", "The shadows coalesce into a dragon at your beckon call"},
                {"Banish Shadows", "Reality splits, and your foes are rent from within"},

                /* Material Shadow */
                {"Feelings of Darkness", "The weaknesses of your enemies are made known to you"},
                {"Dark Bolt", "A massive bolt of living darkness blasts your enemy"},
                {"Shadow Orb", "A throbbing pool of corruption engulfs your foes"},
                {"Shadow of Undead", "The haggard and ominous form of an ancestor rallies to your cause"},
                {"Shadow Rain", "An unnatural storm rages about, destroying all in its path"},
                {"Mirror of Shadow", "Shadows gather into a reflective shield around you"},
                {"Comet from the Void", "A gigantic blob of nothingness swallows your foes"},
                {"Call the Void", "Mountains could be leveled in the blast as Shadows collide"},

                /* Aiding Shades */
                {"Examine Shadow", "Everything has a shadow which can reveal much to you"},
                {"*Shadow Enlightenment*", "You obtain complete knowledge through contemplation of the night"},
                {"Remove Curse", "Foul magics leech away into the night"},
                {"*Remove Curse*", "The foulest magics leech away into the night"},
                {"Shadow Form", "You are transformed as into the shadows themselves"},

                /* Morgoth's Space-Time Warpings */
                {"Shadow Portal", "You jump through a shadowy portal to a nearby location"},
                {"Warping Rift", "You can cause gravity to become unstable in a sphere around you"},
                {"Void Jumping", "You travel the shadow path out of the dungeon"},
                {"Shadow Distortion", "You can cause gravity to become unstable in a sphere around your foes"},
                {"Between Jump", "You create a connecting tunnel between two places"},
                {"Between Maze", "You surround yourself with connecting tunnels between many places"},

                /* Murazor Tome of Conjuring & Dispelling */
                {"Dispel Living", "Darkness sucks the life from your foes"},
                {"Conjure Dragons", "Out of the darkness you call for the protection of a dragon"},
                {"Dispel Undead", "Darkness is sucked out of your foes"},
                {"Conjure Undead", "Out of the darkness you call a creature of the dark"},
                {"Dispel Demons", "Shadows seep out of the hearts of demons"},
                {"Conjure Demons", "Stepping from the shadows is a demonic nightmare"},

                /* Channeling the Void */
                {"Recharge I", "You imbue items with the power of the dark"},
                {"Sphere of Void", "Everything around you dissolves into shadow"},
                {"Shadow Alteration", "Shadows ripple and change the fabric of reality"},
                {"Recharge II", "You imbue items with the power of true darkness"},
                {"Concentrate Light", "You concentrate the light around you into a powerful ball of energy"},
                {"Shield of Darkness", "You transform darkness into a mighty shield against harm"},
                {"Tunnel of Shadow", "You follow the shadows to another level"},

                /* Sauron's Forgotten Tome */
                {"Genocide", "Summons the power of the dark to rid the world of your foes"},
                {"Enslave Undead", "Minions of shadow around you join your cause"},
                {"Create Minor Ring", "Shadows twine around the ring and imbue it with their power"},
                {"Control the Three Rings", "Harness the powers of the rings to control your own shadows"},
                {"Protection from the Undead", "Prevent creatures of shadow from harming you"},
                {"Mass Genocide", "Summons the darkness to rid you of the foes surrounding you"},
                {"Hellfire", "Summons fires of hell from the dark to ravage your foes"},
                {"Control The Ring", "Releases the dark force of the One Ring in a powerful explosion!"},
	},

	/*** Chaos Spells ***/

	{
		/* Common Chaos Spellbooks */
                {"Magic Missile", "This spell creates a magic missile to strike your foes."},
                {"Trap / Door Destruction", "This spell destroys all traps and doors near you."},
                {"Flash of Light", "This spell lights up the room."},
                {"Touch of Confusion", "This spell confuses the next monster you hit in melee."},
                {"Mana Burst", "This spell release a ball of mana to crush your foes."},
                {"Fire Bolt", "This spell invokes the fire element in a bolt."},
                {"Fist of Force", "This spell projects a bolt of force to crush your foes."},
                {"Teleport Self", "This spell allows you to teleport away."},

                {"Wonder", "It will do random things."},
                {"Chaos Bolt", "Harnesses chaotic energies into a powerful bolt."},
                {"Sonic Boom", "Unleashes a sonic wave around you."},
                {"Doom Bolt", "Creates a malevolent projectile."},
                {"Fire Ball", "Releases a ball of fire to engulf your foes."},
                {"Teleport Other", "It will teleport monsters away."},
                {"Word of Destruction", "Shakes the earth, causing damage to the dungeon around you."},
                {"Invoke Chaos", "Unleashes the primal forces of chaos in a ball around your foes."},

		/* Rare Chaos Spellbooks */
                {"Polymorph Other", "Polymorphs a monster into a different one."},
                {"Chain Lightning", "Fires beams of lightning in all directions."},
                {"Arcane Binding", "Absorb ambient mana to recharge a magical item."},
                {"Disintegrate", "Projects a ball of disintegration force."},
                {"Alter Reality", "Alters the world to recreate the current level."},
                {"Polymorph Self", "Polymorphs you into another form."},
                {"Chaos Branding", "Brands a weapon with the Mark of Chaos."},
                {"Summon Demon", "Summons demonic servants to your aid."},

                {"Beam of Gravity", "Creates a beam that warps gravity to dispatch your foes."},
                {"Meteor Swarm", "Hurls meteors down from the sky."},
                {"Flame Strike", "Creates a huge fireball."},
                {"Call Chaos", "Creates a powerful random attack."},
                {"Magic Rocket", "Concentrates magic into an explosive ball."},
                {"Mana Storm", "Disrupt the magic continuum and unleashes its power on your foes."},
                {"Breathe Chaos", "Lets you breathe a ball of chaotic energy."},
                {"Call the Void", "It will do random powerful things."},
	},

        /*** Nether Spells ***/

	{
                /* Nether Openings */
                {"Detect Unlife", "Detects all non-living 'beings'."},
                {"Detect Evil", "Detects all evil beings."},
                {"Horrify", "Scares and stuns a foe."},
                {"Sleep I", "Sends your foe to sleep."},
                {"Reveal Invisible", "Allows you to see invisible beings for a short time."},
                {"Lethargy", "Slows down your foe."},
                {"Resist Poison", "Allows you to temporarily resist the effects of poison."},
                {"Stinking Cloud", "Creates a weak cloud of poison."},

                /* Unholy Blessings */
                {"Resist Cold", "Temporarily allows you to resist the effects of cold."},
                {"Black Dart", "Creates a magical bolt."},
                {"Invisibility", "Temporarily makes you invisible to all eyes."},
                {"Spear of Phantasms", "Fires a frightening illusion beam to scare monsters."},
                {"Levitation", "Allows you to levitate for a short time."},
                {"Sleep II", "Causes all monsters near you to fall asleep."},
                {"Nether Bolt", "Creates a bolt of nether, sapping the soul of your foe."},
                {"Enslave Undead", "Tries to enslave an undead monster to aid you."},

                /* Necromantic Incantations */
                {"Icy Touch", "Harnesses the icy coldness of the undead in a chilling bolt."},
                {"Bloodlust", "Sends you berserk for a short time."},
                {"Werewolf Form", "Allows you to take on the form of a Werewolf."},
                {"Draining Touch", "Steals your foe's life-force to strengthen your own."},
                {"Turn Undead", "Causes Undead creatures to flee from you."},
                {"Sleep III", "All visible monsters fall asleep."},
                {"Call Undead", "Calls mighty undead creatures to your aid."},
                {"Open Chasm", "Opens a dark pit under your foe."},

                /* Curses of Angmar */
                {"Dark Bolt", "Gathers the forces of the night into a powerful bolt."},
                {"Vampiric Form", "Allows you to take on the form of a Vampire."},
                {"Raise Dead", "Raises an undead servant from a dead monster."},
                {"Spear of Darkness", "Gathers the forces of the night into a beam of unlight."},
                {"Banish", "Banishes all monsters in line of sight."},
                {"Dispel Good", "Damages all good monsters in line of sight."},
                {"Genocide", "Removes from existence all members of the same race on that level."},

                /* Eye of Sauron */
                {"Detect Monsters", "Detects all nearby monsters."},
                {"Hypnotic Gaze", "Tries to charm a monster."},
                {"Piercing Gaze", "Reveals the level around you."},
                {"Sense Magic", "Senses the strength of the magic in an item."},
                {"Detection", "Detects all nearby objects, monsters, and special terrain features."},
                {"Telepathy", "Allows you to see into the minds of nearby monsters."},
                {"Clairvoyance", "Fully maps the current level."},

                /* Flame of Udun */
                {"Resist Fire", "Allows you to resist heat for a short time."},
                {"Fiery Aura", "Surrounds you with a wall of fire."},
                {"Spear of Fire", "Creates a mighty spear of flame."},
                {"Fireball", "Unleashes a powerful fireball on your foes."},
                {"Call Demon", "Calls a mighty demonic servant to your aid."},
                {"Flame of Udun", "Allows you to take the form of a Balrog."},
                {"Hellfire", "Unleashes a powerful wave of hellfire, burning *everything* it engulfs."},

                /* Corruptions of Melkor */
                {"Confuse", "Fires a confusing bolt of energy at a monster."},
                {"Thralldom", "Attempts to enslave a monster to your will."},
                {"Polymorph Other", "Polymorphs a monster into a different form."},
                {"Polymorph Self", "Polymorphs you into a different form."},
                {"Plague", "Poisons all monsters in line of sight."},
                {"Ravage Soul", "Gathers the powers of the nether realm and releases a large explosion."},

                /* Crescent of Morgul */
                {"Absorb Light", "Absorbs the light surrounding you to restore your life-force."},
                {"Drain Magic", "Drains the magic from objects to restore your own."},
                {"Spear of Death", "Casts a beam of nether energy at your foes."},
                {"Restore Life", "Restores your stolen experience."},
                {"Nightfall", "Harnesses the powers of the night into a powerful ball of darkness."},
                {"Blood Curse", "Creates a bolt whose damage depends of your mana."},
                {"Wraithworld", "Allows you to take on the form of a Wraith."},

                /* Morgoth's Ring */
                {"Invoke Spirits", "Casts a random nasty effect."},
                {"Vampiric Branding", "Brands a weapon with the Mark of the Vampires."},
                {"Dispel Life", "Damages all living beings in line of sight."},
                {"Word of Destruction", "Shatters the level around you."},
                {"Summon Greater Undead", "Summons a powerful undead servant to your aid."},
                {"Mass Genocide", "Eradicates all monsters around you."},
	},

        /* Crusade Spellbooks */
	{
                /* Rites of Initiation */
                {"Boldness", "Makes you forget your fears."},
                {"Blessing", "Provides temporary protection and assault power."},
                {"Light Area", "Lights up an area or room around you."},
                {"See Invisible", "Allows you to see invisible monsters."},
                {"Touch of Confusion", "Tries to confuse the next monster you hit."},
                {"Invoke Fear", "Tries to scare a monster."},
                {"Resist Fire", "Provides temporary resistance to fire."},
                {"Resist Cold", "Provides temporary resistance to cold."},

                /* Ways of War */
                {"Spear of Light", "Creates a line of pure, divine light."},
                {"Heroism", "Provides temporary fighting bonuses."},
                {"Holy Chant", "Provides temporary protection and assault power."},
                {"Sense Foes", "Detects monsters around you."},
                {"Jam Doors", "Allows you to close doors at a distance."},
                {"Cure Wounds & Poison", "Cures your cuts and cleans out any poison."},
                {"Wolvish Hunger", "It temporarily morphs you to a wolf."},
                {"Berserker Rage", "It temporarily turns you into a fighting machine."},

                /* Divine Retribution */
                {"Vision", "Allows you to sense the world around you."},
                {"Fiery Aura", "It temporarily surrounds you with a flame shield."},
                {"Holy Aura", "It temporarily surrounds you with a divine shield."},
                {"Mend Wounds", "It heals you and cures your cuts."},
                {"Haste Self", "It temporarily increases your speed."},
                {"Thunder's Wrath", "It projects sound, force and confusion to your foes."},
                {"Counterstrike", "Reflects part of the damage done to you back to your foes."},
                {"Whirlwind Attack", "Allows you to spin around and attack all monsters near you."},

                /* Essence of Fury */
                {"Call Thunder", "Projects waves of sound onto your foes."},
                {"Mass Charm", "Tries to charm all monsters in line of sight."},
                {"True Strike", "It temporarily greatly improves your fighting power."},
                {"Deadly Blow", "It allows your next few blows to be critical."},
                {"Healing", "It heals you and cures your wounds."},
                {"Dragon's Wrath", "It temporarily turns you into a dragon."},
                {"Summon Angel", "It calls an angel to your help."},
                {"Wave of Power", "It allows you to project a melee attack to a distant monster."},
	},

        /* Sigaldry Spellbooks */

	{
                /* Novice Crafts */
                {"Detect Monsters", "It will detect monsters near you."},
                {"Wizard Lock", "It will magically lock a door."},
                {"Illuminate", "It will light up a room."},
                {"Locate Doors/Stairs", "It will detect stairs and doors near you."},
                {"Locate Traps", "It will detect traps near you."},
                {"Disruption I", "It will create a damaging, stunning or confusing bolt."},
                {"Blink", "It will teleport you a few squares away."},
                {"Detect Treasure", "It will detect treasures around you."},

                /* Arcane Channels */
                {"Detect Objects", "It will detect objects around you."},
                {"Warding", "It will create a wall of force around you, increasing your shielding."},
                {"Trap/Door Destruction", "It will destroy traps and doors near you."},
                {"Sleep I", "It will put a nearby monster to sleep."},
                {"Preservation", "It will make a corpse last longer."},
                {"Confuse", "It will confuse a monster."},
                {"Magic Aura", "Increases your light radius and lets you resist life draining."},
                {"Appraise Item", "Senses the strength of the magic of an item."},

                /* Sigils of Wizardry */
                {"Resist Fire", "It will temporarily protect you from fire."},
                {"Resist Cold", "It will temporarily protect you from cold."},
                {"Finger of Pain", "It will damage a monster without the need to travel to it."},
                {"Recharge I", "It will harness magical energies to recharge an item."},
                {"Magic Mapping", "It reveals the level around you."},
                {"Sleep II", "It will try to put all monsters near you asleep."},
                {"Teleport Self", "It will teleport you away."},
                {"Identify", "It will identify an object."},

                /* Mana Focus */
                {"True Strike", "It will temporarily help you hit your foes."},
                {"Between Gate", "Opens a between gate to let you travel from one spot to another."},
                {"Disruption II", "Creates a damaging, stunning or confusing ball of energy."},
                {"Drain Magic", "Replenishes your magic by draining the magic from an item."},
                {"Scribe Scroll", "Creates a spell scroll, containing a magic spell."},
                {"Infuse Amulet", "Creates a random amulet."},
                {"Glyph of Warding", "Wards the ground under you, preventing monsters from going there."},
                {"Implosion", "Creates a powerful implosion."},
        },

        /* Symbiotic Spellbooks */

	{
                /* Common Symbiotic Spellbooks */
                {"Minor symbiotic healing", ""},
                {"Tangled Creepers", ""},
                {"Vampiric healing", ""},
                {"Life transfer", ""},
                {"Satisfy Hunger", ""},
                {"Minor symbiotic powers", ""},
                {"Summon never-moving pet", ""},
                {"", ""},

                {"", ""},
                {"", ""},
                {"", ""},
                {"", ""},
                {"", ""},
                {"", ""},
                {"", ""},
                {"", ""},

                /* Rare Symbiotic Spellbooks */
                {"Mana healing", ""},
                {"Summon never-moving pets", ""},
                {"Major symbiotic healing", ""},
                {"Healing", ""},
                {"Major Symbiotic powers", ""},
                {"Use Enemy's Powers", ""},
                {"", ""},
                {"", ""},


                {"", ""},
                {"", ""},
                {"", ""},
                {"", ""},
                {"", ""},
                {"", ""},
                {"", ""},
                {"", ""},
	},
        {
                /******* Apprentice Handbook *******/
                {"Song of Holding", "Slows down all monsters listening the song."},
                {"Stop singing", "Stops your current song"},
                {"Horrible Note", "You scream a horrible note."},
                {"Stun Pattern", "Stuns all monsters listening the song."},
                {"Flow of Life", "Heals you as long as you sing."},
                {"Clairaudience", "Provides telepathy as long as you sing."},
                {"Song of the Sun", "Provides light as long as you sing."},
                {"Heroic Ballad", "Increases your fighting abilities as long as you sing."},

                /******* Minstrel's Music *******/
                {"Song of Awareness", "Detect magic items as long as you sing."},
                {"Song of Lore", "Identify objects near you on the ground as long as you sing."},
                {"Spatial Transfer", "Keeps on teleporting you as long as you sing."},
                {"Doomcall", "This note will wreck your foes."},
                {"Illusion Pattern", "Tries to confuse all monsters listening the song."},
                {"Wrecking Pattern", "Destroy walls around you as long as you sing."},
                {"Finrod's Resistance", "Provides resistances to the elements as long as you sing."},
                {"Hobbit Melodies", "Increases your speed as long as you sing."},

                /******* Harps of Rivendell *******/
                {"Song of Probing", "Learn everything about a monster."},
                {"World Contortion", "Teleports away all your foes."},
                {"Fellowship Chant", "Fire of beam of calming sounds, that can charm monsters..."},
                {"Song of the Tempest", "Creates a beam of pure sound."},
                {"Telchar's Forge", "Imbues the power of the sound into a weapon."},
                {"Akallabeth", "All monsters that hear the song get hit by pure sound."},
                {"Ambarkanta", "As you sing, the level is reshaped."},
                {"Lay of Gil-Galad", "Summons allies to your help."},

                /******* Lays of Beleriand *******/
                {"Felagund's Disguise", "Renders you invisible as long as you sing."},
                {"Wizardry of Sauron", "Fires a powerful bolt of sound."},
                {"The Voice of Saruman", "Charms all monsters that hear the song."},
                {"Ainulindale", "Provides Ainur-like powers as long as you sing."},
                {"The Horns of Ylmir", "Destroys the area around you."},
                {"Fingolfin's Challenge", "Gives you invulnerability as long as you sing."},
                {"Firiel's Song", "Converts evil monsters into good, disembodied spirits."},
                {"Luthien's Mourning", "Turns you into a wraith being as long as you sing."},

        },

	/*** Mage Spells ***/
	{
		/* Magic for Beginners (sval 0) */
                {"Magic Missile", ""},
                {"Detect Monsters", ""},
                {"Phase Door", ""},
                {"Light Area", ""},
                {"Treasure Detection", ""},
                {"Cure Light Wounds", ""},
                {"Object Detection", ""},
                {"Find Hidden Traps/Doors", ""},
                {"Stinking Cloud", ""},

		/* Conjurings and Tricks (sval 1) */
                {"Confuse Monster", ""},
                {"Lightning Bolt", ""},
                {"Trap/Door Destruction", ""},
                {"Sleep I", ""},
                {"Cure Poison", ""},
                {"Teleport Self", ""},
                {"Spear of Light", ""},
                {"Frost Bolt", ""},
                {"Turn Stone to Mud", ""},

		/* Incantations and Illusions (sval 2) */
                {"Satisfy Hunger", ""},
                {"Recharge Item I", ""},
                {"Sleep II", ""},
                {"Polymorph Other", ""},
                {"Identify", ""},
                {"Sleep III", ""},
                {"Fire Bolt", ""},
                {"Slow Monster", ""},

		/* Sorcery and Evocations (sval 3) */
                {"Frost Ball", ""},
                {"Recharge Item II", ""},
                {"Teleport Other", ""},
                {"Haste Self", ""},
                {"Fire Ball", ""},
                {"Word of Destruction", ""},
                {"Genocide", ""},

		/* Mordenkainen's Escapes (sval 5) */
                {"Door Creation", ""},
                {"Stair Creation", ""},
                {"Teleport Level", ""},
                {"Earthquake", ""},
                {"Word of Recall", ""},

		/* Raal's Tome of Destruction (sval 8) */
                {"Acid Bolt", ""},
                {"Cloud Kill", ""},
                {"Acid Ball", ""},
                {"Ice Storm", ""},
                {"Meteor Swarm", ""},
                {"Mana Storm", ""},

		/* Kelek's Grimoire of Power (sval 6) */
                {"Detect Evil", ""},
                {"Detect Enchantment", ""},
                {"Recharge Item III", ""},
                {"Genocide", ""},
                {"Mass Genocide", ""},

		/* Resistance of Scarabtarices (sval 4) */
                {"Resist Fire", ""},
                {"Resist Cold", ""},
                {"Resist Acid", ""},
                {"Resist Poison", ""},
                {"Resistance", ""},

		/* Tenser's transformations... (sval 7) */
                {"Heroism", ""},
                {"Shield", ""},
                {"Berserker", ""},
                {"Essence of Speed", ""},
                {"Globe of Invulnerability", ""},

                {"(blank)", ""},
                {"(blank)", ""},
                {"(blank)", ""},
                {"(blank)", ""},
                {"(blank)", ""},
	},


	/*** Priest Spells ***/

	{
		/* Beginners Handbook (sval 0) */
                {"Detect Evil", ""},
                {"Cure Light Wounds", ""},
                {"Bless", ""},
                {"Remove Fear", ""},
                {"Call Light", ""},
                {"Find Traps", ""},
                {"Detect Doors/Stairs", ""},
                {"Slow Poison", ""},

		/* Words of Wisdom (sval 1) */
                {"Scare Monster", ""},
                {"Portal", ""},
                {"Cure Serious Wounds", ""},
                {"Chant", ""},
                {"Sanctuary", ""},
                {"Satisfy Hunger", ""},
                {"Remove Curse", ""},
                {"Resist Heat and Cold", ""},

		/* Chants and Blessings (sval 2) */
                {"Neutralize Poison", ""},
                {"Orb of Draining", ""},
                {"Cure Critical Wounds", ""},
                {"Sense Invisible", ""},
                {"Protection from Evil", ""},
                {"Earthquake", ""},
                {"Sense Surroundings", ""},
                {"Cure Mortal Wounds", ""},
                {"Turn Undead", ""},

		/* Exorcism and Dispelling (sval 3) */
                {"Prayer", ""},
                {"Dispel Undead", ""},
                {"Heal", ""},
                {"Dispel Evil", ""},
                {"Glyph of Warding", ""},
                {"Holy Word", ""},

		/* Godly Insights... (sval 5) */
                {"Detect Monsters", ""},
                {"Detection", ""},
                {"Perception", ""},
                {"Probing", ""},
                {"Clairvoyance", ""},

		/* Purifications and Healing (sval 6) */
                {"Cure Serious Wounds", ""},
                {"Cure Mortal Wounds", ""},
                {"Healing", ""},
                {"Restoration", ""},
                {"Remembrance", ""},

		/* Wrath of God (sval 8) */
                {"Dispel Undead", ""},
                {"Dispel Evil", ""},
                {"Banishment", ""},
                {"Word of Destruction", ""},
                {"Annihilation", ""},

		/* Holy Infusions (sval 7) */
                {"Unbarring Ways", ""},
                {"Recharging", ""},
                {"Dispel Curse", ""},
                {"Enchant Weapon", ""},
                {"Enchant Armour", ""},
                {"Elemental Brand", ""},

		/* Ethereal openings (sval 4) */
                {"Blink", ""},
                {"Teleport Self", ""},
                {"Teleport Other", ""},
                {"Teleport Level", ""},
                {"Word of Recall", ""},
                {"Alter Reality", ""},

                {"(blank)", ""},
                {"(blank)", ""},
                {"(blank)", ""},
                {"(blank)", ""},
                {"(blank)", ""},
        },

	/*** Illusionist Spells ***/
	/* Added by -KMW- */

	{
		/* Illusions for Beginners (sval 0) */
                {"Confusion Bolt", "Casts an energy bolt that confuses the monster it hits."},
                {"Detect Monsters", "Detects visible monsters within an area around you."},
                {"Phase Door", "Teleports you to a nearby location."},
                {"Light Area", "Lights up the area around you."},
                {"Treasure Detection", "Locates treasures in the area around you."},
                {"Fear", "Causes a monster (or monsters) to become frightened of you."},
                {"Object Detection", "Locates objects in the area around you."},
                {"Find Hidden Traps/Doors", "Locates traps, doors and stairs in the area around you."},
                {"Stinking Cloud", "Casts a cloud of poisonous gas at your foes."},

		/* Tricks and Visions (sval 1) */
                {"Infravision", "Temporarily increases your ability to see warm-blooded lifeforms."},
                {"Sleep", "Causes a targetted monster to fall asleep."},
                {"Trap/Door Destruction", "Destroys all traps and doors next to the caster."},
                {"Fog Cloud", "Casts a cloud of poison at your foes."},
                {"Cure Poison", "Cures the caster of the effects of poison."},
                {"Satisfy Hunger", "Makes the caster feel fully satisfied."},
                {"Shadow Door", "Creates doors around the caster."},
                {"Shadow Monster", "Summons an illusionary beast that rushes to attack, then disappears."},
                {"Turn Stone to Mud", "Causes stone to dissolve."},

		/* Phantasms and Illusions (sval 2) */
                {"Detect Invisible", "Detects the presence of invisible things."},
                {"Recharge Item", "Increases the charge within a magical item."},
                {"Brand Ammo", "Fire/Frost brands a pile of ammunition."},
                {"Spear of Light", "Casts a beam of light."},
                {"Chaos", "Unleashes chaotic energy in a powerful explosion."},
                {"Mental Barrier", "Creates a protective barrier around your intellect."},
                {"True Sight", "Empowers you with a vision of the area around you."},
                {"Slow Monster", "Reduces the speed of a nearby monster."},

		/* Shadows and Prisms (sval 3) */
                {"Shadow Ball", "Casts a ball of shadow to engulf your foes."},
                {"Bolt of Darkness", "Casts a malevolent bolt of darkness at your foe."},
                {"Shadow Form", "Alters the caster's form to that of a shadow."},
                {"Haste Self", "Increases the speed of the caster for a limited time."},
                {"Prismatic Wall", "Creates a wall of force at a point that no monster may pass."},
                {"Prismatic Spray", "A ball of light sprays out from your fingertips."},
                {"Chromatic Shield", "A shield of corruscating light surrounds your form."},

		/* Knowledge of Kenault (sval 5) */
                {"Wizard Lock", "Magically spikes a door to prevent anyone openning it."},
                {"Bedlam", "Calls a ball of chaos down upon your foes."},
                {"Word of Recall", "Teleports you between the dungeon and the town."},
                {"Detect Enchantment", "Detects objects that contain enchantments."},
                {"Probing", "Probes monsters to discover their abilities."},
                {"Sunfire", "Releases the energy of a miniature sun upon your foes."},

		/* Bigby's Handbook (sval 8) */
                {"Bigby's Interposing Hand", "Surrounds the caster with squares that may not be entered by a monster."},
                {"Bigby's Phantom Hand", "Creates a line of phantasms that attack and confuse the enemy then disappear."},
                {"Bigby's Forceful Hand", "Creates a line of shadowy monsters that attack the enemy then disappear."},
                {"Bigby's Grasping Hand", "Slows a line of monsters."},
                {"Bigby's Clenched Fist", "A beam of force projects from your clenched fist."},
                {"Bigby's Crushing Hand", "A beam of crushing gravity projects from the caster."},
                {"Force Blast", "A ball of pure force explodes upon your foes."},

		/* Otiluke's Spheres (sval 6) */
                {"Sphere of Light", "Casts a sphere of light at your foes."},
                {"Sphere of Darkness", "Casts a sphere of darkness at your foes."},
                {"Sphere of Confusion", "Casts a sphere of confusion at your foes."},
                {"Sphere of Chaos", "Casts a sphere of chaotic energy at your foes."},
                {"Sphere of Sound", "Casts a sphere of sound at your foes."},
                {"Explosion", "Creates a powerful explosion of shrapnel."},

		/* Serten's Immunities (sval 4) */
                {"Remove Fear", "Allows the caster to regain their failing courage."},
                {"Resist Light & Dark", "Protects the caster from the ravages of light and darkness."},
                {"Resist Poison", "Protects the caster from the ravages of poison."},
                {"Resist Chaos & Confusion", "Protects the caster from the ravages of Chaos and Confusion."},
                {"Resist Sound & Shards", "Protects the caster from the ravages of Sound and Shards."},
                {"Resist Nexus", "Protects the caster from the ravages of Nexus."},

		/* Boccob's Book of Shadows (sval 7) */
                {"Invisibility", "Makes the caster invisible."},
                {"Shadow Monsters", "Invokes a group of shadowy monsters who attack, then vanish."},
                {"Shadow Ball", "Creates a ball of darkness to ravage your foes."},
                {"Shadow Sacrifices", "Sacrifices your lifeforce to increase your magic."},
                {"Shadow Gate", "Opens a gate to another portion of the level."},
                {"Summon Shadows", "Summons a spirit to your aid."},
	},

        /* Tribal */
        {
                {"Slumber", "Sends a monster or group of monsters to sleep."},
                {"Lightning Bolt", "Casts a bolt of lightning."},
                {"Bewilder", "Confuses a monster of group of monsters."},
                {"Song of Morning", "Creates a miniature sun-rise over a group of monsters."},
                {"Recuperation", "Heals the caster"},
                {"Meditate", "Protects the caster while they heal their mind."},
                {"Wolf Spirit", "Allows the caster to take on the form of a Wolf."},
                {"Dress Wounds", "Heals the caster of wounds and cuts."},

                {"Grow Berries", "Feeds the caster."},
                {"Sense Presence", "Detects monsters around the caster."},
                {"Punishment", "Releases a ball of magical energy, centered on the caster."},
                {"Life Drain", "Physically drains the caster to release a targetted ball of magic."},
                {"Beetle Spirit", "Allows the caster to take the form of an insect."},
                {"Call Nature", "Summons ants and spiders to the aid of the caster."},
                {"Bird Spirit", "Allows the caster to take the form of a sparrow."},
                {"Winter's Fury", "Releases a pair of balls of freezing cold."},

                {"Stun", "Sleeps, confuses and slows all monsters next to the caster."},
                {"Remove Evil", "Removes evil magics from items worn by the caster."},
                {"Destroy Traps", "Destroys traps adjacent to the caster."},
                {"Lore", "Identifies the history of an object."},
                {"Invoked Destruction", "Creates a fireball centered on the caster."},
                {"Ruins", "Creates a ball of destruction centered on the caster."},
                {"Fright", "Attempts to frighten all nearby monsters."},
                {"Winds of Displacement", "High winds scatter your enemies about the level."},

                {"Death Chant", "Physically drains the caster to release 2 powerful balls of magic."},
                {"Storm's Fury", "Releases a lightning storm."},
                {"Call Hydras", "Summons Hydras to your aid."},
                {"Lifeblood", "Uses caster's experience to heal and restore their body."},
                {"Invoke Winds", "High winds scatter your enemies."},
                {"Dispel Evil", "Damages all evil creatures around you."},
                {"Mystic Forces", "Releases mystical forces in a powerful attack!"},
                {"", ""},
        },

        /* Druidistic */
        {
                /* Elemental Stone[Earth] */
                {"Tunnel", ""},
                {"Canalize Mana", ""},
                {"Acid Bolt", ""},
                {"Mana Path", ""},
                {"Forest Generation", ""},
                {"Druidic Acid Beam", ""},
                {"Raise Mountains", ""},
                {"Stone Skin", ""},

                /* Elemental Stone[Fire] */
                {"Infravision", ""},
                {"Fire Bolt", ""},
                {"Fire Ball", ""},
                {"Uncover Traps", ""},
                {"Fire Beam", ""},
                {"Druidic Fire Bolt", ""},
                {"Druidic Fire Beam", ""},
                {"Create Lava", ""},

                /* Elemental Stone[Air] */
                {"Winds of Mana", ""},
                {"Summon Air Elemental", ""},
                {"Whispers from Afar", ""},
                {"The Winds of Manwe", ""},
                {"Bird View", ""},
                {"*Whispers from Afar*", ""},
                {"Windy Speed", ""},
                {"The Thunders of Manwe", ""},

                /* Elemental Stone[Water] */
                {"Summon Aquatic Golems", ""},
                {"Walk over Water", ""},
                {"Flood", ""},
                {"Summon Water Elementals", ""},
                {"Purification", ""},
                {"Call of the Deep", ""},
                {"Tidal Wave", ""},
                {"Flood Level", ""},

                /* Elemental Stone[Mana] */
                {"Glyph of Warding", ""},
                {"Orb of Mana", ""},
                {"Gather Mana", ""},
                {"Mirror of Mana", ""},
                {"Activate Rune of Mana", ""},
                {"Combine the 5 Elements", ""},
                {"Shield of Mana", ""},
                {"Drain Level Mana", ""},
        },

	/* Demon -SCSCSC- */
	{
		/* Dark Incantations */
                {"Detect Good", "Detects all good beings near you."},
                {"Phase Door", "Teleport you a few squares."},
                {"Resist Fire", "Makes you resistant to fire for a short duration."},
                {"Unearthly Blessing", "Temporarily protects you and increases your fighting accuracy."},
                {"Steal Thoughts", "Attempts to confuse monsters."},
                {"Demon Eyes", "Allows you to detect all monsters for a short duration."},
                {"Mend Flesh", "Heals you."},
                {"Vision", "Reveals the level around you."},

		/* Immortal Rituals */
                {"Detect Angels and Demons", "Detects angels and demons near you."},
                {"Protection from Good", "Deflects attacks made by good beings."},
                {"Invisibility", "Turns you invisible."},
                {"Manes Summoning", "Summons an inferior demon to your aid."},
                {"Demoncloak", "Protects you from fire and cold and shields you."},
                {"Breath Fire", "Unleashes a powerful fire ball."},
                {"Fire Blade", "Hastes you, surrounds you with fire and makes you fight with berserk fury."},
                {"Circle of Madness", "Fires explosions of chaos, confusion and charm."},

		/* Minions of Azathoth */
                {"Bladecalm", "It needs to be coded :)"},
                {"Control Demons", "Attempts to charm demons."},
                {"Revive", "It will revive dead demons."},
                {"Trap Demonsoul", "Attempts to enslave a demon."},
                {"Discharge Minions", "Makes all your pets explode like powerful bombs."},
                {"Summon Demons", "Calls some demons to your aid."},

		/* Demonthoughts */
                {"Rain of Lava", "Creates a ball of lava."},
                {"Kiss of the Succubus", "Unleashes a ball of nexus."},
                {"Immortality", "Allows you to resist the ravages of time."},
                {"Glyph of Warding", "It will create a glyph that prevents monsters movement."},
                {"Lava Storm", "Creates a powerful ball of lava."},
                {"Demonform", "Turns you into a demon lord for a short duration."},

		/* Hellfire Tome */
                {"Unholy word", "Heals and cures you."},
                {"Hellfire", "Creates 2 balls of powerful hellfire."},
                {"Armageddon", "Sends into oblivion all monsters near you."},
                {"Shield of the Damned", "Makes you nearly invulnerable for a short duration."},
	},

        /* Spirit */
        {
                {"Phase Door", "Teleports you a few squares."},
                {"Teleport", "Teleports you to another section of the level."},
                {"Teleport Level", "Teleports you out of the level."},
                {"Fast Recall", "It will quickly recall you to town or dungeon."},
                {"Probability Travel", "Allows you to ignore walls and stairs."},
                {"Energize", "Provides a free turn, at the cost of all your mana."},
                {"Solidify Continuum", "Prevents all forms of teleportation."},
                {"Between Jump", "Creates a between gate."},

                {"Detect Monsters", "Detects monsters near you."},
                {"Knowledge", "Identifies an item."},
                {"Reveal Secrets", "Detects everything around you."},
                {"Probe", "Probes a monster."},
                {"Reveal Wilderness", "Reveals more of the wilderness map."},
                {"Self Knowledge", "Reveals more about yourself."},
                {"*Knowledge*", "Fully identifies an item."},
                {"Clairvoyance", "Fully maps out a level."},

                {"Radiate Force", "Projects beams of force in all directions."},
                {"Telekinesis", "Lets you grab a distant object."},
                {"Gravitic Hole", "Creates a ball of gravity, throwing monsters away."},
                {"Project Force", "Creates a ball of pure force."},
                {"Elemental Shield", "Helps you resist fire, cold, lightning, acid and poison."},
                {"Wipe", "Fully wipes the area around you."},
                {"Inertia Wave", "Projects a wave of inertia to all monster in line of sight."},
                {"Disruption Shield", "It will use your sp as your hp"},

                {"Charm Monster", "Tries to charm a monster."},
                {"Disrupt Mind", "Confuses and stuns a monster."},
                {"Sleep", "Sends all monsters in line of sight to sleep."},
                {"Awareness", "Allows you to see into the minds of monsters."},
                {"Psychic Surgery", "It will repair any damage to your brain."},
                {"Mass Charm", "Tries to charm all monsters in line of sight."},
                {"Disrupt Minds", "Confuses and stuns all monsters in line of sight."},
                {"Mental Blast", "Projects a pure wave of psi energy."},
        },
};

/*
 * Class titles for the player.
 *
 * The player gets a new title every five levels, so each class
 * needs only ten titles total.
 */
cptr player_title[MAX_CLASS][PY_MAX_LEVEL/5] =
{
	/* Warrior */
	{
		"Rookie",
		"Soldier",
		"Mercenary",
		"Veteran",
		"Swordsman",
		"Champion",
		"Hero",
		"Baron",
		"Duke",
		"Lord",
	},

	/* Mage */
	{
		"Apprentice",
		"Trickster",
		"Illusionist",
		"Spellbinder",
		"Evoker",
		"Conjurer",
		"Warlock",
		"Sorcerer",
		"Ipsissimus",
		"Archimage",
	},

	/* Priest */
	{
		"Believer",
		"Acolyte",
		"Adept",
		"Curate",
		"Canon",
		"Priest",
		"High Priest",
		"Cardinal",
		"Inquisitor",
		"Pope",
	},

	/* Rogues */
	{
		"Cutpurse",
		"Robber",
		"Burglar",
		"Filcher",
		"Sharper",
		"Low Thief",
		"High Thief",
		"Master Thief",
		"Assassin",
		"Guildmaster",
	},

	/* Rangers */
	{
		"Runner",
		"Strider",
		"Scout",
		"Courser",
		"Tracker",
		"Guide",
		"Pathfinder",
		"Low Ranger",
		"High Ranger",
		"Ranger Lord",
	},

	/* Paladins */
	{
		"Gallant",
		"Keeper",
		"Protector",
		"Defender",
		"Warder",
		"Knight",
		"Guardian",
		"Low Paladin",
		"High Paladin",
		"Paladin Lord",
	},

	/* Warrior-Mage */
	{
		"Novice",
		"Apprentice",
		"Journeyman",
		"Veteran",
		"Enchanter",
		"Champion",
		"Mage-Hero",
		"Baron Mage",
		"Battlemage",
		"Wizard Lord",
	},

	/* Chaos Warrior */
	{
		"Rookie",
		"Soldier",
		"Mercenary",
		"Veteran",
		"Swordsman",
		"Champion",
		"Chaos Hero",
		"Chaos Baron",
		"Chaos Duke",
		"Chaos Lord",
	},

	/* Monk */
	{
		"Initiate",
		"Brother",
		"Disciple",
		"Immaculate",
		"Master",
		"Soft Master",
		"Hard Master",
		"Flower Master",
		"Dragon Master",
		"Grand Master",
	},

	/* Mindcrafter */
	{
		"Trainee",
		"Acolyte",
		"Adept",
		"Immaculate",
		"Contemplator",
		"Mentalist",
		"Psychic",
		"Psionicist",
		"Esper",
		"Mindmaster",
	},

	/* High Mage; same as Mage */
	{
		"Apprentice",
		"Trickster",
		"Illusionist",
		"Spellbinder",
		"Evoker",
		"Conjurer",
		"Warlock",
		"Sorcerer",
		"Ipsissimus",
		"Archimage",
	},

        /* Mimic */
	{
                "Learner",
                "Itemhider",
                "Woodshider",
                "Wolfleader",
                "Low Mirror",
                "Journeymirror",
                "High Mirror",
                "Dragonleader",
                "Shapechanger",
                "Mirror Lord",
	},

        /* BeastMaster */
	{
                "Beastslave",
                "Beastman",
                "Enslaver",
                "Summoner",
                "Beastriser",
                "Thingriser",
                "Demonriser",
                "Chaosriser",
                "Hellriser",
                "BeastMaster",
	},

        /* Alchemist */
	{
                "Student",
                "Topologist",
                "Alchemist",
                "Meddler",
                "Catalyst",
                "Chemist",
                "Transformer",
		"Remaker",
                "Grand Source",
                "Infuser",
	},

        /* Symbiant */
	{
                "Little Mold",
                "Mold",
                "Great Mold",
                "Little Jelly",
                "Jelly",
                "Great Jelly",
                "Symbiant",
                "Symbiant",
                "Symbiant",
                "Greater Jelly",
	},

        /* Harper */
	/* Regular titles 
	{
                "Apprentice",
                "Songsmith",
                "Bard",
                "Companion",
                "Minstrel",
                "Harper",
                "Loreweaver",
                "Muse",
                "Dreamweaver",
                "Master Harper",
	},
	*/
	/* CUSSD titles */
	{
		"Elem. Beginner",
		"Elem. Advanced",
		"Cadet Band",
		"Crusader Band",
		"Marching Band",
		"Concert Band",
		"Symphonic Band",
		"Unemployed",
		"Destitute",
		"Director",
	},
        
	/* Power Mage */
	{
                "Chaos Slave",
                "Chaos Serf",
                "Chaos Novice",
                "Chaos Caster",
                "Chaos Wielder",
                "Chaos Lord",
                "Chaos Master",
                "Chaos Fiend",
                "Chaos King",
                "Chaos King",
	},

        /* Runecrafter */
	{
                "Ignoramus",
                "Charlatan",
                "Initiate",
                "Adept",
		"Evoker",
		"Conjurer",
                "Proselyte",
                "Inculcator",
                "Warder",
                "Runemal",
	},

        /* Possessor */
	{
                "Soul",
                "Free Soul",
                "True Soul",
                "Soul Bender",
                "Body Render",
                "Low Corpser",
                "High Corpser",
                "Possessor",
                "PossessorLord",
                "Soul Master",
	},

        /* Sorceror -- Same as Mage */
	{
		"Apprentice",
		"Trickster",
                "Dilante",
                "Dabbler",
                "Invoker",
                "Low Sorceror",
                "High Sorceror",
                "Low Magus",
                "Magus",
                "True Magus",
	},

        /* Archer */
	{
                "Rock Thrower",
                "Slinger",
                "Great Slinger",
                "Tosser",
                "Bowman",
                "Great Bowman",
                "Great Bowman",
                "Archer",
                "Archer",
                "Great Archer",
	},

	/* Illusionist -KMW- */
	{
		"Novice",
		"Apprentice",
		"Trickster",
		"Cabalist",
		"Visionist",
		"Phantasmist",
		"Spellbinder",
		"Illusionist",
		"Shadow",
		"Shadow Lord",
	},

	/* Druid */
	{
		"Wanderer",
		"Tamer",
		"Nurturer",
		"Gardener",
		"Creator",
		"Earth Warder",
		"Windrider",
		"Stormwielder",
                "Druid",
                "Archdruid",
	},

        /* Necromancer */
	{
		"Acolyte",
		"Curser",
		"Dark Student",
		"Initiate",
		"Slavemaster",
		"Summoner",
		"Controller",
		"Commander",
		"Dark Master",
		"Night Lord",
	},

        /* Unbeliever */
	{
                "Asker",
                "Thinker",
                "Faithless",
                "Critic",
                "Betrayer",
                "Renegate",
                "Undisciple",
                "Disbeliever",
                "Knower",
                "Magicbane",
	},

        /* Daemonologist -SC- */
	{
		"Initiate",
		"Acolyte",
		"Adept",
		"Slavemaster",
		"Spellweaver",
		"Demonriser",
		"Controller",
		"Commander",
		"Hell Master",
		"Daemon Lord",
	},

	/*
	 * Weaponmaster -- All new titles -- Improv
	 */
	{
		"Trainee",
		"Wielder",
		"Armsman",
		"Soldier",
		"Specialist",
		"Adept",
		"Pro",
		"Expert",
		"Master",
		"High Master",
	},

	/* Merchant */
	{
		"Customer",
		"Apprentice",
		"Assistant",
		"Assistant",
		"Clerk",
		"Clerk",
		"Shopkeeper",
		"Shopkeeper",
		"Shop Manager",
		"Shop Manager",
	},
};



/*
 * Hack -- the "basic" color names (see "TERM_xxx")
 */
cptr color_names[16] =
{
	"Dark",
	"White",
	"Slate",
	"Orange",
	"Red",
	"Green",
	"Blue",
	"Umber",
	"Light Dark",
	"Light Slate",
	"Violet",
	"Yellow",
	"Light Red",
	"Light Green",
	"Light Blue",
	"Light Umber",
};


/*
 * Abbreviations of healthy stats
 */
cptr stat_names[6] =
{
        "STR", "INT", "WIS", "DEX", "CON", "CHR"
};

/*
 * Abbreviations of damaged stats
 */
cptr stat_names_reduced[6] =
{
        "Str", "Int", "Wis", "Dex", "Con", "Chr"
};


/*
 * Certain "screens" always use the main screen, including News, Birth,
 * Dungeon, Tomb-stone, High-scores, Macros, Colors, Visuals, Options.
 *
 * Later, special flags may allow sub-windows to "steal" stuff from the
 * main window, including File dump (help), File dump (artifacts, uniques),
 * Character screen, Small scale map, Previous Messages, Store screen, etc.
 *
 * The "ctrl-i" (tab) command flips the "Display inven/equip" and "Display
 * equip/inven" flags for all windows.
 *
 * The "ctrl-g" command (or pseudo-command) should perhaps grab a snapshot
 * of the main screen into any interested windows.
 */
cptr window_flag_desc[32] =
{
	"Display inven/equip",
	"Display equip/inven",
	"Display spell list",
	"Display character",
        "Show visible monsters",
	NULL,
	"Display messages",
	"Display overhead view",
	"Display monster recall",
	"Display object recall",
	NULL,
	"Display snap-shot",
	NULL,
	NULL,
	"Display borg messages",
	"Display borg status",
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};


/*
 * Available Options
 *
 * Option Screen Sets:
 *
 *      Set 1: User Interface
 *      Set 2: Disturbance
 *      Set 3: Inventory
 *      Set 4: Game Play
 *      Set 5: PernAngband
 *      Set 6: Birth
 *
 * Note that bits 28-31 of set 0 are currently unused.
 */
option_type option_info[] =
{
	/*** User-Interface ***/

        { &rogue_like_commands,         FALSE,  1,      0,
	"rogue_like_commands",          "Rogue-like commands" },

        { &quick_messages,              TRUE,  1,       1,
	"quick_messages",               "Activate quick messages" },

        { &other_query_flag,            FALSE,  1,      2,
	"other_query_flag",             "Prompt for various information" },

        { &carry_query_flag,            FALSE,  1,      3,
	"carry_query_flag",             "Prompt before picking things up" },

        { &use_old_target,              FALSE,  1,      4,
        "use_old_target",               "Use old target by default" },

        { &always_pickup,               FALSE,  1,      5,
	"always_pickup",                "Pick things up by default" },

        { &prompt_pickup_heavy,         TRUE,   1,      6,
        "prompt_pickup_heavy",          "Prompt before picking up heavy objects" },

        { &always_repeat,               TRUE,   1,      7,
	"always_repeat",                "Repeat obvious commands" },

        { &depth_in_feet,               FALSE,  1,      8,
	"depth_in_feet",                "Show dungeon level in feet" },

        { &stack_force_notes,           TRUE,  1,       9,
	"stack_force_notes",            "Merge inscriptions when stacking" },

        { &stack_force_costs,           FALSE,  1,      10,
	"stack_force_costs",            "Merge discounts when stacking" },

        { &show_labels,                 TRUE,   1,      11,
	"show_labels",                  "Show labels in object listings" },

        { &show_weights,                TRUE,   1,       12,
	"show_weights",                 "Show weights in object listings" },

        { &show_inven_graph,            TRUE,   1,      13,
	"show_inven_graph",             "Show graphics in inventory list" },

        { &show_equip_graph,            TRUE,   1,      14,
	"show_equip_graph",             "Show graphics in equipment list" },

        { &show_store_graph,            TRUE,   1,      15,
	"show_store_graph",             "Show graphics in stores" },

        { &show_choices,                TRUE,  1,       16,
	"show_choices",                 "Show choices in certain sub-windows" },

        { &show_details,                TRUE,  1,       17,
	"show_details",                 "Show details in certain sub-windows" },

        { &ring_bell,                   FALSE,   1,     18,
	"ring_bell",                    "Audible bell (on errors, etc)" },
	/* Changed to default to FALSE -- it's so extremely annoying!!! -TY */

        { &use_color,                   TRUE,   1,      19,
	"use_color",                    "Use color if possible (slow)" },


	/*** Disturbance ***/

        { &find_ignore_stairs,          FALSE,   2,     0,
	"find_ignore_stairs",           "Run past stairs" },

        { &find_ignore_doors,           TRUE,   2,      1,
	"find_ignore_doors",            "Run through open doors" },

        { &find_cut,                    FALSE,   2,     2,
	"find_cut",                     "Run past known corners" },

        { &find_examine,                TRUE,   2,      3,
	"find_examine",                 "Run into potential corners" },

        { &disturb_move,                FALSE,   2,     4,
	"disturb_move",                 "Disturb whenever any monster moves" },

        { &disturb_near,                TRUE,   2,      5,
	"disturb_near",                 "Disturb whenever viewable monster moves" },

        { &disturb_panel,               TRUE,   2,      6,
	"disturb_panel",                "Disturb whenever map panel changes" },

        { &disturb_state,               TRUE,   2,      7,
	"disturb_state",                "Disturb whenever player state changes" },

        { &disturb_minor,               TRUE,   2,      8,
	"disturb_minor",                "Disturb whenever boring things happen" },

        { &disturb_other,               TRUE,   2,      9,
	"disturb_other",                "Disturb whenever random things happen" },

        { &alert_hitpoint,              FALSE,  2,      10,
	"alert_hitpoint",               "Alert user to critical hitpoints" },

        { &alert_failure,               FALSE,  2,      11,
	"alert_failure",                "Alert user to various failures" },

        { &last_words,                  TRUE,   2,      12,
	"last_words",                   "Get last words when the character dies" },

        { &speak_unique,                TRUE,   2,      13,
	"speak_unique",                 "Allow shopkeepers and uniques to speak" },

        { &auto_destroy,                TRUE,   2,      14,
	"auto_destroy",                 "No query to destroy known worthless items" },

        { &wear_confirm,                TRUE,   2,      15,
	"confirm_wear",                 "Confirm to wear/wield known cursed items" },

        { &confirm_stairs,              FALSE,  2,      16,
	"confirm_stairs",               "Prompt before exiting a dungeon level" },

        { &disturb_pets,                FALSE,  2,      17,
	"disturb_pets",                 "Disturb when visible pets move" },

#ifdef ALLOW_EASY_OPEN
        { &easy_open,                   TRUE,   2,      18,
        "easy_open",                    "Automatically open doors" },
#endif /* ALLOW_EASY_OPEN */

#ifdef ALLOW_EASY_DISARM
        { &easy_disarm,                 TRUE,   2,      19,
        "easy_disarm",                  "Automatically disarm traps" },
#endif /* ALLOW_EASY_DISARM */

        { &easy_tunnel,                 FALSE,  2,      20,
        "easy_tunnel",                  "Automaticaly tunnel walls" },

	/*** Game-Play ***/

        { &auto_haggle,                 TRUE,  3,       0,
	"auto_haggle",                  "Auto-haggle in stores" },

        { &auto_scum,                   TRUE,  3,       1,
	"auto_scum",                    "Auto-scum for good levels" },

        { &stack_allow_items,           TRUE,   3,      2,
	"stack_allow_items",            "Allow weapons and armor to stack" },

        { &stack_allow_wands,           TRUE,   3,      3,
	"stack_allow_wands",            "Allow wands/staffs/rods to stack" },

        { &expand_look,                 FALSE,  3,      4,
	"expand_look",                  "Expand the power of the look command" },

        { &expand_list,                 FALSE,  3,      5,
	"expand_list",                  "Expand the power of the list commands" },

        { &view_perma_grids,            TRUE,   3,      6,
	"view_perma_grids",             "Map remembers all perma-lit grids" },

        { &view_torch_grids,            FALSE,  3,      7,
	"view_torch_grids",             "Map remembers all torch-lit grids" },

        { &dungeon_align,               TRUE,   3,      8,
	"dungeon_align",                "Generate dungeons with aligned rooms" },

        { &dungeon_stair,               TRUE,   3,      9,
	"dungeon_stair",                "Generate dungeons with connected stairs" },

        { &flow_by_sound,               FALSE,  3,      10,
	"flow_by_sound",                "Monsters chase current location (v.slow)" },

        { &flow_by_smell,               FALSE,  3,      11,
	"flow_by_smell",                "Monsters chase recent locations (v.slow)" },

         { &player_symbols,              FALSE, 3,      12,
	"player_symbols",               "Use special symbols for the player char"},

        { &plain_descriptions,          TRUE,   3,      13,
	"plain_descriptions",           "Plain object descriptions" },

        { &smart_learn,                 FALSE,  3,      14,
	"smart_learn",                  "Monsters learn from their mistakes" },

        { &smart_cheat,                 FALSE,  3,      15,
	"smart_cheat",                  "Monsters exploit players weaknesses" },

        { &stupid_monsters,             FALSE,  3,      16,
	"stupid_monsters",              "Monsters behave stupidly" },

        { &small_levels,                TRUE,   3,      17,
	"small_levels",                 "Allow unusually small dungeon levels" },

        { &empty_levels,                TRUE,   3,      18,
        "empty_levels",                 "Allow empty 'arena' levels" },

	/*** Efficiency ***/

        { &view_reduce_lite,            FALSE,  4,      0,
	"view_reduce_lite",             "Reduce lite-radius when running" },

        { &view_reduce_view,            FALSE,  4,      1,
	"view_reduce_view",             "Reduce view-radius in town" },

        { &avoid_abort,                 FALSE,  4,      2,
	"avoid_abort",                  "Avoid checking for user abort" },

        { &avoid_other,                 FALSE,  4,      3,
        "avoid_other",                  "Avoid processing special colors(slow)" },

        { &flush_failure,               TRUE,   4,      4,
	"flush_failure",                "Flush input on various failures" },

        { &flush_disturb,               FALSE,  4,      5,
	"flush_disturb",                "Flush input whenever disturbed" },

        { &flush_command,               FALSE,  4,      6,
	"flush_command",                "Flush input before every command" },

        { &fresh_before,                TRUE,   4,      7,
	"fresh_before",                 "Flush output before every command" },

        { &fresh_after,                 FALSE,  4,      8,
	"fresh_after",                  "Flush output after every command" },

        { &fresh_message,               FALSE,  4,      9,
	"fresh_message",                "Flush output after every message" },

        { &compress_savefile,           TRUE,   4,      10,
	"compress_savefile",            "Compress messages in savefiles" },

        { &hilite_player,               FALSE,  4,      11,
	"hilite_player",                "Hilite the player with the cursor" },

        { &view_yellow_lite,            FALSE,  4,      12,
	"view_yellow_lite",             "Use special colors for torch-lit grids" },

        { &view_bright_lite,            FALSE,  4,      13,
	"view_bright_lite",             "Use special colors for 'viewable' grids" },

        { &view_granite_lite,           FALSE,   4,     14,
	"view_granite_lite",            "Use special colors for wall grids (slow)" },

        { &view_special_lite,           FALSE,  4,      15,
	"view_special_lite",            "Use special colors for floor grids (slow)" },

        { &center_player,               FALSE,  4,      16,
        "center_player",                "Center the view on the player (very slow)" },

        /*** PernAngband options ***/

        { &flavored_attacks,            TRUE,   5,      0,
        "flavored_attacks",             "Show silly messages when fighting" },

        { &(p_body.help.enabled),       TRUE,   5,      1,
        "ingame_help",                  "Ingame contextual help" },

        { &exp_need,                    FALSE,  5,      2,
        "exp_need",                     "Show the experience needed for next level" },

        { &autoload_old_colors,         FALSE,  5,      3,
        "old_colors",                   "Use the old(Z) coloring scheme(reload the game)" },

        { &auto_more,                   FALSE,  5,      4,
        "auto_more",                    "Automatically clear '-more-' prompts" },

        /*** Birth Options ***/

#if 0 /* XXX free -- no more used */
        { &vanilla_town,                FALSE,  6,      0,
	"vanilla_town",                 "Use 'vanilla' town without quests and wilderness" },
#endif

        { &maximize,                    TRUE,   6,      1,
        "maximize",                     "Maximize stats" },

        { &preserve,                    TRUE,   6,      2,
        "preserve",                     "Preserve artifacts" },

        { &autoroll,                    TRUE,   6,      3,
        "autoroll",                     "Specify 'minimal' stats" },

        { &point_based,                 FALSE,  6,      17,
        "point_based",                  "Generate character using a point system" },
#if 0
        { &special_lvls,                TRUE,   6,      4,
        "special_lvls",                 "Allow the use of special, unique, levels" },
#endif
        { &permanent_levels,            FALSE,  6,      5,
        "permanent_levels",             "Generate persistent dungeons" },

        { &ironman_rooms,               FALSE,  6,      6,
	"ironman_rooms",                "Always generate very unusual rooms" },

        { &take_notes,                  TRUE,   6,      7,
        "take_notes",                   "Allow notes to be written to a file" },

        { &auto_notes,                  TRUE,   6,      8,
        "auto_notes",                   "Automatically note important events" },

#if 0 /* when Ill get some ideas */
        { &rand_birth,                  FALSE,  6,      9,
        "rand_birth",                   "Random present at brith" },
#endif
        { &fast_autoroller,             FALSE,  6,      10,
        "fast_autoroller",              "Fast autoroller(NOT on multiuser systems)" },

        { &cth_monsters,                TRUE,   6,      11,
        "cth_monsters",                 "Allow use of lovercraftian monsters" },

#if 0
        { &pern_monsters,               TRUE,   6,      12,
        "pern_monsters",                "Allow use of some Pern related monsters" },
#endif
        { &zang_monsters,               TRUE,   6,      13,
        "zang_monsters",                "Allow use of 'Zangbandish' monsters" },

        { &joke_monsters,               TRUE,   6,      14,
        "joke_monsters",                "Allow use of some 'joke' monsters" },

        { &astral_option,               FALSE,  6,      15,
        "astral_option",                "Player starts at the bottom of the dungeon" },

        { &always_small_level,          FALSE,  6,      16,
        "always_small_level",           "Always make small levels" },

        { &fate_option,                 TRUE,   6,      18,
        "fate_option",                  "You can receive fates, good or bad" },

        /* XXX 17 is used BEFORE */

        /*** Stacking ***/

        { &testing_stack,               TRUE,  7,       0,
	"testing_stack",                "Allow objects to stack on floor" },

        { &testing_carry,               TRUE,  7,       1,
	"testing_carry",                "Allow monsters to carry objects" },


	/*** End of Table ***/

        { NULL,                         0, 0, 0,
	NULL,                           NULL }
};


cptr chaos_patrons[MAX_PATRON] =
{
	"Slortar",
	"Mabelode",
	"Chardros",
	"Hionhurn",
	"Xiombarg",

	"Pyaray",
	"Balaan",
	"Arioch",
	"Eequor",
	"Narjhan",

	"Balo",
	"Khorne",
	"Slaanesh",
	"Nurgle",
	"Tzeentch",

	"Khaine"
};

int chaos_stats[MAX_PATRON] =
{
	A_CON,  /* Slortar */
	A_CON,  /* Mabelode */
	A_STR,  /* Chardros */
	A_STR,  /* Hionhurn */
	A_STR,  /* Xiombarg */

	A_INT,  /* Pyaray */
	A_STR,  /* Balaan */
	A_INT,  /* Arioch */
	A_CON,  /* Eequor */
	A_CHR,  /* Narjhan */

	-1,     /* Balo */
	A_STR,  /* Khorne */
	A_CHR,  /* Slaanesh */
	A_CON,  /* Nurgle */
	A_INT,  /* Tzeentch */

	A_STR,  /* Khaine */
};




int chaos_rewards[MAX_PATRON][20] =
{
	/* Slortar the Old: */
	{
		REW_WRATH, REW_CURSE_WP, REW_CURSE_AR, REW_RUIN_ABL, REW_LOSE_ABL,
		REW_IGNORE, REW_IGNORE, REW_IGNORE, REW_POLY_WND, REW_POLY_SLF,
		REW_POLY_SLF, REW_POLY_SLF, REW_GAIN_ABL, REW_GAIN_ABL, REW_GAIN_EXP,
		REW_GOOD_OBJ, REW_CHAOS_WP, REW_GREA_OBJ, REW_AUGM_ABL, REW_AUGM_ABL
	},

	/* Mabelode the Faceless: */
	{
		REW_WRATH, REW_CURSE_WP, REW_CURSE_AR, REW_H_SUMMON, REW_SUMMON_M,
		REW_SUMMON_M, REW_IGNORE, REW_IGNORE, REW_POLY_WND, REW_POLY_WND,
		REW_POLY_SLF, REW_HEAL_FUL, REW_HEAL_FUL, REW_GAIN_ABL, REW_SER_UNDE,
		REW_CHAOS_WP, REW_GOOD_OBJ, REW_GOOD_OBJ, REW_GOOD_OBS, REW_GOOD_OBS
	},

	/* Chardros the Reaper: */
	{
		REW_WRATH, REW_WRATH, REW_HURT_LOT, REW_PISS_OFF, REW_H_SUMMON,
		REW_SUMMON_M, REW_IGNORE, REW_IGNORE, REW_DESTRUCT, REW_SER_UNDE,
		REW_GENOCIDE, REW_MASS_GEN, REW_MASS_GEN, REW_DISPEL_C, REW_GOOD_OBJ,
		REW_CHAOS_WP, REW_GOOD_OBS, REW_GOOD_OBS, REW_AUGM_ABL, REW_AUGM_ABL
	},

	/* Hionhurn the Executioner: */
	{
		REW_WRATH, REW_WRATH, REW_CURSE_WP, REW_CURSE_AR, REW_RUIN_ABL,
		REW_IGNORE, REW_IGNORE, REW_SER_UNDE, REW_DESTRUCT, REW_GENOCIDE,
		REW_MASS_GEN, REW_MASS_GEN, REW_HEAL_FUL, REW_GAIN_ABL, REW_GAIN_ABL,
		REW_CHAOS_WP, REW_GOOD_OBS, REW_GOOD_OBS, REW_AUGM_ABL, REW_AUGM_ABL
	},

	/* Xiombarg the Sword-Queen: */
	{
		REW_TY_CURSE, REW_TY_CURSE, REW_PISS_OFF, REW_RUIN_ABL, REW_LOSE_ABL,
		REW_IGNORE, REW_POLY_SLF, REW_POLY_SLF, REW_POLY_WND, REW_POLY_WND,
		REW_GENOCIDE, REW_DISPEL_C, REW_GOOD_OBJ, REW_GOOD_OBJ, REW_SER_MONS,
		REW_GAIN_ABL, REW_CHAOS_WP, REW_GAIN_EXP, REW_AUGM_ABL, REW_GOOD_OBS
	},


	/* Pyaray the Tentacled Whisperer of Impossible Secretes: */
	{
		REW_WRATH, REW_TY_CURSE, REW_PISS_OFF, REW_H_SUMMON, REW_H_SUMMON,
		REW_IGNORE, REW_IGNORE, REW_IGNORE, REW_POLY_WND, REW_POLY_SLF,
		REW_POLY_SLF, REW_SER_DEMO, REW_HEAL_FUL, REW_GAIN_ABL, REW_GAIN_ABL,
		REW_CHAOS_WP, REW_DO_HAVOC, REW_GOOD_OBJ, REW_GREA_OBJ, REW_GREA_OBS
	},

	/* Balaan the Grim: */
	{
		REW_TY_CURSE, REW_HURT_LOT, REW_CURSE_WP, REW_CURSE_AR, REW_RUIN_ABL,
		REW_SUMMON_M, REW_LOSE_EXP, REW_POLY_SLF, REW_POLY_SLF, REW_POLY_WND,
		REW_SER_UNDE, REW_HEAL_FUL, REW_HEAL_FUL, REW_GAIN_EXP, REW_GAIN_EXP,
		REW_CHAOS_WP, REW_GOOD_OBJ, REW_GOOD_OBS, REW_GREA_OBS, REW_AUGM_ABL
	},

	/* Arioch, Duke of Hell: */
	{
		REW_WRATH, REW_PISS_OFF, REW_RUIN_ABL, REW_LOSE_EXP, REW_H_SUMMON,
		REW_IGNORE, REW_IGNORE, REW_IGNORE, REW_IGNORE, REW_POLY_SLF,
		REW_POLY_SLF, REW_MASS_GEN, REW_SER_DEMO, REW_HEAL_FUL, REW_CHAOS_WP,
		REW_CHAOS_WP, REW_GOOD_OBJ, REW_GAIN_EXP, REW_GREA_OBJ, REW_AUGM_ABL
	},

	/* Eequor, Blue Lady of Dismay: */
	{
		REW_WRATH, REW_TY_CURSE, REW_PISS_OFF, REW_CURSE_WP, REW_RUIN_ABL,
		REW_IGNORE, REW_IGNORE, REW_POLY_SLF, REW_POLY_SLF, REW_POLY_WND,
		REW_GOOD_OBJ, REW_GOOD_OBJ, REW_SER_MONS, REW_HEAL_FUL, REW_GAIN_EXP,
		REW_GAIN_ABL, REW_CHAOS_WP, REW_GOOD_OBS, REW_GREA_OBJ, REW_AUGM_ABL
	},

	/* Narjhan, Lord of Beggars: */
	{
		REW_WRATH, REW_CURSE_AR, REW_CURSE_WP, REW_CURSE_WP, REW_CURSE_AR,
		REW_IGNORE, REW_IGNORE, REW_IGNORE, REW_POLY_SLF, REW_POLY_SLF,
		REW_POLY_WND, REW_HEAL_FUL, REW_HEAL_FUL, REW_GAIN_EXP, REW_AUGM_ABL,
		REW_GOOD_OBJ, REW_GOOD_OBJ, REW_CHAOS_WP, REW_GREA_OBJ, REW_GREA_OBS
	},

	/* Balo the Jester: */
	{
		REW_WRATH, REW_SER_DEMO, REW_CURSE_WP, REW_CURSE_AR, REW_LOSE_EXP,
		REW_GAIN_ABL, REW_LOSE_ABL, REW_POLY_WND, REW_POLY_SLF, REW_IGNORE,
		REW_DESTRUCT, REW_MASS_GEN, REW_CHAOS_WP, REW_GREA_OBJ, REW_HURT_LOT,
		REW_AUGM_ABL, REW_RUIN_ABL, REW_H_SUMMON, REW_GREA_OBS, REW_AUGM_ABL
	},

	/* Khorne the Bloodgod: */
	{
		REW_WRATH, REW_HURT_LOT, REW_HURT_LOT, REW_H_SUMMON, REW_H_SUMMON,
		REW_IGNORE, REW_IGNORE, REW_IGNORE, REW_SER_MONS, REW_SER_DEMO,
		REW_POLY_SLF, REW_POLY_WND, REW_HEAL_FUL, REW_GOOD_OBJ, REW_GOOD_OBJ,
		REW_CHAOS_WP, REW_GOOD_OBS, REW_GOOD_OBS, REW_GREA_OBJ, REW_GREA_OBS
	},

	/* Slaanesh: */
	{
		REW_WRATH, REW_PISS_OFF, REW_PISS_OFF, REW_RUIN_ABL, REW_LOSE_ABL,
		REW_LOSE_EXP, REW_IGNORE, REW_IGNORE, REW_POLY_WND, REW_SER_DEMO,
		REW_POLY_SLF, REW_HEAL_FUL, REW_HEAL_FUL, REW_GOOD_OBJ, REW_GAIN_EXP,
		REW_GAIN_EXP, REW_CHAOS_WP, REW_GAIN_ABL, REW_GREA_OBJ, REW_AUGM_ABL
	},

	/* Nurgle: */
	{
		REW_WRATH, REW_PISS_OFF, REW_HURT_LOT, REW_RUIN_ABL, REW_LOSE_ABL,
		REW_LOSE_EXP, REW_IGNORE, REW_IGNORE, REW_IGNORE, REW_POLY_SLF,
		REW_POLY_SLF, REW_POLY_WND, REW_HEAL_FUL, REW_GOOD_OBJ, REW_GAIN_ABL,
		REW_GAIN_ABL, REW_SER_UNDE, REW_CHAOS_WP, REW_GREA_OBJ, REW_AUGM_ABL
	},

	/* Tzeentch: */
	{
		REW_WRATH, REW_CURSE_WP, REW_CURSE_AR, REW_RUIN_ABL, REW_LOSE_ABL,
		REW_LOSE_EXP, REW_IGNORE, REW_POLY_SLF, REW_POLY_SLF, REW_POLY_SLF,
		REW_POLY_SLF, REW_POLY_WND, REW_HEAL_FUL, REW_CHAOS_WP, REW_GREA_OBJ,
		REW_GAIN_ABL, REW_GAIN_ABL, REW_GAIN_EXP, REW_GAIN_EXP, REW_AUGM_ABL
	},

	/* Khaine: */
	{
		REW_WRATH, REW_HURT_LOT, REW_PISS_OFF, REW_LOSE_ABL, REW_LOSE_EXP,
		REW_IGNORE,   REW_IGNORE,   REW_DISPEL_C, REW_DO_HAVOC, REW_DO_HAVOC,
		REW_POLY_SLF, REW_POLY_SLF, REW_GAIN_EXP, REW_GAIN_ABL, REW_GAIN_ABL,
		REW_SER_MONS, REW_GOOD_OBJ, REW_CHAOS_WP, REW_GREA_OBJ, REW_GOOD_OBS
	}
};

/* Names used for random artifact name generation */
cptr artifact_names_list =
"adanedhel\n"
"adurant\n"
"aeglos\n"
"aegnor\n"
"aelin\n"
"aeluin\n"
"aerandir\n"
"aerin\n"
"agarwaen\n"
"aglareb\n"
"aglarond\n"
"aglon\n"
"ainulindale\n"
"ainur\n"
"alcarinque\n"
"aldaron\n"
"aldudenie\n"
"almaren\n"
"alqualonde\n"
"aman\n"
"amandil\n"
"amarie\n"
"amarth\n"
"amlach\n"
"amon\n"
"amras\n"
"amrod\n"
"anach\n"
"anar\n"
"anarion\n"
"ancalagon\n"
"ancalimon\n"
"anarrima\n"
"andor\n"
"andram\n"
"androth\n"
"anduin\n"
"andunie\n"
"anfauglir\n"
"anfauglith\n"
"angainor\n"
"angband\n"
"anghabar\n"
"anglachel\n"
"angrenost\n"
"angrim\n"
"angrist\n"
"angrod\n"
"anguirel\n"
"annael\n"
"annatar\n"
"annon\n"
"annuminas\n"
"apanonar\n"
"aradan\n"
"aragorn\n"
"araman\n"
"aranel\n"
"aranruth\n"
"aranwe\n"
"aras\n"
"aratan\n"
"aratar\n"
"arathorn\n"
"arda\n"
"ard-galen\n"
"aredhel\n"
"ar-feiniel\n"
"argonath\n"
"arien\n"
"armenelos\n"
"arminas\n"
"arnor\n"
"aros\n"
"arossiach\n"
"arthad\n"
"arvernien\n"
"arwen\n"
"ascar\n"
"astaldo\n"
"atalante\n"
"atanamir\n"
"atanatari\n"
"atani\n"
"aule\n"
"avallone\n"
"avari\n"
"avathar\n"
"balan\n"
"balar\n"
"balrog\n"
"barad\n"
"baragund\n"
"barahir\n"
"baran\n"
"baranduin\n"
"bar\n"
"bauglir\n"
"beleg\n"
"belegaer\n"
"belegost\n"
"belegund\n"
"beleriand\n"
"belfalas\n"
"belthil\n"
"belthronding\n"
"beor\n"
"beraid\n"
"bereg\n"
"beren\n"
"boromir\n"
"boron\n"
"bragollach\n"
"brandir\n"
"bregolas\n"
"bregor\n"
"brethil\n"
"brilthor\n"
"brithiach\n"
"brithombar\n"
"brithon\n"
"cabed\n"
"calacirya\n"
"calaquendi\n"
"calenardhon\n"
"calion\n"
"camlost\n"
"caragdur\n"
"caranthir\n"
"carcharoth\n"
"cardolan\n"
"carnil\n"
"celeborn\n"
"celebrant\n"
"celebrimbor\n"
"celebrindal\n"
"celebros\n"
"celegorm\n"
"celon\n"
"cirdan\n"
"cirith\n"
"cirth\n"
"ciryatan\n"
"ciryon\n"
"coimas\n"
"corollaire\n"
"crissaegrim\n"
"cuarthal\n"
"cuivienen\n"
"culurien\n"
"curufin\n"
"curufinwe\n"
"curunir\n"
"cuthalion\n"
"daedeloth\n"
"daeron\n"
"dagnir\n"
"dagor\n"
"dagorlad\n"
"dairuin\n"
"danwedh\n"
"delduwath\n"
"denethor\n"
"dimbar\n"
"dimrost\n"
"dinen\n"
"dior\n"
"dirnen\n"
"dolmed\n"
"doriath\n"
"dorlas\n"
"dorthonion\n"
"draugluin\n"
"drengist\n"
"duath\n"
"duinath\n"
"duilwen\n"
"dunedain\n"
"dungortheb\n"
"earendil\n"
"earendur\n"
"earnil\n"
"earnur\n"
"earrame\n"
"earwen\n"
"echor\n"
"echoriath\n"
"ecthelion\n"
"edain\n"
"edrahil\n"
"eglador\n"
"eglarest\n"
"eglath\n"
"eilinel\n"
"eithel\n"
"ekkaia\n"
"elbereth\n"
"eldalie\n"
"eldalieva\n"
"eldamar\n"
"eldar\n"
"eledhwen\n"
"elemmire\n"
"elende\n"
"elendil\n"
"elendur\n"
"elenna\n"
"elentari\n"
"elenwe\n"
"elerrina\n"
"elleth\n"
"elmoth\n"
"elostirion\n"
"elrond\n"
"elros\n"
"elu\n"
"eluchil\n"
"elured\n"
"elurin\n"
"elwe\n"
"elwing\n"
"emeldir\n"
"endor\n"
"engrin\n"
"engwar\n"
"eol\n"
"eonwe\n"
"ephel\n"
"erchamion\n"
"ereb\n"
"ered\n"
"erech\n"
"eregion\n"
"ereinion\n"
"erellont\n"
"eressea\n"
"eriador\n"
"eru\n"
"esgalduin\n"
"este\n"
"estel\n"
"estolad\n"
"ethir\n"
"ezellohar\n"
"faelivrin\n"
"falas\n"
"falathar\n"
"falathrim\n"
"falmari\n"
"faroth\n"
"fauglith\n"
"feanor\n"
"feanturi\n"
"felagund\n"
"finarfin\n"
"finduilas\n"
"fingolfin\n"
"fingon\n"
"finwe\n"
"firimar\n"
"formenos\n"
"fornost\n"
"frodo\n"
"fuin\n"
"fuinur\n"
"gabilgathol\n"
"galad\n"
"galadriel\n"
"galathilion\n"
"galdor\n"
"galen\n"
"galvorn\n"
"gandalf\n"
"gaurhoth\n"
"gelion\n"
"gelmir\n"
"gelydh\n"
"gil\n"
"gildor\n"
"giliath\n"
"ginglith\n"
"girith\n"
"glaurung\n"
"glingal\n"
"glirhuin\n"
"gloredhel\n"
"glorfindel\n"
"golodhrim\n"
"gondolin\n"
"gondor\n"
"gonnhirrim\n"
"gorgoroth\n"
"gorlim\n"
"gorthaur\n"
"gorthol\n"
"gothmog\n"
"guilin\n"
"guinar\n"
"guldur\n"
"gundor\n"
"gurthang\n"
"gwaith\n"
"gwareth\n"
"gwindor\n"
"hadhodrond\n"
"hador\n"
"haladin\n"
"haldad\n"
"haldan\n"
"haldar\n"
"haldir\n"
"haleth\n"
"halmir\n"
"handir\n"
"harad\n"
"hareth\n"
"hathaldir\n"
"hathol\n"
"haudh\n"
"helcar\n"
"helcaraxe\n"
"helevorn\n"
"helluin\n"
"herumor\n"
"herunumen\n"
"hildorien\n"
"himlad\n"
"himring\n"
"hirilorn\n"
"hisilome\n"
"hithaeglir\n"
"hithlum\n"
"hollin\n"
"huan\n"
"hunthor\n"
"huor\n"
"hurin\n"
"hyarmendacil\n"
"hyarmentir\n"
"iant\n"
"iaur\n"
"ibun\n"
"idril\n"
"illuin\n"
"ilmare\n"
"ilmen\n"
"iluvatar\n"
"imlach\n"
"imladris\n"
"indis\n"
"ingwe\n"
"irmo\n"
"isil\n"
"isildur\n"
"istari\n"
"ithil\n"
"ivrin\n"
"kelvar\n"
"kementari\n"
"ladros\n"
"laiquendi\n"
"lalaith\n"
"lamath\n"
"lammoth\n"
"lanthir\n"
"laurelin\n"
"leithian\n"
"legolin\n"
"lembas\n"
"lenwe\n"
"linaewen\n"
"lindon\n"
"lindorie\n"
"loeg\n"
"lomelindi\n"
"lomin\n"
"lomion\n"
"lorellin\n"
"lorien\n"
"lorindol\n"
"losgar\n"
"lothlann\n"
"lothlorien\n"
"luin\n"
"luinil\n"
"lumbar\n"
"luthien\n"
"mablung\n"
"maedhros\n"
"maeglin\n"
"maglor\n"
"magor\n"
"mahanaxar\n"
"mahtan\n"
"maiar\n"
"malduin\n"
"malinalda\n"
"mandos\n"
"manwe\n"
"mardil\n"
"melian\n"
"melkor\n"
"menegroth\n"
"meneldil\n"
"menelmacar\n"
"meneltarma\n"
"minas\n"
"minastir\n"
"mindeb\n"
"mindolluin\n"
"mindon\n"
"minyatur\n"
"mirdain\n"
"miriel\n"
"mithlond\n"
"mithrandir\n"
"mithrim\n"
"mordor\n"
"morgoth\n"
"morgul\n"
"moria\n"
"moriquendi\n"
"mormegil\n"
"morwen\n"
"nahar\n"
"naeramarth\n"
"namo\n"
"nandor\n"
"nargothrond\n"
"narog\n"
"narsil\n"
"narsilion\n"
"narya\n"
"nauglamir\n"
"naugrim\n"
"ndengin\n"
"neithan\n"
"neldoreth\n"
"nenar\n"
"nenning\n"
"nenuial\n"
"nenya\n"
"nerdanel\n"
"nessa\n"
"nevrast\n"
"nibin\n"
"nienna\n"
"nienor\n"
"nimbrethil\n"
"nimloth\n"
"nimphelos\n"
"nimrais\n"
"nimras\n"
"ningloron\n"
"niniel\n"
"ninniach\n"
"ninquelote\n"
"niphredil\n"
"nirnaeth\n"
"nivrim\n"
"noegyth\n"
"nogrod\n"
"noldolante\n"
"noldor\n"
"numenor\n"
"nurtale\n"
"obel\n"
"ohtar\n"
"oiolosse\n"
"oiomure\n"
"olorin\n"
"olvar\n"
"olwe\n"
"ondolinde\n"
"orfalch\n"
"ormal\n"
"orocarni\n"
"orodreth\n"
"orodruin\n"
"orome\n"
"oromet\n"
"orthanc\n"
"osgiliath\n"
"osse\n"
"ossiriand\n"
"palantir\n"
"pelargir\n"
"pelori\n"
"periannath\n"
"quendi\n"
"quenta\n"
"quenya\n"
"radagast\n"
"radhruin\n"
"ragnor\n"
"ramdal\n"
"rana\n"
"rathloriel\n"
"rauros\n"
"region\n"
"rerir\n"
"rhovanion\n"
"rhudaur\n"
"rhun\n"
"rhunen\n"
"rian\n"
"ringil\n"
"ringwil\n"
"romenna\n"
"rudh\n"
"rumil\n"
"saeros\n"
"salmar\n"
"saruman\n"
"sauron\n"
"serech\n"
"seregon\n"
"serinde\n"
"shelob\n"
"silmarien\n"
"silmaril\n"
"silpion\n"
"sindar\n"
"singollo\n"
"sirion\n"
"soronume\n"
"sul\n"
"sulimo\n"
"talath\n"
"taniquetil\n"
"tar\n"
"taras\n"
"tarn\n"
"tathren\n"
"taur\n"
"tauron\n"
"teiglin\n"
"telchar\n"
"telemnar\n"
"teleri\n"
"telperion\n"
"telumendil\n"
"thalion\n"
"thalos\n"
"thangorodrim\n"
"thargelion\n"
"thingol\n"
"thoronath\n"
"thorondor\n"
"thranduil\n"
"thuringwethil\n"
"tilion\n"
"tintalle\n"
"tinuviel\n"
"tirion\n"
"tirith\n"
"tol\n"
"tulkas\n"
"tumhalad\n"
"tumladen\n"
"tuna\n"
"tuor\n"
"turambar\n"
"turgon\n"
"turin\n"
"uial\n"
"uilos\n"
"uinen\n"
"ulairi\n"
"ulmo\n"
"ulumuri\n"
"umanyar\n"
"umarth\n"
"umbar\n"
"ungoliant\n"
"urthel\n"
"uruloki\n"
"utumno\n"
"vaire\n"
"valacirca\n"
"valandil\n"
"valaquenta\n"
"valar\n"
"valaraukar\n"
"valaroma\n"
"valier\n"
"valimar\n"
"valinor\n"
"valinoreva\n"
"valmar\n"
"vana\n"
"vanyar\n"
"varda\n"
"vasa\n"
"vilya\n"
"vingilot\n"
"vinyamar\n"
"voronwe\n"
"wethrin\n"
"wilwarin\n"
"yavanna\n"
;


martial_arts ma_blows[MAX_MA] =
{
#ifdef VERBOSE_MARTIAL_ARTS
	{ "You punch %s.",                          1, 0, 1, 4, 0 },
	{ "You kick %s.",                           2, 0, 1, 6, 0 },
	{ "You strike %s.",                         3, 0, 1, 7, 0 },
	{ "You hit %s with your knee.",             5, 5, 2, 3, MA_KNEE },
	{ "You hit %s with your elbow.",            7, 5, 1, 8, 0 },
	{ "You butt %s.",                           9, 10, 2, 5, 0 },
	{ "You kick %s.",                           11, 10, 3, 4, MA_SLOW },
	{ "You uppercut %s.",                       13, 12, 4, 4, 6 },
	{ "You double-kick %s.",                    16, 15, 5, 4, 8 },
	{ "You hit %s with a Cat's Claw.",          20, 20, 5, 5, 0 },
	{ "You hit %s with a jump kick.",           25, 25, 5, 6, 10 },
	{ "You hit %s with an Eagle's Claw.",       29, 25, 6, 6, 0 },
	{ "You hit %s with a circle kick.",         33, 30, 6, 8, 10 },
	{ "You hit %s with an Iron Fist.",          37, 35, 8, 8, 10 },
	{ "You hit %s with a flying kick.",         41, 35, 8, 10, 12 },
	{ "You hit %s with a Dragon Fist.",         45, 35, 10, 10, 16 },
	{ "You hit %s with a Crushing Blow.",       48, 35, 10, 12, 18 },
#else
	{ "You punch %s.",                          1, 0, 1, 4, 0 },
	{ "You kick %s.",                           2, 0, 1, 6, 0 },
	{ "You strike %s.",                         3, 0, 1, 7, 0 },
	{ "You knee %s.",                           5, 5, 2, 3, MA_KNEE },
	{ "You hit %s.",                            7, 5, 1, 8, 0 },
	{ "You butt %s.",                           9, 10, 2, 5, 0 },
	{ "You kick %s.",                           11, 10, 3, 4, MA_SLOW },
	{ "You uppercut %s.",                       13, 12, 4, 4, 6 },
	{ "You double-kick %s.",                    16, 15, 5, 4, 8 },
	{ "You hit %s.",                            20, 20, 5, 5, 0 },
	{ "You kick %s.",                           25, 25, 5, 6, 10 },
	{ "You hit %s.",                            29, 25, 6, 6, 0 },
	{ "You kick %s.",                           33, 30, 6, 8, 10 },
	{ "You punch %s.",                          37, 35, 8, 8, 10 },
	{ "You kick %s.",                           41, 35, 8, 10, 12 },
	{ "You punch %s.",                          45, 35, 10, 10, 16 },
	{ "You punch %s.",                          48, 35, 10, 12, 18 },
#endif
};


magic_power mindcraft_powers[MAX_MINDCRAFT_POWERS] =
{
	/* Level gained,  cost,  %fail,  name */
        { 1,   1,  15, "Precognition", "Detect monsters, traps and level layout and lights up at higher levels." },          /* Det. monsters/traps */
        { 2,   1,  20, "Neural Blast", "Blast the minds of your foes." },          /* ~MM */
        { 3,   2,  25, "Minor Displacement", "Short distance teleportation" },    /* Phase/Between gate */
        { 7,   6,  35, "Major Displacement", "Teleport you and others at high levels." },    /* Tele. Self / All */
        { 9,   7,  50, "Domination", "Charm monsters" },
        { 11,  7,  30, "Pulverise", "Fires a bolt of pure sound." },             /* Telekinetic "bolt" */
        { 13, 12,  50, "Character Armour", "Sets up physical/elemental shield." },      /* Psychic/physical defences */
        { 15, 12,  60, "Psychometry", "Senses/identifies objects." },
        { 18, 10,  45, "Mind Wave", "Projects psi waves to crush the minds of your foes." },             /* Ball -> LOS */
        { 23, 15,  50, "Adrenaline Channeling", "Heals you, cures you and speeds you." },
        { 25, 10,  40, "Psychic Drain", "Drain your foes life into your mana reserves" },         /* Convert enemy HP to mana */
        { 28, 20,  45, "Telekinetic Wave", "Powerful wave of pure telekinetic forces." },      /* Ball -> LOS */
};

magic_power necro_powers[MAX_NECRO_POWERS] =
{
	/* Level gained,  cost,  %fail,  name */
        {  1,   2, 10, "Call Darkness", "Call upon the darkness to hurt your foes." },       /* Bolt/beam/ball/LOS of dark */
        {  5,   6, 20, "Raise Dead", "Brings back your foes in the form of various undead." },          /* Ball */
        { 25,  10, 25, "Summon Undead", "Call undead creatures(s) to your help." },       /* Summon one(some) undead(s) */
        { 30,  15, 20, "Vampirism", "Drain the life of your foes into your own." },           /* Bolt */
        { 35, 100, 25, "Death", "Instantly kills you opponent and you, turning yourself into an undead." },               /* The Death word, always bolt put your HP to 1 */
};

magic_power mimic_powers[MAX_MIMIC_POWERS] =
{
	/* Level gained,  cost,  %fail,  name */
        {  1,   2,  0, "Mimic", "Lets you use the powers of a Cloak of Mimicry." },               /* Use a book of lore */
        { 10,   6, 20, "Invisibility", "Hides you from the sight of mortals." },        /* Invisibility */
        { 25,  20, 25, "Legs Mimicry", "Temporary proves a new pair of legs." },        /* +1 pair of legs */
        { 30,  40, 30, "Wall Mimicry", "Temporary lets you walk in walls, and ONLY in walls." },        /* wall form */
        { 35, 100, 40, "Arms Mimicry", "Temporary proves a new pair of arms." },        /* +1 pair of arms, +1 weapon */
};

alchemist_recipe alchemist_recipes[MAX_ALCHEMIST_RECIPES] = {
        {SV_BATERIE_POISON,
                {
                        {EGO_BRAND_POIS,TV_SWORD,0,8},
                        {EGO_BRAND_POIS,TV_HAFTED,0,8},
                        {EGO_BRAND_POIS,TV_POLEARM,0,8},
                        {EGO_BRAND_POIS,TV_AXE,0,8},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                },
                {
                        {TV_BOTTLE,1,1,
                         TV_POTION,SV_POTION_POISON},
                        {TV_WAND,SV_WAND_NOTHING,1,
                         TV_WAND,SV_WAND_STINKING_CLOUD},
                        {TV_WAND,SV_WAND_STINKING_CLOUD,1,
                         TV_WAND,SV_WAND_STINKING_CLOUD},
                        {TV_RING,SV_RING_NOTHING,4,
                         TV_RING,SV_RING_RESIST_POIS},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                }
        },
        {SV_BATERIE_EXPLOSION,
                {
                        {EGO_SLAYING_WEAPON,TV_SWORD,ALCHEMIST_ENCHANT_DAM,8},
                        {EGO_SLAYING_WEAPON,TV_HAFTED,ALCHEMIST_ENCHANT_DAM,8},
                        {EGO_SLAYING_WEAPON,TV_POLEARM,ALCHEMIST_ENCHANT_DAM,8},
                        {EGO_SLAYING_WEAPON,TV_AXE,ALCHEMIST_ENCHANT_DAM,8},
                        {EGO_SLAYING,TV_GLOVES,ALCHEMIST_ENCHANT_DAM,8},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                },
                {
                        {TV_WAND,SV_WAND_NOTHING,1,
                         TV_WAND,SV_WAND_MAGIC_MISSILE},
                        {TV_BOTTLE,1,1,
                         TV_POTION,SV_POTION_DETONATIONS},
                        {TV_STAFF,SV_STAFF_NOTHING,2,
                         TV_STAFF,SV_STAFF_EARTHQUAKES},
                        {TV_SCROLL,SV_SCROLL_NOTHING,1,
                         TV_SCROLL,SV_SCROLL_DARKNESS},
                        {TV_WAND,SV_WAND_MAGIC_MISSILE,1,
                         TV_WAND,SV_WAND_MAGIC_MISSILE},
                        {TV_STAFF,SV_STAFF_EARTHQUAKES,2,
                         TV_STAFF,SV_STAFF_EARTHQUAKES},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                }
        },
        {SV_BATERIE_TELEPORT,
                {
                        {EGO_TELEPORTATION,TV_CROWN,0,7},
                        {EGO_TELEPORTATION,TV_HELM,0,7},
                        {EGO_DRAGON, TV_SWORD,ALCHEMIST_ENCHANT_PVAL,9},
                        {EGO_DRAGON, TV_HAFTED,ALCHEMIST_ENCHANT_PVAL,9},
                        {EGO_DRAGON, TV_POLEARM,ALCHEMIST_ENCHANT_PVAL,9},
                        {EGO_DRAGON, TV_AXE,ALCHEMIST_ENCHANT_PVAL,9},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                },
                {
                        {TV_SCROLL,SV_SCROLL_NOTHING,1,
                         TV_SCROLL,SV_SCROLL_TELEPORT},
                        {TV_ROD,SV_ROD_NOTHING,3,
                         TV_ROD,SV_ROD_TELEPORT_AWAY},
                        {TV_WAND,SV_WAND_NOTHING,1,
                         TV_WAND,SV_WAND_TELEPORT_AWAY},
                        {TV_WAND,SV_WAND_TELEPORT_AWAY,1,
                         TV_WAND,SV_WAND_TELEPORT_AWAY},
                        {TV_STAFF,SV_STAFF_NOTHING,1,
                         TV_STAFF,SV_STAFF_TELEPORTATION},
                        {TV_STAFF,SV_STAFF_TELEPORTATION,1,
                         TV_STAFF,SV_STAFF_TELEPORTATION},
                        {TV_RING,SV_RING_NOTHING,3,
                         TV_RING,SV_RING_TELEPORTATION},
                        {TV_AMULET,SV_AMULET_NOTHING,4,
                         TV_AMULET,SV_AMULET_TELEPORT},
                        {0,0,1,
                         0,0},
                }
        },
        {SV_BATERIE_ACID,
                {
                        {EGO_BRAND_ACID,TV_SWORD,0,8},
                        {EGO_BRAND_ACID,TV_HAFTED,0,8},
                        {EGO_BRAND_ACID,TV_POLEARM,0,8},
                        {EGO_BRAND_ACID,TV_AXE,0,8},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                },
                {
                        {TV_RING,SV_RING_NOTHING,8,
                         TV_RING,SV_RING_ACID},
                        {TV_WAND,SV_WAND_NOTHING,2,
                         TV_WAND,SV_WAND_ACID_BOLT},
                        {TV_WAND,SV_WAND_ACID_BOLT,2,
                         TV_WAND,SV_WAND_ACID_BOLT},
                        {TV_ROD,SV_ROD_NOTHING,5,
                         TV_ROD,SV_ROD_ACID_BOLT},
                        {TV_SCROLL,SV_SCROLL_NOTHING,1,
                         TV_SCROLL,SV_SCROLL_CURSE_ARMOR},
                        {TV_AMULET,SV_AMULET_NOTHING,2,
                         TV_AMULET,SV_AMULET_RESIST_ACID},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                }
        },
        {SV_BATERIE_COLD,
                {
                        {EGO_BRAND_COLD,TV_SWORD,0,8},
                        {EGO_BRAND_COLD,TV_HAFTED,0,8},
                        {EGO_BRAND_COLD,TV_POLEARM,0,8},
                        {EGO_BRAND_COLD,TV_AXE,0,8},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                },
                {
                        {TV_RING,SV_RING_NOTHING,8,
                         TV_RING,SV_RING_ICE},
                        {TV_WAND,SV_WAND_NOTHING,1,
                         TV_WAND,SV_WAND_COLD_BOLT},
                        {TV_WAND,SV_WAND_COLD_BOLT,1,
                         TV_WAND,SV_WAND_COLD_BOLT},
                        {TV_ROD,SV_ROD_NOTHING,4,
                         TV_ROD,SV_ROD_COLD_BOLT},
                        {TV_SCROLL,SV_SCROLL_NOTHING,1,
                         TV_SCROLL,SV_SCROLL_ICE},
                        {TV_BOTTLE,1,1,
                         TV_POTION,SV_POTION_RESIST_COLD},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                }
        },
        {SV_BATERIE_FIRE,
                {
                        {EGO_BRAND_FIRE,TV_SWORD,0,8},
                        {EGO_BRAND_FIRE,TV_HAFTED,0,8},
                        {EGO_AURA_FIRE,TV_CLOAK,0,9},
                        {EGO_BRAND_FIRE,TV_POLEARM,0,8},
                        {EGO_BRAND_FIRE,TV_AXE,0,8},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                },
                {
                        {TV_RING,SV_RING_NOTHING,8,
                         TV_RING,SV_RING_FLAMES},
                        {TV_WAND,SV_WAND_NOTHING,2,
                         TV_WAND,SV_WAND_FIRE_BOLT},
                        {TV_WAND,SV_WAND_FIRE_BOLT,2,
                         TV_WAND,SV_WAND_FIRE_BOLT},
                        {TV_ROD,SV_ROD_NOTHING,4,
                         TV_ROD,SV_ROD_FIRE_BOLT},
                        {TV_SCROLL,SV_SCROLL_NOTHING,1,
                         TV_SCROLL,SV_SCROLL_FIRE},
                        {TV_BOTTLE,1,1,
                         TV_POTION,SV_POTION_RESIST_HEAT},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                }
        },
        {SV_BATERIE_LIFE,
                {
                        {EGO_VAMPIRIC,TV_SWORD,0,12},
                        {EGO_VAMPIRIC,TV_HAFTED,0,12},
                        {EGO_VAMPIRIC,TV_POLEARM,0,12},
                        {EGO_VAMPIRIC,TV_AXE,0,12},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                },
                {
                        {TV_RING,SV_RING_NOTHING,5,
                         TV_RING,SV_RING_PROTECTION},
                        {TV_STAFF,SV_STAFF_NOTHING,2,
                         TV_STAFF,SV_STAFF_CURING},
                        {TV_STAFF,SV_STAFF_CURING,2,
                         TV_STAFF,SV_STAFF_CURING},
                        {TV_WAND,SV_WAND_NOTHING,2,
                         TV_WAND,SV_WAND_DRAIN_LIFE},
                        {TV_WAND,SV_WAND_DRAIN_LIFE,2,
                         TV_WAND,SV_WAND_DRAIN_LIFE},
                        {TV_ROD,SV_ROD_NOTHING,5,
                         TV_ROD,SV_ROD_CURING},
                        {TV_SCROLL,SV_SCROLL_NOTHING,1,
                         TV_SCROLL,SV_SCROLL_SATISFY_HUNGER},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                }
        },
        {SV_BATERIE_CONFUSION,
                {
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                },
                {
                        {TV_RING,SV_RING_NOTHING,2,
                         TV_RING,SV_RING_RES_CONFUSION},
                        {TV_WAND,SV_WAND_NOTHING,1,
                         TV_WAND,SV_WAND_CONFUSE_MONSTER},
                        {TV_WAND,SV_WAND_CONFUSE_MONSTER,1,
                         TV_WAND,SV_WAND_CONFUSE_MONSTER},
                        {TV_SCROLL,SV_SCROLL_NOTHING,1,
                         TV_SCROLL,SV_SCROLL_MONSTER_CONFUSION},
                        {TV_BOTTLE,1,1,
                         TV_POTION,SV_POTION_CONFUSION},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                }
        },
        {SV_BATERIE_LITE,
                {
                        {EGO_LITE,TV_CROWN,0,5},
                        {EGO_LITE,TV_HELM,0,5},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                },
                {
                        {TV_RING,SV_RING_NOTHING,6,
                         TV_RING,SV_RING_RES_LD},
                        {TV_STAFF,SV_STAFF_NOTHING,1,
                         TV_STAFF,SV_STAFF_LITE},
                        {TV_STAFF,SV_STAFF_LITE,1,
                         TV_STAFF,SV_STAFF_LITE},
                        {TV_WAND,SV_WAND_NOTHING,1,
                         TV_WAND,SV_WAND_LITE},
                        {TV_WAND,SV_WAND_LITE,1,
                         TV_WAND,SV_WAND_LITE},
                        {TV_ROD,SV_ROD_NOTHING,3,
                         TV_ROD,SV_ROD_ILLUMINATION},
                        {TV_SCROLL,SV_SCROLL_NOTHING,1,
                         TV_SCROLL,SV_SCROLL_LIGHT},
                        {TV_BOTTLE,1,2,
                         TV_POTION,SV_POTION_INFRAVISION},
                        {0,0,1,
                         0,0},
                }
        },
        {SV_BATERIE_CHAOS,
                {
                        {EGO_CHAOTIC,TV_SWORD,0,10},
                        {EGO_CHAOTIC,TV_HAFTED,0,10},
                        {EGO_CHAOTIC,TV_POLEARM,0,10},
                        {EGO_CHAOTIC,TV_AXE,0,10},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                },
                {
                        {TV_RING,SV_RING_NOTHING,5,
                         TV_RING,SV_RING_RES_CHAOS},
                        {TV_WAND,SV_WAND_NOTHING,4,
                         TV_WAND,SV_WAND_ANNIHILATION},
                        {TV_WAND,SV_WAND_ANNIHILATION,4,
                         TV_WAND,SV_WAND_ANNIHILATION},
                        {TV_ROD,SV_ROD_NOTHING,5,
                         TV_ROD,SV_ROD_POLYMORPH},
                        {TV_SCROLL,SV_SCROLL_NOTHING,2,
                         TV_SCROLL,SV_SCROLL_CHAOS},
                        {TV_BOTTLE,1,3,
                         TV_POTION,SV_POTION_MUTATION},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                }
        },
        {SV_BATERIE_TIME,
                {
                        {EGO_SPEED,TV_BOOTS,ALCHEMIST_ENCHANT_PVAL,13},
                        {EGO_RESISTANCE,TV_SOFT_ARMOR,0,10},
                        {EGO_RESISTANCE,TV_HARD_ARMOR,0,10},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                },
                {
                        {TV_RING,SV_RING_NOTHING,6,
                         TV_RING,SV_RING_SPEED},
                        {TV_STAFF,SV_STAFF_NOTHING,2,
                         TV_STAFF,SV_STAFF_SPEED},
                        {TV_STAFF,SV_STAFF_SPEED,2,
                         TV_STAFF,SV_STAFF_SPEED},
                        {TV_ROD,SV_ROD_NOTHING,9,
                         TV_ROD,SV_ROD_SPEED},
                        {TV_BOTTLE,1,33,
                         TV_POTION,SV_POTION_EXPERIENCE},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                }
        },
        {SV_BATERIE_MAGIC,
                {
                        {EGO_MAGI,TV_HELM,ALCHEMIST_ENCHANT_PVAL,10},
                        {EGO_MAGI,TV_CROWN,ALCHEMIST_ENCHANT_PVAL,10},
                        {EGO_JUMP,TV_BOOTS,0,6},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                },
                {
                        {TV_AMULET,SV_AMULET_NOTHING,6,
                         TV_AMULET,SV_AMULET_THE_MAGI},
                        {TV_RING,SV_RING_NOTHING,5,
                         TV_RING,SV_RING_INT},
                        {TV_STAFF,SV_STAFF_NOTHING,3,
                         TV_STAFF,SV_STAFF_THE_MAGI},
                        {TV_STAFF,SV_STAFF_THE_MAGI,3,
                         TV_STAFF,SV_STAFF_THE_MAGI},
                        {TV_ROD,SV_ROD_NOTHING,9,
                         TV_ROD,SV_ROD_IDENTIFY},
                        {TV_SCROLL,SV_SCROLL_NOTHING,99,
                         TV_SCROLL,SV_SCROLL_ARTIFACT},
                        {TV_BOTTLE,1,2,
                         TV_POTION,SV_POTION_RESTORE_MANA},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                }
        },
        {SV_BATERIE_XTRA_LIFE,
                {
                        {EGO_LIFE,TV_SWORD,ALCHEMIST_ENCHANT_PVAL,15},
                        {EGO_LIFE,TV_HAFTED,ALCHEMIST_ENCHANT_PVAL,15},
                        {EGO_LIFE,TV_POLEARM,ALCHEMIST_ENCHANT_PVAL,15},
                        {EGO_LIFE,TV_AXE,ALCHEMIST_ENCHANT_PVAL,15},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                },
                {
                        {TV_BOTTLE,1,2,
                         TV_POTION,SV_POTION_NEW_LIFE},
                        {TV_STAFF,SV_STAFF_NOTHING,2,
                         TV_STAFF,SV_STAFF_HEALING},
                        {TV_STAFF,SV_STAFF_HEALING,2,
                         TV_STAFF,SV_STAFF_HEALING},
                        {TV_WAND,SV_WAND_NOTHING,2,
                         TV_WAND,SV_WAND_CHARM_MONSTER},
                        {TV_WAND,SV_WAND_CHARM_MONSTER,2,
                         TV_WAND,SV_WAND_CHARM_MONSTER},
                        {TV_ROD,SV_ROD_NOTHING,5,
                         TV_ROD,SV_ROD_HEALING},
                        {TV_SCROLL,SV_SCROLL_NOTHING,3,
                         TV_SCROLL,SV_SCROLL_MASS_GENOCIDE},
                        {0,0,1,
                         0,0},
                        {0,0,1,
                         0,0},
                }
        },
        {SV_BATERIE_DARKNESS,
                {
                        {EGO_STEALTH,TV_CLOAK,ALCHEMIST_ENCHANT_PVAL,12},
                        {EGO_QUIET,TV_BOOTS,ALCHEMIST_ENCHANT_PVAL,12},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                },

                {
                        {TV_BOTTLE,1,2,
                         TV_POTION,SV_POTION_INVIS},
                        {TV_WAND,SV_WAND_NOTHING,1,
                         TV_WAND,SV_WAND_FEAR_MONSTER},
                        {TV_WAND,SV_WAND_FEAR_MONSTER,2,
                         TV_WAND,SV_WAND_FEAR_MONSTER},
                        {TV_STAFF,SV_STAFF_NOTHING,1,
                         TV_STAFF,SV_STAFF_DARKNESS},
                        {TV_STAFF,SV_STAFF_DARKNESS,1,
                         TV_STAFF,SV_STAFF_DARKNESS},
                        {TV_ROD,SV_ROD_NOTHING,6,
                         TV_ROD,SV_ROD_SLEEP_MONSTER},
                        {TV_RING,SV_RING_NOTHING,8,
                         TV_RING,SV_RING_INVIS},
                        {TV_AMULET,SV_AMULET_NOTHING,3,
                         TV_AMULET,SV_AMULET_DOOM},
                        {0,0,0,
                         0,0},
                },
        },
        {SV_BATERIE_KNOWLEDGE,
                {
                        {EGO_WISDOM,TV_CROWN,ALCHEMIST_ENCHANT_PVAL,8},
                        {EGO_WISDOM,TV_HELM,ALCHEMIST_ENCHANT_PVAL,8},
                        {EGO_BLESS_BLADE,TV_SWORD,ALCHEMIST_ENCHANT_PVAL,7},
                        {EGO_BLESS_BLADE,TV_HAFTED,ALCHEMIST_ENCHANT_PVAL,7},
                        {EGO_BLESS_BLADE,TV_POLEARM,ALCHEMIST_ENCHANT_PVAL,7},
                        {EGO_BLESS_BLADE,TV_AXE,ALCHEMIST_ENCHANT_PVAL,7},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                },

                {
                        {TV_BOTTLE,1,7,
                         TV_POTION,SV_POTION_SELF_KNOWLEDGE},
                        {TV_WAND,SV_WAND_NOTHING,2,
                         TV_WAND,SV_WAND_DISARMING},
                        {TV_WAND,SV_WAND_DISARMING,2,
                         TV_WAND,SV_WAND_DISARMING},
                        {TV_STAFF,SV_STAFF_NOTHING,3,
                         TV_STAFF,SV_STAFF_IDENTIFY},
                        {TV_STAFF,SV_STAFF_IDENTIFY,3,
                         TV_STAFF,SV_STAFF_IDENTIFY},
                        {TV_ROD,SV_ROD_NOTHING,7,
                         TV_ROD,SV_ROD_PROBING},
                        {TV_RING,SV_RING_NOTHING,5,
                         TV_RING,SV_RING_SEE_INVIS},
                        {TV_AMULET,SV_AMULET_NOTHING,6,
                         TV_AMULET,SV_AMULET_SEARCHING},
                        {TV_SCROLL,SV_SCROLL_NOTHING,2,
                         TV_SCROLL,SV_SCROLL_IDENTIFY},
                },
        },
        {SV_BATERIE_FORCE,
                {
                        {EGO_PROTECTION,TV_CLOAK,ALCHEMIST_ENCHANT_AC,6},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                },

                {
                        {TV_BOTTLE,1,7,
                         TV_POTION,SV_POTION_RESISTANCE},
                        {TV_WAND,SV_WAND_NOTHING,1,
                         TV_WAND,SV_WAND_STONE_TO_MUD},
                        {TV_WAND,SV_WAND_STONE_TO_MUD,1,
                         TV_WAND,SV_WAND_STONE_TO_MUD},
                        {TV_STAFF,SV_STAFF_NOTHING,2,
                         TV_STAFF,SV_STAFF_DESTRUCTION},
                        {TV_STAFF,SV_STAFF_DESTRUCTION,2,
                         TV_STAFF,SV_STAFF_DESTRUCTION},
                        {TV_ROD,SV_ROD_NOTHING,20,
                         TV_ROD,SV_ROD_HAVOC},
                        {TV_RING,SV_RING_NOTHING,8,
                         TV_RING,SV_RING_RES_SHARDS},
                        {TV_AMULET,SV_AMULET_NOTHING,2,
                         TV_AMULET,SV_AMULET_SLOW_DIGEST},
                        {TV_SCROLL,SV_SCROLL_NOTHING,2,
                         TV_SCROLL,SV_SCROLL_ENCHANT_ARMOR},
                },
        },
        {SV_BATERIE_LIGHTNING,
                {
                        {EGO_RESIST_ELEC,TV_SOFT_ARMOR,0,4},
                        {EGO_RESIST_ELEC,TV_HARD_ARMOR,0,4},
                        {EGO_ENDURE_ELEC,TV_SHIELD,0,4},
                        {EGO_BRAND_ELEC,TV_SWORD,0,9},
                        {EGO_BRAND_ELEC,TV_POLEARM,0,9},
                        {EGO_BRAND_ELEC,TV_HAFTED,0,9},
                        {EGO_LIGHTNING_BOLT,TV_SHOT,0,2},
                        {EGO_LIGHTNING_BOLT,TV_ARROW,0,2},
                        {EGO_LIGHTNING_BOLT,TV_BOLT,0,2},
                },

                {
                        {TV_BOTTLE,1,10,
                         TV_POTION,SV_POTION_ENLIGHTENMENT},
                        {TV_WAND,SV_WAND_NOTHING,2,
                         TV_WAND,SV_WAND_ELEC_BALL},
                        {TV_WAND,SV_WAND_ELEC_BALL,2,
                         TV_WAND,SV_WAND_ELEC_BALL},
                        {TV_STAFF,SV_STAFF_NOTHING,1,
                         TV_STAFF,SV_STAFF_STARLITE},
                        {TV_STAFF,SV_STAFF_STARLITE,1,
                         TV_STAFF,SV_STAFF_STARLITE},
                        {TV_ROD,SV_ROD_NOTHING,15,
                         TV_ROD,SV_ROD_ELEC_BALL},
                        {TV_RING,SV_RING_NOTHING,6,
                         TV_RING,SV_RING_RES_BLINDNESS},
                        {TV_AMULET,SV_AMULET_NOTHING,40,
                         TV_AMULET,SV_AMULET_REFLECTION},
                        {TV_SCROLL,SV_SCROLL_NOTHING,3,
                         TV_SCROLL,SV_SCROLL_RECHARGING},
                },
        },
        {SV_BATERIE_MANA,
                {
                        {EGO_FREE_ACTION,TV_GLOVES,0,15},
                        {EGO_MOTION,TV_BOOTS,0,15},
                        {EGO_DF,TV_SWORD,ALCHEMIST_ENCHANT_DAM | ALCHEMIST_ENCHANT_PVAL | ALCHEMIST_ENCHANT_AC,23},
                        {EGO_DF,TV_POLEARM,ALCHEMIST_ENCHANT_DAM | ALCHEMIST_ENCHANT_PVAL | ALCHEMIST_ENCHANT_AC,23},
                        {EGO_DF,TV_HAFTED,ALCHEMIST_ENCHANT_DAM | ALCHEMIST_ENCHANT_PVAL | ALCHEMIST_ENCHANT_AC,23},
                        {EGO_DF,TV_AXE,ALCHEMIST_ENCHANT_DAM | ALCHEMIST_ENCHANT_PVAL | ALCHEMIST_ENCHANT_AC,23},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                },

                {
                        {TV_BOTTLE,1,1,
                         TV_POTION,SV_POTION_SLEEP},
                        {TV_WAND,SV_WAND_NOTHING,1,
                         TV_WAND,SV_WAND_SLEEP_MONSTER},
                        {TV_WAND,SV_WAND_SLEEP_MONSTER,1,
                         TV_WAND,SV_WAND_SLEEP_MONSTER},
                        {TV_STAFF,SV_STAFF_NOTHING,2,
                         TV_STAFF,SV_STAFF_SLEEP_MONSTERS},
                        {TV_STAFF,SV_STAFF_SLEEP_MONSTERS,2,
                         TV_STAFF,SV_STAFF_SLEEP_MONSTERS},
                        {TV_ROD,SV_ROD_NOTHING,10,
                         TV_ROD,SV_ROD_MAPPING},
                        {TV_RING,SV_RING_NOTHING,6,
                         TV_RING,SV_RING_FREE_ACTION},
                        {TV_AMULET,SV_AMULET_NOTHING,15,
                         TV_AMULET,SV_AMULET_NO_MAGIC},
                        {TV_SCROLL,SV_SCROLL_NOTHING,3,
                         TV_SCROLL,SV_SCROLL_STAR_ENCHANT_WEAPON},
                },
        },
};
/*
        {SV_BATERIE_,
                {
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                        {0,0,0,1},
                },

                {
                        {0,0,0,
                         0,0},
                        {0,0,0,
                         0,0},
                        {0,0,0,
                         0,0},
                        {0,0,0,
                         0,0},
                        {0,0,0,
                         0,0},
                        {0,0,0,
                         0,0},
                        {0,0,0,
                         0,0},
                        {0,0,0,
                         0,0},
                        {0,0,0,
                         0,0},
                },
        },
*/

/*
 * Textual translation of your god's "niceness".
 */

cptr deity_niceness[10] = {
  "a lovable",
  "a friendly",
  "an easygoing",
  "a forgiving",
  "an uncaring",
  "a wary",
  "an unforgiving",
  "an impatient",
  "a wrathful",
  "an easily angered"
};

/*
 * Textual translation of your standing with your god.
 */

cptr deity_standing[11] = {
  "cursed",
  "persecuted",
  "punished",
  "despised",
  "disliked",
  "watched",
  "unnoticed",
  "noticed",
  "rewarded",
  "favored",
  "championed"
};

/*
 * Textual translations of your deity's rarity.
 */
cptr deity_rarity[2] = {
  "Major",
  "Supreme"
};

deity deity_info[MAX_GODS] = {
  { "Yavanna",   "Forest",     2, 0, RACE_ENT, -1, "The vala in charge of forests, she protects her followers from cold." },
  { "Ulmo",      "Waters",     3, 0, RACE_ELF, RACE_HUMAN, "The vala of water, he can protect the worthy from poison and sound." },
  { "Aule",      "Earth",      3, 0, RACE_DWARF, RACE_NIBELUNG, "The smith of the vala, associated with earth.  His followers are free to\nmove about the earth and will not be harmed by shards of earth." },
  { "Melkor",    "Darkness",   9, 0, RACE_HALF_ORC, RACE_HALF_TROLL, "Yes, this is Morgoth, the guy you're spending the entire game trying\nto whack.  But you can still worship him.  He grants sustains, and\nprotects his followers from several dark powers." },
  { "Tilion",    "Moon",       4, 0, RACE_ELF, RACE_DARK_ELF, "Vala of the moon, whose followers need fear neither the dark or the\ncreatures that dwell in it." },
  { "Arien",     "Sun",        3, 0, RACE_HUMAN, RACE_RKNIGHT, "Vala of the sun, whose followers have no fear during the day." },
  { "Tulkas",    "Rage",       8, 0, RACE_HUMAN, RACE_DWARF, "Vala of rage, his followers are mighty warriors, who cannot be\ndeceived in battle." },
  { "Manwe",     "Winds",      5, 0, RACE_HIGH_ELF, RACE_HALF_ELF, "Vala of the winds, his followers move with supernatural grace and swiftness." },
  { "Varda",     "Stars",      4, 0, RACE_DUNADAN, -1, "Vala of the stars, her followers have keen and clear minds." },

  { "Iluvatar",  "Being",      2, 1, RACE_ELF, RACE_HUMAN, "Also known as Eru, he is the creator, the God.  Those who\nfollow him are granted knowledge beyond that of ordinary mortals, but\nthey are so strongly connected to life that it is hard for them to kill\ndirectly." },
  { "The RNG",   "Randomness", 9, 1, RACE_MOLD, -1, "The god of chaos, it is as unpredictable and irrational as an\nAngband variant maintainer." },
};

/* jk - to hit, to dam, to ac, to stealth, to disarm, to saving throw */
/* this concept is taken from Adom, where Thomas Biskup thought it out, */
/* as far as I know. */
tactic_info_type tactic_info[9] =
{
/*     hit  dam   ac stl  dis  sav */
     { -10, -10, +15, +3, +15, +14, "coward"},           /* 4-4 */
     {  -8,  -8, +10, +2,  +9,  +9, "meek"},             /* 4-3 */
     {  -4,  -4,  +5, +1,  +5,  +5, "wary"},             /* 4-2 */
     {  -2,  -2,  +2, +1,  +2,  +2, "careful"},          /* 4-1 */
     {   0,   0,   0,  0,   0,   0, "normal"},           /* 4+0 */
     {   2,   2,  -2, -1,  -2,  -3, "confident"},        /* 4+1 */
     {   4,   4,  -5, -2,  -5,  -7, "aggressive"},       /* 4+2 */
     {   6,   6, -10, -3, -11, -12, "furious"},          /* 4+3 */
     {   8,  12, -25, -5, -18, -18, "berserker"}         /* 4+4 */
};

/*
 * Random artifact activations.
 */
activation activation_info[MAX_T_ACT] = {
  {"death",0,127},
  {"ruination",0,128},
  {"destruction",0,129},
  {"stupidity",0,130},
  {"weakness",0,131},
  {"unhealth",0,132},
  {"ugliness",0,133},
  {"clumsiness",0,134},
  {"naivete",0,135},
  {"stat loss",0,136},
  {"huge stat loss",0,137},
  {"experience loss",0,138},
  {"huge experience loss",0,139},
  {"teleportation",1000,125},
  {"monster summoning",5,140},
  {"paralyzation",0,141},
  {"hallucination",100,142},
  {"poisoning",0,143},
  {"hunger",0,144},
  {"stun",0,145},
  {"cuts",0,146},
  {"paranoia",0,147},
  {"confusion",0,148},
  {"blindness",0,149},
  {"pet summoning",1010,150},
  {"cure paralyzation",5000,151},
  {"cure hallucination",1000,152},
  {"cure poison",1000,83},
  {"cure hunger",1000,154},
  {"cure stun",1000,154},
  {"cure cut",1000,155},
  {"cure fear",1000,156},
  {"cure confusion",1000,158},
  {"cure blindness",1000,159},
  {"cure light wounds",500,81},
  {"cure serious wounds",750,82},
  {"cure critical wounds",1000,86},
  {"curing",1100,160},
  {"genocide",5000,57},
  {"mass genocide",10000,58},
  {"restoration",2000,85},
  {"light",1000,111},
  {"darkness",0,161},
  {"teleportation",1000,125},
  {"level teleportation",500,162},
  {"acquirement",30000,163},
  {"something weird",50,164},
  {"aggravation",0,165},
  {"corruption",100,166},
  {"cure insanity",2000,167},
  {"cure corruption",2000,168},
  {"light absortion",800,169},
};

/*
 * Possible Musics.
 */
music music_info[MAX_MUSICS] = {
  {"playing a song of freedom",MUSIC_BETWEEN,10,40,10,1,10},
  {"playing a charming song",MUSIC_CHARME,6,60,20,1,15},
  {"playing a knowledge song",MUSIC_ID,6,50,5,2,10},
  {"playing a *knowledge* song",MUSIC_STAR_ID,2,100,50,4,100}, /* Never random, only for the Harp of Master Robinton */
  {"playing a beautiful song",MUSIC_BEAUTY,10,100,20,1,90},
  {"playing a hiding song",MUSIC_HIDE,20,50,8,3,6},
  {"playing a song of brightness",MUSIC_LITE,60,20,4,1,5},
  {"playing a immaterial song",MUSIC_SHADOW,30,50,2,5,15},
  {"playing a song of the Valar",MUSIC_HOLY,20,100,20,6,15},
  {"playing a song of the Valar",MUSIC_HOLY,30,100,20,5,100}, /* Never random, only for the Drum of Piemur */
  {"playing a *charming* song",MUSIC_CHARME,20,100,20,1,100}, /* Never random, only for the Flute of Menolly */
};

/*
 * Possible movement type.
 */
move_info_type move_info[9] =
{
/*    speed, searching, stealth, perception */
    { -10,     17,        4,      20, "slug-like"},
    {  -8,     12,        4,      16, "very slow"},
    {  -6,      8,        3,      10, "slow"},
    {  -3,      4,        2,       6, "leisurely"},
    {   0,      0,        0,       0, "normal"},
    {   1,     -4,       -1,      -4, "brisk"},
    {   2,     -6,       -4,      -8, "fast"},
    {   3,    -10,       -7,     -14, "very fast"},
    {   4,    -16,      -10,     -20, "running"}
};

/*
 * Possible inscriptions type.
 */
inscription_info_type inscription_info[MAX_INSCRIPTIONS] =
{
        {       /* Nothing */
                "",
                0,
                TRUE,
                0,
        },
        {       /* Light up the room(Adunaic) */
                "ure nimir", /* sun shine */
                INSCRIP_EXEC_ENGRAVE | INSCRIP_EXEC_WALK | INSCRIP_EXEC_MONST_WALK,
                FALSE,
                30,
        },
        {       /* Darkness in room(Adunaic) */
                "lomi gimli", /* night stars */
                INSCRIP_EXEC_ENGRAVE | INSCRIP_EXEC_WALK | INSCRIP_EXEC_MONST_WALK,
                FALSE,
                10,
        },
        {       /* Storm(Adunaic) */
                "dulgi bawiba", /* black winds */
                INSCRIP_EXEC_ENGRAVE | INSCRIP_EXEC_WALK | INSCRIP_EXEC_MONST_WALK,
                FALSE,
                40,
        },
        {       /* Protection(Sindarin) */
                "pedo mellon a minno", /* say friend and enter */
                INSCRIP_EXEC_MONST_WALK,
                FALSE,
                8,
        },
        {       /* Dwarves summoning(Khuzdul) */
                "Baruk Khazad! Khazad aimenu!", /* Axes of the Dwarves, the Dwarves are upon you! */
                INSCRIP_EXEC_ENGRAVE,
                FALSE,
                100,
        },
        {       /* Open Chasm(Nandorin) */
                "dunna hrassa", /* black precipice */
                INSCRIP_EXEC_MONST_WALK,
                FALSE,
                50,
        },
        {       /* Blast of Black Fire(Orkish) */
                "burz ghash ronk", /* black fire pool */
                INSCRIP_EXEC_ENGRAVE | INSCRIP_EXEC_WALK | INSCRIP_EXEC_MONST_WALK,
                FALSE,
                60,
        },
};

/*
 * Inscriptions for pseudo-id
 */
cptr sense_desc[]= {"whoops","cursed","average","good","good","excellent",
                    "worthless","terrible","special","broken",""};

/*
 * Flag groups used for art creation, level gaining weapons, ...
 * -----
 * Name,
 * Price,
 * Flags 1,
 * Flags 2,
 * Flags 3,
 * Flags 4,
 * ESP,
 */
flags_group flags_groups[MAX_FLAG_GROUP] =
{
        {
                "Fire",
                1,
                TR1_SLAY_UNDEAD | TR1_BRAND_FIRE,
                TR2_RES_FIRE,
                TR3_SH_FIRE | TR3_LITE1 | TR3_IGNORE_FIRE,
                0,
                0,
        },
        {
                "Cold",
                1,
                TR1_SLAY_DRAGON | TR1_SLAY_DEMON | TR1_BRAND_COLD,
                TR2_RES_COLD | TR2_INVIS,
                TR3_SLOW_DIGEST | TR3_IGNORE_COLD,
                0,
                0,
        },
        {
                "Acid",
                1,
                TR1_SLAY_ANIMAL | TR1_IMPACT | TR1_TUNNEL | TR1_BRAND_ACID,
                TR2_RES_ACID,
                TR3_IGNORE_ACID,
                0,
                0,
        },
        {
                "Lightning",
                1,
                TR1_SLAY_EVIL | TR1_BRAND_ELEC,
                TR2_RES_ELEC,
                TR3_IGNORE_ELEC | TR3_SH_ELEC | TR3_TELEPORT,
                0,
                0,
        },
        {
                "Poison",
                2,
                TR1_CHR | TR1_VAMPIRIC | TR1_SLAY_ANIMAL | TR1_BRAND_POIS,
                TR2_SUST_CHR | TR2_RES_POIS,
                TR3_DRAIN_EXP,
                0,
                ESP_TROLL | ESP_GIANT,
        },
        {
                "Air",
                5,
                TR1_WIS | TR1_STEALTH | TR1_INFRA | TR1_SPEED,
                TR2_RES_LITE | TR2_RES_DARK | TR2_RES_BLIND | TR2_SUST_WIS,
                TR3_FEATHER | TR3_SEE_INVIS | TR3_BLESSED,
                0,
                ESP_GOOD,
        },
        {
                "Earth",
                5,
                TR1_STR | TR1_CON | TR1_TUNNEL | TR1_BLOWS | TR1_SLAY_TROLL | TR1_SLAY_GIANT | TR1_IMPACT,
                TR2_SUST_STR | TR2_SUST_CON | TR2_FREE_ACT | TR2_RES_FEAR | TR2_RES_SHARDS,
                TR3_REGEN,
                0,
                ESP_TROLL | ESP_GIANT,
        },
        {
                "Mind",
                7,
                TR1_INT | TR1_SEARCH,
                TR2_SUST_INT | TR2_RES_CONF | TR2_RES_FEAR,
                0,
                0,
                ESP_ORC | ESP_TROLL | ESP_GIANT | ESP_ANIMAL | ESP_UNIQUE | ESP_SPIDER | ESP_DEMON,
        },
        {
                "Shield",
                7,
                TR1_DEX,
                TR2_SUST_DEX | TR2_INVIS | TR2_REFLECT | TR2_HOLD_LIFE | TR2_RES_SOUND | TR2_RES_NEXUS,
                TR3_REGEN,
                0,
                0,
        },
        {
                "Chaos",
                7,
                TR1_CHAOTIC | TR1_IMPACT,
                TR2_RES_CHAOS | TR2_RES_DISEN,
                TR3_REGEN,
                0,
                ESP_ALL,
        },
        {
                "Magic",
                10,
                TR1_MANA | TR1_SPELL,
                TR2_RES_CHAOS | TR2_RES_DISEN,
                TR3_WRAITH,
                TR4_PRECOGNITION | TR4_FLY | TR4_CLONE,
                0,
        },
        {
                "Antimagic",
                10,
                TR1_VAMPIRIC | TR1_CHAOTIC | TR1_BLOWS | TR1_SPEED,
                TR2_LIFE | TR2_REFLECT | TR2_FREE_ACT | TR2_HOLD_LIFE,
                TR3_NO_MAGIC | TR3_NO_TELE | TR3_SEE_INVIS,
                TR4_ANTIMAGIC_10 | TR4_ANTIMAGIC_20,
                0,
        },
};

/* Power, the first 32 are the corruptions */
power_type powers_type[POWER_MAX] =
{
        {
                "spit acid",
                "You can spit acid.",
                "You gain the ability to spit acid.",
                "You lose the ability to spit acid.",
                9, 9, A_DEX, 15,
        },
        {
                "fire breath",
                "You can breath fire.",
                "You gain the ability to breathe fire.",
                "You lose the ability to breathe fire.",
                20, 10, A_CON, 18,
        },
        {
                "hypnotic gaze",
                "Your gaze is hypnotic.",
                "Your eyes look mesmerizing...",
                "Your eyes look uninteresting.",
                12, 12, A_CHR, 18,
        },
        {
                "telekinesis",
                "You are telekinetic.",
                "You gain the ability to move objects telekinetically.",
                "You lose the ability to move objects telekinetically.",
                9, 9, A_WIS, 14,
        },
        {
                "teleport",
                "You can teleport at will.",
                "You gain the power of teleportation at will.",
                "You lose the power of teleportation at will.",
                7, 7, A_WIS, 15,
        },
        {
                "mind blast",
                "You can mind blast your ennemies.",
                "You gain the power of Mind Blast.",
                "You lose the power of Mind Blast.",
                5, 3, A_WIS, 15,
        },
        {
                "emit radiation",
                "You can emit hard radiation at will.",
                "You start emitting hard radiation.",
                "You stop emitting hard radiation.",
                15, 15, A_CON, 14,
        },
        {
                "vampiric drain",
                "You can drain life from a foe.",
                "You become vampiric.",
                "You are no longer vampiric.",
                4, 5, A_CON, 14,
        },
        {
                "smell metal",
                "You can smell nearby precious metal.",
                "You smell a metallic odor.",
                "You no longer smell a metallic odor.",
                3, 2, A_INT, 12,
        },
        {
                "smell monsters",
                "You can smell nearby monsters.",
                "You smell filthy monsters.",
                "You no longer smell filthy monsters.",
                5, 4, A_INT, 15,
        },
        {
                "blink",
                "You can teleport yourself short distances.",
                "You gain the power of minor teleportation.",
                "You lose the power of minor teleportation.",
                3, 3, A_WIS, 12,
        },
        {
                "eat rock",
                "You can consume solid rock.",
                "The walls look delicious.",
                "The walls look unappetizing.",
                8, 12, A_CON, 18,
        },
        {
                "swap position",
                "You can switch locations with another being.",
                "You feel like walking a mile in someone else's shoes.",
                "You feel like staying in your own shoes.",
                15, 12, A_DEX, 16,
        },
        {
                "shriek",
                "You can emit a horrible shriek.",
                "Your vocal cords get much tougher.",
                "Your vocal cords get much weaker.",
                4, 4, A_CON, 6,
        },
        {
                "illuminate",
                "You can emit bright light.",
                "You can light up rooms with your presence.",
                "You can no longer light up rooms with your presence.",
                3, 2, A_INT, 10,
        },
        {
                "detect curses",
                "You can feel the danger of evil magic.",
                "You can feel evil magics.",
                "You can no longer feel evil magics.",
                7, 14, A_WIS, 14,
        },
        {
                "berserk",
                "You can drive yourself into a berserk frenzy.",
                "You feel a controlled rage.",
                "You no longer feel a controlled rage.",
                8, 8, A_STR, 14,
        },
        {
                "polymorph",
                "You can polymorph yourself at will.",
                "Your body seems mutable.",
                "Your body seems stable.",
                18, 20, A_CON, 18,
        },
        {
                "midas touch",
                "You can turn ordinary items to gold.",
                "You gain the Midas touch.",
                "You lose the Midas touch.",
                10, 5, A_INT, 12,
        },
        {
                "grow mold",
                "You can cause mold to grow near you.",
                "You feel a sudden affinity for mold.",
                "You feel a sudden dislike for mold.",
                1, 6, A_CON, 14,
        },
        {
                "resist elements",
                "You can harden yourself to the ravages of the elements.",
                "You feel like you can protect yourself.",
                "You feel like you might be vulnerable.",
                10, 12, A_CON, 12,
        },
        {
                "earthquake",
                "You can bring down the dungeon around your ears.",
                "You gain the ability to wreck the dungeon.",
                "You lose the ability to wreck the dungeon.",
                12, 12, A_STR, 16,
        },
        {
                "eat magic",
                "You can consume magic energy for your own use.",
                "Your magic items look delicious.",
                "Your magic items no longer look delicious.",
                17, 1, A_WIS, 15,
        },
        {
                "weigh magic",
                "You can feel the strength of the magics affecting you.",
                "You feel you can better understand the magic around you.",
                "You no longer sense magic.",
                6, 6, A_INT, 10,
        },
        {
                "sterilize",
                "You can cause mass impotence.",
                "You can give everything around you a headache.",
                "You hear a massed sigh of relief.",
                20, 40, A_CHR, 18,
        },
        {
                "panic hit",
                "You can run for your life after hitting something.",
                "You suddenly understand how thieves feel.",
                "You no longer feel jumpy.",
                10, 12, A_DEX, 14,
        },
        {
                "dazzle",
                "You can emit confusing, blinding radiation.",
                "You gain the ability to emit dazzling lights.",
                "You lose the ability to emit dazzling lights.",
                7, 15, A_CHR, 8,
        },
        {
                "spear of darkness",
                "You can create a spear of darkness.",
                "An illusory spear of darkness appears in your hand.",
                "The spear of darkness disappear.",
                7, 10, A_WIS, 9,
        },
        {
                "recall",
                "You can travel between towns and the depths.",
                "You feel briefly homesick, but it passes.",
                "You feel briefly homesick.",
                17, 50, A_INT, 16,
        },
        {
                "banish evil",
                "You can send evil creatures directly to Nether Realm.",
                "You feel a holy wrath fill you.",
                "You no longer feel a holy wrath.",
                25, 25, A_WIS, 18,
        },
        {
                "cold touch",
                "You can freeze things with a touch.",
                "Your hands get very cold.",
                "Your hands warm up.",
                2, 2, A_CON, 11,
        },
        {
                "throw object",
                "You can hurl objects with great force.",
                "Your throwing arm feels much stronger.",
                "Your throwing arm feels much weaker.",
                1, 10, A_STR, 6,
        },

        /* Others */
        {
                "find secret passages",
                "You can use secret passages.",
                "You sudently notice lots of hidden ways.",
                "You no longer can use hidden ways.",
                15, 15, A_DEX, 12,
        },
        {
                "detect doors and traps",
                "You can detect hidden doors and traps.",
                "You grow an affinity for traps.",
                "You no longer can detect hidden doors and traps.",
                5, 5, A_WIS, 10,
        },
        {
                "create food",
                "You can create food.",
                "Your cooking skills greatly improves.",
                "Your cooking skills returns to a normal level.",
                15, 10, A_INT, 10,
        },
        {
                "remove fear",
                "You can bolden yourself.",
                "You feel your fears lessening.",
                "You feel your fears growing again.",
                3, 5, A_WIS, 8,
        },
        {
                "set explosive rune",
                "You can set explosive runes.",
                "You suddently understand how explosive runes work.",
                "You suddently forget how explosive runes work.",
                25, 35, A_INT, 15,
        },
        {
                "stone to mud",
                "You can destroy walls.",
                "You could destroy walls.",
                "You cannot destroy walls anymore.",
                20, 10, A_STR, 12,
        },
        {
                "poison dart",
                "You can throw poisoned darts.",
                "You get an infinite supply of poisoned darts.",
                "You lose your infinite supply of poisoned darts.",
                12, 8, A_DEX, 14,
        },
        {
                "magic missile",
                "You can cast magic missiles.",
                "You suddently understand the basics of magic.",
                "You forgot the basics of magic.",
                2, 2, A_INT, 9,
        },
        {
                "grow trees",
                "You can grow trees.",
                "You feel an afinity for trees.",
                "You no longer feel an afinity for trees.",
                2, 6, A_CHR, 3,
        },
        {
                "cold breath",
                "You can breath cold.",
                "You gain the ability to breathe cold.",
                "You lose the ability to breathe cold.",
                20, 10, A_CON, 18,
        },
        {
                "chaos breath",
                "You can breath chaos.",
                "You gain the ability to breathe chaos.",
                "You lose the ability to breathe chaos.",
                20, 10, A_CON, 18,
        },
        {
                "elemental breath",
                "You can breath the elements.",
                "You gain the ability to breathe the elements.",
                "You lose the ability to breathe the elements.",
                20, 10, A_CON, 18,
        },
        {
                "change the world",
                "You can wreck the world around you.",
                "You gain the ability to wreck the world.",
                "You lose the ability to wreck the world.",
                1, 30, A_CHR, 6,
        },
        {
                "scare monster",
                "You can scare monsters.",
                "You gain the ability to scare monsters.",
                "You lose the ability to scare monsters.",
                4, 3, A_INT, 3,
        },
        {
                "restore life",
                "You can restore lost life forces.",
                "You gain the ability to restore your life force.",
                "You lose the ability to restore your life force.",
                30, 30, A_WIS, 18,
        },
        {
                "summon monsters",
                "You can call upon monsters.",
                "You gain the ability to call upon monsters.",
                "You lose the ability to call upon monsters.",
                0, 0, 0, 0,
        },
        {
                "necromantic powers",
                "You can use the foul necromantic magic.",
                "You gain the ability to use the foul necromantic magic.",
                "You lose the ability to use the foul necromantic magic.",
                0, 0, 0, 0,
        },
        {
                "Rohan's Knight's Powers",
                "You can use rohir powers.",
                "You gain the ability to use rohir powers.",
                "You lose the ability to use rohir powers.",
                0, 0, 0, 0,
        },
        {
                "Dragon's Powers",
                "You can use perniese dragon powers.",
                "You gain the ability to use perniese dragon powers.",
                "You lose the ability to use perniese dragon powers.",
                0, 0, 0, 0,
        },
        {
                "Death Mold's Powers",
                "You can use the foul deathmold magic.",
                "You gain the ability to use the foul deathmold magic.",
                "You lose the ability to use the foul deathmold magic.",
                0, 0, 0, 0,
        },
        {
                "Hypnotize Pet",
                "You can mystify pets.",
                "You gain the ability to mystify pets.",
                "You lose the ability to mystify pets.",
                0, 0, 0, 0,
        },
        {
                "Awaken hypnotized pet",
                "You can wake up a pet.",
                "You gain the ability to wake up a pet.",
                "You lose the ability to wake up a pet.",
                0, 0, 0, 0,
        },
        {
                "Incarnate",
                "You can incarnate into a body.",
                "You feel the need to get a body.",
                "You no longer feel the need for a new body.",
                0, 0, 0, 0,
        },
        {
                "magic map",
                "You can sense what is beyond walls.",
                "You feel you can sense what is beyond walls.",
                "You no longer can sense what is beyond walls.",
                7, 10, A_WIS, 15,
        },
        {
                "lay trap",
                "You can lay monster traps.",
                "You suddently understand how rogues work.",
                "You no longer suddently understand how rogues work.",
                1, 1, A_DEX, 1,
        },
        {
                "Merchant abilities",
                "You can request items and get loans.",
                "From now on you can use the merchant abilities.",
                "You can no longer use the merchant abilities.",
                0, 0, 0, 0,
        },
        {
                "turn pet into companion",
                "You can turn a pet into a companion.",
                "You suddently gain authority over your pets..",
                "You can no longer convert pets into companions.",
                2, 10, A_CHR, 10,
        },
};

/*
 * The Quests
 */
quest_type quest[MAX_Q_IDX] =
{
        {
                FALSE,
                NULL,
                {
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                },
                QUEST_STATUS_UNTAKEN,
                0,

                NULL,
                quest_null_hook,
                {0, 0},
        },
        {
                FALSE,
                "Dol Guldur",
                {
                        "The forest of Mirkwood is a very dangerous place to go, mainly due to",
                        "the activities of the Necromancer that lurks in Dol Guldur.",
                        "Find him, and free Mirkwood from his spells.",
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                },
                QUEST_STATUS_TAKEN,
                70,

                &plots[PLOT_MAIN],
                quest_necro_init_hook,
                {0, 0},
        },
        {
                FALSE,
                "Sauron",
                {
                        "It is time to take the battle to Morgoth. But, before you can",
                        "reach it, you must find and kill Sauron.  Only after defeating",
                        "the powerful sorcerer will the stairs leading to the Morgoth's",
                        "room be opened.",
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                },
                QUEST_STATUS_UNTAKEN,
                99,

                &plots[PLOT_MAIN],
                quest_sauron_init_hook,
                {0, 0},
        },
        {
                FALSE,
                "Morgoth",
                {
                        "Your final quest is the ultimate quest that has always been",
                        "required of you. You must enter the last level of Angband, where",
                        "Morgoth is waiting. Travel deep, and defeat this source of all our",
                        "problems.Be prepared, be patient, and good luck. May the light",
                        "shine on you.",
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                },
                QUEST_STATUS_UNTAKEN,
                100,

                &plots[PLOT_MAIN],
                quest_morgoth_init_hook,
                {0, 0},
        },

        /* Bree plot */
        {
                FALSE,
                "Thieves!!!",
                {
                        "There are thieves robbing my people! They live in a small",
                        "burrow outside the city walls robbing people as they pass",
                        "on the roads. They even sneak inside the town to mug and",
                        "pillage! Your task is to go to the burrow and kill these",
                        "ruffians.",
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                },
                QUEST_STATUS_UNTAKEN,
                5,

                &plots[PLOT_BREE],
                quest_thieves_init_hook,
                {0, 0},
        },

        {
                FALSE,
                "Random Quest",
                {
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                },
                QUEST_STATUS_UNTAKEN,
                5,

                NULL,
                quest_random_init_hook,
                {0, 0},
        },

        {
                FALSE,
                "Lost Hobbit",
                {
                        "Merton Proundfoot, a young hobbit, seems to have disappeared.",
                        "Last time someone saw him was near the horrible maze to the south...",
                        "I fear he got lost in there, please find him!",
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                },
                QUEST_STATUS_UNTAKEN,
                25,

                &plots[PLOT_BREE],
                quest_hobbit_init_hook,
                {0, 0},
        },

        {
                FALSE,
                "The Dark Horseman",
                {
                        "A dark cloaked horseman has been spoted several time in town.",
                        "He carries an aura of fear with him and people seems to get sick",
                        "here he goes. Please do something, but beware...",
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                },
                QUEST_STATUS_UNTAKEN,
                40,

                &plots[PLOT_BREE],
                quest_nazgul_init_hook,
                {0, 0},
        },

        {
                FALSE,
                "The Trolls Glade",
                {
                        "A group of Forest Trolls settled in an abandoned fortress in the",
                        "south. They are killing our people, so it's your mission to put",
                        "an end to this! You may only find them when night comes...",
                        "Local hobbits claim that the mighty swords Orcrist and Glamdring",
                        "can be found there! Bring back one of them as a proof!",
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                },
                QUEST_STATUS_UNTAKEN,
                30,

                &plots[PLOT_BREE],
                quest_troll_init_hook,
                {FALSE, 0},
        },

        {
                FALSE,
                "The Wight Grave",
                {
                        "The Barrow-Downs hides lots of mysteries and dangers...",
                        "Lately lots of people, men and hobbits, have disappeared there.",
                        "Please put an end to this threat!",
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                },
                QUEST_STATUS_UNTAKEN,
                30,

                &plots[PLOT_BREE],
                quest_wight_init_hook,
                {FALSE, 0},
        },

        /* Lorien plot */
        {
                FALSE,
                "Spiders of Mirkwood",
                {
                        "Powers lurk deep within Mirkwood. Spiders have blocked the",
                        "path through the forest, and Thranduil's folk have been",
                        "unable to hold them off. It is your task to drive them",
                        "away. Be careful -- many traps have been laid by their",
                        "webs, and their venom is dangerous indeed.",
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                },
                QUEST_STATUS_UNTAKEN,
                25,

                &plots[PLOT_LORIEN],
                quest_spider_init_hook,
                {0, 0},
        },
        {
                FALSE,
                "Poisoned water",
                {
                        "A curse has beset Lothlorien. All trees along the shorelines of Nimrodel",
                        "are withering away. We fear it would spread to the whole forest. The",
                        "cause seems to be an unknown poison. You are to go to the West and travel",
                        "along Celebrane and Nimrodel until you discover the source of poisoning.",
                        "Then you must destroy it and drop these potions on the tainted water.",
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                },
                QUEST_STATUS_UNTAKEN,
                30,

                &plots[PLOT_LORIEN],
                quest_poison_init_hook,
                {0, 0},
        },
        /* Other quests */
        {
                FALSE,
                "The Broken Sword",
                {
                        "You have found Narsil, a broken sword. It is said that the sword that",
                        "was broken shall be reforged... Maybe it is this one.",
                        "You should bring it to Aragorn at Minas Anor, he would sure know.",
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                },
                QUEST_STATUS_UNTAKEN,
                20,

                &plots[PLOT_OTHER],
                quest_narsil_init_hook,
                {0, 0},
        },
        /* Gondolin plot */
        {
                FALSE,
                "Eol the Dark Elf",
                {
                        "We have disturbing tidings. Eol the Dark Elf has come seeking his kin in",
                        "Gondolin. We cannot let anyone pass the borders of the city without the",
                        "King's leave. Go forth to the eastern mountains and apprehend him. If",
                        "he resists, use whatever means possible to hinder him from reaching the",
                        "city. Be wary -- the mountain caves may have many hidden traps.",
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                },
                QUEST_STATUS_UNTAKEN,
                30,

                &plots[PLOT_GONDOLIN],
                quest_eol_init_hook,
                {0, 0},
        },
        {
                FALSE,
                "Nirnaeth Arnoediad",
                {
                        "The fortunes of war in the north turn against us.",
                        "Morgoth's treachery has driven our armies back nigh",
                        "to the city's walls. Go forth from the city gates",
                        "and clear a path for them to retreat. You need not",
                        "destroy the troll army, simply drive a path through.",
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                },
                QUEST_STATUS_UNTAKEN,
                37,

                &plots[PLOT_GONDOLIN],
                quest_nirnaeth_init_hook,
                {0, 0},
        },
        {
                FALSE,
                "Invasion of Gondolin",
                {
                        "Morgoth is upon us! Dragons and Balrogs have poured over secret",
                        "ways of the Echoriath, and are looking for our city. They are",
                        "conducted by Maeglin! You must stop him or they will find us."
                        "Do not let maeglin get to the stairs or everything will be lost!",
                        "Go now, be brave.",
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                },
                QUEST_STATUS_UNTAKEN,
                80,

                &plots[PLOT_GONDOLIN],
                quest_invasion_init_hook,
                {0, 0},
        },
        {
                FALSE,
                "The Last Alliance",
                {
                        "The armies of Morgoth are closing in on the last remaining strongholds",
                        "of resistance against him. We are too far apart to help each other.",
                        "The arrival of our new Dragonrider allies has helped, but can only delay",
                        "the inevitable. We must be able to stand together and reinforce each other,",
                        "or both our kingdoms will fall separately. The Dragonriders have taught us",
                        "how to use the Between: we need you to open a Between gate in our own city,",
                        "and that of Gondolin.",
                        "Simply travel to gondolin, but beware of rebel dragonriders.",
                        NULL,
                        NULL,
                },
                QUEST_STATUS_UNTAKEN,
                60,

                &plots[PLOT_MINAS],
                quest_between_init_hook,
                {0, 0},
        },
        {
                FALSE,
                "The One Ring",
                {
                        "Find the One Ring, then bring it to Mount Doom, in Mordor to drop",
                        "it in the Great Fire where it was once forged.",
                        "But beware, *NEVER* use it, or you will be corrupted.",
                        "Once destroyed you will be able to permanently defeat Sauron.",
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                },
                QUEST_STATUS_UNTAKEN,
                99,

                &plots[PLOT_MAIN],
                quest_one_init_hook,
                {0, 0},
        },
};

/* List of powers for Symbiants/Powers */
monster_power monster_powers[96] =
{
        { RF4_SHRIEK, "Aggravate Monster", 1, FALSE },
        { RF4_MULTIPLY, "Multiply", 10, FALSE },
        { RF4_S_ANIMAL, "Summon Animal", 30, FALSE },
        { RF4_ROCKET, "Fire a Rocket", 40, TRUE },
        { RF4_ARROW_1, "Light Arrow", 1, FALSE },
        { RF4_ARROW_2, "Minor Arrow", 3, FALSE },
        { RF4_ARROW_3, "Major Arrow", 7, TRUE },
        { RF4_ARROW_4, "Great Arrow", 9, TRUE },
        { RF4_BR_ACID, "Breathe Acid", 10, FALSE },
        { RF4_BR_ELEC, "Breathe Lightning", 10, FALSE },
        { RF4_BR_FIRE, "Breathe Fire", 10, FALSE },
        { RF4_BR_COLD, "Breathe Cold", 10, FALSE },
        { RF4_BR_POIS, "Breathe Poison", 15, TRUE },
        { RF4_BR_NETH, "Breathe Nether", 30, TRUE },
        { RF4_BR_LITE, "Breathe Lite", 20, TRUE },
        { RF4_BR_DARK, "Breathe Dark", 20, TRUE },
        { RF4_BR_CONF, "Breathe Confusion", 15, TRUE },
        { RF4_BR_SOUN, "Breathe Sound", 30, TRUE },
        { RF4_BR_CHAO, "Breathe Chaos", 30, TRUE },
        { RF4_BR_DISE, "Breathe Disenchantment", 30, TRUE },
        { RF4_BR_NEXU, "Breathe Nexus", 30, TRUE },
        { RF4_BR_TIME, "Breathe Time", 30, TRUE },
        { RF4_BR_INER, "Breathe Inertia", 30, TRUE },
        { RF4_BR_GRAV, "Breathe Gravity", 30, TRUE },
        { RF4_BR_SHAR, "Breathe Shards", 30, TRUE },
        { RF4_BR_PLAS, "Breathe Plasma", 30, TRUE },
        { RF4_BR_WALL, "Breathe Force", 30, TRUE },
        { RF4_BR_MANA, "Breathe Mana", 40, TRUE },
        { RF4_BA_NUKE, "Nuke Ball", 30, TRUE },
        { RF4_BR_NUKE, "Breathe Nuke", 40, TRUE },
        { RF4_BA_CHAO, "Chaos Ball", 30, TRUE },
        { RF4_BR_DISI, "Breathe Disintegration", 40, TRUE },

        { RF5_BA_ACID, "Acid Ball", 8, FALSE },
        { RF5_BA_ELEC, "Lightning Ball", 8, FALSE },
        { RF5_BA_FIRE, "Fire Ball", 8, FALSE },
        { RF5_BA_COLD, "Cold Ball", 8, FALSE },
        { RF5_BA_POIS, "Poison Ball", 20, TRUE },
        { RF5_BA_NETH, "Nether Ball", 20, TRUE },
        { RF5_BA_WATE, "Water Ball", 20, TRUE },
        { RF5_BA_MANA, "Mana Ball", 50, TRUE },
        { RF5_BA_DARK, "Darkness Ball", 20, TRUE },
        { 0, "(none)", 0, FALSE },
        { 0, "(none)", 0, FALSE },
        { 0, "(none)", 0, FALSE },
        { RF5_CAUSE_1, "Cause Light Wounds", 20, FALSE },
        { RF5_CAUSE_2, "Cause Medium Wounds", 30, FALSE },
        { RF5_CAUSE_3, "Cause Critical Wounds", 35, TRUE },
        { RF5_CAUSE_4, "Cause Mortal Wounds", 45, TRUE },
        { RF5_BO_ACID, "Acid Bolt", 5, FALSE },
        { RF5_BO_ELEC, "Lightning Bolt", 5, FALSE },
        { RF5_BO_FIRE, "Fire Bolt", 5, FALSE },
        { RF5_BO_COLD, "Cold Bolt", 5, FALSE },
        { RF5_BO_POIS, "Poison Bolt", 10, TRUE },
        { RF5_BO_NETH, "Nether Bolt", 15, TRUE },
        { RF5_BO_WATE, "Water Bolt", 20, TRUE },
        { RF5_BO_MANA, "Mana Bolt", 25, TRUE },
        { RF5_BO_PLAS, "Plasma Bolt", 20, TRUE },
        { RF5_BO_ICEE, "Ice Bolt", 20, TRUE },
        { RF5_MISSILE, "Magic Missile", 1, FALSE },
        { RF5_SCARE, "Scare", 4, FALSE },
        { RF5_BLIND, "Blindness", 6, FALSE },
        { RF5_CONF, "Confusion", 7, FALSE },
        { RF5_SLOW, "Slowness", 10, FALSE },
        { RF5_HOLD, "Paralyse", 10, FALSE },

        { RF6_HASTE, "Haste Self", 50, FALSE },
        { RF6_HAND_DOOM, "Hand of Doom", 30, TRUE },
        { RF6_HEAL, "Healing", 60, FALSE },
        { RF6_S_ANIMALS, "Summon Animals", 60, TRUE },
        { RF6_BLINK, "Phase Door", 2, FALSE },
        { RF6_TPORT, "Teleport", 10, FALSE },
        { RF6_TELE_TO, "Teleport To", 20, TRUE },
        { RF6_TELE_AWAY, "Teleport Away", 20, FALSE },
        { RF6_TELE_LEVEL, "Teleport Level", 20, TRUE },
        { RF6_DARKNESS, "Darkness", 3, FALSE },
        { RF6_TRAPS, "Create Traps", 10, TRUE },
        { 0, "(none)", 0, FALSE },
        { RF6_RAISE_DEAD, "Raise the Dead", 400, TRUE },
        { 0, "(none)", 0, FALSE },
        { 0, "(none)", 0, FALSE },
        { RF6_S_DRAGONRIDDER, "Summon DragonRiders", 90, TRUE },
        { RF6_S_KIN, "Summon Kin", 80, FALSE },
        { RF6_S_HI_DEMON, "Summon Greater Demons", 90, TRUE },
        { RF6_S_MONSTER, "Summon Monster", 50, FALSE },
        { RF6_S_MONSTERS, "Summon Monsters", 60, TRUE },
        { RF6_S_ANT, "Summon Ants", 30, FALSE },
        { RF6_S_SPIDER, "Summon Spider", 30, FALSE },
        { RF6_S_HOUND, "Summon Hound", 50, TRUE },
        { RF6_S_HYDRA, "Summon Hydra", 40, TRUE },
        { RF6_S_ANGEL, "Summon Angel", 60, TRUE },
        { RF6_S_DEMON, "Summon Demon", 60, TRUE },
        { RF6_S_UNDEAD, "Summon Undead", 70, TRUE },
        { RF6_S_DRAGON, "Summon Dragon", 70, TRUE },
        { RF6_S_HI_UNDEAD, "Summon High Undead", 90, TRUE },
        { RF6_S_HI_DRAGON, "Summon High Dragon", 90, TRUE },
        { RF6_S_WRAITH, "Summon Wraith", 90, TRUE },
        { 0, "(none)", 0, FALSE },
};

/* Tval descriptions */
tval_desc tval_descs[] =
{
        {TV_BATERIE, "Essenses contain the primitive magic forces which enable Alchemists using them to create powerful magic items from other magic items."},
        {TV_MSTAFF, "Mage Staves are the weapons of predilection of spellcasters, they all reduce spellcasting time to 80% of normal time and some will yield even greater powers."},
        {TV_FIRESTONE, "DragonRiders can feed their dragons with firestone to allow them to breath fire."},
        {TV_PARCHEMENT, "Parchments can contain useful information ... or useless junk."},
        {TV_EGG, "Eggs are laid by some monsters, if they hatch in your inventory the monster will be your friend."},
        {TV_TOOL, "Tools can be diggers, climbing equipment and such, they have their own slot in your inventory."},
        {TV_INSTRUMENT, "All instruments have a special magical song in them, activate them to play it. Harpers can use them to have two songs at a time."},
        {TV_BOOMERANG, "Boomerangs can be used instead of bows or slings, they are more like melee weapons than bows."},
        {TV_SHOT, "Shots are the standard ammunition for slings, you can wear them in your quiver if your have a sling equiped."},
        {TV_ARROW, "Arrows are the standard ammunition for bows, you can wear them in your quiver if your have a bow equiped."},
        {TV_BOLT, "Bolts are the standard ammunition for crossbows, you can wear them in your quiver if your have a crossbow equiped."},
        {TV_BOW, "Slings, bows and crossbows are used to attack monsters from a distance."},
        {TV_DIGGING, "Tools can be diggers, climbing equipment and such, they have their own slot in your inventory."},
        {TV_HAFTED, "Hafted weapons are melee weapons. Priests can use them without penalities."},
        {TV_SWORD, "Swords are melee weapons."},
        {TV_AXE, "Axes are melee weapons."},
        {TV_POLEARM, "Polearms are melee weapons."},
        {TV_DRAG_ARMOR, "Dragon armors are made from the scales of dead dragons, those mighty armors usually yield great power to their wearer."},
        {TV_LITE, "Ligths are useful for they allow you to read things and see from afar. Some of them need to be refilled, some do not."},
        {TV_AMULET, "Amulets are fine pieces of jewelry, usualy imbued with arcane magics."},
        {TV_RING, "Rings are fine pieces of jewelry, usualy imbued with arcane magics."},
        {TV_TRAPKIT, "Trapping kits are used by rogues to set deadly monster traps."},
        {TV_STAFF, "Staves are objects imbued with mystical powers."},
        {TV_WAND, "Wands are like small staves and usually have a targetted effect."},
        {TV_ROD, "Rod tips are the physical bindings of some powerful spells, zap (attach) them to a rod to get a fully functionnal rod. Each spell takes some mana from the rod it is attached to to work."},
        {TV_ROD_MAIN, "Rods contain mana reserves used to cast spells in rod tips, zap(attach) a rod tip to them to get a fully functionnal rod. Each spell takes some mana from the rod it is attached to to work."},
        {TV_SCROLL, "Scrolls are magical parchments, imbued with magic spells, some are good some ... are not. When a scroll is read its magic is released and the scroll destroyed."},
        {TV_POTION, "Potions are magical liquids, some of them can be beneficial .. some not."},
        {TV_POTION2, "Potions are magical liquids, some of them can be beneficial .. some not."},
        {TV_FLASK, "Flasks of oil can be used to refill lanterns."},
        {TV_FOOD, "Everybody needs to eat, even you."},
        {TV_HYPNOS, "This monster seems to be hypnotized and friendly."},
        {TV_RANDART, "Those objects are only known by rumors, it is said that they can be activated for great or strange powers..."},
        {TV_RUNE1, "Runes are used by Runecrafters to create brand new spells."},
        {TV_RUNE2, "Runes are used by Runecrafters to create brand new spells."},
        {TV_JUNK, "Junk is usually worthless, though experienced archers can create ammo with them."},
        {TV_SKELETON, "It looks dead..."},
        {TV_BOTTLE, "An empty bottle. Maybe an alchemists could refill it."},
        {TV_SPIKE, "Spikes can be used to jam doors."},
        {TV_CORPSE, "It looks dead..."},
        {TV_BOOTS, "Boots can help your armor rating, some can be magical too."},
        {TV_GLOVES, "Handgear is used to protect hands, but non magical ones can sometimes hinder spellcasting. Also alchemists needs gloves in order to do alchemy."},
        {TV_HELM, "Headgear will protect your head."},
        {TV_CROWN, "Headgear will protect your head."},
        {TV_SHIELD, "Shields will help improve your defense rating, but you cannot use them with two handed weapons."},
        {TV_CLOAK, "Cloaks can shield you from damage, sometimes also providing magical powers."},
        {TV_SOFT_ARMOR, "Soft armor is light, not hindering your combat much."},
        {TV_HARD_ARMOR, "Hard armor provides much more protection than soft armor but also hinders combat much more."},
        {TV_VALARIN_BOOK, "This holy book is used by priests and a few others to call upon their god."},
        {TV_MAGERY_BOOK, "This magic book is used by spellcasters to cast spells."},
        {TV_SHADOW_BOOK, "This magic book is used by spellcasters to cast spells."},
        {TV_NETHER_BOOK, "This magic book is used by spellcasters to cast spells."},
        {TV_ILLUSION_BOOK, "This magic book is used by spellcasters to cast spells."},
        {TV_TRIBAL_BOOK, "This mystical book is used by rangers and a few others to cast spells."},
        {TV_CHAOS_BOOK, "This magic book is used by chaos warriors and few others to cast spells"},
        {TV_CRUSADE_BOOK, "This holy book is used by paladins and a few others to call upon their god."},
        {TV_SIGALDRY_BOOK, "This magic book is used by spellcasters to cast spells."},
        {TV_SYMBIOTIC_BOOK, "This mystical book is used by symbiants to extend their symbiosis."},
        {TV_MUSIC_BOOK, "This song book is used by harpers to play songs."},
        {TV_MAGIC_BOOK, "This magic book is used by spellcasters to cast spells."},
        {TV_PRAYER_BOOK, "This holy book is used by priests and a few others to call upon their god."},
        {TV_DRUID_BOOK, "This mystical book is used by druids to call upon the powers of nature."},
        {TV_DAEMON_BOOK, "This magic book is used by daemonologists to control demons."},
        {TV_SPIRIT_BOOK, "This magic book is used by spellcasters to cast spells."},
        {0, ""},
};

/*
 * List of the between exits
 *       s16b corresp;           Corresponding between gate
 *       bool dungeon;           Do we exit in a dungeon or in the wild ?
 *
 *       s16b wild_x, wild_y;    Wilderness spot to land onto
 *       s16b px, py;            Location of the map
 *
 *       s16b d_idx;             Dungeon to land onto
 *       s16b level;
 */
between_exit between_exits[MAX_BETWEEN_EXITS] =
{
        {
                1,
                FALSE,
                49, 11,
                119, 25,
                0, 0
        },
        {
                0,
                FALSE,
                60, 56,
                10, 35,
                0, 0
        },
};

/*
 * Months
 */
int month_day[9] =
{
        0,      /* 1 day */

        1,      /* 54 days */
        55,     /* 72 days */
        127,    /* 54 days */

        181,    /* 3 days */

        184,    /* 54 days */
        238,    /* 72 days */
        310,    /* 54 days */

        364,    /* 1 day */
};
cptr month_name[9] =
{
        "Yestare",

        "Tuile",
        "Laire",
        "Yavie",

        "Enderi",

        "Quelle",
        "Hrive",
        "Coire",

        "Mettare",
};
