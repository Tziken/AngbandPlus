/* File: config.h */

/* Purpose: Angband specific configuration stuff */

/*
 * Copyright (c) 1989 James E. Wilson, Robert A. Koeneke
 *
 * This software may be copied and distributed for educational, research, and
 * not for profit purposes provided that this copyright and statement are
 * included in all such copies.
 */

/*
 * Look through the following lines, and where a comment includes the
 * tag "OPTION:", examine the associated "#define" statements, and decide
 * whether you wish to keep, comment, or uncomment them.  You should not
 * have to modify any lines not indicated by "OPTION".
 *
 * Note: Also examine the "system" configuration file "h-config.h"
 * and the variable initialization file "variable.c".  If you change
 * anything in "variable.c", you only need to recompile that file.
 *
 * And finally, remember that the "Makefile" will specify some rather
 * important compile time options, like what visual module to use.
 */

/*
 * jk OPTION: debug some game actions via dlog statements in the source
 * make sure to keep this in sync with debug_flag_names[] in table.c!!!!
 */
#define DEBUGALWAYS 0x00000000L /* these messages are always debugged */
#define DEBUGSAVE   0x00000001L /* debug handling of loading/saving (overview only) */
#define DEBUGSAVE2  0x00000002L /* write more info, like precise descriptions of every item saved/loaded */
#define DEBUGTRAPS  0x00000004L /* debug trap-handling */
#define DEBUGITEMS  0x00000008L /* debug item-handling */
#define DEBUGMOVES  0x00000010L /* debug moving about  */
#define DEBUGLIGHT  0x00000020L /* debug lighting use with care - generates enormous log- */
                                /* files and slows the game down considerably */
#define DEBUGGENER  0x00000040L /* debug level generation */
#define DEBUGGENER2 0x00000080L /* debug level generation */
                                /* use with care - show every location that's created */
#define DEBUGSTORE  0x00000100L /* debug store interaction */
#define DEBUGPREF   0x00000200L /* debug pref-file interaction */
#define DEBUGMESG   0x00000400L /* debug message generation and handling */
#define DEBUGFLOW   0x00000800L /* debug the main program flow */
#define DEBUGARENA  0x00001000L /* debug the arena handling */
#define DEBUGPROJ   0x00002000L /* debug projecting various things */
#define DEBUGLOS    0x00004000L /* debug LOS calculations */
#define DEBUGFIGHT  0x00008000L /* debug fighting */
#define DEBUGMACRO  0x00010000L /* debug macro handling */
#define DEBUGGHOST  0x00020000L /* ghost handling */
#define DEBUGALLOC  0x00040000L /* memory allocation */
#define DEBUGTEMPL  0x00080000L /* template handling */
#define DEBUGMONST  0x00100000L /* monster birth */
#define DEBUGMONAI  0x00200000L /* monster AI for moving & doing things */
#define DEBUGBIRTH  0x00400000L /* character birth */
#define DEBUGCMPRS  0x00800000L /* savefile compression */
#define DEBUGMSGS   0x01000000L /* send all msg_print/msg_format to logfile */
#ifdef linux
#define DEBUGDUMP   0x02000000L /* allow calling 'addr2line' from within the program */
#endif
                                /* this is only tested on Linux! */

#define DEBUGKEYS   0x04000000L /* debug the handling of key-presses */
#define DEBUGEXTRA  0x80000000L /* debug some other things, including leaving of wizard mode */

/*
 * if you want to see some debugging messages (which? see above!)
 * either call the program with the -x <logfile> argument,
 * or define this constant and redirect standard out to somewhere.
 */
/* #define DEBUG_TO_STDERR */

/*
 * if you want the debugging messages (see above) to be copied into
 * the regular game messages (meaning you can see them while you play!)
 * and also possibly leading to a very big (100's of megabytes) and slow
 * message-file in lib/save, define this.
 */
/* #define DEBUG_COPY_AS_MESSAGE */

/*
 * send debugging messages to stderr only - for debugging some
 * shitty win95 setups
 */
/* #define WIN_DEBUG_TO_STDERR */

/*
 * OPTION: See the Makefile(s), where several options may be declared.
 *
 * Some popular options include "USE_GCU" (allow use with Unix "curses"),
 * "USE_X11" (allow basic use with Unix X11), "USE_XAW" (allow use with
 * Unix X11 plus the Athena Widget set), and "USE_CAP" (allow use with
 * the "termcap" library, or with hard-coded vt100 terminals).
 *
 * The old "USE_NCU" option has been replaced with "USE_GCU".
 *
 * Several other such options are available for non-unix machines,
 * such as "MACINTOSH", "WINDOWS", "USE_IBM", "USE_EMX".
 *
 * You may also need to specify the "system", using defines such as
 * "SOLARIS" (for Solaris), etc, see "h-config.h" for more info.
 */

