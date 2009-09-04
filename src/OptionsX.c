/* gtkgo 0.0.10 (OptionsX.c) - 05/17/99
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

#include "OptionsX.h"

void OptionsX (void)
{
  if (ixdone == 1)
  {
    ixdone = 0;
    if (ioptionsx == 0)
    {
      ioptionsx = 1;
    }
    else
    {
      ioptionsx = 0;
    }

    gtk_container_remove (GTK_CONTAINER (changebutton), cbpixmapwid);
    if (ioptionsx == 1)
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/1x.png");
    }
    else
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/1.png");
    }
    w3 = im3->rgb_width;
    h3 = im3->rgb_height;
    gdk_imlib_render (im3, w3, h3);
    cbpixmap = gdk_imlib_move_image (im3);
    cbpixmapwid = gtk_pixmap_new (cbpixmap, NULL);
    gtk_container_add (GTK_CONTAINER (changebutton), cbpixmapwid);
    gtk_widget_show (cbpixmapwid);
    gdk_flush ();

    gtk_container_remove (GTK_CONTAINER (changebutton2), cbpixmapwid2);
    if (ioptionsx == 1)
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/2x.png");
    }
    else
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/2.png");
    }
    w3 = im3->rgb_width;
    h3 = im3->rgb_height;
    gdk_imlib_render (im3, w3, h3);
    cbpixmap2 = gdk_imlib_move_image (im3);
    cbpixmapwid2 = gtk_pixmap_new (cbpixmap2, NULL);
    gtk_container_add (GTK_CONTAINER (changebutton2), cbpixmapwid2);
    gtk_widget_show (cbpixmapwid2);
    gdk_flush ();

    gtk_container_remove (GTK_CONTAINER (changebutton3), cbpixmapwid3);
    if (ioptionsx == 1)
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/3x.png");
    }
    else
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/3.png");
    }
    w3 = im3->rgb_width;
    h3 = im3->rgb_height;
    gdk_imlib_render (im3, w3, h3);
    cbpixmap3 = gdk_imlib_move_image (im3);
    cbpixmapwid3 = gtk_pixmap_new (cbpixmap3, NULL);
    gtk_container_add (GTK_CONTAINER (changebutton3), cbpixmapwid3);
    gtk_widget_show (cbpixmapwid3);
    gdk_flush ();

    gtk_container_remove (GTK_CONTAINER (changebutton4), cbpixmapwid4);
    if (ioptionsx == 1)
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/4x.png");
    }
    else
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/4.png");
    }
    w3 = im3->rgb_width;
    h3 = im3->rgb_height;
    gdk_imlib_render (im3, w3, h3);
    cbpixmap4 = gdk_imlib_move_image (im3);
    cbpixmapwid4 = gtk_pixmap_new (cbpixmap4, NULL);
    gtk_container_add (GTK_CONTAINER (changebutton4), cbpixmapwid4);
    gtk_widget_show (cbpixmapwid4);
    gdk_flush ();

    gtk_container_remove (GTK_CONTAINER (changebutton5), cbpixmapwid5);
    if (ioptionsx == 1)
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/5x.png");
    }
    else
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/5.png");
    }
    w3 = im3->rgb_width;
    h3 = im3->rgb_height;
    gdk_imlib_render (im3, w3, h3);
    cbpixmap5 = gdk_imlib_move_image (im3);
    cbpixmapwid5 = gtk_pixmap_new (cbpixmap5, NULL);
    gtk_container_add (GTK_CONTAINER (changebutton5), cbpixmapwid5);
    gtk_widget_show (cbpixmapwid5);
    gdk_flush ();

    gtk_container_remove (GTK_CONTAINER (changebuttonx), cbpixmapwidx);
    if (ioptionsx == 1)
    {
    im3 = gdk_imlib_load_image (PKGDATADIR"pix/5bx.png");
    }
    else
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/5b.png");
    }
    w3 = im3->rgb_width;
    h3 = im3->rgb_height;
    gdk_imlib_render (im3, w3, h3);
    cbpixmapx = gdk_imlib_move_image (im3);
    cbpixmapwidx = gtk_pixmap_new (cbpixmapx, NULL);
    gtk_container_add (GTK_CONTAINER (changebuttonx), cbpixmapwidx);
    gtk_widget_show (cbpixmapwidx);
    gdk_flush ();

    gtk_container_remove (GTK_CONTAINER (changebutton6), cbpixmapwid6);
    if (ioptionsx == 1)
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/6x.png");
    }
    else
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/6.png");
    }
    w3 = im3->rgb_width;
    h3 = im3->rgb_height;
    gdk_imlib_render (im3, w3, h3);
    cbpixmap6 = gdk_imlib_move_image (im3);
    cbpixmapwid6 = gtk_pixmap_new (cbpixmap6, NULL);
    gtk_container_add (GTK_CONTAINER (changebutton6), cbpixmapwid6);
    gtk_widget_show (cbpixmapwid6);
    gdk_flush ();

    gtk_container_remove (GTK_CONTAINER (changebutton7), cbpixmapwid7);
    if ((ioptionsx == 1) && (itooltips == 1))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/6onx.png");
    }
    if ((ioptionsx == 1) && (itooltips == 0))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/6offx.png");
    }
    if ((ioptionsx == 0) && (itooltips == 1))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/6on.png");
    }
    if ((ioptionsx == 0) && (itooltips == 0))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/6off.png");
    }
    w3 = im3->rgb_width;
    h3 = im3->rgb_height;
    gdk_imlib_render (im3, w3, h3);
    cbpixmap7 = gdk_imlib_move_image (im3);
    cbpixmapwid7 = gtk_pixmap_new (cbpixmap7, NULL);
    gtk_container_add (GTK_CONTAINER (changebutton7), cbpixmapwid7);
    gtk_widget_show (cbpixmapwid7);
    gdk_flush ();

    gtk_container_remove (GTK_CONTAINER (changebutton8), cbpixmapwid8);
    if (ioptionsx == 1)
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/7x.png");
    }
    else
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/7.png");
    }
    w3 = im3->rgb_width;
    h3 = im3->rgb_height;
    gdk_imlib_render (im3, w3, h3);
    cbpixmap8 = gdk_imlib_move_image (im3);
    cbpixmapwid8 = gtk_pixmap_new (cbpixmap8, NULL);
    gtk_container_add (GTK_CONTAINER (changebutton8), cbpixmapwid8);
    gtk_widget_show (cbpixmapwid8);
    gdk_flush ();

    gtk_container_remove (GTK_CONTAINER (changebutton9), cbpixmapwid9);
    if ((ioptionsx == 1) && (ishowlast == 1))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/7onx.png");
    }
    if ((ioptionsx == 1) && (ishowlast == 0))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/7offx.png");
    }
    if ((ioptionsx == 0) && (ishowlast == 1))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/7on.png");
    }
    if ((ioptionsx == 0) && (ishowlast == 0))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/7off.png");
    }
    w3 = im3->rgb_width;
    h3 = im3->rgb_height;
    gdk_imlib_render (im3, w3, h3);
    cbpixmap9 = gdk_imlib_move_image (im3);
    cbpixmapwid9 = gtk_pixmap_new (cbpixmap9, NULL);
    gtk_container_add (GTK_CONTAINER (changebutton9), cbpixmapwid9);
    gtk_widget_show (cbpixmapwid9);
    gdk_flush ();

    gtk_container_remove (GTK_CONTAINER (changebutton10), cbpixmapwid10);
    if (ioptionsx == 1)
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/8x.png");
    }
    else
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/8.png");
    }
    w3 = im3->rgb_width;
    h3 = im3->rgb_height;
    gdk_imlib_render (im3, w3, h3);
    cbpixmap10 = gdk_imlib_move_image (im3);
    cbpixmapwid10 = gtk_pixmap_new (cbpixmap10, NULL);
    gtk_container_add (GTK_CONTAINER (changebutton10), cbpixmapwid10);
    gtk_widget_show (cbpixmapwid10);
    gdk_flush ();

    gtk_container_remove (GTK_CONTAINER (changebutton11), cbpixmapwid11);
    if ((ioptionsx == 1) && (isound == 1))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/8onx.png");
    }
    if ((ioptionsx == 1) && (isound == 0))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/8offx.png");
    }
    if ((ioptionsx == 0) && (isound == 1))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/8on.png");
    }
    if ((ioptionsx == 0) && (isound == 0))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/8off.png");
    }
    w3 = im3->rgb_width;
    h3 = im3->rgb_height;
    gdk_imlib_render (im3, w3, h3);
    cbpixmap11 = gdk_imlib_move_image (im3);
    cbpixmapwid11 = gtk_pixmap_new (cbpixmap11, NULL);
    gtk_container_add (GTK_CONTAINER (changebutton11), cbpixmapwid11);
    gtk_widget_show (cbpixmapwid11);
    gdk_flush ();

    gtk_container_remove (GTK_CONTAINER (changebutton12), cbpixmapwid12);
    if (ioptionsx == 1)
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/9x.png");
    }
    else
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/9.png");
    }
    w3 = im3->rgb_width;
    h3 = im3->rgb_height;
    gdk_imlib_render (im3, w3, h3);
    cbpixmap12 = gdk_imlib_move_image (im3);
    cbpixmapwid12 = gtk_pixmap_new (cbpixmap12, NULL);
    gtk_container_add (GTK_CONTAINER (changebutton12), cbpixmapwid12);
    gtk_widget_show (cbpixmapwid12);
    gdk_flush ();

    gtk_container_remove (GTK_CONTAINER (changebutton13), cbpixmapwid13);
    if (ioptionsx == 1)
    {
      sprintf (cThePng3, PKGDATADIR"pix/9%ix.png", ihandicap);
    }
    else
    {
      sprintf (cThePng3, PKGDATADIR"pix/9%i.png", ihandicap);
    }
    im3 = gdk_imlib_load_image (cThePng3);
    w3 = im3->rgb_width;
    h3 = im3->rgb_height;
    gdk_imlib_render (im3, w3, h3);
    cbpixmap13 = gdk_imlib_move_image (im3);
    cbpixmapwid13 = gtk_pixmap_new (cbpixmap13, NULL);
    gtk_container_add (GTK_CONTAINER (changebutton13), cbpixmapwid13);
    gtk_widget_show (cbpixmapwid13);
    gdk_flush ();
    while (gtk_events_pending ())
    {
      gtk_main_iteration ();
    }
    ixdone = 1;
  }
}
