/* gtkgo 0.0.10 (ChangePixmap.c) - 05/17/99
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

#include "ChangePixmap.h"

int ChangePixmap (int icpbutton, char cpccolor)
{
  iOkp = 1;
  if ((butrem[ihistory] == icpbutton) && (HowMany (icpbutton, cpccolor) == 1))
  {
    return (0);
  }
  if ((inotside == 1) && (iother != 1))
  {
    if ((Modulo ((icpbutton - 1), 19) == 0) ||
      (Modulo (icpbutton, 19) == 0) ||
      (icpbutton <= 19) ||
      (icpbutton >= 343))
    {
      return (0);
    }
  }
  if ((inotown == 1) && (iother != 1))
  {
    if (FreePlace (icpbutton, cpccolor, '!') == 1)
    {
      return (0);
    }
  }
  if ((inotother == 1) && (iother != 1))
  {
    if (FreePlace (icpbutton, cpccolor, '.') == 1)
    {
      return (0);
    }
  }
  if ((cpccolor == 'b') || (cpccolor == 'w'))
  {
    if ((strcmp (Board[icpbutton], "mme") == 0) &&
       (((CheckSides (icpbutton, cpccolor, 1) != 15) ||
         ((NotSuicide (icpbutton, cpccolor) == 1) &&
         (CheckSides (icpbutton, cpccolor, 1) == 15)))))
    {
      if (ishowlast == 1)
      {
        sprintf (Board[icpbutton], "%s%cl", "mm", cpccolor);
      }
      else
      {
        sprintf (Board[icpbutton], "%s%c", "mm", cpccolor);
      }
    } else
    if ((strcmp (Board[icpbutton], "mms") == 0) &&
       (((CheckSides (icpbutton, cpccolor, 1) != 15) ||
         ((NotSuicide (icpbutton, cpccolor) == 1) &&
         (CheckSides (icpbutton, cpccolor, 1) == 15)))))
    {
      if (ishowlast == 1)
      {
        sprintf (Board[icpbutton], "%s%cl", "mm", cpccolor);
      }
      else
      {
        sprintf (Board[icpbutton], "%s%c", "mm", cpccolor);
      }
    } else
    if ((strcmp (Board[icpbutton], "lte") == 0) &&
       (((CheckSides (icpbutton, cpccolor, 1) != 15) ||
         ((NotSuicide (icpbutton, cpccolor) == 1) &&
         (CheckSides (icpbutton, cpccolor, 1) == 15)))))
    {
      if (ishowlast == 1)
      {
        sprintf (Board[icpbutton], "%s%cl", "lt", cpccolor);
      }
      else
      {
        sprintf (Board[icpbutton], "%s%c", "lt", cpccolor);
      }
    } else
    if ((strcmp (Board[icpbutton], "lue") == 0) &&
       (((CheckSides (icpbutton, cpccolor, 1) != 15) ||
         ((NotSuicide (icpbutton, cpccolor) == 1) &&
         (CheckSides (icpbutton, cpccolor, 1) == 15)))))
    {
      if (ishowlast == 1)
      {
        sprintf (Board[icpbutton], "%s%cl", "lu", cpccolor);
      }
      else
      {
        sprintf (Board[icpbutton], "%s%c", "lu", cpccolor);
      }
    } else
    if ((strcmp (Board[icpbutton], "rte") == 0) &&
       (((CheckSides (icpbutton, cpccolor, 1) != 15) ||
         ((NotSuicide (icpbutton, cpccolor) == 1) &&
         (CheckSides (icpbutton, cpccolor, 1) == 15)))))
    {
      if (ishowlast == 1)
      {
        sprintf (Board[icpbutton], "%s%cl", "rt", cpccolor);
      }
      else
      {
        sprintf (Board[icpbutton], "%s%c", "rt", cpccolor);
      }
    } else
    if ((strcmp (Board[icpbutton], "rue") == 0) &&
       (((CheckSides (icpbutton, cpccolor, 1) != 15) ||
         ((NotSuicide (icpbutton, cpccolor) == 1) &&
         (CheckSides (icpbutton, cpccolor, 1) == 15)))))
    {
      if (ishowlast == 1)
      {
        sprintf (Board[icpbutton], "%s%cl", "ru", cpccolor);
      }
      else
      {
        sprintf (Board[icpbutton], "%s%c", "ru", cpccolor);
      }
    } else
    if ((strcmp (Board[icpbutton], "lme") == 0) &&
       (((CheckSides (icpbutton, cpccolor, 1) != 15) ||
         ((NotSuicide (icpbutton, cpccolor) == 1) &&
         (CheckSides (icpbutton, cpccolor, 1) == 15)))))
    {
      if (ishowlast == 1)
      {
        sprintf (Board[icpbutton], "%s%cl", "lm", cpccolor);
      }
      else
      {
        sprintf (Board[icpbutton], "%s%c", "lm", cpccolor);
      }
    } else
    if ((strcmp (Board[icpbutton], "mte") == 0) &&
       (((CheckSides (icpbutton, cpccolor, 1) != 15) ||
         ((NotSuicide (icpbutton, cpccolor) == 1) &&
         (CheckSides (icpbutton, cpccolor, 1) == 15)))))
    {
      if (ishowlast == 1)
      {
        sprintf (Board[icpbutton], "%s%cl", "mt", cpccolor);
      }
      else
      {
        sprintf (Board[icpbutton], "%s%c", "mt", cpccolor);
      }
    } else
    if ((strcmp (Board[icpbutton], "rme") == 0) &&
       (((CheckSides (icpbutton, cpccolor, 1) != 15) ||
         ((NotSuicide (icpbutton, cpccolor) == 1) &&
         (CheckSides (icpbutton, cpccolor, 1) == 15)))))
    {
      if (ishowlast == 1)
      {
        sprintf (Board[icpbutton], "%s%cl", "rm", cpccolor);
      }
      else
      {
        sprintf (Board[icpbutton], "%s%c", "rm", cpccolor);
      }
    } else
    if ((strcmp (Board[icpbutton], "mue") == 0) &&
       (((CheckSides (icpbutton, cpccolor, 1) != 15) ||
         ((NotSuicide (icpbutton, cpccolor) == 1) &&
         (CheckSides (icpbutton, cpccolor, 1) == 15)))))
    {
      if (ishowlast == 1)
      {
        sprintf (Board[icpbutton], "%s%cl", "mu", cpccolor);
      }
      else
      {
        sprintf (Board[icpbutton], "%s%c", "mu", cpccolor);
      }
    } else
      iOkp = 0;
  }
  if (cpccolor == 'e')
  {
    if ((strcmp (Board[icpbutton], "mmw") == 0) ||
      (strcmp (Board[icpbutton], "mmb") == 0) ||
      (strcmp (Board[icpbutton], "mmwl") == 0) ||
      (strcmp (Board[icpbutton], "mmbl") == 0))
    {
      if ((icpbutton == 61) || (icpbutton == 67) || (icpbutton == 73) ||
        (icpbutton == 175) || (icpbutton == 181) || (icpbutton == 187) ||
        (icpbutton == 289) || (icpbutton == 295) || (icpbutton == 301))
      {
        sprintf (Board[icpbutton], "%s", "mms");
      }
      else
      {
        sprintf (Board[icpbutton], "%s", "mme");
      }
    }
    if ((strcmp (Board[icpbutton], "ltw") == 0) ||
      (strcmp (Board[icpbutton], "ltb") == 0) ||
      (strcmp (Board[icpbutton], "ltwl") == 0) ||
      (strcmp (Board[icpbutton], "ltbl") == 0))
      { sprintf (Board[icpbutton], "%s", "lte"); }
    if ((strcmp (Board[icpbutton], "luw") == 0) ||
      (strcmp (Board[icpbutton], "lub") == 0) ||
      (strcmp (Board[icpbutton], "luwl") == 0) ||
      (strcmp (Board[icpbutton], "lubl") == 0))
      { sprintf (Board[icpbutton], "%s", "lue"); }
    if ((strcmp (Board[icpbutton], "rtw") == 0) ||
      (strcmp (Board[icpbutton], "rtb") == 0) ||
      (strcmp (Board[icpbutton], "rtwl") == 0) ||
      (strcmp (Board[icpbutton], "rtbl") == 0))
      { sprintf (Board[icpbutton], "%s", "rte"); }
    if ((strcmp (Board[icpbutton], "ruw") == 0) ||
      (strcmp (Board[icpbutton], "rub") == 0) ||
      (strcmp (Board[icpbutton], "ruwl") == 0) ||
      (strcmp (Board[icpbutton], "rubl") == 0))
      { sprintf (Board[icpbutton], "%s", "rue"); }
    if ((strcmp (Board[icpbutton], "lmw") == 0) ||
      (strcmp (Board[icpbutton], "lmb") == 0) ||
      (strcmp (Board[icpbutton], "lmwl") == 0) ||
      (strcmp (Board[icpbutton], "lmbl") == 0))
      { sprintf (Board[icpbutton], "%s", "lme"); }
    if ((strcmp (Board[icpbutton], "mtw") == 0) ||
      (strcmp (Board[icpbutton], "mtb") == 0) ||
      (strcmp (Board[icpbutton], "mtwl") == 0) ||
      (strcmp (Board[icpbutton], "mtbl") == 0))
      { sprintf (Board[icpbutton], "%s", "mte"); }
    if ((strcmp (Board[icpbutton], "rmw") == 0) ||
      (strcmp (Board[icpbutton], "rmb") == 0) ||
      (strcmp (Board[icpbutton], "rmwl") == 0) ||
      (strcmp (Board[icpbutton], "rmbl") == 0))
      { sprintf (Board[icpbutton], "%s", "rme"); }
    if ((strcmp (Board[icpbutton], "muw") == 0) ||
      (strcmp (Board[icpbutton], "mub") == 0) ||
      (strcmp (Board[icpbutton], "muwl") == 0) ||
      (strcmp (Board[icpbutton], "mubl") == 0))
      { sprintf (Board[icpbutton], "%s", "mue"); }
  }
  if (iOkp == 1)
  {
    for (ibuttonl = 1; ibuttonl <= 361; ibuttonl++)
    {
      if ((Board[ibuttonl][3] == 'l') && (Board[ibuttonl][2] == cpccolor) &&
        (icpbutton != ibuttonl))
      {
        Board[ibuttonl][3] = '\0';
        Change (ibuttonl);
      }
    }
    Change (icpbutton);
    iremoved = 0;
    if (cpccolor == 'b')
    {
      ilastmoveb = icpbutton;
      if (ichangestuff == 0)
      {
        Play ("blackm.mp3", 0);
      }
    }
    if (cpccolor == 'w')
    {
      ilastmovew = icpbutton;
      if (ichangestuff == 0)
      {
        Play ("whitem.mp3", 0);
      }
    }
    idone = 1;
  }
  if ((inet == 1) && (idohint == 1))
  {
    SendData (1, BoardPlace (2, icpbutton));
  }
  return (iOkp);
}
