/* gtkgo 0.0.10 (Undo.c) - 05/17/99
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

#include "Undo.h"

void Undo (void)
{
  /* WARNING: Ugly, but cool, coding ahead... */
  if ((((((((wiscomputer == 0) && (biscomputer == 0) && (istarthand > 0) &&
    (ihistory >= 2)) || ((wiscomputer == 1) && (biscomputer == 0) &&
    (istarthand > 0) && (ihistory >= 4)) || ((wiscomputer == 0) && (biscomputer
    == 1) && (istarthand > 0) && (ihistory >= 3)) || ((wiscomputer == 0) &&
    (biscomputer == 0) && (istarthand == 0) && (ihistory >= 1)) ||
    ((wiscomputer == 1) && (biscomputer == 0) && (istarthand == 0) && (ihistory
    >= 2)) || ((wiscomputer == 0) && (biscomputer == 1) && (istarthand == 0) &&
    (ihistory >= 3))) && (ilimit == 0)) || ((ihistory >= 547) && (ijustundo ==
    0) && (ilimit == 1))) && (iyesno == 0) && (ifilestuff == 0)) &&
    (((((Modulo (imoves, 2) == 0) && (iiamblack == 1)) || ((Modulo (imoves,
    2) != 0) && (iiamblack == 0))) && (inet == 1)) || (inet == 0))) ||
    (igonow == 1))
  {
    if ((inet == 1) && (igonow != 1))
    {
      SendData (1, "undo");
    }
    if ((wiscomputer == 0) && (biscomputer == 0) && (ilimit == 0))
    {
      imoves -= 1;
      ihistory -= 1;
    }
    else
    {
      imoves -= 2;
      if (ilimit == 0)
      {
        ihistory -= 2;
      }
      else
      {
        ijustundo = 1;
        if (ihistory == 547)
          ihistory = 549; else
        if (ihistory == 548)
          ihistory = 550; else
        if ((ihistory == 549) || (ihistory == 550))
          ihistory -= 2;
      }
    }
    if (Modulo (imoves, 2) == 0)
    {
      itimew = TimeHistory[ihistory] + (unsigned)time(&tm);
      itimeb = TimeHistory[ihistory - 1] + (unsigned)time(&tm);
    }
    else
    {
      itimeb = TimeHistory[ihistory] + (unsigned)time(&tm);
      if (ihistory > 1)
      {
        itimew = TimeHistory[ihistory - 1] + (unsigned)time(&tm);
      }
      else
      {
        itimew = (itimelimit * 60) + (unsigned)time(&tm);
      }
    }
    ioldtime = (unsigned)time(&tm);
    itsleftb = itimeb - (unsigned)time(&tm);
    itsleftw = itimew - (unsigned)time(&tm);
    iCapturedW = CapturedW[ihistory];
    iCapturedB = CapturedB[ihistory];
    for (ibuttonu = 1; ibuttonu <= 361; ibuttonu++)
    {
      if ((History[ihistory][ibuttonu][3] == 'l') &&
        (History[ihistory][ibuttonu][2] == 'b'))
      {
        ilastmoveb = ibuttonu;
      }
      if ((History[ihistory][ibuttonu][3] == 'l') &&
        (History[ihistory][ibuttonu][2] == 'w'))
      {
        ilastmovew = ibuttonu;
      }
      if (strcmp (History[ihistory][ibuttonu], Board[ibuttonu]) != 0)
      {
        if (History[ihistory][ibuttonu][3] != 'l')
        {
          sprintf (Board[ibuttonu], "%s", History[ihistory][ibuttonu]);
        }
        else
        {
          if (ishowlast == 0)
          {
            sprintf (Board[ibuttonu], "%c%c%c", History[ihistory][ibuttonu][0],
              History[ihistory][ibuttonu][1], History[ihistory][ibuttonu][2]);
          }
          else
          {
            sprintf (Board[ibuttonu], "%s", History[ihistory][ibuttonu]);
          }
        }
        iother = 1;
        Change (ibuttonu);
        iother = 0;
      }
    }
    StatusBar ();
  }
  else
  {
    if (inet == 1)
    {
      Message ("It is not your move.", 3, 0);
    }
  }
  if (ichangestuff == 0)
  {
    Play ("click.mp3", 0);
  }
}
