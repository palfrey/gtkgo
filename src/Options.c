/* gtkgo 0.0.10 (Options.c) - 05/17/99
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

#include "Options.h"

static void click_handler2 (GtkWidget *ch2widget, GdkEvent *ch2event)
{
  GdkEventButton *ch2button = (GdkEventButton *) ch2event;
  switch (ch2button->button)
  {
    case 1: Handicap (ch2widget, ch2event, (gpointer) 1); break;
    case 3: Handicap (ch2widget, ch2event, (gpointer) 2); break;
  }
}

static gint button_press (GtkWidget *widget, GdkEvent *event)
{
  if ((event->type == GDK_BUTTON_PRESS) && (ifilestuff == 0) && (inet == 0) &&
    (iyesno == 0) && ((biscomputer == 0) || (wiscomputer == 0)))
  {
    GdkEventButton *bevent = (GdkEventButton *) event;
    gtk_menu_popup (GTK_MENU (widget), NULL, NULL, NULL, NULL,
      bevent->button, bevent->time);
    return TRUE;
  }
  return FALSE;
}

void Options (void)
{
  if ((ifilestuff == 0) && (ichangestuff == 0) && (iyesno == 0))
  {
    Play ("options.mp3", 1);
    changewindow = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (changewindow), "options");
    gtk_signal_connect (GTK_OBJECT (changewindow), "delete_event",
      GTK_SIGNAL_FUNC (DestroyOptions), NULL);
    gtk_window_set_policy (GTK_WINDOW (changewindow), 0, 0, 1);
    gtk_container_border_width (GTK_CONTAINER (changewindow), 0);
    gtk_widget_realize (changewindow);

    changebox1 = gtk_vbox_new (FALSE, 0);
    gtk_container_border_width (GTK_CONTAINER (changebox1), 0);
    gtk_container_add (GTK_CONTAINER (changewindow), changebox1);
    gtk_widget_show (changebox1);
    changebox2 = gtk_hbox_new (FALSE, 0);
    gtk_container_border_width (GTK_CONTAINER (changebox2), 0);
    gtk_box_pack_start (GTK_BOX (changebox1), changebox2, FALSE, FALSE, 0);
    gtk_widget_show (changebox2);
    changetable1 = gtk_table_new (2, 9, FALSE);
    gtk_widget_show (changetable1);
    gtk_box_pack_start (GTK_BOX (changebox2), changetable1, TRUE, TRUE, 0);

    menu = gtk_menu_new ();
    menu_items = gtk_menu_item_new_with_label ("human player");
    gtk_menu_append (GTK_MENU (menu), menu_items);
    gtk_signal_connect (GTK_OBJECT (menu_items), "activate",
      GTK_SIGNAL_FUNC (Human), (gpointer) 1);
    gtk_widget_show (menu_items);
    menu_items = gtk_menu_item_new_with_label ("go-computer");
    gtk_menu_append (GTK_MENU (menu), menu_items);
    gtk_signal_connect (GTK_OBJECT (menu_items), "activate",
      GTK_SIGNAL_FUNC (TheComputer), (gpointer) 1);
    gtk_widget_show (menu_items);

    menu2 = gtk_menu_new ();
    menu_items = gtk_menu_item_new_with_label ("human player");
    gtk_menu_append (GTK_MENU (menu2), menu_items);
    gtk_signal_connect (GTK_OBJECT (menu_items), "activate",
      GTK_SIGNAL_FUNC (Human), (gpointer) 2);
    gtk_widget_show (menu_items);
    menu_items = gtk_menu_item_new_with_label ("go-computer");
    gtk_menu_append (GTK_MENU (menu2), menu_items);
    gtk_signal_connect (GTK_OBJECT (menu_items), "activate",
      GTK_SIGNAL_FUNC (TheComputer), (gpointer) 2);
    gtk_widget_show (menu_items);

    changebutton = gtk_event_box_new ();
    gtk_widget_set_usize (changebutton, 200, 30);
    gtk_table_attach (GTK_TABLE (changetable1), changebutton, 0, 2, 0, 1,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_signal_connect_object (GTK_OBJECT (changebutton), "event",
      GTK_SIGNAL_FUNC (button_press), GTK_OBJECT (menu));
    gtk_widget_show (changebutton);
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

    changebutton2 = gtk_event_box_new ();
    gtk_widget_set_usize (changebutton2, 200, 30);
    gtk_table_attach (GTK_TABLE (changetable1), changebutton2, 0, 2, 1, 2,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_signal_connect_object (GTK_OBJECT (changebutton2), "event",
      GTK_SIGNAL_FUNC (button_press), GTK_OBJECT (menu2));
    gtk_widget_show (changebutton2);
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

    changebutton3 = gtk_event_box_new ();
    gtk_widget_set_usize (changebutton3, 200, 30);
    gtk_table_attach (GTK_TABLE (changetable1), changebutton3, 0, 2, 2, 3,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_signal_connect (GTK_OBJECT (changebutton3), "button_press_event",
      GTK_SIGNAL_FUNC (Internet), NULL);
    gtk_widget_show (changebutton3);
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

    changebutton4 = gtk_event_box_new ();
    gtk_widget_set_usize (changebutton4, 200, 30);
    gtk_table_attach (GTK_TABLE (changetable1), changebutton4, 0, 2, 3, 4,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_signal_connect (GTK_OBJECT (changebutton4), "button_press_event",
      GTK_SIGNAL_FUNC (TimeLimit), NULL);
    gtk_widget_show (changebutton4);
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

    changebutton5 = gtk_event_box_new ();
    gtk_widget_set_usize (changebutton5, 180, 30);
    gtk_table_attach (GTK_TABLE (changetable1), changebutton5, 0, 1, 4, 5,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_signal_connect (GTK_OBJECT (changebutton5), "button_press_event",
      GTK_SIGNAL_FUNC (Help), NULL);
    gtk_widget_show (changebutton5);
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

    changebuttonx = gtk_event_box_new ();
    gtk_widget_set_usize (changebuttonx, 20, 30);
    gtk_table_attach (GTK_TABLE (changetable1), changebuttonx, 1, 2, 4, 5,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_signal_connect (GTK_OBJECT (changebuttonx), "button_press_event",
      GTK_SIGNAL_FUNC (OptionsX), NULL);
    gtk_widget_show (changebuttonx);
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

    changebutton6 = gtk_event_box_new ();
    gtk_widget_set_usize (changebutton6, 180, 30);
    gtk_table_attach (GTK_TABLE (changetable1), changebutton6, 0, 1, 5, 6,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_signal_connect (GTK_OBJECT (changebutton6), "button_press_event",
      GTK_SIGNAL_FUNC (Tooltips), NULL);
    gtk_widget_show (changebutton6);
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

    changebutton7 = gtk_event_box_new ();
    gtk_widget_set_usize (changebutton7, 20, 30);
    gtk_table_attach (GTK_TABLE (changetable1), changebutton7, 1, 2, 5, 6,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_signal_connect (GTK_OBJECT (changebutton7), "button_press_event",
      GTK_SIGNAL_FUNC (Tooltips), NULL);
    gtk_widget_show (changebutton7);
    if ((itooltips == 1) && (ioptionsx == 1))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/6onx.png");
    }
    if ((itooltips == 0) && (ioptionsx == 1))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/6offx.png");
    }
    if ((itooltips == 1) && (ioptionsx == 0))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/6on.png");
    }
    if ((itooltips == 0) && (ioptionsx == 0))
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

    changebutton8 = gtk_event_box_new ();
    gtk_widget_set_usize (changebutton8, 180, 30);
    gtk_table_attach (GTK_TABLE (changetable1), changebutton8, 0, 1, 6, 7,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_signal_connect (GTK_OBJECT (changebutton8), "button_press_event",
      GTK_SIGNAL_FUNC (Latest), NULL);
    gtk_widget_show (changebutton8);
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

    changebutton9 = gtk_event_box_new ();
    gtk_widget_set_usize (changebutton9, 20, 30);
    gtk_table_attach (GTK_TABLE (changetable1), changebutton9, 1, 2, 6, 7,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_signal_connect (GTK_OBJECT (changebutton9), "button_press_event",
      GTK_SIGNAL_FUNC (Latest), NULL);
    gtk_widget_show (changebutton9);
    if ((ishowlast == 1) && (ioptionsx == 1))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/7onx.png");
    }
    if ((ishowlast == 0) && (ioptionsx == 1))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/7offx.png");
    }
    if ((ishowlast == 1) && (ioptionsx == 0))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/7on.png");
    }
    if ((ishowlast == 0) && (ioptionsx == 0))
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

    changebutton10 = gtk_event_box_new ();
    gtk_widget_set_usize (changebutton10, 180, 30);
    gtk_table_attach (GTK_TABLE (changetable1), changebutton10, 0, 1, 7, 8,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_signal_connect (GTK_OBJECT (changebutton10), "button_press_event",
      GTK_SIGNAL_FUNC (Sound), NULL);
    gtk_widget_show (changebutton10);
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

    changebutton11 = gtk_event_box_new ();
    gtk_widget_set_usize (changebutton11, 20, 30);
    gtk_table_attach (GTK_TABLE (changetable1), changebutton11, 1, 2, 7, 8,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_signal_connect (GTK_OBJECT (changebutton11), "button_press_event",
      GTK_SIGNAL_FUNC (Sound), NULL);
    gtk_widget_show (changebutton11);
    if ((isound == 1) && (ioptionsx == 1))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/8onx.png");
    }
    if ((isound == 0) && (ioptionsx == 1))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/8offx.png");
    }
    if ((isound == 1) && (ioptionsx == 0))
    {
      im3 = gdk_imlib_load_image (PKGDATADIR"pix/8on.png");
    }
    if ((isound == 0) && (ioptionsx == 0))
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

    changebutton12 = gtk_event_box_new ();
    gtk_widget_set_usize (changebutton12, 180, 30);
    gtk_table_attach (GTK_TABLE (changetable1), changebutton12, 0, 1, 8, 9,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_signal_connect (GTK_OBJECT (changebutton12), "button_press_event",
      GTK_SIGNAL_FUNC (click_handler2), NULL);
    gtk_widget_show (changebutton12);
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

    changebutton13 = gtk_event_box_new ();
    gtk_widget_set_usize (changebutton13, 20, 30);
    gtk_table_attach (GTK_TABLE (changetable1), changebutton13, 1, 2, 8, 9,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_signal_connect (GTK_OBJECT (changebutton13), "button_press_event",
      GTK_SIGNAL_FUNC (click_handler2), NULL);
    gtk_widget_show (changebutton13);
    if (ioptionsx == 1)
    {
      sprintf (cThePng2, PKGDATADIR"pix/9%ix.png", ihandicap);
    }
    else
    {
      sprintf (cThePng2, PKGDATADIR"pix/9%i.png", ihandicap);
    }
    im3 = gdk_imlib_load_image (cThePng2);
    w3 = im3->rgb_width;
    h3 = im3->rgb_height;
    gdk_imlib_render (im3, w3, h3);
    cbpixmap13 = gdk_imlib_move_image (im3);
    cbpixmapwid13 = gtk_pixmap_new (cbpixmap13, NULL);
    gtk_container_add (GTK_CONTAINER (changebutton13), cbpixmapwid13);
    gtk_widget_show (cbpixmapwid13);
    gdk_flush ();

    gtk_widget_show (changewindow);
    ichangestuff = 1;
  }
  else
  if (ichangestuff == 0)
  {
    Play ("click.mp3", 0);
  }
}
