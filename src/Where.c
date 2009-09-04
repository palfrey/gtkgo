/* gtkgo 0.0.10 (Where.c) - 05/17/99
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

#include "Where.h"

int Where (int iwabove, int iwunder, int iwright, int iwleft)
{
  if ((iwabove == 1) && (iwunder == 0) && (iwright == 0) && (iwleft == 0))
    return (1);
  if ((iwabove == 0) && (iwunder == 1) && (iwright == 0) && (iwleft == 0))
    return (2);
  if ((iwabove == 0) && (iwunder == 0) && (iwright == 1) && (iwleft == 0))
    return (3);
  if ((iwabove == 0) && (iwunder == 0) && (iwright == 0) && (iwleft == 1))
    return (4);
  if ((iwabove == 1) && (iwunder == 1) && (iwright == 0) && (iwleft == 0))
    return (1 + (int) (2.0 * random() / (RAND_MAX + 1.0)));
  if ((iwabove == 0) && (iwunder == 1) && (iwright == 1) && (iwleft == 0))
    return (2 + (int) (2.0 * random() / (RAND_MAX + 1.0)));
  if ((iwabove == 0) && (iwunder == 0) && (iwright == 1) && (iwleft == 1))
    return (3 + (int) (2.0 * random() / (RAND_MAX + 1.0)));
  if ((iwabove == 1) && (iwunder == 0) && (iwright == 1) && (iwleft == 0))
  {
    iwtemp = 1 + (int) (2.0 * random() / (RAND_MAX + 1.0));
    if (iwtemp == 1) return (1);
    if (iwtemp == 2) return (3);
  }
  if ((iwabove == 0) && (iwunder == 1) && (iwright == 0) && (iwleft == 1))
  {
    iwtemp = 1 + (int) (2.0 * random() / (RAND_MAX + 1.0));
    if (iwtemp == 1) return (2);
    if (iwtemp == 2) return (4);
  }
  if ((iwabove == 1) && (iwunder == 0) && (iwright == 0) && (iwleft == 1))
  {
    iwtemp = 1 + (int) (2.0 * random() / (RAND_MAX + 1.0));
    if (iwtemp == 1) return (1);
    if (iwtemp == 2) return (4);
  }
  if ((iwabove == 1) && (iwunder == 1) && (iwright == 1) && (iwleft == 0))
    return (1 + (int) (3.0 * random() / (RAND_MAX + 1.0)));
  if ((iwabove == 1) && (iwunder == 1) && (iwright == 0) && (iwleft == 1))
  {
    iwtemp = 1 + (int) (3.0 * random() / (RAND_MAX + 1.0));
    if (iwtemp == 1) return (1);
    if (iwtemp == 2) return (2);
    if (iwtemp == 3) return (4);
  }
  if ((iwabove == 1) && (iwunder == 0) && (iwright == 1) && (iwleft == 1))
  {
    iwtemp = 1 + (int) (3.0 * random() / (RAND_MAX + 1.0));
    if (iwtemp == 1) return (1);
    if (iwtemp == 2) return (3);
    if (iwtemp == 3) return (4);
  }
  if ((iwabove == 0) && (iwunder == 1) && (iwright == 1) && (iwleft == 1))
    return (2 + (int) (3.0 * random() / (RAND_MAX + 1.0)));
  if ((iwabove == 1) && (iwunder == 1) && (iwright == 1) && (iwleft == 1))
    return (1 + (int) (4.0 * random() / (RAND_MAX + 1.0)));
  return (0);
}
