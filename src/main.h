
/*****************************************************************************
        This file is commented in CYS format. If you want to read this
            file, set the width of your terminal to at least 160.
 *****************************************************************************/

/* gtkgo 0.0.10 (main.h) - 05/17/99
 * Copyright (C) 1998, 1999  Norbert de Jonge (hack@altavista.net)
 *
 * This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this game; if not, write to the Free Software Foundation, Inc., 59 Temple Place
 * - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef MAIN_H                                                                  /* If not defined MAIN_H                                                     */
#define MAIN_H                                                                  /* Define MAIN_H                                                             */
                                                                                /*                                                                           */
#include <gtk/gtk.h>                                                            /* Include GTK+                                                              */
#include <gdk_imlib.h>                                                          /* GdkImlibImage, etc.                                                       */
#include <stdio.h>                                                              /* sprintf, etc.                                                             */
#include <time.h>                                                               /* time, etc.                                                                */
#include <string.h>                                                             /* bzero, strerror, etc.                                                     */
#include <arpa/inet.h>                                                          /* [Gnome] host_addr, etc.                                                   */
#include <errno.h>                                                              /* [Gnome] errno, etc.                                                       */
#include <fcntl.h>                                                              /* [Gnome] O_RDONLY, etc.                                                    */
#include <unistd.h>                                                             /* read, close, etc.                                                         */
#include <netdb.h>                                                              /* [Gnome] gethostbyname, etc.                                               */
#include <stdlib.h>                                                             /* random, RAND_MAX, atoi, etc.                                              */
#include <signal.h>                                                             /* [Gnome] kill, SIGKILL, etc.                                               */
#include <dirent.h>                                                             /* DIR, etc.                                                                 */
                                                                                /*                                                                           */
#ifdef USE_GNOME                                                                /* If USE_GNOME defined                                                      */
#include <gnome.h>                                                              /* [Gnome] Include Gnome                                                     */
#endif                                                                          /* End of if statement                                                       */
                                                                                /*                                                                           */
