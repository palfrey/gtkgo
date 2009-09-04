/* gtkgo 0.0.10 (Hint.c) - 05/17/99
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

#include "Hint.h"

void Hint (void)
{
  /* The next 4 lines must be there. */
  while (gtk_events_pending ())
  {
    gtk_main_iteration ();
  }
  if (ichangestuff == 0)
  {
    Play ("click.mp3", 0);
  }
  if ((((ifilestuff == 0) && ((biscomputer == 0) || (wiscomputer == 0)) &&
    (iyesno == 0)) && (((((Modulo (imoves, 2) == 0) && (iiamblack == 1)) ||
    ((Modulo (imoves, 2) != 0) && (iiamblack == 0))) && (inet == 1)) ||
    (inet == 0))) && (imoving == 0))
  {
    imoving = 1;
    if (Modulo (imoves, 2) == 0)
    {
      if (inet == 1) idohint = 1;
      Computer ('b');
      idohint = 0;
      JudgeBoard ('w');
      if (wiscomputer == 1)
      {
        Computer ('w');
        JudgeBoard ('b');
      }
    }
    else
    {
      if (inet == 1) idohint = 1;
      Computer ('w');
      idohint = 0;
      JudgeBoard ('b');
      if (biscomputer == 1)
      {
        Computer ('b');
        JudgeBoard ('w');
      }
    }
    imoving = 0;
  }
  else
  {
    if (inet == 1)
    {
      Message ("It is not your move.", 3, 0);
    }
  }
}
