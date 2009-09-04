/* gtkgo 0.0.10 (StatusBar.c) - 05/17/99
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

#include "StatusBar.h"

void StatusBar (void)
{
  if ((isize == 1) && ((iyesno == 0) || (iselectdead == 1)))
  {
    if (iselectdead == 0)
    {
      if (imoves >= 1)
      {
        if (Modulo (imoves, 2) == 0)
        {
          itsleftw = itimew - (unsigned)time(&tm);
        }
        else
        {
          itsleftb = itimeb - (unsigned)time(&tm);
        }
        ihleftb = 0;
        imleftb = 0;
        isleftb = itsleftb;
        if (isleftb > 59)
        {
          do
          {
            isleftb -= 60;
            imleftb++;
          } while (isleftb >= 60);
        }
        if (imleftb > 59)
        {
          do
          {
            imleftb -= 60;
            ihleftb++;
          } while (imleftb >= 60);
        }
        ihleftw = 0;
        imleftw = 0;
        isleftw = itsleftw;
        if (isleftw > 59)
        {
          do
          {
            isleftw -= 60;
            imleftw++;
          } while (isleftw >= 60);
        }
        if (imleftw > 59)
        {
          do
          {
            imleftw -= 60;
            ihleftw++;
          } while (imleftw >= 60);
        }
      }
      else
      {
        isleftb = 0;
        imleftb = itimelimit;
        ihleftb = 0;
        if (imleftb > 59)
        {
          ihleftb = 0;
          do
          {
            imleftb -= 60;
            ihleftb++;
          } while (imleftb >= 60);
        }
        isleftw = isleftb;
        imleftw = imleftb;
        ihleftw = ihleftb;
      }
      if (((isleftb <= 0) && (imleftb == 0) && (ihleftb == 0)) ||
        ((isleftw <= 0) && (imleftw == 0) && (ihleftw == 0)))
      {
        itype = 3;
        AskSave ();
        if (isleftb < 0)
        {
          isleftb = 0;
        }
        if (isleftw < 0)
        {
          isleftw = 0;
        }
      }
      if (isleftb < 10)
      {
        sprintf (ssleftb, "0%i", isleftb);
      }
      else
      {
        sprintf (ssleftb, "%i", isleftb);
      }
      if (imleftb < 10)
      {
        sprintf (smleftb, "0%i", imleftb);
      }
      else
      {
        sprintf (smleftb, "%i", imleftb);
      }
      if (ihleftb != 0)
      {
        sprintf (shleftb, "%i:", ihleftb);
      }
      else
      {
        sprintf (shleftb, "%s", "");
      }
      if (isleftw < 10)
      {
        sprintf (ssleftw, "0%i", isleftw);
      }
      else
      {
        sprintf (ssleftw, "%i", isleftw);
      }
      if (imleftw < 10)
      {
        sprintf (smleftw, "0%i", imleftw);
      }
      else
      {
        sprintf (smleftw, "%i", imleftw);
      }
      if (ihleftw != 0)
      {
        sprintf (shleftw, "%i:", ihleftw);
      }
      else
      {
        sprintf (shleftw, "%s", "");
      }
    }

    iscoreblack = ScoreBlack ();
    if (biscomputer == 1)
    {
      sprintf (sstatusbar, " Black computer %s has score %.1f (%i captures) "
        "and %s%s:%s time left.", bplayername, iscoreblack, iCapturedW,
        shleftb, smleftb, ssleftb);
    }
    else
    {
      sprintf (sstatusbar, " Black player %s has score %.1f (%i captures) "
        "and %s%s:%s time left.", bplayername, iscoreblack, iCapturedW,
        shleftb, smleftb, ssleftb);
    }
    gtk_statusbar_push (GTK_STATUSBAR (statbar2), 1, sstatusbar);

    iscorewhite = ScoreWhite ();
    if (wiscomputer == 1)
    {
      sprintf (sstatusbar, " White computer %s has score %.1f (%i captures) "
        "and %s%s:%s time left.", wplayername, iscorewhite, iCapturedB,
        shleftw, smleftw, ssleftw);
    }
    else
    {
      sprintf (sstatusbar, " White player %s has score %.1f (%i captures) "
        "and %s%s:%s time left.", wplayername, iscorewhite, iCapturedB,
        shleftw, smleftw, ssleftw);
    }
    gtk_statusbar_push (GTK_STATUSBAR (statbar3), 1, sstatusbar);

    if (Modulo (imoves, 2) == 0)
    {
      gtk_statusbar_push (GTK_STATUSBAR (statbar), 1, "  black\n  to move");
    }
    else
    {
      gtk_statusbar_push (GTK_STATUSBAR (statbar), 1, "  white\n  to move");
    }
  }
}