#include "About.h"                                                              /* Include About.h                                                           */
#include "AskSave.h"                                                            /* Include AskSave.h                                                         */
#include "BoardPlace.h"                                                         /* Include BoardPlace.h                                                      */
#include "Change.h"                                                             /* Include Change.h                                                          */
#include "ChangePixmap.h"                                                       /* Include ChangePixmap.h                                                    */
#include "ChangeSkin.h"                                                         /* Include ChangeSkin.h                                                      */
#include "CheckSides.h"                                                         /* Include CheckSides.h                                                      */
#include "Computer.h"                                                           /* Include Computer.h                                                        */
#include "DeadStones.h"                                                         /* Include DeadStones.h                                                      */
#include "DestroyChange.h"                                                      /* Include DestroyChange.h                                                   */
#include "DestroyFiles.h"                                                       /* Include DestroyFiles.h                                                    */
#include "DestroyFiles2.h"                                                      /* Include DestroyFiles2.h                                                   */
#include "DestroyMessage.h"                                                     /* Include DestroyMessage.h                                                  */
#include "DestroyOptions.h"                                                     /* Include DestroyOptions.h                                                  */
#include "DestroyYesNo.h"                                                       /* Include DestroyYesNo.h                                                    */
#include "DoHandicap.h"                                                         /* Include DoHandicap.h                                                      */
#include "EnableComp.h"                                                         /* Include EnableComp.h                                                      */
#include "EndGame.h"                                                            /* Include EndGame.h                                                         */
#include "FreePlace.h"                                                          /* Include FreePlace.h                                                       */
#include "Handicap.h"                                                           /* Include Handicap.h                                                        */
#include "Help.h"                                                               /* Include Help.h                                                            */
#include "Hint.h"                                                               /* Include Hint.h                                                            */
#include "HowMany.h"                                                            /* Include HowMany.h                                                         */
#include "Human.h"                                                              /* Include Human.h                                                           */
#include "Internet.h"                                                           /* Include Internet.h                                                        */
#include "InternetGo.h"                                                         /* Include InternetGo.h                                                      */
#include "JudgeBoard.h"                                                         /* Include JudgeBoard.h                                                      */
#include "Latest.h"                                                             /* Include Latest.h                                                          */
#include "MainWindow.h"                                                         /* Include MainWindow.h                                                      */
#include "MakeMove.h"                                                           /* Include MakeMove.h                                                        */
#include "Message.h"                                                            /* Include Message.h                                                         */
#include "Modulo.h"                                                             /* Include Modulo.h                                                          */
#include "MyLand.h"                                                             /* Include MyLand.h                                                          */
#include "NotSuicide.h"                                                         /* Include NotSuicide.h                                                      */
#include "Options.h"                                                            /* Include Options.h                                                         */
#include "OptionsX.h"                                                           /* Include OptionsX.h                                                        */
#include "Pass.h"                                                               /* Include Pass.h                                                            */
#include "PixmapOnButton.h"                                                     /* Include PixmapOnButton.h                                                  */
#include "Play.h"                                                               /* Include Play.h                                                            */
#include "Quit.h"                                                               /* Include Quit.h                                                            */
#include "ReallyQuit.h"                                                         /* Include ReallyQuit.h                                                      */
#include "ReallyReStart.h"                                                      /* Include ReallyReStart.h                                                   */
#include "ReceiveData.h"                                                        /* Include ReceiveData.h                                                     */
#include "ReSize.h"                                                             /* Include ReSize.h                                                          */
#include "ReStart.h"                                                            /* Include ReStart.h                                                         */
#include "Save.h"                                                               /* Include Save.h                                                            */
#include "SaveSgf.h"                                                            /* Include SaveSgf.h                                                         */
#include "ScoreBlack.h"                                                         /* Include ScoreBlack.h                                                      */
#include "ScoreWhite.h"                                                         /* Include ScoreWhite.h                                                      */
#include "SendData.h"                                                           /* Include SendData.h                                                        */
#include "SetTimeLimit.h"                                                       /* Include SetTimeLimit.h                                                    */
#include "Skin.h"                                                               /* Include Skin.h                                                            */
#include "Sound.h"                                                              /* Include Sound.h                                                           */
#include "StatusBar.h"                                                          /* Include StatusBar.h                                                       */
#include "TheComputer.h"                                                        /* Include TheComputer.h                                                     */
#include "TimeLimit.h"                                                          /* Include TimeLimit.h                                                       */
#include "Tooltips.h"                                                           /* Include Tooltips.h                                                        */
#include "Undo.h"                                                               /* Include Undo.h                                                            */
#include "Where.h"                                                              /* Include Where.h                                                           */

/*
 * Oh my god, where do all these global variables come from? I am doomed...
 */

