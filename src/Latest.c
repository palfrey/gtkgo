/* gtkgo 0.0.10 (Latest.c) - 05/17/99
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

#include "Latest.h"

void Latest (void)
{
  if ((ifilestuff == 0) && (ilatestdone == 1) && (iyesno == 0))
  {
    ilatestdone = 0;
    gtk_container_remove (GTK_CONTAINER (changebutton9), cbpixmapwid9);
    if (ishowlast == 1)
    {
      if (ioptionsx == 1)
      {
        im5 = gdk_imlib_load_image (PKGDATADIR"pix/7offx.png");
      }
      else
      {
        im5 = gdk_imlib_load_image (PKGDATADIR"pix/7off.png");
      }
      if (ihistory >= 1)
      {
        if (Board[ilastmoveb][2] == 'b')
        {
          Board[ilastmoveb][3] = '\0';
          Change (ilastmoveb);
        }
        if (Board[ilastmovew][2] == 'w')
        {
          Board[ilastmovew][3] = '\0';
          Change (ilastmovew);
        }
      }
      ishowlast = 0;
    }
    else
    {
      if (ioptionsx == 1)
      {
        im5 = gdk_imlib_load_image (PKGDATADIR"pix/7onx.png");
      }
      else
      {
        im5 = gdk_imlib_load_image (PKGDATADIR"pix/7on.png");
      }
      if (ihistory >= 1)
      {
        if (Board[ilastmoveb][2] == 'b')
        {
          Board[ilastmoveb][3] = 'l';
          Change (ilastmoveb);
        }
        if (Board[ilastmovew][2] == 'w')
        {
          Board[ilastmovew][3] = 'l';
          Change (ilastmovew);
        }
      }
      ishowlast = 1;
    }
    w5 = im5->rgb_width;
    h5 = im5->rgb_height;
    gdk_imlib_render (im5, w5, h5);
    cbpixmap9 = gdk_imlib_move_image (im5);
    cbpixmapwid9 = gtk_pixmap_new (cbpixmap9, NULL);
    gtk_container_add (GTK_CONTAINER (changebutton9), cbpixmapwid9);
    gtk_widget_show (cbpixmapwid9);
    gdk_flush ();
    while (gtk_events_pending ())
    {
      gtk_main_iteration ();
    }
    ilatestdone = 1;
  }
}
