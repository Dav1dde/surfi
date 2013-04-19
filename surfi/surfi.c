/* See LICENSE file for copyright and license details. */
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <webkit/webkit.h>


// abcdefghijklmnopqrstuvqxyz
bool surfi_init(void);
bool surfi_poll(void);


/*
 * Initializes surfi.
 * This is basically a call to gtk_init_check.
 *
 * RETURNS: true if call was succesful otherwise false
 *
 */
bool surfi_init(void)
{
	return gtk_init_check(NULL, NULL);
}


/*
 * This updates everything related to surfi *and* gtk.
 * You can omit a call to surfi_poll if you're running
 * the gtk mainloop your own.
 *
 * RETURNS: true if there were events which needed processing, otherwise false
 */
bool surfi_poll(void)
{
	if(gtk_events_pending()) {
		gtk_main_iteration();
		return true;
	}

	return false;
}