/* gtkgo 0.0.10 (BoardPlace.c) - 05/17/99
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

char* BoardPlace (int iplacetype, int iboardplace)
{
  icount = 1;
  while (iboardplace >= 20)
  {
    iboardplace -= 19;
    icount++;
  }
  if (iplacetype == 1)
  {
    switch (icount)
    {
      case 1: sprintf (splace, "%s", "a"); break;
      case 2: sprintf (splace, "%s", "b"); break;
      case 3: sprintf (splace, "%s", "c"); break;
      case 4: sprintf (splace, "%s", "d"); break;
      case 5: sprintf (splace, "%s", "e"); break;
      case 6: sprintf (splace, "%s", "f"); break;
      case 7: sprintf (splace, "%s", "g"); break;
      case 8: sprintf (splace, "%s", "h"); break;
      case 9: sprintf (splace, "%s", "i"); break;
      case 10: sprintf (splace, "%s", "j"); break;
      case 11: sprintf (splace, "%s", "k"); break;
      case 12: sprintf (splace, "%s", "l"); break;
      case 13: sprintf (splace, "%s", "m"); break;
      case 14: sprintf (splace, "%s", "n"); break;
      case 15: sprintf (splace, "%s", "o"); break;
      case 16: sprintf (splace, "%s", "p"); break;
      case 17: sprintf (splace, "%s", "q"); break;
      case 18: sprintf (splace, "%s", "r"); break;
      case 19: sprintf (splace, "%s", "s"); break;
    }
  }
  else
  {
    switch (icount)
    {
      case 1: sprintf (splace, "%s", "19"); break;
      case 2: sprintf (splace, "%s", "18"); break;
      case 3: sprintf (splace, "%s", "17"); break;
      case 4: sprintf (splace, "%s", "16"); break;
      case 5: sprintf (splace, "%s", "15"); break;
      case 6: sprintf (splace, "%s", "14"); break;
      case 7: sprintf (splace, "%s", "13"); break;
      case 8: sprintf (splace, "%s", "12"); break;
      case 9: sprintf (splace, "%s", "11"); break;
      case 10: sprintf (splace, "%s", "10"); break;
      case 11: sprintf (splace, "%s", "9"); break;
      case 12: sprintf (splace, "%s", "8"); break;
      case 13: sprintf (splace, "%s", "7"); break;
      case 14: sprintf (splace, "%s", "6"); break;
      case 15: sprintf (splace, "%s", "5"); break;
      case 16: sprintf (splace, "%s", "4"); break;
      case 17: sprintf (splace, "%s", "3"); break;
      case 18: sprintf (splace, "%s", "2"); break;
      case 19: sprintf (splace, "%s", "1"); break;
    }
  }
  if (iplacetype == 1)
  {
    switch (iboardplace)
    {
      case 1: sprintf (splace2, "%s%s", "a", splace); break;
      case 2: sprintf (splace2, "%s%s", "b", splace); break;
      case 3: sprintf (splace2, "%s%s", "c", splace); break;
      case 4: sprintf (splace2, "%s%s", "d", splace); break;
      case 5: sprintf (splace2, "%s%s", "e", splace); break;
      case 6: sprintf (splace2, "%s%s", "f", splace); break;
      case 7: sprintf (splace2, "%s%s", "g", splace); break;
      case 8: sprintf (splace2, "%s%s", "h", splace); break;
      case 9: sprintf (splace2, "%s%s", "i", splace); break;
      case 10: sprintf (splace2, "%s%s", "j", splace); break;
      case 11: sprintf (splace2, "%s%s", "k", splace); break;
      case 12: sprintf (splace2, "%s%s", "l", splace); break;
      case 13: sprintf (splace2, "%s%s", "m", splace); break;
      case 14: sprintf (splace2, "%s%s", "n", splace); break;
      case 15: sprintf (splace2, "%s%s", "o", splace); break;
      case 16: sprintf (splace2, "%s%s", "p", splace); break;
      case 17: sprintf (splace2, "%s%s", "q", splace); break;
      case 18: sprintf (splace2, "%s%s", "r", splace); break;
      case 19: sprintf (splace2, "%s%s", "s", splace); break;
    }
  }
  else
  {
    switch (iboardplace)
    {
      case 1: sprintf (splace2, "%s%s", "A", splace); break;
      case 2: sprintf (splace2, "%s%s", "B", splace); break;
      case 3: sprintf (splace2, "%s%s", "C", splace); break;
      case 4: sprintf (splace2, "%s%s", "D", splace); break;
      case 5: sprintf (splace2, "%s%s", "E", splace); break;
      case 6: sprintf (splace2, "%s%s", "F", splace); break;
      case 7: sprintf (splace2, "%s%s", "G", splace); break;
      case 8: sprintf (splace2, "%s%s", "H", splace); break;
      case 9: sprintf (splace2, "%s%s", "J", splace); break;
      case 10: sprintf (splace2, "%s%s", "K", splace); break;
      case 11: sprintf (splace2, "%s%s", "L", splace); break;
      case 12: sprintf (splace2, "%s%s", "M", splace); break;
      case 13: sprintf (splace2, "%s%s", "N", splace); break;
      case 14: sprintf (splace2, "%s%s", "O", splace); break;
      case 15: sprintf (splace2, "%s%s", "P", splace); break;
      case 16: sprintf (splace2, "%s%s", "Q", splace); break;
      case 17: sprintf (splace2, "%s%s", "R", splace); break;
      case 18: sprintf (splace2, "%s%s", "S", splace); break;
      case 19: sprintf (splace2, "%s%s", "T", splace); break;
    }
  }
  return (splace2);
}
