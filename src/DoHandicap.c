/* gtkgo 0.0.10 (DoHandicap.c) - 05/17/99
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

#include "DoHandicap.h"

void DoHandicap (void)
{
  ijustrestart = 1;
  for (icheckboard = 1; icheckboard <= 361; icheckboard++)
  {
    if ((Board[icheckboard][2] == 'w') || (Board[icheckboard][2] == 'b'))
    {
      ChangePixmap (icheckboard, 'e');
    }
  }
  if ((ihandicap == 0) && (biscomputer == 1))
  {
    Computer ('b');
    JudgeBoard ('w');
  }
  if ((ihandicap == 1) && (inet == 1))
  {
    sprintf (Board[73], "%s", "mmb"); Change (73);
  }
  if (ihandicap == 2)
  {
    sprintf (Board[73], "%s", "mmb"); Change (73);
    sprintf (Board[289], "%s", "mmb"); Change (289);
  }
  if (ihandicap == 3)
  {
    sprintf (Board[61], "%s", "mmb"); Change (61);
    sprintf (Board[73], "%s", "mmb"); Change (73);
    sprintf (Board[289], "%s", "mmb"); Change (289);
  }
  if (ihandicap == 4)
  {
    sprintf (Board[61], "%s", "mmb"); Change (61);
    sprintf (Board[301], "%s", "mmb"); Change (301);
    sprintf (Board[73], "%s", "mmb"); Change (73);
    sprintf (Board[289], "%s", "mmb"); Change (289);
  }
  if (ihandicap == 5)
  {
    sprintf (Board[61], "%s", "mmb"); Change (61);
    sprintf (Board[301], "%s", "mmb"); Change (301);
    sprintf (Board[73], "%s", "mmb"); Change (73);
    sprintf (Board[289], "%s", "mmb"); Change (289);
    sprintf (Board[181], "%s", "mmb"); Change (181);
  }
  if (ihandicap == 6)
  {
    sprintf (Board[61], "%s", "mmb"); Change (61);
    sprintf (Board[301], "%s", "mmb"); Change (301);
    sprintf (Board[73], "%s", "mmb"); Change (73);
    sprintf (Board[289], "%s", "mmb"); Change (289);
    sprintf (Board[175], "%s", "mmb"); Change (175);
    sprintf (Board[187], "%s", "mmb"); Change (187);
  }
  if (ihandicap == 7)
  {
    sprintf (Board[61], "%s", "mmb"); Change (61);
    sprintf (Board[301], "%s", "mmb"); Change (301);
    sprintf (Board[73], "%s", "mmb"); Change (73);
    sprintf (Board[289], "%s", "mmb"); Change (289);
    sprintf (Board[175], "%s", "mmb"); Change (175);
    sprintf (Board[187], "%s", "mmb"); Change (187);
    sprintf (Board[181], "%s", "mmb"); Change (181);
  }
  if (ihandicap >= 8)
  {
    sprintf (Board[61], "%s", "mmb"); Change (61);
    sprintf (Board[301], "%s", "mmb"); Change (301);
    sprintf (Board[73], "%s", "mmb"); Change (73);
    sprintf (Board[289], "%s", "mmb"); Change (289);
    sprintf (Board[175], "%s", "mmb"); Change (175);
    sprintf (Board[187], "%s", "mmb"); Change (187);
    sprintf (Board[67], "%s", "mmb"); Change (67);
    sprintf (Board[295], "%s", "mmb"); Change (295);
  }
  if (ihandicap >= 9)
  {
    sprintf (Board[181], "%s", "mmb"); Change (181);
  }
  if (ihandicap >= 10)
  {
    sprintf (Board[41], "%s", "mmb"); Change (41);
  }
  if (ihandicap >= 11)
  {
    sprintf (Board[321], "%s", "mmb"); Change (321);
  }
  if (ihandicap >= 12)
  {
    sprintf (Board[55], "%s", "mmb"); Change (55);
  }
  if (ihandicap >= 13)
  {
    sprintf (Board[307], "%s", "mmb"); Change (307);
  }
  if (ihandicap >= 14)
  {
    sprintf (Board[121], "%s", "mmb"); Change (121);
  }
  if (ihandicap >= 15)
  {
    sprintf (Board[241], "%s", "mmb"); Change (241);
  }
  if (ihandicap >= 16)
  {
    sprintf (Board[127], "%s", "mmb"); Change (127);
  }
  if (ihandicap == 17)
  {
    sprintf (Board[235], "%s", "mmb"); Change (235);
  }
  ilastmoveb = 1000;
  if (ihandicap != 0)
  {
    JudgeBoard ('w');
  }
  else
  {
    istarthand = 0;
    StatusBar ();
  }
  if ((ihandicap != 0) && (wiscomputer == 1))
  {
    Computer ('w');
    JudgeBoard ('b');
  }
}
