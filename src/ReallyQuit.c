/* gtkgo 0.0.10 (ReallyQuit.c) - 05/17/99
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

#include "ReallyQuit.h"

void ReallyQuit (GtkWidget *rqw, GtkFileSelection *rqfs)
{
  if (itype == 1)
  {
    if (((wiscomputer == 1) && (biscomputer == 0)) ||
      ((wiscomputer == 0) && (biscomputer == 0) && (Modulo (imoves, 2) == 0)) ||
      ((wiscomputer == 1) && (biscomputer == 1) && (Modulo (imoves, 2) == 0)))
    {
      JudgeBoard ('w');
      sprintf (stemptxt, "%s/W wins (resign).", wplayername);
      if (isave == 1)
      {
        Save ();
      }
      Message (stemptxt, 1, 1);
    }
    if (((biscomputer == 1) && (wiscomputer == 0)) ||
      ((biscomputer == 0) && (wiscomputer == 0) && (Modulo (imoves, 2) != 0)) ||
      ((biscomputer == 1) && (wiscomputer == 1) && (Modulo (imoves, 2) != 0)))
    {
      JudgeBoard ('b');
      sprintf (stemptxt, "%s/B wins (resign).", bplayername);
      if (isave == 1)
      {
        Save ();
      }
      Message (stemptxt, 1, 1);
    }
  }
  if (itype == 3)
  {
    if (((isleftb <= 0) && (imleftb == 0) && (ihleftb == 0)) || ((isleftw <= 0)
      && (imleftw == 0) && (ihleftw == 0)))
    {
      if ((isleftb <= 0) && (imleftb == 0) && (ihleftb == 0))
      {
        sprintf (stemptxt, "%s/W wins (time).", wplayername);
      }
      if ((isleftw <= 0) && (imleftw == 0) && (ihleftw == 0))
      {
        sprintf (stemptxt, "%s/B wins (time).", bplayername);
      }
      if (isave == 1)
      {
        Save ();
      }
      Message (stemptxt, 1, 1);
    }
    else
    {
      if ((Modulo (ihistory, 2) == 0) &&
        ((biscomputer == 0) || (wiscomputer == 0)))
      {
        JudgeBoard ('w');
        if (iduh == 1)
        {
          pass[ihistory] = 1;
        }
      }
      if ((Modulo (ihistory, 2) != 0) &&
        ((biscomputer == 0) || (wiscomputer == 0)))
      {
        JudgeBoard ('b');
        if (iduh == 1)
        {
          pass[ihistory] = 1;
        }
      }
      if (iscoreblack > iscorewhite)
      {
        sprintf (stemptxt, "%s/B wins (+%.1f).", bplayername, iscoreblack -
          iscorewhite);
        if (isave == 1)
        {
          Save ();
        }
        Message (stemptxt, 1, 1);
      }
      if (iscoreblack < iscorewhite)
      {
        sprintf (stemptxt, "%s/W wins (+%.1f).", wplayername, iscorewhite -
          iscoreblack);
        if (isave == 1)
        {
          Save ();
        }
        Message (stemptxt, 1, 1);
      }
      if (iscoreblack == iscorewhite)
      {
        if (isave == 1)
        {
          Save ();
        }
        Message ("Same scores (0).", 1, 1);
      }
    }
  }
  isavedes = open (sthesavef, O_CREAT | O_TRUNC | O_WRONLY, 0600);
  if (isavedes != -1)
  {
    sprintf (stext2, "%s", "# gtkgo skin/time settings.\n\n");
    write (isavedes, stext2, strlen (stext2));
    sprintf (stext2, "%s\n", sskin);
    write (isavedes, stext2, strlen (stext2));
    sprintf (stext2, "%i\n", ioptionsx);
    write (isavedes, stext2, strlen (stext2));
    sprintf (stext2, "%i\n", itimelimit);
    write (isavedes, stext2, strlen (stext2));
    close (isavedes);
  }
  if (itype == 4)
  {
    gtk_exit (0);
  }
}
