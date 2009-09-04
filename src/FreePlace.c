/* gtkgo 0.0.10 (FreePlace.c) - 05/17/99
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

#include "FreePlace.h"

int FreePlace (int ifpbutton, char fpccolor, char fpctype)
{
  if (fpccolor == 'b')
  {
    fpnotccolor = 'w';
  }
  else
  {
    fpnotccolor = 'b';
  }
  if (fpctype == 'F')
  {
    ifree = 0;
    if ((Modulo ((ifpbutton - 1), 19) != 0) && (Modulo (ifpbutton, 19) != 0)
      && (ifpbutton >= 20) && (ifpbutton <= 342))
    {
      if (((Board[ifpbutton - 20][2] == 's') ||
        (Board[ifpbutton - 20][2] == 'e'))
      && ((Board[ifpbutton - 19][2] == 's') ||
        (Board[ifpbutton - 19][2] == 'e'))
      && ((Board[ifpbutton - 18][2] == 's') ||
        (Board[ifpbutton - 18][2] == 'e'))
      && ((Board[ifpbutton - 1][2] == 's') ||
        (Board[ifpbutton - 1][2] == 'e'))
      && ((Board[ifpbutton + 1][2] == 's') ||
        (Board[ifpbutton + 1][2] == 'e'))
      && ((Board[ifpbutton + 18][2] == 's') ||
        (Board[ifpbutton + 18][2] == 'e'))
      && ((Board[ifpbutton + 19][2] == 's') ||
        (Board[ifpbutton + 19][2] == 'e'))
      && ((Board[ifpbutton + 20][2] == 's') ||
        (Board[ifpbutton + 20][2] == 'e'))
      && (Board[ifpbutton][2] != 'b') && (Board[ifpbutton][2] != 'w'))
      {
        ifree = 1;
      }
    }
  }
  if (fpctype == 'f')
  {
    ifree = 0;
    iown = 0;
    if (Modulo ((ifpbutton - 1), 19) != 0)
    {
      if ((Board[ifpbutton - 1][2] == 's') || (Board[ifpbutton - 1][2] == 'e'))
      {
        ifree++;
      }
      if (ifpbutton >= 21)
      {
        if (Board[ifpbutton - 20][2] == fpccolor)
          iown++;
      }
      if (ifpbutton <= 342)
      {
        if (Board[ifpbutton + 18][2] == fpccolor)
          iown++;
      }
    } else ifree++;
    if (Modulo (ifpbutton, 19) != 0)
    {
      if ((Board[ifpbutton + 1][2] == 's') || (Board[ifpbutton + 1][2] == 'e'))
      {
        ifree++;
      }
      if (ifpbutton >= 20)
      {
        if (Board[ifpbutton - 18][2] == fpccolor)
          iown++;
      }
      if (ifpbutton <= 343)
      {
        if (Board[ifpbutton + 20][2] == fpccolor)
          iown++;
      }
    } else ifree++;
    if (ifpbutton >= 20)
    {
      if ((Board[ifpbutton - 19][2] == 's') ||
        (Board[ifpbutton - 19][2] == 'e'))
        ifree++;
    } else ifree++;
    if (ifpbutton <= 342)
    {
      if ((Board[ifpbutton + 19][2] == 's') ||
        (Board[ifpbutton + 19][2] == 'e'))
        ifree++;
    } else ifree++;
    if ((iown == 1)
    && (ifree == 4)
    && (Board[ifpbutton][2] != 'b')
    && (Board[ifpbutton][2] != 'w'))
    {
      ifree = 1;
    }
    else
    {
      ifree = 0;
    }
  }
  if (fpctype == '!')
  {
    ifree = 0;
    if (Modulo ((ifpbutton - 1), 19) != 0)
    {
      if (Board[ifpbutton - 1][2] == fpccolor)
      {
        ifree++;
      }
    } else ifree++;
    if (Modulo (ifpbutton, 19) != 0)
    {
      if (Board[ifpbutton + 1][2] == fpccolor)
      {
        ifree++;
      }
    } else ifree++;
    if (ifpbutton >= 20)
    {
      if (Board[ifpbutton - 19][2] == fpccolor)
        ifree++;
    } else ifree++;
    if (ifpbutton <= 342)
    {
      if (Board[ifpbutton + 19][2] == fpccolor)
        ifree++;
    } else ifree++;
    if (((ifree == 3) || (ifree == 4))
      && (NotSuicide (ifpbutton, fpnotccolor) == 0)
      && (Board[ifpbutton][2] != 'b')
      && (Board[ifpbutton][2] != 'w'))
    {
      ifree = 1;
    }
    else
    {
      ifree = 0;
    }
  }
  if (fpctype == '.')
  {
    ifree = 0;
    if (Modulo ((ifpbutton - 1), 19) != 0)
    {
      if (Board[ifpbutton - 1][2] == fpnotccolor)
      {
        ifree++;
      }
    } else ifree++;
    if (Modulo (ifpbutton, 19) != 0)
    {
      if (Board[ifpbutton + 1][2] == fpnotccolor)
      {
        ifree++;
      }
    } else ifree++;
    if (ifpbutton >= 20)
    {
      if (Board[ifpbutton - 19][2] == fpnotccolor)
        ifree++;
    } else ifree++;
    if (ifpbutton <= 342)
    {
      if (Board[ifpbutton + 19][2] == fpnotccolor)
        ifree++;
    } else ifree++;
    if ((ifree > 1)
    && (Board[ifpbutton][2] != 'b')
    && (Board[ifpbutton][2] != 'w'))
    {
      ifree = 1;
    }
    else
    {
      ifree = 0;
    }
  }
  if (fpctype == 'M')
  {
    ifree = 0;
    if (Modulo ((ifpbutton - 1), 19) != 0)
    {
      if (Board[ifpbutton - 1][2] == fpccolor)
        ifree++;
    }
    if (Modulo (ifpbutton, 19) != 0)
    {
      if (Board[ifpbutton + 1][2] == fpccolor)
        ifree++;
    }
    if (ifpbutton >= 20)
    {
      if (Board[ifpbutton - 19][2] == fpccolor)
        ifree++;
    }
    if (ifpbutton <= 342)
    {
      if (Board[ifpbutton + 19][2] == fpccolor)
        ifree++;
    }
    if ((ifree > 1)
    && (Board[ifpbutton][2] != 'b')
    && (Board[ifpbutton][2] != 'w'))
    {
      ifree = 1;
    }
    else
    {
      ifree = 0;
    }
  }
  return (ifree);
}
