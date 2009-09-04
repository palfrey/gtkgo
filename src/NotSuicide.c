/* gtkgo 0.0.10 (NotSuicide.c) - 05/17/99
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

#include "NotSuicide.h"

int NotSuicide (int insbutton, char nsccolor)
{
  iyeahs = 0;
  ireturns = 0;
  if (nsccolor == 'b')
  {
    nsnotccolor = 'w';
  }
  else
  {
    nsnotccolor = 'b';
  }
  if (Board[insbutton][2] != nsccolor)
  {
    if (Board[insbutton][2] == 'e')
    {
      iyeahs = 1;
    }
    if (Board[insbutton][2] == 's')
    {
      iyeahs = 2;
    }
    if ((iyeahs == 1) || (iyeahs == 2))
    {
      sprintf (Board[insbutton], "%c%c%c", Board[insbutton][0],
        Board[insbutton][1], nsccolor);
    }
  }
  if (Modulo (insbutton - 1, 19) != 0)
  {
    if (Board[insbutton - 1][2] == nsnotccolor)
    {
      if (CheckSides (insbutton - 1, nsnotccolor, 1) == 15)
        ireturns = 1;
    }
  }
  if (Modulo (insbutton, 19) != 0)
  {
    if (Board[insbutton + 1][2] == nsnotccolor)
    {
      if (CheckSides (insbutton + 1, nsnotccolor, 1) == 15)
        ireturns = 1;
    }
  }
  if (insbutton >= 20)
  {
    if (Board[insbutton - 19][2] == nsnotccolor)
    {
      if (CheckSides (insbutton - 19, nsnotccolor, 1) == 15)
        ireturns = 1;
    }
  }
  if (insbutton <= 342)
  {
    if (Board[insbutton + 19][2] == nsnotccolor)
    {
      if (CheckSides (insbutton + 19, nsnotccolor, 1) == 15)
        ireturns = 1;
    }
  }
  if (iyeahs == 1)
  {
    sprintf (Board[insbutton], "%c%c%c", Board[insbutton][0],
      Board[insbutton][1], 'e');
  }
  if (iyeahs == 2)
  {
    sprintf (Board[insbutton], "%c%c%c", Board[insbutton][0],
      Board[insbutton][1], 's');
  }
  return (ireturns);
}
