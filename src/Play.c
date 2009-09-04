/* gtkgo 0.0.10 (Play.c) - 05/17/99
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

#include "Play.h"

void Play (char *sfiletoplay, int iloop)
{
  if (iloop != 2)
  {
    if (isound == 1)
    {
      if (mpg123pid)
      {
        kill (mpg123pid, SIGKILL);
      }
      if (iloop == 0)
      {
        mpg123pid = fork ();
        if (!mpg123pid)
        {
          sprintf (sysexec, "%smp3/%s", PKGDATADIR, sfiletoplay);
          execlp ("mpg123", "mpg123", "-q", sysexec, NULL);
          exit (0);
        }
      }
      else
      {
        mpg123pid = fork ();
        if (!mpg123pid)
        {
          sprintf (sysexec, "%smp3/%s", PKGDATADIR, sfiletoplay);
          execlp ("mpg123", "mpg123", "-q", "-Z", sysexec, NULL);
          exit (0);
        }
      }
    }
  }
  else
  {
    if (mpg123pid)
    {
      kill (mpg123pid, SIGKILL);
    }
  }
}
