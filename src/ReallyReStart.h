/* gtkgo 0.0.10 (ReallyReStart.h) - 05/17/99
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

#ifndef REALLYRESTART_H
#define REALLYRESTART_H

#include "main.h"

int           ibuttonrr;
int           iPlace;
GtkWidget     *loadingw;
GdkImlibImage *im9;
gint          w9,
              h9;
GdkPixmap     *lpixmap;
GtkWidget     *lpixmapwid;
GtkWidget     *lbox1;
GtkWidget     *lbox2;
GtkWidget     *ltable1;
GtkWidget     *lbar;

#endif
