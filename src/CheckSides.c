/* gtkgo 0.0.9 (CheckSides.c) - 05/17/99
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

#include "CheckSides.h"

int CheckSides (int icsbutton, char csccolor, int csitype)
{
  if ((csitype > 0) && (csitype < 4))
  {
    iyeah = 0;
    ichecked = 0;
    if (Board[icsbutton][2] != csccolor)
    {
      if (Board[icsbutton][2] == 'e')
      {
        iyeah = 1;
      }
      else
      {
        iyeah = 2;
      }
      sprintf (Board[icsbutton], "%c%c%c", Board[icsbutton][0],
        Board[icsbutton][1], csccolor);
    }
    for (iclear = 1; iclear <= 361; iclear++)
    {
      ireturn[iclear] = 0;
      Checked[iclear] = 0;
    }
  }

  if (Checked[icsbutton] == 1)
  {
    return (15);
  }
  Checked[icsbutton] = 1;
  ichecked++;

  if (csccolor == 'w')
  {
    csnotccolor = 'b';
  }
  else
  {
    csnotccolor = 'w';
  }

  if ((Modulo ((icsbutton - 1), 19) == 0)
    || (Checked[icsbutton - 1] == 2)
    || ((Modulo ((icsbutton - 1), 19) != 0)
      && (Board[icsbutton - 1][2] == csnotccolor))
    || ((Modulo ((icsbutton - 1), 19) != 0)
      && (Board[icsbutton - 1][2] == csccolor)
      && (CheckSides ((icsbutton - 1), csccolor, 0) == 15)))
  {
    ireturn[icsbutton] += 1;
  }
  else
    Checked[icsbutton - 1] = 2;
  if ((Modulo ((icsbutton), 19) == 0)
    || (Checked[icsbutton + 1] == 2)
    || ((Modulo ((icsbutton), 19) != 0)
      && (Board[icsbutton + 1][2] == csnotccolor))
    || ((Modulo ((icsbutton), 19) != 0)
      && (Board[icsbutton + 1][2] == csccolor)
      && (CheckSides ((icsbutton + 1), csccolor, 0) == 15)))
  {
    ireturn[icsbutton] += 2;
  }
  else
    Checked[icsbutton + 1] = 2;
  if (((icsbutton >= 1) && (icsbutton <= 19))
    || (Checked[icsbutton - 19] == 2)
    || ((icsbutton > 19)
      && (Board[icsbutton - 19][2] == csnotccolor))
    || ((icsbutton > 19)
      && (Board[icsbutton - 19][2] == csccolor)
      && (CheckSides ((icsbutton - 19), csccolor, 0) == 15)))
  {
    ireturn[icsbutton] += 4;
  }
  else
    Checked[icsbutton - 19] = 2;
  if (((icsbutton >= 343) && (icsbutton <= 361))
    || (Checked[icsbutton + 19] == 2)
    || ((icsbutton < 343)
      && (Board[icsbutton + 19][2] == csnotccolor))
    || ((icsbutton < 343)
      && (Board[icsbutton + 19][2] == csccolor)
      && (CheckSides ((icsbutton + 19), csccolor, 0) == 15)))
  {
    ireturn[icsbutton] += 8;
  }
  else
    Checked[icsbutton + 19] = 2;
  if ((csitype == 1) || (csitype == 2))
  {
    if (iyeah == 1)
    {
      sprintf (Board[icsbutton], "%c%c%c", Board[icsbutton][0],
        Board[icsbutton][1], 'e');
    }
    if (iyeah == 2)
    {
      sprintf (Board[icsbutton], "%c%c%c", Board[icsbutton][0],
        Board[icsbutton][1], 's');
    }
  }
  if (csitype == 3)
  {
    return (ichecked);
  }
  else
  {
    return (ireturn[icsbutton]);
  }
}
