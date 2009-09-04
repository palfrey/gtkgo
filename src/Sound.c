/* gtkgo 0.0.10 (Sound.c) - 05/17/99
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

#include "Sound.h"

void Sound (void)
{
  if ((ifilestuff == 0) && (isounddone == 1) && (iyesno == 0))
  {
    isounddone = 0;
    gtk_container_remove (GTK_CONTAINER (changebutton11), cbpixmapwid11);
    if (isound == 1)
    {
      if (ioptionsx == 1)
      {
        im6 = gdk_imlib_load_image (PKGDATADIR"pix/8offx.png");
      }
      else
      {
        im6 = gdk_imlib_load_image (PKGDATADIR"pix/8off.png");
      }
      isound = 0;
      Play ("", 2);
    }
    else
    {
      if (ioptionsx == 1)
      {
        im6 = gdk_imlib_load_image (PKGDATADIR"pix/8onx.png");
      }
      else
      {
        im6 = gdk_imlib_load_image (PKGDATADIR"pix/8on.png");
      }
      isound = 1;
      Play ("options.mp3", 1);
    }
    w6 = im6->rgb_width;
    h6 = im6->rgb_height;
    gdk_imlib_render (im6, w6, h6);
    cbpixmap11 = gdk_imlib_move_image (im6);
    cbpixmapwid11 = gtk_pixmap_new (cbpixmap11, NULL);
    gtk_container_add (GTK_CONTAINER (changebutton11), cbpixmapwid11);
    gtk_widget_show (cbpixmapwid11);
    gdk_flush ();
    while (gtk_events_pending ())
    {
      gtk_main_iteration ();
    }
    isounddone = 1;
  }
}
