/* gtkgo 0.0.10 (Quit.c) - 05/17/99
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

#include "Quit.h"

void Quit (void)
{
  if ((ifilestuff == 0) && (iyesno == 0))
  {
    if (ihistory > 1)
    {
      itype = 1;
      AskSave ();
    }
    else
    {
      if (ichangestuff == 0)
      {
        Play ("click.mp3", 0);
      }
      Play ("", 2);
      itype = 4;
      ReallyQuit (NULL, NULL);
    }
  }
  else
  {
    if (ichangestuff == 0)
    {
      Play ("click.mp3", 0);
    }
  }
}
