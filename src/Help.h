/* gtkgo 0.0.10 (Help.h) - 05/17/99
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

#ifndef HELP_H
#define HELP_H

#include "main.h"

GtkWidget *helpwindow;
GtkWidget *helpbox1;
GtkWidget *helpbox2;
GtkWidget *helpbox3;
GtkWidget *helptable1;
GtkWidget *helptable2;
GtkWidget *vscrollbarh;
GtkWidget *wrapcheckh;
GtkWidget *helpsep;
GtkWidget *helpbutton;
int       ihelpdes;
char      buffer[1024];
int       nchars;

#endif
