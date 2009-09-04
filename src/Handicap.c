/* gtkgo 0.0.10 (Handicap.c) - 05/17/99
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

#include "Handicap.h"

void Handicap (GtkWidget *hwidget, GdkEvent *hevent, gpointer hdata)
{
  if ((ifilestuff == 0) && (ihandicapdone == 1) && (iyesno == 0) && (inet == 0))
  {
    ihandicapdone = 0;
    gtk_container_remove (GTK_CONTAINER (changebutton13), cbpixmapwid13);
    if ((int) hdata == 1)
    {
      ihandicap++;
      if (ihandicap == 1)
      {
        ihandicap = 2;
      }
      if (ihandicap == 18)
      {
        ihandicap = 0;
      }
    }
    else
    {
      ihandicap--;
      if (ihandicap == 1)
      {
        ihandicap = 0;
      }
      if (ihandicap == -1)
      {
        ihandicap = 17;
      }
    }
    if (ioptionsx == 1)
    {
      sprintf (cThePng, PKGDATADIR"pix/9%ix.png", ihandicap);
    }
    else
    {
      sprintf (cThePng, PKGDATADIR"pix/9%i.png", ihandicap);
    }
    im7 = gdk_imlib_load_image (cThePng);
    w7 = im7->rgb_width;
    h7 = im7->rgb_height;
    gdk_imlib_render (im7, w7, h7);
    cbpixmap13 = gdk_imlib_move_image (im7);
    cbpixmapwid13 = gtk_pixmap_new (cbpixmap13, NULL);
    gtk_container_add (GTK_CONTAINER (changebutton13), cbpixmapwid13);
    gtk_widget_show (cbpixmapwid13);
    gdk_flush ();
    while (gtk_events_pending ())
    {
      gtk_main_iteration ();
    }
    if (((ihistory <= 1) && (wiscomputer == 0)) ||
      ((ihistory <= 2) && (wiscomputer == 1)))
    {
      ihistory = 0;
      imoves = 0;
      DoHandicap ();
    }
    ihandicapdone = 1;
  }
}
