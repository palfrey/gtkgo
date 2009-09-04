/* gtkgo 0.0.10 (ReceiveData.c) - 05/17/99
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

#include "ReceiveData.h"

int BoardPlace2 (char stomove[3])
{
  int ireturnit;

  ireturnit = 0;
  switch (stomove[0])
  {
    case 'A': ireturnit++; break;
    case 'B': ireturnit += 2; break;
    case 'C': ireturnit += 3; break;
    case 'D': ireturnit += 4; break;
    case 'E': ireturnit += 5; break;
    case 'F': ireturnit += 6; break;
    case 'G': ireturnit += 7; break;
    case 'H': ireturnit += 8; break;
    case 'J': ireturnit += 9; break;
    case 'K': ireturnit += 10; break;
    case 'L': ireturnit += 11; break;
    case 'M': ireturnit += 12; break;
    case 'N': ireturnit += 13; break;
    case 'O': ireturnit += 14; break;
    case 'P': ireturnit += 15; break;
    case 'Q': ireturnit += 16; break;
    case 'R': ireturnit += 17; break;
    case 'S': ireturnit += 18; break;
    case 'T': ireturnit += 19; break;
    default: Message ("Incorrect server.", 3, 0);
  }
  if (strlen (stomove) == 3)
  {
    switch (stomove[2])
    {
      case '8': ireturnit += 19; break;
      case '7': ireturnit += 38; break;
      case '6': ireturnit += 57; break;
      case '5': ireturnit += 76; break;
      case '4': ireturnit += 95; break;
      case '3': ireturnit += 114; break;
      case '2': ireturnit += 133; break;
      case '1': ireturnit += 152; break;
      case '0': ireturnit += 171; break;
    }
  }
  else
  {
    ireturnit += 190;
    switch (stomove[1])
    {
      case '8': ireturnit += 19; break;
      case '7': ireturnit += 38; break;
      case '6': ireturnit += 57; break;
      case '5': ireturnit += 76; break;
      case '4': ireturnit += 95; break;
      case '3': ireturnit += 114; break;
      case '2': ireturnit += 133; break;
      case '1': ireturnit += 152; break;
    }
  }
  return (ireturnit);
}

void ReceiveData (void)
{
  iinetgame = 0;
  iinetmove = 0;
  iinetcreate = 0;
  iinethand = 0;
  iinetresign = 0;
  iinetundo = 0;
  isetclient = 0;
  sprintf (sinetmove, "%s", "");
  sprintf (sothername, "%s", "");
  sprintf (shandicap, "%s", "");
  sprintf (snamew, "%s", "");
  sprintf (snameb, "%s", "");
  do {
    n = recv (sockfd, recvline, 255, 0);
    recvline[n] = 0;
    if (n == 0)
    {
      inet = 0;
    }
    if (n == -1)
    {
      if (gtk_events_pending ())
      {
        gtk_main_iteration ();
      }
    }
    if ((n != -1) && (n != 0))
    {
      gtk_text_freeze (GTK_TEXT (text));
      for (itemp2 = 0; itemp2 < n; itemp2++)
      {
        if (isetclient == 2)
        {
          SendData (1, " client 23");
          isetclient = 3;
        }
        if (iinetundo == 5)
        {
          igonow = 1;
          Undo ();
          igonow = 0;
          iinetundo = 0;
        }
        else
        if (iinetpls == 15)
        {
          if (recvline[itemp2] != ' ')
          {
            sprintf (sinettemp4, "%s%c", snameb, recvline[itemp2]);
            sprintf (snameb, "%s", sinettemp4);
          }
          else
          {
            sprintf (bplayername, "%s", snameb);
            StatusBar ();
            if (strcmp (snamew, sothername) == 0)
            {
              iiamblack = 1;
            }
            sprintf (snamew, "%s", "");
            sprintf (snameb, "%s", "");
            iinetpls = 0;
          }
        }
        else
        if (iinetpls == 11)
        {
          if (recvline[itemp2] != ' ')
          {
            sprintf (sinettemp4, "%s%c", snamew, recvline[itemp2]);
            sprintf (snamew, "%s", sinettemp4);
          }
          else
          {
            sprintf (wplayername, "%s", snamew);
            iinetpls++;
          }
        }
        else
        if (iinetpls == 5)
        {
          if (recvline[itemp2] == ' ')
            iinetpls++;
        }
        else
        if (iinetresign == 8)
        {
          iinetgame = 0;
          sprintf (sothername, "%s", "");
          sprintf (bplayername, "%s", "unknown");
          sprintf (wplayername, "%s", "unknown");
          StatusBar ();
          iinetresign = 0;
          iiamblack = 0;
          ihandicap = 0;
        }
        else
        if (iinethand == 9)
        {
          if (recvline[itemp2] != '\r')
          {
            sprintf (sinettemp3, "%s%c", shandicap, recvline[itemp2]);
            sprintf (shandicap, "%s", sinettemp3);
          }
          else
          {
            ihandicap = atoi (shandicap);
            ihistory = 0;
            imoves = 0;
            DoHandicap ();
            iinethand = 0;
            sprintf (shandicap, "%s", "");
          }
        }
        else
        if (iinetcreate == 23)
        {
          if (recvline[itemp2] != '.')
          {
            sprintf (sinettemp2, "%s%c", sothername, recvline[itemp2]);
            sprintf (sothername, "%s", sinettemp2);
          }
          else
          {
            iinetgame = 1;
            ihandicap = 0;
            isave = 0;
            ReallyReStart (NULL, NULL);
            iinetcreate = 0;
          }
        }
        else
        if (iinetmove == 11)
        {
          if (recvline[itemp2] != '\r')
          {
            if (recvline[itemp2] == 'a')
            {
              iinethand = 2;
              iinetmove = 0;
              sprintf (sinetmove, "%s", "");
            }
            else
            {
              sprintf (sinettemp, "%s%c", sinetmove, recvline[itemp2]);
              sprintf (sinetmove, "%s", sinettemp);
            }
          }
          else
          {
            if (Modulo (imoves, 2) == 0)
            {
              idone = 0;
              ChangePixmap (BoardPlace2 (sinetmove), 'b');
              if (idone == 1)
              {
                JudgeBoard ('w');
              }
            }
            else
            {
              idone = 0;
              ChangePixmap (BoardPlace2 (sinetmove), 'w');
              if (idone == 1)
              {
                JudgeBoard ('b');
              }
            }
            iinetmove = 0;
            sprintf (sinetmove, "%s", "");
          }
        }
        else
        {
          switch (recvline[itemp2])
          {
            case 'C':
              iinetcreate++;
              break;
            case 'G':
              iinetpls++;
              break;
            case 'I':
              if (iinetpls == 7)
                iinetpls++;
              break;
            case 'L':
              iinetmove++;
              break;
            case 'M':
              if (iinetmove == 5)
                iinetmove++;
              break;
            case ' ':
              if ((iinetmove == 4) || (iinetmove == 10))
                iinetmove++;
              if ((iinetcreate == 8) || (iinetcreate == 14) ||
                (iinetcreate == 17) || (iinetcreate == 22))
                iinetcreate++;
              if (iinethand == 8)
                iinethand++;
              if ((iinetpls == 4) || (iinetpls == 10) || (iinetpls == 14))
                iinetpls++;
              break;
            case ':':
              if (iinetmove == 9)
                iinetmove++;
              if (iinetpls == 9)
                iinetpls++;
              break;
            case '[':
              if (iinetcreate == 15)
                iinetcreate++;
              break;
            case ']':
              if (iinetcreate == 16)
                iinetcreate++;
              break;
            case '(':
              if (iinetpls == 6)
                iinetpls++;
              break;
            case ')':
              if (iinetpls == 8)
                iinetpls++;
              break;
            case '#':
              if (isetclient == 0)
                isetclient++;
              break;
            case '>':
              if (isetclient == 1)
                isetclient++;
              break;
            case 'a':
              if (iinetmove == 1)
                iinetmove++;
              if ((iinetcreate == 3) || (iinetcreate == 10))
                iinetcreate++;
              if (iinethand == 6)
                iinethand++;
              if (iinetpls == 1)
                iinetpls++;
              break;
            case 'c':
              if (iinetcreate == 12)
                iinetcreate++;
              if (iinethand == 5)
                iinethand++;
              break;
            case 'd':
              if (iinethand == 3)
                iinethand++;
              if (iinetresign == 7)
                iinetresign++;
              if ((iinetundo == 2) || (iinetundo == 4))
                iinetundo++;
              break;
            case 'e':
              if (iinetmove == 8)
                iinetmove++;
              if (iinetcreate == 2)
                iinetcreate++;
              if ((iinetresign == 1) || (iinetresign == 6))
                iinetresign++;
              if (iinetpls == 3)
                iinetpls++;
              break;
            case 'g':
              if (iinetcreate == 7)
                iinetcreate++;
              if (iinetresign == 4)
                iinetresign++;
              break;
            case 'h':
              if ((iinetcreate == 13) || (iinetcreate == 21))
                iinetcreate++;
              break;
            case 'i':
              if ((iinetcreate == 5) || (iinetcreate == 19))
                iinetcreate++;
              if (iinethand == 4)
                iinethand++;
              if (iinetresign == 3)
                iinetresign++;
              if (iinetundo == 3)
                iinetundo++;
              break;
            case 'm':
              if (iinetcreate == 9)
                iinetcreate++;
              if (iinetpls == 2)
                iinetpls++;
              break;
            case 'n':
              if (iinetcreate == 6)
                iinetcreate++;
              if (iinethand == 2)
                iinethand++;
              if (iinetresign == 5)
                iinetresign++;
              if (iinetundo == 1)
                iinetundo++;
              break;
            case 'o': if (iinetmove == 6) iinetmove++; break;
            case 'p': if (iinethand == 7) iinethand++; break;
            case 'r':
              if (iinetcreate == 1)
                iinetcreate++;
              iinetresign++;
              break;
            case 's':
              if (iinetmove == 2)
                iinetmove++;
              if (iinetresign == 2)
                iinetresign++;
              if (iinetpls == 13)
                iinetpls++;
              break;
            case 't':
              if (iinetmove == 3)
                iinetmove++;
              if ((iinetcreate == 4) || (iinetcreate == 11) ||
                (iinetcreate == 20))
                iinetcreate++;
              break;
            case 'u':
              iinetundo++;
              break;
            case 'v':
              if (iinetmove == 7)
                iinetmove++;
              if (iinetpls == 12)
                iinetpls++;
              break;
            case 'w': if (iinetcreate == 18) iinetcreate++; break;
            default:
              iinetmove = 0;
              if (iinetcreate != 16)
                iinetcreate = 0;
              iinethand = 0;
              iinetresign = 0;
              if ((iinetpls != 5) && (iinetpls != 12))
                iinetpls = 0;
              iinetundo = 0;
              if (isetclient != 3)
                isetclient = 0;
          }
        }
        if (recvline[itemp2] != '\r')
        {
          sprintf (sshowthis, "%c", recvline[itemp2]);
          gtk_text_insert (GTK_TEXT (text), fixed_font, &text->style->black,
            NULL, sshowthis, -1);
        }
      }
      gtk_text_thaw (GTK_TEXT (text));
      gtk_adjustment_set_value (adj, adj->upper - adj->lower -
        adj->page_size);
    }
  } while (inet == 1);
  close (sockfd);
  gtk_widget_destroy (internetwindow);
}
