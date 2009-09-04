/* gtkgo 0.0.10 (InternetGo.h) - 05/17/99
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

#ifndef INTERNETGO_H
#define INTERNETGO_H

#include "main.h"

struct sockaddr_in host_addr;
struct in_addr     *theaddress;
char               *shost;
int                iport;
GtkWidget          *internetwindow;
GtkWidget          *internetbox1;
GtkWidget          *internetbox2;
GtkWidget          *internetbox3;
GtkWidget          *internettable1;
GtkWidget          *internettable2;
GtkWidget          *vscrollbar;
GdkColormap        *cmap;
GtkWidget          *wrapcheck;
GtkWidget          *inetsep;
GtkWidget          *inetbutton;
int                itheerror;
char               serrortemp[100];

#endif
