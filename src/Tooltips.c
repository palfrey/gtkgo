/* gtkgo 0.0.10 (Tooltips.c) - 05/17/99
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

#include "Tooltips.h"

void Tooltips (void)
{
  if ((ifilestuff == 0) && (itooltipsdone == 1) && (iyesno == 0))
  {
    itooltipsdone = 0;
    for (iabutton = 1; iabutton <= 361; iabutton++)
    {
      if (itooltips == 1)
      {
        gtk_tooltips_disable (buttontip[iabutton]);
      }
      else
      {
        gtk_tooltips_enable (buttontip[iabutton]);
      }
    }
    if (ichangestuff == 1)
      {
      gtk_container_remove (GTK_CONTAINER (changebutton7), cbpixmapwid7);
      if (itooltips == 1)
      {
        if (ioptionsx == 1)
        {
          im4 = gdk_imlib_load_image (PKGDATADIR"pix/6offx.png");
        }
        else
        {
          im4 = gdk_imlib_load_image (PKGDATADIR"pix/6off.png");
        }
      }
      else
      {
        if (ioptionsx == 1)
        {
          im4 = gdk_imlib_load_image (PKGDATADIR"pix/6onx.png");
        }
        else
        {
          im4 = gdk_imlib_load_image (PKGDATADIR"pix/6on.png");
        }
      }
      w4 = im4->rgb_width;
      h4 = im4->rgb_height;
      gdk_imlib_render (im4, w4, h4);
      cbpixmap7 = gdk_imlib_move_image (im4);
      cbpixmapwid7 = gtk_pixmap_new (cbpixmap7, NULL);
      gtk_container_add (GTK_CONTAINER (changebutton7), cbpixmapwid7);
      gtk_widget_show (cbpixmapwid7);
      gdk_flush ();
      while (gtk_events_pending ())
      {
        gtk_main_iteration ();
      }
    }
    if (itooltips == 1)
    {
      gtk_tooltips_disable (toptip);
      gtk_tooltips_disable (toptip2);
      gtk_tooltips_disable (toptip3);
      gtk_tooltips_disable (toptip4);
      gtk_tooltips_disable (toptip5);
      gtk_tooltips_disable (toptip6);
      gtk_tooltips_disable (toptip7);
      gtk_tooltips_disable (toptip8);
      itooltips = 0;
    }
    else
    {
      gtk_tooltips_enable (toptip);
      gtk_tooltips_enable (toptip2);
      gtk_tooltips_enable (toptip3);
      gtk_tooltips_enable (toptip4);
      gtk_tooltips_enable (toptip5);
      gtk_tooltips_enable (toptip6);
      gtk_tooltips_enable (toptip7);
      gtk_tooltips_enable (toptip8);
      itooltips = 1;
    }
    itooltipsdone = 1;
  }
}
