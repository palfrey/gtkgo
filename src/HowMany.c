/* gtkgo 0.0.10 (HowMany.c) - 05/17/99
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

#include "HowMany.h"

int HowMany (int hmbutton, char hmccolor)
{
  icounter = 0;
  if (Board[hmbutton][2] == 'e')
  {
    cwas = 'e';
  }
  else
  if (Board[hmbutton][2] == 's')
  {
    cwas = 's';
  }
  else
    return (0);
  Board[hmbutton][2] = hmccolor;
  if (hmccolor == 'b')
  {
    nothmccolor = 'w';
  }
  else
  {
    nothmccolor = 'b';
  }
  for (icolor = 1; icolor <= 361; icolor++)
  {
    if (Board[icolor][2] == nothmccolor)
    {
      if (CheckSides (icolor, nothmccolor, 2) == 15)
      {
        icounter++;
      }
    }
  }
  if (cwas == 'e')
  {
    Board[hmbutton][2] = 'e';
  }
  else
  {
    Board[hmbutton][2] = 's';
  }
  return (icounter);
}
