/* gtkgo 0.0.9 (MyLand.c) - 05/17/99
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

#include "MyLand.h"

int MyLand (char mlccolor)
{
  ilscore = 0;
  for (ibuttonml = 1; ibuttonml <= 361; ibuttonml++)
  {
    icheckthing[ibuttonml] = 0;
  }
  for (ibuttonml = 1; ibuttonml <= 361; ibuttonml++)
  {
    if ((Board[ibuttonml][2] == 'e') || (Board[ibuttonml][2] == 's'))
    {
      if ((Board[ibuttonml - 1][2] == 'b') ||
        (Board[ibuttonml + 1][2] == 'b') ||
        (Board[ibuttonml - 19][2] == 'b') ||
        (Board[ibuttonml + 19][2] == 'b'))
      {
        icheckthing[ibuttonml] += 1;
      }
      if ((Board[ibuttonml - 1][2] == 'w') ||
        (Board[ibuttonml + 1][2] == 'w') ||
        (Board[ibuttonml - 19][2] == 'w') ||
        (Board[ibuttonml + 19][2] == 'w'))
      {
        icheckthing[ibuttonml] += 2;
      }
    }
    else
    {
      if (Board[ibuttonml][2] == 'b')
      {
        icheckthing[ibuttonml] = 4;
      }
      if (Board[ibuttonml][2] == 'w')
      {
        icheckthing[ibuttonml] = 5;
      }
    }
  }

  /* Make every 0 connecting 1 -> 1 */
  do
  {
    icheckchanged = 0;
    for (ibuttonml = 1; ibuttonml <= 361; ibuttonml++)
    {
      if (icheckthing[ibuttonml] == 1)
      {
        if ((icheckthing[ibuttonml - 1] == 0) && (Modulo (ibuttonml - 1, 19) != 0))
        {
          icheckthing[ibuttonml - 1] = 1;
          icheckchanged = 1;
        }
        if ((icheckthing[ibuttonml + 1] == 0) && (Modulo (ibuttonml, 19) != 0))
        {
          icheckthing[ibuttonml + 1] = 1;
          icheckchanged = 1;
        }
        if ((icheckthing[ibuttonml - 19] == 0) && (ibuttonml > 19))
        {
          icheckthing[ibuttonml - 19] = 1;
          icheckchanged = 1;
        }
        if ((icheckthing[ibuttonml + 19] == 0) && (ibuttonml < 343))
        {
          icheckthing[ibuttonml + 19] = 1;
          icheckchanged = 1;
        }
      }
    }
  } while (icheckchanged != 0);

  /* Make every 0 connecting 2 -> 2 */
  do
  {
    icheckchanged = 0;
    for (ibuttonml = 1; ibuttonml <= 361; ibuttonml++)
    {
      if (icheckthing[ibuttonml] == 2)
      {
        if ((icheckthing[ibuttonml - 1] == 0) && (Modulo (ibuttonml - 1, 19) != 0))
        {
          icheckthing[ibuttonml - 1] = 2;
          icheckchanged = 1;
        }
        if ((icheckthing[ibuttonml + 1] == 0) && (Modulo (ibuttonml, 19) != 0))
        {
          icheckthing[ibuttonml + 1] = 2;
          icheckchanged = 1;
        }
        if ((icheckthing[ibuttonml - 19] == 0) && (ibuttonml > 19))
        {
          icheckthing[ibuttonml - 19] = 2;
          icheckchanged = 1;
        }
        if ((icheckthing[ibuttonml + 19] == 0) && (ibuttonml < 343))
        {
          icheckthing[ibuttonml + 19] = 2;
          icheckchanged = 1;
        }
      }
    }
  } while (icheckchanged != 0);

  /* Make every 1 connecting 2 -> 3 */
  do
  {
    icheckchanged = 0;
    for (ibuttonml = 1; ibuttonml <= 361; ibuttonml++)
    {
      if (icheckthing[ibuttonml] == 1)
      {
        if ((icheckthing[ibuttonml - 1] == 2) && (Modulo (ibuttonml - 1, 19) != 0))
        {
          icheckthing[ibuttonml - 1] = 3;
          icheckchanged = 1;
        }
        if ((icheckthing[ibuttonml + 1] == 2) && (Modulo (ibuttonml, 19) != 0))
        {
          icheckthing[ibuttonml + 1] = 3;
          icheckchanged = 1;
        }
        if ((icheckthing[ibuttonml - 19] == 2) && (ibuttonml > 19))
        {
          icheckthing[ibuttonml - 19] = 3;
          icheckchanged = 1;
        }
        if ((icheckthing[ibuttonml + 19] == 2) && (ibuttonml < 343))
        {
          icheckthing[ibuttonml + 19] = 3;
          icheckchanged = 1;
        }
      }
    }
  } while (icheckchanged != 0);

  /* Make every 0, 1 and 2 connecting 3 -> 3 */
  do
  {
    icheckchanged = 0;
    for (ibuttonml = 1; ibuttonml <= 361; ibuttonml++)
    {
      if (icheckthing[ibuttonml] == 3)
      {
        if ((icheckthing[ibuttonml - 1] < 3) && (Modulo (ibuttonml - 1, 19) != 0))
        {
          icheckthing[ibuttonml - 1] = 3;
          icheckchanged = 1;
        }
        if ((icheckthing[ibuttonml + 1] < 3) && (Modulo (ibuttonml, 19) != 0))
        {
          icheckthing[ibuttonml + 1] = 3;
          icheckchanged = 1;
        }
        if ((icheckthing[ibuttonml - 19] < 3) && (ibuttonml > 19))
        {
          icheckthing[ibuttonml - 19] = 3;
          icheckchanged = 1;
        }
        if ((icheckthing[ibuttonml + 19] < 3) && (ibuttonml < 343))
        {
          icheckthing[ibuttonml + 19] = 3;
          icheckchanged = 1;
        }
      }
    }
  } while (icheckchanged != 0);

  for (ibuttonml = 1; ibuttonml <= 361; ibuttonml++)
  {
    if (mlccolor == 'b')
    {
      if (icheckthing[ibuttonml] == 1)
      {
        ilscore++;
      }
    }
    if (mlccolor == 'w')
    {
      if (icheckthing[ibuttonml] == 2)
      {
        ilscore++;
      }
    }
  }
  return (ilscore);
}
