/* gtkgo 0.0.10 (Computer.c) - 05/17/99
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

#include "Computer.h"

void Computer (char cccolor)
{
  /* The next 4 lines must be there. */
  while (gtk_events_pending ())
  {
    gtk_main_iteration ();
  }

  idone = 0;
  inotside = 0;
  inotown = 0;
  inotother = 0;
  iok = 1;
  i50p = 0;
  iok2 = 1;
  i10p = 0;
  iok3 = 1;
  idid = 0;
  i30moves = 0;
  iok4 = 0;

  if (cccolor == 'w')
  {
    if (wiscomputer == 1)
    {
      sprintf (thefile, PKGDATADIR"computers/%s.gtkgo", wplayername);
    }
    else
    {
      if (biscomputer == 0)
      {
        sprintf (thefile, "%s", PKGDATADIR"computers/default2.gtkgo");
      }
      else
      {
        sprintf (thefile, PKGDATADIR"computers/%s.gtkgo", bplayername);
      }
    }
    cnotccolor = 'b';
  }
  else
  {
    if (biscomputer == 1)
    {
      sprintf (thefile, PKGDATADIR"computers/%s.gtkgo", bplayername);
    }
    else
    {
      if (wiscomputer == 0)
      {
        sprintf (thefile, "%s", PKGDATADIR"computers/default2.gtkgo");
      }
      else
      {
        sprintf (thefile, PKGDATADIR"computers/%s.gtkgo", wplayername);
      }
    }
    cnotccolor = 'w';
  }

  ifiledes = open (thefile, O_RDONLY, 0600);
  if (ifiledes == -1)
  {
    Message ("Could not open computer.", 1, 0);
  }
  else
  do
  {
    if (idid != 1)
    {
      ireturned = read (ifiledes, schar, 1);
    }
    else
    {
      idid = 0;
    }
    if (ireturned == -1)
    {
      Message ("Error reading computer.", 1, 0);
    }
    else
    {

      if (i30moves == 1)
      {
        if (imoves >= 49)
        {
          iok4 = 1;
        }
        else
        {
          iok4 = 0;
        }
      }
      else
      {
        iok4 = 1;
      }

      /* # */

      if ((schar[0] == '#') && (idone == 0))
      {
        if (iok3 == 0)
        {
          iok3 = 1;
        }
        else
        {
          iok3 = 0;
        }
      }

      /* + */

      if ((schar[0] == '+') && (idone == 0) && (iok == 1) && (iok3 == 1) &&
        (iok4 == 1))
      {
        if (i10p == 1)
        {
          iok2 = 1;
          i10p = 0;
        }
        else
        {
          ido = 1 + (int) (10.0 * random() / (RAND_MAX + 1.0));
          if (ido != 10)
          {
            iok2 = 0;
          }
          i10p = 1;
        }
      }

      /* % */

      if ((schar[0] == '%') && (idone == 0) && (iok2 == 1) && (iok3 == 1) &&
        (iok4 == 1))
      {
        if (i50p == 1)
        {
          iok = 1;
          i50p = 0;
        }
        else
        {
          ido = 1 + (int) (2.0 * random() / (RAND_MAX + 1.0));
          if (ido == 2)
          {
            iok = 0;
          }
          i50p = 1;
        }
      }

      /* * */

      if ((schar[0] == '*') && (idone == 0) && (iok == 1) && (iok2 == 1)
        && (iok3 == 1))
      {
        if (i30moves == 0)
        {
          i30moves = 1;
        }
        else
        {
          i30moves = 0;
        }
      }

      if ((iok == 1) && (iok2 == 1) && (iok3 == 1) && (iok4 == 1))
      {

      /* z */

      if ((schar[0] == 'z') && (idone == 0))
      {
        for (ictemp = 1; ictemp <= 5; ictemp++)
        {
          for (ictemp2 = 1; ictemp2 <= 5; ictemp2++)
          {
            ieye[ictemp][ictemp2] = 0;
          }
        }
        do
        {
          ireturned = read (ifiledes, schar, 1);
          if (ireturned == -1)
          {
            Message ("Error reading computer.", 1, 0);
          }
          switch (schar[0])
          {
            case 'a': ieye[1][1] = 1; break;
            case 'b': ieye[1][2] = 1; break;
            case 'c': ieye[1][3] = 1; break;
            case 'd': ieye[1][4] = 1; break;
            case 'e': ieye[1][5] = 1; break;
            case 'f': ieye[2][1] = 1; break;
            case 'g': ieye[2][2] = 1; break;
            case 'h': ieye[2][3] = 1; break;
            case 'i': ieye[2][4] = 1; break;
            case 'j': ieye[2][5] = 1; break;
            case 'k': ieye[3][1] = 1; break;
            case 'l': ieye[3][2] = 1; break;
            case 'm': ieye[3][3] = 1; break;
            case 'n': ieye[3][4] = 1; break;
            case 'o': ieye[3][5] = 1; break;
            case 'p': ieye[4][1] = 1; break;
            case 'q': ieye[4][2] = 1; break;
            case 'r': ieye[4][3] = 1; break;
            case 's': ieye[4][4] = 1; break;
            case 't': ieye[4][5] = 1; break;
            case 'u': ieye[5][1] = 1; break;
            case 'v': ieye[5][2] = 1; break;
            case 'w': ieye[5][3] = 1; break;
            case 'x': ieye[5][4] = 1; break;
            case 'y': ieye[5][5] = 1;
          }
        } while ((schar[0] != '/') && (ireturned != 0));
        if (ireturned == 0)
        {
          Message ("Incorrect computer.", 1, 0);
        }
        sprintf (sctemp, "%s", "");
        do
        {
          ireturned = read (ifiledes, schar, 1);
          if (ireturned == -1)
          {
            Message ("Error reading computer.", 1, 0);
          }
          if ((schar[0] == '0') || (schar[0] == '1') || (schar[0] == '2') ||
            (schar[0] == '3') || (schar[0] == '4') || (schar[0] == '5') ||
            (schar[0] == '6') || (schar[0] == '7') || (schar[0] == '8') ||
            (schar[0] == '9'))
          {
            sprintf (ssides, "%s%c", sctemp, schar[0]);
            sprintf (sctemp, "%s", ssides);
          }
          else idid = 1;
        } while ((idid == 0) && (ireturned != 0));
        if (ireturned == 0)
        {
          Message ("Incorrect computer.", 1, 0);
        }
        idid = 0;
        do
        {
          switch (schar[0])
          {
            case 'a': ieye[1][1] = 2; break;
            case 'b': ieye[1][2] = 2; break;
            case 'c': ieye[1][3] = 2; break;
            case 'd': ieye[1][4] = 2; break;
            case 'e': ieye[1][5] = 2; break;
            case 'f': ieye[2][1] = 2; break;
            case 'g': ieye[2][2] = 2; break;
            case 'h': ieye[2][3] = 2; break;
            case 'i': ieye[2][4] = 2; break;
            case 'j': ieye[2][5] = 2; break;
            case 'k': ieye[3][1] = 2; break;
            case 'l': ieye[3][2] = 2; break;
            case 'm': ieye[3][3] = 2; break;
            case 'n': ieye[3][4] = 2; break;
            case 'o': ieye[3][5] = 2; break;
            case 'p': ieye[4][1] = 2; break;
            case 'q': ieye[4][2] = 2; break;
            case 'r': ieye[4][3] = 2; break;
            case 's': ieye[4][4] = 2; break;
            case 't': ieye[4][5] = 2; break;
            case 'u': ieye[5][1] = 2; break;
            case 'v': ieye[5][2] = 2; break;
            case 'w': ieye[5][3] = 2; break;
            case 'x': ieye[5][4] = 2; break;
            case 'y': ieye[5][5] = 2;
          }
          ireturned = read (ifiledes, schar, 1);
          if (ireturned == -1)
          {
            Message ("Error reading computer.", 1, 0);
          }
        } while ((schar[0] != 'z') && (ireturned != 0));
        if (ireturned == 0)
        {
          Message ("Incorrect computer.", 1, 0);
        }
        for (ibuttonc = 1; ibuttonc <= 361; ibuttonc++)
        {
          if (idone != 1)
          {
            ineed = 0;
            istopit = 0;

            /* a */

            if ((ieye[1][1] == 1) && (istopit != 1))
            {
              if ((ibuttonc <= 19) ||
                (Modulo (ibuttonc - 1, 19) == 0))
              {
                istopit = 1;
              }
              if ((Board[ibuttonc - 20][2] != 'e') &&
                (Board[ibuttonc - 20][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[1][1] == 2) && (istopit != 1))
            {
              if ((ibuttonc > 19) &&
                (Modulo (ibuttonc - 1, 19) != 0))
              {
                if (Board[ibuttonc - 20][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc - 20][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc - 20;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* b */

            if ((ieye[1][2] == 1) && (istopit != 1))
            {
              if (ibuttonc <= 19)
              {
                istopit = 1;
              }
              if ((Board[ibuttonc - 19][2] != 'e') &&
                (Board[ibuttonc - 19][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[1][2] == 2) && (istopit != 1))
            {
              if (ibuttonc > 19)
              {
                if (Board[ibuttonc - 19][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc - 19][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc - 19;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* c */

            if ((ieye[1][3] == 1) && (istopit != 1))
            {
              if ((ibuttonc <= 19) ||
                (Modulo (ibuttonc, 19) == 0))
              {
                istopit = 1;
              }
              if ((Board[ibuttonc - 18][2] != 'e') &&
                (Board[ibuttonc - 18][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[1][3] == 2) && (istopit != 1))
            {
              if ((ibuttonc > 19) &&
                (Modulo (ibuttonc, 19) != 0))
              {
                if (Board[ibuttonc - 18][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc - 18][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc - 18;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* d */

            if ((ieye[1][4] == 1) && (istopit != 1))
            {
              if (Modulo (ibuttonc, 19) == 0)
              {
                istopit = 1;
              }
              if ((ibuttonc <= 19) ||
                (Modulo (ibuttonc + 1, 19) == 0))
              {
                istopit = 1;
              }
              if ((Board[ibuttonc - 17][2] != 'e') &&
                (Board[ibuttonc - 17][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[1][4] == 2) && (istopit != 1))
            {
              if (Modulo (ibuttonc, 19) == 0)
              {
                istopit = 1;
              }
              if ((ibuttonc > 19) &&
                (Modulo (ibuttonc + 1, 19) != 0))
              {
                if (Board[ibuttonc - 17][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc - 17][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc - 17;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* e */

            if ((ieye[1][5] == 1) && (istopit != 1))
            {
              if ((Modulo (ibuttonc, 19) == 0) ||
                (Modulo (ibuttonc + 1, 19) == 0))
              {
                istopit = 1;
              }
              if ((ibuttonc <= 19) ||
                (Modulo (ibuttonc + 2, 19) == 0))
              {
                istopit = 1;
              }
              if ((Board[ibuttonc - 16][2] != 'e') &&
                (Board[ibuttonc - 16][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[1][5] == 2) && (istopit != 1))
            {
              if ((Modulo (ibuttonc, 19) == 0) ||
                (Modulo (ibuttonc + 1, 19) == 0))
              {
                istopit = 1;
              }
              if ((ibuttonc > 19) &&
                (Modulo (ibuttonc + 2, 19) != 0))
              {
                if (Board[ibuttonc - 16][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc - 16][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc - 16;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* f */

            if ((ieye[2][1] == 1) && (istopit != 1))
            {
              if (Modulo (ibuttonc - 1, 19) == 0)
              {
                istopit = 1;
              }
              if ((Board[ibuttonc - 1][2] != 'e') &&
                (Board[ibuttonc - 1][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[2][1] == 2) && (istopit != 1))
            {
              if (Modulo (ibuttonc - 1, 19) != 0)
              {
                if (Board[ibuttonc - 1][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc - 1][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc - 1;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* g */

            if ((ieye[2][2] == 1) && (istopit != 1))
            {
              if ((Board[ibuttonc][2] != 'e') &&
                (Board[ibuttonc][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[2][2] == 2) && (istopit != 1))
            {
              if (Board[ibuttonc][2] == cnotccolor)
              {
                istopit = 1;
              }
              if (Board[ibuttonc][2] != cccolor)
              {
                ineed++;
                if (ineed == 1) itheone = ibuttonc;
                if (ineed > atoi (ssides)) istopit = 1;
              }
            }

            /* h */

            if ((ieye[2][3] == 1) && (istopit != 1))
            {
              if (Modulo (ibuttonc, 19) == 0)
              {
                istopit = 1;
              }
              if ((Board[ibuttonc + 1][2] != 'e') &&
                (Board[ibuttonc + 1][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[2][3] == 2) && (istopit != 1))
            {
              if (Modulo (ibuttonc, 19) != 0)
              {
                if (Board[ibuttonc + 1][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc + 1][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc + 1;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* i */

            if ((ieye[2][4] == 1) && (istopit != 1))
            {
              if (Modulo (ibuttonc, 19) == 0)
              {
                istopit = 1;
              }
              if (Modulo (ibuttonc + 1, 19) == 0)
              {
                istopit = 1;
              }
              if ((Board[ibuttonc + 2][2] != 'e') &&
                (Board[ibuttonc + 2][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[2][4] == 2) && (istopit != 1))
            {
              if (Modulo (ibuttonc, 19) == 0)
              {
                istopit = 1;
              }
              if (Modulo (ibuttonc + 1, 19) != 0)
              {
                if (Board[ibuttonc + 2][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc + 2][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc + 2;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* j */

            if ((ieye[2][5] == 1) && (istopit != 1))
            {
              if ((Modulo (ibuttonc, 19) == 0) ||
                (Modulo (ibuttonc + 1, 19) == 0))
              {
                istopit = 1;
              }
              if (Modulo (ibuttonc + 2, 19) == 0)
              {
                istopit = 1;
              }
              if ((Board[ibuttonc + 3][2] != 'e') &&
                (Board[ibuttonc + 3][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[2][5] == 2) && (istopit != 1))
            {
              if ((Modulo (ibuttonc, 19) == 0) ||
                (Modulo (ibuttonc + 1, 19) == 0))
              {
                istopit = 1;
              }
              if (Modulo (ibuttonc + 2, 19) != 0)
              {
                if (Board[ibuttonc + 3][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc + 3][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc + 3;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* k */

            if ((ieye[3][1] == 1) && (istopit != 1))
            {
              if ((Modulo (ibuttonc - 1, 19) == 0) ||
                (ibuttonc >= 343))
              {
                istopit = 1;
              }
              if ((Board[ibuttonc + 18][2] != 'e') &&
                (Board[ibuttonc + 18][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[3][1] == 2) && (istopit != 1))
            {
              if ((Modulo (ibuttonc - 1, 19) != 0) &&
                (ibuttonc < 343))
              {
                if (Board[ibuttonc + 18][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc + 18][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc + 18;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* l */

            if ((ieye[3][2] == 1) && (istopit != 1))
            {
              if (ibuttonc >= 343)
              {
                istopit = 1;
              }
              if ((Board[ibuttonc + 19][2] != 'e') &&
                (Board[ibuttonc + 19][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[3][2] == 2) && (istopit != 1))
            {
              if (ibuttonc < 343)
              {
                if (Board[ibuttonc + 19][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc + 19][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc + 19;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* m */

            if ((ieye[3][3] == 1) && (istopit != 1))
            {
              if ((Modulo (ibuttonc, 19) == 0) ||
                (ibuttonc >= 343))
              {
                istopit = 1;
              }
              if ((Board[ibuttonc + 20][2] != 'e') &&
                (Board[ibuttonc + 20][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[3][3] == 2) && (istopit != 1))
            {
              if ((Modulo (ibuttonc, 19) != 0) &&
                (ibuttonc < 343))
              {
                if (Board[ibuttonc + 20][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc + 20][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc + 20;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* n */

            if ((ieye[3][4] == 1) && (istopit != 1))
            {
              if (Modulo (ibuttonc, 19) == 0)
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc + 1, 19) == 0) ||
                (ibuttonc >= 343))
              {
                istopit = 1;
              }
              if ((Board[ibuttonc + 21][2] != 'e') &&
                (Board[ibuttonc + 21][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[3][4] == 2) && (istopit != 1))
            {
              if (Modulo (ibuttonc, 19) == 0)
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc + 1, 19) != 0) &&
                (ibuttonc < 343))
              {
                if (Board[ibuttonc + 21][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc + 21][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc + 21;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* o */

            if ((ieye[3][5] == 1) && (istopit != 1))
            {
              if ((Modulo (ibuttonc, 19) == 0) ||
                (Modulo (ibuttonc + 1, 19) == 0))
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc + 2, 19) == 0) ||
                (ibuttonc >= 343))
              {
                istopit = 1;
              }
              if ((Board[ibuttonc + 22][2] != 'e') &&
                (Board[ibuttonc + 22][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[3][5] == 2) && (istopit != 1))
            {
              if ((Modulo (ibuttonc, 19) == 0) ||
                (Modulo (ibuttonc + 1, 19) == 0))
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc + 2, 19) != 0) &&
                (ibuttonc < 343))
              {
                if (Board[ibuttonc + 22][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc + 22][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc + 22;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* p */

            if ((ieye[4][1] == 1) && (istopit != 1))
            {
              if (ibuttonc >= 343)
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc - 1, 19) == 0) ||
                (ibuttonc >= 324))
              {
                istopit = 1;
              }
              if ((Board[ibuttonc + 37][2] != 'e') &&
                (Board[ibuttonc + 37][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[4][1] == 2) && (istopit != 1))
            {
              if (ibuttonc >= 343)
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc - 1, 19) != 0) &&
                (ibuttonc < 324))
              {
                if (Board[ibuttonc + 37][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc + 37][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc + 37;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* q */

            if ((ieye[4][2] == 1) && (istopit != 1))
            {
              if (ibuttonc >= 343)
              {
                istopit = 1;
              }
              if (ibuttonc >= 324)
              {
                istopit = 1;
              }
              if ((Board[ibuttonc + 38][2] != 'e') &&
                (Board[ibuttonc + 38][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[4][2] == 2) && (istopit != 1))
            {
              if (ibuttonc >= 343)
              {
                istopit = 1;
              }
              if (ibuttonc < 324)
              {
                if (Board[ibuttonc + 38][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc + 38][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc + 38;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* r */

            if ((ieye[4][3] == 1) && (istopit != 1))
            {
              if (ibuttonc >= 343)
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc, 19) == 0) ||
                (ibuttonc >= 324))
              {
                istopit = 1;
              }
              if ((Board[ibuttonc + 39][2] != 'e') &&
                (Board[ibuttonc + 39][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[4][3] == 2) && (istopit != 1))
            {
              if (ibuttonc >= 343)
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc, 19) != 0) &&
                (ibuttonc < 324))
              {
                if (Board[ibuttonc + 39][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc + 39][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc + 39;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* s */

            if ((ieye[4][4] == 1) && (istopit != 1))
            {
              if (ibuttonc >= 343)
              {
                istopit = 1;
              }
              if (Modulo (ibuttonc, 19) == 0)
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc + 1, 19) == 0) ||
                (ibuttonc >= 324))
              {
                istopit = 1;
              }
              if ((Board[ibuttonc + 40][2] != 'e') &&
                (Board[ibuttonc + 40][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[4][4] == 2) && (istopit != 1))
            {
              if (ibuttonc >= 343)
              {
                istopit = 1;
              }
              if (Modulo (ibuttonc, 19) == 0)
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc + 1, 19) != 0) &&
                (ibuttonc < 324))
              {
                if (Board[ibuttonc + 40][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc + 40][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc + 40;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* t */

            if ((ieye[4][5] == 1) && (istopit != 1))
            {
              if (ibuttonc >= 343)
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc, 19) == 0) ||
                (Modulo (ibuttonc + 1, 19) == 0))
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc + 2, 19) == 0) ||
                (ibuttonc >= 324))
              {
                istopit = 1;
              }
              if ((Board[ibuttonc + 41][2] != 'e') &&
                (Board[ibuttonc + 41][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[4][5] == 2) && (istopit != 1))
            {
              if (ibuttonc >= 343)
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc, 19) == 0) ||
                (Modulo (ibuttonc + 1, 19) == 0))
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc + 2, 19) != 0) &&
                (ibuttonc < 324))
              {
                if (Board[ibuttonc + 41][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc + 41][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc + 41;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* u */

            if ((ieye[5][1] == 1) && (istopit != 1))
            {
              if (ibuttonc >= 324)
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc - 1, 19) == 0) ||
                (ibuttonc >= 305))
              {
                istopit = 1;
              }
              if ((Board[ibuttonc + 56][2] != 'e') &&
                (Board[ibuttonc + 56][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[5][1] == 2) && (istopit != 1))
            {
              if (ibuttonc >= 324)
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc - 1, 19) != 0) &&
                (ibuttonc < 305))
              {
                if (Board[ibuttonc + 56][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc + 56][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc + 56;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* v */

            if ((ieye[5][2] == 1) && (istopit != 1))
            {
              if (ibuttonc >= 324)
              {
                istopit = 1;
              }
              if (ibuttonc >= 305)
              {
                istopit = 1;
              }
              if ((Board[ibuttonc + 57][2] != 'e') &&
                (Board[ibuttonc + 57][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[5][2] == 2) && (istopit != 1))
            {
              if (ibuttonc >= 324)
              {
                istopit = 1;
              }
              if (ibuttonc < 305)
              {
                if (Board[ibuttonc + 57][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc + 57][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc + 57;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* w */

            if ((ieye[5][3] == 1) && (istopit != 1))
            {
              if (ibuttonc >= 324)
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc, 19) == 0) ||
                (ibuttonc >= 305))
              {
                istopit = 1;
              }
              if ((Board[ibuttonc + 58][2] != 'e') &&
                (Board[ibuttonc + 58][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[5][3] == 2) && (istopit != 1))
            {
              if (ibuttonc >= 324)
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc, 19) != 0) &&
                (ibuttonc < 305))
              {
                if (Board[ibuttonc + 58][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc + 58][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc + 58;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* x */

            if ((ieye[5][4] == 1) && (istopit != 1))
            {
              if (ibuttonc >= 324)
              {
                istopit = 1;
              }
              if (Modulo (ibuttonc, 19) == 0)
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc + 1, 19) == 0) ||
                (ibuttonc >= 305))
              {
                istopit = 1;
              }
              if ((Board[ibuttonc + 59][2] != 'e') &&
                (Board[ibuttonc + 59][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[5][4] == 2) && (istopit != 1))
            {
              if (ibuttonc >= 324)
              {
                istopit = 1;
              }
              if (Modulo (ibuttonc, 19) == 0)
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc + 1, 19) != 0) &&
                (ibuttonc < 305))
              {
                if (Board[ibuttonc + 59][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc + 59][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc + 59;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            /* y */

            if ((ieye[5][5] == 1) && (istopit != 1))
            {
              if (ibuttonc >= 324)
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc, 19) == 0) ||
                (Modulo (ibuttonc + 1, 19) == 0))
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc + 2, 19) == 0) ||
                (ibuttonc >= 305))
              {
                istopit = 1;
              }
              if ((Board[ibuttonc + 60][2] != 'e') &&
                (Board[ibuttonc + 60][2] != 's'))
              {
                istopit = 1;
              }
            }
            if ((ieye[5][5] == 2) && (istopit != 1))
            {
              if (ibuttonc >= 324)
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc, 19) == 0) ||
                (Modulo (ibuttonc + 1, 19) == 0))
              {
                istopit = 1;
              }
              if ((Modulo (ibuttonc + 2, 19) != 0) &&
                (ibuttonc < 305))
              {
                if (Board[ibuttonc + 60][2] == cnotccolor)
                {
                  istopit = 1;
                }
                if (Board[ibuttonc + 60][2] != cccolor)
                {
                  ineed++;
                  if (ineed == 1) itheone = ibuttonc + 60;
                  if (ineed > atoi (ssides)) istopit = 1;
                }
              }
            }

            if ((istopit != 1) && (ineed != 0))
            {
              ChangePixmap (itheone, cccolor);
            }
          }
        }
      }

      /* m */

      if ((schar[0] == 'm') && (idone == 0))
      {
        for (ibuttonc = 1; ibuttonc <= 361; ibuttonc++)
        {
          if (((Board[ibuttonc - 1][2] == cnotccolor) ||
            (Board[ibuttonc + 1][2] == cnotccolor) ||
            (Board[ibuttonc - 19][2] == cnotccolor) ||
            (Board[ibuttonc + 19][2] == cnotccolor)) &&
            (Board[ibuttonc - 20][2] != cccolor) &&
            (Board[ibuttonc - 19][2] != cccolor) &&
            (Board[ibuttonc - 18][2] != cccolor) &&
            (Board[ibuttonc - 1][2] != cccolor) &&
            (Board[ibuttonc + 1][2] != cccolor) &&
            (Board[ibuttonc + 18][2] != cccolor) &&
            (Board[ibuttonc + 19][2] != cccolor) &&
            (Board[ibuttonc + 20][2] != cccolor) &&
            (Board[ibuttonc][2] == cccolor))
          {
            fnumber++;
          }
        }
        if (fnumber != 0)
        {
          irandom = 1 + (int) (fnumber * random() / (RAND_MAX + 1.0));
          fnumber = 0;
          itry = 0;
          for (ibuttonc = 1; ibuttonc <= 361; ibuttonc++)
          {
            if (((Board[ibuttonc - 1][2] == cnotccolor) ||
              (Board[ibuttonc + 1][2] == cnotccolor) ||
              (Board[ibuttonc - 19][2] == cnotccolor) ||
              (Board[ibuttonc + 19][2] == cnotccolor)) &&
              (Board[ibuttonc - 20][2] != cccolor) &&
              (Board[ibuttonc - 19][2] != cccolor) &&
              (Board[ibuttonc - 18][2] != cccolor) &&
              (Board[ibuttonc - 1][2] != cccolor) &&
              (Board[ibuttonc + 1][2] != cccolor) &&
              (Board[ibuttonc + 18][2] != cccolor) &&
              (Board[ibuttonc + 19][2] != cccolor) &&
              (Board[ibuttonc + 20][2] != cccolor) &&
              (Board[ibuttonc][2] == cccolor))
            {
              fnumber++;
            }
            if ((fnumber == irandom) && (itry == 0))
            {
              itry = 1;
              if ((Modulo (ibuttonc - 1, 19) != 0) && (ibuttonc > 19))
              {
                ChangePixmap (ibuttonc - 20, cccolor);
              }
              if ((Modulo (ibuttonc, 19) != 0) && (ibuttonc > 19) &&
                (idone == 0))
              {
                ChangePixmap (ibuttonc - 18, cccolor);
              }
              if ((Modulo (ibuttonc - 1, 19) != 0) && (ibuttonc < 343) &&
                (idone == 0))
              {
                ChangePixmap (ibuttonc + 18, cccolor);
              }
              if ((Modulo (ibuttonc, 19) != 0) && (ibuttonc < 343) &&
                (idone == 0))
              {
                ChangePixmap (ibuttonc + 20, cccolor);
              }
            }
          }
        }
      }

      /* X */

      if ((schar[0] == 'X') && (idone == 0))
      {
        fnumber = 0;
        for (ibuttonc = 1; ibuttonc <= 361; ibuttonc++)
        {
          if ((FreePlace (ibuttonc, cccolor, 'F') == 1) &&
            (((ibuttonc > 40) && (ibuttonc < 56)) ||
            ((ibuttonc > 59) && (ibuttonc < 75)) ||
            ((ibuttonc > 78) && (ibuttonc < 94)) ||
            ((ibuttonc > 268) && (ibuttonc < 284)) ||
            ((ibuttonc > 287) && (ibuttonc < 303)) ||
            ((ibuttonc > 306) && (ibuttonc < 322)) ||
            (((BoardPlace (1, ibuttonc)[0] == 'c') ||
            (BoardPlace (1, ibuttonc)[0] == 'd') ||
            (BoardPlace (1, ibuttonc)[0] == 'e') ||
            (BoardPlace (1, ibuttonc)[0] == 'o') ||
            (BoardPlace (1, ibuttonc)[0] == 'p') ||
            (BoardPlace (1, ibuttonc)[0] == 'q')) &&
            ((BoardPlace (1, ibuttonc)[1] == 'f') ||
            (BoardPlace (1, ibuttonc)[1] == 'g') ||
            (BoardPlace (1, ibuttonc)[1] == 'h') ||
            (BoardPlace (1, ibuttonc)[1] == 'i') ||
            (BoardPlace (1, ibuttonc)[1] == 'j') ||
            (BoardPlace (1, ibuttonc)[1] == 'k') ||
            (BoardPlace (1, ibuttonc)[1] == 'l') ||
            (BoardPlace (1, ibuttonc)[1] == 'm') ||
            (BoardPlace (1, ibuttonc)[1] == 'n')))))
          {
            fnumber++;
          }
        }
        if (fnumber != 0)
        {
          irandom = 1 + (int) (fnumber * random() / (RAND_MAX + 1.0));
          fnumber = 0;
          itry = 0;
          for (ibuttonc = 1; ibuttonc <= 361; ibuttonc++)
          {
            if ((FreePlace (ibuttonc, cccolor, 'F') == 1) &&
              (((ibuttonc > 40) && (ibuttonc < 56)) ||
              ((ibuttonc > 59) && (ibuttonc < 75)) ||
              ((ibuttonc > 78) && (ibuttonc < 94)) ||
              ((ibuttonc > 268) && (ibuttonc < 284)) ||
              ((ibuttonc > 287) && (ibuttonc < 303)) ||
              ((ibuttonc > 306) && (ibuttonc < 322)) ||
              (((BoardPlace (1, ibuttonc)[0] == 'c') ||
              (BoardPlace (1, ibuttonc)[0] == 'd') ||
              (BoardPlace (1, ibuttonc)[0] == 'e') ||
              (BoardPlace (1, ibuttonc)[0] == 'o') ||
              (BoardPlace (1, ibuttonc)[0] == 'p') ||
              (BoardPlace (1, ibuttonc)[0] == 'q')) &&
              ((BoardPlace (1, ibuttonc)[1] == 'f') ||
              (BoardPlace (1, ibuttonc)[1] == 'g') ||
              (BoardPlace (1, ibuttonc)[1] == 'h') ||
              (BoardPlace (1, ibuttonc)[1] == 'i') ||
              (BoardPlace (1, ibuttonc)[1] == 'j') ||
              (BoardPlace (1, ibuttonc)[1] == 'k') ||
              (BoardPlace (1, ibuttonc)[1] == 'l') ||
              (BoardPlace (1, ibuttonc)[1] == 'm') ||
              (BoardPlace (1, ibuttonc)[1] == 'n')))))
            {
              fnumber++;
            }
            if ((fnumber == irandom) && (idone == 0) && (itry == 0))
            {
              ChangePixmap (ibuttonc, cccolor);
              itry = 1;
            }
          }
        }
      }

      /* s */

      if ((schar[0] == 's') && (idone == 0))
      {
        iabove = 0;
        iunder = 0;
        ileft = 0;
        iright = 0;
        do
        {
          ireturned = read (ifiledes, schar, 1);
          if (ireturned == -1)
          {
            Message ("Error reading computer.", 1, 0);
          }
        } while ((schar[0] != 'C') && (schar[0] != 'N') && (ireturned != 0));
        if (ireturned == 0)
        {
          Message ("Incorrect computer.", 1, 0);
        }
        ccheck = schar[0];
        sprintf (sctemp, "%s", "");
        do
        {
          ireturned = read (ifiledes, schar, 1);
          if (ireturned == -1)
          {
            Message ("Error reading computer.", 1, 0);
          }
          if ((schar[0] == '0') || (schar[0] == '1') || (schar[0] == '2') ||
            (schar[0] == '3') || (schar[0] == '4') || (schar[0] == '5') ||
            (schar[0] == '6') || (schar[0] == '7') || (schar[0] == '8') ||
            (schar[0] == '9'))
          {
            sprintf (ssides, "%s%c", sctemp, schar[0]);
            sprintf (sctemp, "%s", ssides);
          }
        } while ((schar[0] != 'a') && (schar[0] != 'u') &&
          (schar[0] != 'r') && (schar[0] != 'l') && (ireturned != 0));
        if (ireturned == 0)
        {
          Message ("Incorrect computer.", 1, 0);
        }
        if (schar[0] == 'a') iabove = 1;
        if (schar[0] == 'u') iunder = 1;
        if (schar[0] == 'r') iright = 1;
        if (schar[0] == 'l') ileft = 1;
        do
        {
          ireturned = read (ifiledes, schar, 1);
          if (ireturned == -1)
          {
            Message ("Error reading computer.", 1, 0);
          }
          if (schar[0] == 'a') iabove = 1;
          if (schar[0] == 'u') iunder = 1;
          if (schar[0] == 'r') iright = 1;
          if (schar[0] == 'l') ileft = 1;
        } while (((schar[0] == 'a') || (schar[0] == 'u') || (schar[0] == 'r')
          || (schar[0] == 'l')) && (ireturned != 0));
        if (ireturned == 0)
        {
          Message ("Incorrect computer.", 1, 0);
        }
        idid = 1;
        irandom = Where (iabove, iunder, iright, ileft);
        if (ccheck == 'C')
        {
          for (ibuttonc = 1; ibuttonc <= 361; ibuttonc++)
          {
            if ((Board[ibuttonc][2] == cccolor) && (idone == 0))
            {
              if (CheckSides (ibuttonc, cccolor, 1) == atoi (ssides))
              {
                if (irandom == 1)
                {
                  ChangePixmap (ibuttonc - 19, cccolor);
                }
                if (irandom == 2)
                {
                  ChangePixmap (ibuttonc + 19, cccolor);
                }
                if (irandom == 3)
                {
                  ChangePixmap (ibuttonc + 1, cccolor);
                }
                if (irandom == 4)
                {
                  ChangePixmap (ibuttonc - 1, cccolor);
                }
              }
            }
          }
        }
        else
        {
          for (ibuttonc = 1; ibuttonc <= 361; ibuttonc++)
          {
            if ((Board[ibuttonc][2] == cnotccolor) && (idone == 0))
            {
              if (CheckSides (ibuttonc, cnotccolor, 1) == atoi (ssides))
              {
                if (irandom == 1)
                {
                  ChangePixmap (ibuttonc - 19, cccolor);
                }
                if (irandom == 2)
                {
                  ChangePixmap (ibuttonc + 19, cccolor);
                }
                if (irandom == 3)
                {
                  ChangePixmap (ibuttonc + 1, cccolor);
                }
                if (irandom == 4)
                {
                  ChangePixmap (ibuttonc - 1, cccolor);
                }
              }
            }
          }
        }
      }

      /* g */

      if ((schar[0] == 'g') && (idone == 0) && (idid != 1))
      {
        iabove = 0;
        iunder = 0;
        ileft = 0;
        iright = 0;
        do
        {
          ireturned = read (ifiledes, schar, 1);
          if (ireturned == -1)
          {
            Message ("Error reading computer.", 1, 0);
          }
        } while ((schar[0] != 'C') && (schar[0] != 'N') && (ireturned != 0));
        if (ireturned == 0)
        {
          Message ("Incorrect computer.", 1, 0);
        }
        ccheck = schar[0];
        sprintf (sctemp, "%s", "");
        do
        {
          ireturned = read (ifiledes, schar, 1);
          if (ireturned == -1)
          {
            Message ("Error reading computer.", 1, 0);
          }
          if ((schar[0] == '0') || (schar[0] == '1') || (schar[0] == '2') ||
            (schar[0] == '3') || (schar[0] == '4') || (schar[0] == '5') ||
            (schar[0] == '6') || (schar[0] == '7') || (schar[0] == '8') ||
            (schar[0] == '9'))
          {
            sprintf (ssides, "%s%c", sctemp, schar[0]);
            sprintf (sctemp, "%s", ssides);
          }
        } while ((schar[0] != 'a') && (schar[0] != 'u') &&
          (schar[0] != 'r') && (schar[0] != 'l') && (ireturned != 0));
        if (ireturned == 0)
        {
          Message ("Incorrect computer.", 1, 0);
        }
        if (schar[0] == 'a') iabove = 1;
        if (schar[0] == 'u') iunder = 1;
        if (schar[0] == 'r') iright = 1;
        if (schar[0] == 'l') ileft = 1;
        do
        {
          ireturned = read (ifiledes, schar, 1);
          if (ireturned == -1)
          {
            Message ("Error reading computer.", 1, 0);
          }
          if (schar[0] == 'a') iabove = 1;
          if (schar[0] == 'u') iunder = 1;
          if (schar[0] == 'r') iright = 1;
          if (schar[0] == 'l') ileft = 1;
        } while (((schar[0] == 'a') || (schar[0] == 'u') || (schar[0] == 'r')
          || (schar[0] == 'l')) && (ireturned != 0));
        if (ireturned == 0)
        {
          Message ("Incorrect computer.", 1, 0);
        }
        idid = 1;
        if (((ccheck == 'C') && (cccolor == 'b')) ||
          ((ccheck == 'N') && (cccolor == 'w')))
        {
          if (CheckSides (ilastmoveb, 'b', 3) >= atoi (ssides))
          {
            if ((idone == 0) && (iabove == 1) && (ilastmoveb > 19))
              ChangePixmap (ilastmoveb - 19, cccolor);
            if ((idone == 0) && (iunder == 1) && (ilastmoveb < 343))
              ChangePixmap (ilastmoveb + 19, cccolor);
            if ((idone == 0) && (iright == 1) &&
              (Modulo (ilastmoveb, 19) != 0))
              ChangePixmap (ilastmoveb + 1, cccolor);
            if ((idone == 0) && (ileft == 1) &&
              (Modulo (ilastmoveb - 1, 19) != 0))
              ChangePixmap (ilastmoveb - 1, cccolor);
          }
        }
        if (((ccheck == 'C') && (cccolor == 'w')) ||
          ((ccheck == 'N') && (cccolor == 'b')))
        {
          if (CheckSides (ilastmovew, 'w', 3) >= atoi (ssides))
          {
            if ((idone == 0) && (iabove == 1) && (ilastmovew > 19))
              ChangePixmap (ilastmovew - 19, cccolor);
            if ((idone == 0) && (iunder == 1) && (ilastmovew < 343))
              ChangePixmap (ilastmovew + 19, cccolor);
            if ((idone == 0) && (iright == 1) &&
              (Modulo (ilastmovew, 19) != 0))
              ChangePixmap (ilastmovew + 1, cccolor);
            if ((idone == 0) && (ileft == 1) &&
              (Modulo (ilastmovew - 1, 19) != 0))
              ChangePixmap (ilastmovew - 1, cccolor);
          }
        }
        if (ccheck == 'C')
        {
          for (ibuttonc = 1; ibuttonc <= 361; ibuttonc++)
          {
            if ((Board[ibuttonc][2] == cccolor) && (idone == 0))
            {
              if (CheckSides (ibuttonc, cccolor, 3) >= atoi (ssides))
              {
                if ((idone == 0) && (iabove == 1) && (ibuttonc > 19))
                  ChangePixmap (ibuttonc - 19, cccolor);
                if ((idone == 0) && (iunder == 1) && (ibuttonc < 343))
                  ChangePixmap (ibuttonc + 19, cccolor);
                if ((idone == 0) && (iright == 1) &&
                  (Modulo (ibuttonc, 19) != 0))
                  ChangePixmap (ibuttonc + 1, cccolor);
                if ((idone == 0) && (ileft == 1) &&
                  (Modulo (ibuttonc - 1, 19) != 0))
                  ChangePixmap (ibuttonc - 1, cccolor);
              }
            }
          }
        }
        else
        {
          for (ibuttonc = 1; ibuttonc <= 361; ibuttonc++)
          {
            if ((Board[ibuttonc][2] == cnotccolor) && (idone == 0))
            {
              if (CheckSides (ibuttonc, cnotccolor, 3) >= atoi (ssides))
              {
                if ((idone == 0) && (iabove == 1) && (ibuttonc > 19))
                  ChangePixmap (ibuttonc - 19, cccolor);
                if ((idone == 0) && (iunder == 1) && (ibuttonc < 343))
                  ChangePixmap (ibuttonc + 19, cccolor);
                if ((idone == 0) && (iright == 1) &&
                  (Modulo (ibuttonc, 19) != 0))
                  ChangePixmap (ibuttonc + 1, cccolor);
                if ((idone == 0) && (ileft == 1) &&
                  (Modulo (ibuttonc - 1, 19) != 0))
                  ChangePixmap (ibuttonc - 1, cccolor);
              }
            }
          }
        }
      }

      /* l */

      if ((schar[0] == 'l') && (idone == 0) && (idid != 1))
      {
        iabove = 0;
        iunder = 0;
        ileft = 0;
        iright = 0;
        do
        {
          ireturned = read (ifiledes, schar, 1);
          if (ireturned == -1)
          {
            Message ("Error reading computer.", 1, 0);
          }
          if (schar[0] == 'a') iabove = 1;
          if (schar[0] == 'u') iunder = 1;
          if (schar[0] == 'r') iright = 1;
          if (schar[0] == 'l') ileft = 1;
        } while ((schar[0] != 'C') && (schar[0] != 'N') && (ireturned != 0));
        if (ireturned == 0)
        {
          Message ("Incorrect computer.", 1, 0);
        }
        irandom = Where (iabove, iunder, iright, ileft);
        if (((schar[0] == 'C') && (cccolor == 'b')) ||
          ((schar[0] == 'N') && (cccolor == 'w')))
        {
          if (irandom == 1)
          {
            if (ilastmoveb - 19 >= 1)
            {
              ChangePixmap (ilastmoveb - 19, cccolor);
            }
          }
          if (irandom == 2)
          {
            if (ilastmoveb + 19 <= 361)
            {
              ChangePixmap (ilastmoveb + 19, cccolor);
            }
          }
          if (irandom == 3)
          {
            if (Modulo (ilastmoveb, 19) != 0)
            {
              ChangePixmap (ilastmoveb + 1, cccolor);
            }
          }
          if (irandom == 4)
          {
            if (Modulo (ilastmoveb - 1, 19) != 0)
            {
              ChangePixmap (ilastmoveb - 1, cccolor);
            }
          }
          if (((schar[0] == 'N') && (cccolor == 'b')) ||
            ((schar[0] == 'C') && (cccolor == 'w')))
          {
            if (irandom == 1)
            {
              if (ilastmovew - 19 >= 1)
              {
                ChangePixmap (ilastmovew - 19, cccolor);
              }
            }
            if (irandom == 2)
            {
              if (ilastmovew + 19 <= 361)
              {
                ChangePixmap (ilastmovew + 19, cccolor);
              }
            }
            if (irandom == 3)
            {
              if (Modulo (ilastmovew, 19) != 0)
              {
                ChangePixmap (ilastmovew + 1, cccolor);
              }
            }
            if (irandom == 4)
            {
              if (Modulo (ilastmovew - 1, 19) != 0)
              {
                ChangePixmap (ilastmovew - 1, cccolor);
              }
            }
          }
        }
      }

      /* ! */

      if ((schar[0] == '!') && (idone == 0) && (idid != 1))
      {
        if (inotown == 0)
        {
          inotown = 1;
        }
        else
        {
          inotown = 0;
        }
      }

      /* . */

      if ((schar[0] == '.') && (idone == 0) && (idid != 1))
      {
        if (inotother == 0)
        {
          inotother = 1;
        }
        else
        {
          inotother = 0;
        }
      }

      /* $ */

      if ((schar[0] == '$') && (idone == 0) && (idid != 1))
      {
        if (inotside == 0)
        {
          inotside = 1;
        }
        else
        {
          inotside = 0;
        }
      }

      /* E */

      if ((schar[0] == 'E') && (idone == 0) && (idid != 1))
      {
        if ((cccolor == 'w') && (pass[ihistory] == 1) &&
          (ScoreWhite () > ScoreBlack ()))
        {
          pass[ihistory + 1] = 1;
          EndGame ();
          idone = 1;
        }
        if ((cccolor == 'b') && (pass[ihistory] == 1) &&
          (ScoreBlack () > ScoreWhite ()))
        {
          pass[ihistory + 1] = 1;
          EndGame ();
          idone = 1;
        }
      }

      /* F */

      if ((schar[0] == 'F') && (idone == 0) && (idid != 1))
      {
        fnumber = 0;
        for (ibuttonc = 1; ibuttonc <= 361; ibuttonc++)
        {
          if (FreePlace (ibuttonc, cccolor, 'F') == 1)
          {
            fnumber++;
          }
        }
        if (fnumber != 0)
        {
          irandom = 1 + (int) (fnumber * random() / (RAND_MAX + 1.0));
          fnumber = 0;
          itry = 0;
          for (ibuttonc = 1; ibuttonc <= 361; ibuttonc++)
          {
            if (FreePlace (ibuttonc, cccolor, 'F') == 1)
            {
              fnumber++;
            }
            if ((fnumber == irandom) && (idone == 0) && (itry == 0))
            {
              ChangePixmap (ibuttonc, cccolor);
              itry = 1;
            }
          }
        }
      }

      /* f */

      if ((schar[0] == 'f') && (idone == 0) && (idid != 1))
      {
        fnumber = 0;
        for (ibuttonc = 1; ibuttonc <= 361; ibuttonc++)
        {
          if (FreePlace (ibuttonc, cccolor, 'f') == 1)
          {
            fnumber++;
          }
        }
        if (fnumber != 0)
        {
          irandom = 1 + (int) (fnumber * random() / (RAND_MAX + 1.0));
          fnumber = 0;
          itry2 = 0;
          for (ibuttonc = 1; ibuttonc <= 361; ibuttonc++)
          {
            if (FreePlace (ibuttonc, cccolor, 'f') == 1)
            {
              fnumber++;
            }
            if ((fnumber == irandom) && (idone == 0) && (itry2 == 0))
            {
              ChangePixmap (ibuttonc, cccolor);
              itry2 = 1;
            }
          }
        }
      }

      /* M */

      if ((schar[0] == 'M') && (idone == 0) && (idid != 1))
      {
        for (ibuttonc = 1; ibuttonc <= 361; ibuttonc++)
        {
          itriedb[ibuttonc] = 0;
        }
        do {
          fnumber = 0;
          for (ibuttonc = 1; ibuttonc <= 361; ibuttonc++)
          {
            if ((FreePlace (ibuttonc, cccolor, 'M') == 1)
              && (itriedb[ibuttonc] != 1))
            {
              fnumber++;
            }
          }
          if (fnumber != 0)
          {
            irandom = 1 + (int) (fnumber * random() / (RAND_MAX + 1.0));
            fnumber = 0;
            itry3 = 0;
            for (ibuttonc = 1; ibuttonc <= 361; ibuttonc++)
            {
              if ((FreePlace (ibuttonc, cccolor, 'M') == 1)
                && (itriedb[ibuttonc] != 1))
              {
                fnumber++;
              }
              if ((fnumber == irandom) && (idone == 0) && (itry3 == 0))
              {
                ChangePixmap (ibuttonc, cccolor);
                itriedb[ibuttonc] = 1;
                itry3 = 1;
              }
            }
          }
        } while ((fnumber != 0) && (idone == 0));
      }

      /* P */

      if ((schar[0] == 'P') && (idone == 0) && (idid != 1))
      {
        if (cccolor == 'w')
        {
          pass[ihistory + 1] = 1;
          if (pass[ihistory] == 1)
          {
            EndGame ();
          }
        }
        else
        {
          pass[ihistory + 1] = 1;
          if (pass[ihistory] == 1)
          {
            EndGame ();
          }
        }
        idone = 1;
      }

      }

    }
  } while ((ireturned != 0) && (idone == 0));
  close (ifiledes);
  if (idone == 0)
  {
    if (cccolor == 'w')
    {
      pass[ihistory + 1] = 1;
      if (pass[ihistory] == 1)
      {
        EndGame ();
      }
    }
    else
    {
      pass[ihistory + 1] = 1;
      if (pass[ihistory] == 1)
      {
        EndGame ();
      }
    }
  }
  else
  {
    if (((imoves == 0) || (imoves == 1)) && (ijustrestart == 1))
    {
      istarthand = ihandicap;
      ijustrestart = 0;
    }
  }
  while (gtk_events_pending ())
  {
    gtk_main_iteration ();
  }
}
