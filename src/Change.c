/* gtkgo 0.0.10 (Change.c) - 05/17/99
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

#include "Change.h"

void Change (int icbutton)
{
  gtk_container_remove (GTK_CONTAINER (button[icbutton]),
    pixmapwid[icbutton]);
  sprintf (cpixmapname, PKGDATADIR"skins/%s/%s.png", sskin, Board[icbutton]);
  im[icbutton] = gdk_imlib_load_image (cpixmapname);
  if (isize == 1)
  {
    w = im[icbutton]->rgb_width;
    h = im[icbutton]->rgb_height;
  }
  if (isize == 2)
  {
    w = im[icbutton]->rgb_width * 0.8;
    h = im[icbutton]->rgb_height * 0.8;
  }
  if (isize == 3)
  {
    w = im[icbutton]->rgb_width/2;
    h = im[icbutton]->rgb_height/2;
  }
  gdk_imlib_render (im[icbutton], w, h);
  pixmap[icbutton] = gdk_imlib_move_image (im[icbutton]);
  pixmapwid[icbutton] = gtk_pixmap_new (pixmap[icbutton], NULL);
  gtk_container_add (GTK_CONTAINER (button[icbutton]),
    pixmapwid[icbutton]);
  gtk_widget_show (pixmapwid[icbutton]);
  gdk_flush ();
  if ((biscomputer == 1) && (wiscomputer == 1))
  {
    while (gtk_events_pending ())
    {
      gtk_main_iteration ();
    }
  }
}