int           x,                                                                /* x and y are used as counters to put all pixmaps on ...                    */
              y,                                                                /* ... the buttons.                                                          */
              isize,                                                            /* 1 - large board, 2 - small board.                                         */
              iCapturedB,                                                       /* Number of black stones removed from board.                                */
              iCapturedW,                                                       /* Number of white stones removed from the board.                            */
              ilastmovew,                                                       /* Place where white placed it's last stone.                                 */
              ilastmoveb,                                                       /* Place where black placed it's last stone.                                 */
              ihistory,                                                         /* Number of moves made (at 549 reset to 547).                               */
              ilimit,                                                           /* 1 - limit of history has been reached.                                    */
              ijustundo,                                                        /* 1 - a player has just done undo.                                          */
              ifilestuff,                                                       /* 1 - a file is currently being saved/loaded.                               */
              ichangestuff,                                                     /* 1 - the options window is active.                                         */
              itype,                                                            /* 1 - quit (resign/time), 2 - restart (r/t), 3 - must quit, 4 - quit        */
              iduh,                                                             /* 1 - passed, but no higher score than opponent.                            */
              biscomputer,                                                      /* 0 - black is a human player, 1 - black is a go-computer.                  */
              wiscomputer,                                                      /* 0 - white is a human player, 1 - white is a go-computer.                  */
              ichangecolor,                                                     /* 1 - change white player, 2 - change black player.                         */
              idone,                                                            /* 1 - a player has successfully made a move.                                */
              inotside,                                                         /* 1 - don't make a move on the sides of the board.                          */
              inotown,                                                          /* 1 - don't make a move in your own territory.                              */
              inotother,                                                        /* 1 - don't make a move in your opponents territory.                        */
              iother,                                                           /* 1 - don't look at inotside, inotown and inotother.                        */
              imoves,                                                           /* The number of moves made so far.                                          */
              itooltips,                                                        /* 0 - no tooltips, 1 - show tooltips.                                       */
              ishowlast,                                                        /* 0 - don't show latest stones, 1 - show latest stones.                     */
              itooltipsdone,                                                    /* 0 - busy changing tooltips, 1 - tooltips changed.                         */
              ilatestdone,                                                      /* 0 - busy changing latest stones, 1 - done changing latest stones.         */
              isounddone,                                                       /* 0 - busy changing sound on/off, 1 - ready changing sound.                 */
              ihandicapdone,                                                    /* 0 - busy changing handicap, 1 - done changing handicap.                   */
              isound,                                                           /* 0 - no sound, 1 - sound.                                                  */
              ihandicap,                                                        /* The number of handicap stones.                                            */
              istarthand,                                                       /* Number of handicap stones with which the game started.                    */
              ijustrestart,                                                     /* 0 - busy playing a game, 1 - a game has just been restarted.              */
              isave,                                                            /* 0 - do not save this game, 1 - save this game.                            */
              iyesno,                                                           /* 1 - a window other than the main window is open.                          */
              iquit,                                                            /* 1 - quit after a DestroyMessage ().                                       */
              isavemes,                                                         /* 1 - a message is stored to be shown with the next message.                */
              inet,                                                             /* 1 - the internet window is opened.                                        */
              sockfd,                                                           /* The socket file descriptor used to send/receive messages.                 */
              n,                                                                /* Number of bytes send/received.                                            */
              iiamblack,                                                        /* 0 - I am white, 1 - I am black.                                           */
              igonow,                                                           /* 1 - always allow undo.                                                    */
              idohint,                                                          /* 1 - also send a hint via the internet.                                    */
              ioptionsx,                                                        /* 0 - normal options window, 1 - fancy options window.                      */
              ixdone,                                                           /* 1 - busy changing the options window.                                     */
              itimelimit,                                                       /* Number of minutes for each player to play.                                */
              itimemm,                                                          /* These two are used ...                                                    */
              itimehh,                                                          /* ... to set the timelimit.                                                 */
              ihleftb,                                                          /* Hours left for the black player.                                          */
              imleftb,                                                          /* Minutes left for the black player.                                        */
              isleftb,                                                          /* Seconds left for the black player.                                        */
              ihleftw,                                                          /* Hours left for the white player.                                          */
              imleftw,                                                          /* Minutes left for the white player.                                        */
              isleftw,                                                          /* Seconds left for the white player.                                        */
              itsleftb,                                                         /* Number of seconds left for black player.                                  */
              itsleftw,                                                         /* Number of seconds left for white player.                                  */
              isavedes,                                                         /* A file descriptor used when saving/loading files.                         */
              idone2,                                                           /* Used for a loop when reading the ~/.gtkgo file.                           */
              iret,                                                             /* A file descriptor used when reading from ~/.gtkgo                         */
              ithing,                                                           /* The number of chars read from ~/.gtkgo                                    */
              iabout,                                                           /* 1 - about window is opened.                                               */
              imoving,                                                          /* 1 - busy making a move (MakeMove is not allowed).                         */
              iselectdead;                                                      /* 1 - MakeMove will remove dead stones or place them back.                  */
