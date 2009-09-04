/* gtkgo 0.0.10 (ReSize.c) - 05/17/99
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

#include "ReSize.h"

void ReSize (void)
{
  if ((ifilestuff == 0) && ((biscomputer == 0) || (wiscomputer == 0))
    && (iyesno == 0))
  {
    switch (isize)
    {
      case 1: isize = 2; break;
      case 2: isize = 3; break;
      case 3: isize = 1; break;
    }
    gtk_widget_hide (window1);
    MainWindow ();
    ReStart (2);
  }
  else
  {
    if (ichangestuff == 0)
    {
      Play ("click.mp3", 0);
    }
  }
}
