/* gtkgo 0.0.10 (Save.c) - 05/17/99
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

#include "Save.h"

void Save (void)
{
  if (isave == 1)
  {
    gtk_widget_destroy (yesnowindow);
    iyesno = 0;
  }
  if (ilimit == 0)
  {
    sthefile = gtk_file_selection_get_filename (GTK_FILE_SELECTION (files2));
    ifiled = open (sthefile, O_CREAT | O_TRUNC | O_WRONLY, 0600);
  }
  if ((ifiled == -1) || (ilimit == 1))
  {
    Message ("Saving unsuccesfull.", 0, 0);
  }
  else
  {
    sprintf (stext, "%s", "(\n;GM[1]\nFF[4]\nRU[Japanese]\nSZ[19]\n");
    write (ifiled, stext, strlen (stext));
    sprintf (stext, "HA[%i]\n", istarthand);
    write (ifiled, stext, strlen (stext));
    write (ifiled, "KM[5.5]\n", 8);
    sprintf (stext, "PB[%s]\n", bplayername);
    write (ifiled, stext, strlen (stext));
    sprintf (stext, "PW[%s]\n", wplayername);
    write (ifiled, stext, strlen (stext));
    sprintf (stext, "GN[%s/W vs %s/B]\n", wplayername, bplayername);
    write (ifiled, stext, strlen (stext));
    write (ifiled, "AP[gtkgo:0.0.10]\n", 17);
    if ((itype == 1) || (itype == 2))
    {
      if ((isleftb <= 0) && (imleftb == 0) && (ihleftb == 0))
      {
        write (ifiled, "RE[W+Time]\n", 11);
      }
      else
      if ((isleftw <= 0) && (imleftw == 0) && (ihleftw == 0))
      {
        write (ifiled, "RE[B+Time]\n", 11);
      }
      else
      {
        write (ifiled, "RE[W+Resign]\n", 13);
      }
    }
    else
    {
      iscorewhite = ScoreWhite ();
      iscoreblack = ScoreBlack ();
      if (iscorewhite > iscoreblack)
      {
        sprintf (stext, "RE[W+%.1f]\n", iscorewhite - iscoreblack);
        write (ifiled, stext, strlen (stext));
      }
      if (iscorewhite < iscoreblack)
      {
        sprintf (stext, "RE[B+%.1f]\n", iscoreblack - iscorewhite);
        write (ifiled, stext, strlen (stext));
      }
      if (iscorewhite == iscoreblack)
      {
        write (ifiled, "RE[0]\n", 6);
      }
    }
    sprintf (stext, "TM[%i]\n", (itimelimit * 60));
    write (ifiled, stext, strlen (stext));
    switch (istarthand)
    {
      case 2: write (ifiled, ";AB[dd];AB[pp]", 14); break;
      case 3: write (ifiled, ";AB[dd];AB[pp];AB[pd]", 21); break;
      case 4: write (ifiled, ";AB[dd];AB[pp];AB[pd];AB[dp]", 28); break;
      case 5: write (ifiled, ";AB[dd];AB[pp];AB[pd];AB[dp];AB[jj]", 35);
        break;
      case 6: write (ifiled, ";AB[dd];AB[pp];AB[pd];AB[dp];AB[dj];AB[pj]",
        42); break;
      case 7: write (ifiled, ";AB[dd];AB[pp];AB[pd];AB[dp];AB[dj];AB[pj]"
        ";AB[jj]", 49);
    }
    if (istarthand >= 8)
    {
      write (ifiled, ";AB[dd];AB[pp];AB[pd];AB[dp];AB[dj];AB[pj]"
        ";AB[jd];AB[jp]", 56);
    }
    if (istarthand >= 9)
    {
      write (ifiled, ";AB[jj]", 7);
    }
    if (istarthand >= 10)
    {
      write (ifiled, ";AB[cc]\n", 7);
    }
    if (istarthand >= 11)
    {
      write (ifiled, "\n;AB[qq]", 8);
    }
    if (istarthand >= 12)
    {
      write (ifiled, ";AB[qc]", 7);
    }
    if (istarthand >= 13)
    {
      write (ifiled, ";AB[cq]", 7);
    }
    if (istarthand >= 14)
    {
      write (ifiled, ";AB[gg]", 7);
    }
    if (istarthand >= 15)
    {
      write (ifiled, ";AB[mm]", 7);
    }
    if (istarthand >= 16)
    {
      write (ifiled, ";AB[mg]", 7);
    }
    if (istarthand == 17)
    {
      write (ifiled, ";AB[gm]", 7);
    }
    if (istarthand >= 2)
    {
      write (ifiled, "\n", 1);
    }
    for (idoit = 0; idoit <= ihistory; idoit++)
    {
      if ((itype == 3) || ((itype != 3) && (idoit != ihistory)))
      {
        if (pass[idoit] == 1)
        {
          if (((cstart == 'b') && (Modulo (idoit, 2) == 0))
            || ((cstart == 'w') && (Modulo (idoit, 2) != 0)))
          {
            write (ifiled, ";W[]", 4);
          }
          else
          {
            write (ifiled, ";B[]", 4);
          }
        }
        else
        {
          for (ibuttons = 1; ibuttons <= 361; ibuttons++)
          {
            if (History[idoit][ibuttons][3] == 'l')
            {
              if (((History[idoit][ibuttons][2] == 'b')
                && (((cstart == 'b') && (Modulo (idoit, 2) != 0))
                || ((cstart == 'w') && (Modulo (idoit, 2) == 0))))
                && (ibuttons != iblackdone))
              {
                sprintf (stext, ";B[%s]", BoardPlace (1, ibuttons));
                write (ifiled, stext, strlen (stext));
                iblacktemp = ibuttons;
              }
              if (((History[idoit][ibuttons][2] == 'w')
                && (((cstart == 'b') && (Modulo (idoit, 2) == 0))
                || ((cstart == 'w') && (Modulo (idoit, 2) != 0))))
                && (ibuttons != iwhitedone))
              {
                sprintf (stext, ";W[%s]", BoardPlace (1, ibuttons));
                write (ifiled, stext, strlen (stext));
                iwhitetemp = ibuttons;
              }
            }
          }
          if (idoit >= 1)
          {
            if (((cstart == 'b') && (Modulo (idoit, 2) == 0))
              || ((cstart == 'w') && (Modulo (idoit, 2) != 0)))
            {
              sprintf (stext, "WL[%i]", TimeHistory[idoit]);
              write (ifiled, stext, strlen (stext));
            }
            else
            {
              sprintf (stext, "BL[%i]", TimeHistory[idoit]);
              write (ifiled, stext, strlen (stext));
            }
          }
          iblackdone = iblacktemp;
          iwhitedone = iwhitetemp;
        }
        if ((Modulo (idoit, 5) == 0) && (idoit != 0))
        {
          write (ifiled, "\n", 1);
        }
      }
    }
    write (ifiled, "\n)\n", 3);
    close (ifiled);
    sprintf (stemptt, "%s succesfully saved.", sthefile);
    Message (stemptt, 0, 1);
  }
}
