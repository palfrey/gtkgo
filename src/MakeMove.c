/* gtkgo 0.0.10 (MakeMove.c) - 05/17/99
 * Copyright (C) 1998, 1999  Norbert de Jonge
 * (hack@altavista.net)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this game; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#include "MakeMove.h"

int itemppp;

void MakeMove (GtkWidget *mmwidget, GdkEvent *mmevent, gpointer mmdata)
{
  /* The next 4 lines must be there. */
  while (gtk_events_pending ())
  {
    gtk_main_iteration ();
  }
  if ((((ifilestuff == 0) && ((biscomputer == 0) || (wiscomputer == 0))
    && (iyesno == 0)) || (iselectdead == 1)) && (imoving == 0))
  {
    imoving = 1;
    if (iselectdead == 1)
    {
      ibuttonm = (int) mmdata;
      if (((Board[ibuttonm][2] == 'e') || (Board[ibuttonm][2] == 's')) &&
        ((History[ihistory][ibuttonm][2] == 'b') ||
        (History[ihistory][ibuttonm][2] == 'w')))
      {
        Board[ibuttonm][2] = History[ihistory][ibuttonm][2];
        if (ishowlast == 1)
        {
          Board[ibuttonm][3] = History[ihistory][ibuttonm][3];
        }
        Change (ibuttonm);
      }
      else
      if ((Board[ibuttonm][2] == 'b') || (Board[ibuttonm][2] == 'w'))
      {
        switch (ibuttonm)
        {
          case 61: Board[ibuttonm][2] = 's'; break;
          case 67: Board[ibuttonm][2] = 's'; break;
          case 73: Board[ibuttonm][2] = 's'; break;
          case 175: Board[ibuttonm][2] = 's'; break;
          case 181: Board[ibuttonm][2] = 's'; break;
          case 187: Board[ibuttonm][2] = 's'; break;
          case 289: Board[ibuttonm][2] = 's'; break;
          case 295: Board[ibuttonm][2] = 's'; break;
          case 301: Board[ibuttonm][2] = 's'; break;
          default: Board[ibuttonm][2] = 'e'; break;
        }
        if (Board[ibuttonm][3] == 'l')
        {
          Board[ibuttonm][3] = '\0';
        }
        Change (ibuttonm);
      }
    }
    else
    if (((((Modulo (imoves, 2) == 0) && (iiamblack == 1)) || ((Modulo (imoves,
      2) != 0) && (iiamblack == 0))) && (inet == 1)) || (inet == 0))
    {
      ibuttonm = (int) mmdata;
      if (inet == 1)
      {
        SendData (1, BoardPlace (2, ibuttonm));
      }
      idone = 0;
      iother = 1;
      if (Modulo (imoves, 2) == 0)
      {
        ChangePixmap (ibuttonm, 'b');
      }
      else
      {
        ChangePixmap (ibuttonm, 'w');
      }
      iother = 0;
      if (idone == 1)
      {
        if (((imoves == 0) || (imoves == 1)) && (ijustrestart == 1))
        {
          istarthand = ihandicap;
          ijustrestart = 0;
        }
        if ((biscomputer == 1) || (wiscomputer == 1))
        {
          if (Modulo (imoves, 2) == 0)
          {
            JudgeBoard ('w');
            Computer ('w');
            JudgeBoard ('b');
          }
          else
          {
            JudgeBoard ('b');
            Computer ('b');
            JudgeBoard ('w');
          }
        }
        else
        {
          if (Modulo (imoves, 2) == 0)
          {
            JudgeBoard ('w');
          }
          else
          {
            JudgeBoard ('b');
          }
        }
      }
    }
    else
    {
      if (inet == 1)
      {
        Message ("It is not your move.", 3, 0);
      }
    }
    imoving = 0;
    StatusBar ();
  }
}