float         iscoreblack,                                                      /* Total score of the black player.                                          */
              iscorewhite;                                                      /* Total score of the white player.                                          */
pid_t         mpg123pid;                                                        /* Process ID used for playing mp3's.                                        */
unsigned int  itimeb,                                                           /* The moment in time when black will run out of time.                       */
              itimew,                                                           /* The moment in time when white will run out of time.                       */
              ioldtime;                                                         /* Moment when the player starts thinking about it's next move.              */
char          cstart;                                                           /* Color of the player who started the game.                                 */
gint          w,                                                                /* The width and height of the pixmaps on ...                                */
              h;                                                                /* ... the event boxes.                                                      */
char          sskin[61];                                                        /* Name of the currently used skin.                                          */
GtkWidget     *window1;                                                         /* The main window.                                                          */
GtkWidget     *changewindow;                                                    /* The options window.                                                       */
GtkWidget     *messagewindow;                                                   /* The message window.                                                       */
GtkWidget     *timewindow;                                                      /* Time limit window.                                                        */
GtkWidget     *table2;                                                          /* Bottom table of the main window.                                          */
GtkWidget     *button[362];                                                     /* The buttons (event boxes) on the main window.                             */
char          Board[362][5];                                                    /* Current value of all the boardplaces.                                     */
char          History[551][362][5];                                             /* History of all moves.                                                     */
int           TimeHistory[551];                                                 /* Time history of all the moves.                                            */
int           CapturedW[551],                                                   /* History of the number of white stones captured by black.                  */
              CapturedB[551];                                                   /* History of the number of black stones captured by white.                  */
GtkWidget     *pixmapwid[362];                                                  /* These two are used to draw the pixmaps on the ...                         */
GdkPixmap     *pixmap[362];                                                     /* ... event boxes.                                                          */
int           Checked[362];                                                     /* Values are set to one if CheckSides () has checked them already.          */
GtkWidget     *skinswindow,                                                     /* The window used to select new skins.                                      */
              *files2,                                                          /* File selection used to save sgf files.                                    */
              *change;                                                          /* File selection used to load a new computer.                               */
GdkImlibImage *im[362];                                                         /* Used to load the pixmaps on the event boxes.                              */
int           butrem[551];                                                      /* Remembers the place of the latest stone removed at ihistory               */
int           pass[551];                                                        /* 1 - someone has passed.                                                   */
char          bplayername[100],                                                 /* Name of the black player.                                                 */
              wplayername[100];                                                 /* Name of the white player.                                                 */
