/* gtkgo 0.0.10 (JudgeBoard.c) - 05/17/99
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

#include "JudgeBoard.h"

void JudgeBoard (char jbccolor)
{
  ijustundo = 0;
  for (iLookForColor = 1; iLookForColor <= 361; iLookForColor++)
  {
    if (Board[iLookForColor][2] == jbccolor)
    {
      if (CheckSides (iLookForColor, jbccolor, 2) == 15)
      {
        iremoved = 0;
        for (iremove = 1; iremove <= 361; iremove++)
        {
          if (Checked[iremove] == 1)
          {
            if (jbccolor == 'b')
            {
              iCapturedB++;
            }
            else
            {
              iCapturedW++;
            }
            iother = 1;
            ChangePixmap (iremove, 'e');
            iother = 0;
            iremovedone = iremove;
            iremoved++;
            StatusBar ();
          }
        }
      }
    }
  }
  imoves++;
  if ((imoves == 1) && (jbccolor == 'b'))
  {
    cstart = 'w';
  }
  if ((imoves == 1) && (jbccolor == 'w'))
  {
    cstart = 'b';
  }
  if (imoves == 1)
  {
    itimeb = (itimelimit * 60) + (unsigned)time(&tm);
    itimew = (itimelimit * 60) + (unsigned)time(&tm);
    itsleftb = itimelimit * 60;
    itsleftw = itimelimit * 60;
  }
  else
  {
    if (Modulo (imoves, 2) == 0)
    {
      itimeb += (unsigned)time(&tm) - ioldtime;
    }
    else
    {
      itimew += (unsigned)time(&tm) - ioldtime;
    }
  }
  ioldtime = (unsigned)time(&tm);
  if (ihistory <= 549)
  {
    ihistory++;
  }
  else
  {
    ihistory = 547;
    ilimit = 1;
  }
  if (iremoved == 1)
  {
    butrem[ihistory] = iremovedone;
  }
  else
  {
    butrem[ihistory] = 0;
  }
  CapturedW[ihistory] = iCapturedW;
  CapturedB[ihistory] = iCapturedB;
  for (ibuttonj = 1; ibuttonj <= 361; ibuttonj++)
  {
    if (((jbccolor == 'b') && (ibuttonj == ilastmovew) &&
      (Board[ibuttonj][3] != 'l')) ||
      ((jbccolor == 'w') && (ibuttonj == ilastmoveb) &&
      (Board[ibuttonj][3] != 'l')))
    {
      Board[ibuttonj][3] = 'l';
    }
    sprintf (History[ihistory][ibuttonj], "%s", Board[ibuttonj]);
  }
  if (jbccolor == 'w')
  {
    TimeHistory[ihistory] = itimeb - (unsigned)time(&tm);
  }
  else
  {
    TimeHistory[ihistory] = itimew - (unsigned)time(&tm);
  }
  if (TimeHistory[ihistory] < 0)
  {
    TimeHistory[ihistory] = 0;
  }
  if ((biscomputer == 0) || (wiscomputer == 0))
  {
    pass[ihistory] = 0;
  }
  StatusBar ();
  while (gtk_events_pending ())
  {
    gtk_main_iteration ();
  }
}