/*
 * OPTION: define "SPECIAL_BSD" for using certain versions of UNIX
 * that use the 4.4BSD Lite version of Curses in "main-gcu.c"
 */
/* #define SPECIAL_BSD */


/*
 * OPTION: Use the POSIX "termios" methods in "main-gcu.c"
 */
/* #define USE_TPOSIX */

/*
 * OPTION: Use the "termio" methods in "main-gcu.c"
 */
/* #define USE_TERMIO */

/*
 * OPTION: Use the icky BSD "tchars" methods in "main-gcu.c"
 */
/* #define USE_TCHARS */

/*
 * OPTION: Use "blocking getch() calls" in "main-gcu.c".
 * Hack -- Note that this option will NOT work on many BSD machines
 * Currently used whenever available, if you get a warning about
 * "nodelay()" undefined, then make sure to undefine this.
 */
#if defined(SYS_V) || defined(AMIGA)
# define USE_GETCH
#endif

/*
 * OPTION: Use the "curs_set()" call in "main-gcu.c".
 * Hack -- This option will not work on most BSD machines
 */
#ifdef SYS_V
# define USE_CURS_SET
#endif


/*
 * OPTION: Include "ncurses.h" instead of "curses.h" in "main-gcu.c"
 */
#define USE_NCURSES

/*
 * allow the use of the ACS characters (block-characters)
 * these are defined in lib/user/graf-gcu.prf
 */
#define USE_NCURSES_ACS

/*
 * OPTION: for multi-user machines running the game setuid to some other
 * user (like 'games') this SAFE_SETUID option allows the program to drop
 * its privileges when saving files that allow for user specified pathnames.
 * This lets the game be installed system wide without major security
 * concerns.  There should not be any side effects on any machines.
 *
 * This will handle "gids" correctly once the permissions are set right.
 */
#define SAFE_SETUID

/*
 * This flag enables the "POSIX" methods for "SAFE_SETUID".
 */
#ifdef _POSIX_SAVED_IDS
# define SAFE_SETUID_POSIX
#endif

/*
 * This "fix" is from "Yoshiaki KASAHARA <kasahara@csce.kyushu-u.ac.jp>"
 * It prevents problems on (non-Solaris) Suns using "SAFE_SETUID".
 */
#if defined(sun) && !defined(SOLARIS)
# undef SAFE_SETUID_POSIX
#endif

/*
 * if this is TRUE, make sure you compile the c++ compression sources also!
 * this allows you to compress save-files as a whole. Typical sizes go from
 * 300 Kb per file to 20 Kb.
 * note that this (obviously) means you have to have a c++ compiler as well.
 */
#define ALLOW_COMPRESSION
#define COMPRESS_RLE
#undef COMPRESS_LZW

/*
 * this allows you to test another random numbers algorithm.
 * see z-rand.c for details.
 */
#define USE_OTHER_RAND


/*
 * OPTION: for the AFS distributed file system, define this to ensure that
 * the program is secure with respect to the setuid code.  This option has
 * not been tested (to the best of my knowledge).  This option may require
 * some weird tricks with "player_uid" and such involving "defines".
 * Note that this option used the AFS library routines Authenticate(),
 * bePlayer(), beGames() to enforce the proper priviledges.
 * You may need to turn "SAFE_SETUID" off to use this option.
 */
/* #define SECURE */

/*
 * OPTION: Verify savefile Checksums (Angband 2.7.0 and up)
 * This option can help prevent "corruption" of savefiles, and also
 * stop intentional modification by amateur users.
 */
/* #define VERIFY_CHECKSUMS */

/*
 * OPTION: Forbid the use of "fiddled" savefiles.  As far as I can tell,
 * a fiddled savefile is one with an internal timestamp different from
 * the actual timestamp.  Thus, turning this option on forbids one from
 * copying a savefile to a different name.  Combined with disabling the
 * ability to save the game without quitting, and with some method of
 * stopping the user from killing the process at the tombstone screen,
 * this should prevent the use of backup savefiles.  It may also stop
 * the use of savefiles from other platforms, so be careful.
 */
/* #define VERIFY_TIMESTAMP */


/*
 * OPTION: Forbid the "savefile over-write" cheat, in which you simply
 * run another copy of the game, loading a previously saved savefile,
 * and let that copy over-write the "dead" savefile later.  This option
 * either locks the savefile, or creates a fake "xxx.lok" file to prevent
 * the use of the savefile until the file is deleted.  Not ready yet.
 */
/* #define VERIFY_SAVEFILE */

/*
 * OPTION: Hack -- Compile in support for "Cyborg" mode
 */