char          sysexec[250];                                                     /* Temporary string with a line to be executed.                              */
char          ssavemes[100];                                                    /* Temporary string of the line to be shown.                                 */
time_t        tm;                                                               /* This one is used for random and the time limits.                          */
GtkTooltips   *toptip;                                                          /* These tooltips are used for the upper table ...                           */
GtkTooltips   *toptip2;                                                         /* ...                                                                       */
GtkTooltips   *toptip3;                                                         /* ...                                                                       */
GtkTooltips   *toptip4;                                                         /* ...                                                                       */
GtkTooltips   *toptip5;                                                         /* ...                                                                       */
GtkTooltips   *toptip6;                                                         /* ...                                                                       */
GtkTooltips   *toptip7;                                                         /* ...                                                                       */
GtkTooltips   *toptip8;                                                         /* ... of the main window.                                                   */
GtkTooltips   *buttontip[362];                                                  /* The tooltips for the event boxes (on the main window).                    */
GtkWidget     *changebutton7;                                                   /* A few event boxes from the options window ...                             */
GtkWidget     *changebutton9;                                                   /* ...                                                                       */
GtkWidget     *changebutton11;                                                  /* ...                                                                       */
GtkWidget     *changebutton13;                                                  /* ... must be here, so I can change them from outside Options ().           */
GdkPixmap     *cbpixmap7;                                                       /* These GdkPixmap's and GtkWidget's must be here ...                        */
GdkPixmap     *cbpixmap9;                                                       /* ...                                                                       */
GdkPixmap     *cbpixmap11;                                                      /* ...                                                                       */
GdkPixmap     *cbpixmap13;                                                      /* ...                                                                       */
GtkWidget     *cbpixmapwid7;                                                    /* ...                                                                       */
GtkWidget     *cbpixmapwid9;                                                    /* ...                                                                       */
GtkWidget     *cbpixmapwid11;                                                   /* ...                                                                       */
GtkWidget     *cbpixmapwid13;                                                   /* ... so I can use them from outside Options ().                            */
GtkWidget     *statbar2;                                                        /* The statusbar for black on the bottom table of the main window.           */
GtkWidget     *statbar3;                                                        /* The statusbar for white on the bottom table of the main window.           */
GtkWidget     *connectentry1;                                                   /* Entry for the host (Internet play).                                       */
GtkWidget     *connectentry2;                                                   /* Entry for the port (Internet play).                                       */
GdkColor      color;                                                            /* Used for allocating a specific color (in InternetGo ()).                  */
GtkWidget     *internetentry;                                                   /* Entry used in the internet window.                                        */
GdkFont       *fixed_font;                                                      /* The fixed font (loaded in main.c) used for Help () and InternetGo ().     */
GtkAdjustment *adj;                                                             /* Used to adjust the text in the internet window.                           */
GtkWidget     *text;                                                            /* The text block used in the internet window.                               */
GtkWidget     *texth;                                                           /* The text block used in Help ().                                           */
GtkWidget     *timeentry1;                                                      /* Entry for the time limit.                                                 */
char          schar2[1];                                                        /* Small string, used for reading chars from ~/.gtkgo                        */
char          ssaveread[100];                                                   /* ssaveread and ssavetemp contain the data read ...                         */
char          ssavetemp[100];                                                   /* ... from the ~/.gtkgo file.                                               */
char          sthesavef[100];                                                   /* Temporary string to save the location of the $HOME/.gtkgo file.           */
                                                                                /*                                                                           */
void About (void);                                                              /* Function About                                                            */

/*
 * Shows the about window.
 */

void AskSave (void);                                                            /* Function AskSave                                                          */

/*
 * Asks the user if the played game should be saved.
 */

char* BoardPlace (int iplacetype, int iboardplace);                             /* Function BoardPlace                                                       */

/*
 * Returns the selected iboardplace in SGF (iplacetype = 1) or go format (iplacetype = 2).
 */

void Change (int icbutton);                                                     /* Function Change                                                           */

/*
 * Places the (new) pixmap from Board[icbutton] on icbutton.
 */

int ChangePixmap (int icpbutton, char cpccolor);                                /* Function ChangePixmap                                                     */

/*
 * Returns 1 if the pixmap of icpbutton has successfully been changed to cpccolor ('b', 'w' or 'e').
 */

void ChangeSkin (GtkWidget *csw, gpointer csdata);                              /* Function ChangeSkin                                                       */

/*
 * Changes the skin to the skin in csdata.
 */

int CheckSides (int icsbutton, char csccolor, int csitype);                     /* Function CheckSides                                                       */

/*
 * Use csitype = 0 to call CheckSides () from within itself.
 * csitype = 0, 1 or 2 will return the total of under (8), above (4), right (2) and left (1) of icsbutton (when it would be of color csccolor) where it is
 * not free. csitype = 3 returns the number of stones in the group where icsbutton (of color csccolor) is part of.
 */

void Computer (char cccolor);                                                   /* Function Computer                                                         */

/*
 * Makes a computer generated move for the player with color cccolor.
 */

void DeadStones (void);                                                         /* Function DeadStones                                                       */

/*
 * Makes it possible for the user to select dead stones.
 */

