/* gtkgo 0.0.10 (ReStart.c) - 05/17/99
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

#include "ReStart.h"

void ReStart (int iReCheck)
{
  if ((iReCheck != 1) && (ichangestuff == 0)
    && (((ihistory == 0) && (ihandicap == istarthand)) || (ifilestuff != 0)
    || (iyesno != 0) || ((inet == 1) && (iReCheck != 2))))
  {
    Play ("click.mp3", 0);
  }
  if (((iReCheck == 2) || (iReCheck == 0)
    || (iReCheck == 1)
    || ((ihistory > 0) || ((ihistory == 0) && (ihandicap != istarthand))))
    && (ifilestuff == 0) && ((biscomputer == 0) || (wiscomputer == 0))
    && (iyesno == 0) && ((inet == 0) || ((inet == 1) && (iReCheck == 2))))
  {
    if (iReCheck != 2)
    {
      if (ihistory > 0)
      {
        itype = 2;
        AskSave ();
      }
      else
      {
        ReallyReStart (NULL, NULL);
      }
    }
    else
    {
      if (ichangestuff == 0)
      {
        Play ("click.mp3", 0);
      }
      gtk_widget_hide (window1);
      x = 0;
      y = 0;
      for (ibuttonr = 1; ibuttonr <= 361; ibuttonr++)
      {
        PixmapOnButton (ibuttonr);
      }
      if (itooltips == 0)
      {
        itooltips = 1;
        Tooltips ();
      }
      gtk_widget_show (window1);
    }
  }
}