/* #define ALLOW_BORG */
#ifdef ALLOW_BORG
#error "Sorry, there is no Borg code in Angband/64!"
#endif

/*
 * OPTION: Compile in support for random artifacts
 */
#define GJW_RANDART

/*
 * OPTION: Hack -- Compile in support for "Wizard Commands"
 */
#define ALLOW_WIZARD

/*
 * OPTION: Hack -- Compile in support for "Spoiler Generation"
 */
#define ALLOW_SPOILERS


/*
 * OPTION: Allow "do_cmd_colors" at run-time
 */
#define ALLOW_COLORS

/*
 * OPTION: Allow "do_cmd_visuals" at run-time
 */
#define ALLOW_VISUALS

/*
 * OPTION: Allow "do_cmd_macros" at run-time
 */
#define ALLOW_MACROS


/*
 * OPTION: Allow characteres to be "auto-rolled"
 */
#define ALLOW_AUTOROLLER

/*
 * OPTION: Allow monsters to "flee" when hit hard
 */
/* jk - this doesn't work in the arena.... */
#define ALLOW_FEAR

/*
 * OPTION: Allow monsters to "flee" from strong players
 */
#define ALLOW_TERROR

/*
 * OPTION: Allow parsing of the ascii template files in "init.c".
 * This must be defined if you do not have valid binary image files.
 * It should be usually be defined anyway to allow easy "updating".
 */
#define ALLOW_TEMPLATES

/*
 * OPTION: Handle signals
 */
#define HANDLE_SIGNALS


/*
 * Allow "Wizards" to yield "high scores"
 */
#define SCORE_WIZARDS

/*
 * Allow "Borgs" to yield "high scores"
 */
/* #define SCORE_BORGS */

/*
 * Allow "Cheaters" to yield "high scores"
 */
#define SCORE_CHEATERS

/*
 * OPTION: Allow use of the "flow_by_smell" and "flow_by_sound"
 * software options, which enable "monster flowing".
 */
#define MONSTER_FLOW

/*
 * OPTION: Maximum flow depth when using "MONSTER_FLOW"
 */
#define MONSTER_FLOW_DEPTH 32

/*
 * OPTION: Allow use of extended spell info  -DRS-
 */
#define DRS_SHOW_SPELL_INFO

/*
 * OPTION: Allow use of the monster health bar  -DRS-
 */
#define DRS_SHOW_HEALTH_BAR

/*
 * OPTION: Enable the "smart_learn" and "smart_cheat" options.
 * They let monsters make more "intelligent" choices about attacks
 * (including spell attacks) based on their observations of the
 * player's reactions to previous attacks.  The "smart_cheat" option
 * lets the monster know how the player would react to an attack
 * without actually needing to make the attack.  The "smart_learn"
 * option requires that a monster make a "failed" attack before
 * learning that the player is not harmed by that attack.
 *
 * This adds about 3K to the memory and about 5K to the executable.
 */
#define DRS_SMART_OPTIONS

/*
 * OPTION: Allow the use of "color" in various places.  Disabling this
 * flag will remove some code, and auto-cast all colors to "White".
 * This will almost certainly speed up the program.  Note that there
 * is a software level flag as well ("use_color") which is almost as
 * good at speeding up the code.
 */
#define USE_COLOR

/*
 * OPTION: Allow the use of "sound" in various places.
 */
#define USE_SOUND

/*
 * OPTION: Allow the use of "graphics" in various places
 * note: I can't compile it with this using my cygwin crosscompiler on linux
 */
#define USE_GRAPHICS
#undef WIN_USE_GRAPHICS


/*
 * OPTION: Hack -- Macintosh stuff
 */
#ifdef MACINTOSH

/* Do not handle signals */
# undef HANDLE_SIGNALS

#endif


/*
 * OPTION: Hack -- Windows stuff
 */
#ifdef WINDOWS

#endif


/*
 * OPTION: Hack -- EMX stuff
 */
#ifdef USE_EMX

/* Do not handle signals */
# undef HANDLE_SIGNALS

#endif


/*
 * OPTION: Set the "default" path to the angband "lib" directory.
 *
 * See "main.c" for usage, and note that this value is only used on
 * certain machines, primarily Unix machines.  If this value is used,
 * it will be over-ridden by the "ANGBAND_PATH" environment variable,
 * if that variable is defined and accessable.  The final slash is
 * optional, but it may eventually be required.
 *
 * Using the value "./lib/" below tells Angband that, by default,
 * the user will run "angband" from the same directory that contains
 * the "lib" directory.  This is a reasonable (but imperfect) default.
 *
 * If at all possible, you should change this value to refer to the
 * actual location of the "lib" folder, for example, "/tmp/angband/lib/"
 * or "/usr/games/lib/angband/", or "/pkg/angband/lib".
 */