void DestroyChange (void);                                                      /* Function DestroyChange                                                    */

/*
 * Destroys the computer loading window.
 */

void DestroyFiles (void);                                                       /* Function DestroyFiles                                                     */

/*
 * Destroys the skin loading window.
 */

void DestroyFiles2 (void);                                                      /* Function DestroyFiles2                                                    */

/*
 * Destroys the sgf saving window.
 */

void DestroyMessage (void);                                                     /* Function DestroyMessage                                                   */

/*
 * Destroys the message window.
 */

void DestroyOptions (void);                                                     /* Function DestroyOptions                                                   */

/*
 * Destroy the options window.
 */

void DestroyYesNo (GtkWidget *ynwidget, GdkEvent *ynevent, gpointer yndata);    /* Function DestroyYesNo                                                     */

/*
 * Destroy the window yesnowindow (yndata = 0), save a SGF (yndata = 1), restart (yndata = 2) or quit (yndata = 3).
 */

void DoHandicap (void);                                                         /* Function DoHandicap                                                       */

/*
 * Place or remove (new) handicap stones on the board.
 */

void EnableComp (GtkWidget *ecw, GtkFileSelection *ecfs);                       /* Function EnableComp                                                       */

/*
 * Change the black (ichangecolor = 2) or white (ichangecolor = 1) player to the go-computer in ecfs.
 */

void EndGame (void);                                                            /* Function EndGame                                                          */

/*
 * Call AskSave with itype = 3.
 */

int FreePlace (int ifpbutton, char fpccolor, char fpctype);                     /* Function FreePlace                                                        */

/*
 * Returns 1 if ifpbutton (when fpccolor) is fpctype, returns 0 if ifpbutton (when fpccolor) is not fpctype. fpctype may be:
 * 'F': random free place (all sides unoccupied).
 * 'f': same as 'F', but touches color fpccolor at northeast, ... just ones.
 * '!': in own territory.
 * '.': in opponents territory.
 * 'M': random free place, but touches at least one point with color fpccolor.
 */

void Handicap (GtkWidget *hwidget, GdkEvent *hevent, gpointer hdata);           /* Function Handicap                                                         */

/*
 * Changes the handicap.
 */

void Help (void);                                                               /* Function Help                                                             */

/*
 * Shows the help window.
 */

void Hint (void);                                                               /* Function Hint                                                             */

/*
 * Makes a computer generated move for the current player.
 */

int HowMany (int hmbutton, char nothmccolor);
void Human (GtkWidget *humwidget, gpointer humdata);
void Internet (void);
void InternetGo (void);
void JudgeBoard (char jbccolor);
void Latest (void);
void MainWindow (void);
void MakeMove (GtkWidget *mmwidget, GdkEvent *mmevent, gpointer mmdata);
void Message (char *mestext, int imesquit, int imestype);
int Modulo (int ione, int itwo);
int MyLand (char mlccolor);
int NotSuicide (int insbutton, char nsccolor);
void Options (void);
void OptionsX (void);
void Pass (void);
void PixmapOnButton (int ithebutton);
void Play (char *sfiletoplay, int iloop);
void Quit (void);
void ReallyQuit (GtkWidget *rqw, GtkFileSelection *rqfs);
void ReallyReStart (GtkWidget *rrw, GtkFileSelection *rrfs);
void ReceiveData (void);
void ReSize (void);
void ReStart (int iReCheck);
void Save (void);
void SaveSgf (void);
float ScoreBlack (void);
float ScoreWhite (void);
void SendData (int istype, char *ssenddata);
void SetTimeLimit (void);
void Skin (void);
void Sound (void);
void StatusBar (void);
void TheComputer (GtkWidget *tcwidget, gpointer tcdata);
void TimeLimit (void);
void Tooltips (void);
void Undo (void);
int Where (int iwabove, int iwunder, int iwright, int iwleft);

#endif
