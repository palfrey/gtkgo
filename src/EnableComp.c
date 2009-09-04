/* gtkgo 0.0.10 (EnableComp.c) - 05/17/99
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

#include "EnableComp.h"

void EnableComp (GtkWidget *ecw, GtkFileSelection *ecfs)
{
  ichangeit = 0;
  sprintf (stempname, "%s", "");
  newtemp = gtk_file_selection_get_filename (GTK_FILE_SELECTION (ecfs));
  if ((newtemp[strlen (newtemp) - 1] == 'o') &&
    (newtemp[strlen (newtemp) - 2] == 'g') &&
    (newtemp[strlen (newtemp) - 3] == 'k') &&
    (newtemp[strlen (newtemp) - 4] == 't') &&
    (newtemp[strlen (newtemp) - 5] == 'g') &&
    (newtemp[strlen (newtemp) - 6] == '.'))
  {
    iname = 7;
    do
    {
      sprintf (thename, "%c%s", newtemp[strlen (newtemp) - iname], stempname);
      sprintf (stempname, "%s", thename);
      iname++;
    } while (newtemp[strlen (newtemp) - iname] != '/');
    sprintf (thenamecomp, PKGDATADIR"computers/%s.gtkgo", thename);
    if (ichangecolor == 2)
    {
      if ((open (thenamecomp, O_RDONLY, 0600) != -1) &&
        (strcmp (thename, bplayername) != 0) &&
        (strcmp (thename, "") != 0))
      {
        sprintf (bplayername, "%s", thename);
        biscomputer = 1;
        ichangeit = 1;
      }
    }
    else
    {
      if ((open (thenamecomp, O_RDONLY, 0600) != -1) &&
        (strcmp (thename, wplayername) != 0) &&
        (strcmp (thename, "") != 0))
      {
        sprintf (wplayername, "%s", thename);
        wiscomputer = 1;
        ichangeit = 1;
      }
    }
  }
  DestroyChange ();
  if (ifilestuff == 1)
  {
    DestroyOptions ();
  }
  if (ichangeit == 1)
  {
    StatusBar ();
    if ((ihistory > 0) && ((biscomputer != 1) || (wiscomputer != 1)))
    {
      itype = 2;
      AskSave ();
    }
    else
    {
      if ((biscomputer == 1) && (wiscomputer != 1))
      {
        Computer ('b');
        JudgeBoard ('w');
      }
    }
  }
  if ((biscomputer == 1) && (wiscomputer == 1))
  {
    istarthand = ihandicap;
    if (imoves > 1)
    {
      ihistory = 0;
      ReallyReStart (NULL, NULL);
    }
    do {
      /* Start with white, because of DoHandicap */
      Computer ('w');
      JudgeBoard ('b');
      if (iyesno != 1)
      {
        Computer ('b');
        JudgeBoard ('w');
      }
    } while (iyesno != 1);
  }
}