#define DEFAULT_PATH "./lib/"

/*
 * Most of the bug-reports mention data-corruption, for example in items.
 * I never see that, but I always regenerate the .hdr files from the
 * templates.
 */
/* #define ALWAYS_LOAD_TEMPLATES */

/*
 * OPTION: Maximum number of messages to remember (see "io.c")
 * Default: assume maximal memorization of 2048 total messages
 */
#define MESSAGE_MAX     32768L

/*
 * OPTION: Maximum space for the message text buffer (see "io.c")
 * angband/64 isn't so cramped for space, so we could request up to 1 Mb.
 *
 * but as we log to file, we only need 1 window (the message-recall window)
 */
#define MESSAGE_BUF     200000L

/*
 * On multiuser systems, add the "uid" to savefile names
 */
#ifdef SET_UID
# define SAVEFILE_USE_UID
#endif


/*
 * OPTION: Check the "time" against "lib/file/hours.txt"
 */
/* #define CHECK_TIME */

/*
 * OPTION: Check the "load" against "lib/file/load.txt"
 * This may require the 'rpcsvs' library
 */
/* #define CHECK_LOAD */


/*
 * OPTION: For some brain-dead computers with no command line interface,
 * namely Macintosh, there has to be some way of "naming" your savefiles.
 * The current "Macintosh" hack is to make it so whenever the character
 * name changes, the savefile is renamed accordingly.  But on normal
 * machines, once you manage to "load" a savefile, it stays that way.
 * Macintosh is particularly weird because you can load savefiles that
 * are not contained in the "lib:save:" folder, and if you change the
 * player's name, it will then save the savefile elsewhere.  Note that
 * this also gives a method of "bypassing" the "VERIFY_TIMESTAMP" code.
 */
#if defined(MACINTOSH) || defined(WINDOWS) || defined(AMIGA)
# define SAVEFILE_MUTABLE
#endif


/*
 * OPTION: Capitalize the "user_name" (for "default" player name)
 * This option is only relevant on SET_UID machines.
 */
#define CAPITALIZE_USER_NAME


/*
 * OPTION: Allow the use of a "Recall Window", if supported
 */
#define GRAPHIC_RECALL

/*
 * OPTION: Allow the use of a "Choice Window", if supported
 */
#define GRAPHIC_CHOICE

/*
 * OPTION: Allow the use of a "Mirror Window", if supported
 */
#define GRAPHIC_MIRROR



/*
 * OPTION: Shimmer Multi-Hued monsters/objects
 */
#define SHIMMER_MONSTERS
#define SHIMMER_OBJECTS


/*
 * OPTION: Person to bother if something goes wrong.
 */
#define MAINTAINER   "thunder7@xs4all.nl"


/*
 * OPTION: Default font (when using X11).
 */
#define DEFAULT_X11_FONT      "9x15"

/*
 * OPTION: Default fonts (when using X11)
 */
#define DEFAULT_X11_FONT_SCREEN     DEFAULT_X11_FONT
#define DEFAULT_X11_FONT_MIRROR     DEFAULT_X11_FONT
#define DEFAULT_X11_FONT_RECALL     DEFAULT_X11_FONT
#define DEFAULT_X11_FONT_CHOICE     DEFAULT_X11_FONT

/*
 * Hack -- Special "ancient DOS-286" version
 */
#ifdef USE_286
# define ANGBAND_LITE
#endif

/*
 * Hack -- Special "ancient Macintosh" version
 */
#ifdef ANGBAND_LITE_MAC
# define ANGBAND_LITE
# undef USE_COLOR
# undef ALLOW_TEMPLATES
#endif


/*
 * OPTION: Attempt to minimize the size of the game
 */
/* #define ANGBAND_LITE */

/*
 * Hack -- React to the "ANGBAND_LITE" flag
 */
#ifdef ANGBAND_LITE
# undef GRAPHIC_RECALL
# undef GRAPHIC_CHOICE
# undef GRAPHIC_MIRROR
# undef ALLOW_COLORS
# undef ALLOW_VISUALS
# undef ALLOW_MACROS
# undef MONSTER_FLOW
# undef WDT_TRACK_OPTIONS
# undef DRS_SMART_OPTIONS
# undef ALLOW_OLD_SAVEFILES
# undef ALLOW_BORG
# undef ALLOW_WIZARD
# undef ALLOW_SPOILERS
#endif



/*
 * OPTION: Attempt to prevent all "cheating"
 */
/* #define VERIFY_HONOR */


/*
 * React to the "VERIFY_HONOR" flag
 */
#ifdef VERIFY_HONOR
# define VERIFY_SAVEFILE
# define VERIFY_CHECKSUMS
# define VERIFY_TIMESTAMPS
#endif


